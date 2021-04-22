#include<iostream>
#include<vector>
#include<string> 
#include<iomanip>
#include<conio.h>
using namespace std;

class Abiturient {
private:
	vector<int> t;
	static int id;
	string surname;		//Фамилия
	string name;		//Имя
	int yearOfBirth;	//Год рождения
	int schoolNumber;	//Номер школы
	int averageScore;	//Средний балл
	static void countID() { id++; }
public:
	void addField() {	//Запись поля
		cout << "Введите фамилию : ";
		cin >> this->surname;
		cout << "Введите имя : ";
		cin >> this->name;
		cout << "Год рождения : ";
		cin >> this->yearOfBirth;
		cout << "Номер школы : ";
		cin >> this->schoolNumber;
		cout << "Средний балл : ";
		cin >> this->averageScore;
	}
	void editField(vector<Abiturient>& obj) {	//Редактирования поля
		cout << "\nВведите ID абитуриента : ";
		int temp;
		cin >> temp;
		for (int i = 0; i < obj.size(); i++) {
			if (temp == obj[i].id) {
				obj[i].addField();
				obj.insert(obj.begin() + i, obj[i]);
			}
		}
	}
	void deleteField() { //Удаление поля
	
	}
	void heading() {
		cout << setw(5) << left << "ID" << setw(10) << "Фамилия" << setw(10) << "Имя"
			<< setw(15) << "Год рождения" << setw(14) << "Номер школы"
			<< setw(15) << "Средний балл" << endl;
	}
	void outputData() {
		countID();
		cout << setw(5) << left << this->id << setw(10) << this->surname << setw(10) << this->name
			<< setw(15) << this->yearOfBirth << setw(14) << this->schoolNumber
			<< setw(15) << this->averageScore << endl;
	}
};

int Abiturient::id = 0;

void add(vector<Abiturient>& obj);
void output(vector<Abiturient>& obj);

void edit(vector<Abiturient>& obj);

int main() {
	setlocale(LC_ALL, "ru");

	vector<Abiturient> obj;
	Abiturient temp;

	int m;//переменная меню для switch
	do {
		cout << "1 - Добавить данные" << endl;
		cout << "2 - Вывод данных " << endl;
		cout << "3 - Редактировать данные " << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите действие : ";
		cin >> m;

		switch (m) {
		case 1:
			add(obj);
			break;
		case 2:
			output(obj);
			break;
		case 3:
			edit(obj);
			break;
		default:
			break;
		}
	} while (m != 0);


	system("pause");
	return 0;
}

void add(vector<Abiturient>& obj) {
	cout << "Введите кол-во студентов : ";
	int kolStudent;
	cin >> kolStudent;
	obj.reserve(kolStudent);
	for (int i = 0; i < kolStudent; i++) {
		Abiturient a;
		a.addField();
		obj.push_back(a);
	}
}

void output(vector<Abiturient>& obj) {
	Abiturient help;
	help.heading();
	for (int i = 0; i < obj.size(); i++) {
		obj[i].outputData();
	}
}

void edit(vector<Abiturient>& obj) {
	Abiturient temp;
	temp.editField(obj);
}
