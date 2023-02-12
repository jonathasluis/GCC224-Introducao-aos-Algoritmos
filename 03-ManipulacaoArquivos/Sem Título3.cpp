#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char v1[100],v2[100];

    cin.getline(v1,100);
    cin.getline(v2,100);
    
    int tamanho1 = strlen(v1);
    int tamanho2 = strlen(v2);
    int tamanhoResultante = tamanho1 + tamanho2 + 1;
    char *resultante = new char[tamanhoResultante];
    
    for(int i = 0; i < tamanho1; i++){
        resultante[i] = v1[i];
    }
    
    resultante[tamanho1] = ' ';
    
    for(int i = 0; i < tamanho2; i++){
        resultante[i+tamanho1+1] = v2[i];
    }
    
    for(int i = 0; i < tamanhoResultante; i++){
        cout << resultante[i];
    }
    
    delete[] resultante;
    return 0;
}
