#include <iostream>

using namespace std;

struct no{
    int info;
    struct no *prox;
};
typedef struct no* noPtr;

noPtr top = NULL;
noPtr last = NULL;

void inicializa(Lista *lista){
    lista->inicio = NULL;
    lista->ult = NULL;
    lista->qtd = 0;
}

void inserir(Lista *lista, int num){
    noPtr p = new no;
    p->info = num;
    if (emptyList()){
		top = p;
		last = p;
	}
	else{
		bufferPtr aux = last;
		aux -> next = p;
		last = p;
	}
    p->prox = lista->inicio;
    if(lista->ult == NULL){
        lista->ult = p;
        lista->ult->prox = lista->inicio;
        lista->qtd++;
    }
    else cout <<"\nLista está vazia!";

}

noPtr retirar(Lista *lista, int num){
    noPtr aux, retirar = NULL;
    if(lista->inicio){
      if(lista->inicio == lista->fim && lista->inicio->valor == num){
        retirar = lista->inicio;
        lista->inicio = NULL;
        lista->ult = NULL;
        lista->tam--;
      }
      else if(lista->inicio->info == num){
        retirar = lista->inicio;
        lista->inicio;
        lista->tam--;
      }
      else{
        aux = lista->inicio;
        while(aux->prox != lista->inicio && aux->prox->info != num)
            aux = aux->prox;
        if(aux->prox->info == num){
            if(lista->ult == aux->prox){
                retirar = aux->prox;
                aux->prox = retirar->prox;
                lista->fim = aux;
            }
            else{
                retirar = aux->prox;
                aux-prox = retirar->prox;
            }
            lista->tam--;
        }
     }
   }
  return retirar;
}

void listar(Lista lista){
    no *no = lista.inicio;
    cout << "\n\tLista tamanho " << lista->qtd;
    if(no){
        do{
            cout << no->info;
            no = no->prox;
        } while(no != lista.inicio);
        cout << "\nInicio: " << no->valor;
    }
    else cout << "\n\nLista vazia!\n";
}

bool emptyList(){
	if (top == NULL){return true;}
	return false;
}

int main()
{
    int op, valor;

    do{
        cout << "\n\t0 - Sair  1 - Inserir 2 - Retirar  3 - Listar";
        cin >> op;
        switch(op){
            case 1:
            cout << "\nDigite um valor:";
            cin >> valor;
            inserirInicio(&lista, valor); break;
            case 2:
            retirar(&topo, &qtde); break;

            case 3: listar(topo, qtde); break;
        }
    } while(op != 0);
}
