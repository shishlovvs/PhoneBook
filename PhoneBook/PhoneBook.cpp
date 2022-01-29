#include<iostream>
#include<fstream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void addToFile();
void searchInFile();
string strToLower(string str);
void delInFile();
void loadFromFile();

void main()
{
	setlocale(LC_ALL, "ru");
	addToFile();
	searchInFile();
	//string strToLower();
	delInFile();
	loadFromFile();
	
}

void addToFile()
{
	ofstream f("phones.txt", ios_base::app);
	if (f.is_open() != true)
	{
		cout << "������ �������� �����!";
		exit(0);
	}
	else
	{
		string name, phone;
		cout << "������� ���: "; cin >> name;
		cout << "������� �����: "; cin >> phone;
		f << phone << endl;
		f << name << endl;
		f.close();
		cout << "������ ���������!" << endl;
		//1)������ ����������� ������ ����� � ������ � ����. 
		//��������� ����� ���� ����������� ������ ����� ������, � �� ���������� ������
		//��� ����������� � ������� ������� ios_base::app (append  - � ������������ ������ ����������� �����)
	}
	
}

void searchInFile()
{
	cout << "������� ������ ��� ������: ";
	string str;
	cin >> str;
	ifstream f("phones.txt");
	if (f.is_open() != true)
	{
		cout << "������ �������� �����!";
		exit(0);
	}
	else
	{
		//�������� ������
		string name, phone;
		bool flag = false;
		while (f.eof() != true)
		{
			f >> phone;
			f >> name;
			//��������� �� ����� ����� � ���
			//����� ����� ���� ��������� - ���� �� ����� �����/��� � �����
			if (phone.find(str) != string::npos)
			{
				cout << phone << " " << name << endl;
				flag = true;
			}
			else if (strToLower(name).find(strToLower(str)) != string::npos)
			{
				cout << phone << " " << name << endl;
				flag = true;
			}
			//���������� �������� �������� ������ ��� ������ ���� �����
		}
		f.close();
		if (flag == false)
		{
			cout << "���������� �� �������!" << endl;
		}
	}
}

string strToLower(string str)
{
	string search = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string replace = "abcdefghijklmnopqrstuvwxyz";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		for (unsigned int j = 0; j < search.length(); j++)
		{
			if (str[i] == search[j])
			{
				str[i] = replace[j];
			}
		}
	}
	return str;
}

void delInFile()
{
	string result = " ";
	cout << "������� ������ ��� ��������: " << endl;
	string str;
	cin >> str;
	ifstream f("phones.txt");
	if (f.is_open() != true)
	{
		cout << "������ �������� �����!" << endl;
		exit(0);
	}
	else 
	{
		//�������� ������
		string name, phone;
		bool flag = false;
		while (f.eof() != true)
		{
			phone.clear();
			f >> phone;
			f >> name;
			//��������� �� ����� ����� � ���
			//����� ����� ���� ��������� - ���� �� ����� �����/��� � �����
			if (phone==str)
			{
				flag = true;
			}
			else
			{
				if (phone.length() > 0)
				{
					result += phone + "\n";
					result += name + "\n";
				}
				flag = true;
			}
			//���������� �������� �������� ������ ��� ������ ���� �����
		}
		f.close();
		if (flag == false)
		{
			cout << "���������� �� �������!" << endl;
		}
		else
		{
			ofstream fout("phones.txt");
			fout << result;
			fout.close();
			cout << "������ �������!" << endl;
		}
	}
}

void loadFromFile()
{
	string f("phones.txt");
	ifstream fin;

	fin.open(f);
	
	if (!fin.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
}