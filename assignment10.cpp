#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

typedef struct student
{
	int roll;
	char a, name[20], add[30];
}
stud;

void create();
void display();
void insert();
void search(int key);
void deletem(int key);
void modify(int key);

int main()
{
	int ch, x;
	do {
		cout << "\n\t----------------|MENU|---------------- " << endl << "\n1.Accept\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Modify\n7.Exit\nEnter your choice:- ";
		cin >> ch;
		switch (ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insert();
				break;
			case 4:
				cout << "Enter roll no. to search:- ";
				cin >> x;
				search(x);
				break;
			case 5:
				cout << "Enter roll no. to delete:- ";
				cin >> x;
				deletem(x);
				break;
			case 6:
				cout << "Enter roll no to modify:- ";
				cin >> x;
				modify(x);
				break;
		}
	} while (ch != 7);
	return 0;
}

ifstream fin;
ofstream fout;
fstream fm;
int n;
char fname[20];

void create()
{
	int i;
	stud s;
	cout << "Enter the name of file:- ";
	cin >> fname;
	fm.open(fname, ios::out);
	cout << "Enter no. of records:- ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Enter the roll no:- ";
		cin >> s.roll;
		cout << "Enter the name:- ";
		cin >> s.name;
		cout << "Enter division:- ";
		cin >> s.a;
		cout << "Enter address:- ";
		cin >> s.add;
		fm.write((char*) &s, sizeof(s));
	}
	fm.close();
}

void display()
{
	int i;
	stud s;
	fin.open(fname);
	cout << "\n Roll no\tNAME\tDIV\tADDRESS";

	for (i = 0; i < n; i++)
	{
		fin.read((char*) &s, sizeof(s));
		cout << "\n" << s.roll << "\t" << s.name << "\t" << s.a << "\t" << s.add;
	}
	fin.close();
}

void insert()
{
	stud s;
	fout.open(fname, ios::app);
	cout << "Enter the roll no:- ";
	cin >> s.roll;
	cout << "Enter the name:- ";
	cin >> s.name;
	cout << "Enter the division:- ";
	cin >> s.a;
	cout << "Enter the address:- ";
	cin >> s.add;
	fout.write((char*) &s, sizeof(s));
	n++;
	fout.close();
}

void search(int key)
{
	stud s;
	int flag = 0, i;
	fin.open(fname);
	for (i = 0; i < n; i++)
	{
		fin.read((char*) &s, sizeof(s));
		if (s.roll == key)
		{
			cout << "\nRecord is present their corresponding details are:\nRoll no: ";
			cout << s.roll << "\nName: " << s.name << "\nDivision: " << s.a << "\nAddress: " << s.add;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\nRoll no: " << key << "is not present in your records";
	fin.close();
}

void deletem(int key)
{
	stud s;
	int flag = 0, i;
	fin.open(fname);
	fout.open("temp.txt", ios::out);

	for (i = 0; i < n; i++)
	{
		fin.read((char*) &s, sizeof(s));
		if (s.roll == key)
		{
			cout << "\nRecord deleted successfully";
			flag = 1;
		}
		else
		{
			fout.write((char*) &s, sizeof(s));
		}
	}
	if (flag == 0)
			cout << "\nRoll no=" << key << "is not present in the record";
		else
			n--;
		fin.close();
		fout.close();
		remove(fname);
		rename("temp.txt", fname);
}

void modify(int key)
{
	stud s;
	int flag = 0, i;
	fin.open(fname);
	fout.open("temp.txt", ios::out);

	for (i = 0; i < n; i++)
	{
		fin.read((char*) &s, sizeof(s));
		if (s.roll == key)
		{
			cout << "Enter the roll no:- ";
			cin >> s.roll;
			cout << "Enter the name:- ";
			cin >> s.name;
			cout << "Enter the division:- ";
			cin >> s.a;
			cout << "Enter the address:- ";
			cin >> s.add;
			fout.write((char*) &s, sizeof(s));
			flag = 1;
		}
		else
		{
			fout.write((char*) &s, sizeof(s));
		}
	}
	if (flag == 0)
		cout << "\nRoll no=" << key << "is not present in the records";
	fin.close();
	fout.close();

	remove(fname);
	rename("temp.txt", fname);
}
