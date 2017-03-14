#pragma once
#include "iostream"


class VendinMachine {
public:
	friend class Drinks;
	friend class Snacks;

	float getamountInserted();
	void setCoins(int number);
	void setAmountInserted(float coins);

	void displayMenu();
	void displayAmountInserted();
	void displayMainMenu();
	void displayErroronCoice();

	void initDrinkDispenser();
	void initSnacksDispenser();

	void checkSelection(int selection);
private:
	int number_of_coins;
	float amountInserted;

};

class Drinks:VendinMachine {
public:
	//friend class VendinMachine;

	float getWater() {return this->Water;}
	float getSoda() {return this->Soda;}
	float getJuice() {return this->Juice;}

	void displayDrinksMenu();
	void setSelectedDrink(char selected) {this->selectedDrink=selected;}

	void checkDrinkSelection(char option);
	bool checkDispenseWater();
	bool checkDispenseJuice();
	bool checkDispenseSoda();


private:
	float Water = 0.75;
	float Juice = 0.99;
	float Soda = 1.39;
	char selectedDrink;
};



class Snacks:VendinMachine {
public:
	float getChips() {return this->Chips;}
	float getPeanuts() {return this->Peanuts;}
	float getGum() {return this->Gum;}

 	void displaySnacksMenu();

	void checkSnackSelection(char option);
	bool checkDispenseChips();
	bool checkDispensePeanuts();
	bool checkDispenseGum();
private:
	float Chips = 0.99;
	float Peanuts = 0.5;
	float Gum = 0.35;

};