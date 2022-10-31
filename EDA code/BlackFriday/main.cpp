#include <iostream>
#include <stdlib.h>
using namespace std;

struct cliente{
	int cod;
	struct cliente* prox;
};
typedef struct cliente * clientePtr;
clientePtr topo = NULL, ult = NULL;

bool filaVazia(){
	if (topo == NULL)
        return true;
    else
        return false;
}

void darCodigo(){
	clientePtr p = new cliente;
	cout << "\nDe um codigo para o cliente:";
	cin >> p -> cod;
	p->prox = NULL;
	if (filaVazia()){
		topo = p;
		ult = p;
	}
	else{
		clientePtr aux = ult;
		aux->prox = p;
		ult = p;
	}

}

void atenderCliente(){
	if (filaVazia()){
		cout << "\nNao tem clientes com codigos na fila!";
	}
	else {
		clientePtr p = topo;
		topo = p->prox;
		cout << "\nO cliente de codigo " << p->cod << " foi atendido" << endl;
		delete p;
	}
}

int menu(){
    int op;
    cout << "\n\n\n---- Menu Principal ----\n\n"
         << "\n1.Dar o codigo de atendimento para um cliente"
         << "\n2.Atender cliente com codigo na fila"
         << "\n0.Sair"
         << "\nDigite uma opcao: ";
    cin >> op;
    return op;
}

int main(){
	int op;

	do{
        op = menu();
		switch (op){
			case 1: darCodigo();
				break;
			case 2: atenderCliente();
				break;
		}
	   }while (op!=0);

    return 0;
}
