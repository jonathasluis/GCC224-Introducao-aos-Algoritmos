#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int afundados(int **matriz1, int **matriz2, int n){
    int qtd=0;
    int navios = 0,resto = 0;
	int x = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matriz1[i][j] != x and matriz1[i][j] != 0 and matriz1[i][j+1] == matriz1[i][j]){
				x = matriz1[i][j];
				navios++;
			}
		}
        x = 0;	
	}
	
	x=0;
	
	int aux[n][n];
	
	for(int i=0;i<n;i++){//transposta
        for(int j=0;j<n;j++){
            aux[i][j] = matriz1[j][i];
        }
    }
    
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(aux[i][j] != x and aux[i][j] != 0 and aux[i][j+1] == aux[i][j]){
				x = aux[i][j];
				navios++;
			}
		}
        x = 0;	
	}
	
	x=0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matriz2[i][j] == 1 and matriz1[i][j] >=1){
				matriz1[i][j] = 0;
			}
			if(matriz1[i][j] != x and matriz1[i][j] != 0){
				x = matriz1[i][j];
				resto++;
			}
			
		}
	}
	qtd = navios - resto;

    return qtd;
}



int main(){
    
    ifstream arquivo("BatalhaNaval.txt");
    int n;
    string c;
    int cont=0;
    
    if(arquivo){
        while(arquivo >> c and cont < 1){
            if(c != " " and c != "\n"){
                cont ++;
                if(cont == 1)
                    n = atoi(c.c_str());
            }
        }
        arquivo.close();
    }
    
    int **matriz1,**matriz2;

    matriz1 =  new int*[n];
    matriz2 =  new int*[n];
    
    for (int i = 0; i < n; i++){
	    matriz1[i] = new int[n];
	    matriz2[i] = new int[n];
    }
    
    string aux;
    int i=0;
    
    arquivo.open("BatalhaNaval.txt");
    
    if(arquivo){
        cont=0;
        while(getline(arquivo,c) and i < n){
            cont ++;
            if(cont != 1){
                for(int j = 0; j < n; j++){
                    if(j != 0){
                        aux = c[j*2];
                    }else
                        aux = c[j];
                        
                    matriz1[i][j] = atoi(aux.c_str());
                }
                i++;
            }
        }
        
        i=0;
        
        while(getline(arquivo,c) and i < n){
            cont ++;
            if(cont != n+1){
                for(int j = 0; j < n; j++){
                    if(j != 0){
                        aux = c[j*2];
                    }else
                        aux = c[j];
                        
                    matriz2[i][j] = atoi(aux.c_str());
                }
                i++;
            }
        }
        
        arquivo.close(); 
    }               
    
    cout << afundados(matriz1,matriz2,n);
    
    for (int i = 0; i < n; i++){
	   delete[] matriz1[i]; 
	   delete[] matriz2[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    
    return 0;
}
