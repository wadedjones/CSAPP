/* K&R simple allocator using an explicit free list with a block size and successor pointer in each free block.
 * It uses unions to eliminate a lot of the complicated pointer arithmetic, but at the expense of a linear-time
 * (rather than constant-time) free operation. */

#include <stddef.h>

union header { 			   /* Block header: */
	struct {
		union header *ptr; /* Next block if on free list */
		unsigned size;     /* Size of this block */
	} s;
	long x; 			   /* Force alignment of blocks */
};

typedef union header Header;

#define NALLOC 1024 /* Minimum #units to request */

/* Function prototypes */
static Header *morecore(unsigned nu);
void kr_free(void *ap);

/* Global variables */
static Header base; /* Empty list to get started */
static Header *freep = NULL; /* Start of free list */

/* malloc: general-purpose storage allocator */
void *kr_malloc(unsigned nbytes) {
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;

	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {
		base.s.ptr = freep = prevp = &base; /* No free list yet */
		base.s.size = 0;
	}

	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) { /* Big enough */
			if (p->s.size == nunits) { /* Exact size */
				prevp->s.ptr = p->s.ptr;
			} else { /* Allocate tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p + 1);
		}
		if (p == freep) { /* Wrapped around free list */
			if ((p = morecore(nunits)) == NULL) {
				return NULL; /* None left */
			}
		}
	}
}

/* morecore: ask system for more memory */
static Header *morecore(unsigned nu) {
	char *cp, *sbrk(int);
	Header *up;

	if (nu < NALLOC) {
		nu = NALLOC;
	}
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *)-1) { /* No space at all */
		return NULL;
	}
	up = (Header *)cp;
	up->s.size = nu;
	kr_free((void *)(up + 1));
	return freep;
}

void kr_free(void *ap) {
	Header *bp, *p;

	bp = (Header *)ap - 1; /* point to block header */
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
			break; /* freed block at start or end of arena */
		}
	}

	if (bp + bp->s.size == p->s.ptr) { /* Join to upper nbr */
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else {
		bp->s.ptr = p->s.ptr;
	}
	if (p + p->s.size == bp) { /* Join to lower nbr */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else {
		p->s.ptr = bp;
	}
	freep = p;
}
