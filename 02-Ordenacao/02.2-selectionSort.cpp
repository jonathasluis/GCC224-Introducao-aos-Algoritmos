#include <iostream>
using namespace std;

struct figurinha{
	string jogador;
	int numeroFigurinha, exemplares;
};

figurinha preencherRegistro(){
	figurinha colecao;

	cin >> colecao.numeroFigurinha >> colecao.jogador >> colecao.exemplares;
	
	return colecao;
}

void selectionSort(figurinha vetor[],int n){
	int menor;
	figurinha aux;
	
    for(int i = 0; i < n-1; i++){
		menor = i;
		for(int j = i + 1; j < n; j++){
		    if(vetor[j].numeroFigurinha < vetor[menor].numeroFigurinha){
		 	    menor = j;
			}
		}
        aux = vetor[i];
		vetor[i] = vetor[menor];
		vetor[menor] = aux;
	}
}

int pesquisa (int qtd,int valor, figurinha vetor[]){
	int indice = -1;
	
	for(int i=0; i < qtd; i++){
		if(valor == vetor[i].numeroFigurinha){
			indice = i;
			i = qtd + 1;
		}
	}
	
	return indice;
}

int main(){
	
	int qtd, busca, indiceProcurado;
	cin >> qtd;
	figurinha colecao[qtd];
	
	for(int i=0; i<qtd; i++){
		colecao[i] = preencherRegistro();
	}
	
	cin>>busca;
	
	selectionSort(colecao,qtd);
	
	indiceProcurado = pesquisa(qtd , busca, colecao);
	
	
	if(indiceProcurado != -1)
		cout << indiceProcurado << endl << colecao[indiceProcurado].jogador << " " << colecao[indiceProcurado].exemplares;
	else
		cout << indiceProcurado;
	
	return 0;
}
