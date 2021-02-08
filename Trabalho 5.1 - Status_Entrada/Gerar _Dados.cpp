#include "Funcoes_e_estruturas.h"
#include <fstream>
#include <cstring>

using namespace std;

Filmes gerador (int semente);
void salvar_dados_teste ();

int main()
{
    salvar_dados_teste ();
}

Filmes gerador (int semente)        // GERAR ALEATORIAMENTE OS DADOS PARA O STRUCT
{
    srand(semente);

    Filmes i;

    strcpy(i.nome,"teste");
    strcpy(i.obs, "Obs");
    i.data.dia = 1 + rand() % 30;
    i.data.mes = 1 + rand() % 11;
    i.data.ano = 1000 + rand ()% 2000;

    return i;

}

void salvar_dados_teste ()      // CRIA UM ARQUIVO COM OS DADOS GERADOS
{
    Filmes informacoes[MAX];

    for (int i=0 ; i<4000 ; i++)
    {
    ofstream escrever;

    escrever.open("filme.txt", ofstream:: app);


    if (!escrever.is_open())
    {
        cout << "Não foi possivel abrir o arquivo. Tente novamente !" <<endl;
        exit(-1);
    }

        informacoes[i] = gerador(i);

        cout << informacoes[i].nome << "\n";
        cout << informacoes[i].obs << "\n";
        cout << informacoes[i].data.dia << " " << informacoes[i].data.mes << " " << informacoes[i].data.ano << "\n";


        escrever << informacoes[i].nome <<" "<<i<<"\n";
        escrever << informacoes[i].obs << " "<< i <<" \n";
        escrever << informacoes[i].data.dia << " " << informacoes[i].data.mes << " " << informacoes[i].data.ano << "\n";

        escrever.close();

        cout << "\n\nFilme Adicionado !!\n";
        escrever.close();
    }
}
