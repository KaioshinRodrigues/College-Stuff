//Caio Rodrigues da silva

#include <stdio.h>
//Calculates the IMC using the weights and height
float calcIMC(float ps, float alt){
  float IMC;
  IMC = ps / (alt * alt);
  return IMC;
  } 
//Evaluates your IMC change after 6 months of activity
void situacao(float imchegada ,float imcatual){
  int mat;
  printf("Inserir a sua matrícula:\n");
  scanf(" %d",&mat);
  printf("Matricula:%d",mat);
 if (imchegada == imcatual) { 
   printf("\nVocê chegou com IMC de %.2f", imchegada);
   printf("\nApós 6 meses está com um IMC de %.2f que não mudou e se estabilizou", imcatual);    
 }    
 else
  if (imchegada > imcatual){  
  printf("\nVocê chegou com IMC de %.2f", imchegada);
  printf("\nApós 6 meses está com um IMC de %.2f e sua situação melhorou", imcatual);
  }     
   else{
    printf("\nVocê chegou com IMC de %.2f", imchegada);
    printf("\nApós 6 meses está com um IMC de %.2f e  piorou", imcatual);    
    }
}
//Gets input on the height, current weight, weight on arrival and prints the weight after 6 months of activity
 int main (){
  float alt,pesentrada, pesatual, imchegada, imcatual;
  printf("Sua altura em metros por favor:");
  scanf("%f",&alt);
  printf("Seu peso em kg ao entrar na academia:");
  scanf("%f",&pesentrada);
  printf("Seu peso em kg após seus 6 meses de atividade:");
  scanf("%f",&pesatual);
  imchegada = calcIMC(pesentrada,alt);
  imcatual = calcIMC(pesatual,alt);
  situacao (imchegada,imcatual);
  
  return 0;
}
