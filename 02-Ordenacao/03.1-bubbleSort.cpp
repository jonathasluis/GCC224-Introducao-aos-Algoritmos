#include <iostream>
using namespace std;

struct funcionarios{
	int id;
	float horasTrabalhadas, valorHora, salario; 
};

funcionarios preencher(){
	funcionarios empregado;
	cin >> empregado.id >> empregado.horasTrabalhadas >> empregado.valorHora;
	empregado.salario = empregado.horasTrabalhadas * empregado.valorHora;
	
	return empregado;
}

void bubbleSort(funcionarios vetor[],int qtd){
	funcionarios aux;
	for (int i = 0; i < qtd-1; i++) {
		for (int j = 0; j < qtd-1-i; j++) {
			if (vetor[j].salario > vetor[j+1].salario) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

int main(){
	int qtd;
	cin >> qtd;
	funcionarios empregado[qtd];
	
	for(int i=0; i < qtd; i++){
		empregado[i] = preencher();
	}
	
	bubbleSort(empregado,qtd);
	
	cout<<endl;
	for(int i=0; i < qtd; i++){
		cout << empregado[i].id << " " << empregado[i].salario << endl ;
	}
	
	return 0;
}
