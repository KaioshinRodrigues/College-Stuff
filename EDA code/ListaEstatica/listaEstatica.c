#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

//Static list ordenation using dual pivot quicksort.
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
