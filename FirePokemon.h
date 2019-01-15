//FirePokemon.h
//This is a fire pokemon class

#ifndef FirePokemon_H
#define FirePokemon_H
#include "Pokemon.h"
class FirePokemon : public Pokemon
{
  public:
	FirePokemon();
	virtual void PrintType() const;
	virtual std::string getType() const;

  private:
	std::string weapon;
};

FirePokemon::FirePokemon()
{
	type = "Fire";
}

void FirePokemon::PrintType() const
{
	std::cout << "FIRE POKEMON\n";
}
std::string FirePokemon::getType() const
{
	return type;
}
#endif
