#include "VendinMachine.h"
float totalAmount;

float getTotalamount() {
	return totalAmount;
}
void setTotalamount(float amt) {
	totalAmount = amt;
}
void VendinMachine::displayMenu()
{
	int number = 0;
	std::cout << "Welcome to the UB Vending Machine \n";
	std::cout << "Enter the number of coins you wish to insert:";
	std::cin >> number;
	setCoins(number);
	
}

void VendinMachine::setCoins(int number)
{
	this->number_of_coins = number;
	setAmountInserted(this->number_of_coins);
}
void VendinMachine::setAmountInserted(float coins)
{
	this->amountInserted = coins*0.05;
	setTotalamount(getamountInserted());
	displayAmountInserted();
}

void VendinMachine::displayAmountInserted()
{
	std::cout << "You Inserted "<< getamountInserted() <<" dollars\n";
	displayMainMenu();
}

void VendinMachine::displayMainMenu()
{
	int selectedChoice = 0;
	std::cout << "--------------------------------------------- \n";
	std::cout << "Main Menu \n";
	std::cout << "--------------------------------------------- \n";
	std::cout << "[1] Drinks \n";
	std::cout << "[2] Snacks \n";
	std::cout << "[3] Exit \n";
	std::cout << "Select an option <3 to exit>: ";
	std::cin >> selectedChoice;

	checkSelection(selectedChoice);
}

void VendinMachine::checkSelection(int selectedChoice)
{
	if (selectedChoice > 3) {
		displayErroronCoice();
	}
	else if(selectedChoice==3){
		displayMenu();
	}
	else {
		switch (selectedChoice)
		{
		case 1:
			VendinMachine::initDrinkDispenser();
			break;
		case 2:
			VendinMachine::initSnacksDispenser();
			break;
		default:
			break;
		}
	}
}
void VendinMachine::displayErroronCoice()
{
	std::cout << "There is no selection for the Optoin you entered \n";
	displayMainMenu();
}

void VendinMachine::initDrinkDispenser()
{
	Drinks d;
	d.displayDrinksMenu();
}

void VendinMachine::initSnacksDispenser()
{
	Snacks s;
	s.displaySnacksMenu();
}

float VendinMachine::getamountInserted()
{
	return this->amountInserted;
}

/*--------------------Drinks--------------------*/
void Drinks::displayDrinksMenu()
{
	char option=' ';
	std::cout << "--------------------------------------------- \n";
	std::cout << "Drinks Menu \n";
	std::cout << "--------------------------------------------- \n";
	std::cout << "[W] Water \n";
	std::cout << "[J] Juice \n";
	std::cout << "[S] Soda \n";
	std::cout << "Select a drink by enterin the character in the brackets <X to exit to main menu> \n ";
	std::cout << "Drinks Option: ";
	std::cin >> option;
	if (option == 'X' || option == 'x') { 
		displayMainMenu();
	}
	else {
		checkDrinkSelection(option);
	}
}

void Drinks::checkDrinkSelection(char option)
{
	switch (option)
	{
	case 'W':
		if (checkDispenseWater()) {
			std::cout << "Vendin Water, you have "<< getTotalamount()<<" dollars left\n";
			Drinks::displayDrinksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Water <" << getTotalamount() << " < " <<Drinks::getWater()<<"> \n" ;
			Drinks::displayDrinksMenu();
		}
		break;
	case 'J':
		if (checkDispenseJuice()) {
			std::cout << "Vendin Juice, you have " << getTotalamount() << " dollars left\n";
			Drinks::displayDrinksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Juice <" << getTotalamount() << " < " << Drinks::getJuice() << "> \n";
			Drinks::displayDrinksMenu();
		}		
		break;
	case 'S':
		if (checkDispenseSoda()) {
			std::cout << "Vendin Soda, you have " << getTotalamount() << " dollars left\n";
			Drinks::displayDrinksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Soda <" << getTotalamount() << " < " << Drinks::getSoda() << "> \n";
			Drinks::displayDrinksMenu();
		}		
		break;

	case 'w':
		if (checkDispenseWater()) {
			std::cout << "Vendin Water, you have " << getTotalamount() << " dollars left\n";
			Drinks::displayDrinksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Water <" << getTotalamount() << " < " << Drinks::getWater() << "> \n";
			Drinks::displayDrinksMenu();
		}		break;
	case 'j':
		if (checkDispenseJuice()) {
			std::cout << "Vendin Juice, you have " << getTotalamount() << " dollars left\n";
			Drinks::displayDrinksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Juice <" << getTotalamount() << " < " << Drinks::getJuice() << "> \n";
			Drinks::displayDrinksMenu();
		}		
		break;
	case 's':
		if (checkDispenseSoda()) {
			std::cout << "Vendin Soda, you have " << getTotalamount() << " dollars left \n";
			Drinks::displayDrinksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Soda <" << getTotalamount() << " < " << Drinks::getSoda() << "> \n";
			Drinks::displayDrinksMenu();
		}				
		break;
	default:
		break;
	}
}

bool Drinks::checkDispenseWater()
{
	float amountRemainin= getTotalamount();
	if (amountRemainin >=Drinks::getWater()) {
		float newBalance = amountRemainin - Drinks::getWater();
		setTotalamount(newBalance);
		return true;
	}
	else {
		return false;
	}
}

bool Drinks::checkDispenseJuice()
{
	float amountRemainin = getTotalamount();
	if (amountRemainin >= Drinks::getJuice()) {
		float newBalance = amountRemainin - Drinks::getJuice();
		setTotalamount(newBalance);
		return true;
	}
	else {
		return false;
	}
}

bool Drinks::checkDispenseSoda()
{
	float amountRemainin = getTotalamount();
	if (amountRemainin >= Drinks::getSoda()) {
		float newBalance = amountRemainin - Drinks::getSoda();
		setTotalamount(newBalance);
		return true;
	}
	else {
		return false;
	}
}

/*--------------------Snacks--------------------*/
void Snacks::displaySnacksMenu()
{
	char option = ' ';
	std::cout << "--------------------------------------------- \n";
	std::cout << "Snacks Menu \n";
	std::cout << "--------------------------------------------- \n";
	std::cout << "[C] Chips \n";
	std::cout << "[P] Peanuts \n";
	std::cout << "[G] Gum \n";
	std::cout << "Select a Snack by enterin the character in the brackets <X to exit to main menu> \n ";
	std::cout << "Drinks Option: ";
	std::cin >> option;
	if (option == 'X' || option == 'x') {
		displayMainMenu();
	}
	else {
		checkSnackSelection(option);
	}
}

void Snacks::checkSnackSelection(char option)
{
	switch (option)
	{
	case 'C':
		if (checkDispenseChips()) {
			std::cout << "Vendin Chips, you have " << getTotalamount() << " dollars left\n";
			Snacks::displaySnacksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Chips <" << getTotalamount() << " < " << Snacks::getChips() << "> \n";
			Snacks::displaySnacksMenu();
		}
		break;
	case 'P':
		if (checkDispensePeanuts()) {
			std::cout << "Vendin Peanuts, you have " << getTotalamount() << " dollars left\n";
			Snacks::displaySnacksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Peanuts <" << getTotalamount() << " < " << Snacks::getPeanuts() << "> \n";
			Snacks::displaySnacksMenu();
		}
		break;
	case 'G':
		if (checkDispenseGum()) {
			std::cout << "Vendin Gum, you have " << getTotalamount() << " dollars left \n";
			Snacks::displaySnacksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Gum <" << getTotalamount() << " < " << Snacks::getGum() << "> \n";
			Snacks::displaySnacksMenu();
		}
		break;

	case 'c':
		if (checkDispenseChips()) {
			std::cout << "Vendin Chips, you have " << getTotalamount() << " dollars left\n";
			Snacks::displaySnacksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Chips <" << getTotalamount() << " < " << Snacks::getChips() << "> \n";
			Snacks::displaySnacksMenu();
		}		break;
	case 'p':
		if (checkDispensePeanuts()) {
			std::cout << "Vendin Peanuts, you have " << getTotalamount() << " dollars left\n";
			Snacks::displaySnacksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Peanuts <" << getTotalamount() << " < " << Snacks::getPeanuts() << "> \n";
			Snacks::displaySnacksMenu();
		}
		break;
	case 'g':
		if (checkDispenseGum()) {
			std::cout << "Vendin Gum, you have " << getTotalamount() << " dollars left \n";
			Snacks::displaySnacksMenu();
		}
		else {
			std::cout << "You dont have enough money to buy Gum <" << getTotalamount() << " < " << Snacks::getGum()<< "> \n";
			Snacks::displaySnacksMenu();
		}
		break;
	default:
		break;
	}
}

bool Snacks::checkDispenseChips()
{
	float amountRemainin = getTotalamount();
	if (amountRemainin >= Snacks::getChips()) {
		float newBalance = amountRemainin - Snacks::getChips();
		setTotalamount(newBalance);
		return true;
	}
	else {
		return false;
	}
}

bool Snacks::checkDispensePeanuts()
{
	float amountRemainin = getTotalamount();
	if (amountRemainin >= Snacks::getPeanuts()) {
		float newBalance = amountRemainin - Snacks::getPeanuts();
		setTotalamount(newBalance);
		return true;
	}
	else {
		return false;
	}
}

bool Snacks::checkDispenseGum()
{
	float amountRemainin = getTotalamount();
	if (amountRemainin >= Snacks::getGum()) {
		float newBalance = amountRemainin - Snacks::getGum();
		setTotalamount(newBalance);
		return true;
	}
	else {
		return false;
	}
}

