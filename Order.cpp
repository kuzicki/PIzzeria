#include "Order.h"

Order::Order() : _id(0), _status(Status::Cooking) { }

std::vector<Pizza> Order::GetPizzas() {
	return _pizzas;
}

void Order::Complete() {
	_status = Status::Ready;
}

void Order::AddPizza(Pizza pizza) {
	_pizzas.push_back(pizza);
}

Status Order::GetStatus() const {
	return _status;
}

void Order::SetStatus(Status status) {
	_status = status;
}

int Order::CalculateCost() const {
	int cost = 0;
	for (const Pizza& pizza : _pizzas) {
		cost += pizza.CalculateCost();
	}
	return cost;
}

bool Order::operator==(const Order& other) const {
	if (this->_id != other._id)
		return false;
	if (this->_status != other._status)
		return false;
	if (this->_pizzas != other._pizzas)
		return false;
	return true;
}

void Order::SetId(int id) {
	_id = id;
}

int Order::GetId() const {
	return _id;
}
