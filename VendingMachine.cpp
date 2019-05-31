//FUNCTION FILE:

#include <iostream>
#include "vendingMachine.h"
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int MAX_PRODUCTS = 30;

void readProducts(ifstream &indata, Products products[])
{
	int total = 0;
	int ID, quant, price;
	string desc;
	while (!indata.eof())
	{
		indata >> ID >> quant >> price;
		getline(indata, desc);
		products[total].setPID(ID);
		products[total].setPQuantity(quant);
		products[total].setPPrice(price);
		products[total].setPDescription(desc);
		total++;
	}

}
void readProductC(ifstream &indata, Products products[])
{
	int total = 0;
	int ID, quant, price;
	string desc;
	while (!indata.eof())
	{
		indata >> ID >> quant >> price;
		getline(indata, desc);
		products[total].setPID(ID);
		products[total].setPQuantity(quant);
		products[total].setPPrice(price);
		products[total].setPDescription(desc);
		total++;
	}

}


VendingMachine::VendingMachine(int q, int d, int n)
{
	quarter = q;
	dime = d;
	nickel = n;
}
int VendingMachine::getQuarter()
{
	return quarter;
}
int VendingMachine::getNickel()
{
	return nickel;
}
int VendingMachine::getQuantity()
{
	return quant;
}
int VendingMachine::getVID()
{
	return ID;
}
int VendingMachine::getnumItems()
{
	return numItems;
}
string VendingMachine::getVSelection()
{
	return selection_ven;
}
int VendingMachine::getDime()
{
	return dime;
}
void VendingMachine::setQuarter(int q)
{
	quarter = q;
}
void VendingMachine::setnumItems(int i)
{
	numItems = i;
}
void VendingMachine::setDime(int d)
{
	dime = d;
}
void VendingMachine::setNickel(int n)
{
	nickel = n;
}
void VendingMachine::setVQuantity(int a)
{
	quant = a;
}
void VendingMachine::setVID(int b)
{
	ID = b;
}
void VendingMachine::setVSelection(string x)
{
	selection_ven = x;
}

Products::Products(int i, int q, int p, string s, string d)
{
	ID = i;
	quant = q;
	price = p;
	selection = s;
	desc = d;
}
void Products::setPID(int i)
{
	ID = i;
}
void Products::setPQuantity(int q)
{
	quant = q;
}
void Products::setPPrice(int p)
{
	price = p;
}
void Products::setPDescription(string d)
{
	desc = d;
}
void Products::setPSelection(string s)
{
	selection = s;
}
int Products::getPID()
{
	return ID;
}
int Products::getPQuantity()
{
	return quant;
}
int Products::getPPrice()
{
	return price;
}
string Products::getPDescription()
{
	return desc;
}

string Products::getPSelection()
{
	return selection;
}
MachineC::MachineC(string card)
{
}
void MachineC::printInfo()
{
	cout << "This machine accepts credit card only.\n";
	cout << "Avaliable items: \n";

}

void MachineC::lastFour(string card)
{
	//get last 4 digits for output report
	//wrong
	string temp = "	";

	if (checkCard(card))
	{
		for (int i = card.length() - 4; i <= card.length(); i++)
		{
			temp = card[i];
			cout << temp;
		}
	}
	else
	{

	}
}

void MachineC::purchase(string card)
{
	for (int i = 1; i <= 2; i++)
	{
		cout << "Enter your credit card number --> ";
		cin >> card;

		if (checkCard(card))
		{
			cout << "You credit card was successfully charged for $" << Products[total].getPPrice() << endl;
			// need to get price from the machine and change to dollars;

			cout << "Thank you! Please Take your item.\n";
			break;
		}
		else if (i == 1)
		{
			cout << "Invalid credit card number was entered.\n";
		}
		//Two invalid attempts will cancel item
		else if (i == 2)
		{
			cout << "Item has been canceled.\n";
		}
	}
}

bool MachineC::checkCard(string card)
{
	int num = card.length();

	bool isSecond = false;

	if (card.length() <= 16 && card.length() >= 13)
	{
		if (card[0] == '4' || card[0] == '5' || card[0] == '6')
		{
			int sum = 0;

			for (int i = num - 1; i >= 0; i--)
			{
				int x = card[i] - '0';

				if (isSecond == true)
					x *= 2;

				sum += x / 10;
				sum += x % 10;
				isSecond = !isSecond;
			}
			isSecond = (sum % 10 == 0) ? true : false;
			return isSecond;
		}

		else if (card[0] == '3' && card[1] == '7')
		{
			int sum = 0, isSecond = false;

			for (int i = num - 1; i >= 0; i--)
			{
				int x = card[i] - '0';

				if (isSecond == true)
					x *= 2;

				sum += x / 10;
				sum += x % 10;
				isSecond = !isSecond;
			}
			isSecond = (sum % 10 == 0) ? true : false;
			return isSecond;
		}
		else
			return isSecond;
	}

	else
	{
		return isSecond;
	}
}

void MachineC::print(string card)
{
	if (checkCard(card))
	{
		cout << "You credit card was successfully charged for $" << endl;
		cout << "Thank you! Please that your item.\n";
	}
	else
	{
		cout << "Invalid credit card number was entered.\n";
	}
}
//MachineC::MachineC(string c)
//{
//    card = c;
//}
//
//string MachineC::returnCard()
//{
//    return card;
//}
/*void Products::subProductAmount(int x)
{
if (x <= quant)
{
quant -= x;
}
}
*/

void readmachineA(ifstream &indata, Machine100A machineA[], Products products[])
{
	int total = 0;
	int quarter, dime, nickel;
	int ID, quant, numofmachines, numofitems;
	string model, selection;
	indata >> model >> numofmachines;
	while (!indata.eof())
	{
		indata >> quarter >> dime >> nickel >> numofitems;
		machineA[total].setQuarter(quarter);
		machineA[total].setDime(dime);
		machineA[total].setNickel(nickel);
		machineA[total].setnumItems(numofitems);
		int temp = numofmachines;
		for (int i = 0; i < numofitems; i++)
		{
			indata >> selection >> ID >> quant;
			for (int k = 0; k < MAX_PRODUCTS; k++)
			{
				if (ID == products[k].getPID())
				{
					machineA[total].Products[i].setPID(ID);
					machineA[total].Products[i].setPSelection(selection);
					machineA[total].Products[i].setPQuantity(quant);
					products[k].setPQuantity(products[k].getPQuantity() - quant);
					machineA[total].Products[i].setPPrice(products[k].getPPrice());
					machineA[total].Products[i].setPDescription(products[k].getPDescription());
				}
			}
		}
		total++;
	}
}

void readmachineC(ifstream & indata, MachineC machineC[], Products products[])
{
	int total = 0;
	int quarter, dime, nickel;
	int ID, quant, numofmachines, numofitems;
	string model, selection;
	indata >> model >> numofmachines;
	while (!indata.eof())
	{
		indata >> quarter >> dime >> nickel >> numofitems;
		machineC[total].setQuarter(quarter);
		machineC[total].setDime(dime);
		machineC[total].setNickel(nickel);
		machineC[total].setnumItems(numofitems);
		int temp = numofmachines;
		for (int i = 0; i < numofitems; i++)
		{
			indata >> selection >> ID >> quant;
			for (int k = 0; k < MAX_PRODUCTS; k++)
			{
				if (ID == products[k].getPID())
				{
					machineC[total].Products[i].setPID(ID);
					machineC[total].Products[i].setPSelection(selection);
					machineC[total].Products[i].setPQuantity(quant);
					products[k].setPQuantity(products[k].getPQuantity() - quant);
					machineC[total].Products[i].setPPrice(products[k].getPPrice());
					machineC[total].Products[i].setPDescription(products[k].getPDescription());
				}
			}
		}
		total++;
	}
}




