#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;


int main ()
	{
	string items[30][6];
	string storage[30][4];
	string line;
	
	//variables in machines.txt
	string model;
	int numMachines;
	int q, n, d;
	int numItems;

	//variables in products.txt
	string ID;
	string quantity;
	string price;
	string desc;


	ifstream infile;
	infile.open("E:\\CSCI_140\\VendingMachine\\machines.txt");
	if (!infile)
	{
		cout << "no file" << endl;
	}
	else
	{
		infile >> model >> numMachines;
		infile >> q >> d >> n;
		infile >> numItems;

		for (int i = 0;i < numItems;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				infile >> items[i][j];
			}
		}

		ifstream product;
		product.open("E:\\CSCI_140\\VendingMachine\\products.txt");
		if (!product)
		{
			cout << "no file" << endl;
		}
		else
		{
			
			for (int i = 0;i < 23;i++)
			{
				getline(product, line);
				int start=0;
				int end=0;
				while (line[end] != ' ')
				{
					end++;
				}
				ID = line.substr(start, end-start);

				while (line[end] == ' ')
				{
					end++;
				}
				start = end;
				while (line[end] != ' ')
				{
					end++;
				}
				quantity = line.substr(start, end-start);

				while (line[end] == ' ')
				{
					end++;
				}
				start = end;
				while (line[end] != ' ')
				{
					end++;
				}
				price = line.substr(start, end-start);

				while (line[end] == ' ')
				{
					end++;
				}
				start = end;
				end = line.length();
				desc = line.substr(start, end);

				storage[i][0] = ID;
				storage[i][1] = quantity;
				storage[i][2] = price;
				storage[i][3] = desc;
			}

			for (int i = 0;i < 23;i++)
			{
				for (int j = 0;j < 4;j++)
				{
					cout <<setw(0)<< storage[i][j]<<" ";
				}
				cout << endl;
			}


		}
	}


	system("pause");
	return 0;
	}
