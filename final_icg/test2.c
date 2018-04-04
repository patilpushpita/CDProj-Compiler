//nested for

#include <stdio.h>
 
int main () {

   /* local variable definition */
   int i, j;
   
   for(i = 2; i<100; ) 
  {

      for(j = 2; j <= i; ) 
      {
		if(!(i/j)) 
			break; // if factor found, not prime
	  }
      if(j > 1) 
	  {
		j=299;
	  }
   }
 
   return 0;
}
