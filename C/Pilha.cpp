#include <iostream>
using namespace std;

struct Pilha {
    int num;
    Pilha *prox;
};

int main() {
    
    Pilha *topo = NULL;
    Pilha *aux;
    int op;

    do {
        cout << "\n1 - Inserir na pilha";
        cout << "\n2 - Consultar pilha";
        cout << "\n3 - Remover do topo";
        cout << "\n4 - Esvaziar pilha";
        cout << "\n5 - Sair";
        cout << "\nOpcao: ";
        
        cin >> op;

        if (op == 1) {
            
            Pilha *novo = new Pilha;
            
            cout << "Digite o numero a ser inserido na pilha: ";
            cin >> novo->num;
            
            novo->prox = topo;
            topo = novo;
            
            cout << "Numero inserido na pilha\n";
        } 
        else if (op == 2) {
            
            if (topo == NULL) {
                
                cout << "Pilha vazia!\n";
            } else {
                
                cout << "Consultando pilha: ";
                aux = topo;
                
                while (aux != NULL) {
                    
                    cout << aux->num << " ";
                    aux = aux->prox;
                }
                cout << "\n";
            }
        } 
        else if (op == 3) {
            
            if (topo == NULL) {
                
                cout << "Pilha vazia!\n";
            } else {
                
                aux = topo;
                cout << "Numero " << topo->num << " removido\n";
                topo = topo->prox;
                delete aux;
            }
        } 
        else if (op == 4) {
            
            if (topo == NULL) {
                
                cout << "Pilha vazia!\n";
            } else {
                
                while (topo != NULL) {
                    
                    aux = topo;
                    topo = topo->prox;
                    delete aux;
                }
                cout << "Pilha esvaziada\n";
            }
        } 
        else if (op != 5) {
            
            cout << "Opcao invalida!\n";
        }

    } while (op != 5);

    return 0;
}
