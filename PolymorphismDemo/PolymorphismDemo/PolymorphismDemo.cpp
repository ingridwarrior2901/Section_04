// PolymorphismDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// 1. ad-hoc polymorphism (overloading)
int GetSize(int x)
{
	return x;
}

int GetSize(std::string x)
{
	return x.length();
}

// 2. subtype polymorphism (AKA runtime polymorphism)
class Animal
{
public:
	virtual void MakeNoise()
	{
		std::cout << "???" << std::endl;
	}
};

// subclass
class Doggo : public Animal
{
public:
	/*
	override is not really necessary but added here
	illustrate its usage under normal circumstances
	*/
	void MakeNoise() override
	{
		std::cout << "aawooo!" << std::endl;
	}
};

// subclass
class Kitteh : public Animal
{
public:
	void MakeNoise() override
	{
		std::cout << "peep!" << std::endl;
	}
};

// must use pointer or reference to work or else animal that is passed in
// will be a direct copy of Animal and not include the inherited method for Pet()
void Pet(Animal* animal)
{
	animal->MakeNoise();
}

int main()
{
	std::cout << GetSize(5) << std::endl;
	std::cout << GetSize("Hello World") << std::endl;

	Doggo goodboye;
	Kitteh peepers;
	Pet(&goodboye);
	Pet(&peepers);

    return 0;
}

