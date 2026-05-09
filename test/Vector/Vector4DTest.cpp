#include <gtest/gtest.h>
#include<LinearAlgebra4D.hpp>

class Vector4DTest : public ::testing::Test {
protected:
	Vector4D vec0 = Vector4D();
	Vector4D vec1 = Vector4D(1, 2, 3, 5);
};

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
TEST_F(Vector4DTest, ScalarMultiplication) {
	EXPECT_EQ(1.0f * vec0, vec0);
	EXPECT_EQ(1.0f * vec1, vec1);
	EXPECT_EQ(2.0f * vec0, vec0);
	EXPECT_EQ(2.0f * vec1, Vector4D(2, 4, 6, 10));
}