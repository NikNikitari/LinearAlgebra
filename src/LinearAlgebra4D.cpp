#include <LinearAlgebra4D.hpp>
#include <initializer_list>
#include <stdexcept>

Vector4D::Vector4D(): x(0), y(0), z(0), w(0) {}
Vector4D::Vector4D(float _x, float _y, float _z, float _w): x(_x), y(_y), z(_z), w(_w) {}
Vector4D::Vector4D(float vector[4]) : x(vector[0]), y(vector[1]), z(vector[2]), w(vector[3]) {}
Vector4D::Vector4D(std::initializer_list<float> vector) {
	if (vector.size() != 4) throw std::invalid_argument("Vector must be size 4");
	x = *vector.begin();
	y = *(vector.begin() + 1);
	z = *(vector.begin() + 2);
	w = *(vector.begin() + 3);
}

float Vector4D::operator[](int index) const {
	if (index == 0) return x;
    if (index == 1) return y;
	if (index == 2) return z;
	if (index == 3) return w;
    throw std::out_of_range("Index out of range");
}

const bool Vector4D::operator==(const Vector4D &vector) const {
	return x == vector[0] && y == vector[1] && z == vector[2] && w == vector[3];
}
const bool Vector4D::operator!=(const Vector4D &vector) const {
	return !(*this == vector);
}

Vector4D Vector4D::operator+(const Vector4D &vector) {
	return Vector4D(x + vector[0], y + vector[1], z + vector[2], w + vector[3]);
}
float Vector4D::operator*(const Vector4D &vector) {
	return x * vector[0] + y * vector[1] + z * vector[2] + w * vector[3];
}
Vector4D operator*(float scalar, const Vector4D &vector) {
	return Vector4D(scalar * vector[0], scalar * vector[1], scalar * vector[2], scalar * vector[3]);
}

Matrix4D::Matrix4D(): matrix{} {}
Matrix4D::Matrix4D(float _matrix[4][4]) {
	matrix[0]  = _matrix[0][0];
	matrix[1]  = _matrix[0][1];
	matrix[2]  = _matrix[0][2];
	matrix[3]  = _matrix[0][3];
	matrix[4]  = _matrix[1][0];
	matrix[5]  = _matrix[1][1];
	matrix[6]  = _matrix[1][2];
	matrix[7]  = _matrix[1][3];
	matrix[8]  = _matrix[2][0];
	matrix[9]  = _matrix[2][1];
	matrix[10] = _matrix[2][2];
	matrix[11] = _matrix[2][3];
	matrix[12] = _matrix[3][0];
	matrix[13] = _matrix[3][1];
	matrix[14] = _matrix[3][2];
	matrix[15] = _matrix[3][3];
}
Matrix4D::Matrix4D(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15) {
	matrix[0]  = a0;
	matrix[1]  = a1;
	matrix[2]  = a2;
	matrix[3]  = a3;
	matrix[4]  = a4;
	matrix[5]  = a5;
	matrix[6]  = a6;
	matrix[7]  = a7;
	matrix[8]  = a8;
	matrix[9]  = a9;
	matrix[10] = a10;
	matrix[11] = a11;
	matrix[12] = a12;
	matrix[13] = a13;
	matrix[14] = a14;
	matrix[15] = a15;
}
Matrix4D::Matrix4D(std::initializer_list<std::initializer_list<float>> _matrix) {
	if (_matrix.size() != 4) throw std::invalid_argument("Matrix must be 4x4");
	
	int y = 0;
	for (std::initializer_list<float> row : _matrix) {
		if (row.size() != 4) throw std::invalid_argument("Matrix must be 4x4");
		
		int x = 0;
		for (float number : row) matrix[y * 4 + x++] = number;
		++y;
	}
}

float Matrix4D::operator[](int index) const {
	if (index > 15 || index < 0) throw std::out_of_range("Index out of range");
	return matrix[index];
}
float Matrix4D::operator()(int x, int y) const {
	if (x > 3 || y > 3 || x < 0 || y < 0) throw std::out_of_range("Index out of range");
	return matrix[x+y*3];
}

const bool Matrix4D::operator==(const Matrix4D &_matrix) const {
	return 
	matrix[0]  == _matrix[0]  && 
	matrix[1]  == _matrix[1]  && 
	matrix[2]  == _matrix[2]  && 
	matrix[3]  == _matrix[3]  && 
	matrix[4]  == _matrix[4]  && 
	matrix[5]  == _matrix[5]  && 
	matrix[6]  == _matrix[6]  && 
	matrix[7]  == _matrix[7]  && 
	matrix[8]  == _matrix[8]  &&
	matrix[9]  == _matrix[9]  && 
	matrix[10] == _matrix[10] && 
	matrix[11] == _matrix[11] && 
	matrix[12] == _matrix[12] && 
	matrix[13] == _matrix[13] && 
	matrix[14] == _matrix[14] && 
	matrix[15] == _matrix[15];   
}
const bool Matrix4D::operator!=(const Matrix4D &_matrix) const {
	return !(*this == _matrix);
}

Matrix4D Matrix4D::operator+(const Matrix4D &_matrix) {
	return Matrix4D(
		matrix[0] + _matrix[0], matrix[1] + _matrix[1], matrix[2] + _matrix[2], matrix[3] + _matrix[3], 
		matrix[4] + _matrix[4], matrix[5] + _matrix[5], matrix[6] + _matrix[6], matrix[7] + _matrix[7], 
		matrix[8] + _matrix[8], matrix[9] + _matrix[9], matrix[10] + _matrix[10], matrix[11] + _matrix[11], 
		matrix[12] + _matrix[12], matrix[13] + _matrix[13], matrix[14] + _matrix[14], matrix[15] + _matrix[15]
	);
}
Matrix4D Matrix4D::operator*(const Matrix4D &_matrix) {
	return Matrix4D(
		matrix[0]  * _matrix[0] + matrix[1]  * _matrix[4] + matrix[2]  * _matrix[8]  + matrix[3]  * _matrix[12], 
		matrix[0]  * _matrix[1] + matrix[1]  * _matrix[5] + matrix[2]  * _matrix[9]  + matrix[3]  * _matrix[13], 
		matrix[0]  * _matrix[2] + matrix[1]  * _matrix[6] + matrix[2]  * _matrix[10] + matrix[3]  * _matrix[14], 
		matrix[0]  * _matrix[3] + matrix[1]  * _matrix[7] + matrix[2]  * _matrix[11] + matrix[3]  * _matrix[15], 
		matrix[4]  * _matrix[0] + matrix[5]  * _matrix[4] + matrix[6]  * _matrix[8]  + matrix[7]  * _matrix[12], 
		matrix[4]  * _matrix[1] + matrix[5]  * _matrix[5] + matrix[6]  * _matrix[9]  + matrix[7]  * _matrix[13], 
		matrix[4]  * _matrix[2] + matrix[5]  * _matrix[6] + matrix[6]  * _matrix[10] + matrix[7]  * _matrix[14], 
		matrix[4]  * _matrix[3] + matrix[5]  * _matrix[7] + matrix[6]  * _matrix[11] + matrix[7]  * _matrix[15], 
		matrix[8]  * _matrix[0] + matrix[9]  * _matrix[4] + matrix[10] * _matrix[8]  + matrix[11] * _matrix[12], 
		matrix[8]  * _matrix[1] + matrix[9]  * _matrix[5] + matrix[10] * _matrix[9]  + matrix[11] * _matrix[13], 
		matrix[8]  * _matrix[2] + matrix[9]  * _matrix[6] + matrix[10] * _matrix[10] + matrix[11] * _matrix[14], 
		matrix[8]  * _matrix[3] + matrix[9]  * _matrix[7] + matrix[10] * _matrix[11] + matrix[11] * _matrix[15], 
		matrix[12] * _matrix[0] + matrix[13] * _matrix[4] + matrix[14] * _matrix[8]  + matrix[15] * _matrix[12], 
		matrix[12] * _matrix[1] + matrix[13] * _matrix[5] + matrix[14] * _matrix[9]  + matrix[15] * _matrix[13], 
		matrix[12] * _matrix[2] + matrix[13] * _matrix[6] + matrix[14] * _matrix[10] + matrix[15] * _matrix[14], 
		matrix[12] * _matrix[3] + matrix[13] * _matrix[7] + matrix[14] * _matrix[11] + matrix[15] * _matrix[15]  
	);
}
Vector4D Matrix4D::operator*(const Vector4D &vector) {
	return Vector4D(
		vector[0] * matrix[0] + vector[1] * matrix[1] + vector[2] * matrix[2] + vector[3] * matrix[3],
		vector[0] * matrix[4] + vector[1] * matrix[5] + vector[2] * matrix[6] + vector[3] * matrix[7],
		vector[0] * matrix[8] + vector[1] * matrix[9] + vector[2] * matrix[10] + vector[3] * matrix[11],
		vector[0] * matrix[12] + vector[1] * matrix[13] + vector[2] * matrix[14] + vector[3] * matrix[15]
	);
}
Matrix4D operator*(float scalar, const Matrix4D& matrix) {
	return Matrix4D(
		scalar * matrix[0] , 
		scalar * matrix[1] , 
		scalar * matrix[2] , 
		scalar * matrix[3] , 
		scalar * matrix[4] , 
		scalar * matrix[5] , 
		scalar * matrix[6] , 
		scalar * matrix[7] , 
		scalar * matrix[8] , 
		scalar * matrix[9] , 
		scalar * matrix[10], 
		scalar * matrix[11], 
		scalar * matrix[12], 
		scalar * matrix[13], 
		scalar * matrix[14], 
		scalar * matrix[15]   
	);
}

Matrix4D Matrix4D::transpose() {
	return Matrix4D(
		matrix[0], matrix[4], matrix[8] , matrix[12], 
		matrix[1], matrix[5], matrix[9] , matrix[13], 
		matrix[2], matrix[6], matrix[10], matrix[14], 
		matrix[3], matrix[7], matrix[11], matrix[15]  
	);
}

float Matrix4D::minor(int i, int j) {
	if (i > 3 || j > 3 || i < 0 || j < 0) throw std::out_of_range("Index out of range");
	int a[6];
	a[0] = i ? 0 : 1;
	a[1] = i > 1 ? 1 : 2;
	a[2] = i > 2 ? 2 : 3;
	a[3] = j ? 0 : 4;
	a[4] = j > 1 ? 4: 8;
	a[5] = j > 2 ? 8 : 12;
	return 
	matrix[a[0] + a[3]] * matrix[a[1] + a[4]] * matrix[a[2] + a[5]] + 
	matrix[a[1] + a[3]] * matrix[a[2] + a[4]] * matrix[a[0] + a[5]] + 
	matrix[a[2] + a[3]] * matrix[a[0] + a[4]] * matrix[a[1] + a[5]] - 
	matrix[a[2] + a[3]] * matrix[a[1] + a[4]] * matrix[a[0] + a[5]] - 
	matrix[a[0] + a[3]] * matrix[a[2] + a[4]] * matrix[a[1] + a[5]] - 
	matrix[a[1] + a[3]] * matrix[a[0] + a[4]] * matrix[a[2] + a[5]];  
}

float Matrix4D::det() {
	return 
	matrix[0] * matrix[5] * matrix[10] * matrix[15] + 
	matrix[0] * matrix[6] * matrix[11] * matrix[13] + 
	matrix[0] * matrix[7] * matrix[9]  * matrix[14] + 
	matrix[1] * matrix[4] * matrix[11] * matrix[14] + 
	matrix[1] * matrix[6] * matrix[8]  * matrix[15] + 
	matrix[1] * matrix[7] * matrix[10] * matrix[12] + 
	matrix[2] * matrix[4] * matrix[9]  * matrix[15] + 
	matrix[2] * matrix[5] * matrix[11] * matrix[12] + 
	matrix[2] * matrix[7] * matrix[8]  * matrix[13] + 
	matrix[3] * matrix[4] * matrix[10] * matrix[13] + 
	matrix[3] * matrix[5] * matrix[8]  * matrix[14] + 
	matrix[3] * matrix[6] * matrix[9]  * matrix[12] - 
	matrix[0] * matrix[5] * matrix[11] * matrix[14] - 
	matrix[0] * matrix[6] * matrix[9]  * matrix[15] - 
	matrix[0] * matrix[7] * matrix[10] * matrix[13] - 
	matrix[1] * matrix[4] * matrix[10] * matrix[15] - 
	matrix[1] * matrix[6] * matrix[11] * matrix[12] - 
	matrix[1] * matrix[7] * matrix[8]  * matrix[14] - 
	matrix[2] * matrix[4] * matrix[11] * matrix[13] - 
	matrix[2] * matrix[5] * matrix[8]  * matrix[15] - 
	matrix[2] * matrix[7] * matrix[9]  * matrix[12] - 
	matrix[3] * matrix[4] * matrix[9]  * matrix[14] - 
	matrix[3] * matrix[5] * matrix[10] * matrix[12] - 
	matrix[3] * matrix[6] * matrix[8]  * matrix[13];
}
