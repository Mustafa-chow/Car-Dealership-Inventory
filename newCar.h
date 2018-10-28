#include<string>
#include "CarType.h"

#ifndef NEWCAR_H
#define NEWCAR_H

class newCar :public CarType
{
public:
	newCar();
	//void setWarenty(string w);
	string getWarrenty_Provider()const;
	void print()const;
	newCar(string vin, string ma, string mo, int y, float p, string cat, string w);
private:
	string warrenty_provider;
};
#endif

