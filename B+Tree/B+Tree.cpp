// B+Tree.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "BTree.h"
#include "BTreeNode.h"

int takeInputInt(std::string message);

int main(){
	int value;
	BTree *bTree = new BTree();
	do
	{
		std::cout << "1: Creare un nuovo B-Tree" << std::endl;
		std::cout << "2: Inserire una chiave" << std::endl;
		std::cout << "3: Ricercare una chiave" << std::endl;
		std::cout << "4: Eliminare una chiave" << std::endl;
		std::cout << "5: Stampa delle chiavi" << std::endl;
		std::cout << "6: Uscita" << std::endl;
		value = takeInputInt("Inserire la scelta: ");
		switch (value)
		{
			case 1:
				{
					if (!(bTree->exists)())
					{
						value = takeInputInt("Inserire il grado: ");
						bTree->setT(value);
					}
					else
						std::cout << "Non e' possibile creare un nuovo albero" << std::endl;
					break;
				}
			case 2:
				{
				if (bTree->exists())
				{
					value = takeInputInt("Inserire la chiave: ");
					if (bTree->search(value) == NULL)
					{
						bTree->insert(value);
						std::cout << "La chiave e' stata inserita" << std::endl;
					}
					else
						std::cout << "Non e' possibile inserire questa chiave" << std::endl;
				}
				else
					std::cout << "L'albero non esiste " << std::endl;
				break;
				}
			case 3:
				{
					value = takeInputInt("Inserire la chiave: ");
					if (bTree->search(value) == NULL)
						std::cout << "la chiave inserita non e' presente" << std::endl;
					else
						std::cout << "la chiave inserita e' stata trovata"<< std::endl;
					break;
				}
			case 4:
				{
					value = takeInputInt("Inserire la chiave da eliminare: ");
					if(bTree->search(value) == NULL) 
						std::cout << "Chiave non trovato!" << std::endl;
					else
					{
						bTree->remove(value);
						std::cout << "La chiave " << value << "e' stata eliminata" << std::endl;
					}
					break;
				}
			case 5:
				{
					std::cout << "Le chiavi: "; bTree->traverse(); std::cout << std::endl;
					break;
				}
			case 6:
				{
					goto a;
				}
			default:
				{
					break;
				}
		}
	} while (true);
	a: std::cout << "Il programma e' terminato" << std::endl;
	delete bTree;
}

int takeInputInt(std::string message) {

	int in;
	std::string temp;
	std::cout << message;
	while (std::getline(std::cin, temp))
	{
		std::stringstream stringStream(temp);
		if (stringStream >> in)
		{
			if (stringStream.eof())
			{
				break;
			}
		}
		std::cout << message;
	}
	std::cin.clear();
	return in;
}