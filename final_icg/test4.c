//function calls

#include <stdio.h>

int f1()
{
	int x;
	x=10;
	
	return x;
}

int f2()
{
	int y;
	y=12;
	f1();
	return y;
}

int main () 
{

   /* local variable definition */
   int i, j,k;
   f1();
	f2();
	return 0;
}
