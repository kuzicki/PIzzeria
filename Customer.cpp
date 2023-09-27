#include "OrderHistory.h"
#include "OrderSystem.h"
#include "Customer.h"

Customer::Customer(std::string name, std::string address) : _name(name), _address(address) { }

void Customer::AddOrder(const Order& order) {
	_history.Add(order);
}

std::vector<Order> Customer::GetActiveOrders(){
	return _history.GetActiveOrders();
}

void Customer::CancelOrder(int id) {
	_history.CancelOrder(id);
}

void Customer::CompleteOrder(int id) {
	_history.CompleteOrder(id);
}

bool Customer::operator==(const Customer& other) const {
	if (this->_name != other._name) {
		return false;
	}

	if (this->_address != other._address) {
		return false;
	}

	return true;
}


std::vector<Order>& Customer::GetOrders(){
	return _history.GetOrders();
}

std::string Customer::GetName() {
	return _name;
}

void Customer::DeleteOrder(const int id) {
	_history.DeleteOrder(id);
}
