#include <iostream>
using namespace std;

struct data{
	int d,m,a;
};

struct regAnimal{
	int id;
	string nome,dono;
	data vacina;
};

int main(){
	regAnimal animal[100];
	int identificador,aux=0;
	
	for(int i=0;i<100;i++){
		cin >> animal[i].id;
		
		if(animal[i].id == 0)
			i=100;//sai do loop
		
		if(i<100){
			cin >> animal[i].nome >> animal[i].dono >> animal[i].vacina.d >>  animal[i].vacina.m >>  animal[i].vacina.a;
			aux++;
		}
	
	}
	
	cin >> identificador;
	
	int inicio = 0, fim = aux-1, meio, pos=-1;
	
	while(inicio <= fim){
		meio = (inicio + fim)/2;
		
		if(identificador == animal[meio].id){
			pos = meio;
			inicio = fim + 1;
		}else{
			if(identificador > animal[meio].id){
				inicio = meio + 1;
			}else
				fim = meio - 1;
		}
	}
	
	if(pos == -1){
		cout << "inexistente";
	}else
		cout << animal[pos].nome << " " << animal[pos].vacina.d << "/" << animal[pos].vacina.m << "/" << animal[pos].vacina.a;
		
		
	return 0;
}
