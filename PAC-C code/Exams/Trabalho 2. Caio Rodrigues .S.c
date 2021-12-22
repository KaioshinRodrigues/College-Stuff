
//Caio Rodrigues da Silva
  
#include <stdio.h>
//Does the calculation to pass on for the measurement of growth
float calculaIDH(float E,float L,float R){  
  float LR, IDH;
  LR = L + R;
  if(E == LR || E > LR){
   IDH = E * L * R / ((E + L + R)/3);
    }
     else{
       IDH = (E + L + R)/3;
       }
   return IDH;
  }
 //Shows the growth in human development based on the raise of the IDH
 void exibeDesenvolvimento (float desenvolvimento){
   
   if (desenvolvimento == 0){
        printf("nenhum desenvolvimento humano");
        }
     else if (desenvolvimento > 0 && desenvolvimento < 0.5){
        printf("baixo desenvolvimento humano");
        }
      else if (desenvolvimento > 0.5 && desenvolvimento < 0.8){
        printf("médio desenvolvimento humano");
        }
       else if (desenvolvimento > 0.8 && desenvolvimento < 1.0){
        printf("alto desenvolvimento humano");
        }
          else{
         printf("desenvolvimento humano total"); 
         }
  }

//Gets the rates of education, longevity and richness to calculate the IDH
int main()
{
  float educacao, longevidade, riqueza, desenvolvimento;
  printf("Estática de educação:");
  scanf("%f",&educacao);
  printf("longevidade:");
  scanf("%f",&longevidade);
  printf("riqueza:");
  scanf("%f",&riqueza);
  desenvolvimento = calculaIDH(educacao,longevidade,riqueza);
  exibeDesenvolvimento(desenvolvimento);
  
  return 0;
}