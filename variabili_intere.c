#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   int n, i;
   long long int nfatt;
 
   printf ("inserisci n: ");
   scanf ("%d", &n);
 
   i = 1;
   nfatt = 1;
   while (i <= n)
   {
      nfatt = nfatt * i;
      i++;
   }
 
   printf ("n! = %lld", nfatt);
 
   return EXIT_SUCCESS;
}