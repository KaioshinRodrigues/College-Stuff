
int main ()
{
   int qtdAlunos, qtdAprov;
   float percRepr;
   printf("insira a quantidade de alunos: ");
   scanf("%d", &qtdAlunos);
   printf("insira a quantidade de aprovados: ");
   scanf("%d", &qtdAprov);
   
   percRepr = (float)(qtdAlunos - qtdAprov) * 100.0 / qtdAlunos;
 
   printf("Porcentagem de %d e %d é = %.2f% reprovados",qtdAlunos,qtdAprov, percRepr);

   return 0;
}