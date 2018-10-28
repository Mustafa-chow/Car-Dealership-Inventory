#include<string>
#include "CarType.h"


#ifndef OLDCAR_H
#define OLDCAR_H

class oldCar :public CarType
{
public:
	oldCar();
	//void setMileage(int mil);
	int getMileage()const;
	void print()const;
	oldCar(string vin, string ma, string mo, int y, float p, string cat, int mil);
private:
	int mileage;
};
#endif

