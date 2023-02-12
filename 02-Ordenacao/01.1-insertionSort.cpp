#include <iostream>
using namespace std;

struct estoque{
	int id;
	string descricao;
	float preco;
};

estoque preencher(){
	estoque produto;
	cin.ignore(2, '\n');
	cin >> produto.id;
	cin.ignore();
	getline(cin , produto.descricao);
	cin >> produto.preco;
	
	return produto;
}

void insertionSort(estoque vetor[],int qtd){
	estoque pivo;
	int j;
	for(int i = 1; i < qtd; i++){
		pivo = vetor[i];
		j = i - 1;
		while(j >= 0 and pivo.preco < vetor[j].preco){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = pivo;
    }
}

int main (){
	int qtd, aux = -1;
	float precoMin, precoMax;
	cin >> qtd;
	estoque produto[qtd];
	
	for(int i = 0; i < qtd; i++){
		produto[i] = preencher();
	}
	
	insertionSort(produto,qtd);
	
	cin >> precoMin >> precoMax;
	
	for(int i = 0; i < qtd; i++){
		if(produto[i].preco >= precoMin and produto[i].preco <= precoMax){
			cout << produto[i].id << " " << "\"" << produto[i].descricao << "\"" << " " << produto[i].preco << endl;
			aux++;
		}
	}
	
	/*for(int i = 0; i < qtd; i++){
		cout << produto[i].id << " " << "\"" << produto[i].descricao << "\"" << " " << produto[i].preco << endl;
		aux++;
	}*/
	
	if(aux == -1)
		cout << "Inexistente";
		
		
	return 0;
}
