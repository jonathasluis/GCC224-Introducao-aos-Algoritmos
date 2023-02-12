#include <iostream>
using namespace std;

void selectionSort(int vetor[],int n,int inicio){
	int menor;
	int aux;
	
    for(int i = inicio; i < n; i++){
		menor = i;
		for(int j = i + 1; j < n; j++){
		    if(vetor[j] < vetor[menor]){
                menor = j;
			}
		}
        aux = vetor[i];
		vetor[i] = vetor[menor];
		vetor[menor] = aux;
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
            return j;
        }
        swap(vetor[i],vetor[j]);
    }  
    

} 

void quicksort(int vetor[], int posPivo, int fim,int m) {
    int novoPivo=fim;
    if (posPivo < fim) {    
        if(fim>=m){
            novoPivo = particiona(vetor, posPivo, fim);
            
            if(novoPivo-posPivo < m){
                selectionSort(vetor,novoPivo,posPivo);
            }else{
                quicksort(vetor, posPivo, novoPivo,m);  
            }
            
            if(fim-(novoPivo+1) < m){
                selectionSort(vetor,fim,novoPivo);
            }else{
                quicksort(vetor, novoPivo + 1, fim,m); 
            }   
        }
        
        else{
            selectionSort(vetor,fim+1,0);
        }    
    } 
}

int main (){
    int m,qtd;
    cin >> m >> qtd;
    int vetor[qtd];
    
    for(int i=0; i<qtd;i++){
        cin >> vetor[i];
    }
    
    quicksort(vetor,0,qtd-1,m);
    
    cout << endl;
    
    for(int i=0; i<qtd;i++){
        cout<<vetor[i] << " ";
    }
    
    return 0;
}
