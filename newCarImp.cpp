#include "newCar.h"
#include <iostream>
#include <string>
#include<iomanip>



newCar::newCar()
{
	CarType::CarType();
	warrenty_provider = "NONE";
}
newCar::newCar(string vin, string ma, string mo, int y, float p, string cat, string w)
	:CarType(vin, ma, mo, y, p, cat)
{
	warrenty_provider = w;
}
/*
void newCar::setWarenty(string w)
{
	warrenty_provider = w;
}
*/
string newCar::getWarrenty_Provider()const
{
	return warrenty_provider;
}
void newCar::print()const

{

	CarType::print();
	cout << setprecision(2) << fixed;
	cout << fixed << left << setw(10) << "       " << getWarrenty_Provider() << endl;
}

