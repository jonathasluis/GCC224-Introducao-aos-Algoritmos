#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){
    
   ifstream arq("tropas.txt");
   string c;
   
   int cont=0;
   char w,i,digito;

   int qtdW,qtdI;
   
   if(arq){//inicio preencher variaveis
       while(arq >> c){
            if(c != " " and c != "\n"){
                cont++;
                
                switch(cont){
                    case 1:
                        w = c[0];
                        break;
                        
                    case 2:
                        i = c[0];
                        break;
                        
                    case 3:
                        qtdW = atoi(c.c_str());
                        break;
                        
                    default:
                        if(cont == qtdW*2 + 4)
                            qtdI = atoi(c.c_str());
                }   
            }  
        }
        digito = c[0];
        arq.close();
   }//fim preencher variaveis
   
    arq.open("tropas.txt");
    string linha;
   
    int x,y;
    char matriz[10][10];
    
    for(int k = 0; k < 10; k++){
        for(int j =0; j < 10; j++){
                matriz[k][j] = digito;
        }
    }
   
    if(arq){//inicio preencher matriz
        cont = 0;
        while(getline(arq,linha)){
            if(linha != ""){
                cont++;
                
                if(cont >= 4 and cont < qtdW + 4){
                    x = linha[0] - 48;
                    y = linha[2] - 48;
                    matriz[x][y] = w; 
                }
                
                if(cont > qtdW + 4 and cont <= qtdI + qtdW + 4){
                    x = linha[0] - 48;
                    y = linha[2] - 48;
                    matriz[x][y] = i;
                }
            } 
            
        }
        arq.close();
    }//inicio preencher matriz
    
    for(int k = 0; k < 10; k++){
        for(int j =0; j < 10; j++){
            cout << matriz[k][j] << " ";
        }
        cout << endl;
    }
    
    int contW=0,contI=0;
    
    cout << w <<": ";
    
    for(int k = 0; k < 10; k++){
        for(int j = 0; j < 10; j++){
            
            if(matriz[k][j] == i)
                contI++;
            if(matriz[k][j] == w)
                contW++;
            
               
        }
        
        if(contW > contI)
            cout << k << " ";
            
        contI=0;
        contW=0; 
    }
   
    return 0;
}
