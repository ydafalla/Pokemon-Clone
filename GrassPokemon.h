//GrassPokemon.h
//This is a derived class from Pokemon.h

#ifndef GrassPokemon_H
#define GrassPokemon_H
class GrassPokemon:public Pokemon
{
	public:
		virtual void PrintType() const;
		
		
		
		
	private:
		string weapon;
	
	
};

void GrassPokemon::PrintType() const
{
	cout<<"GRASS POKEMON\n";
}

#endif
