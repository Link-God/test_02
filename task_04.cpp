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

void spiral(int ** matrix,unsigned int str_t, unsigned int col_t, unsigned int str_size, unsigned int col_size, int i1 ,int j1 , int & q)
{
	int i = i1, j = j1;
	int inext = i1, jnext = j1;
	int count_vnesh_elemets = (2 * str_size + 2 * (col_size - 2));
	for (int h = 0; h < count_vnesh_elemets; h++, q++)
	{
		if (i ==i1 )
		{
			if (j < col_t - 1)
			{
				matrix[i][j] = q;
				jnext++;
			}
			else
			{
				matrix[i][j] = q;
				inext++;
			}
		}
		else
		{
			if ((j == col_t - 1) && (inext < str_t - 1))
			{
				matrix[i][j] = q;
				inext++;
			}
			else
			{
				if (jnext > j1)
				{
					matrix[i][j] = q;
					jnext--;
				}
				else
				{
					matrix[i][j] = q;
					inext--;
				}
			}
		}
		i = inext; j = jnext;
	}
}

int main()
{
	unsigned int str, col;
	bool suc_creat = false;
	int **matrix = nullptr;
	if (read_numb_elements(str, col))
	{
		matrix = creat(str, col);
		suc_creat = true;
		int str_t = str, col_t = col;
		int str_size = str, col_size = col;
		int i1=0, j1=0,q=1;
		while (str_size > 0 && col_size > 0)
		{
			
			if (str_size == 1 && col_size == 1)
			{
				int I = str / 2;
				int J = col / 2;
				matrix[I][J] = str*col;
			}
			else
			{
				spiral(matrix,str_t, col_t,str_size,col_size,i1,j1,q);
			}
			str_t -- ; col_t--;
			str_size -= 2; col_size -= 2;
			i1++; j1++;
		}
		print(matrix, str, col);
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
