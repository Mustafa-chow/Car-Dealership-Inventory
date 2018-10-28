#include "CarType.h"
#include <string>
#include<iostream>
#include <iomanip>
#include <vector>


CarType::CarType()
{
	VIN = "";
	make = "";
	model = "";
	category = "";
	year = 1990;
	price = 0.0;
}

CarType::CarType(string vin, string ma, string mo, int y, float p, string cat)
{
	VIN = vin;
	make = ma;
	model = mo;
	if (p > 2000 && p < 100000)
		price = p;
	else
		price = 2000;
	if (y>2000 && y < 2020)
		year = y;
	else
		year = 2000;
	category = cat;
}
/*
void CarType::setVin(string vin)
{
	VIN = vin;
}
void CarType::setMake(string ma)
{
	make = ma;
}
void CarType::setModel(string mo)
{
	model = mo;
}
void CarType::setYear(int y)
{
	year = y;
}
void CarType::setPrice(float p)
{
	price = p;
}
void CarType::setCat(string cat)
{
	category = cat;
}
*/
string CarType::getVin()const
{
	return VIN;
}
string CarType::getMake()const
{
	return make;
}
string CarType::getModel()const
{
	return model;
}
int CarType::getYear()const
{
	return year;
}
float CarType::getPrice()const
{
	return price;
}
string CarType::getCat()const
{
	return category;
}
void CarType::print() const
{

	cout << left << getVin() << setw(15) << right << getMake() << setw(12) << right << getModel() << setw(12) << right << getYear()
		<< setw(6) << right << "$" << getPrice() << setw(12) << right << getCat();
}

ostream& operator<<(ostream& os_object, const CarType &car_object)
{
	os_object <<left<< car_object.VIN << setw(15)<<right << car_object.make << setw(12)<<right << car_object.model << setw(12) << car_object.year
		<< setw(6)<<right << "$" << car_object.price << setw(12) << car_object.category << endl;
	return os_object;
}