#include "Vector3D.h"
#include<string>
#include<cassert>

using namespace std;

int char_to_num(char op[]);
Vector3D substract_vectors(Vector3D vec[], int n);
Vector3D add_vectors(Vector3D vec[], int n);
void negate(Vector3D vec[], int n);
void multNUM(Vector3D vec[], int n, char num[]);
void NUMmult(Vector3D vec[], int n, char num[]);

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