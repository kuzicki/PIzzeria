#include "OrderHistory.h"

void OrderHistory::Add(const Order& order) {
	_items.emplace_back(order);
}

void OrderHistory::CompleteLast() {
	_items[_items.size() - 1].Complete();
}

void OrderHistory::DeleteOrder(const int id) {
	for (int i = 0; i < _items.size(); i++) {
		if (id == _items[i].GetId()) {
			_items.erase(_items.begin() + i);
			return;
		}
	}
}

void OrderHistory::CancelOrder(const int id) {
	for (auto& item : _items) {
		if (item.GetId() == id) {
			item.SetStatus(Status::Canceled);
			return;
		}
	}
}

void OrderHistory::CompleteOrder(const int id) {
	for (auto& item : _items) {
		if (item.GetId() == id) {
			item.SetStatus(Status::Ready);
			return;
		}
	}
}

std::vector<Order> OrderHistory::GetActiveOrders() {
	std::vector<Order> orders;
	for (const auto& order : _items) {
		if (order.GetStatus() == Status::Cooking) {
			orders.push_back(order);
		}
	}
	return orders;
}

std::vector<Order>& OrderHistory::GetOrders() {
	return _items;
}