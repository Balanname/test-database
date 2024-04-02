#include <iostream>
#include "database.h"

using namespace std;

struct Array {
	int size;
	Type type;
	void* items;
};

struct Entry {
	Type type;
	std::string key;
	void* value;
};


struct Database {

	int size;
	int arrays;
	Entry** data = new Entry*[arrays];


	// Entry 동적배열 필드를 갖고 add, get 등을 통해 조작할수있어야한다.

	// 해당 부분만 수정하여 사용한다.
	// 다른 부분은 수정하면 안됨.
};

Database mydatabase;


string keyset() {
	
	string key;
	cout << "key: ";
	cin >> key;
	return key;
}

string typeset() {

	string name;
	cin >> name;
	return name;
}

string* valueset() {

	string* value = new string;
	cout << "value: ";
	cin >> *value;

	return value;

}

int* intset() {

	cout << "value: ";
	int* number = new int;
	cin >> *number;
	return number;
}

double* doubleset() {

	cout << "value: ";
	double* dounumber = new double;
	cin >> *dounumber;
	return dounumber;
}

Entry* create(Type type, string key, void* value) {

	Entry* entry = new Entry;
	entry->type = type;
	entry->key = key;

	switch (type) {
	case Type::INT: {
		int* intValue = static_cast<int*>(value);
		entry->value = new int(*intValue);
		break;
	}
	case Type::DOUBLE: {
		double* douvalue = static_cast<double*>(value);
		entry->value = new double(*douvalue);
		break;
	}
	case Type::STRING: {
		string* strvalue = static_cast<string*>(value);
		entry->value = new string(*strvalue);
		break;
	}
	case Type::ARRAY: {

		Array* arrayvalue = static_cast<Array*>(value);
		entry->value = new Array;
		Array* entryarray = static_cast<Array*>(value);
		entryarray->size = arrayvalue->size;
		entryarray->type = arrayvalue->type;
		entryarray->items = new char[arrayvalue->size];
		memcpy(entryarray->items, arrayvalue->items, arrayvalue->size);
		break;
	}
	}
	return entry;


}

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry* get(Database& database, std::string& key) {

	for (int i = 0; i < database.size; ++i) {
		if (database.data[i]->key == key) {
			return database.data[i];
		}
	}
	

}
// 엔트리에 값을 넣는다.
void add(Database& database, Entry* entry) {

	

	database.data[database.size++] = entry;

}

// 데이터베이스를 해제한다.
void destroy(Database& database) {

	delete[] database.data;
}

// 데이터베이스를 초기화한다.
void init(Database& database) {

	database.size = 0;
	database.arrays = 10;

	delete[] &database.arrays;

	database.data = new Entry*[database.arrays];
}

int main() {
	string command;


	struct Database mydatabase;

	

	init(mydatabase);

	while (true) {
		
		cout << "command (list, add, get, del, exit): ";
		cin >> command;
		if (command == "add") {
			string key = keyset();
			cout << "type (int, double, string, array): ";
			string types = typeset(); //타입 정하기

			if (types == "string") {
				
				string* stvalue = valueset();
				Entry* stringEntry = create(Type::STRING, key, (void*)&stvalue);
				add(mydatabase, stringEntry);
			}
			else if (types == "int") {

				int* num = intset();
				Entry* intEntry = create(Type::INT, key, (void*)&num);
				add(mydatabase, intEntry);
			}
			else if (types == "double") {

				double* dounum = doubleset();
				Entry* doubleEntry = create(Type::DOUBLE, key, (void*)&dounum);
				add(mydatabase, doubleEntry);
				
			}
			else if (types == "array") {

				
			}
			else {
				cout << "not found cammand";
			}
			
		}
		else if (command == "get") {
			string keyget;
			cout << "key: ";
			cin >> keyget;
			string getstr = keyset();
			get(mydatabase, keyget);

		}

		if (command == "exit") {
			destroy(mydatabase);
			exit(EXIT_SUCCESS);
		}
	}


}

