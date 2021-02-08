#include<time.h>
#include<iostream>
#include <stdlib.h>

using namespace std;

struct Data
{
	int dia;
	int mes;
	int ano;
};

void ParseData(Data alvo);

int main()
{
    Data alvo;

    ParseData(alvo);

}


void ParseData(Data alvo){

    char data[9];
    char aux;
    int k=9;
    bool barra=true;
	_strdate(data); // pega a data atual e salva em um char

    cout << data;



    while(barra){
        for (int i=0 ; i<k  ; i++)
        {
            barra=false;
            if (data[i]=='/')
            {
                aux=data[i];
                data[i] = data[i+1];
                data[i+1] = aux;
                barra = true;

            }cout <<endl<<data;

        }
        k--;
        cout <<k;
    }

   // int i = atoi(str);

    //cout <<"-"<< i;


}
