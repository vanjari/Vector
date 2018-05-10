#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = y = z = 0;
}

Vector3D::Vector3D(double x, double y, double z):x(x), y(y), z(z) 
{}

Vector3D::~Vector3D()
{
	//cout << "~Vector3D "<< getX() << " " << getY() << " " << getZ() << endl;
}

double Vector3D::getX() const
{
	return x;
}

double Vector3D::getY() const
{
	return y;
}

double Vector3D::getZ() const
{
	return z;
}

Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D newVector(x + secondVector.x, y + secondVector.y, z + secondVector.z);
	return newVector;
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D newVector(x - secondVector.x, y - secondVector.y, z - secondVector.z);
	return newVector;
}

Vector3D Vector3D::operator-() const
{
	Vector3D newVector(-1 * x, -1 * y, -1 * z);
	return newVector;
}

Vector3D Vector3D::operator*(double number) const
{
	Vector3D newVector(x*number, y*number, z*number);
	return newVector;
}

Vector3D operator*(double number, const Vector3D & vector)
{
	Vector3D newVector(vector.x * number, vector.y * number, vector.z * number);
	return newVector;
}

std::istream & operator >> (std::istream & iStream, Vector3D & vector)
{
	char open, comma1, comma2, close;
	iStream >> open >> vector.x >> comma1 >> vector.y >> comma2 >> vector.z >> close;
	return iStream;
}

 std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector)
{
	 oStream << "(" << vector.getX() << "," << vector.getY() << "," << vector.getZ() << ") ";
	return oStream;
}

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
