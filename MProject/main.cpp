#include<iostream>
#include<vector>
#include<string> 
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

class Abiturient {
protected:
	int id;
	static size_t counter;
	string surname;		//Фамилия
	string name;		//Имя
	int yearOfBirth;	//Год рождения
	int schoolNumber;	//Номер школы
	float averageScore;	//Средний балл
public:
	Abiturient() { counter++; this->id = counter; }
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
		cout << "\nВведите ID : ";
		int temp;
		bool check = false;
		cin >> temp;
		for (int i = 0; i < obj.size(); i++) {
			if (temp == obj[i].id) {
				obj[i].addField();
				obj.at(i) = obj[i];
				check = true;
			}
		}
		if(!check)
			cout << "Такого абитуриента нет!" << endl;
	}
	void deleteField(vector<Abiturient>& obj) { //Удаление поля
		cout << "\nВведите ID : ";
		int temp;
		bool check = false;
		cin >> temp;
		for (int i = 0; i < obj.size(); i++) {
			if (temp == obj[i].id) {
				obj.erase(obj.begin() + i);
				check = true;
			}
		}
		if (!check)
			cout << "Такого абитуриента нет!" << endl;
	}

	void searchBySurname(vector<Abiturient>& obj) {
		cout << "Введите фамилию : ";
		string tempSurname;
		bool check = false;
		cin >> tempSurname;
		for (int i = 0; i < obj.size(); i++) {
			if (tempSurname == obj[i].surname) {
				Abiturient temp;
				heading();
				obj[i].outputData();
				check = true;
			}
		}
		if (!check)
			cout << "Такого абитуриента нет!" << endl;
	}
	void searchByName(vector<Abiturient>& obj) {
		cout << "Введите имя : ";
		string tempName;
		bool check = false;
		cin >> tempName;
		for (int i = 0; i < obj.size(); i++) {
			if (tempName == obj[i].name) {
				Abiturient temp;
				heading();
				obj[i].outputData();
				check = true;
			}
		}
		if (!check)
			cout << "Такого абитуриента нет!" << endl;
	}
	void searchByYearOfBirth(vector<Abiturient>& obj) {
		cout << "Введите год рождения : ";
		int tempYear;
		bool check = false;
		cin >> tempYear;
		for (int i = 0; i < obj.size(); i++) {
			if (tempYear == obj[i].yearOfBirth) {
				Abiturient temp;
				heading();
				obj[i].outputData();
				bool check = false;
			}
		}
		if (!check)
			cout << "Такого абитуриента нет!" << endl;
	}
	void searchBySchoolNum(vector<Abiturient>& obj) {
		cout << "Введите номер школы : ";
		int tempSchoolNum;
		bool check = false;
		cin >> tempSchoolNum;
		for (int i = 0; i < obj.size(); i++) {
			if (tempSchoolNum == obj[i].schoolNumber) {
				if (obj[i].averageScore > 4) {
					Abiturient temp;
					heading();
					obj[i].outputData();
					bool check = false;
				}
			}
		}
		if (!check)
			cout << "Такого абитуриента нет!" << endl;
	}
	void searchByAverageScore(vector<Abiturient>& obj) {
		cout << "Введите год рождения : ";
		float tempAverageScore;
		bool check = false;
		cin >> tempAverageScore;
		for (int i = 0; i < obj.size(); i++) {
			if (tempAverageScore == obj[i].averageScore) {
				Abiturient temp;
				heading();
				obj[i].outputData();					
				bool check = false;
			}
		}
		if (!check)
			cout << "Такого абитуриента нет!" << endl;
	}

	void readData(vector<Abiturient>& obj) {
		ifstream read("C:/Users/User/source/repos/MProject/data.txt");
		if (read.is_open()) {
			while(!read.eof()){
				Abiturient temp;
				read >> temp.surname >> temp.name;
				read >> temp.yearOfBirth >> temp.schoolNumber >> temp.averageScore;
				obj.push_back(temp);
			}
		}
		else {
			cout << "Ошибка открытия файла!" << endl;
		}
		read.close();
	}

	void heading() {
		cout<<"\n\t\t\t\tБД АБИТУРИЕНТЫ"<<"\n"
			<< setw(5) << left << "\nID" << setw(10) << "Фамилия" << setw(10) << "Имя"
			<< setw(15) << "Год рождения" << setw(14) << "Номер школы"
			<< setw(15) << "Средний балл" << endl;
	}
	void outputData() {
		cout << "____________________________________________________________________" << endl;
		cout << setw(4) << left << this->id << setw(10) << this->surname << setw(10) << this->name
			<< setw(15) << this->yearOfBirth << setw(14) << this->schoolNumber
			<< setw(15) << this->averageScore << endl;
	}
	string getSurname() { return surname; }
};

size_t Abiturient::counter = 0;

void add(vector<Abiturient>& obj);
void output(vector<Abiturient>& obj);
void edit(vector<Abiturient>& obj);
void del(vector<Abiturient>& obj);
void search(vector<Abiturient>& obj);

int main() {
	setlocale(LC_ALL, "ru");

	vector<Abiturient> obj;
	Abiturient temp;

	int m;//переменная меню для switch
	do {
		cout << "\n1 - Добавить данные" << endl;
		cout << "2 - Вывод данных " << endl;
		cout << "3 - Редактировать данные " << endl;
		cout << "4 - Удалить данные" << endl;
		cout << "5 - Поиск" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите действие : ";
		cin >> m;

		switch (m) {
		case 1:add(obj);break;
		case 2:output(obj);break;
		case 3:edit(obj); break;
		case 4:del(obj); break;
		case 5:search(obj); break;
		default:break;
		}
	} while (m != 0);


	system("pause");
	return 0;
}

void add(vector<Abiturient>& obj) {
	cout << "Введите кол-во абитуриентов : ";
	int kolStudent;
	cin >> kolStudent;
	obj.reserve(kolStudent);
	for (int i = 0; i < kolStudent; i++) {
		cout << "\n--------№" << i + 1 << "--------" << endl;
		Abiturient a;
		a.addField();
		obj.push_back(a);
	}
}

void output(vector<Abiturient>& obj) {
	Abiturient help;
	obj.clear();
	help.readData(obj);
	help.heading();
	for (int i = 0; i < obj.size(); i++) {
		obj[i].outputData();
	}
} 

void edit(vector<Abiturient>& obj) {
	Abiturient temp;
	temp.editField(obj);
}

void del(vector<Abiturient>& obj) {
	Abiturient temp;
	temp.deleteField(obj);
}

void search(vector<Abiturient>& obj) {
	Abiturient temp;
	int m;
	cout << "\n1 - Поиск по фамилиии" << endl;
	cout << "2 - Поиск по имени" << endl;
	cout << "3 - Поиск по году рождения" << endl;
	cout << "4 - Поиск по номеру школы" << endl;
	cout << "5 - Поиск по среднему баллу" << endl;
	cout << "Выберите действие : ";
	cin >> m;
	switch (m) {
	case 1:temp.searchBySurname(obj); cout << endl; break;
	case 2:temp.searchByName(obj); cout << endl; break;
	case 3:temp.searchByYearOfBirth(obj); cout << endl; break;
	case 4:temp.searchBySchoolNum(obj); cout << endl; break;
	case 5:temp.searchByAverageScore(obj); cout << endl; break;
	default:
		break;
	}
}