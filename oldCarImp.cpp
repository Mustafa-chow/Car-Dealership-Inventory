#include "oldCar.h"
#include<iostream>
#include <iomanip>

oldCar::oldCar()
{
	CarType::CarType();
	mileage = 0;
}
/*
void oldCar::setMileage(int mil)
{
	mileage = mil;
}
*/
int oldCar::getMileage()const
{

	return mileage;
}
void oldCar::print()const

{

	CarType::print();
	cout << fixed << "                             " << setw(10) << setfill('0') << setw(6) << mileage << setfill(' ') << endl;
}
oldCar::oldCar(string vin, string ma, string mo, int y, float p, string cat, int mil)
	:CarType(vin, ma, mo, y, p, cat)

{
	mileage = mil;
}
