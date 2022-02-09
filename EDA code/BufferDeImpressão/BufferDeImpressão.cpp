#include <iostream>

using namespace std;

struct buffer{
    int cod;
    struct buffer*prox;
};
typedef struct buffer*bufferPtr;

bufferPtr topo = NULL;

bool listaVazia(){
    if(topo)
        return false;
    else
        return true;
}

void enviar(){
    bufferPtr p;
    int valor;

    p = new buffer;
    cout<<"Digite o codigo do pacote:";
    cin>>valor;
    p-> cod = valor;
    p-> prox = topo;
    topo = p;
}

buffer *imprimir(){
    bufferPtr p = topo;

    if(topo->prox == NULL){

        cout << "\nO buffer de impressao esta vazio" << endl;
        return NULL;
    } else{
        buffer *ult = topo->prox, *penult = topo;
        while(ult->prox != NULL){
           penult = ult;
           ult = ult->prox;
    }
        penult->prox = NULL;

        cout << "\nO pacote foi impresso e retirado." << endl;

        if(!listaVazia()){
        cout <<"\n Codigo dos pacotes"
        << "\n\nespera -> ";
        while(p != NULL){
            cout << p->cod << "\t";
            p = p->prox;
        }
        cout << "-> imprimido\n\n";
    }

        return ult;
    }

}

int main()
{
    int op;

    do{
        cout << "\nInformar o seu uso desejado da impressora:"
         << "\n1. Enviar pacote e armazenar"
         << "\n2. Imprimir pacote e remover"
         << "\n0. Sair"
         << "\n: ";
        cin >> op;
        switch(op){
            case 1: enviar(); break;
            case 2: imprimir(); break;
        }
    } while(op!=0);
}
