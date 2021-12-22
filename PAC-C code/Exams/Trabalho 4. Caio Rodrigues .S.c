//Caio Rodrigues da Silva

#include <stdio.h>
#define TOT 100
//Reads the product type
int leValidaTipo(){
    int tipo;
    do{
  printf("\ndigite o tipo do produto (1 - 2 - 3): ");
  scanf("%d",&tipo);
    }while(tipo < 1 || tipo > 3);
    return tipo;
}

//Multiplies each product by their percentual raise for their type and passes the amount desired on store
void dadosProduto(int tipoProd ,float *perc,int *qtdMaxDes){
    if (tipoProd == 1){
       *perc = 1.5;
       *qtdMaxDes = 100;       
       }   
      else if (tipoProd == 2){
         *perc = 2.5;
         *qtdMaxDes = 200;
         }      
          else{
           *perc = 3.5;  
           *qtdMaxDes = 300;
           }                
}
//Gets the price, code and prints the maximun quantity desired and the new price after changes
int main(){
    int i, tipo, cod, qtdMaxDes;
    float perc, preUni, novoPreco;
    for(i = 0; i < TOT; i++){
    tipo = leValidaTipo();
    printf("\ninsira o preço da unidade: ");
    scanf("%f",&preUni);    
    dadosProduto(tipo, &perc, &qtdMaxDes);
    printf("\ninsira o codigo do produto: ");
    scanf("%d",&cod);
    novoPreco = preUni + preUni * perc/100;
  printf("\ncodigo do produto: %d", cod);
  printf("\ntipo do produto: %d", tipo);
  printf("\nquantidade maxima desejada em estoque: %d",qtdMaxDes);
  printf("\npreço unitario atualizado: %.2fR$", novoPreco); 
  }

  return 0;
}


