#include "pch.h"
#include "CppUnitTest.h"
#include <Pizzeria.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PizzeriaTest
{
	TEST_CLASS(PizzeriaTest)
	{
	public:
		
		TEST_METHOD(PizzaClassCalculate) {
			Pizza pizza("Default");
			pizza.AddDefaultIngredients();
			int expected = 500;
			Assert::AreEqual(expected, pizza.CalculateCost());
		}

		TEST_METHOD(PizzaConstructorOverload) {
			PeperonniPizza pizza;
			Assert::AreEqual("Peperonni pizza(Peperroni, Tomato Sauce, Mozarella Cheese)", pizza.ToString().c_str());
		}

		TEST_METHOD(CustomerTest) {
			OrderSystem instance = OrderSystem::Get();
			Customer customer("Nick", "Street avenue");
			MargaritaPizza pizza;
			Order expected;
			expected.AddPizza(pizza);
			instance.AddOrder(customer, expected);
			std::vector<Order> orders = customer.GetOrders();
			Assert::AreEqual(orders[0].GetId(), expected.GetId());
		}

		TEST_METHOD(GetActiveOrders) {
			OrderSystem instance = OrderSystem::GetNew();
			Customer customer("Nick", "Street avenue");
			MargaritaPizza pizza;
			Order expected;
			expected.AddPizza(pizza);
			instance.AddOrder(customer, expected);
			std::string out = instance.GetActiveOrders();
			std::string expectedStr = "Nick\n1)\nMargarita pizza(Tomato Sauce, Mozarella Cheese)\n";
			Assert::AreEqual(expectedStr, out);
		}

		TEST_METHOD(GetActiveOrders2) {
			OrderSystem instance = OrderSystem::GetNew();
			Customer customer("Nick", "Street avenue");
			FarmPizza pizza1;
			PeperonniPizza pizza2;
			Order order;
			order.AddPizza(pizza1);
			order.AddPizza(pizza2);
			instance.AddOrder(customer, order);
			std::string out = instance.GetActiveOrders();
			std::string expectedStr = "Nick\n1)\nFarm pizza(Bacon, Pickles, Mozarella Cheese)\nPeperonni pizza(Peperroni, Tomato Sauce, Mozarella Cheese)\n";
			Assert::AreEqual(expectedStr, out);
		}

		TEST_METHOD(GetOrders) {
			OrderSystem instance = OrderSystem::GetNew();
			Customer customer("Nick", "Street avenue");
			FarmPizza pizza1;
			PeperonniPizza pizza2;
			Order order;
			order.AddPizza(pizza1);
			order.AddPizza(pizza2);
			instance.AddOrder(customer, order);
			instance.CancelOrder(1);
			std::string out = instance.GetOrders();
			std::string expectedStr = "Nick\n1) Canceled\nFarm pizza(Bacon, Pickles, Mozarella Cheese)\nPeperonni pizza(Peperroni, Tomato Sauce, Mozarella Cheese)\n";
			Assert::AreEqual(expectedStr, out);
		}

		TEST_METHOD(DeleteOrderFirst) {
			OrderSystem instance = OrderSystem::GetNew();
			Customer customer("Nick", "Street avenue");
			FarmPizza pizza1;
			PeperonniPizza pizza2;
			MargaritaPizza pizza3;
			Order order1;
			Order order2;
			order1.AddPizza(pizza1);
			order1.AddPizza(pizza2);
			order2.AddPizza(pizza3);
			order2.AddPizza(pizza1);
			instance.AddOrder(customer, order1);
			instance.AddOrder(customer, order2);
			instance.DeleteOrder(1);
			std::string out = instance.GetOrders();
			std::string expectedStr = "Nick\n1) Cooking\nMargarita pizza(Tomato Sauce, Mozarella Cheese)\nFarm pizza(Bacon, Pickles, Mozarella Cheese)\n";
			Assert::AreEqual(expectedStr, out);
		}

		TEST_METHOD(DeleteOrderLast) {
			OrderSystem instance = OrderSystem::GetNew();
			Customer customer("Nick", "Street avenue");
			FarmPizza pizza1;
			PeperonniPizza pizza2;
			MargaritaPizza pizza3;
			Order order1;
			Order order2;
			order1.AddPizza(pizza1);
			order1.AddPizza(pizza2);
			order2.AddPizza(pizza3);
			order2.AddPizza(pizza1);
			instance.AddOrder(customer, order1);
			instance.AddOrder(customer, order2);
			instance.DeleteOrder(2);
			std::string out = instance.GetOrders();
			std::string expectedStr = "Nick\n1) Cooking\nFarm pizza(Bacon, Pickles, Mozarella Cheese)\nPeperonni pizza(Peperroni, Tomato Sauce, Mozarella Cheese)\n";
			Assert::AreEqual(expectedStr, out);
		}

		TEST_METHOD(CompleteOrder) {
			OrderSystem instance = OrderSystem::GetNew();
			Customer customer("Nick", "Street avenue");
			FarmPizza pizza1;
			PeperonniPizza pizza2;
			MargaritaPizza pizza3;
			Order order1;
			Order order2;
			order1.AddPizza(pizza1);
			order1.AddPizza(pizza2);
			order2.AddPizza(pizza3);
			order2.AddPizza(pizza1);
			instance.AddOrder(customer, order1);
			instance.AddOrder(customer, order2);
			instance.DeleteOrder(2);
			instance.CompleteOrder(1);
			std::string out = instance.GetOrders();
			std::string expectedStr = "Nick\n1) Ready\nFarm pizza(Bacon, Pickles, Mozarella Cheese)\nPeperonni pizza(Peperroni, Tomato Sauce, Mozarella Cheese)\n";
			Assert::AreEqual(expectedStr, out);
		}

		TEST_METHOD(ChangeNameTest) {
			PeperonniPizza peperonni;
			peperonni.ChangeName("My own pizza");
			std::string expected = "My own pizza(Peperroni, Tomato Sauce, Mozarella Cheese)";
			Assert::AreEqual(expected, peperonni.ToString());
		}

		TEST_METHOD(AddIngredientsTest) {
			PeperonniPizza pizza;
			Ingredient* cabagge = new Ingredient("Cabbage", 100);
			pizza.AddIngredient(cabagge);
			std::string expected = "Peperonni pizza(Peperroni, Tomato Sauce, Mozarella Cheese, Cabbage)";
			Assert::AreEqual(expected, pizza.ToString());
		}
	};
}
