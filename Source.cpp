#include <fstream>
#include "Employee.h"
int main()
{
	int n;
	int k=0;	
	Employee* es;
	in_file >> n;
	es = new Employee[n];
	for (int i = 0; i < n; i++)
	{
		in_file >> es[i].name >> es[i].sname >> es[i].age >> es[i].salary >> es[i].address;
	}
	for (int i = 0; i < n; i++)
	{
		es[i].print();
	}
	while (true)
	{
		cout << "Enter:\n1-Print\n2-Search\n3-Delete\n4-Edit\n5-Filter by age\n6-Filter by first letter of surname\n0-Save and Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			for (int i = 0; i < n; i++)
			{
				es[i].print();
			}
			break;
		case 2: search(es, n);
			break;
		case 3: search(es, n,2);
			break;
		case 4: search(es, n,1);
			break;
		case 5: filter_age(es, n);
			break;
		case 6: filter_by_sname(es, n);
			break;
		}
		if (k == 0)
		{
			save_all(es, n);
			break;
		}

	}
	
	system("pause");
	return 0;
}