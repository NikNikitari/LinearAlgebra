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

class API Vector2D {
private:
	float x; float y;
public:
	Vector2D();
	Vector2D(float vector[2]);
	Vector2D(float _x, float _y);
	Vector2D(std::initializer_list<float> vector);
	
	float operator[](int index) const;
	
	const bool operator==(const Vector2D &vector) const;
	const bool operator!=(const Vector2D &vector) const;
	
	Vector2D operator+(const Vector2D &vector);
	float operator*(const Vector2D &vector);
	
	~Vector2D() = default;
};

class API Matrix2D {
private:
	float matrix[4];
public:
	Matrix2D();
	Matrix2D(float _matrix[2][2]);
	Matrix2D(float a, float b, float c, float d);
	Matrix2D(std::initializer_list<std::initializer_list<float>> _matrix);
	
	float operator[](int index) const;
	float operator()(int x, int y) const;
	
	const bool operator==(const Matrix2D &_matrix) const;
	const bool operator!=(const Matrix2D &_matrix) const;
	
	Matrix2D operator+(const Matrix2D &_matrix);
	Matrix2D operator*(const Matrix2D &_matrix);
	Vector2D operator*(const Vector2D &vector);
	
	float det();
	Matrix2D transpose();
	float minor(int i, int j);
	float cofactor(int i, int j);
	Matrix2D inversion();
	
	~Matrix2D() = default;
};

Vector2D API operator*(float scalar, const Vector2D &vector);
Matrix2D API operator*(float scalar, const Matrix2D &matrix);