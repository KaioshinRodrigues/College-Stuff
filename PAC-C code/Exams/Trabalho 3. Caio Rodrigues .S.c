//Caio Rodrigues da Silva
#include <stdio.h>

int leValidaQtd();
//Reads the matriculation and salary of each employee
float umDepartamento (int qtdfuncio)
{
  int i, mat;
  float sal,salMaior;
  salMaior = 0;  
  for(i = 0; i < qtdfuncio; i++){
      printf("\ninsira a matrícula:");
      scanf("%d",&mat);
      printf("\ninsira o salário:");
      scanf("%f",&sal);  
      if(sal > salMaior)
        salMaior = sal;
   }
   printf("\nMaior salário do departamento: %.2f",salMaior);
  
   return salMaior;
 }
//Sets the input for the function that will get the number of employees and shows the biggest salary in the department   
int main()
{
  int cod, qtd;
  float maiordepto, maiorger;
  maiorger = 0;
  printf("Digite 0 para encerrar:");
  scanf("%d",&cod);
  while(cod != 0){
    qtd = leValidaQtd();
    if(maiordepto > maiorger)
     maiorger = maiordepto;  
   printf("\nDigite 0 para encerrar:");
   scanf("%d",&cod);
  }
  printf("Maior salario geral: %.2f", maiorger); 
  return 0; 
}
//Gets the number of employees between 1 and 1000
int leValidaQtd()
{
  int qtd;
  do{
    printf("Qual a quantidade de funcionários?");
    scanf("%d",&qtd);
     }while(qtd < 1 || qtd > 1000);

    return qtd;
  }

  
  