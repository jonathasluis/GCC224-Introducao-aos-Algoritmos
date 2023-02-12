#include <iostream>
using namespace std;

struct tropas{
	string nome,planeta;
	int batalhas;
};

struct planetas{
	string nome;
	int numero;
	float media;
};

int main(){
	int qtd,cont=0;
	cin >> qtd;
	tropas soldado[qtd];
	string planeta[qtd];
	
	for(int i=0;i<qtd;i++){
		cin>> soldado[i].nome >> soldado[i].planeta >> soldado[i].batalhas;
	}
	
	for(int i=0; i<qtd; i++){
		planeta[i] = soldado[i].planeta;
	}
	
	for(int i=0; i<qtd; i++){
		for(int j=i+1; j<qtd; j++){
			if(planeta[i]==planeta[j]){
				planeta[j]="";
			}
		}
	}
	
	for(int i =0;i<qtd;i++){
		if(planeta[i]!="")
			cont++;
	}
	
	planetas registroPlaneta[cont];
	int j=0,aux=0;
	
	for(int i=0; i<cont; i++){
		j=aux;
		while(j<qtd){
			if(planeta[j]!=""){
				registroPlaneta[i].nome = planeta[j];
				j++;
				aux=j;
				j=qtd+1;
			}
			j++;
		}
	}
	
	int qtdPorPlaneta=0,soma=0;
	
	for(int i=0; i<cont;i++){
		
		for(int j=0;j<qtd;j++){
			if(registroPlaneta[i].nome == soldado[j].planeta){
				qtdPorPlaneta++;
				soma=soma+soldado[j].batalhas;
			}
		}
		registroPlaneta[i].numero = qtdPorPlaneta;
		registroPlaneta[i].media = (float)soma / qtdPorPlaneta;
		
		soma=0;
		qtdPorPlaneta=0;
	}
	
	for(int i=0;i<cont;i++){
		cout<<registroPlaneta[i].nome<<" "<<registroPlaneta[i].numero<<" "<<registroPlaneta[i].media<<endl;
	}
	return 0;
}


