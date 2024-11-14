#include <gtest/gtest.h>
#include "include/vector.h"

TEST(VectorTest, AtAndOperator) {
    syh::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec.at(1), 2);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec.at(2), 3);
    EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, FrontAndBack) {
    syh::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.front(), 1);
    EXPECT_EQ(vec.back(), 3);
}

TEST(VectorTest, PushAndPopBack) {
    syh::Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.size(), 3);

    vec.pop_back();
    EXPECT_EQ(vec.size(), 2);

    vec.pop_back();
    EXPECT_EQ(vec.size(), 1);

    vec.pop_back();
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, LargeNumberOfElements) {
    syh::Vector<int> vec;
    for (int i = 0; i < 6174; i++) {
        vec.push_back(i);
    }

    for (int i = 0; i < 6174; i++) {
        EXPECT_EQ(vec.at(i), i);
        EXPECT_EQ(vec[i], i);
    }

    for (int i = 0; i < 6174; i++) {
        vec.pop_back();
        EXPECT_EQ(vec.size(), 6174 - i - 1);
    }

    EXPECT_TRUE(vec.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
