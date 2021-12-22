#include <stdio.h>
 
int main ()
 
{ 
int horas, minutos, totmin;
printf("Porfavor colocar horas e minutos: \n");
printf("\t horas:minutos = "); 
scanf("%d:%d",&horas,&minutos); 
totmin=horas*60; 
totmin=totmin+minutos;
printf("\n\t %d horas:%d minutos = %d minutes",horas,minutos,totmin);
 return totmin;


}