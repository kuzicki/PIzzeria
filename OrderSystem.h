#pragma once
#include <iostream>
#include "Customer.h"

class OrderSystem {
public:
	static OrderSystem& Get();

	static OrderSystem& GetNew();

	static std::string GetActiveOrders();

	static std::string GetOrders();

	static int findOrder(const std::vector<Customer>& customers, const Customer& customer);

	static void AddOrder(Customer& customer, Order& order);

	static void CompleteOrder(int id);

	static void CancelOrder(int id);

	static void DeleteOrder(Customer& customer, const int id);
	
	static void DeleteOrder(const int id);
private:
	static OrderSystem* s_instance;
	int _id = 1;
	std::vector<Customer> _customers;
};

