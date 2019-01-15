//Class Pokemon.h
//This is the base class Pokemon
//Author: Yousif Dafalla
#ifndef Pokemon_H
#define Pokemon_H
#include <iostream>
class Pokemon
{
  public:
	virtual void PrintType() const = 0;
	virtual std::string getType() const = 0;
	std::string type;

  protected:
	std::string name;
	std::string size;
};

#endif
