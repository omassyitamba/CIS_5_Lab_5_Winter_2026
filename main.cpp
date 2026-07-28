#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Create a struct Business Card
struct BusinessCard {
	string companyName;
	string address;
	string phoneNumber;
	string workingHours;
	string pointOfContact;
	int priceQuoted;

	BusinessCard(string name, string addr, string phone, string hours, string contact, int price)
		: companyName(name), address(addr), phoneNumber(phone), workingHours(hours), pointOfContact(contact), priceQuoted(price) {
	}
};

void printCard(const BusinessCard& card) {
	cout << card.companyName << " | " << card.phoneNumber << " | " << card.address
	     << " | " << card.workingHours << " | " << card.pointOfContact
	     << " | $" << card.priceQuoted << endl;
}
int main() {
	//Seeding the randomizer
	srand(time(nullptr));

	//Creating the 5 Companies
	BusinessCard companies[5] = {
		BusinessCard("Company A", "123 Main St", "555-1234", "9am-5pm", "Alice", rand() % 500 + 100),
		BusinessCard("Company B", "456 Elm St", "555-5678", "10am-6pm", "Bob", rand() % 500 + 100),
		BusinessCard("Company C", "789 Oak St", "555-9012", "8am-4pm", "Charlie", rand() % 500 + 100),
		BusinessCard("Company D", "321 Pine St", "555-3456", "11am-7pm", "Diana", rand() % 500 + 100),
		BusinessCard("Company E", "654 Maple St", "555-7890", "7am-3pm", "Eve", rand() % 500 + 100)

	};

	for (int i = 0; i < 5; i++) {
		printCard(companies[i]);
	}

	// Finding the cheapest company
	int lowestIndex = 0;
	for (int i = 1; i < 5; i++) {
		if (companies[i].priceQuoted < companies[lowestIndex].priceQuoted) {
			lowestIndex = i;
		}
	}
	// Printing the cheapest company
	cout << "The cheapest company is: " << companies[lowestIndex].companyName
		<< " with a price of $" << companies[lowestIndex].priceQuoted << endl;

	return 0;

}


