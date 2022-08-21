#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
double mysqrt (double r);
 
int main()
{
   double r1, r2;
 
   r1 = sqrt (2.0);
   r2 = mysqrt (2.0);
 
   if (r1 == r2)
   {
      printf ("OK! Radice di due = %.7lf\n", r1);
   }
   else
   {
      printf ("Bo!? x = %.7lf, y = %.7lf\n", r1, r2);
   }
 
   return EXIT_SUCCESS;
}
 
double mysqrt (double r)
{

   double n1, n2;
 
   n1 = r;
   n2 = 1;
   printf("%.10lf %.10lf\n",n1,n2);
   while (n1 - n2 > 0)
   {
        n1 = (n1 + n2) / 2;
        n2 = r / n1;
   }
   return n1;
}