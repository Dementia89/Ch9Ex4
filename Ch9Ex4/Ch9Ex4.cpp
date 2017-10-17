// Ch9Ex4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

struct menuItemType
{
	string menuItem;
	double menuPrice;
};

void ShowMenu();
void GetData();
void PrintCheck(double& total);
void GetOrder(int order, double& total);

menuItemType menuList[8];
//{ { "Plain Egg", 1.45 },
//{ "Bacon and Egg", 2.45 },
//{ "Muffin", 0.99 },
//{ "French Toast", 1.99 },
//{ "Fruit Basket", 2.49 },
//{ "Cereal", 0.69 },
//{ "Coffee", 0.50 },
//{ "Tea", 0.75 } }
list<menuItemType> currentOrder;

int main()
{
	double total = 0;
	int order = -1;

	cout << fixed << setprecision(2);

	GetData();

	ShowMenu();

	while (order != 0)
	{
		cout << "Current Total: $" << total;
		cout << endl << "Enter Order: ";
		cin >> order;
		GetOrder(order, total);
	}

	cin.ignore();
	cin.get();

    return 0;
}

// Display the menu
void ShowMenu()
{
	cout << "Welcome to Holton's restaurant.";
	for (int i = 0; i < 8; i++)
	{
		cout << endl;
		cout << setw(3) << i + 1 << "." << setw(20) << left << menuList[i].menuItem << "$" << menuList[i].menuPrice << ".";
	}
	//Blah
	cout << endl << "0. Print Order and Exit.";
}

// Load data into menu.
void GetData()
{
	menuList[0].menuItem = "Plain Egg";
	menuList[0].menuPrice = 1.45;

	menuList[1].menuItem = "Bacon and Egg";
	menuList[1].menuPrice = 2.45;

	menuList[2].menuItem = "Muffin";
	menuList[2].menuPrice = 0.99;

	menuList[3].menuItem = "French Toast";
	menuList[3].menuPrice = 1.99;

	menuList[4].menuItem = "Fruit Basket";
	menuList[4].menuPrice = 2.49;

	menuList[5].menuItem = "Cereal";
	menuList[5].menuPrice = 0.69;

	menuList[6].menuItem = "Coffee";
	menuList[6].menuPrice = 0.50;

	menuList[7].menuItem = "Tea";
	menuList[7].menuPrice = 0.75;
}

// Print Current Check
void PrintCheck(double& total)
{
	cout << endl << "Thank you for eating at Holton's Restaurant!" << endl << "Your order:" << endl;
	for (menuItemType i : currentOrder)
	{
		cout << endl;
		cout << setw(20) << left << i.menuItem << "$" << i.menuPrice;
	}

	cout << endl << setw(20) << left << "Tax" << "$" << total * 0.06;
	cout << endl << setw(20) << left << "Total Today" << "$" << total * 1.06;
}

void GetOrder(int order, double& total)
{
	switch (order)
	{
	case 1:
		currentOrder.push_back(menuList[0]);
		total += menuList[0].menuPrice;
		break;
	case 2:
		currentOrder.push_back(menuList[1]);
		total += menuList[1].menuPrice;
		break;
	case 3:
		currentOrder.push_back(menuList[2]);
		total += menuList[2].menuPrice;
		break;
	case 4:
		currentOrder.push_back(menuList[3]);
		total += menuList[3].menuPrice;
		break;
	case 5:
		currentOrder.push_back(menuList[4]);
		total += menuList[4].menuPrice;
		break;
	case 6:
		currentOrder.push_back(menuList[5]);
		total += menuList[5].menuPrice;
		break;
	case 7:
		currentOrder.push_back(menuList[6]);
		total += menuList[6].menuPrice;
		break;
	case 8:
		currentOrder.push_back(menuList[7]);
		total += menuList[7].menuPrice;
		break;
	case 0:
		PrintCheck(total);
		break;
	}
}