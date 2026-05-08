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
	Vector4D(const float vector[4]);
	Vector4D(const float& _x, const float& _y, const float& _z, const float& _w);
	Vector4D(std::initializer_list<float> vector);
	
	const float& operator[](int index) const;
	
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
	Matrix4D(const float _matrix[4][4]);
	Matrix4D(const float& a0, const float& a1, const float& a2, const float& a3, const float& a4, const float& a5, const float& a6, const float& a7, const float& a8, const float& a9, const float& a10, const float& a11, const float& a12, const float& a13, const float& a14, const float& a15);
	Matrix4D(std::initializer_list<std::initializer_list<float>> _matrix);
	
	const float& operator[](int index) const;
	const float& operator()(int x, int y) const;
	
	const bool operator==(const Matrix4D &_matrix) const;
	const bool operator!=(const Matrix4D &_matrix) const;
	
	Matrix4D operator+(const Matrix4D &_matrix);
	Matrix4D operator*(const Matrix4D &_matrix);
	Vector4D operator*(const Vector4D &vector);
	
	float det();
	
	~Matrix4D() = default;
};