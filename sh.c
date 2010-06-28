#include <stdio.h>

int main()
{
	unsigned int insn = 0xe1600070;
	unsigned int op1 = (insn >> 21) & 3;
	unsigned int sh = (insn >> 4) & 0xf;
	unsigned int rm = insn & 0xf;

	printf("op1 = 0x%x\n", op1);
	printf("sh  = 0x%x\n", sh);
	printf("rm  = 0x%x\n", rm);
	return 0;
}

