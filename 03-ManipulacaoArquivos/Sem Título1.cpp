#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string nomeArq;
    cin>>nomeArq;
    
    ifstream arquivo(nomeArq.c_str());
    ofstream  cifrado("cifrado.txt");
    char c[1];
    int valor=0;
    
    if(arquivo){
        while(arquivo.read(c,1)){
            valor = (int)c[0];
            if(valor >= 65 and valor <= 90){
                valor = (int)c[0];
                valor = 155 - valor;
                c[0] = (char)valor;
            }
           cifrado << c[0];
        }
        
        arquivo.close();
        cifrado.close();
    }
    
    return 0;
}
