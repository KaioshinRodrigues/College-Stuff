#include <bits/stdc++.h>
using namespace std;
 
void insertionSort(int arr[], int n)
{
    int i, pivo, j;
    for (i = 1; i < n; i++)
    {
        pivo = arr[i];
        j = i - 1;
        /* Move os elementps do array, que são maiores que o pivo, para uma posição acima da atual */
        while (j >= 0 && arr[j] > pivo)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = pivo;
    }
}

int main()
{ // Pior caso {13, 12, 11, 10, 7, 6, 5, 4, 3}
  // Melhor caso {3, 4, 5, 6, 7, 9, 10, 11, 12, 13}
    int i, arr[] = { 12, 11, 13, 5, 6, 9, 10, 4, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);
    cout <<"Array arrumado: \n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
 
    return 0;
}