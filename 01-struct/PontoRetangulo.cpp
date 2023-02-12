#include <iostream>
using namespace std;

struct ponto{
	int x,y;
};

struct retangulo{
	ponto v1,v2;
};

int main(){
	ponto p;
	cin>> p.x>>p.y;
	
	int qtd,cont=0;
	cin>>qtd;
	
	retangulo ret[qtd];
	
	for(int i=0; i<qtd; i++){
		cin>>ret[i].v1.x>>ret[i].v1.y;
		cin>>ret[i].v2.x>>ret[i].v2.y;
	}
	
	for(int i=0; i<qtd;i++){
		if((p.x >= ret[i].v1.x and p.y >= ret[i].v1.y) and (p.x <= ret[i].v2.x and p.y <= ret[i].v2.y)){
			cont++;
		}
	}
	
	cout<<cont;
	return 0;
}
