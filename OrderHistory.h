#pragma once
#include "Order.h"
#include <vector>
class OrderHistory {
public:
	void Add(const Order& order);

	void CompleteLast();

	void DeleteOrder(const int id);

	void CancelOrder(const int id);

	void CompleteOrder(const int id);

	bool operator!=(const OrderHistory& other)const {
		return this->_items != other._items;
	}

	std::vector<Order> GetActiveOrders();

	std::vector<Order>& GetOrders();
private:
	std::vector<Order> _items;
};