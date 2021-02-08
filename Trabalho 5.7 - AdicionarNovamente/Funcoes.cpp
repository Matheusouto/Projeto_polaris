#include "Funcoes_e_estruturas.h"
#include <fstream>
#include <cstring>
#include<time.h>


Filmes entrar_dados ()  // RECEBE DO USUARIO OS DADOS DO FILME E COLOCA EM UMA VARIÁVEL *OK
{

    Filmes dados;
    cin.ignore();

    cout << "Nome do filme : ";     //  ENTRADA DOS DADOS NECESSARIOS
    cin.getline(dados.nome,MAX_NOME);

    cout << "Data de estreia (dd mm aaaa): ";
    cin >> dados.data.dia;
    cin >> dados.data.mes;
    cin >> dados.data.ano;

    cin.ignore();


    cout <<"Status: "<<endl;
    cout << "\t[1] - Baixado "<<endl;
    cout << "\t[2] - Assistido"<<endl;
    cout << "\t[3] - No HD"<<endl;
    cout << "\t[4] - Não lançado"<<endl;
    cout << "\t[5] - Lançado "<<endl;
    cin >> dados.status;

    cin.ignore();

    cout << "Observação: ";
    cin.getline(dados.obs,MAX_OBS);

    return dados;
}


void saida_de_dados (int contador, Filmes saida[MAX]) // PEGA OS DADOS QUE ESTÃO NO ARRAY E IMPRIME NA TELA *OK
{
    for(int i=0 ; i< contador-1 ; i++)
    {
        cout <<endl;
        cout << "Filme " << i+1 <<": "<<endl;
        cout << "Nome: "<< saida[i].nome << endl ;
        cout <<"Data: " << saida[i].data.dia << "/" << saida[i].data.mes << "/" << saida[i].data.ano <<endl;

        if (saida[i].status == 1)
        {
                cout <<"Status: " << saida[i].status << " - BAIXADO." <<endl;
        }
        else if (saida[i].status == 2)
        {
                cout <<"Status: " << saida[i].status << " - ASSISTIDO." <<endl;
        }
        else if (saida[i].status == 3)
        {
                cout <<"Status: " << saida[i].status << " - NO HD." <<endl;
        }
        else if (saida[i].status == 4)
        {
                cout <<"Status: " << saida[i].status << " - NÃO LANÇADO." <<endl;
        }
        else
        {
                cout <<"Status: " << saida[i].status << " - LANÇADO." <<endl;
        }

        cout <<"Observação: " << saida[i].obs << endl ;
        cout << endl;
    }
    cout << "O programa possui "<< contador-1 << " filmes."<<endl;
    cout <<"_______________________________"<<endl;
}


// **************  MENU **********************************************************************

int menu_inicial ()     // OPÇÕES DO MENU / O QUE  PROGRAMA OFERECE
{

    int desejo;
    cout << "\t\t\t\t.___  ___.  _______ .__   __.  __    __ \n";
    cout << "\t\t\t\t|   \\/   | |   ____||  \\ |  | |  |  |  | \n";
    cout << "\t\t\t\t|  \\  /  | |  |__   |   \\|  | |  |  |  |\n";
    cout << "\t\t\t\t|  |\\/|  | |   __|  |  . `  | |  |  |  |\n";
    cout << "\t\t\t\t|  |  |  | |  |____ |  |\\   | |  `--'  |\n";
    cout << "\t\t\t\t|__|  |__| |_______||__| \\__|  \\______/\n";

    cout << "\t [1] - ADICINAR NOVO FILME.\n";
    cout << "\t [2] - VISUALIZAR FILMES.\n";
    cout << "\t [3] - PESQUISAR.\n";
    cout << "\t [4] - SAIR.\n";


    cout << "Escolha uma opção: ";
    cin >> desejo;
return desejo;
}


void meses ()   // MESES
{
    cout<<"\t[1] - JANEIRO " << "\t[5] - MAIO" << "\t[9] - SETEMBRO"<<endl;
    cout<<"\t[2] - FEVEREIRO" << "\t[6] - JUNHO" << "\t[10] - OUTUBRO"<<endl;
    cout<<"\t[3] - MARÇO" << "\t[7] - JULHO" << "\t[11] - NOVEMBRO"<<endl;
    cout<<"\t[4] - ABRIL" << "\t[8] - AGOSTO" << "\t[12] - DEZEMBRO"<<endl;

}

void menu_secundario(int quantidade_filmes,Filmes retorno[MAX])  // MENU VISULIZAÇÕES
{
        int oq_fazer;
        int chave_mes;
        Data chave_data;

        cout <<"Você Deseja:\n";    // OPÇÕES DE VISUALIZAÇÃO DO USUARIO
        cout <<"[1] - VISUALIZAR TODOS OS FILMES.\n";
        cout <<"[2] - VISUALIZAR FILMES DE UM MÊS ESPECÍFICO.\n";
        cout <<"[3] - VISUALIZAR FILMES DE UM DATA ESPECÍFICO.\n";

        cout << "Escolha uma Opção:";
        cin>>oq_fazer;


        switch (oq_fazer)       // EXECUTAÇÃO DA ESCOLHA
        {
        case 1:  // VIAZUALIXZAR TODOS OS FILMES

            //system("clear"); // linux
            system("CLS");

            ordenacao_ano(retorno,quantidade_filmes);       // COLOCAR OS FILME EM ORDEM CRONOLÓGICA
            ordenacao_ano_mes(retorno,quantidade_filmes);
            ordenacao_ano_mes_dia(retorno,quantidade_filmes);

            Atual_automatica_status (retorno,quantidade_filmes-1); //MUDA STATUS DE NÃO LANÇADO PARA LANÇADO


            saida_de_dados(quantidade_filmes,retorno); // IMPRIMI TODOS OS FILMES NA TELA.

            salvar_dados_ord (retorno,quantidade_filmes);
            break;

        case 2:         // VIZUALIZAR FILME POR MÊS

            //printf("\e[H\e[2J"); // LIMPAR TELA LINUX
            system("CLS");

            cout << "VISUALIZAÇÃO MÊS ESPECÍFICO\n";
            cout << "--------------------------------\n";
            meses();
            cout << "Escolha um Mês: ";

            cin >> chave_mes;       // ENTRADA DO MES ESCOLHIDO

            //system("clear"); // LIMPAR TELA LINUX
            system("CLS");

            pesquisa_mes(retorno,chave_mes,quantidade_filmes);      // FUNÇÃO RESPONSAVEL PELO COMANDO
            break;

        case 3:         // VIZUALIZAR DATA ESPECÍFICA

            //system("clear");      // LIMPAR TELA LINUX
            system("CLS");

            cout << "VISUALIZAÇÃO DATA ESPECÍFICO\n";
            cout << "--------------------------------\n";
            cout << "Escolha um Data [dd mm aaaa]: ";
            cin >> chave_data.dia>> chave_data.mes>> chave_data.ano;        // ENTRADA DA DATA ESCOLHIDA

             //printf("\e[H\e[2J");         // LIMPAR TELA LINUX
            system("CLS");

            pesquisa_data(retorno,chave_data,quantidade_filmes); // FUNÇÃO RESPONSAVEL POR ACHA DADOS DE UMA DATA ESPECÍFICO;
            break;

        default:        // VALIDAÇÃO DA ESTRADA ESCOLHIDA PELO USUÁRIO
            //printf("\e[H\e[2J"); // LIMPAR TELA LINUX
            system("CLS");

            cout << "Numero invalido !!\n";
            menu_secundario(quantidade_filmes,retorno);
        }
}

//  *****************  MANIPULAÇÃO DE ARQUIVOS  **********************************************

void salvar_dados_ord (Filmes inf [MAX],int m)    // SALVAR AS INFORMAÇÕES DECLARADAS PELO USUARIO NO ARQUIVO .TXT *OK
{
    ofstream escrever;      //DECLARAÇÃO DE UM FILE HANDLE PARA UM ARQUIVO TEXTO

    escrever.open("filme.txt", ofstream:: trunc);     // ABERURA DO ARQUIVO

    if (!escrever.is_open())        // VERIFICA SE O ARQUIVO FOI ABERO SEM NENHUM ERRO
    {
        cout << "Não foi possivel abrir o arquivo. Tente novamente !" <<endl;
        exit(-1);
    }

    else{
    for (int i=0 ; i < m-1 ; i++)
    {
                                                // PASSA AS INFORMAÇÕES DA VARIÁVEL PARA O ARQUIVO .TXT
    escrever << inf[i].nome << "\n";
    escrever << inf[i].obs << "\n";
    escrever << inf[i].status<<"\n";
    escrever << inf[i].data.dia << " " << inf[i].data.mes << " " << inf[i].data.ano<<"\n";
    }
    escrever.close();       // FECHAR ARQUIVO
    }
}


void salvar_dados ()    // SALVAR AS INFORMAÇÕES DECLARADAS PELO USUARIO NO ARQUIVO .TXT *OK
{
    Filmes informacoes;

    ofstream escrever;      //DECLARAÇÃO DE UM FILE HANDLE PARA UM ARQUIVO TEXTO

    escrever.open("filme.txt", ofstream:: app);     // ABERURA DO ARQUIVO

    informacoes = entrar_dados ();      // RECEBER DADOS DA FUNÇÃPO QUE INTERAGIL COM O USUA.

    if (!escrever.is_open())        // VERIFICA SE O ARQUIVO FOI ABERO SEM NENHUM ERRO
    {
        cout << "Não foi possivel abrir o arquivo. Tente novamente !" <<endl;
        exit(-1);
    }
                                                // PASSA AS INFORMAÇÕES DA VARIÁVEL PARA O ARQUIVO .TXT
    escrever << informacoes.nome << "\n";
    escrever << informacoes.obs << "\n";
    escrever << informacoes.status<<"\n";
    escrever << informacoes.data.dia << " " << informacoes.data.mes << " " << informacoes.data.ano << "\n";

    escrever.close();       // FECHAR ARQUIVO

    cout << "\n\nFilme Adicionado !!\n";
}

int ler_dados (Filmes inf [MAX])        // SALVA AS INFORMAÇÕES DO ARQUIVO .TXT EM UMAS VARIÁVEL *OK
{
    int cont=0;

    ifstream ler;       //DECLARAÇÃO DE UM FILE HANDLE PARA UM ARQUIVO TEXTO

    ler.open ("filme.txt");     // ABERURA DO ARQUIVO

    if (!ler.is_open())     // VERIFICA SE O ARQUIVO FOI ABERO SEM NENHUM ERRO
    {
        cout << "Não foi possivel abrir o arquivo. Tente novamente !" <<endl;
        exit(-1);
    }

                            // PASSA AS INFORMAÇÕES DO ARQUIVO .TXT PARA UMA VARIAVEL
    while (!ler.eof())
    {
    ler.getline(inf[cont].nome,MAX);
    ler.getline(inf[cont].obs,MAX);
    ler>> inf[cont].status;
    ler >> inf[cont].data.dia >> inf[cont].data.mes >> inf[cont].data.ano;

    ler.ignore();

    cont++;

    }

    ler.close();
return cont;
}



void pesquisa (char buscar[MAX_NOME])       // PESQUISA FILME PELA PALACRA CHAVE *OK
{
    int c=0;
    string line;
    Filmes aux;

    ifstream ler;
    ler.open ("filme.txt");

    if (!ler.is_open())
    {
        cout << "Não foi possivel abrir o arquivo. Tente novamente !" <<endl;
        exit(-1);
    }

        size_t pos;
        while ( getline (ler,line) ){
            pos=line.find(buscar);      // PESQUISAR
                if(pos!=string::npos){
                                                    // PASSAR DADOS ENCONTRADOS DO ARQ. PARA UM STRING
                    ler.getline(aux.obs,MAX_OBS);
                    ler >> aux.status;
                    ler >> aux.data.dia >> aux.data.mes >> aux.data.ano;
                                                    // IMPRIME NA TELA AS INFORMAÇÕES INCONTRADAS
                    cout <<endl;
                    cout << "Nome: "<< line << endl ;
                    cout <<"Data: " << aux.data.dia << "/" << aux.data.mes << "/" << aux.data.ano <<endl;

                    if (aux.status == 1)
                    {
                        cout <<"Status: " << aux.status << " - BAIXADO." <<endl;
                    }
                    else if (aux.status == 2)
                    {
                            cout <<"Status: " << aux.status << " - ASSISTIDO." <<endl;
                    }
                    else if (aux.status == 3)
                    {
                            cout <<"Status: " << aux.status << " - NO HD." <<endl;
                    }
                    else if (aux.status == 4)
                    {
                            cout <<"Status: " << aux.status << " - NÃO LANÇADO." <<endl;
                    }
                    else
                    {
                            cout <<"Status: " << aux.status << " - LANÇADO." <<endl;
                    }

                    cout <<"Observação: " << aux.obs<< endl ;
                    cout << endl;
                    c++;
                }
        }
        if (c==0)       // MENSAGM CASO NÃO SEJA ENCONTRADA
        {
            cout << "Nenhuma arquivo encontrado com a palavra chave: "<< buscar <<". Tente Novamente."<<endl;
        }

    ler.close();

}

//  ***********************  PESQUISA  *******************************************************

void pesquisa_mes(Filmes todos[MAX],int chave,int cont)  // ACHA DADOS DE UM MES ESPECÍFICO
{
    Filmes retorno_mes[MAX_PESQUISA];
    int x=0;
    for (int i=0; i<=cont ; i++)
    {
        if (todos[i].data.mes == chave)
        {                                   // COPIA  DOS DADOS PARA UM NOVO ARRAY[MES]
            strcpy(retorno_mes[x].nome,todos[i].nome);
            strcpy(retorno_mes[x].obs,todos[i].obs);
            retorno_mes[x].data.dia = todos[i].data.dia;
            retorno_mes[x].data.mes = todos[i].data.mes;
            retorno_mes[x].data.ano = todos[i].data.ano;
            retorno_mes[x].status = todos[i].status;
        x++;
        }
    }

    if (x==0){                            // MESAGEM SE NÃO HOVER NENHUMA COMBINAÇÃO
        cout << "Nenhum Filme Encontrado ! \n";
    }

    else
    {                                  // ORDENAÇÃO CRONOLOGOCA DO NOVO ARRAY
        ordenacao_ano(retorno_mes,x);
        ordenacao_ano_mes_dia(retorno_mes,x);

        for (int i=0 ; i<x ; i++)       //  IMPRESSÃO DO NOVO ARRAY
        {
        cout <<endl;
        cout << "Filme " << i+1 <<": "<<endl;
        cout << "Nome: "<< retorno_mes[i].nome << endl ;
        cout <<"Data: " << retorno_mes[i].data.dia << "/" << retorno_mes[i].data.mes << "/" << retorno_mes[i].data.ano <<endl;

        if (retorno_mes[i].status == 1)
        {
                cout <<"Status: " << retorno_mes[i].status << " - BAIXADO." <<endl;
        }
        else if (retorno_mes[i].status == 2)
        {
                cout <<"Status: " << retorno_mes[i].status << " - ASSISTIDO." <<endl;
        }
        else if (retorno_mes[i].status == 3)
        {
                cout <<"Status: " << retorno_mes[i].status << " - NO HD." <<endl;
        }
        else if (retorno_mes[i].status == 4)
        {
                cout <<"Status: " << retorno_mes[i].status << " - NÃO LANÇADO." <<endl;
        }
        else
        {
                cout <<"Status: " << retorno_mes[i].status << " - LANÇADO." <<endl;
        }


        cout <<"Observação: " << retorno_mes[i].obs << endl ;
        cout <<endl;
        }
    }
}

void pesquisa_data(Filmes saida[MAX],Data chave,int cont)    // ACHA DADOS DE UMA DATA ESPECÍFICO
{
    int x;
    for (int i=0; i<=cont ; i++)
    {
        if (saida[i].data.dia == chave.dia && saida[i].data.mes == chave.mes && saida[i].data.ano == chave.ano )        //  VERIFICA SE EXISTE A DATANO ARQUIVO
        {                                                   // IMPRESSÃO SE OUVER COMBINAÇÃO
        cout << "Nome: "<< saida[i].nome << endl ;
        cout <<"Data: " << saida[i].data.dia << "/" << saida[i].data.mes << "/" << saida[i].data.ano <<endl;

        if (saida[i].status == 1)
        {
                cout <<"Status: " << saida[i].status << " - BAIXADO." <<endl;
        }
        if (saida[i].status == 2)
        {
                cout <<"Status: " << saida[i].status << " - ASSISTIDO." <<endl;
        }
        if (saida[i].status == 3)
        {
                cout <<"Status: " << saida[i].status << " - NO HD." <<endl;
        }
        if (saida[i].status == 4)
        {
                cout <<"Status: " << saida[i].status << " - NÃO LANÇADO." <<endl;
        }
        if (saida[i].status == 5)
        {
                cout <<"Status: " << saida[i].status << " - LANÇADO." <<endl;
        }

        cout <<"Observação: " << saida[i].obs << endl ;
        x++;
        cout << endl;
        }

    }

    if (x==0){
        cout << "Nenhum Filme Encontrado ! \n";
    }
}



// ******************** ORDENAÇÃO ************************************

void ordenacao_ano (Filmes inf[MAX],int n)      // ORDENAR POR ANO OS ARRAYS
{
/*
                            // VERIFCAR SE JA ESTA EM ORDEM:
    bool ordem=true;

    for(int i=0;i<n;i++)
    {
        if(inf[i].data.dia < inf[i+1].data.dia && inf[i].data.ano < inf[i+1].data.ano )
        {
            ordem = false;
            break;
        }
    }
*/
                            // COLOCAR EM ORDEM:
    bool troca=true;
    int ultimo=n-1;
    Filmes aux;

//    if (ordem==false)
//    {

        while(troca==true)      //  REPETIÇÃO DO ORDENAMENTO / COMANDO DE PARADA
        {
            troca=false;
            for (int i=0 ; i<ultimo-1 ; i++)
            {
                if (inf[i].data.ano > inf[i+1].data.ano)        // INVERSÃO DOS VALODES DESORDENADOS
                {
                    strcpy(aux.nome,inf[i].nome);
                    strcpy(aux.obs,inf[i].obs);
                    aux.data.dia = inf[i].data.dia;
                    aux.data.mes = inf[i].data.mes;
                    aux.data.ano = inf[i].data.ano;
                    aux.status = inf[i].status;

                    strcpy(inf[i].nome,inf[i+1].nome);
                    strcpy(inf[i].obs,inf[i+1].obs);
                    inf[i].data.dia = inf[i+1].data.dia;
                    inf[i].data.mes = inf[i+1].data.mes;
                    inf[i].data.ano = inf[i+1].data.ano;
                    inf[i].status = inf[i+1].status;

                    strcpy(inf[i+1].nome,aux.nome);
                    strcpy(inf[i+1].obs,aux.obs);
                    inf[i+1].data.dia = aux.data.dia;
                    inf[i+1].data.mes = aux.data.mes;
                    inf[i+1].data.ano = aux.data.ano;
                    inf[i+1].status = aux.status;

                    troca=true;
                }
            }
            ultimo=ultimo-1;
        }
//    }
}
void ordenacao_ano_mes (Filmes inf[MAX],int n)      // ORDENAÇÃO DOS MESSES APOS ORDENAÇÃO POR ANO
{
/*
    cout << endl << "Verificação Entrada" <<endl;

                            // VERIFCAR SE JA ESTA EM ORDEM:
    bool ordem=true;

    for(int i=0;i<n;i++)
    {
        if(inf[i].data.ano < inf[i+1].data.ano)
        {
            ordem = false;
            break;
        }
    }
*/
                            // COLOCAR EM ORDEM:
    bool troca=true;
    int ultimo=n-1;
    Filmes aux;

//    if (ordem==false)
//    {

        while(troca==true)
        {
            troca=false;
            for (int i=0 ; i<ultimo-1 ; i++)
            {
                if (inf[i].data.mes > inf[i+1].data.mes && inf[i].data.ano == inf[i+1].data.ano )        // INVERSÃO DOS VALODES DESORDENADOS
                {
                    strcpy(aux.nome,inf[i].nome);
                    strcpy(aux.obs,inf[i].obs);
                    aux.data.dia = inf[i].data.dia;
                    aux.data.mes = inf[i].data.mes;
                    aux.data.ano = inf[i].data.ano;
                    aux.status = inf[i].status;

                    strcpy(inf[i].nome,inf[i+1].nome);
                    strcpy(inf[i].obs,inf[i+1].obs);
                    inf[i].data.dia = inf[i+1].data.dia;
                    inf[i].data.mes = inf[i+1].data.mes;
                    inf[i].data.ano = inf[i+1].data.ano;
                    inf[i].status = inf[i+1].status;

                    strcpy(inf[i+1].nome,aux.nome);
                    strcpy(inf[i+1].obs,aux.obs);
                    inf[i+1].data.dia = aux.data.dia;
                    inf[i+1].data.mes = aux.data.mes;
                    inf[i+1].data.ano = aux.data.ano;
                    inf[i+1].status = aux.status;

                    troca=true;
                }
            }
            ultimo=ultimo-1;
        }
 //   }
}


void ordenacao_ano_mes_dia (Filmes inf[MAX],int n)      // ORDENAÇÃO DOS DIA  APOS ORDENAÇÃO POR ANO E MÊS
{
// COLOCAR EM ORDEM:
    bool troca=true;
    int ultimo=n-1;
    Filmes aux;

//    if (ordem==false)
//    {

        while(troca==true)
        {
            troca=false;
            for (int i=0 ; i<ultimo-1 ; i++)
            {
                if (inf[i].data.dia > inf[i+1].data.dia && inf[i].data.mes == inf[i+1].data.mes && inf[i].data.ano == inf[i+1].data.ano )        // INVERSÃO DOS VALODES DESORDENADOS
                {
                    strcpy(aux.nome,inf[i].nome);
                    strcpy(aux.obs,inf[i].obs);
                    aux.data.dia = inf[i].data.dia;
                    aux.data.mes = inf[i].data.mes;
                    aux.data.ano = inf[i].data.ano;
                    aux.status = inf[i].status;

                    strcpy(inf[i].nome,inf[i+1].nome);
                    strcpy(inf[i].obs,inf[i+1].obs);
                    inf[i].data.dia = inf[i+1].data.dia;
                    inf[i].data.mes = inf[i+1].data.mes;
                    inf[i].data.ano = inf[i+1].data.ano;
                    inf[i].status = inf[i+1].status;

                    strcpy(inf[i+1].nome,aux.nome);
                    strcpy(inf[i+1].obs,aux.obs);
                    inf[i+1].data.dia = aux.data.dia;
                    inf[i+1].data.mes = aux.data.mes;
                    inf[i+1].data.ano = aux.data.ano;
                    inf[i+1].status = aux.status;

                    troca=true;
                }
            }
            ultimo=ultimo-1;
        }
//    }
}



/// ******************** OUTROS ************************************


Data data_automatica ()      // DATA ATUAL
{
    Data x;

    time_t now;

    struct tm nowLocal;

    now = time (NULL); /// GET THE TIME FORM THE OS

    nowLocal = *localtime(&now);

    x.dia = nowLocal.tm_mday;
    x.mes = nowLocal.tm_mon+1;
    x.ano = nowLocal.tm_year+1900;

    //cout << x.dia << " "<< x.mes << " " << x.ano  <<endl;

    return x;
}



void Atual_automatica_status (Filmes inf[MAX],int quant_filmes)
{
    Data data_atual;


    data_atual = data_automatica();

    for (int i=0 ; i<quant_filmes ; i++)
    {
        if ((data_atual.dia>= inf[i].data.dia) && (data_atual.mes>=inf[i].data.mes) && (data_atual.ano>=inf[i].data.ano) && (inf[i].status == 4) || (data_atual.ano > inf[i].data.ano) && (inf[i].status == 4))
        {
            inf[i].status=5;
        }
    }
}

