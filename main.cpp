#pragma once

// MAIN FILE

#include <iostream>
#include <fstream>
#include "vendingMachine.h"
#include <iomanip>
#include <string>
using namespace std;
const int MAX_PRODUCTS = 30;
const int MAX_MACHINES = 30;
void readProducts(ifstream&, Products[]);
void readmachineA(ifstream &indata, Machine100A machineA[], Products products[]);
void readmachineC(ifstream &indata, MachineC machineC[], Products products[]);
void readProductC(ifstream&, Products[]);

void machineChange(Machine100A[], int, int, int);


//int machineSize(T machine[], int n)
//{
//    int count = 0;
//    for (int i = 0; i < MAX_PRODUCTS; i++)
//    {
//   	 if (machine[n].Products[i].getPID() == 0)
//   	 {
//   		 count = i;
//   		 break;
//   	 }
//    }
//    return count;
//}

int main()
{

	ifstream machine_file;
	ifstream machine_Cfile;
	ifstream products_file;

	ofstream result;
	string startCode;
	string machineCode;
	string model;

	Machine100A machineA[MAX_MACHINES];
	Products products[MAX_PRODUCTS];
	Products productC[MAX_PRODUCTS];

	// Machine C stuff
	MachineC machineC[MAX_MACHINES];
	string cardNum;
	string machine;
	string item;
	MachineC call;
	machine_file.open("E:\\CSCI_140\\VendingMachine\\testMachineA.txt");
	machine_Cfile.open("E:\\CSCI_140\\VendingMachine\\machines.txt");

	products_file.open("E:\\CSCI_140\\VendingMachine\\products.txt");
	result.open("E:\\CSCI_140\\VendingMachine\\results.txt");

	if (!machine_file)
	{
		cout << "Machines.txt not found." << endl;
		system("Pause");
		return 1;
	}
	if (!products_file)
	{
		cout << "products.txt not found." << endl;
		system("Pause");
		return 1;
	}
	//cout << "Please enter a startup code --> ";
	//cin >> startCode;
	//while (startCode != "csci140")
	//{
	//    cout << "Machine not found. " << endl;
	//    cout << "Please enter another startup code --> ";
	//    cin >> startCode;
	//}

	int total = 0;

	cout << "Please enter a startup code --> ";
	cin >> startCode;
	while (startCode != "csci140")
	{
		cout << "Machine not found. " << endl;
		cout << "Please enter another startup code --> ";
		cin >> startCode;
	}
	//readmachineC(machine_Cfile, machineC, productC);
	readProducts(products_file, products);
	readProductC(products_file, productC);
	readmachineA(machine_file, machineA, products);

	cout << "Initializing machines. Please wait. . ." << endl;
	cout << "Machines are ready." << endl;
	cout << "Available machines: 100A1 100A2, 100C1, 100C2" << endl << endl;
	cout << "Select a machine --> ";
	cin >> machineCode;

	while (machineCode != "csci140")
	{

		if (machineCode == "100A1")
		{

			string input;
			int price;
			int sentinel;

			cout << "This machine accepts one-dollar bill only." << endl;
			cout << "Available items: " << endl;
			for (int i = 0; i < machineA[0].getnumItems(); i++)
			{
				cout << setw(5) << machineA[0].Products[i].getPSelection() << " " << machineA[0].Products[i].getPPrice() << machineA[0].Products[i].getPDescription() << endl;
			}
			cout << "Select an item --> ";
			cin >> item;
			for (int i = 0; i < machineA[0].getnumItems(); i++)
			{
				if (machineA[0].Products[i].getPSelection() == item)
				{
					int temp;
					cout << "You selected : " << machineA[0].Products[i].getPDescription() << endl;
					cout << "The cost of this item is " << machineA[0].Products[i].getPPrice() << " cents" << endl;
					cout << "Insert your money --> ";
					cin >> price >> sentinel;
					if (price == 0)
					{
						cout << "You chose to cancel your selection\n";
						break;
					}
					cout << "Your entered an amount of " << price << " cents." << endl;
					cout << "Processing your purchase. . . " << endl;
					temp = price - machineA[0].Products[i].getPPrice();

					machineChange(machineA, price - machineA[0].Products[i].getPPrice(), price, temp);

				}
			}
		}
		if (machineCode == "100C1")
		{
			int i = 19;
			int numofitems = 3;
			string input;

			call.printInfo();

			for (int k = 0; k < numofitems; k++)
			{
				cout << setw(5) << machineA[0].Products[k].getPSelection() << " " << products[i].getPPrice() << products[i].getPDescription() << endl;
				i++;
			}
			int num = 0;
			cout << "Select an item --> ";
			cin >> item;
			if (item == machineA[0].Products[0].getPSelection())
			{

				cout << "You selected " << products[19].getPDescription() << endl;
				cout << "The cost of this item is " << products[19].getPPrice() << " cents\n";
			}
			else if (item == machineA[0].Products[1].getPSelection())
			{
				cout << "You selected " << products[20].getPDescription() << endl;
				cout << "The cost of this item is " << products[20].getPPrice() << " cents\n";
			}
			else if (item == machineA[0].Products[2].getPSelection())
			{
				cout << "You selected " << products[21].getPDescription() << endl;
				cout << "The cost of this item is " << products[21].getPPrice() << " cents\n";

			}
			call.purchase(cardNum);
			call.checkCard(cardNum);
			call.lastFour(cardNum);
			call.print(cardNum);


		}
		cout << "Select a machine --> ";
		cin >> machineCode;
	}
	cout << "Report is generating ...\n";
	cout << "System is shutting down.\n";

	system("Pause");
	return 0;
}

void machineChange(Machine100A machine[], int n, int price, int change)
{
	int quarter = machine[0].getQuarter();
	int dime = machine[0].getDime();
	int nickel = machine[0].getNickel();
	int changeQuarter = 0;
	int changeDime = 0;
	int changeNickel = 0;

	while (n != 0)
	{

		if (quarter > 0 && n >= 25)
		{
			changeQuarter++;
			quarter--;
			machine[0].setQuarter(quarter);
			n = n - 25;
		}
		else if (dime > 0 && n >= 10)
		{
			changeDime++;
			dime--;
			machine[0].setDime(dime);
			n = n - 10;
		}
		else if (nickel > 0 && n >= 5)
		{
			changeNickel++;
			nickel--;
			machine[0].setNickel(nickel);
			n = n - 5;
		}
		else if (changeQuarter == 0 || changeDime == 3 || changeNickel == 3)
		{
			cout << "insufficient changes! " << endl;
			cout << "your transaction cannot be processed " << endl;
			cout << "please take back your dollar bill." << endl;
			machine[0].setQuarter(changeQuarter + quarter);
			machine[0].setDime(changeDime + dime);
			machine[0].setNickel(nickel + changeNickel);

			n = 0;
		}
	}

	cout << "Your change of " << change << " is given by " << endl;
	cout << setw(4) << "Quarter(s) : " << changeQuarter << endl;
	cout << setw(4) << "Dime(s) : " << changeDime << endl;
	cout << setw(4) << "Nickel(s) : " << changeNickel << endl;

}




