#include <iostream>
#include <fstream>
using namespace std;

struct hospedes{
    int id;
    char nome[50];
    char telefone[12];
};

int busca(hospedes vetor[],int inicio,int fim,int procurado,int troca){
    int meio = (inicio + fim)/2;
   
    if (procurado == vetor[meio].id) {
        vetor[meio].id = troca;
        return meio;
    }
    
    else if (inicio < fim) {
        if (vetor[meio].id < procurado)
            return busca(vetor, meio+1, fim, procurado,troca);
            
        else
            return busca(vetor, inicio, meio-1, procurado,troca);
            
    } else {
        return -1;
    }
}

void shell_sort(hospedes vetor[], int tamanho) {
    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    int pos_gap = 8;
    
    while (gaps[pos_gap] > tamanho) {
        pos_gap--;
    }   
     
    hospedes valor;
    int j;
    
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap];

        for (int i = gap; i < tamanho; i++) {
            valor = vetor[i];
            j = i;
            while ((j >= gap) and (valor.id < vetor[j - gap].id)) {
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }
            vetor[j] = valor;
        }
        pos_gap--;
    }
}

int main(){
    int numeroHospedes;
    cin >> numeroHospedes;
    
    hospedes hospede[numeroHospedes];
    
    ofstream arquivo("caravana.bin");
    
    
    if(arquivo){
        for(int i = 0; i < numeroHospedes; i++){
			cin >> hospede[i].nome >> hospede[i].id >> hospede[i].telefone;
		}
		arquivo.write((char *) (hospede), numeroHospedes*sizeof(hospedes));
		arquivo.close();
    }
    
    int procurado, novo;
    
    cin >> procurado >> novo;
    
    fstream arq("caravana.bin");
    
    if(arq){
        hospedes novoRegistro[numeroHospedes];
        
        arq.read((char*)(novoRegistro), numeroHospedes*sizeof(hospedes));
        
        int inicio = 0;
        int fim = numeroHospedes - 1;
        
        busca(novoRegistro,inicio,fim,procurado,novo);
        shell_sort(novoRegistro,numeroHospedes);
        
        arq.write((char *) (novoRegistro), numeroHospedes*sizeof(hospedes));
        arq.read((char*)(novoRegistro), numeroHospedes*sizeof(hospedes));
        
        arq.close();
        
        for(int i =0; i < numeroHospedes; i++){
			cout << novoRegistro[i].nome << " "	<< novoRegistro[i].id <<endl;
		}
    }
    
    return 0;
}
