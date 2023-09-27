#pragma once
#include <string>

enum class Ingredients {
	Tomato, Cheese, Lettuce, Mayo, Peperroni, Bacon, TomatoSauce, MozarellaCheese, Pickles
};

class Ingredient {
public:
	Ingredient(std::string name, int price);

	int GetPrice() const;

	std::string ToString();
private:
	std::string _name;
	int _price;
};

class IngredientFactory {
public:
	Ingredient* Create(Ingredients ingredient);
};