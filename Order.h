#pragma once
#include "Pizza.h"
#include <vector>

enum class Status {
	Cooking, Ready, Canceled
};

class Order {
public:
	Order();

	std::vector<Pizza> GetPizzas();

	void Complete();

	void AddPizza(Pizza pizza);

	Status GetStatus() const;

	void SetStatus(Status status);

	int CalculateCost() const;

	void SetId(int id);

	bool operator==(const Order& other) const;

	int GetId() const;
private:
	int _id;
	Status _status;
	std::vector<Pizza> _pizzas;
};