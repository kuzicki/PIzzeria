#include "Ingredient.h"

Ingredient::Ingredient(std::string name, int price) : _name(name), _price(price) {}

int Ingredient::GetPrice() const { return _price; }

std::string Ingredient::ToString() {
	return _name;
}

Ingredient* IngredientFactory::Create(Ingredients ingredient) {
	switch (ingredient) {
	case Ingredients::Tomato:
		return new Ingredient("Tomato", 150);
	case Ingredients::Cheese:
		return new Ingredient("Cheese", 200);
	case Ingredients::Lettuce:
		return new Ingredient("Lettuce", 110);
	case Ingredients::Mayo:
		return new Ingredient("Mayo", 150);
	case Ingredients::Peperroni:
		return new Ingredient("Peperroni", 300);
	case Ingredients::Bacon:
		return new Ingredient("Bacon", 350);
	case Ingredients::TomatoSauce:
		return new Ingredient("Tomato Sauce", 140);
	case Ingredients::MozarellaCheese:
		return new Ingredient("Mozarella Cheese", 200);
	case Ingredients::Pickles:
		return new Ingredient("Pickles", 110);
	default:
		return new Ingredient("Peperroni", 300);
	}
}