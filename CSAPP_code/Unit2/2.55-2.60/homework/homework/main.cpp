#include<stdio.h>
#include<stdlib.h>

void show_bytes(unsigned char* code,int lenght)
{
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		printf("%.2x ", code[i]);
	}
	printf("\n");
}

void show_short(short a)
{
	show_bytes((unsigned char*)&a, sizeof(short));
}

void show_long(long a)
{
	show_bytes((unsigned char*)&a, sizeof(long));
}

void show_double(double a)
{
	show_bytes((unsigned char*)&a, sizeof(double));
}

int is_little_endian()
{
	short i = 1;
	unsigned char* code = (unsigned char*)&i;
	return code[0];
}

unsigned int generate_code(unsigned int x, unsigned int y)
{
	//unsigned int c = x & 0x000000ff + y & 0xffffff00;   优先级加法比按位与高
	unsigned int c = (x & 0x000000ff) + (y & 0xffffff00);
	return c;
}

unsigned int replace_byte(unsigned int x, int i, unsigned char b)
{
	unsigned int c =~( 0x000000ff << (i*8));
	unsigned int tmp = x & c;
	unsigned int tmp1 = (unsigned int)b;
	tmp1 = tmp1 << (i * 8);
	tmp = tmp | tmp1;
	return tmp;
}

int main()
{
	short a = 0xabcd;
	long b = 0xabcdef98;
	double c = 3.1415926535;
	char d = 0xab;
	//2.55-2.56
	show_bytes((unsigned char*)&d,sizeof(char));
	//2.57
	show_short(a);
	show_long(b);
	show_double(c);
	//2.58
	printf("%d\n", is_little_endian());
	//2.59
	unsigned int x = 0x89abcdef; unsigned int y = 0x76543210;
	printf("%x\n", generate_code(x,y));
	//2.60
	printf("%x\n", replace_byte(0x12345678,2,0xAB));
	printf("%x\n", replace_byte(0x12345678, 0, 0xAB));
	system("pause");
	return 0;
}