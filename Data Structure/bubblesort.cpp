#include <bits/stdc++.h>
using namespace std;

//Faz a troca de posições entre j e j+1
void troca(int *xp, int *yp)
{
    int aux = *xp;
    *xp = *yp;
    *yp = aux;
}
//Intera pelo array, mas diferente ao bubble que vimos em classe testa os valores booleanos para saber se seria necessario uma interação de checagem.
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool trocado;
   for (i = 0; i < n-1; i++)
   {
     trocado = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           troca(&arr[j], &arr[j+1]);
           trocado = true;
        }
     }
     // Dado que os loops internos não fizeram uma troca é presumido que o array já foi arrumado, o algoritmo então quebra e evita uma interação extra para confirmar se o array está de fato em ordem.
     if (trocado == false)
        break;
   }
}
int main()
{  // Melhor caso {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    int arr[] = {10, 6, 9, 8, 5, 4, 2, 3, 1, 7,};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    int i;
    cout <<"Array arrumado: \n";
    for (i = 0; i < n; i++)
        cout <<" "<< arr[i];
    return 0;
}
 