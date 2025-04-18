#include <iostream>

#include "Hero.hpp"
#include "Item.hpp"

// Because I'm including default values, I only need one constructor
Hero::Hero(std::string name = "John", int powerLevel = 1) : GameCharacter(name, powerLevel), quest("TBD")
{
}

void Hero::act()
{
	std::cout << name << " poses heroically." << std::endl;
}

void Hero::speak()
{
	std::cout << "If by my life or death I can protect you, I will." << std::endl;
}

void Hero::interactWith(GameCharacter& target)
{
	speak();
	act();
	target.speak();
	target.act();
}

// Swaps inventory items with another GameCharacter
void Hero::trade(GameCharacter& target, int inventoryIndexThis, int inventoryIndexOther)
{
	Item thisItem = Item(inventory.getItem(inventoryIndexThis).getName(), inventory.getItem(inventoryIndexThis).getValue());
	Item otherItem = Item(target.getInventory().getItem(inventoryIndexOther).getName(), target.getInventory().getItem(inventoryIndexOther).getValue());
	inventory.addItem(otherItem);
	inventory.removeItem(thisItem);
	target.getInventory().addItem(thisItem);
	target.getInventory().removeItem(otherItem);
}

// Decreases another GameCharacter's health by the hero's power level
void Hero::attack(GameCharacter& target)
{
	target.setHealth(target.getHealth() - powerLevel);
}

std::string Hero::getQuest()
{
	return quest;
}

void Hero::setQuest(std::string quest)
{
	this->quest = quest;
}

Hero::~Hero()
{
}
