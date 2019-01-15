//WaterPokemon.h
//This is a derived class from Pokemon

#ifndef WaterPokemon_H
#define WaterPokemon_H
#include "Pokemon.h"
class WaterPokemon : public Pokemon
{
  public:
	WaterPokemon();
	virtual void PrintType() const;
	virtual std::string getType() const;

  private:
	std::string weapon;
};

WaterPokemon::WaterPokemon()
{
	type = "Water";
}
void WaterPokemon::PrintType() const
{
	std::cout << "WATER POKEMON\n";
}
std::string WaterPokemon::getType() const
{
	return type;
}

#endif
