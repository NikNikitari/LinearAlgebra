#include <LinearAlgebra2D.hpp>
#include <initializer_list>
#include <stdexcept>

Vector2D::Vector2D(): x(0), y(0) {}
Vector2D::Vector2D(float _x, float _y): x(_x), y(_y) {}
Vector2D::Vector2D(float vector[2]) : x(vector[0]), y(vector[1]) {}
Vector2D::Vector2D(std::initializer_list<float> vector) {
	if (vector.size() != 2) throw std::invalid_argument("Vector must be size 2");
	x = *vector.begin();
	y = *(vector.begin() + 1);
}

float Vector2D::operator[](int index) const {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index out of range");
}

const bool Vector2D::operator==(const Vector2D& vector) const {return (vector[0] == x) && (vector[1] == y);}
const bool Vector2D::operator!=(const Vector2D& vector) const {return !(*this == vector);}

Vector2D Vector2D::operator+(const Vector2D &vector) {
	return Vector2D(x+vector[0], y+vector[1]);
}
float Vector2D::operator*(const Vector2D &vector) {
	return x * vector[0] + y * vector[1];
}
Vector2D operator*(float scalar, const Vector2D &vector) {
	return Vector2D(scalar * vector[0], scalar * vector[1]);
}

Matrix2D::Matrix2D(): matrix{0}{}
Matrix2D::Matrix2D(float _matrix[2][2]) {
	matrix[0] = _matrix[0][0];
	matrix[1] = _matrix[0][1];
	matrix[2] = _matrix[1][0];
	matrix[3] = _matrix[1][1];
}
Matrix2D::Matrix2D(float a, float b, float c, float d) {
	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;
	matrix[3] = d;
}
Matrix2D::Matrix2D(std::initializer_list<std::initializer_list<float>> _matrix) {
	if (_matrix.size() != 2) throw std::invalid_argument("Matrix must be 2x2");
	
	int y = 0;
	for (std::initializer_list<float> row : _matrix) {
		if (row.size() != 2) throw std::invalid_argument("Matrix must be 2x2");
		
		int x = 0;
		for (float number : row) matrix[y * 2 + x++] = number;
		++y;
	}
}

float Matrix2D::operator[](int index) const {
	if (index > 3 || index < 0) throw std::out_of_range("Index out of range");
	return matrix[index];
}

float Matrix2D::operator()(int x, int y) const {
	if (x > 1 || y > 1 || x < 0 || y < 0) throw std::out_of_range("Index out of range");
	return matrix[x+y*2];
}

const bool Matrix2D::operator==(const Matrix2D &_matrix) const {
	return (matrix[0] == _matrix[0]) && (matrix[1] == _matrix[1]) && (matrix[2] == _matrix[2]) && (matrix[3] == _matrix[3]);
}
const bool Matrix2D::operator!=(const Matrix2D &_matrix) const {
	return !(*this == _matrix);
}

Matrix2D Matrix2D::operator+(const Matrix2D &_matrix) {
	return Matrix2D(_matrix[0] + matrix[0], _matrix[1] + matrix[1], _matrix(0, 1) + matrix[2], _matrix[3] + matrix[3]);
}
Matrix2D Matrix2D::operator*(const Matrix2D &_matrix) {
	return Matrix2D(
		matrix[0] * _matrix[0] + matrix[1] * _matrix[2],
		matrix[0] * _matrix[1] + matrix[1] * _matrix[3],
		matrix[2] * _matrix[0] + matrix[3] * _matrix[2],
    	matrix[2] * _matrix[1] + matrix[3] * _matrix[3]
	);
}
Vector2D Matrix2D::operator*(const Vector2D &vector) {
	return Vector2D(matrix[0] * vector[0] + matrix[1] * vector[1], matrix[2] * vector[0] + matrix[3] * vector[1]);
}
Matrix2D operator*(float scalar, const Matrix2D &matrix) {
	return Matrix2D(scalar * matrix[0], scalar * matrix[1], scalar * matrix[2], scalar * matrix[3]);
}

float Matrix2D::det() {
	return matrix[0] * matrix[3] - matrix[1] * matrix[2];
}
Matrix2D Matrix2D::transpose() {
	return Matrix2D(matrix[0], matrix[2], matrix[1], matrix[3]);
}
float Matrix2D::minor(int i, int j) {
	if (i > 1 || j > 1 || i < 0 || j < 0) throw std::out_of_range("Index out of range");
	return matrix[(i ? 0 : 1) + (j ? 0 : 2)];
}
float Matrix2D::cofactor(int i, int j) {
	return minor(i, j) * ((i+j) % 2 ? -1 : 1);
}