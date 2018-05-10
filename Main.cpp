#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include "Vector3D.h"

using namespace std;

int char_to_num(char op[])
{
	int len = strlen(op) + 1;
	int num = 0;
	for (int i = 0; i < len - 1; i++)
	{
		if (op[i] == '*') continue;
		int ch = op[i] - '0';
		num = num * 10 + ch;
	}
	return num;
}

Vector3D add_vectors(Vector3D vec[], int n)
{
	Vector3D temp;
	for (int i = 0; i < n; i++)
	{
		temp = temp + vec[i];
	}
	return temp;
}

Vector3D substract_vectors(Vector3D vec[], int n)
{
	Vector3D temp = vec[0];
	for (int i = 1; i < n; i++)
	{
		temp = temp - vec[i];
	}
	return temp;
}

void negate(Vector3D vec[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << -vec[i];
	}
}

void multNUM(Vector3D vec[], int n, char num[])
{
	int number = char_to_num(num);
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] * number;
	}
}

void NUMmult(Vector3D vec[], int n, char num[])
{
	int number = char_to_num(num);
	for (int i = 0; i < n; i++)
	{
		cout << number * vec[i];
	}
}

int main()
{

		char operation[5];
		int n;
	
		cin >> operation;
		cin >> n;
	
		//zapazvame si purviq simvol ot operaciqta, koeto shte ni trqbva za switch/case-a
		char first_symbol = operation[0];
	
		Vector3D* vecs;
		vecs = new Vector3D[n];
		assert(vecs != NULL);
	
		for (int i = 0; i < n; i++)
		{
			cin >> vecs[i];
		}
	
		switch (first_symbol)
		{
		case '+':
			cout << add_vectors(vecs, n) << endl;
			break;
		case '-':
			cout << substract_vectors(vecs, n)<<endl;
			break;
		case 'N':
			negate(vecs, n);
			break;
		case '*':
			multNUM(vecs, n, operation);
			break;
		default:
			NUMmult(vecs, n, operation);
			break;
		}
	
		delete[]vecs;

	system("pause");
	return 0;
}