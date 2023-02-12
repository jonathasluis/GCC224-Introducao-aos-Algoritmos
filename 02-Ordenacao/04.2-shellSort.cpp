#include <iostream>
using namespace std;

void shellsort(int vetor[], int tamanho,int posGap,int gaps[]){
    int cont=0;
    
    cont++;
    while(gaps[posGap] > tamanho){//loop sequencia
        posGap--;
        cont++;
    }
    
    float aux;
    int j;
    
    cont++;
    while(posGap >= 0){
        cont++;
        int gap = gaps[posGap];
        
        cont++;
        for(int i = gap; i < tamanho; i++) {
            cont++;
            aux = vetor[i];
            j = i - gap;

            cont++;
            while ((j >= 0) and (aux > vetor[j])){
                vetor[j+gap] = vetor[j];
                j=j-gap;
                cont++;
            }
            vetor[j+gap] = aux;
        }
        posGap--;
    }
    cout << endl << cont;
}

int main(){
    int tam;
    int qtdSaltos;
    cin >> tam;
    int vetor[tam];
    
    for(int i = 0; i < tam; i++){
        cin>>vetor[i];
    }
    
    cin >> qtdSaltos;
    
    int gaps[qtdSaltos];
    
    for(int i = 0; i < qtdSaltos; i++){
        cin>>gaps[i];
    }
    
    shellsort(vetor,tam,qtdSaltos-1,gaps);
    
    /*for(int i = 0; i < tam; i++){
        cout << vetor[i];
    }*/
    return 0;
}
