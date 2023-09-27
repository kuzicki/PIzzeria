#pragma once
#include <vector>
#include "Ingredient.h"

class Pizza {
public:
	Pizza();

	Pizza(std::string name);

	void AddIngredient(Ingredient* ingredient);

	void ChangeName(std::string name);

	virtual void AddDefaultIngredients();

	std::string ToString() const;

	int CalculateCost() const;

	bool operator==(const Pizza & other) const {
		if (this->_name != other._name) {
			return false;
		}

		return true;
	}
protected:
	std::string _name;
	std::vector<Ingredient*> _ingredients;
};

class PeperonniPizza : public Pizza {
public:
	PeperonniPizza() : Pizza("Peperonni pizza") {
		AddDefaultIngredients();
	}

	void AddDefaultIngredients() override;
};

class MargaritaPizza : public Pizza {
public:
	MargaritaPizza() : Pizza("Margarita pizza") {
		AddDefaultIngredients();
	}

	void AddDefaultIngredients() override;
};

class FarmPizza : public Pizza {
public:
	FarmPizza() : Pizza("Farm pizza") {
		AddDefaultIngredients();
	}

	void AddDefaultIngredients() override;
};