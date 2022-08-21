#include "stdio.h"
#include "stdlib.h"

int numero_da_inizio_anno(int giorno, int mese, int anno);
int chkdate (int g, int m, int a);
int giorni_del_mese (int mese, int anno);
int bisestile (int anno);


int main()
{
    int giorno, mese,anno,numero_giorni;

    scanf("%d %d %d", &giorno, &mese, &anno);
    if(chkdate(giorno, mese, anno) == 0)
    {
        printf("non valida\n");
    }

    numero_giorni = numero_da_inizio_anno(giorno, mese, anno);
    printf("%d\n",numero_giorni);

    exit(EXIT_SUCCESS);
}

int numero_da_inizio_anno(int giorno, int mese, int anno)
{
    int mese_corrente,numero_giorni;
    numero_giorni = 0;
    mese_corrente = 1;

    while(mese_corrente < mese)
    {
        numero_giorni = numero_giorni + giorni_del_mese(mese_corrente, anno); 
        mese_corrente++;  
    }

    numero_giorni = numero_giorni + giorno;

    return numero_giorni;
}

int chkdate (int giorno, int mese, int anno)
{

   if (anno < 1582)
      return 0;  


   if (mese < 1 || mese > 12)
      return 0;  

   if (giorno < 1 || giorno > giorni_del_mese (mese, anno))
      return 0; 

   return 1; 
}

int giorni_del_mese (int mese, int anno)
{
   switch (mese)
   {
      case 11:
      case 4:
      case 6:
      case 9: return 30;

      case 2: if (bisestile(anno))
                 return 29;
            else
                 return 28;

      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12: return 31;

      default: printf ("numero del mese non valido: %d\n", mese);
               exit (EXIT_FAILURE);
   }
}

int bisestile (int anno)
{
   if ( ( (anno % 4 == 0) && (anno % 100 != 0) )   ||   (anno % 400 == 0) )
      return 1;
   else
      return 0;

}