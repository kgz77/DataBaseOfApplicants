#include<iostream>
#include<vector>
#include<string> 
#include<iomanip>	//��� ���������������� ������
#include<fstream>
#include<Windows.h>	//��� ������������� �������� � �������
using namespace std;

class Abiturient {
private:
	int id;				//ID
	string surname;		//�������
	string name;		//���
	int yearOfBirth;	//��� ��������
	int schoolNumber;	//����� �����
	float averageScore;	//������� ����
public:
	//���������� ������
	void addField();
	//�������������� ������
	void editField(vector<Abiturient>& obj);
	//�������� ������
	void deleteField(vector<Abiturient>& obj);
	//����� �� ���������
	void searchBySurname(vector<Abiturient>& obj);
	void searchByName(vector<Abiturient>& obj);
	void searchByYearOfBirth(vector<Abiturient>& obj);
	void searchBySchoolNum(vector<Abiturient>& obj);
	void searchByAverageScore(vector<Abiturient>& obj);
	//����� ������ � ������� ���� ���� ������ 4
	void outputAverageScore(vector<Abiturient>& obj);
	//������ ������ �� �����
	void readingFromFile(vector<Abiturient>& obj);
	//������ ������ � ����
	void writingToFile(vector<Abiturient>& obj);
	//����� ���������
	void heading();
	//����� ������ �� �������
	void outputData();
};

void Abiturient::addField() {
	cout << "������� ������� : ";
	cin >> this->surname;
	cout << "������� ��� : ";
	cin >> this->name;
	cout << "��� �������� : ";
	cin >> this->yearOfBirth;
	cout << "����� ����� : ";
	cin >> this->schoolNumber;
	cout << "������� ���� : ";
	cin >> this->averageScore;
}
void Abiturient::editField(vector<Abiturient>& obj) {	//�������������� ����
	cout << "\n������� ID : ";
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
		cout << "������ ����������� ���!" << endl;
	Abiturient help;
	help.writingToFile(obj);
}
void Abiturient::deleteField(vector<Abiturient>& obj) { //�������� ����
	cout << "\n������� ID : ";
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
		cout << "������ ����������� ���!" << endl;
	Abiturient help;
	help.writingToFile(obj);
}

void Abiturient::searchBySurname(vector<Abiturient>& obj) {
	cout << "������� ������� : ";
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
		cout << "������ ����������� ���!" << endl;
}
void Abiturient::searchByName(vector<Abiturient>& obj) {
	cout << "������� ��� : ";
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
		cout << "������ ����������� ���!" << endl;
}
void Abiturient::searchByYearOfBirth(vector<Abiturient>& obj) {
	cout << "������� ��� �������� : ";
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
		cout << "������ ����������� ���!" << endl;
}
void Abiturient::searchBySchoolNum(vector<Abiturient>& obj) {
	cout << "������� ����� ����� : ";
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
		cout << "������ ����������� ���!" << endl;
}
void Abiturient::searchByAverageScore(vector<Abiturient>& obj) {
	cout << "������� ���� ���� : ";
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
		cout << "������ ����������� ���!" << endl;
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
		cout << "������ ����������� ���!" << endl;
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
		cout << "������ �������� �����!" << endl;
	}
	reading.close();
}

void Abiturient::writingToFile(vector<Abiturient>& obj) {
	ofstream writing("C:/Users/User/source/repos/MProject/data.txt");
	if (writing.is_open()) {
		int sizeOfFile = obj.size();
		writing << sizeOfFile << endl;
		for (int i = 0; i < obj.size(); i++) {
			obj[i].id = i;//��������� id
			writing << obj[i].id << endl << obj[i].surname << endl << obj[i].name << endl;
			writing << obj[i].yearOfBirth << endl << obj[i].schoolNumber << endl << obj[i].averageScore << endl;
			obj[i].id = 0;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	writing.close();
}

void Abiturient::heading() {
	cout << "\n\t\t\t\t�� �����������" << "\n"
		<< setw(5) << left << "\nID" << setw(10) << "�������" << setw(10) << "���"
		<< setw(15) << "��� ��������" << setw(14) << "����� �����"
		<< setw(15) << "������� ����" << endl;
}
void Abiturient::outputData() {
	cout << "____________________________________________________________________" << endl;
	cout << setw(4) << left << this->id << setw(10) << this->surname << setw(10) << this->name
		<< setw(15) << this->yearOfBirth << setw(14) << this->schoolNumber
		<< setw(15) << this->averageScore << endl;
}

//_________��������� �������___________
//����������
void add(vector<Abiturient>& obj);
//����� ������
void output(vector<Abiturient>& obj);
//��������������
void edit(vector<Abiturient>& obj);
//��������
void del(vector<Abiturient>& obj);
//����� 
void search(vector<Abiturient>& obj);
//������ ������ �� �����
void start(vector<Abiturient>& obj);

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������� ������ � ����� �������
	vector<Abiturient> obj;
	//��������������� ������
	Abiturient temp;

	int m;//���������� ���� ��� switch
	do {
		start(obj);
		cout << "\n1 - �������� ������" << endl;
		cout << "2 - ����� ������ " << endl;
		cout << "3 - ������������� ������ " << endl;
		cout << "4 - ������� ������" << endl;
		cout << "5 - �����" << endl;
		cout << "6 - ����� ������ ���� ���� ������ 4" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �������� : ";
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
	cout << "������� ���-�� ������������ : ";
	int kolStudent;
	cin >> kolStudent;
	obj.reserve(kolStudent);
	for (int i = 0; i < kolStudent; i++) {
		cout << "\n--------�" << i + 1 << "--------" << endl;
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
	cout << "\n1 - ����� �� ��������" << endl;
	cout << "2 - ����� �� �����" << endl;
	cout << "3 - ����� �� ���� ��������" << endl;
	cout << "4 - ����� �� ������ �����" << endl;
	cout << "5 - ����� �� �������� �����" << endl;
	cout << "�������� �������� : ";
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