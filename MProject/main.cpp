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
	string surname;		//�������
	string name;		//���
	int yearOfBirth;	//��� ��������
	int schoolNumber;	//����� �����
	int averageScore;	//������� ����
	static void countID() { id++; }
public:
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
		cout << "\n������� ID ����������� : ";
		int temp;
		cin >> temp;
		for (int i = 0; i < obj.size(); i++) {
			if (temp == obj[i].id) {
				obj[i].addField();
				obj.insert(obj.begin() + i, obj[i]);
			}
		}
	}
	void deleteField() { //�������� ����
	
	}
	void heading() {
		cout << setw(5) << left << "ID" << setw(10) << "�������" << setw(10) << "���"
			<< setw(15) << "��� ��������" << setw(14) << "����� �����"
			<< setw(15) << "������� ����" << endl;
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

	int m;//���������� ���� ��� switch
	do {
		cout << "1 - �������� ������" << endl;
		cout << "2 - ����� ������ " << endl;
		cout << "3 - ������������� ������ " << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �������� : ";
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
	cout << "������� ���-�� ��������� : ";
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
