#include <iostream>
#include <cstdlib>
#include <string>
#include "classe.h"

using namespace std;

int main(int argc, char *argv[])	//	./lista [cin ou ifstream] [cout ou ofstream]
{
	if(argc != 3)
	{
		cout << "A quantidade de argumentos eh invalida (" << argc << ")." << endl;
		return EXIT_FAILURE;
	}

	Lista lista;

	string argu[3];
        for(int i = 0; i < 3; i++)
                argu[i] = argv[i];

	if(!(argu[1].compare("cin") || argu[1].compare("ifstream")))
	{
		cout << argu[1] << ": argumento invalido." << endl;
		return EXIT_FAILURE;
	}
	if(!(argu[2].compare("cout") || argu[2].compare("ofstream")))
	{
		cout << argu[2] << ": argumento invalido." << endl;
		return EXIT_FAILURE;
	}
		

/*      ENTRADA DE DADOS - ISTREAM: cin ou ifstream     */

        if(!argu[1].compare("cin"))
        {
                string number;

                int counter = 0;

                do
                {
                        cout << "Entre com o inteiro numero " << counter << ": ";
                        cin >> number;
                        if(number.compare("-"))
                                lista.insert(atoi(number.c_str()));
                }
                while(number.compare("-"));     // - sai da entrada de numeros. 
        }
        else if(!argu[1].compare("ifstream"))
        {
                string file_in = "Input.txt";
                ifstream inFile("Input.txt");
                if(inFile.is_open())
                {
                        string number;
                        while(getline(inFile, number))
                                lista.insert(atoi(number.c_str()));
                }
                else
                        cout << "Incapaz de abrir/ler arquivo " << file_in << endl;

                inFile.close();
        }

/*	MENU de opçoes	*/

	unsigned short int choice = 0;

	do 
	{

	        cout << "Digite: " << endl << " 0 - Sair do programa." << endl
        	                        << " 1 - Inserir um elemento na lista." << endl
                	                << " 2 - Remover um elemento da lista." << endl
                        	        << " 3 - Verificar se um elemento estah na lista." << endl;
	        cout << "Escolha: ";
        	cin >> choice;
		
		int number;
	
		switch(choice)
		{
			case 1:
				cout << "Elemento: ";
				cin >> number;
				lista.insert(number);
				break;
			case 2:
				cout << "Elemento: ";
				cin >> number;
				lista.remove(number);
				break;
			case 3:
				cout << "Elemento: ";
				cin >> number;
				lista.encontra(number);
				break;
			default:
				cout << endl << "Saindo..." << endl;
				choice = 0;
		}
	}
	while(choice != 0);

	/*      SAIDA DE DADOS - OSTREAM: cout ou ofstream      */

        if(!argu[2].compare("cout"))
                cout << lista;
        else if(!argu[2].compare("ofstream"))
        {
                string file_out = "Output.txt";
                ofstream outFile("Output.txt");
                if(outFile.is_open())
                        outFile << lista;
                else
                        cout << "Incapaz de abrir/escrever arquivo " << file_out << endl;

                outFile.close();
        }

	cout << lista;

	return EXIT_SUCCESS;
}
