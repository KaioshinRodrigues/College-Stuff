#include <stdio.h>

float main() 
{

float gasto;
float garcom;

   printf("Digite a quantidade do pagamento: ");
   scanf("%f", &gasto); 
   garcom = gasto * 0.1;

   printf("Valor da gorjeta: %.02lf\n", garcom);

   printf("----------\n");

   printf("Total obtido de gorjeta:   R$%.02lf\n", garcom);
   return 0;

}