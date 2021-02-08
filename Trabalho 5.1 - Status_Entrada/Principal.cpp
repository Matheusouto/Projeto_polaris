#include <iostream>
#include "Funcoes_e_estruturas.h"

using namespace std;

int main ()
{
    setlocale(LC_ALL,"portuguese");

    // VARIAVEIS
    int oq_fazer,quantidade_filmes,continuar;
    Filmes retorno[MAX];
    char buscar[MAX_NOME];

    do{
        ////system("clear");        // LIMPAR TELA LINUX
        system("CLS");

                    //VALIDA��O DA ENTRADA
         do{
            oq_fazer = menu_inicial();      //CHAMADA DA FUN��O MENU

            //////system("clear");        // LIMPAR TELA LINUX
            system("CLS");

            if (oq_fazer <1 || oq_fazer>4)
            {
                cout << "Op��o Invalida, ESCOLHA 1, 2 OU 3 !! "<<endl;
            }
        }while (oq_fazer <1 || oq_fazer>4);


        switch (oq_fazer)           // OP��ES A PARTIR DO MENU(PRIMARIO):
        {
        case 1:     // ADICIONAR NOVO FILME

            salvar_dados();

            break;

        case 2:         // VISUALIZAR FILMES
            quantidade_filmes = ler_dados (retorno); //  PASSA INF. DO  ARQUIVO PARA A VARI�VEL.

            menu_secundario(quantidade_filmes,retorno);     //OP��ES DE VISULIZA��O

            break;

        case 3:     // BUSCA ESPEC�FICA
            cout << "Deseja busacar por (Nome): ";
            cin.ignore();
            cin.getline(buscar,MAX_NOME);

            pesquisa(buscar);

            break;
        //SAIR
        case 4:
            exit(-1);
            break;

        }

        cout << "Deseja:\n";
        cout<< "\t[1] - VOLTAR AO MENU.";
        cout <<"\t[2] - SAIR."<<endl;
        cout<<" . . . ";

        cin>>continuar;

        if (continuar==2){
            exit(-1);
        }
    }while(continuar==1);

    system("PAUSE");
    return 0;
}
