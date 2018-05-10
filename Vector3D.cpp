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
