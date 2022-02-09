//Caio Rodrigues da silva
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

/* A escolha do quicksort foi dada pelo seu desempenho em comparação aos demais algoritmos de ordenação por divisão e conquista,
especialmente a versão com pivo duplo usada, porém mesmo que essa seja uma versão mais atualizada do algoritmo ele ainda tem
uma complexidade de pior caso que é compáravel ao do bubble sort dado que T(n)=(n-1)+O(n) resultará em T(n)=(O^2) o que é
inescapavel para o quicksort, quando encontrado com o caso onde as chamadas recursivas geram partições desbalanceadas com
tamanho 0 e n-1 elementos que ocorre quando o array está ordenado de forma crescente ou decrescente no qual o pivo é o maior
ou menor elemento dependente ao método de implementação, se esse desbalanceamento acontecer a cada chamada então recursivamente
a cada etapa serão separadas listas de tamanho iguais a anterior, mesmo que o algoritmo tenha esta pequena vulnerabilidade a
eficiência do quicksort é trazida a frente no seu melhor caso e no seu caso de complexidade médio que porém de ser o mesmo que
o do mergesort O(n log n) supera a sua velocidade pela forma como os dois algoritmos utilizam-se de partições e trocas.
*/

//Lista estática com ordenação usando quicksort.
int main()
{
    int V[MAX], i, op;
    srand(time(NULL));
    for(i = 0; i < MAX; i++){
        V[i] = rand()%50;
    }

    do{
        printf ("\n1. Ordenar \n2. Listar elementos da lista \n0. Sair \nInforme a opcao: ");
        scanf("%d",&op);
        switch(op){
            case 1: quicksortPivoD(V, 0, MAX - 1);
            break;
            case 2: imprimirLista(V, MAX);
            break;
        }
    } while(op != 0);

    return 0;
}

void imprimirLista(int V[], int size){
   int i;
   for (i=0; i < size; i++){
      printf(" %d >", V[i]);
   }
}

void quicksortPivoD(int V[], int esq, int dir){
  if(esq < dir){
    int pivoEsq, pivoDir;
    pivoDir = particiona(V, esq, dir, &pivoEsq);
    quicksortPivoD(V, esq, pivoEsq - 1);
    quicksortPivoD(V, pivoEsq + 1, pivoDir - 1);
    quicksortPivoD(V, pivoDir + 1, dir);
  }
}

int particiona(int V[], int esq, int dir, int *pivoEsq){
  if (V[esq] > V[dir])
    troca(&V[esq], &V[dir]);

  int j = esq + 1;
  int g = dir - 1, k = esq + 1, p = V[esq], q = V[dir];
  while (k <= g) {
    if (V[k] < p) {
        troca(&V[k], &V[j]);
        j++;
    }
    else if (V[k] >= q) {
        while (V[g] > q && k < g)
            g--;
        troca(&V[k], &V[g]);
        g--;
        if (V[k] < p) {
            troca(&V[k], &V[j]);
            j++;
        }
    }
       k++;
    }
    j--;
    g++;

    troca(&V[esq], &V[j]);
    troca(&V[dir], &V[g]);

    *pivoEsq = j;

    return g;
}

void troca(int* a, int* b){
   int t = *a;
   *a = *b;
   *b = t;
}
