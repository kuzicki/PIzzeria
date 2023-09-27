#include <iostream>
#include <vector>
#include "Pizzeria.h"
#include <iostream>

using namespace std;

int main() {
	OrderSystem instance = OrderSystem::GetNew();
	Customer customer("Nick", "Street avenue");
	FarmPizza pizza1;
	PeperonniPizza pizza2;
	Order order;
	order.AddPizza(pizza1);
	order.AddPizza(pizza2);
	instance.AddOrder(customer, order);
	instance.CancelOrder(1);
	instance.CompleteOrder(1);
	std::string out = instance.GetOrders();
	std::string expectedStr = "Nick\n1)\nFarm pizza(Bacon, Pickles, Mozarella Cheese)\n";
	cout << out;
}