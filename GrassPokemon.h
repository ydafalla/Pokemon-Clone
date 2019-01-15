//GrassPokemon.h
//This is a derived class from Pokemon.h

#ifndef GrassPokemon_H
#define GrassPokemon_H
#include "Pokemon.h"
class GrassPokemon : public Pokemon
{
  public:
	GrassPokemon();
	virtual void PrintType() const;
	virtual std::string getType() const;

  private:
	std::string weapon;
};
GrassPokemon::GrassPokemon()
{
	type = "Grass";
}

void GrassPokemon::PrintType() const
{
	std::cout << "GRASS POKEMON\n";
}

std::string GrassPokemon::getType() const
{
	return type;
}

#endif
