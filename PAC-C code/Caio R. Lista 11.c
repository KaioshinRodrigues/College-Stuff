#include <stdio.h>

void pagamentoDinheiro(float valor)
 {
 float dinheiro,troco,falta;
 printf("insira a quantia de pagamento:\n");
 scanf("%f",&dinheiro);
 
  if (dinheiro == valor)
  {
  printf("não há troco.");
  }
  else
   if (dinheiro > valor)
    {
      troco = dinheiro - valor;
      printf("O valor do seu troco:%.2f",&troco);  
     }
   else 
    { 
      falta = valor - dinheiro;
      printf("O pagamento é insuficiente, aínda falta:%.2f",&troco);
    }
    
   }

int main()
{
  int forma;
  float despesa;
  printf("Qual o valor da despesa:\n");
  scanf("%f",&despesa);
  printf("Qual será a forma de pagamento:\n");
  printf("1 - debito, 2 - crédito - 3 - dinheiro\n");
  scanf("d",&forma);
  switch(forma)
   {
     case 1: printf("não há troco");
            break;
     case 2: printf("não há troco");
            break;
     case 3: pagamentoDinheiro (despesa);
            break;
   }
   
  return 0;
}