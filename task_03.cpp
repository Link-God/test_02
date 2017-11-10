#include"stdafx.h"
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

bool read_numb_elements(unsigned int &str, unsigned int &col)
{
	string razmer;
	char op; bool sucsses = true;
	unsigned int str_t, col_t;
	getline(cin, razmer);
	istringstream stream(razmer);
	if (stream >> str_t && stream >> op && op == ',' && stream >> col_t) {
		str = str_t;
		col = col_t;

		return true;;
	}

	return false;
}

bool read(int **matrix, unsigned int str, unsigned  int col)
{
	int read_matrix_numb = 0;
	for (unsigned int i = 0; i < str; i++)
	{
		string row;
		getline(cin, row);
		istringstream stream(row);
		for (unsigned int j = 0; j < col; j++)
		{
			if (stream >> matrix[i][j]) { read_matrix_numb++; }
		}
	}
	if (read_matrix_numb == str*col) return true;
	else return false;
}

void print(int **matrix, unsigned int str, unsigned int col)
{
	for (unsigned int i = 0; i < str; i++)
	{
		cout << endl;
		for (unsigned int j = 0; j < col; j++)
		{
			if (matrix[i][j] == -0.0) { cout << 0 << " "; }
			else { cout << matrix[i][j] << " "; }
		}
	}
}
void del(int ** matrix, unsigned int str)
{
	for (unsigned int i = 0; i < str; i++)
	{
		delete[] matrix[i];
	}
	delete matrix;
}
int** creat(unsigned int str, unsigned int col)
{
	int ** mat = new int*[str];
	for (unsigned int i = 0; i < str; i++)
	{
		mat[i] = new int[col];
	}
	return mat;
}

void spiral(int ** matrix, unsigned int str, unsigned int col, int sdvig)
{
	
	int count_vnesh_elemets = (2 * str + 2 * (col - 2));
	int count_sdvig = sdvig % count_vnesh_elemets;
	for (int q = 0; q < count_sdvig; q++)
	{
		int i = 0, j = 0;
		int inext = i, jnext = j;
		int t1_elemetn = matrix[i][j];
		for (int h = 0; h <count_vnesh_elemets; h++)
		{
			if (i == 0)
			{
				if (j < col - 1)
				{
					jnext++;
				}
				else
				{
					inext++;
				}
			}
			else
			{
				if ((j == col - 1) && (inext < str - 1))
				{
					inext++;
				}
				else
				{
					if (jnext > 0)
					{
						jnext--;
					}
					else
					{
						inext--;
					}
				}
			}
			int t2_element = matrix[inext][jnext];
			matrix[inext][jnext] = t1_elemetn;
			t1_elemetn = t2_element;
			i = inext; j = jnext;
		}
	}
}

bool read_sdvig(int &sdvig)
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
	unsigned int str, col;
	int sdvig; 
	bool suc_creat=false;
	int **matrix = nullptr;
	if (read_numb_elements(str, col))
	{
		matrix = creat(str, col);
		if (read(matrix, str, col) && read_sdvig(sdvig))
		{
			suc_creat = true;
			spiral(matrix, str, col, sdvig);
			print(matrix, str, col);
		}
		else 
		{
			cout << "fail input";
		}
	}
	else 
	{
		cout << "fail input";
	}
	if (suc_creat)
	{
		del(matrix, str); 
	}
	cin.get();
    return 0;
}
