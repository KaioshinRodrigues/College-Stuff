//Caio Rodrigues da Silva
#include <stdio.h>
#define TOT 500
#define MAX 21

//Stores the employees age range
typedef struct {
int ate;
int acima;
} Funcio;
//initializes each position in the vector 0 as value
void inicializa(Funcio v[]){
 int i;
 for(i=0; i<TOT; i++){
     v[i].ate = 0;
     v[i].acima = 0;
 }
}
//Goes through all the 500 employees and prints the ones with age above/less than 45 years
void exibe(Funcio *v){
 int cod; 
  for(cod=0; cod < TOT; cod++){
   printf("\nDepartamento %d: %d funcionários até 45 anos e %d acima de 45 anos", cod + 1, v[cod].ate, v[cod].acima);
  }        
}
//Gets input on the department and age of each employee
int main(){
 int i, cod, idade;
 i = 0;
 Funcio v[MAX];
 for(i = 0; i < TOT; i++){
 printf("\ndigite o seu departamento (1-20):");
 scanf("%d",&cod); 
 printf("\ndigite a sua idade:");
 scanf("%d",&idade);
 if(idade <= 45)
   v[cod-1].ate++;
    else
    v[cod-1].acima++;
 }

 return 0;
}

