// laba2oopA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Class1 {
public:
	virtual void print() {
		cout << "This is Class1" << endl;
	}
};

class Class2 : public Class1 {
public:
	virtual void print() {
		cout << "This is Class2" << endl;
	}
};

void my_copy(Class1* obj, vector<Class1*>& database) {
	Class1* copy = 0;
	if (dynamic_cast<Class2*>(obj)) {
		copy = new Class2(*dynamic_cast<Class2*>(obj));
	}
	else {
		copy = new Class1(*dynamic_cast<Class1*>(obj));
	}
	database.push_back(copy);
}

int main() {
	Class1 obj1;
	Class2 obj2;

	vector<Class1*> database;

	my_copy(&obj1, database);
	my_copy(&obj2, database);

	for (vector<Class1*>::iterator it = database.begin(); it != database.end(); ++it) {
		cout << typeid(**it).name() << endl;
		delete* it;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
