#include <iostream>

using namespace std;

struct no{
    int info;
    struct no * esq, * dir;
};
typedef struct no *noPtr;

int contaNoFolha(noPtr raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    return contaNoFolha(raiz->esq) + contaNoFolha(raiz->dir);
}

int somatorio(noPtr raiz, int soma){

 if(!((raiz->esq) == NULL && ((raiz->dir) != NULL))){

	soma += (raiz->info);
    soma = somatorio(raiz->dir, soma);
    soma = somatorio(raiz->esq, soma);
}
 else if(!((raiz->dir) == NULL)){
	soma = somatorio(raiz->dir, soma);
}
 else if(!((raiz->esq) == NULL)){
	soma = somatorio(raiz->esq, soma);
}
 cout << "valor" << soma;
 return soma;
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
 /*
    Arvore com 6 elementos que vai ser contada:

         8
       /   \
      5     9
    /  \      \
   3    7      12

*/

    noPtr raiz = inserirNo(8);
    raiz->esq = inserirNo(5);
    raiz->dir = inserirNo(9);
    raiz->esq->esq = inserirNo(3);
    raiz->esq->dir = inserirNo(7);
    raiz->dir->dir = inserirNo(12);


}
