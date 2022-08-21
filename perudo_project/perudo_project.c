
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double calcola_prob(int n_dadi, int chiamata, int lato_dado);
long long int coeff_bin(int n, int k);


int main()
{
    int n_dadi, n_dadi_chiamata, lato_dado;

    double prob;

    printf("***TEST***: %lld\n", coeff_bin(4,2));

    printf("Inserisci il numero di dadi: ");

    scanf("%d", &n_dadi);

    printf("Inserisci la chiamata([1-n] [1-6]): ");

    scanf("%d %d", &n_dadi_chiamata, &lato_dado);

    prob = calcola_prob(n_dadi, n_dadi_chiamata, lato_dado);

    printf("Probabilita di successo della chiamata: %.1lf%%\n", prob*100);

    return EXIT_SUCCESS;

}
double calcola_prob(int n_dadi, int chiamata, int lato_dado)
{
    int i;
    double prob;
    int x_1, x_2;
    double f_1, f_2;

    printf("\n");

    for(i = chiamata; i < n_dadi + 1; i++)
    {
        x_1 = i;
        x_2 = n_dadi - i;

        f_1 = pow(0.333333, x_1);
        f_2 = pow(0.666666,x_2);
        
        if(i % 4 == 0)
        {
            printf(".");
            printf(".");
            printf(".");
            printf("calcolo");
            printf(".");
            printf(".");
            printf(".\n\n");
        }
        

        prob = prob + (coeff_bin(n_dadi, x_1) * f_1 * f_2);
    }

    return prob;
}


long long int coeff_bin(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return coeff_bin(n - 1, k - 1)
           + coeff_bin(n - 1, k);
}
