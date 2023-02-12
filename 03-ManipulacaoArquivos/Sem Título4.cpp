#include <iostream>
using namespace std;

struct atletas{
    float tempo;
};

int main(){
    
    atletas* atleta = new atletas[8];
    
    cout << fixed;
    cout.precision(2);
    
    for(int i = 0; i < 8; i++){
        cin >> atleta[i].tempo;
    }
    
    float menor = atleta[0].tempo;
    
    for(int i = 0; i < 8; i++){
        if(atleta[i].tempo < menor){
            menor = atleta[i].tempo;
        }
    }
    
    float* diferenca = new float[8];
    
    for(int i = 0; i < 8; i++){
        diferenca[i] =  atleta[i].tempo - menor;
        if(diferenca[i] == 0)
            diferenca[i] = atleta[i].tempo;
    }
    
    delete[] atleta;
    
    for(int i = 0; i < 8; i++){
        cout << diferenca[i] << endl;
    }
    
    delete[] diferenca;
    
    
    return 0;
}
