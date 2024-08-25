/* examining PP 3.4 with gcc gdb disassembler */

void pp_char_int(char *sp, int *dp) { *dp = (int)*sp; }
void pp_char_unsigned(char *sp, unsigned *dp) { *dp = (unsigned)*sp; }
void pp_unsigned_char_long(unsigned char *sp, long *dp) { *dp = (long)*sp; }
void pp_int_char(int *sp, char *dp) { *dp = (char)*sp; }
void pp_unsigned_unsigned_char(unsigned *sp, unsigned char *dp) {
  *dp = (unsigned char)*sp;
}
void pp_char_short(char *sp, short *dp) { *dp = (short)*sp; }
