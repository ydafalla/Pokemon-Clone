//Class Pokemon.h
//This is the base class Pokemon
//Author: Yousif Dafalla
#ifndef Pokemon_H
#define Pokemon_H
class Pokemon
{
	public:
		virtual void PrintType() const=0;
		
		
		
	protected:
		string name;
		string size;
		string color;
	
	
	
};

#endif
