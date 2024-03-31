#include <iostream>
#include "database.h"

using namespace std;

string keyset() {
	
	string key;
	cin >> key;
	return key;
}

string nameset() {

	string name;
	cin >> name;
	return name;
}



int main() {
	string command;


	Database mydatabase;

	Entry* intEntry = create(Type:: INT, "intset", (void*)&mydatabase.intvalue);
	Entry* doubleEntry = create(Type::DOUBLE, "doubleset", (void*)&mydatabase.doublevalue);
	Entry* stringEntry = create(Type::STRING, "stringset", (void*)&mydatabase.stringvalue);
	Entry* arrayEntry = create(Type::ARRAY, "Arrayset", (void*)&mydatabase.array);

	init(mydatabase);

	while (true) {
		
		cout << "command (list, add, get, del, exit): ";
		cin >> command;
		if (command == "add") {
			string key = keyset();
			cout << "type (int, double, string, array): ";
			if (key == "string") {
				cout << "value: ";
				string name = nameset();
				add(mydatabase, stringEntry);
				


			}
			
		}

	}


}

