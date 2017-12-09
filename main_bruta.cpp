#include <iostream>

using namespace std;

typedef struct{
    int atual;
    int prox;
}josephus;

int inicializa(int n){
    cout << "Inicializando os vetores com " << n << " posicoes" << endl;
    josephus vet[n-1];
    int resultado;
    if (n==1){
        resultado = 1;
        return resultado;
    }
    for(int i=0; i<n; i++){
        vet[i].atual = i+1;
        vet[i].prox = i+1;
        if (i==n-1)
            vet[n-1].prox = 0;
        cout << "Posicao " << i << " = " << vet[i].atual
        << "    Aponta para = " << vet[i].prox << endl;
    }

        int quantidade = n-1;
        int i = 0;
        while(quantidade >= 1){
            cout <<"Turno do soldado -> " << i+1 << endl;
            cout << "Soldado morto -> " << (vet[i].prox)+1 << endl;
            vet[i].prox = vet[vet[i].prox].prox;

            quantidade = quantidade-1;
            i = vet[i].prox;
            }
            cout << "Soldado vencedor -> " << vet[i].atual << endl;
            return vet[i].atual;
};
int main()
{
    int n;
    cout << "Numero total de soldados -> " << endl;
    cin >> n;
    inicializa(n);
    while (cin.get() != 'k') {
        cout << "Pressione k para sair -> ";
    }
    return 0;
}
