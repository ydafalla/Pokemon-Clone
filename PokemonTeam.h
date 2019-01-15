//This is the class that will hold the Pokemon Team
//The class is a queue with different Pokemon Nodes
//The class has the following functions
/*
1. addPokemon() for adding a pokemon node to the end of list
2. removePokemon() for removing the first Pokemon node from the list
3. IsEmpty() returns a boolean that tells whether the team is empty
4. IsFull() returns a boolean that tells whether the team is full
5. displayTeam() a function to display all the members of the team
Author: Yousif Dafalla
*/
#include <iostream>
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"
class PokemonNode
{
  public:
	Pokemon *pokemon;
	PokemonNode *next;
};

class PokemonTeam
{
  private:
	PokemonNode *front;
	PokemonNode *rear;
	int numberOfPokemons;
	int maximum;
	std::string teamString;

  public:
	PokemonTeam();
	PokemonNode *GetFront();
	bool isEmpty();
	bool isFull();
	void addPokemon();
	void removePokemon();
	void displayTeam();
	std::string getTeamString();
	//void changeMax(int a);
	//void addEnemy(int b);
	std::string getFirst();
};

std::string PokemonTeam::getTeamString()
{
	return teamString;
}
PokemonTeam::PokemonTeam()
{
	numberOfPokemons = 0;
	front = NULL;
	rear = NULL;
	maximum = 6;
}
/*
void PokemonTeam::changeMax(int a)
{
	maximum = a;
}

void PokemonTeam::addEnemy(int b)
{
	Pokemon* enemy;
	int t = b;
	switch(t)
	{
		case 1:
				enemy = new GrassPokemon;
				break;
		case 2:
				enemy = new FirePokemon;
				break;
		case 3:
				enemy = new WaterPokemon;
				break;
		default:
				cout<<"ERROR"<<endl;
				break;
	}
}
*/
std::string PokemonTeam::getFirst()
{
	PokemonNode *pNav = front;
	return pNav->pokemon->getType();
}

//This Function is used for displaying all the members of the team
void PokemonTeam::displayTeam()
{
	int i = 1;
	PokemonNode *pNav = front;
	if (PokemonTeam::isEmpty())
	{
		std::cerr << "There are no members in the team\n";
	}
	else
	{
		while (pNav != NULL)
		{
			std::cout << i++ << ". ";
			std::cout << pNav->pokemon->getType() << std::endl;
			pNav = pNav->next;
		}
	}
}

//addPokemon function
void PokemonTeam::addPokemon()
{
	PokemonNode *poky = new PokemonNode;
	if (numberOfPokemons == maximum)
	{
		std::cout << "The team is Full\n";
	}
	else
	{
		int i;
		do
		{
			std::cout << "=======Menu=======\n"
				 << "Enter the type of Pokemon\n"
				 << "1. Grass\n"
				 << "2. Fire\n"
				 << "3. Water\n";
			std::cin >> i;
			switch (i)
			{
			case 1:
				poky->pokemon = new GrassPokemon;
				std::cout << "You added a Grass Type Pokemon! " << std::endl;
				teamString += "G ";
				break;
			case 2:
				poky->pokemon = new FirePokemon;
				std::cout << "You added a Fire Type Pokemon! " << std::endl;
				teamString += "F ";
				break;
			case 3:
				poky->pokemon = new WaterPokemon;
				std::cout << "You added a Water Type Pokemon! " << std::endl;
				teamString += "W ";
				break;
			default:
				std::cout << "Wrong choice try again\n";
				break;
			}
		} while (i < 1 || i > 3);
		if (numberOfPokemons == 0)
		{
			poky->next = NULL;
			front = poky;
			rear = poky;
			numberOfPokemons++;
		}
		else
		{
			rear->next = poky;
			poky->next = NULL;
			rear = poky;
			numberOfPokemons++;
		}
	}
}

//IsEmpty Function
bool PokemonTeam::isEmpty()
{
	return (rear == NULL);
}

//IsFull Function
bool PokemonTeam::isFull()
{
	return numberOfPokemons == maximum;
}

PokemonNode *PokemonTeam::GetFront()
{
	return front;
}

//removePokemon Function
void PokemonTeam::removePokemon()
{
	if (isEmpty())
	{
		std::cout << "PokemonTeam is empty\n";
	}
	else
	{
		PokemonNode *oldNode = front;
		if (front == rear)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
		numberOfPokemons--;
		delete oldNode;
	}
}
