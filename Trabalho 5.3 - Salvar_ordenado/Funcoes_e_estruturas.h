#ifndef FUNCOES_E_ESTRUTURAS_H_INCLUDED
#define FUNCOES_E_ESTRUTURAS_H_INCLUDED

#define MAX_PESQUISA 1500   //  QUANTIDAD MAXIMA DE FILMES NA BUSCA POR M�S
#define MAX_NOME 100        //  QUANTIDAD MAXIMA DE CARACTERES NO NOME DO FILME
#define MAX_OBS 200         //  QUANTIDAD MAXIMA DE CARACTERES NAS OBSERVACOES
#define MAX 5000            //  QUANTIDADE DE FILMES QUE PODE VIR A SER ADD PELO USUARIO
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<locale.h>
#include<string>


using namespace std;

struct Data
{
    int  dia,mes,ano;
};


struct Filmes
{
    char nome[MAX_NOME];

    Data data;

    char  obs[MAX_OBS];

    int status;
};



Filmes entrar_dados ();     // RECEBE DO USUARIO O DADO DO FILME E COLOCA EM UMA VARI�VEL
int menu_inicial();     // OP��ES DO MENU/ O QUE O PROGRAMA OFERECE
void salvar_dados ();       // SALVAR AS INFORMA��ES DECLARADAS PELO USUARIO NO ARQUIVO .TXT
int ler_dados (Filmes inf [MAX]);       // SALVA AS INFORMA��ES DO ARQUIVO .TXT EM UMAS VARI�VEL
void saida_de_dados (int contador,Filmes saida[MAX]);       // RECEBE O VALOR DAS VARI�VEIA E IMPRIME NA TELA
void pesquisa_mes(Filmes saida[MAX],int chave,int cont);        // ACHA DADOS DE UM MES ESPEC�FICO
void pesquisa_data(Filmes saida[MAX],Data chave,int cont);      // ACHA DADOS DE UMA DATA ESPEC�FICO
void meses();
void menu_secundario(int quantidade_filmes,Filmes retorno[MAX]);        // MENU VISULIZA��ES
void ordenacao_ano(Filmes inf[MAX],int n);      // ORDENAR POR ANO OS ARRAYS
void ordenacao_ano_mes(Filmes inf[MAX], int n);     // ORDENA��O DOS MESSES APOS ORDENA��O POR ANO
void ordenacao_ano_mes_dia(Filmes inf [MAX],int n);      // ORDENA��O DOS DIA  APOS ORDENA��O POR ANO E M�S
void pesquisa (char buscar[MAX_NOME]);      // PESQUISA POR PALAVRA CHACE
void salvar_dados_ord (Filmes inf [MAX],int m);
#endif // FUNCOES_E_ESTRUTURAS_H_INCLUDED
