#include "stdafx.h"
#include<iostream>
#include<sstream>

using namespace std;

void revers(int * array, int size)
{
	unsigned int k = size - 1;
	for (int i = 0; i < (size / 2) ; i++)
	{
		swap(array[i], array[k]);
		k--;
	}
}
void revers_two(int * array, int size,int sdvig)
{
	unsigned int k = size - 1;
	for (int i = sdvig; i < ((size - sdvig) / 2) + sdvig ; i++)
	{

		swap(array[i], array[k]);
		k--;
	}
}
bool read(int * array, int size)
{
	string mas;
	unsigned int i = 0, array_count = 0;
	getline(cin, mas);
	istringstream stream(mas);
	for (i; i < size; i++)
	{
		if (stream >> array[i])
		{
			array_count++;
		}
	}
	if (array_count == size && stream.eof()) return true;
	else return false;
}
void print(int * array, int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

bool size_s(int &size)
{
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (!(stream >> size))
	{
		return false;
	}
	else
	{
		if (stream.eof()) { return true; }
		else { return false; }
	}
}
bool sdv (int &sdvig)
{
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (!(stream >> sdvig))
	{
		return false;
	}
	else
	{
		if (stream.eof()) { return true; }
		else { return false; }
	}
}
int main()
{
	int size,sdvig;
	if (size_s(size) && size > 0 )
	{
		int * array;
		array = new int[size];
		if (read(array, size)&& sdv(sdvig))
		{
			revers(array, sdvig); 
			revers_two(array, size, sdvig);
			revers(array, size); 
			print(array, size);
			cin.get();
		}
		else
		{
			cout << "fail input ";
			cin.get();
		}
		delete[] array;
	}
	else { cout << "size error"; cin.get(); }
	return 0;
}
