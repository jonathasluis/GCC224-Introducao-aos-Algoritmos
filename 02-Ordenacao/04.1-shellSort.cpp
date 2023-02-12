#include <iostream>
using namespace std;

void shellsort(float vetor[], int tamanho){
    int gaps[5] = {1, 3, 7, 15, 31};
    int posGap = 4;
    int cont=0;
    
    while(gaps[posGap] > tamanho){//loop sequencia
        posGap--;
    }
    
    float aux;
    int j;
    
    while(posGap >= 0){
        int gap = gaps[posGap];
        
        for(int i = gap; i < tamanho; i++) {
            aux = vetor[i];
            j = i - gap;
            while ((j >= 0) and (aux < vetor[j])){
                vetor[j+gap] = vetor[j];
                j=j-gap;
                cont++;
            }
            vetor[j+gap] = aux;
            cont++;
        }
        
        posGap--;
        
        cout << endl << gap << ":";
        for(int i =0; i < tamanho; i++){
            cout << " "<< vetor[i];
        }
    }
    
    cout << endl << cont;
}

int main(){
    int tam;
    cin >> tam;
    float vetor[tam];
    
    for(int i = 0; i < tam; i++){
        cin>>vetor[i];
    }
    
    shellsort(vetor,tam);
    return 0;
}
