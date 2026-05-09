#include <gtest/gtest.h>
#include<LinearAlgebra3D.hpp>

class Vector3DTest : public ::testing::Test {
protected:
	Vector3D vec0 = Vector3D();
	Vector3D vec1 = Vector3D(1, 2, 3);
};

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
TEST_F(Vector3DTest, ScalarMultiplication) {
	EXPECT_EQ(1.0f * vec0, vec0);
	EXPECT_EQ(1.0f * vec1, vec1);
	EXPECT_EQ(2.0f * vec0, vec0);
	EXPECT_EQ(2.0f * vec1, Vector3D(2, 4, 6));
}