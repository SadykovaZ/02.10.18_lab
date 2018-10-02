#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
fstream in_file("in.txt",ios::in);
ofstream out_file("out.txt");

struct Employee
{
	string name;
	string sname;
	int age;
	double salary;
	string address;
	void change()
	{
		cout << "Which data you want to change: " << endl;
		cout << "1.Name\n2.Age\n3.Salary\n4.Address\n5.Surname" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1: cin >> name;
			break;
		case 2: cin >> age;
			break;
		case 3: cin >> salary;
			break;
		case 4: cin >> address;
			break;
		case 5: cin >> sname;
			break;
		}

	}

	void add()
	{
		cin >> name >> sname >> age >> salary >> address;
	}
	void print()
	{
		cout << name << " " << sname << " " << age << " " << salary << " " << address << endl;
	}
	void save_in_file()
	{
		out_file << name << " " << sname << " " << age << " " << salary << " " << address << endl;

	}

};

void save_all(Employee * es, int n) {
	in_file.close();
	in_file.open("in.txt", ios::out);
	in_file << n << endl;
	for (int i = 0; i < n; i++)
	{
		in_file << es[i].name << " " << es[i].sname << " " << es[i].age << " " << es[i].salary << " " << es[i].address << endl;
	}

}

void del(Employee*&es, int &n, int s)
{
	Employee* tmp;
	tmp = new Employee[n - 1];
	for (int i = 0, j = 1; i < n - 1; i++, j++)
	{
		if (i < s)	tmp[i] = es[i];
		else tmp[i] = es[j];
	}
	delete[] es;
	es = tmp;
	n--;
}
void search(Employee* &es, int &n, int k = 0)
{
	string spoisk;
	int z = 1;
	int x;
	cout << "Enter surname: ";
	cin >> spoisk;
	for (int i = 0; i < n; i++)
	{
		if (es[i].sname == spoisk)
		{
			cout << "Found." << endl;
			if (k == 0)
			{
				cout << "1-change, 2-delete, 3-exit" << endl;
				cin >> x;
			}
			else
				x = k;
			switch (x)
			{
			case 1: es[i].change();
				break;
			case 2: del(es, n, i);
				break;
			}
			z = 1;
			break;
		}
		else z = 0;
	}
	if (z == 0) cout << "Not Found." << endl;
}
void filter_age(Employee* es, int n)
{
	int age;
	int x;
	cout << "Enter age: ";
	cin >> age;
	for (int i = 0; i < n; i++)
	{
		if (es[i].age == age)
			es[i].print();
	}
	cout << "Save data: (1-yes) ";
	cin >> x;
	if (x == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (es[i].age == age)
				es[i].save_in_file();
		}
	}
}
void filter_by_sname(Employee* es, int n)
{
	char letter;
	int x;
	cout << "Enter first letter: ";
	cin >> letter;
	for (int i = 0; i < n; i++)
	{
		if (es[i].sname[0] == letter)
			es[i].print();
	}
	cout << "Save data: (1-yes) ";
	cin >> x;
	if (x == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (es[i].sname[0] == letter)
				es[i].save_in_file();
		}

	}
}
