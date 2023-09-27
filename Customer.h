#pragma once
#include <vector>
#include <string>
#include "OrderSystem.h"
#include "OrderHistory.h"
#include "Order.h"

class Customer {
public:
	Customer(std::string name, std::string address);

	void AddOrder(const Order& order);

	std::vector<Order> GetActiveOrders();

	std::vector<Order>& GetOrders();

	void CancelOrder(int id);

	void CompleteOrder(int id);

	std::string GetName();

	void DeleteOrder(const int id);

	bool operator==(const Customer& other) const;

private:
	OrderHistory _history;
	std::string _name;
	std::string _address;
};