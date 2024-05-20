#include <stdio.h>

int Scanf(int* a)
{
	int flag=scanf("%d",a);
	while(flag != 1 && flag != EOF)
	{
		printf("введен символ, а не число, повторите ввод\n");
		scanf("%*[^\n]");
		flag=scanf("%d",a);
	}
	if(flag == 1)
	{
		return 1;
	}
	if(flag == EOF)
	{
		printf("\nEOF!!!\n");
		return 0;
	}
}
