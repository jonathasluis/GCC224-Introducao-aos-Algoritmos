#include <iostream>
#include <cmath>
using namespace std;

struct registroCliente{
	string nomeCliente;
	int coordenadaXCLiente, coordenadaYCliente, distancia;
	float valor;
};

registroCliente preencher(int xPizza,int yPizza){
	registroCliente cliente;
	
	cin>>cliente.nomeCliente>>cliente.coordenadaXCLiente>>cliente.coordenadaYCliente>>cliente.valor;
	cliente.distancia = sqrt(pow(xPizza - cliente.coordenadaXCLiente, 2) + pow(yPizza - cliente.coordenadaYCliente, 2));
	
	return cliente;
}

void insertionSort (registroCliente vetor[],int qtd){
	registroCliente pivo;
	int j;
	for(int i = 1; i < qtd; i++){
		pivo = vetor[i];
		j = i - 1;
		while(j >= 0 and pivo.distancia < vetor[j].distancia){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = pivo;
    }
}

int main(){
	int n,qtd,xPizza,yPizza;
	float soma=0;
	cin >> n >> xPizza >> yPizza >> qtd;
	registroCliente cliente[qtd];
	
	for(int i=0; i<qtd; i++){
		cliente[i] = preencher(xPizza,yPizza);
	}
	
	insertionSort(cliente,qtd);
	
	for(int i=0; i<n; i++){
		soma += cliente[i].valor; 
	}
	
	cout << soma;
	return 0;
}
