// Mustafa Chowdhury, Final project, 12/02/2017
/* this program is made for a car dealership system where employer can show the inventory list, 
update the list based on their needs*/

#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<iomanip>
#include<string>
#include "CarType.h"
#include "newCar.h"
#include "oldCar.h"
#include<vector>
#include <fstream>

using namespace std;


void printHeading();
void priceRange(vector<CarType *> &object);// printing price in given range by user

void convert(string &s); // converting lowercase to uppercase

void addcar(vector<CarType *> &car);// adding car into the inventory
void catalogs(vector<CarType *> &object);// printing list of all type of car from the inventory
void leaseCarList(vector<CarType *> &object);// printing lease car inventory
void search(vector<CarType *> &object, string searchItem);// searching car from the inventory
void erase(vector <CarType *> &delete_object, vector<CarType *> &l_object);// delete car from the inventory
void returnCar(vector <CarType *> &object, vector <CarType *> &lease_object);// returnning lease car into the inventory and 
// converting categeory NEW to OLD and add mileage

void saveData(vector<CarType *> &object);


int main()
{


	cout << setprecision(2) << fixed << endl;

	newCar *new22;
	new22 = new newCar("12345", "TOYOTA", "CAMRY", 2012, 24000, "NEW", "MUSTAFA");

	oldCar *old1;
	old1 = new oldCar("10998", "FORD", "FUSION", 2012, 24000, "OLD", 20);

	oldCar *old2;
	old2 = new oldCar("11233", "HONDA", "ACCORD", 2017, 30000, "OLD", 2000);

	newCar *new2;
	new2 = new newCar("16987", "AUDI", "R8", 2017, 25000, "NEW", "SAYEM");

	oldCar *old3;
	old3 = new oldCar("11236", "NISSAN", "ALTIMA", 2017, 22000, "OLD", 12000);

	newCar * new3;
	new3 = new newCar("1X23A", "FORD", "EXPLORER", 2018, 35000, "NEW", "MUSA");

	oldCar *old4;
	old4 = new oldCar("Q93PV", "DODGE", "CHARGER", 2016, 15999, "OLD", 62985);


	vector<CarType*>cars;
	cars.push_back(new22);
	cars.push_back(old1);
	cars.push_back(old2);
	cars.push_back(new2);
	cars.push_back(old3);
	cars.push_back(new3);
	cars.push_back(old4);

	// creating a list for lease car;
	newCar *lease1;
	lease1 = new newCar(); // initializing using default constructor from class newCar

	vector<CarType *> leaseCar;
	leaseCar.push_back(lease1);
	leaseCar.pop_back();// empty list
	while (true)
	{
		try
		{
			int option;
			cout << " " << setw(45) << "              ------------ MENU ------------              " << endl;
			cout << "[1]-- Show Inventory\n[2]-- Search Inventory\n[3]-- Sell/Lease Cars\n[4]-- Return a leased car/see ctalogs";
			cout << "\n[5]-- Add cars to inventory\n[6]-- Searching by Price Range\n[7]-- Sava Data into File\n[8]-- Exit" << endl;
			cin >> option;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				throw string("exception!!");
			}
			cout << endl;
			string  m, MODEL, cat;
			switch (option)                                    // switch 1
			{
			case 1:
				cout << "Printing catalogs....." << endl;
				catalogs(cars);
				break;
			case 2:

				int options;
				cout << "Entering Search Inventoey....." << endl;
				cout << "\t(PRESS 1) Search By Make \n\t(PRESS 2) Search By Model \n\t(PRESS 3) Search By Categoty" << endl;
				cin >> options;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					throw string("exception!! Please enter a correct number");
				}
				switch (options)                         // switch 2
				{
				case 1:
					cout << "Enter the make: ";
					cin >> m;
					convert(m);
					search(cars, m);
					break;
				case 2:
					cout << "Enter the model: ";
					cin >> MODEL;
					convert(MODEL);
					search(cars, MODEL);
					break;
				case 3:
					cout << "Enter the Categeory: ";
					cin >> cat;
					convert(cat);
					search(cars, cat);
					break;
				default:
					cout << "Invalid Entry" << endl;
					break;
				} // end block for switch 2

				break;
				//catalogs(cars);

			case 3:
				erase(cars, leaseCar);

				break;
			case 4:
				//leaseCarList()
				leaseCarList(leaseCar);
				returnCar(cars, leaseCar);
				break;
			case 5:
				addcar(cars);
				//catalogs(cars);
				break;
			case 6:
				priceRange(cars);
				break;
			case 7:
				saveData(cars);
				break;
			case 8:
				cout << "Exiting......" << endl;
				return 0;
			default:
				cout << "Invalid Entry" << endl;
				break;

			}                                            // end switch 1
		} //end try
		catch (string str)
		{
			cout << str << endl;
			//break;
		}
		cout << endl;

	} //end block while loop

	delete old1, old2, old3, old4, new22, new2, new3, lease1; // deleting........ dynamic variables


	return 0;
}
#endif

void catalogs(vector<CarType *> &object)

{
	if (object.empty())
		cout << "There are no car in the inventory" << endl;
	else
	{
		cout << " " << setw(85) << "              ------------ Catalog ------------              " << endl << endl;
		printHeading();

		for (int i = 0; i < object.size(); i++)
		{

			object[i]->print();
			//cout << object[i];
		}
	}

}


void convert(string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
}


void printHeading()

{
	//cout << " " << setw(85) << "              ------------ Catalog ------------              " << endl << endl;
	cout << fixed << "VIN  " << setw(15)<<right << "Make" << setw(12) << "Model" << setw(12) << "Year" << setw(12) << "Price " << setw(16)
		<< " Category" << setw(20) << "     Warrenty Provider " << setw(12) << " Mileage " << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}






void addcar(vector<CarType *> &car)
{
	try
	{
		string vin, mak, mod, cata, provider;
		float prices;
		int year, mileage;
		cout << "Enter the VIN Number: ";
		cin >> vin;
		convert(vin);
		if (vin.length() != 5)
			throw string("VIN number should be 5 characters long.");
		else
		{
			for (int j = 0; j < car.size(); j++)
			{
				if (vin == car[j]->getVin())
					throw string("This vichele is already in the inventory.");
			}
		}
		cout << "Enter the Make: ";
		cin >> mak;
		convert(mak);
		cout << "Enter the model: ";
		cin >> mod;
		convert(mod);
		cout << "Enter the price: ";
		cin >> prices;
		if (prices < 2000)
			throw prices;
		cout << "Enter the year: ";
		cin >> year;
		if (year < 1998 || year>2020)
			throw year;
		cout << "Enter the Category New/OLD: ";
		cin >> cata;
		convert(cata);

		if (cata == "NEW")
		{
			cout << "Enter warrenty provider: ";
			cin >> provider;
			cout << endl;
			newCar *newCarObject;
			newCarObject = new newCar(vin, mak, mod, year, prices, cata, provider);
			car.push_back(newCarObject);

		}
		else if (cata == "OLD")
		{
			cout << "Enter odometer mileage: ";
			cin >> mileage;
			cout << endl;
			oldCar *oldCarObject;
			oldCarObject = new oldCar(vin, mak, mod, year, prices, cata, mileage);
			car.push_back(oldCarObject);
			catalogs(car);
		}
		else
			throw string("Input only NEW or OLD for the catageory");

	}
	catch (string str)
	{
		cout << str;
	}
	catch (float price)
	{
		cout << "The price of the car should be more than $5000" << endl;
	}
	catch (int YEAR)
	{
		cout << "Year: " << YEAR << " can't be added to the inventory, because\n";
		cout << "The car's year must be in between 1998 to 2020" << endl;
	}
	catch (...)
	{
		cout << "Invalid entry";
	}
	cout << endl;
}


void search(vector<CarType *> &object, string searchItem)
{
	//cout << " " << setw(85) << "              ------------ Catalog ------------              " << endl << endl;
	printHeading();
	bool found = false;
	for (int i = 0; i < object.size(); i++)
	{

		if (searchItem == object[i]->getMake() || searchItem == object[i]->getModel() || searchItem == object[i]->getCat())
		{
			object[i]->print();
			found = true;
		}

	}
	if (found == false)
		cout << "This car doesn't exist in the inventory" << endl;
	cout << endl;

}

void erase(vector <CarType *> &delete_object, vector<CarType *> &l_object)
{
	try
	{
		int option;
		const string n = "NEW";
		const string o = "OLD";
		string vin;
		bool found = false;
		cout << "\t(Press 1): Sell Cars\n\t(Press 2): Lease Car" << endl;
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw string("exception!!");
		}
		switch (option)
		{
		case 1:
			catalogs(delete_object);
			cout << endl;
			cout << "Enter the VIN number of the car you want to sell: ";
			cin >> vin;
			convert(vin);
			if (vin.length() != 5)
				throw string("exception!! VIN number must be 5 characters long");

			for (int i = 0; i < delete_object.size(); i++)
			{

				if (vin == delete_object[i]->getVin())
				{
					delete_object.erase(delete_object.begin() + i);
					found = true;
				}
			}
			if (found == false)
				throw string("Exception!! VIN number doesn't match");
			cout << "The car is sold successfully" << endl;
			catalogs(delete_object);
	
			break;
		case 2:
			catalogs(delete_object);

			cout << endl;
			cout << "Enter the VIN number of the car you want to lease: ";
			cin >> vin;
			convert(vin);

			for (int i = 0; i < delete_object.size(); i++)
			{

				if (vin == delete_object[i]->getVin())
				{
					l_object.push_back(delete_object[i]);
					delete_object.erase(delete_object.begin() + i);
					found = true;
				}
			}
			if (found == false)
				throw string("EXCEPTION FOUND!!! This car doesn't exist in the inventory");


			cout << "The car is remove from the inventory\n The car is added into the lease list" << endl;
			catalogs(delete_object);
			cout << endl;
			break;
		default:
			cout << "Invalid Entry" << endl;
			break;
		}
	}
	catch (string str)
	{
		cout << str << endl;
	}
}

void returnCar(vector <CarType *> &object, vector<CarType *> &lease_object)
{
	try
	{
		string vin;
		int mileage;
		cout << endl;
		if (lease_object.empty())
			throw string("There are no cars in the lease list");
		else
		{
			cout << "Enter the VIN number of ther lease car that you want to put back in the inventory: ";
			cin >> vin;
			convert(vin);


			bool found = false;
			for (int i = 0; i < lease_object.size(); i++)
			{

				if (vin == lease_object[i]->getVin())
				{
					cout << "Enter the current odometer mileage: ";
					cin >> mileage;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
						throw string("Mileage should be numbers");
					}
					cout << "The car is added to the inventory succesfully..."<< endl;
					//object.push_back(lease_object[i]);


					oldCar *leaseCarObject;
					

					leaseCarObject = new oldCar(lease_object[i]->getVin(), lease_object[i]->getMake(), lease_object[i]->getModel(),
						lease_object[i]->getYear(), lease_object[i]->getPrice(), "OLD",
						mileage);
					cout << "Car is removed from the Lease car list..." << endl;
					object.push_back(leaseCarObject);
					found = true;
					lease_object.erase(lease_object.begin() + i);
				}

			}
			if (found == false)
				throw string("EXCEPTION FOUND!!! This car doesn't exist in the inventory");
		}
	}
	catch (string str)
	{
		cout << str << endl;
	}

	cout << endl;

	//catalogs(object);

}
void leaseCarList(vector<CarType *> &object)
{
	if (object.empty())
		cout << endl;
	else
	{	
		cout << " " << setw(80) << "              ------------ Lease Car List ------------              " << endl << endl;
		printHeading();
		for (int i = 0; i < object.size(); i++)
		{
			object[i]->print();
			//cout << *object[i];
		}
	}
}
void priceRange(vector<CarType *> &object)
{
	try
	{
		int lower, upper;
		cout << "Enter the price range (lower to upper): ";
		cin >> lower;
		cin >> upper;
		if (lower > upper)
			throw string("Input failure!! lower price is greater than upper price");
		bool found = false;
		printHeading();
		for (int i = 0; i < object.size(); i++)
		{
			if (lower <= object[i]->getPrice() && upper >= object[i]->getPrice())
			{
				object[i]->print();
				found = true;
			}
			else
				found = false;
		}
		if (found == false)
			throw string("There are no car's in the INVENTORY, in this price range");
	}

	catch (string str)
	{
		cout << str << endl;
	}

}


void saveData(vector<CarType *> &object)
{
	ofstream outfile;
	outfile.open("output.txt");
	for (int i = 0; i < object.size(); i++)
	{
		outfile << *object[i];
	}
	outfile.close();
	cout << "Data is saved into the file" << endl;
	cout << endl;
}