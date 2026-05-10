#include <gtest/gtest.h>
#include<LinearAlgebra3D.hpp>

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
TEST_F(Matrix3DTest, ScalarMultiplication) {
	EXPECT_EQ(1.0f * matrix0, matrix0);
	EXPECT_EQ(1.0f * matrix1, matrix1);
	EXPECT_EQ(1.0f * matrix2, matrix2);
	EXPECT_EQ(2.0f * matrix0, matrix0);
	EXPECT_EQ(2.0f * matrix1, Matrix3D({
		{2, 0, 0},
		{0, 2, 0},
		{0, 0, 2}
	}));
	EXPECT_EQ(10.0f * matrix2, Matrix3D({
		{10, 20, 30},
		{50, 70, 110},
		{130, 170, 190}
	}));
}

TEST_F(Matrix3DTest, Det) {
	EXPECT_EQ(matrix0.det(), 0);
	EXPECT_EQ(matrix1.det(), 1);
	EXPECT_EQ(matrix1.det() * matrix0.det(), (matrix1 * matrix0).det());
	EXPECT_EQ(matrix1.det() * matrix2.det(), (matrix1 * matrix2).det());
}