#include <iostream>
using namespace std;

void visualizacaoDoProcesso(int pivo,int inicio,int fim,int vetor[]){
    cout << endl <<pivo << ": ";
    for(int k=inicio; k<fim+1;k++){
        cout <<vetor[k]<<" ";
    }
}

int particiona (int vetor[], int inicio, int fim) {
    int pivo = vetor[inicio + (fim - inicio) / 2];
    int i = inicio - 1;
    int j = fim + 1;
    
    while (true) {
        do {
            i++;
        }while (vetor[i] < pivo);
        
        do {
            j--;
        }while (vetor[j] > pivo);
        
    
        if (i >= j){
            visualizacaoDoProcesso(pivo,inicio,fim,vetor);
            return j;
        }
        swap(vetor[i],vetor[j]);
    } 
} 

void quicksort(int vetor[], int posPivo, int fim) {
    int novoPivo;
    if (posPivo < fim) {
        novoPivo = particiona(vetor, posPivo, fim);
        quicksort(vetor, posPivo, novoPivo); 
        quicksort(vetor, novoPivo + 1, fim); 
    } 
}

int main (){
    int qtd;
    cin >> qtd;
    int vetor[qtd];
    
    for(int i=0; i<qtd;i++){
        cin >> vetor[i];
    }
    
    quicksort(vetor,0,qtd-1);
    
    cout << endl;
    
    for(int i=0; i<qtd;i++){
        cout<<vetor[i] << " ";
    }
    
    return 0;
}
