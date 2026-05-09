#include<LinearAlgebra2D.hpp>
#include<LinearAlgebra3D.hpp>
#include<LinearAlgebra4D.hpp>
#include <gtest/gtest.h>

class Vector2DTest : public ::testing::Test {
protected:
	Vector2D vec0 = Vector2D();
	Vector2D vec1 = Vector2D(1, 2);
};
class Vector3DTest : public ::testing::Test {
protected:
	Vector3D vec0 = Vector3D();
	Vector3D vec1 = Vector3D(1, 2, 3);
};
class Vector4DTest : public ::testing::Test {
protected:
	Vector4D vec0 = Vector4D();
	Vector4D vec1 = Vector4D(1, 2, 3, 5);
};

class Matrix2DTest : public ::testing::Test {
protected:
	Matrix2D matrix0 = Matrix2D();
	Matrix2D matrix1 = Matrix2D({
		{1, 0},
		{0, 1}
	});
	Matrix2D matrix2 = Matrix2D({
		{1, 2},
		{3, 5}
	});
};
class Matrix3DTest : public ::testing::Test {
protected:
	Matrix3D matrix0 = Matrix3D();
	Matrix3D matrix1 = Matrix3D({
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	});
	Matrix3D matrix2 = Matrix3D({
		{1, 2, 3},
		{5, 7, 11},
		{13, 17, 19}
	});
};
class Matrix4DTest : public ::testing::Test {
protected:
	Matrix4D matrix0 = Matrix4D();
	Matrix4D matrix1 = Matrix4D({
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	});
	Matrix4D matrix2 = Matrix4D({
		{1, 2, 3, 5},
		{7, 11, 13, 17},
		{19, 23, 29, 31},
		{37, 41, 43, 47}
	});
};

TEST(test, test) {
	EXPECT_TRUE(true);
}

TEST_F(Vector2DTest, GetByIndex) {
	EXPECT_EQ(vec1[0], 1);
	EXPECT_EQ(vec1[1], 2);
}

TEST_F(Vector2DTest, Eq) {
	EXPECT_TRUE (vec0 == vec0);
	EXPECT_TRUE (vec1 == vec1);
	EXPECT_FALSE(vec0 == vec1);
	EXPECT_FALSE(vec1 == vec0);
}
TEST_F(Vector2DTest, notEq) {
	EXPECT_FALSE(vec0 != vec0);
	EXPECT_FALSE(vec1 != vec1);
	EXPECT_TRUE (vec0 != vec1);
	EXPECT_TRUE (vec1 != vec0);
}

TEST_F(Vector2DTest, Adding) {
	EXPECT_EQ(vec0 + vec0, vec0);
	EXPECT_EQ(vec0 + vec1, vec1);
	EXPECT_EQ(vec1 + vec0, vec0 + vec1);
	EXPECT_EQ(vec1 + vec1, Vector2D(2, 4));
}
TEST_F(Vector2DTest, DotProduct) {
	EXPECT_EQ(vec0 * vec0, 0);
	EXPECT_EQ(vec0 * vec1, 0);
	EXPECT_EQ(vec1 * vec0, vec0 * vec1);
	EXPECT_EQ(vec1 * vec1, 5);
}
TEST_F(Vector2DTest, ScalarMultiplication) {
	EXPECT_EQ(1.0f * vec0, vec0);
	EXPECT_EQ(1.0f * vec1, vec1);
	EXPECT_EQ(2.0f * vec0, vec0);
	EXPECT_EQ(2.0f * vec1, Vector2D(2, 4));
}

TEST_F(Vector3DTest, GetByIndex) {
	EXPECT_EQ(vec1[0], 1);
	EXPECT_EQ(vec1[1], 2);
	EXPECT_EQ(vec1[2], 3);
}

TEST_F(Vector3DTest, Eq) {
	EXPECT_TRUE (vec0 == vec0);
	EXPECT_TRUE (vec1 == vec1);
	EXPECT_FALSE(vec0 == vec1);
	EXPECT_FALSE(vec1 == vec0);
}
TEST_F(Vector3DTest, notEq) {
	EXPECT_FALSE(vec0 != vec0);
	EXPECT_FALSE(vec1 != vec1);
	EXPECT_TRUE (vec0 != vec1);
	EXPECT_TRUE (vec1 != vec0);
}

TEST_F(Vector3DTest, Adding) {
	EXPECT_EQ(vec0 + vec0, vec0);
	EXPECT_EQ(vec0 + vec1, vec1);
	EXPECT_EQ(vec1 + vec0, vec0 + vec1);
	EXPECT_EQ(vec1 + vec1, Vector3D(2, 4, 6));
}
TEST_F(Vector3DTest, DotProduct) {
	EXPECT_EQ(vec0 * vec0, 0);
	EXPECT_EQ(vec0 * vec1, 0);
	EXPECT_EQ(vec1 * vec0, vec0 * vec1);
	EXPECT_EQ(vec1 * vec1, 14);
}

TEST_F(Vector4DTest, GetByIndex) {
	EXPECT_EQ(vec1[0], 1);
	EXPECT_EQ(vec1[1], 2);
	EXPECT_EQ(vec1[2], 3);
	EXPECT_EQ(vec1[3], 5);
}

TEST_F(Vector4DTest, Eq) {
	EXPECT_TRUE (vec0 == vec0);
	EXPECT_TRUE (vec1 == vec1);
	EXPECT_FALSE(vec0 == vec1);
	EXPECT_FALSE(vec1 == vec0);
}
TEST_F(Vector4DTest, notEq) {
	EXPECT_FALSE(vec0 != vec0);
	EXPECT_FALSE(vec1 != vec1);
	EXPECT_TRUE (vec0 != vec1);
	EXPECT_TRUE (vec1 != vec0);
}

TEST_F(Vector4DTest, Adding) {
	EXPECT_EQ(vec0 + vec0, vec0);
	EXPECT_EQ(vec0 + vec1, vec1);
	EXPECT_EQ(vec1 + vec0, vec0 + vec1);
	EXPECT_EQ(vec1 + vec1, Vector4D(2, 4, 6, 10));
}
TEST_F(Vector4DTest, DotProduct) {
	Vector4D vec0;
	Vector4D vec1(1, 2, 3, 5);
	EXPECT_EQ(vec0 * vec0, 0);
	EXPECT_EQ(vec0 * vec1, 0);
	EXPECT_EQ(vec1 * vec0, vec0 * vec1);
	EXPECT_EQ(vec1 * vec1, 39);
}

TEST_F(Matrix2DTest, GetByIndex) {
	EXPECT_EQ(matrix2[0], 1);
	EXPECT_EQ(matrix2[1], 2);
	EXPECT_EQ(matrix2[2], 3);
	EXPECT_EQ(matrix2[3], 5);
}

TEST_F(Matrix2DTest, Eq) {
	EXPECT_TRUE (matrix0 == matrix0);
	EXPECT_TRUE (matrix1 == matrix1);
	EXPECT_TRUE (matrix2 == matrix2);
	EXPECT_FALSE(matrix0 == matrix1);
	EXPECT_FALSE(matrix1 == matrix0);
	EXPECT_FALSE(matrix0 == matrix2);
	EXPECT_FALSE(matrix2 == matrix0);
	EXPECT_FALSE(matrix2 == matrix1);
	EXPECT_FALSE(matrix1 == matrix2);
}
TEST_F(Matrix2DTest, notEq) {
	EXPECT_FALSE(matrix0 != matrix0);
	EXPECT_FALSE(matrix1 != matrix1);
	EXPECT_FALSE(matrix2 != matrix2);
	EXPECT_TRUE (matrix0 != matrix1);
	EXPECT_TRUE (matrix1 != matrix0);
	EXPECT_TRUE (matrix0 != matrix2);
	EXPECT_TRUE (matrix2 != matrix0);
	EXPECT_TRUE (matrix2 != matrix1);
	EXPECT_TRUE (matrix1 != matrix2);
}

TEST_F(Matrix2DTest, Adding) {
	EXPECT_EQ(matrix0 + matrix0, matrix0);
	EXPECT_EQ(matrix1 + matrix0, matrix1);
	EXPECT_EQ(matrix2 + matrix0, matrix2);
	EXPECT_EQ(matrix1 + matrix1, Matrix2D({
		{2, 0},
		{0, 2}
	}));
	EXPECT_EQ(matrix2 + matrix2, Matrix2D({
		{2, 4},
		{6, 10}
	}));
	EXPECT_EQ(matrix2 + matrix1, Matrix2D({
		{2, 2},
		{3, 6}
	}));
}
TEST_F(Matrix2DTest, MatrixMultiplication) {
	EXPECT_EQ(matrix0 * matrix1, matrix0);
	EXPECT_EQ(matrix0 * matrix2, matrix0);
	EXPECT_EQ(matrix1 * matrix1, matrix1);
	EXPECT_EQ(matrix2 * matrix1, matrix2);
	EXPECT_EQ(matrix2 * matrix2, Matrix2D({
		{7, 12},
		{18, 31}
	}));
}
TEST_F(Matrix2DTest, MatrixVectorMultiplication) {
	Vector2D vec0;
	Vector2D vec1(1, 2);
	EXPECT_EQ(matrix0 * vec0, vec0);
	EXPECT_EQ(matrix1 * vec0, vec0);
	EXPECT_EQ(matrix1 * vec0, vec0);
	EXPECT_EQ(matrix0 * vec1, vec0);
	EXPECT_EQ(matrix1 * vec1, vec1);
	EXPECT_EQ(matrix2 * vec1, Vector2D(5, 13));
}
TEST_F(Matrix2DTest, ScalarMultiplication) {
	EXPECT_EQ(1.0f * matrix0, matrix0);
	EXPECT_EQ(1.0f * matrix1, matrix1);
	EXPECT_EQ(1.0f * matrix2, matrix2);
	EXPECT_EQ(2.0f * matrix0, matrix0);
	EXPECT_EQ(2.0f * matrix1, Matrix2D({
		{2, 0},
		{0, 2}
	}));
	EXPECT_EQ(3.0f * matrix2, Matrix2D({
		{3, 6},
		{9, 15}
	}));
}

TEST_F(Matrix3DTest, GetByIndex) {
	EXPECT_EQ(matrix2[0], 1);
	EXPECT_EQ(matrix2[1], 2);
	EXPECT_EQ(matrix2[2], 3);
	EXPECT_EQ(matrix2[3], 5);
	EXPECT_EQ(matrix2[4], 7);
	EXPECT_EQ(matrix2[5], 11);
	EXPECT_EQ(matrix2[6], 13);
	EXPECT_EQ(matrix2[7], 17);
	EXPECT_EQ(matrix2[8], 19);
}

TEST_F(Matrix3DTest, Eq) {
	EXPECT_TRUE (matrix0 == matrix0);
	EXPECT_TRUE (matrix1 == matrix1);
	EXPECT_TRUE (matrix2 == matrix2);
	EXPECT_FALSE(matrix0 == matrix1);
	EXPECT_FALSE(matrix1 == matrix0);
	EXPECT_FALSE(matrix0 == matrix2);
	EXPECT_FALSE(matrix2 == matrix0);
	EXPECT_FALSE(matrix2 == matrix1);
	EXPECT_FALSE(matrix1 == matrix2);
}
TEST_F(Matrix3DTest, notEq) {
	EXPECT_FALSE(matrix0 != matrix0);
	EXPECT_FALSE(matrix1 != matrix1);
	EXPECT_FALSE(matrix2 != matrix2);
	EXPECT_TRUE (matrix0 != matrix1);
	EXPECT_TRUE (matrix1 != matrix0);
	EXPECT_TRUE (matrix0 != matrix2);
	EXPECT_TRUE (matrix2 != matrix0);
	EXPECT_TRUE (matrix2 != matrix1);
	EXPECT_TRUE (matrix1 != matrix2);
}

TEST_F(Matrix3DTest, Adding) {
	EXPECT_EQ(matrix0 + matrix0, matrix0);
	EXPECT_EQ(matrix1 + matrix0, matrix1);
	EXPECT_EQ(matrix2 + matrix0, matrix2);
	EXPECT_EQ(matrix1 + matrix1, Matrix3D({
		{2, 0, 0},
		{0, 2, 0},
		{0, 0, 2}
	}));
	EXPECT_EQ(matrix2 + matrix2, Matrix3D({
		{2, 4, 6},
		{10, 14, 22},
		{26, 34, 38}
	}));
	EXPECT_EQ(matrix2 + matrix1, Matrix3D({
		{2, 2, 3},
		{5, 8, 11},
		{13, 17, 20}
	}));
}
TEST_F(Matrix3DTest, MatrixMultiplication) {
	EXPECT_EQ(matrix0 * matrix1, matrix0);
	EXPECT_EQ(matrix0 * matrix2, matrix0);
	EXPECT_EQ(matrix1 * matrix1, matrix1);
	EXPECT_EQ(matrix2 * matrix1, matrix2);
	EXPECT_EQ(matrix2 * matrix2, Matrix3D({
		{50, 67, 82},
		{183, 246, 301},
		{345, 468, 587}
	}));
}
TEST_F(Matrix3DTest, MatrixVectorMultiplication) {
	Vector3D vec0;
	Vector3D vec1(1, 2, 3);
	EXPECT_EQ(matrix0 * vec0, vec0);
	EXPECT_EQ(matrix1 * vec0, vec0);
	EXPECT_EQ(matrix1 * vec0, vec0);
	EXPECT_EQ(matrix0 * vec1, vec0);
	EXPECT_EQ(matrix1 * vec1, vec1);
	EXPECT_EQ(matrix2 * vec1, Vector3D(14, 52, 104));
}

TEST_F(Matrix4DTest, GetByIndex) {
	EXPECT_EQ(matrix2[0], 1);
	EXPECT_EQ(matrix2[1], 2);
	EXPECT_EQ(matrix2[2], 3);
	EXPECT_EQ(matrix2[3], 5);
	EXPECT_EQ(matrix2[4], 7);
	EXPECT_EQ(matrix2[5], 11);
	EXPECT_EQ(matrix2[6], 13);
	EXPECT_EQ(matrix2[7], 17);
	EXPECT_EQ(matrix2[8], 19);
}

TEST_F(Matrix4DTest, Eq) {
	EXPECT_TRUE (matrix0 == matrix0);
	EXPECT_TRUE (matrix1 == matrix1);
	EXPECT_TRUE (matrix2 == matrix2);
	EXPECT_FALSE(matrix0 == matrix1);
	EXPECT_FALSE(matrix1 == matrix0);
	EXPECT_FALSE(matrix0 == matrix2);
	EXPECT_FALSE(matrix2 == matrix0);
	EXPECT_FALSE(matrix2 == matrix1);
	EXPECT_FALSE(matrix1 == matrix2);
}
TEST_F(Matrix4DTest, notEq) {
	EXPECT_FALSE(matrix0 != matrix0);
	EXPECT_FALSE(matrix1 != matrix1);
	EXPECT_FALSE(matrix2 != matrix2);
	EXPECT_TRUE (matrix0 != matrix1);
	EXPECT_TRUE (matrix1 != matrix0);
	EXPECT_TRUE (matrix0 != matrix2);
	EXPECT_TRUE (matrix2 != matrix0);
	EXPECT_TRUE (matrix2 != matrix1);
	EXPECT_TRUE (matrix1 != matrix2);
}

TEST_F(Matrix4DTest, Adding) {
	EXPECT_EQ(matrix0 + matrix0, matrix0);
	EXPECT_EQ(matrix1 + matrix0, matrix1);
	EXPECT_EQ(matrix2 + matrix0, matrix2);
	EXPECT_EQ(matrix1 + matrix1, Matrix4D({
		{2, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 2}
	}));
	EXPECT_EQ(matrix2 + matrix2, Matrix4D({
		{2, 4, 6, 10},
		{14, 22, 26, 34},
		{38, 46, 58, 62},
		{74, 82, 86, 94}
	}));
	EXPECT_EQ(matrix2 + matrix1, Matrix4D({
		{2, 2, 3, 5},
		{7, 12, 13, 17},
		{19, 23, 30, 31},
		{37, 41, 43, 48}
	}));
}
TEST_F(Matrix4DTest, MatrixMultiplication) {
	EXPECT_EQ(matrix0 * matrix1, matrix0);
	EXPECT_EQ(matrix0 * matrix2, matrix0);
	EXPECT_EQ(matrix1 * matrix1, matrix1);
	EXPECT_EQ(matrix2 * matrix1, matrix2);
	EXPECT_EQ(matrix2 * matrix2, Matrix4D(
		{{257, 298, 331, 367},
		{960, 1131, 1272, 1424},
		{1878, 2229, 2530, 2842},
		{2880, 3441, 3912, 4424}
	}));
}
TEST_F(Matrix4DTest, MatrixVectorMultiplication) {
	Vector4D vec0;
	Vector4D vec1(1, 2, 3, 5);
	EXPECT_EQ(matrix0 * vec0, vec0);
	EXPECT_EQ(matrix1 * vec0, vec0);
	EXPECT_EQ(matrix1 * vec0, vec0);
	EXPECT_EQ(matrix0 * vec1, vec0);
	EXPECT_EQ(matrix1 * vec1, vec1);
	EXPECT_EQ(matrix2 * vec1, Vector4D(39, 153, 307, 483));
}