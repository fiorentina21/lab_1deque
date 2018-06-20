// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
//�������� � ������� �������� ������ ���������� �������� �����.
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <deque>   
#include <sstream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <time.h>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

deque <int> de;

int abs_nech();
class class_container_deq
{
private:
	int arithmetical_mean;
	
public:
	class_container_deq(const int& _Val) :arithmetical_mean(_Val) {
	}
	
	int operator ( ) (int& elem) const
	{
		int el = static_cast< int >(elem);
		elem = elem + abs_nech();
		return elem;
	}
};

class random_range
{
private: 
	int M;
public:
	random_range(const int& Value) : M(Value) {
	}
	int operator () () const
	{
		return rand() % (2 * M + 1) - M;
	}
};

int random(int M)
{
	return rand() % (2 * M + 1) - M;
}

// �������� ������������ ������� � ����� �����
bool correct_symbol(char c)										//!!!!!!!!!!!!!
{
	switch (c)
	{
	case '>':
	case ':':
	case '|':
	case '.':
	case '*':
	case '?':
	case '<':
		return false;
	default:
		return true;
	}
}

// �������� ������������ �����
bool correct_name(string name)
{
	int i = 1;
	bool goodsymbol = true;
	for(int i = 1; (i < name.length() && goodsymbol);i++)
		goodsymbol = correct_symbol(name[i++]);
	return goodsymbol;
}

//���� ����� �����
string input_file_name()
{
	char *filename;
	filename = new char[45];

	do
	{
		cout << "������� ��� �����(��� ����������):  ";
		cin >> filename;
		if (correct_name(filename))
		{
			strcat(filename, ".txt");//����������� ����� �������������
			break;
		}
		else
			cout << "���� �� ������� �������\n";
	} while (true);

	return filename;
}

// ���������� ����� ���������� �������
ofstream in_text_file(string filename,int N, int M)
{
	ofstream file(filename);
	deque<int> deq_numbers;
	srand((unsigned int)time(0));
	for (int i = 1; i < N; i++)
		deq_numbers.push_back(random(M));
	copy(deq_numbers.begin(), deq_numbers.end(), ostream_iterator<int>(file," "));
	file.close();
	return file;

}

// ���������� ����� ���������� ������� ����� generate
ofstream in_text_fileIn_generate(string filename,int N, int M)
{
	ofstream file(filename);
	deque<int> deq_numbers(N);
	srand((unsigned int)time(0));
	generate(deq_numbers.begin(), deq_numbers.end(), random_range(M));
	copy(deq_numbers.begin(), deq_numbers.end(), ostream_iterator<int>(file, " "));
	file.close();
	return file;
}

// �������� ����� �� ����� � �������
deque<int> load_from_file(string filename)
{
	ifstream file(filename);
	deque<int> deq_numbers;
	int x;
	while (!file.eof())
	{
		file >> x;
		deq_numbers.push_back(x);
	}
	file.close();

	de = deq_numbers;
	return deq_numbers;
}

// ������ ������� � ����
void PrintFile(string filename,deque<int> &items)
{
	ofstream fout;
	fout.open(filename, ios::out);
	if (fout)
	{
		deque<int>::const_iterator pos;

		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			fout << *pos << ' ';
		}
		fout.close();
	}
	else
	{
		cout << "������ �������� �����!" << endl;
	}
}


// ������ ������� �� �����
void output_screen(deque<int> &items)
{
	deque<int>::const_iterator pos;

	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << *pos << ' ';
	}
}

// �������  ��� ���������� �����
int sum(deque<int> &deq_numbers)
{
	int sum = 0;
	for (auto iter = deq_numbers.begin(); iter != deq_numbers.end(); iter++)
	{
		sum += *iter;
	}
	return sum;
}




// �������  ��� ���������� �������� ��������������� (����� ���������)
double average(deque<int>::iterator begin, deque<int>::iterator end)
{
	int summ = 0;
	int col = 0;
	
	for (auto iter = begin; iter != end; iter++)
	{
		summ += *iter;
		col++;
	}
	if (col == 0)
	{
		col = 1;
	}
	
	return (double)summ / col;
}


// �������  ��� ���������� �������� ���������������
int average(deque<int> &deq_numbers)
{
	return average(deq_numbers.begin(), deq_numbers.end());
}

int abs_nech()
{
		int nech = 0;
	    deque<int> de_mod = de;
		bool flag = true;
		
		while (!de_mod.empty())
		 {
			 if (flag)
			 {
				 if (de_mod.back()%2!=0)
				 {
					 nech =  abs(de_mod.back()); 
				 }
				 
			 }
			 
			  de_mod.pop_back();
			  
		 }
		return nech;
}

// ������������� ������� modify ��� ��������� �������
deque<int> modify(deque<int>::iterator begin, deque<int>::iterator end)
{
		cout<<endl;
		deque<int> modif_Deque;
		deque<int> vs = de;
		bool flag = true;
		//cout << endl << "������ ���������� ��������: " << abs_nech() << endl;
		while (!vs.empty())
		{
			modif_Deque.push_front(vs.back() + abs_nech());
			vs.pop_back();  
		}
		de = modif_Deque;
		return modif_Deque;
}

// ������� modify ��� ��������� �������
deque<int> modify(deque<int> &deq_numbers)
{
	return modify(deq_numbers.begin(), deq_numbers.end());
}

// �������  ��� ��������� ������� ����� transform
deque<int> transform_deque(deque<int> &deq_numbers)
{
	int arithmetical_mean = average(deq_numbers);
	transform(deq_numbers.begin(), deq_numbers.end(), deq_numbers.begin(), class_container_deq(arithmetical_mean));
	return deq_numbers;
}

// �������  ��� ��������� ������� ����� for_each
deque<int> for_each_deque(deque<int> &deq_numbers)
{

	int arithmetical_mean = average(deq_numbers);
	for_each(deq_numbers.begin(), deq_numbers.end(), class_container_deq(arithmetical_mean));
	return deq_numbers;
}



int input_number(int min, int max)
{
	int n;
	do
	{
		cout << "������� ����� ����: ";
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "������������ ���� !!  ��������� �����!\n";
			cin.clear(); 
			cin.sync();
			cout << "��� ����� : ";
			getchar();
			getchar();
		}
	} while ((n < min) || (n > max));
	return n;
}

int menu()
{
	cout << "������ � �����������:" << endl;
	cout << "1 - modify(�������������� �������)" << endl;
	cout << "2 - modify(�������������� ������� - ������������� �������) " << endl;
	cout << "3 - �������������� � ������� transform" << endl;
	cout << "4 - �������������� � ������� for_each" << endl;
	cout << "5 - ��������� �����" << endl;
	cout << "6 - ��������� ������� ��������������" << endl;
	cout << "7 - ����� �� ����� " << endl;
	cout << "8 - ����� � ����" << endl;
	cout << "0 - ����� " << endl;
	int n = input_number(0, 8);
	cout << "\n";
	return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ofstream OutputFile;
	string filename = "";
	deque<int> deq_numbers;
	int N ;
	int M ;
	int changemenu;
	bool enterfile = true;


	cout << " _____________________����___________________  " << endl;
	cout << "1 - ���������� ���������� ����� ���������� �������(����)" << endl;
	cout << "2 - ���������� ���������� ����� ���������� �������(generate) " << endl;
	cout << "0 - �����" << endl;
	changemenu = input_number(0, 2);
	switch (changemenu)
	{
	case 1:
	{
		filename = input_file_name();
		cout << ("������� ����� N") << endl;
		cin >> N;
		cout << ("������� ����� M") << endl;
		cin >> M;
		OutputFile = in_text_file(filename, N, M);
		break;
	}		

	case 2:
	{
		filename = input_file_name();
		cout << ("������� ����� N") << endl;
		cin >> N;
		cout << ("������� ����� M") << endl;
		cin >> M;
		OutputFile =in_text_fileIn_generate(filename, N, M);
		break;
	}
	default:
		enterfile = false;
		break;
	}
	if (enterfile)
	{
		deq_numbers = load_from_file(filename);
		for (;;)
		{
			int n = menu();
			switch (n)
			{
			case 1:
				deq_numbers = modify(deq_numbers);
				break;

			case 2:
				deq_numbers = modify(deq_numbers.begin(), deq_numbers.end());
				break;

			case 3:
				deq_numbers = transform_deque(deq_numbers);
				break;

			case 4:
				deq_numbers = for_each_deque(deq_numbers);
				break;

			case 5:
				cout << "�����: " << sum(deq_numbers) << endl;
				break;

			case 6:
				cout << "������� ��������������: " << average(deq_numbers) << endl;
				break;

			case 7:
				cout << "�������: " << endl;
				output_screen(deq_numbers);
				break;

			case 8:
				PrintFile(filename,deq_numbers);
				break;

			default:
				cout << "����� " << endl; exit(0);
				break;

			}
		}
	}
	else
		cout << "�����\n";
	system("pause");
}
