#include <iostream>
#define T 10

using namespace std;

//A complexidade de pior caso e O(n lg n)

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void descer(int A[], int i, int q){
    int d = 2 * i + 2;
    int e = 2 * i + 1;
    int maior = i;
    if(d <= q && A[d] > A[i])
        maior = d;
    if(e <= q && A[e] > A[maior])
        maior = e;
    if(maior != i){
        troca(&A[i],&A[maior]);
        descer(A,maior,q);
    }
}


void subir(int A[], int i){
    int j = i/2;
    if(j >= 0)
        if(A[i] > A[j]){
        troca(&A[i],&A[j]);
        subir(A,j);
    }
}

void inserir(int A[], int valor, int *t){
    *t = *t + 1;
    A[*t] = valor;
    subir(A,*t);
}

void remover(int A[], int *q){
    A[0] = A[*q];
    *q = *q - 1;
    descer(A,0,*q);
}

void heap(int A[], int t){
    for(int i = (t/2); i >= 0; i--)
        descer(A, i, t - 1);
}

void heapsort(int A[], int n){
    int i;

    heap(A, T);
    for(i = n - 1; i >= 1; i--){
        troca(&A[0], &A[i]);
        descer(A, 0, i-1);
    }
}

int main()
{
    int A[T] = {12,10,11,8,9,1,4,5,7,2};
    int i;
    heapsort(A,T);
    for(i=0; i<T; i++){
      cout << A[i] << " ";
    }
}
