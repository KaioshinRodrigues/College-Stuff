#include <iostream>
#include <stdlib.h>
using namespace std;

struct buffer{
	int cod;
	struct buffer* next;
};
typedef struct buffer * bufferPtr;
bufferPtr top = NULL;
bufferPtr last = NULL;

bool emptyList();
void enqueue();
void dequeue();


int main(){
	int op;

	do{
		cout << "Escolha uma opcao: \n";
		cout << "0: Sair \n";
		cout << "1: Enviar pacote \n";
		cout << "2: Imprimir Pacote \n";
		cin >> op;
		switch (op){
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
		}
		if (op!=0 && op!=1 && op!=2){
			cout << "Opcao invalida! \n\n";
		}
	}while (op!=0);


return 0;
}

bool emptyList(){
	if (top == NULL){return true;}
	return false;
}
void enqueue(){
	bufferPtr p = new buffer;
	cout << "Insira o codigo do pacote: ";
	cin >> p -> cod;
	p -> next = NULL;
	if (emptyList()){
		top = p;
		last = p;
	}
	else{
		bufferPtr aux = last;
		aux -> next = p;
		last = p;
	}

}
void dequeue(){
	if (emptyList()){
		cout << "O Buffer esta vazio! \n\n";
	}
	else {
		bufferPtr p = top;
		top = p -> next;
		cout << "O elemento de codigo " << p -> cod << " foi impresso" << endl;
		delete p;
	}

}
