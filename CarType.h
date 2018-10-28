#ifndef CARTYPE_H
#define CARTYPE_H

#include<string>

using namespace std;
class CarType
{
	friend ostream& operator<<(ostream& os_object, const CarType& car_object);
public:
	//void setVin(string vin);
	//void setMake(string ma);
	//void setModel(string mo);
	//void setYear(int y);
	//void setPrice(float p);
	//void setCat(string cat);
	virtual void print() const;
	string getVin()const;
	string getMake()const;
	string getModel()const;
	int getYear()const;
	float getPrice()const;
	string getCat()const;
	CarType(string vin, string ma, string mo, int y, float p, string cat);
	CarType();
private:
	string VIN;
	string make;
	string model;
	int year;
	float price;
	string category;

};

#endif

