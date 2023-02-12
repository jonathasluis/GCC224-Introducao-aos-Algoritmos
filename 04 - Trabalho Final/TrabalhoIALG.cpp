/*
 Desenvolvido por Jonathas Luis de Sousa.
 Universidade Federal de Lavras.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct robos{
    int identificador;
    string tipo;
    string anoCriacao;
    string descricao;
    string principalUso;
};

int buscaSequencial(robos *vetor,int procurado,int uso/*avalia qual o uso da busca para a impressao*/){
    int posicaoProcurado=-1;
    
    for(int i = 0; i < 100; i++){ //percorre o vetor
        if(vetor[i].identificador == procurado){ //verifica se o elemento do vetor � igual ao elemento procurado
            posicaoProcurado = i;
            i = 101; // muda o valor de i quando o elemento foi encontrado para sair do loop
        }
    }
    
    if(posicaoProcurado == -1 and uso == 0)//se o valor nao for encontrado
        cout << "Registro nao encontrado" << endl;

    return posicaoProcurado;
}

void shellSort(robos *vetor, int tamanho) {
    int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};//sequencia de ciura (melhores resultados)
    int pos_gap = 8;//ultima posicao da sequencia
    
    while (gaps[pos_gap] > tamanho) {//enquanto o valor em uma posicao da sequencia for maior do que o tamanho do vetor  
        pos_gap--;                   //diminui-se o tamanho dos saltos
    }   
     
    robos auxiliar;//variavel auxiliar para a substitui��o dos valores
    int j;
    
    while ( pos_gap >= 0 ) {
        int gap = gaps[pos_gap];//determina o valor do salto

        for (int i = gap; i < tamanho; i++) {
            auxiliar = vetor[i];
            j = i;
            while ((j >= gap) and (auxiliar.identificador < vetor[j - gap].identificador)) {// efetua compara��es entre elementos com dist�ncia gap
                vetor[j] = vetor[j - gap];
                j = j - gap;
            }
            vetor[j] = auxiliar;
        }
        pos_gap--;//diminue o salto
    }
}

int incluir(robos *vetor, int ultimaPosicao,robos *vetorId){
    int i = ultimaPosicao + 1; // posicao em qual sera salva os dados; posicao posterior do ultimo dado;
    
    if(i >= 100){//limite de registros e 100, ultima posicao acessivel e a 99;
        cout << "Nao e possivel inserir novo registro" << endl;
        i = ultimaPosicao;
    }else{
        cout << "Identificador (numero): ";
        
        int identificador=0;
        cin >> identificador;//salva o valor do identificador para a verificacao
        
        
        if(buscaSequencial(vetorId,identificador,1) == -1){
            vetor[i].identificador = identificador;//se nao existir esse identificador ele � salvo no campo
            vetorId[i].identificador = identificador;
        }else{
            cout << "Esse identificador esta indisponivel!" << endl;
            return ultimaPosicao;
        }
        
        cout << "tipo: ";
        cin.ignore();//ignora os caracteres \n no final de cada linha
        getline(cin,vetor[i].tipo);//pega os valores inseridos de toda a linha e salva no campo "tipo"
        
        cout << "Ano de criacao: ";
        cin >> vetor[i].anoCriacao;//pega os valores inseridos de toda a linha e salva no campo "anoCriacao"
        
        cin.ignore();
        cout << "Descricao: ";
        getline(cin, vetor[i].descricao);//pega os valores inseridos de toda a linha e salva no campo "descricao"
        
        cout << "Principal uso: ";
        getline(cin, vetor[i].principalUso);//pega os valores inseridos de toda a linha e salva no campo "principalUso"
        
        cout << "Registro incluido com sucesso" << endl;
    }
    return i;//retor a posicao em que o registro foi salvo
}

int excluir(robos *vetor,int ultimaPosicao,int posicao){
    
    for(int i = posicao; i < ultimaPosicao + 1; i++){//percorre o vetor a partir do elemento procurado
        vetor[i] = vetor[i+1];//remove o elemento deslocando os elementos a sua direita 
    }
    
    cout << "Removido com sucesso!" << endl;
    return ultimaPosicao - 1;//diminue o tamanho utilizado pelo vetor
}

void listar(robos *vetor, int ultimaPosicao){
    
    cout << "O numero de registros e: " << ultimaPosicao + 1 << endl;//mostra o numero de registros salvos
    
    for(int i = 0; i < ultimaPosicao + 1; i++){// percorre o vetor at� a ultima posi�ao utilizada
        cout << vetor[i].identificador << " - " << vetor[i].tipo << " - " << vetor[i].anoCriacao << " - " << vetor[i].descricao << " - " << vetor[i].principalUso << endl;
        //imprime os dados separados por "-" e cada registro em uma linha
    }
}

string alterar(int posicao,int campo,robos *vetor,string novoValor){
    string retorno = "Registro alterado com sucesso.";
    
    switch (campo){//altera o valor de acordo com o campo selecionado
        case 1 :
            vetor[posicao].tipo = novoValor;
            break;
        case 2 :
            vetor[posicao].anoCriacao = novoValor;
            break;
        case 3 :
            vetor[posicao].descricao = novoValor;
            break;    
        case 4 :
            vetor[posicao].principalUso = novoValor;
            break;
        default :
            retorno = "opcao invalida!";
    }
    return retorno;
}

void gravarDados(robos *vetor,int tamanho){
    ofstream arquivo("dados.txt");//cria ou abre o arquivo "dados.txt" 
    shellSort(vetor,tamanho);//ordena o vetor de registros
    
    if(arquivo){//verifica se o arquivo existe ou foi aberto
        for(int i = 0; i < tamanho; i++){//percorre o vetor
            arquivo << vetor[i].identificador << " - " << vetor[i].tipo << " - " << vetor[i].anoCriacao << " - " << vetor[i].descricao << " - " << vetor[i].principalUso << endl;
            //escreve os dados do vetor no arquivo
        }
        cout << "Gravacao realizada com sucesso" << endl;
        arquivo.close();//fecha o arquivo
    }
}

int main(){
    
    robos *vetorRobos = new robos[100]; // criacao de um vetor de registros alocado dinamicamente
    robos *vetorIdentificadores = new robos[100];//armazena todos os identificadores utilizados, inclusive os excluidos
    int ultimaPosicao = -1;//variavel para armazenar a ultima posicao utilizada no vetor de registros; valor -1 para indicar vetor vazio;

    while(true){//inicio do loop do menu
        cout << endl << "Escolha uma Opcao:" << endl << "(1) Incluir    (2) Excluir    (3) Listar   (4) Alterar    (5) Gravar Dados    (6) Sair" << endl;//menu
        int opcao; // variavel para armazenar a opcao do menu escolhida pelo usuario
        cin >> opcao;
        
        int procurado;// variavel para armazenar o identificador procurado pelo usuario
        int posicao;//variavel que armazena a posicao no vetor no qual esta localizado o identificador procurado
        
        switch (opcao){//inicio da estrutura condicional para determinar o que fazer dependendo da escolha do usurio
            case 1:
                ultimaPosicao = incluir(vetorRobos,ultimaPosicao,vetorIdentificadores);//inclui um novo registro e retorna a ultima posicao utilizada no vetor
                break;
                
            case 2:
                cout << "Qual identificador deseja remover?" << endl;
                cin >> procurado;
                
                posicao = buscaSequencial(vetorRobos,procurado,0); // busca no vetor o elemento procurado e retorna sua posicao
                
                if(posicao != -1)  //se a posicao for -1 o elemento nao foi encontrado
                    ultimaPosicao = excluir(vetorRobos,ultimaPosicao,posicao);//exclui o elemento e retorna a ultima posicao atualizada
                break;
                
            case 3:
                if(ultimaPosicao != -1){//verifica se o vetor possui algum elemento
                    shellSort(vetorRobos,ultimaPosicao + 1);//ordena o vetor antes de listar
                    listar(vetorRobos,ultimaPosicao);//listar o vetor de registro
                }else
                    cout << "Registro vazio!" << endl;
                
                break;    
            
            case 4:
                cout << "Qual identificador deseja alterar?" << endl;
                cin >> procurado;
                
                posicao = buscaSequencial(vetorRobos,procurado,0);// busca no vetor o elemento procurado e retorna sua posicao
                
                if(posicao != -1){//verifica se o elemento foi encontrado
                    cout << "Qual campo? (1: tipo; 2: Ano de criacao; 3: descricao; 4: principal uso)?" << endl;
                    int campo;//variavel que armazena qual campo o usuario deseja alterar
                    cin >> campo;
                    
                    cout << "Qual o novo valor?" << endl;
                    string novoValor;//valor que substituira o valor do campo selecionado para alteracao
                    cin >> novoValor;
                    
                    cout << alterar(posicao,campo,vetorRobos,novoValor) << endl;//atera, se possivel, o campo selecionado e retorna uma mensagem
                }
                break;
                
            case 5:
                gravarDados(vetorRobos,ultimaPosicao+1);//grava os dados do registro em um arquivo txt
                break;
                
            case 6:
                char resposta;//variavel para armazenar a resposta do usuario se deseja ou nao guardar os dados antes de sair
                do {// inicio loop para garantir uma resposta valida
                    cout << "Deseja guardar os dados? (s/n)" << endl;
                    cin >> resposta;
                    if(resposta == 's'){
                        gravarDados(vetorRobos,ultimaPosicao+1);//guarda os dados
                        delete[] vetorRobos;//desaloca o vetor alocado dinamicamente
                        delete[] vetorIdentificadores;//desaloca o vetor alocado dinamicamente
                        return 0;//encerra o programa
                    }                       
                    else if (resposta == 'n'){
                        delete[] vetorRobos;//desaloca o vetor alocado dinamicamente
                        delete[] vetorIdentificadores;//desaloca o vetor alocado dinamicamente
                        return 0;//encerra o programa
                    }
                        
                    else
                        cout << "resposta invalida!" << endl;
                    
                }while(resposta != 's' and resposta != 'n');// fim loop para garantir uma resposta valida
                break;
                    
            default:
                cout << "Opcao Invalida!" << endl;//caso a escolha do usuario seja diferente das op�oes disponiveis   
                   
        }//fim estrutura condicional para determinar o que fazer dependendo da escolha do usurio
        
    }//fim do loop do menu
    
    return 0;//encerra o programa
}
