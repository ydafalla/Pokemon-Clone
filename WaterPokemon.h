//WaterPokemon.h
//This is a derived class from Pokemon

#ifndef WaterPokemon_H
#define WaterPokemon_H
class WaterPokemon:public Pokemon
{
	public:
		virtual void PrintType() const;
		
		
		
	private:
		string weapon;

	
};

void WaterPokemon::PrintType() const
{
	cout<<"WATER POKEMON\n";
}

#endif
