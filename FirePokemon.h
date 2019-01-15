//FirePokemon.h
//This is a fire pokemon class

#ifndef FirePokemon_H
#define FirePokemon_H

class FirePokemon:public Pokemon
{
	public:
		virtual void PrintType() const;
		
		
		
	private:
		string weapon;
	
	
};

void FirePokemon::PrintType() const
{
	cout<<"FIRE POKEMON\n";
}

#endif
