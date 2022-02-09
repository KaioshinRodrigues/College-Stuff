#include <iostream>

using namespace std;

struct no {
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no *noPtr;

struct no2{
	int info;
	struct no2 *prox;
};
typedef struct no2 *noPtr2;

int total = 0;
noPtr2 topo3 = NULL, fim;


 bool listaVazia(noPtr inicio){

        if(inicio == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int inserir (noPtr * i, int q) {

    noPtr p = new no;

    cout << "\nDigite o valor do elemento: ";
    cin >> p->info;

    if (listaVazia(*i))
   {
    *i = p;
    p->prox = NULL;
    p->ant = NULL;
   }

    else {
    p->ant= NULL;
    p->prox = *i;
    (*i)->ant = p;
    *i = p;
    }

 total++;

    q++;
    return q;

}

void retirar (noPtr * i)
{
    noPtr p = *i;

    if (!listaVazia(*i))
 {
    if (p->prox == NULL)
    *i = NULL;
    else
 {
    *i = p->prox;
    (*i)->ant = NULL;
 }
    delete(p);
    cout << "\nO elemento foi retirado da lista!\n";
 }
    else cout << "\n\nLista esta Vazia!\n";

    total--;
}

void listar(noPtr p)
{
    if (!listaVazia(p))
 {
    cout << "\nElementos da lista : \n";
    cout << "inicio"<<endl;

    while (p != NULL)
{
    cout << " --> " << p->info;
    p = p->prox;
 }
    cout << " -- > NULL"<<endl;
}
    else
    cout << "\n\nLista esta Vazia!\n";
}

void maiorElemento(noPtr l1, noPtr l2){

    int x = l1->info;
    int y = l2->info;

    while (l1->prox != NULL){
        if (x < l1->info){
            x = l1->info;
        }
        l1 = l1->prox;
    }
    if(l1->prox == NULL){
		if(x < l1->info){
			x = l1->info;
		}
	}

     while (l2->prox != NULL){

        if (y < l2->info){
            y = l2->info;
        }
        l2 = l2->prox;
    }

    if(l2->prox == NULL){
		if(y < l2->info){
			y = l2->info;
		}
    }

    if (x > y){
        cout << "\nMaior elemento e o "<< x <<" e esta na Lista 1";
    }
    else if (y > x){
        cout << "\nMaior elemento e o "<<y<<" e esta na lista 2";
    }
    else if (x == y){
        cout << "\nO maior elemento da lista L1 e L2 sao iguais "<< x << " = " << y;
    }
}

void intercala(noPtr l1, noPtr l2, noPtr2 *m){

    while(l1 != NULL || l2 != NULL){
     if(topo3 == NULL){
        noPtr2 p = new no2;
		p->info = l1->info;
		topo3 = p;
		*m = p;
		p->prox = *m;
		l1 = l1->prox;
		}
     else{
		if(l2 != NULL){
            noPtr2 p = new no2;
			p->prox = topo3;
			p->info = l2->info;
			topo3 = p;
			(*m)->prox = p;
			l2 = l2->prox;
			}
        if(l1 != NULL){
            noPtr2 p = new no2;
            p->prox = topo3;
            p->info = l1->info;
            topo3 = p;
            (*m)->prox = p;
            l1 = l1->prox;
			}
		}
	}
	cout << "\nlista criada!";

	noPtr2 aux = topo3;

	cout << "\nElementos da lista 3:\n";
	cout << "INICIO";
	for(int i = 0; i < total; i++){
		cout << " -> " << aux->info;
		aux = aux->prox;
	}
	cout << " -> NULL";
}

    main()
{
    int op, aux;
    int qtde1 = 0, qtde2 = 0;
    noPtr topo1 = NULL;
    noPtr topo2 = NULL;

 do {
    cout << endl
         <<"\n1. Inserir elementos nas listas"
         <<"\n2. Retirar elementos das listas"
         <<"\n3. Listar elementos das listas"
         <<"\n4. Verificar qual o maior elemento das listas"
         <<"\n5. Intercalar listas"
         <<"\n0. Sair"
         <<"\n\nDigite a opcao que deseja: ";
    cin >> op;
switch (op){
    case 1:
        do{
        cout <<  endl
        << "Informe qual lista deseja usar (1 ou 2), digite 0 para sair: ";
        cin >> aux;
        switch(aux){
          case 1:
            qtde1 = inserir(&topo1, qtde1); cout << qtde1; break;
          case 2:
            qtde2 = inserir(&topo2, qtde2); cout << qtde2; break;
        }
        }while(aux != 0);
        break;
    case 2:
        do{
        cout <<  endl
        << "Informe qual lista deseja usar (1 ou 2): ";
        cin >> aux;
        switch(aux){
          case 1:
             retirar(&topo1); break;
          case 2:
            retirar(&topo2); break;
        }
        }while(aux != 0);
        break;
    case 3:
        do{
        cout <<  endl
        << "Informe qual lista deseja usar (1 ou 2): ";
        cin >> aux;
        switch(aux){
          case 1:
             listar(topo1); break;
          case 2:
             listar(topo2); break;
        }
        }while(aux != 0);
    case 4: maiorElemento(topo1, topo2); break;
    case 5: intercala(topo1, topo2, &fim); break;
    }
  } while (op != 0);
}
