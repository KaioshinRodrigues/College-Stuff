#include <stdio.h>

void tabuada (multiplo)
{
int num;
int cont = 0;

while (cont < multiplo)
{
 num + num;
cont++;
}

}

int main()
{
  int num;
  int multi;
  printf("Insira o número a multiplicar:\n");
  scanf("%d",&num);
  printf("insira o multiplicador:\n");
  scanf("%d",&multi);
  tabuada (multi);

  return 0;
}