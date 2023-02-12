#include <iostream>
using namespace std;

void intercala(int vetor[],int inicio,int meio, int fim){
    int i = inicio, j = meio + 1;
    int tamanho = fim - inicio + 1;
    int aux[tamanho];
    
    int x;
    for(x = inicio; x < j; x++){
        cout << vetor[x] << " ";
    }
    
    cout << "+ ";
    
    for(x = j; x <= fim; x++){
        cout << vetor[x] << " ";
    }
    
    cout << "= ";
    
    for(int k = 0; k < tamanho; k++){
        if((i <= meio) and (j <= fim)){
            if(vetor[i] <= vetor[j]){
                aux[k] = vetor[i];
                i++;
            }else{
                aux[k] = vetor[j];
                j++;
            }
        }else if (i > meio){
            aux[k] = vetor[j];
            j++;
        }else{
            aux[k] = vetor[i];
            i++ ;
        }
    }
    
    for(int k = 0; k < tamanho; k++){
        cout << aux[k] << " ";
        vetor[inicio + k] = aux[k];
    }
    cout << endl;
}

void margesort(int vetor[],int inicio,int fim){
    int meio;
    
    if(inicio < fim){
        meio = (inicio + fim) / 2;
        margesort(vetor,inicio,meio);
        margesort(vetor,meio+1,fim);
        intercala(vetor,inicio,meio,fim);
    }
}

int main(){
    int qtd;
    cin >> qtd;
    int vetor[qtd];
    
    for(int i = 0; i < qtd; i++){
        cin >> vetor[i];
    }
    
    margesort(vetor,0,qtd-1);
    
    /*for(int i = 0; i < qtd; i++){
        cout << vetor[i] << " ";
    }*/
    
    return 0;
}
