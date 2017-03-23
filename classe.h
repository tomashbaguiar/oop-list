#ifndef CLASSE_H
#define CLASSE_H

#include <stddef.h>
#include <iostream>
#include <fstream>

struct _Node;
typedef struct _Node Node;

class Lista
{
	private:
		int size_;	//Guarda o número de elementos da lista.
		Node *head;	//Aponta para o primeiro nó da lista.
	public:
		Lista();	//Construtor de lista vazia.
		bool empty();	//Testa se a lista está vazia.
		int size();	//Retorna o número de elementos na lista.
		Node* find(int key);	//Verifica se um elemento estpa na lista e retorna seu enedereço.
		void encontra(int key);
		void insert(int data);	//Insere um novo nó na lista.
		void remove(int data);	//Remove um nó da lista.
//		void imprime();		//Imprime a lista na ostream cout.
		friend std::ostream& operator<<(std::ostream& os, const Lista& lista);
		friend std::ofstream& operator<<(std::ofstream& os, const Lista& lista);
	//	void operator>>(std::ifstream &outFile);	//Escreve a lista em um arquivo de saida.
		~Lista();	//Destrutor de lista, desaloca o espaço usado.
};

#endif //CLASSE_H
