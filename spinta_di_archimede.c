#include "stdio.h"
#include "stdlib.h"

#define PIGRECO 3.141592
#define D_ACQUA 1.028
#define F_GRAV 9.81

double calcola_volume_sfera(double raggio);
double cubo(double raggio);

int main()
{
    double raggio;
    double v;
    double spinta_di_archimede;
    scanf("%lf", &raggio);

    v = calcola_volume_sfera(raggio);

    spinta_di_archimede = D_ACQUA * F_GRAV * v;

    printf("%lf\n", spinta_di_archimede);

    exit(EXIT_SUCCESS);
}

double calcola_volume_sfera(double raggio)
{
    double volume,cost;
    cost = 4.000000 /  3.000000;
    volume = cost * PIGRECO * cubo(raggio);
    return volume;
}

double cubo(double raggio)
{
    double cubo = raggio * raggio * raggio;
    return cubo;
}




