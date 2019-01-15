
#include <iostream>
using namespace std;
#include <cstdlib>
#include "Pokemon.h"
#include "WaterPokemon.h"
#include "FirePokemon.h"
#include "GrassPokemon.h"
#include "PokemonTeam.h"

//This is the function for creating the player's team
void CreatePlayerTeam();

//This is the function for creating the computer's team
void CreateComputerTeam();


PokemonTeam playerTeam,computerTeam;




//This is the menu function
int menu()
{
	int choice;
	cout <<"\t\tMAIN MENU\n"
		 <<"\t\t=========\n"
		 <<"\t\t1. Fight an opponent! \n"
		 <<"\t\t2. Create your team! \n"
		 <<"\t\t3. Save your team to a file! \n"
		 <<"\t\t4. View High Scores \n"
		 <<"\t\t5. EXIT \n \t \t";
	cin >>choice;
	return choice;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PLAY FUNCTION


int main()
{
	int option;
	//only leaves when letter 4, This works for Chars and String as well! 
	do
	{
		int score = 0;
			option = menu();
			switch(option)
			{
						case 1: cout<<"A horde of Monsters have arrived! \n";
								//CALL PLAY FUNCTION
								//when you lose,, Score: scoreVal TeamName
								//Check if team is 6 / FULL
									//While(team != empty)
										//if so, create enemy of random type no skill
											//if (lose), dequeue 
											//else
												//score++;
									
										
								break;
						case 2: cout <<" Create your Team! \n";
								//CALL CREATETEAM FOR TEAMQUEUE
								CreatePlayerTeam();
								break;
						case 3: cout <<" \n";
								//CALL SCOREVIEW
								break;
						case 4: cout <<" HIGH SCORES: \n";
					
								break;
						case 5: 
						//EXIT
								break;
						default: cout <<"ERROR: Invalid option!\n";
						
			}
			system("PAUSE");
			system("CLS");
	}while (option != 5);
	
	cout <<"Thank you for playing!"<<endl;
	
	//system("PAUSE");
	return 0;
}

//This is the function for creating a team
void CreatePlayerTeam()
{
	for(int i=0;i<6;i++)
	{
		cout<<"Pockemon "<<(i+1)<<": \n";
		playerTeam.addPokemon();
	}
	playerTeam.displayTeam();
}
