#include <gtest/gtest.h>
#include<LinearAlgebra2D.hpp>

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

TEST_F(Matrix2DTest, Det) {
	EXPECT_EQ(matrix0.det(), 0);
	EXPECT_EQ(matrix1.det(), 1);
	EXPECT_EQ(matrix1.det() * matrix0.det(), (matrix1 * matrix0).det());
	EXPECT_EQ(matrix1.det() * matrix2.det(), (matrix1 * matrix2).det());
	EXPECT_EQ(matrix2.det() * matrix2.det(), (matrix2 * matrix2).det());
}
TEST_F(Matrix2DTest, Transpose) {
	EXPECT_EQ(matrix0.transpose().transpose(), matrix0);
	EXPECT_EQ(matrix1.transpose().transpose(), matrix1);
	EXPECT_EQ(matrix2.transpose().transpose(), matrix2);
	
	EXPECT_EQ(matrix0.transpose().det(), matrix0.det());
	EXPECT_EQ(matrix1.transpose().det(), matrix1.det());
	EXPECT_EQ(matrix2.transpose().det(), matrix2.det());
	
	
	EXPECT_EQ(matrix0.transpose(), matrix0);
	EXPECT_EQ(matrix1.transpose(), matrix1);
	EXPECT_NE(matrix2.transpose(), matrix2);
	
	EXPECT_EQ(matrix1 * matrix1.transpose(), matrix1);
	EXPECT_EQ((2 * matrix2).transpose(), 2 * matrix2.transpose());
	EXPECT_EQ((matrix2 * matrix2).transpose(), matrix2.transpose() * matrix2.transpose());
}