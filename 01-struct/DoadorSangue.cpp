#include <iostream>
using namespace std;

struct pessoa{
	string nome,tipo;
};

int main(){
	int qtd;
	cin>>qtd;
	string tipoComparar;
	pessoa doador[qtd];
	
	for(int i=0;i<qtd;i++){
		cin>> doador[i].nome;
		cin>> doador[i].tipo;
	}
	
	cin>>tipoComparar;
	
	if(tipoComparar=="A"){
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "A")
				cout<<doador[i].nome<<endl;
		}
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "O")
				cout<<doador[i].nome<<endl;
		}
	}
	
	if(tipoComparar=="B"){
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "B")
				cout<<doador[i].nome<<endl;
		}
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "O")
				cout<<doador[i].nome<<endl;
		}
	}
	
	if(tipoComparar=="AB"){
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "AB")
				cout<<doador[i].nome<<endl;
		}
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "A")
				cout<<doador[i].nome<<endl;
		}
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "B")
				cout<<doador[i].nome<<endl;
		}
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "O")
				cout<<doador[i].nome<<endl;
		}
	}
	
	if(tipoComparar=="O"){
		for(int i=0;i<qtd;i++){
			if(doador[i].tipo == "O")
				cout<<doador[i].nome<<endl;
		}
	}
	
	return 0;
}
