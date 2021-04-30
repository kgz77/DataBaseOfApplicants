#include<iostream>
#include<vector>
#include<string> 
#include<iomanip>	//Для форматированного вывода
#include<fstream>
#include<Windows.h>	//Для использования кирилицы в консоли
using namespace std;

class Abiturient {
private:
	int id;				//ID
	string surname;		//Фамилия
	string name;		//Имя
	int yearOfBirth;	//Год рождения
	int schoolNumber;	//Номер школы
	float averageScore;	//Средний балл
public:
	//Добавление данных
	void addField();
	//Редактирование данных
	void editField(vector<Abiturient>& obj);
	//Удаление данных
	void deleteField(vector<Abiturient>& obj);
	//Поиск по значениям
	void searchBySurname(vector<Abiturient>& obj);
	void searchByName(vector<Abiturient>& obj);
	void searchByYearOfBirth(vector<Abiturient>& obj);
	void searchBySchoolNum(vector<Abiturient>& obj);
	void searchByAverageScore(vector<Abiturient>& obj);
	//Вывод данных у которых сред балл больше 4
	void outputAverageScore(vector<Abiturient>& obj);
	//Чтение данных из файал
	void readingFromFile(vector<Abiturient>& obj);
	//Запись данных в файл
	void writingToFile(vector<Abiturient>& obj);
	//Вывод заголовка
	void heading();
	//Вывод данных на консоль
	void outputData();
};

void Abiturient::addField() {
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
void Abiturient::editField(vector<Abiturient>& obj) {	//Редактирования поля
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
	if (!check)
		cout << "Такого абитуриента нет!" << endl;
	Abiturient help;
	help.writingToFile(obj);
}
void Abiturient::deleteField(vector<Abiturient>& obj) { //Удаление поля
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
	Abiturient help;
	help.writingToFile(obj);
}

void Abiturient::searchBySurname(vector<Abiturient>& obj) {
	cout << "Введите фамилию : ";
	string tempSurname;
	bool check = false;
	cin >> tempSurname;
	heading();
	for (int i = 0; i < obj.size(); i++) {
		if (tempSurname == obj[i].surname) {
			obj[i].outputData();
			check = true;
		}
	}
	if (!check)
		cout << "Такого абитуриента нет!" << endl;
}
void Abiturient::searchByName(vector<Abiturient>& obj) {
	cout << "Введите имя : ";
	string tempName;
	bool check = false;
	cin >> tempName;
	heading();
	for (int i = 0; i < obj.size(); i++) {
		if (tempName == obj[i].name) {
			obj[i].outputData();
			check = true;
		}
	}
	if (!check)
		cout << "Такого абитуриента нет!" << endl;
}
void Abiturient::searchByYearOfBirth(vector<Abiturient>& obj) {
	cout << "Введите год рождения : ";
	int tempYear;
	bool check = false;
	cin >> tempYear;
	heading();
	for (int i = 0; i < obj.size(); i++) {
		if (tempYear == obj[i].yearOfBirth) {
			obj[i].outputData();
			check = true;
		}
	}
	if (!check)
		cout << "Такого абитуриента нет!" << endl;
}
void Abiturient::searchBySchoolNum(vector<Abiturient>& obj) {
	cout << "Введите номер школы : ";
	int tempSchoolNum;
	bool check = false;
	cin >> tempSchoolNum;
	heading();
	for (int i = 0; i < obj.size(); i++) {
		if (tempSchoolNum == obj[i].schoolNumber) {
			if (obj[i].averageScore > 4) {
				obj[i].outputData();
				check = true;
			}
		}
	}
	if (!check)
		cout << "Такого абитуриента нет!" << endl;
}
void Abiturient::searchByAverageScore(vector<Abiturient>& obj) {
	cout << "Введите сред балл : ";
	float tempAverageScore;
	bool check = false;
	cin >> tempAverageScore;
	heading();
	for (int i = 0; i < obj.size(); i++) {
		if (tempAverageScore == obj[i].averageScore) {
			obj[i].outputData();
			check = true;
		}
	}
	if (!check)
		cout << "Такого абитуриента нет!" << endl;
}

void Abiturient::outputAverageScore(vector<Abiturient>& obj) {
	bool check = false;
	heading();
	for (int i = 0; i < obj.size(); i++) {
		if (obj[i].averageScore > 4) {
			obj[i].outputData();
			check = true;
		}
	}
	if(!check)
		cout << "Такого абитуриента нет!" << endl;
}

void Abiturient::readingFromFile(vector<Abiturient>& obj) {
	ifstream reading("C:/Users/User/source/repos/MProject/data.txt");
	if (reading.is_open()) {
		int sizeOfFile;
		reading >> sizeOfFile;
		for (int i = 0; i < sizeOfFile; i++) {
			Abiturient temp;
			reading >> temp.id >> temp.surname >> temp.name;
			reading >> temp.yearOfBirth >> temp.schoolNumber >> temp.averageScore;
			obj.push_back(temp);
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	reading.close();
}

void Abiturient::writingToFile(vector<Abiturient>& obj) {
	ofstream writing("C:/Users/User/source/repos/MProject/data.txt");
	if (writing.is_open()) {
		int sizeOfFile = obj.size();
		writing << sizeOfFile << endl;
		for (int i = 0; i < obj.size(); i++) {
			obj[i].id = i;//генерация id
			writing << obj[i].id << endl << obj[i].surname << endl << obj[i].name << endl;
			writing << obj[i].yearOfBirth << endl << obj[i].schoolNumber << endl << obj[i].averageScore << endl;
			obj[i].id = 0;
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
	}
	writing.close();
}

void Abiturient::heading() {
	cout << "\n\t\t\t\tБД АБИТУРИЕНТЫ" << "\n"
		<< setw(5) << left << "\nID" << setw(10) << "Фамилия" << setw(10) << "Имя"
		<< setw(15) << "Год рождения" << setw(14) << "Номер школы"
		<< setw(15) << "Средний балл" << endl;
}
void Abiturient::outputData() {
	cout << "____________________________________________________________________" << endl;
	cout << setw(4) << left << this->id << setw(10) << this->surname << setw(10) << this->name
		<< setw(15) << this->yearOfBirth << setw(14) << this->schoolNumber
		<< setw(15) << this->averageScore << endl;
}

//_________Прототипы функций___________
//Добавление
void add(vector<Abiturient>& obj);
//Вывод данных
void output(vector<Abiturient>& obj);
//Редактирование
void edit(vector<Abiturient>& obj);
//Удаление
void del(vector<Abiturient>& obj);
//Поиск 
void search(vector<Abiturient>& obj);
//Чтение данных из файла
void start(vector<Abiturient>& obj);

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//объекты класса в ввиде вектора
	vector<Abiturient> obj;
	//Вспомогательный объект
	Abiturient temp;

	int m;//переменная меню для switch
	do {
		start(obj);
		cout << "\n1 - Добавить данные" << endl;
		cout << "2 - Вывод данных " << endl;
		cout << "3 - Редактировать данные " << endl;
		cout << "4 - Удалить данные" << endl;
		cout << "5 - Поиск" << endl;
		cout << "6 - Вывод данных сред балл больше 4" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите действие : ";
		cin >> m;

		switch (m) {
		case 1:add(obj);break;
		case 2:output(obj);break;
		case 3:edit(obj); break;
		case 4:del(obj); break;
		case 5:search(obj); break;
		case 6:temp.outputAverageScore(obj); break;
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
	Abiturient help;
	help.writingToFile(obj);
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

void start(vector<Abiturient>& obj) {
	Abiturient temp;
	obj.clear();
	temp.readingFromFile(obj);
}