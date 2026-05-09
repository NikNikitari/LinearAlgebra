#include <gtest/gtest.h>
#include<LinearAlgebra2D.hpp>

class Vector2DTest : public ::testing::Test {
protected:
	Vector2D vec0 = Vector2D();
	Vector2D vec1 = Vector2D(1, 2);
};

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