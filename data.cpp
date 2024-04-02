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


	// Entry �����迭 �ʵ带 ���� add, get ���� ���� �����Ҽ��־���Ѵ�.

	// �ش� �κи� �����Ͽ� ����Ѵ�.
	// �ٸ� �κ��� �����ϸ� �ȵ�.
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

// �����ͺ��̽����� Ű�� �ش��ϴ� ��Ʈ���� ã�´�.
Entry* get(Database& database, std::string& key) {

	for (int i = 0; i < database.size; ++i) {
		if (database.data[i]->key == key) {
			return database.data[i];
		}
	}
	

}
// ��Ʈ���� ���� �ִ´�.
void add(Database& database, Entry* entry) {

	

	database.data[database.size++] = entry;

}

// �����ͺ��̽��� �����Ѵ�.
void destroy(Database& database) {

	delete[] database.data;
}

// �����ͺ��̽��� �ʱ�ȭ�Ѵ�.
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
			string types = typeset(); //Ÿ�� ���ϱ�

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

