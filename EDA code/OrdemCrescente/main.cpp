#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * esq, * dir;
};
typedef struct no *noPtr;

/* A complexidade nesse caso seria igual a altura dá arvore. A complexidade seria O(n) aonde (n) seria
a quantidade nós da arvore, se a arvore estiver balanceada o pior caso ficaria O(log n) já que a busca
poderá ser mais efetiva */


void emOrdem (noPtr raiz) {
   if (raiz != NULL) {
      printf (" %d - ", raiz->info);
      emOrdem (raiz->esq);

      emOrdem (raiz->dir);
   }
}

noPtr inserirNo(int info)
{
    noPtr raiz = new no;
    raiz->info = info;
    raiz->esq = raiz->dir = NULL;
    return (raiz);
}

int main()
{
    /* Essa arvore vai ser lida na ordem Esquerda -> Raiz -> Direita que é uma ordem crescente

              20
            /    \
          13      30
         /  \    /  \
        9   17  28   33

   */

    noPtr raiz = inserirNo(20);
    raiz->esq = inserirNo(13);
    raiz->dir = inserirNo(30);
    raiz->esq->esq = inserirNo(9);
    raiz->esq->dir = inserirNo(17);
    raiz->dir->esq = inserirNo(28);
    raiz->dir->esq->esq = inserirNo(28);
    raiz->dir->dir = inserirNo(33);

    emOrdem(raiz);

    return 0;
}
