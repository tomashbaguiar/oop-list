#include "classe.h"
/*#include <stddef.h>
#include <iostream>
#include <fstream>*/

struct _Node
{
	int data;	//Recebe o dado (inteiro) do nó.
	Node *next;	//Ponteiro para o pŕoximo nó.
};

Lista::Lista()
{
	head = new Node;	//Aloca espaço para o ponteiro head.
	head->next = NULL;	//Head aponta para NULL.
	size_ = 0;		//Define o tamanho inicial da lista.
}

bool Lista::empty()	{return (size_ == 0);}

int Lista::size()	{return size_;}

Node* Lista::find(int key)
{
	for(Node* i = head->next; i != NULL; i = i->next)
	{
		//Retorna o nó i se este contiver key.
		if(i->data == key)	
			return i;	
	}
	
	return NULL;	//Retorna NULL se não encontrar key.
}

void Lista::encontra(int key)
{
	Node *k = find(key);
	if(k != NULL)
		std::cout << "O elemento " << key << " estah na lista." << std::endl;
}

void Lista::insert(int dado)
{
	Node *prev = head;

	//Encontra o último elemento menor que dado na lista.
	while((prev->next != NULL) && (prev->next->data < dado))
	{
		prev = prev->next;
	}
	
	//Caso dado não esteja na lista, cria um novo nó para ele.
	if((prev->next == NULL) || (prev->next->data != dado))
	{
		Node *node = new Node;
		node->data = dado;
		node->next = prev->next;
		prev->next = node;
		size_++;	//Incrementa o tamanho da lista.
	}
}

void Lista::remove(int dado)
{
	Node *place = find(dado);	//Localização do dado na lista.

	Node *aux = new Node;
	aux->next = head;

	while(aux->next->next != place)
		aux->next = aux->next->next;
	
	aux->next->next = place->next;
	delete place;
	delete aux;
}

Lista::~Lista()
{
	Node *aux1 = new Node;
	aux1 = head;

	delete head;
	
	Node *aux2 = new Node;
	aux2 = aux1->next->next;
	
	while(aux2->next != NULL)
	{
		delete aux1->next;
		aux1->next = aux2->next;
		aux2->next = aux2->next->next;
	}
	
	delete aux2;
	delete aux1->next;
	delete aux1;
}

std::ostream& operator<<(std::ostream& os, const Lista& lista)
{
	os << "HEAD->";
	
	for(Node *i = lista.head->next; i != NULL; i = i->next)
		os << i->data << "->";

	os << std::endl;

	return os;
}

std::ofstream& operator<<(std::ofstream& os, const Lista& lista)
{
	for(Node *i = lista.head->next; i != NULL; i = i->next)
		os << i->data << std::endl;

	return os;
}
