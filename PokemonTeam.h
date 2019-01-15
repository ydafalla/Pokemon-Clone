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
class PokemonNode
{
	public:
		Pokemon* pokemon;
		PokemonNode* next;	
};

class PokemonTeam
{
	private:
		PokemonNode* front;
		PokemonNode* rear;
		int numberOfPokemons;
		int maximum;
		
	public:
		PokemonTeam();
		bool isEmpty();
		bool isFull();
		void addPokemon();
		void removePokemon();
		void displayTeam();
};

PokemonTeam::PokemonTeam()
{
	numberOfPokemons=0;
	front=NULL;
	rear=NULL;
	maximum=6;
}

//This Function is used for displaying all the members of the team
void PokemonTeam::displayTeam()
{
	int i=1;
	PokemonNode* pNav=front;
	cout<<"=====Your Team======\n";
	if(PokemonTeam::isEmpty())
	{
		cout<<"There are no members in the team\n";
	}
	else
	{
		while(pNav!=NULL)
		{
			cout<<i++<<". ";
			pNav->pokemon->PrintType();
			pNav=pNav->next;
		}
	}
}


//addPokemon function
void PokemonTeam::addPokemon()
{
	PokemonNode* poky=new PokemonNode;
	if(numberOfPokemons==maximum)
	{
		cout<<"The team is Full\n";
	}
	else
	{
		int i;
		do
		{
			cout<<"=======Menu=======\n"
			<<"Enter the type of Pokemon\n"
			<<"1. Fire\n"
			<<"2. Water\n"
			<<"3. Grass\n";
			cin>>i;
			switch(i)
			{
				case 1:
					poky->pokemon=new FirePokemon;
					break;
				case 2:
					poky->pokemon=new WaterPokemon;
					break;
				case 3:
					poky->pokemon=new GrassPokemon;
					break;
				default:
					cout<<"Wrong choice try again\n";
					break;
			} 
		}while(i<1 || i>3);
		if(numberOfPokemons==0)
		{
			poky->next=NULL;
			front=poky;
			rear=poky;
			numberOfPokemons++;
		}
		else
		{
			rear->next=poky;
			poky->next=NULL;
			rear=poky;
			numberOfPokemons++;	
			
		}
	}
}

//IsEmpty Function
bool PokemonTeam::isEmpty()
{
	return (rear==NULL);
}


//removePokemon Function
void PokemonTeam::removePokemon()
{
	if(isEmpty())
	{
		cout<<"PokemonTeam is empty\n";
	}
	else
	{
		PokemonNode* oldNode=front;
		if(front==rear)
		{
			front=rear=NULL;
		}
		else
		{
			front=front->next;
		}
		delete oldNode;
	}
}
