// исправил ошибку не квадратных матриц
// позже исправил если сдвиг больше размера строки или столбца
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

void spiral(int ** matrix, unsigned int str_t, unsigned int col_t, unsigned int str_size, unsigned int col_size, int i1, int j1, int sdvig)
{
	int i = i1, j = j1;
	int inext = i1, jnext = j1;
	int count_vnesh_elemets = (2 * str_size + 2 * (col_size - 2));
	int count_sdvig = sdvig % count_vnesh_elemets;
	for (int q = 0; q < count_sdvig; q++)
	{
		unsigned int i = i1, j = i1;
		int inext = i, jnext = j;
		int t1_elemetn = matrix[i][j];
		for (int h = 0; h < count_vnesh_elemets; h++)
		{
			if (i == i1)
			{
				if (j < col_t - 1)
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
				if ((j == col_t - 1) && (inext < str_t - 1))
				{

					inext++;
				}
				else
				{
					if (jnext > j1)
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

void revers(int * array, int size)
{
	unsigned int k = size - 1;
	for (int i = 0; i < (size / 2); i++)
	{
		swap(array[i], array[k]);
		k--;
	}
}

void revers_two(int * array, int size, int sdvig)
{
	unsigned int k = size - 1;
	for (int i = sdvig; i < ((size - sdvig) / 2) + sdvig; i++)
	{

		swap(array[i], array[k]);
		k--;
	}
}

bool read_str(int * array, int size)
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

void print_str(int * array, int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

void print_martix_str(int * array, unsigned int col, int sdvig)
{
	revers(array, sdvig);
	revers_two(array, col, sdvig);
	revers(array, col);
	print_str(array, col);
	cin.get();
}

void print_matrix_col(int ** matrix, unsigned int col, unsigned int str, int sdvig)
{
	for (int i = sdvig; i < str; i++)
	{
		cout << endl;
		for (unsigned int j = 0; j < col; j++)
		{
			cout << matrix[i][j];
		}
	}

	for (int i = 0; i < sdvig; i++)
	{
		cout << endl;
		for (unsigned int j = 0; j <col; j++)
		{
			cout << matrix[i][j];
		}
	}
}

int main()
{
	unsigned int str, col;
	int sdvig;
	bool suc_creat = false;
	int **matrix = nullptr;
	if (read_numb_elements(str, col) && str>0 && col > 0)
	{
		if (str == 1 || col == 1)
		{
			if (str == 1 && col == 1)
			{
				int element;
				cin >> element;
				cin.get();
				if (read_sdvig(sdvig))
				{
					cout << element;
				}
				else { cout << "fail input"; }
			}
			else if (str == 1)
			{
				int * array;
				array = new int[col];
				if (read_str(array, col) && read_sdvig(sdvig))
				{
					sdvig = sdvig % col;
					print_martix_str(array, col, sdvig);
				}
				else
				{
					cout << "fail input ";
				}
				delete[] array;
			}
			else if (col == 1)
			{
				matrix = creat(str, col);
				if (read(matrix, str, col) && read_sdvig(sdvig))
				{
					suc_creat = true;
					sdvig = sdvig % str;
					print_matrix_col(matrix, col, str, sdvig);
				}
				else
				{
					cout << "fail input";
				}
			}
		}
		else
		{
			matrix = creat(str, col);
			if (read(matrix, str, col) && read_sdvig(sdvig))
			{
				suc_creat = true;
				int str_t = str, col_t = col;
				int str_size = str, col_size = col;
				int i1 = 0, j1 = 0;
				while (str_size > 0 && col_size > 0)
				{

					if (str_size == 1 || col_size == 1)
					{
						if (str_size == 1 && col_size == 1){ }
						else if (str_size == 1)
						{
							sdvig = sdvig % col_size;
							int * array;
							array = new int[col_size];
							for (int b = 0; b < col_size; b++) { array[b] = matrix[i1][j1+b]; }
							revers(array, sdvig);
							revers_two(array, col_size, sdvig);
							revers(array, col_size);
							for (int b = 0; b < col_size; b++) { matrix[i1][j1 + b]=array[b]; }
							delete[] array;
						}
						else if (col_size == 1)
						{
							sdvig = sdvig % str_size;
							int * array;
							array = new int[str_size];
							for (int b = 0; b < str_size; b++) { array[b] = matrix[i1+b][j1]; }
							revers(array, sdvig);
							revers_two(array, str_size, sdvig);
							revers(array, str_size);
							for (int b = 0; b < str_size; b++) { matrix[i1+b][j1] = array[b]; }
							delete[] array;
						}
					}
					else
					{
						spiral(matrix, str_t, col_t, str_size, col_size, i1, j1, sdvig);
					}
					str_t--; col_t--;
					str_size -= 2; col_size -= 2;
					i1++; j1++;
				}
				print(matrix, str, col);
			}
			else
			{
				cout << "fail input";
			}
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
