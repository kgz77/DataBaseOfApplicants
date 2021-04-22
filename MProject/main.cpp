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
	string surname;		//�������
	string name;		//���
	int yearOfBirth;	//��� ��������
	int schoolNumber;	//����� �����
	float averageScore;	//������� ����
public:
	Abiturient() { counter++; this->id = counter; }
	void addField() {	//������ ����
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
	void editField(vector<Abiturient>& obj) {	//�������������� ����
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
		if(!check)
			cout << "������ ����������� ���!" << endl;
	}
	void deleteField(vector<Abiturient>& obj) { //�������� ����
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
	}

	void searchBySurname(vector<Abiturient>& obj) {
		cout << "������� ������� : ";
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
			cout << "������ ����������� ���!" << endl;
	}
	void searchByName(vector<Abiturient>& obj) {
		cout << "������� ��� : ";
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
			cout << "������ ����������� ���!" << endl;
	}
	void searchByYearOfBirth(vector<Abiturient>& obj) {
		cout << "������� ��� �������� : ";
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
			cout << "������ ����������� ���!" << endl;
	}
	void searchBySchoolNum(vector<Abiturient>& obj) {
		cout << "������� ����� ����� : ";
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
			cout << "������ ����������� ���!" << endl;
	}
	void searchByAverageScore(vector<Abiturient>& obj) {
		cout << "������� ��� �������� : ";
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
			cout << "������ ����������� ���!" << endl;
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
			cout << "������ �������� �����!" << endl;
		}
		read.close();
	}

	void heading() {
		cout<<"\n\t\t\t\t�� �����������"<<"\n"
			<< setw(5) << left << "\nID" << setw(10) << "�������" << setw(10) << "���"
			<< setw(15) << "��� ��������" << setw(14) << "����� �����"
			<< setw(15) << "������� ����" << endl;
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

	int m;//���������� ���� ��� switch
	do {
		cout << "\n1 - �������� ������" << endl;
		cout << "2 - ����� ������ " << endl;
		cout << "3 - ������������� ������ " << endl;
		cout << "4 - ������� ������" << endl;
		cout << "5 - �����" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �������� : ";
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