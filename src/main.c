#include <stdio.h>
#include <string.h>

void banner()
{
	printf("------------------------------\n");
	printf("WINDOWS SHELLCODE POLYGON\n");
	printf("AFANX\n");
	printf("channel: https://t.me/k0n70r4\n");
	printf("------------------------------\n");
}

int main (int argc, char *argv[])
{
	banner();
	
	if(argc<2){
		printf("USAGE: scpolygon.exe shellcode.bin");
		getchar();
		return -1;
	}
	
	char buf[4096];
	
	FILE *fp;
	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open file!");
		getchar();
		return -2;
	}
	
	fgets(buf, 4096, fp);
	asm("jmp *%eax");
	return 0;
}
