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
	Vector3D(const float vector[3]);
	Vector3D(const float& _x, const float& _y, const float& _z);
	Vector3D(std::initializer_list<float> vector);
	
	const float& operator[](int index) const;
	
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
	Matrix3D(const float _matrix[3][3]);
	Matrix3D(const float& a0, const float& a1, const float& a2, const float& a3, const float& a4, const float& a5, const float& a6, const float& a7, const float& a8);
	Matrix3D(std::initializer_list<std::initializer_list<float>> _matrix);
	
	const float& operator[](int index) const;
	const float& operator()(int x, int y) const;
	
	const bool operator==(const Matrix3D &_matrix) const;
	const bool operator!=(const Matrix3D &_matrix) const;
	
	Matrix3D operator+(const Matrix3D &_matrix);
	Matrix3D operator*(const Matrix3D &_matrix);
	Vector3D operator*(const Vector3D &vector);
	
	float det();
	
	~Matrix3D() = default;
};