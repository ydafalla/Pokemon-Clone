
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "Pokemon.h"
#include "WaterPokemon.h"
#include "FirePokemon.h"
#include "GrassPokemon.h"
#include "PokemonTeam.h"

//This is the function for creating the player's team
void CreatePlayerTeam();

int score = 0;
std::string scoreString;
PokemonTeam playerTeam;
PokemonTeam scoredTeam;

//This is the menu function
int menu()
{
	int choice;
	std::cout << "\t\tMAIN MENU\n"
		 << "\t\t=========\n"
		 << "\t\t1. Fight an opponent! \n"
		 << "\t\t2. Create your team! \n"
		 << "\t\t3. View High Scores \n"
		 << "\t\t4. EXIT \n \t \t";
	std::cin >> choice;
	return choice;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PLAY FUNCTION
int play()
{
	scoredTeam = playerTeam;
	//when you lose,, Score: scoreVal TeamName
	//Check if team is 6 / FULL
	int rand_int;
	if (!playerTeam.isEmpty())
	{
		std::cout << "A wild monster appeared!" << std::endl;
		//CODE SUPPLIED FROM https://www.daniweb.com/programming/software-development/threads/1769/c-random-numbers

		int rand_int;
		//GENERATE ENEMY
		rand_int = (rand() % 3 + 1);
		if (rand_int == 1)
		{
			std::cout << "The enemy is a Grass type!" << std::endl;
		}
		if (rand_int == 2)
		{
			std::cout << "The enemy is a Fire type!" << std::endl;
		}
		if (rand_int == 3)
		{
			std::cout << "The enemy is a Water type!" << std::endl;
		}
		//Now Battle!
		//WINNING SITUATIONS
		std::cout << "Your pokemon is: " << playerTeam.getFirst() << std::endl;
		if ((playerTeam.getFirst() == "Grass" && rand_int == 3) || (playerTeam.getFirst() == "Fire" && rand_int == 1) || (playerTeam.getFirst() == "Water" && rand_int == 2))
		{
			std::cout << "You won!" << std::endl;
			score++;
			std::cout << "Score: " << score << std::endl;
		}
		//TIES
		if ((playerTeam.getFirst() == "Grass" && rand_int == 1) || (playerTeam.getFirst() == "Fire" && rand_int == 2) || (playerTeam.getFirst() == "Water" && rand_int == 3))
		{
			std::cout << "ITS A TIE!" << std::endl;
			std::cout << "Score: " << score << std::endl;
		}
		//LOSE
		if ((playerTeam.getFirst() == "Grass" && rand_int == 2) || (playerTeam.getFirst() == "Fire" && rand_int == 3) || (playerTeam.getFirst() == "Water" && rand_int == 1))
		{
			std::cout << "You lost!" << std::endl;
			//Remove the Top pokemon
			playerTeam.removePokemon();
			std::cout << "Score: " << score << std::endl;
			std::cout << "Remaining Team: " << std::endl;
			playerTeam.displayTeam();
			std::cout << scoreString;
		}
		if (playerTeam.isEmpty())
		{
			std::cout << "YOUR HIGH SCORE IS: " << score << std::endl;
		}
	}
	else
	{
		std::cout << "You do not have a full team of monsters ready." << std::endl;
	}
}

void scoreView()
{
	//append to file
	std::ofstream outScore;
	outScore.open("scores.txt", std::ios_base::app);
	outScore << score << " ";
	std::string teamString = playerTeam.getTeamString();
	outScore << teamString << std::endl;
	outScore.close();

	// //read from file into an array
	std::ifstream inScore;
	inScore.open("scores.txt");
	std::string scoreArray[11];
	int index = 0;
	std::string str;
	while (std::getline(inScore, str))
	{
		scoreArray[index] = str;
		index++;
	}
	inScore.close();

	// //sort by score
	sort(scoreArray, scoreArray + 10, std::greater<std::string>());
	

	//write to file
	outScore.open("scores.txt");
	for (int l = 0; l < 10; l++)
	{
		outScore << scoreArray[l] << std::endl;
	}

	//display results
	for (int l = 0; l < 10; l++)
	{
		std::cout << (l + 1) << ". " << scoreArray[l] << std::endl;
	}
}

int main()
{
	int option;
	do
	{
		//int score = 0;
		option = menu();
		switch (option)
		{
		case 1: //Fight!
			play();
			break;
		case 2:
			std::cout << " Create your Team! \n";
			//CALL CREATETEAM FOR TEAMQUEUE
			CreatePlayerTeam();
			break;
		case 3:
			std::cout << "High Scores! \n";
			scoreView();
			break;
		case 4:
			//EXIT
			break;
		default:
			std::cout << "ERROR: Invalid option!\n";
		}
		system("PAUSE");
		system("CLS");
	} while (option != 4);

	std::cout << "Thank you for playing!" << std::endl;

	//system("PAUSE");
	return 0;
}

//This is the function for creating a team
void CreatePlayerTeam()
{
	score = 0;

	if (playerTeam.isFull())
	{
		for (int i = 0; i < 6; i++)
		{
			playerTeam.removePokemon();
		}
	}
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Pokemon " << (i + 1) << ": \n";
		playerTeam.addPokemon();
	}
	playerTeam.displayTeam();
}
