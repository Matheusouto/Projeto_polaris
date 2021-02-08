#include<time.h>
#include<iostream>
#include <stdlib.h>

using namespace std;



int main()
{
    Data alvo;
	char date[9],data[9];
	_strdate(date);
	cout << date << endl;

	system ( "date /t" );

    // pega a data atual
	_strdate(data);
	cout << data;



}



