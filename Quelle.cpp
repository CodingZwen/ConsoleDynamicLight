
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

//fill vor printing bits -> y || Y for yes, else not
void printbits(unsigned int bits, unsigned char fill)
{

	unsigned  int i;
	char currentbyte = '_';
	char buffer[32];

	for (i = 0; bits > 0; i++)
	{
		currentbyte = bits % 2 ? '1' : '0';
		buffer[i] = currentbyte;
		bits = bits / 2;
	}

	//füllen
	if (fill == 'y' || fill == 'Y')
	{
		for (; i < 32; i++)
		{
			buffer[i] = '0';

		}
	}

	for (int j = i - 1; j >= 0; j--)
	{

		printf("%c", buffer[j]);
	}
}


//not used, not finished
unsigned char *getbitsAsString(unsigned int bits)
{

	unsigned  int i;
	unsigned char currentbyte = '_';
	unsigned char *str;
	unsigned char *ptrstr;
	int size = 33; // '\0'
	str = (unsigned char *)malloc(sizeof(unsigned char)*size);
	ptrstr = str;


	for (i = 0; bits > 0; i++)
	{
		currentbyte = bits % 2 ? '1' : '0';
		*ptrstr = currentbyte;
		bits = bits / 2;
		*ptrstr++;
	}


	if (i == 32)*ptrstr = '\0';


	for (int j = i; j >= 0; j--)
	{

		printf("%c", *ptrstr);
		*ptrstr--;
	}

	return str;


}

void printAngelLights(unsigned int bits, unsigned int lightsize)
{

	if (lightsize > 32)lightsize = 32;

	unsigned char carlight[32];
	unsigned char currentdiode;
	unsigned int i;


	for (i = 0; bits > 0 && i < lightsize; i++)
	{
		currentdiode = bits % 2 ? 0x3d : ' ';
		carlight[i] = currentdiode;
		bits = bits / 2;

	}

	for (int j = 0; j < lightsize*2; j++) {
		printf("_");

	}
	printf("\n");

	for (int k = i - 1; k >= 0; k--)
	{
		printf("|");
		printf("%c", carlight[k]);
	}

	for(int l= lightsize-i;l>0;l--)
	printf(" |");

	printf("\n");

	for (int j = 0; j < lightsize*2.0; j++) {
		printf("_");

	}

}

//returns max int to corresponding bits to check if all lights on
unsigned int getMaxNumberfromBits(unsigned int bitcount)
{
	unsigned int bits= 0;
	for (int i = 0; i < bitcount; i++)
	{
		bits <<= 1;
		bits |= 1;
	
	}
	return bits;
}


int main()
{

	
	//printAngelLights(128723, 32);
	//  getbitsAsString(4294967295);

	unsigned int light = 0;
	unsigned int shift = 1;
	unsigned int amountdiods = 16;
	const int sleeptime = 50;
	int sleeptimer = sleeptime;

	while (1)
	{
		printAngelLights(light, amountdiods);
	
		light <<= 1;
		light |= shift;
		Sleep(sleeptimer);
		if(sleeptimer>5)sleeptimer-=5;

		if (light >= getMaxNumberfromBits(amountdiods))
		{
			sleeptimer = sleeptime;
			light = 1;
			Sleep(sleeptime*2);
		}
		system("cls");

	}


	return 0;
}
