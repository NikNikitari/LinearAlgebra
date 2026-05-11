#pragma once
#ifdef API
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

namespace std {
    template<class E>
    class initializer_list;
}

class API Vector3D {
private:
float x, y, z;
public:
	Vector3D();
	Vector3D(float vector[3]);
	Vector3D(float _x, float _y, float _z);
	Vector3D(std::initializer_list<float> vector);
	
	float operator[](int index) const;
	
	const bool operator==(const Vector3D &vector) const;
	const bool operator!=(const Vector3D &vector) const;
	
	Vector3D operator+(const Vector3D &vector);
	float operator*(const Vector3D &vector);
	
	~Vector3D() = default;
};

class API Matrix3D {
private:
	float matrix[9];
public:
	Matrix3D();
	Matrix3D(float _matrix[3][3]);
	Matrix3D(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8);
	Matrix3D(std::initializer_list<std::initializer_list<float>> _matrix);
	
	float operator[](int index) const;
	float operator()(int x, int y) const;
	
	const bool operator==(const Matrix3D &_matrix) const;
	const bool operator!=(const Matrix3D &_matrix) const;
	
	Matrix3D operator+(const Matrix3D &_matrix);
	Matrix3D operator*(const Matrix3D &_matrix);
	Vector3D operator*(const Vector3D &vector);
	
	float det();
	Matrix3D transpose();
	float minor(int i, int j);
	float cofactor(int i, int j);
	Matrix3D inversion();
	
	~Matrix3D() = default;
};

Vector3D API operator*(float scalar, const Vector3D &vector);
Matrix3D API operator*(float scalar, const Matrix3D &matrix);