#pragma once
#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif

namespace std {
    template<class E>
    class initializer_list;
}

class API Vector4D {
private:
float x, y, z, w;
public:
	Vector4D();
	Vector4D(float vector[4]);
	Vector4D(float _x, float _y, float _z, float _w);
	Vector4D(std::initializer_list<float> vector);
	
	float operator[](int index) const;
	
	const bool operator==(const Vector4D &vector) const;
	const bool operator!=(const Vector4D &vector) const;
	
	Vector4D operator+(const Vector4D &vector);
	float operator*(const Vector4D &vector);
	
	~Vector4D() = default;
};

class API Matrix4D {
private:
	float matrix[16];
public:
	Matrix4D();
	Matrix4D(float _matrix[4][4]);
	Matrix4D(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15);
	Matrix4D(std::initializer_list<std::initializer_list<float>> _matrix);
	
	float operator[](int index) const;
	float operator()(int x, int y) const;
	
	const bool operator==(const Matrix4D &_matrix) const;
	const bool operator!=(const Matrix4D &_matrix) const;
	
	Matrix4D operator+(const Matrix4D &_matrix);
	Matrix4D operator*(const Matrix4D &_matrix);
	Vector4D operator*(const Vector4D &vector);
	
	float det();
	
	~Matrix4D() = default;
};