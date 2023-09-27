#include "Pizza.h"
#include <string>

Pizza::Pizza() : _name("Custom pizza") { }

Pizza::Pizza(std::string name) : _name(name) { }

void Pizza::AddIngredient(Ingredient* ingredient) {
	_ingredients.push_back(ingredient);
}

void Pizza::ChangeName(std::string name) {
	_name = name;
}

void Pizza::AddDefaultIngredients() {
	IngredientFactory factory;
	_ingredients.push_back(factory.Create(Ingredients::Cheese));
	_ingredients.push_back(factory.Create(Ingredients::Peperroni));
}

std::string Pizza::ToString() const {
	std::string string = _name + "(";

	if (_ingredients.empty()) {
		return string + "Nothing)";
	}

	for (auto ingredient : _ingredients) {
		string += ingredient->ToString() + ", ";
	}
	string = string.substr(0, string.size() - 2);
	string += ")";
	return string;
}

int Pizza::CalculateCost() const {
	int cost = 0;
	for (auto ingredient : _ingredients) {
		cost += ingredient->GetPrice();
	}
	return cost;
}

void PeperonniPizza::AddDefaultIngredients() {
	IngredientFactory factory;
	_ingredients.push_back(factory.Create(Ingredients::Peperroni));
	_ingredients.push_back(factory.Create(Ingredients::TomatoSauce));
	_ingredients.push_back(factory.Create(Ingredients::MozarellaCheese));
}

void MargaritaPizza::AddDefaultIngredients() {
	IngredientFactory factory;
	_ingredients.push_back(factory.Create(Ingredients::TomatoSauce));
	_ingredients.push_back(factory.Create(Ingredients::MozarellaCheese));
}

void FarmPizza::AddDefaultIngredients() {
	IngredientFactory factory;
	_ingredients.push_back(factory.Create(Ingredients::Bacon));
	_ingredients.push_back(factory.Create(Ingredients::Pickles));
	_ingredients.push_back(factory.Create(Ingredients::MozarellaCheese));
}
