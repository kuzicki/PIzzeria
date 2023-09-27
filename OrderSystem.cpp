#include "OrderSystem.h"

OrderSystem& OrderSystem::Get() {
	if (!s_instance)
		s_instance = new OrderSystem;

	return *s_instance;
}

OrderSystem& OrderSystem::GetNew() {
	delete s_instance;
	s_instance = new OrderSystem;

	return *s_instance;
}

OrderSystem* OrderSystem::s_instance;

std::string OrderSystem::GetActiveOrders() {
	std::string out = "";
	std::vector<Order> orders;
	std::vector<Pizza> pizzas;
	for (Customer& customer : s_instance->_customers) {
		out += customer.GetName() + "\n";
		orders = customer.GetActiveOrders();
		for (int i = 0; i < orders.size(); i++) {
			pizzas = orders[i].GetPizzas();
			out += std::to_string(i + 1) + ")\n";
			for (auto& pizza : pizzas) {
				out += pizza.ToString() + "\n";
			}
		}
	}
	return out;
}

std::string OrderSystem::GetOrders() {
	std::string out = "";
	std::vector<Order> orders;
	std::vector<Pizza> pizzas;
	for (Customer& customer : s_instance->_customers) {
		out += customer.GetName() + "\n";
		orders = customer.GetOrders();
		for (int i = 0; i < orders.size(); i++) {
			pizzas = orders[i].GetPizzas();
			out += std::to_string(i + 1) + ") ";
			Status status = orders[i].GetStatus();
			if (status == Status::Ready) {
				out += "Ready\n";
			} else if (status == Status::Cooking) {
				out += "Cooking\n";
			} else if (status == Status::Canceled) {
				out += "Canceled\n";
			}
			for (auto& pizza : pizzas) {
				out += pizza.ToString() + "\n";
			}
		}
	}
	return out;
}

void OrderSystem::AddOrder(Customer& customer, Order& order) {
	order.SetId(s_instance->_id);
	std::vector<Customer>& customers = s_instance->_customers;
	int index = findOrder(customers, customer);
	customer.AddOrder(order);
	if (index == -1) {
		s_instance->_customers.push_back(customer);
	}
	else{
		customers[index].AddOrder(order);
	}
	
	s_instance->_id++;
}

int OrderSystem::findOrder(const std::vector<Customer>& customers, const Customer& customer) {
	for (int i = 0; i < customers.size(); i++) {
		if (customer == customers[i]) {
			return i;
		}
	}
	return -1;
}

void OrderSystem::CompleteOrder(int id) {
	std::vector<Order> orders;
	for (auto& customer : s_instance->_customers) {
		customer.CompleteOrder(id);
	}
}

void OrderSystem::CancelOrder(int id) {
	std::vector<Order> orders;
	for (auto& customer : s_instance->_customers) {
		customer.CancelOrder(id);
	}
}

void OrderSystem::DeleteOrder(Customer& customer, const int id) {
	customer.DeleteOrder(id);
}

void OrderSystem::DeleteOrder(const int id) {
	std::vector<Order> orders;
	for (auto& customer : s_instance->_customers) {
		customer.DeleteOrder(id);
	}
}
