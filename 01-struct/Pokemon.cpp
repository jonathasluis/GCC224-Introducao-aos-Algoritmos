#include <iostream>
using namespace std;

struct pokemon{
	string nome;
	int atk,def;
};

struct treinador{
	string nome;
	pokemon posse[3];
};

void duelo(treinador &a,treinador &b){
	if(a.posse[0].atk > a.posse[1].atk and a.posse[0].atk > a.posse[2].atk)
		a.posse[0]= a.posse[0];
	if(a.posse[1].atk > a.posse[0].atk and a.posse[1].atk > a.posse[2].atk)
		a.posse[0]= a.posse[1];
	if(a.posse[2].atk > a.posse[1].atk and a.posse[2].atk > a.posse[0].atk)
		a.posse[0]= a.posse[2];
		
	if(b.posse[0].def > b.posse[1].def and b.posse[0].def > b.posse[2].def)
		b.posse[0]= b.posse[0];
	if(b.posse[1].def > b.posse[0].def and b.posse[1].def > b.posse[2].def)
		b.posse[0]= b.posse[1];
	if(b.posse[2].def > b.posse[0].def and b.posse[2].def > b.posse[1].def)
		b.posse[0]= b.posse[2];
}

int main(){
	int qtd, a=0,b=0;
	cin>>qtd;
	treinador pessoa[qtd];
	
	for(int i=0; i<qtd; i++){
		cin>>pessoa[i].nome;
		for(int j=0; j<3; j++){
			cin>>pessoa[i].posse[j].nome;
			cin>>pessoa[i].posse[j].atk;
			cin>>pessoa[i].posse[j].def;
		}
	}
	
	cin>>a;
	cin>>b;
	
	duelo(pessoa[a], pessoa[b]);
	
	if(pessoa[a].posse[0].atk > pessoa[b].posse[0].def){
		cout<<pessoa[a].nome << endl << pessoa[a].posse[0].nome;
	}
	else{
		cout<<pessoa[b].nome<< endl<< pessoa[b].posse[0].nome;
	}
	
	return 0;
}
