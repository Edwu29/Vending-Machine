#pragma once
//Header FILE:
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Products
{
	//protected
private:
	int ID;
	int quant;
	int price;
	string selection;
	string desc;

public:
	Products(int i = 0, int q = 0, int p = 0, string s = "", string d = "");
	void setPID(int);
	void setPQuantity(int);
	void setPPrice(int);
	void setPDescription(string);
	void setPSelection(string);
	int getPID();
	int getPQuantity();
	int getPPrice();
	string getPDescription();
	string getPSelection();
};
class VendingMachine
{
protected:
	string selection_ven;
	int quarter;
	int nickel;
	int dime;
	int ID;
	int quant;
	int numItems;
public:
	Products Products[10];
	VendingMachine(int q = 0, int d = 0, int n = 0);
	int getQuarter();
	int getDime();
	int getNickel();
	int getQuantity();
	int getVID();
	int getnumItems();
	string getVSelection();
	void setQuarter(int);
	void setnumItems(int);
	void setDime(int);
	void setNickel(int);
	void setVQuantity(int);
	void setVID(int);
	void setVSelection(string);

};
class Machine100A : public VendingMachine
{
private:

	int dollar;
public:

};
class MachineC : public VendingMachine
{
private:
	string card;
	int total = 0;

public:
	//Products products[10];
	MachineC(string c = "0000000000000");
	string returnCard();
	void printInfo();
	void lastFour(string card);
	void purchase(string card);
	bool checkCard(string card);
	void print(string card);

};

