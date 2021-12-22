#include <stdio.h>
 
void funcaoMaior (int maior)

{
int num1,num2;
 if (num1 > num2)
 maior = num1;
  else
  if (num2 > num1)
 maior = num2;
}
 
int main(funcaoMaior)
{
  int num1, num2;
  int maior;
  maior = num1;
 
  printf ("insira o primeiro número:\n");
  scanf ("%d",&num1);
  printf ("insira o segundo número:\n");
  scanf ("%d",&num2);
  printf ("o maior desses dois números é %d", &maior);
  return 0;
}