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
		cout << "Ошибка открытия файла!";
		exit(0);
	}
	else
	{
		string name, phone;
		cout << "Введите имя: "; cin >> name;
		cout << "Введите номер: "; cin >> phone;
		f << phone << endl;
		f << name << endl;
		f.close();
		cout << "Данные сохранены!" << endl;
		//1)Сейчас реализована запись имени и номера в файл. 
		//Следующим шагом надо реализовать запись новых данных, а не перезапись старых
		//Это реализуется с помощью команды ios_base::app (append  - к существующим данным добавляются новые)
	}
	
}

void searchInFile()
{
	cout << "Введите строку для поиска: ";
	string str;
	cin >> str;
	ifstream f("phones.txt");
	if (f.is_open() != true)
	{
		cout << "Ошибка открытия файла!";
		exit(0);
	}
	else
	{
		//алгоритм поиска
		string name, phone;
		bool flag = false;
		while (f.eof() != true)
		{
			f >> phone;
			f >> name;
			//извлекаем из файла номер и имя
			//после этого надо проверить - есть ли такие номер/имя в книге
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
			//написанный алгоритм работает ТОЛЬКО для первых двух строк
		}
		f.close();
		if (flag == false)
		{
			cout << "Совпадений не найдено!" << endl;
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
	cout << "Введите строку для удаления: " << endl;
	string str;
	cin >> str;
	ifstream f("phones.txt");
	if (f.is_open() != true)
	{
		cout << "Ошибка открытия файла!" << endl;
		exit(0);
	}
	else 
	{
		//алгоритм поиска
		string name, phone;
		bool flag = false;
		while (f.eof() != true)
		{
			phone.clear();
			f >> phone;
			f >> name;
			//извлекаем из файла номер и имя
			//после этого надо проверить - есть ли такие номер/имя в книге
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
			//написанный алгоритм работает ТОЛЬКО для первых двух строк
		}
		f.close();
		if (flag == false)
		{
			cout << "Совпадений не найдено!" << endl;
		}
		else
		{
			ofstream fout("phones.txt");
			fout << result;
			fout.close();
			cout << "Данные удалены!" << endl;
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
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
	fin.close();
}