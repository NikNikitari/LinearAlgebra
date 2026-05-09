#include <LinearAlgebra3D.hpp>
#include <initializer_list>
#include <stdexcept>

Vector3D::Vector3D(): x(0), y(0), z(0) {}
Vector3D::Vector3D(float vector[3]):x(vector[0]), y(vector[1]), z(vector[2]) {}
Vector3D::Vector3D(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
Vector3D::Vector3D(std::initializer_list<float> vector) {
	if (vector.size() != 3) throw std::invalid_argument("Vector must be size 3");
	x = *vector.begin();
	y = *(vector.begin() + 1);
	z = *(vector.begin() + 2);
}

float Vector3D::operator[](int index) const {
	if (index == 0) return x;
    if (index == 1) return y;
	if (index == 2) return z;
    throw std::out_of_range("Index out of range");
}

const bool Vector3D::operator==(const Vector3D &vector) const {
	return x == vector[0] && y == vector[1] && z == vector[2];
}
const bool Vector3D::operator!=(const Vector3D &vector) const {
	return !(*this == vector);
}

Vector3D Vector3D::operator+(const Vector3D &vector) {
	return Vector3D(x + vector[0], y + vector[1], z + vector[2]);
}
float Vector3D::operator*(const Vector3D &vector) {
	return x * vector[0] + y * vector[1] + z * vector[2];
}
Vector3D operator*(float scalar, const Vector3D &vector) {
	return Vector3D(scalar * vector[0], scalar * vector[1], scalar * vector[2]);
}

Matrix3D::Matrix3D(): matrix{} {}
Matrix3D::Matrix3D(float _matrix[3][3]) {
	matrix[0] = _matrix[0][0];
	matrix[1] = _matrix[1][0];
	matrix[2] = _matrix[2][0];
	matrix[3] = _matrix[0][1];
	matrix[4] = _matrix[1][1];
	matrix[5] = _matrix[2][1];
	matrix[6] = _matrix[0][2];
	matrix[7] = _matrix[1][2];
	matrix[8] = _matrix[2][2];
}
Matrix3D::Matrix3D(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8) {
	matrix[0] = a0;
	matrix[1] = a1;
	matrix[2] = a2;
	matrix[3] = a3;
	matrix[4] = a4;
	matrix[5] = a5;
	matrix[6] = a6;
	matrix[7] = a7;
	matrix[8] = a8;
}
Matrix3D::Matrix3D(std::initializer_list<std::initializer_list<float>> _matrix) {
	if (_matrix.size() != 3) throw std::invalid_argument("Matrix must be 3x3");
	
	int y = 0;
	for (std::initializer_list<float> row : _matrix) {
		if (row.size() != 3) throw std::invalid_argument("Matrix must be 3x3");
		
		int x = 0;
		for (float number : row) matrix[y * 3 + x++] = number;
		++y;
	}
}

float Matrix3D::operator[](int index) const {
	if (index > 8 || index < 0) throw std::out_of_range("Index out of range");
	return matrix[index];
}
float Matrix3D::operator()(int x, int y) const {
	if (x > 2 || y > 2 || x < 0 || y < 0) throw std::out_of_range("Index out of range");
	return matrix[x+y*3];
}

const bool Matrix3D::operator==(const Matrix3D &_matrix) const {
	return 
	matrix[0] == _matrix[0] && 
	matrix[1] == _matrix[1] && 
	matrix[2] == _matrix[2] && 
	matrix[3] == _matrix[3] && 
	matrix[4] == _matrix[4] && 
	matrix[5] == _matrix[5] && 
	matrix[6] == _matrix[6] && 
	matrix[7] == _matrix[7] && 
	matrix[8] == _matrix[8];
}
const bool Matrix3D::operator!=(const Matrix3D &_matrix) const {
	return !(*this == _matrix);
}

Matrix3D Matrix3D::operator+(const Matrix3D &_matrix) {
	return Matrix3D(
		matrix[0] + _matrix[0], matrix[1] + _matrix[1], matrix[2] + _matrix[2], 
		matrix[3] + _matrix[3], matrix[4] + _matrix[4], matrix[5] + _matrix[5], 
		matrix[6] + _matrix[6], matrix[7] + _matrix[7], matrix[8] + _matrix[8]
	);
}
Matrix3D Matrix3D::operator*(const Matrix3D &_matrix) {
	return Matrix3D(
		matrix[0] * _matrix[0] + matrix[1] * _matrix[3] + matrix[2] * _matrix[6],
		matrix[0] * _matrix[1] + matrix[1] * _matrix[4] + matrix[2] * _matrix[7],
		matrix[0] * _matrix[2] + matrix[1] * _matrix[5] + matrix[2] * _matrix[8],
		matrix[3] * _matrix[0] + matrix[4] * _matrix[3] + matrix[5] * _matrix[6],
		matrix[3] * _matrix[1] + matrix[4] * _matrix[4] + matrix[5] * _matrix[7],
		matrix[3] * _matrix[2] + matrix[4] * _matrix[5] + matrix[5] * _matrix[8],
		matrix[6] * _matrix[0] + matrix[7] * _matrix[3] + matrix[8] * _matrix[6],
		matrix[6] * _matrix[1] + matrix[7] * _matrix[4] + matrix[8] * _matrix[7],
		matrix[6] * _matrix[2] + matrix[7] * _matrix[5] + matrix[8] * _matrix[8]
	);
}
Vector3D Matrix3D::operator*(const Vector3D &vector) {
	return Vector3D(
		matrix[0] * vector[0] + matrix[1] * vector[1] + matrix[2] * vector[2], 
		matrix[3] * vector[0] + matrix[4] * vector[1] + matrix[5] * vector[2], 
		matrix[6] * vector[0] + matrix[7] * vector[1] + matrix[8] * vector[2]
	);
}
Matrix3D operator*(float scalar, const Matrix3D& matrix) {
	return Matrix3D(
		scalar * matrix[0], 
		scalar * matrix[1], 
		scalar * matrix[2], 
		scalar * matrix[3], 
		scalar * matrix[4], 
		scalar * matrix[5], 
		scalar * matrix[6], 
		scalar * matrix[7], 
		scalar * matrix[8]  
	);
}

float Matrix3D::det() {
	return 
	matrix[0] * matrix[4] * matrix[8] +
	matrix[1] * matrix[5] * matrix[6] +
	matrix[2] * matrix[3] * matrix[7] -
	matrix[2] * matrix[4] * matrix[6] -
	matrix[0] * matrix[5] * matrix[7] -
	matrix[1] * matrix[3] * matrix[8];
}