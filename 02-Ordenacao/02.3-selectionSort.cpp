#include <iostream>
using namespace std;

struct registro{
	int numero;
	string nomeArq, assunto, site;
};

registro preencher(){
	registro meme;
	
	cin >> meme.numero >> meme.nomeArq >> meme.assunto >> meme.site;
	
	return meme;
}

void selectionSort(registro vetor[], int qtd){
	int menor;
	registro aux;
	
    for(int i = 0; i < qtd-1; i++){
		menor = i;
		for(int j = i + 1; j < qtd; j++){
		    if(vetor[j].numero < vetor[menor].numero){
				menor = j;
			}
		}
        aux = vetor[i];
		vetor[i] = vetor[menor];
		vetor[menor] = aux;
	}
}

void imprimir(string site, int qtd, registro vetor[]){
	int aux=-1;
	
	for(int i = 0; i < qtd; i++){
		if(vetor[i].site == site){
			cout << vetor[i].numero << " " << vetor[i].nomeArq << " " << vetor[i].assunto << " " << vetor[i].site << endl;
			aux++;
		}
	}
	
	if(aux == -1){
		cout << "Inexistente";
	}
}

int main(){
	int qtd;
	cin >> qtd;
	registro meme[qtd];
	string busca;

	for(int i = 0; i < qtd; i++){
		meme[i] = preencher();
	}
	
	selectionSort(meme,qtd);
	
	cin >> busca;
	imprimir(busca,qtd,meme);
	
	return 0;
}
