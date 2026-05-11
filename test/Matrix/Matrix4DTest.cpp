#include <gtest/gtest.h>
#include<LinearAlgebra4D.hpp>

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
TEST_F(Matrix4DTest, ScalarMultiplication) {
	EXPECT_EQ(1.0f * matrix0, matrix0);
	EXPECT_EQ(1.0f * matrix1, matrix1);
	EXPECT_EQ(1.0f * matrix2, matrix2);
	EXPECT_EQ(2.0f * matrix0, matrix0);
	EXPECT_EQ(2.0f * matrix1, Matrix4D({
		{2, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 2}
	}));
	EXPECT_EQ(10.0f * matrix2, Matrix4D({
		{10, 20, 30, 50},
		{70, 110, 130, 170},
		{190, 230, 290, 310},
		{370, 410, 430, 470}
	}));
}

TEST_F(Matrix4DTest, Det) {
	EXPECT_EQ(matrix0.det(), 0);
	EXPECT_EQ(matrix1.det(), 1);
	EXPECT_EQ(matrix1.det() * matrix0.det(), (matrix1 * matrix0).det());
	EXPECT_EQ(matrix1.det() * matrix2.det(), (matrix1 * matrix2).det());
}
TEST_F(Matrix4DTest, Transpose) {
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
TEST_F(Matrix4DTest, Minor) {
	EXPECT_EQ(matrix0.minor(0, 0), 0);
	EXPECT_EQ(matrix0.minor(1, 0), 0);
	EXPECT_EQ(matrix0.minor(2, 0), 0);
	EXPECT_EQ(matrix0.minor(3, 0), 0);
	EXPECT_EQ(matrix0.minor(0, 1), 0);
	EXPECT_EQ(matrix0.minor(1, 1), 0);
	EXPECT_EQ(matrix0.minor(2, 1), 0);
	EXPECT_EQ(matrix0.minor(3, 1), 0);
	EXPECT_EQ(matrix0.minor(0, 2), 0);
	EXPECT_EQ(matrix0.minor(1, 2), 0);
	EXPECT_EQ(matrix0.minor(2, 2), 0);
	EXPECT_EQ(matrix0.minor(3, 2), 0);
	EXPECT_EQ(matrix0.minor(0, 3), 0);
	EXPECT_EQ(matrix0.minor(1, 3), 0);
	EXPECT_EQ(matrix0.minor(2, 3), 0);
	EXPECT_EQ(matrix0.minor(3, 3), 0);
	
	EXPECT_EQ(matrix1.minor(0, 0), 1);
	EXPECT_EQ(matrix1.minor(1, 0), 0);
	EXPECT_EQ(matrix1.minor(2, 0), 0);
	EXPECT_EQ(matrix1.minor(3, 0), 0);
	EXPECT_EQ(matrix1.minor(0, 1), 0);
	EXPECT_EQ(matrix1.minor(1, 1), 1);
	EXPECT_EQ(matrix1.minor(2, 1), 0);
	EXPECT_EQ(matrix1.minor(3, 1), 0);
	EXPECT_EQ(matrix1.minor(0, 2), 0);
	EXPECT_EQ(matrix1.minor(1, 2), 0);
	EXPECT_EQ(matrix1.minor(2, 2), 1);
	EXPECT_EQ(matrix1.minor(3, 2), 0);
	EXPECT_EQ(matrix1.minor(0, 3), 0);
	EXPECT_EQ(matrix1.minor(1, 3), 0);
	EXPECT_EQ(matrix1.minor(2, 3), 0);
	EXPECT_EQ(matrix1.minor(3, 3), 1);
	
	EXPECT_EQ(matrix2.minor(0, 0), -600);
	EXPECT_EQ(matrix2.minor(1, 0), -840);
	EXPECT_EQ(matrix2.minor(2, 0), 240);
	EXPECT_EQ(matrix2.minor(3, 0), 480);
	EXPECT_EQ(matrix2.minor(0, 1), -370);
	EXPECT_EQ(matrix2.minor(1, 1), -488);
	EXPECT_EQ(matrix2.minor(2, 1), -42);
	EXPECT_EQ(matrix2.minor(3, 1), 96);
	EXPECT_EQ(matrix2.minor(0, 2), 0);
	EXPECT_EQ(matrix2.minor(1, 2), -120);
	EXPECT_EQ(matrix2.minor(2, 2), -180);
	EXPECT_EQ(matrix2.minor(3, 2), -60);
	EXPECT_EQ(matrix2.minor(0, 3), 70);
	EXPECT_EQ(matrix2.minor(1, 3), 8);
	EXPECT_EQ(matrix2.minor(2, 3), -78);
	EXPECT_EQ(matrix2.minor(3, 3), -36);
}
TEST_F(Matrix4DTest, Cofactor) {
	EXPECT_EQ(matrix0.cofactor(0, 0), 0);
	EXPECT_EQ(matrix0.cofactor(1, 0), 0);
	EXPECT_EQ(matrix0.cofactor(2, 0), 0);
	EXPECT_EQ(matrix0.cofactor(3, 0), 0);
	EXPECT_EQ(matrix0.cofactor(0, 1), 0);
	EXPECT_EQ(matrix0.cofactor(1, 1), 0);
	EXPECT_EQ(matrix0.cofactor(2, 1), 0);
	EXPECT_EQ(matrix0.cofactor(3, 1), 0);
	EXPECT_EQ(matrix0.cofactor(0, 2), 0);
	EXPECT_EQ(matrix0.cofactor(1, 2), 0);
	EXPECT_EQ(matrix0.cofactor(2, 2), 0);
	EXPECT_EQ(matrix0.cofactor(3, 2), 0);
	EXPECT_EQ(matrix0.cofactor(0, 3), 0);
	EXPECT_EQ(matrix0.cofactor(1, 3), 0);
	EXPECT_EQ(matrix0.cofactor(2, 3), 0);
	EXPECT_EQ(matrix0.cofactor(3, 3), 0);
	
	EXPECT_EQ(matrix1.cofactor(0, 0), 1);
	EXPECT_EQ(matrix1.cofactor(1, 0), 0);
	EXPECT_EQ(matrix1.cofactor(2, 0), 0);
	EXPECT_EQ(matrix1.cofactor(3, 0), 0);
	EXPECT_EQ(matrix1.cofactor(0, 1), 0);
	EXPECT_EQ(matrix1.cofactor(1, 1), 1);
	EXPECT_EQ(matrix1.cofactor(2, 1), 0);
	EXPECT_EQ(matrix1.cofactor(3, 1), 0);
	EXPECT_EQ(matrix1.cofactor(0, 2), 0);
	EXPECT_EQ(matrix1.cofactor(1, 2), 0);
	EXPECT_EQ(matrix1.cofactor(2, 2), 1);
	EXPECT_EQ(matrix1.cofactor(3, 2), 0);
	EXPECT_EQ(matrix1.cofactor(0, 3), 0);
	EXPECT_EQ(matrix1.cofactor(1, 3), 0);
	EXPECT_EQ(matrix1.cofactor(2, 3), 0);
	EXPECT_EQ(matrix1.cofactor(3, 3), 1);
	
	EXPECT_EQ(matrix2.cofactor(0, 0), -600);
	EXPECT_EQ(matrix2.cofactor(1, 0), 840);
	EXPECT_EQ(matrix2.cofactor(2, 0), 240);
	EXPECT_EQ(matrix2.cofactor(3, 0), -480);
	EXPECT_EQ(matrix2.cofactor(0, 1), 370);
	EXPECT_EQ(matrix2.cofactor(1, 1), -488);
	EXPECT_EQ(matrix2.cofactor(2, 1), 42);
	EXPECT_EQ(matrix2.cofactor(3, 1), 96);
	EXPECT_EQ(matrix2.cofactor(0, 2), 0);
	EXPECT_EQ(matrix2.cofactor(1, 2), 120);
	EXPECT_EQ(matrix2.cofactor(2, 2), -180);
	EXPECT_EQ(matrix2.cofactor(3, 2), 60);
	EXPECT_EQ(matrix2.cofactor(0, 3), -70);
	EXPECT_EQ(matrix2.cofactor(1, 3), 8);
	EXPECT_EQ(matrix2.cofactor(2, 3), 78);
	EXPECT_EQ(matrix2.cofactor(3, 3), -36);
}