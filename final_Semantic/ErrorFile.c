//Error file out of scope variable

#include<stdio.h>
int f1()
{
	int new;
	new=10;
	return 0;
}
void main()
{
	int a[10];
	int test;
	float b=12.2;
	int c;

    new = new +1;
	if(c)
	{
		int temp = 5;
		b=13.3;
	}
	else
		c=12;

	for(c=1;c<2;c = c+1)
	{
		b=b/2;
	}
	a=f1(8);
}
}


