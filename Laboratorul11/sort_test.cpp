//
// Created by Andrei on 5/13/2021.
//
#include <gtest/gtest.h>

// Codul lui Razvan Pahoncea ( doar Sortarea )
template<typename T>
void jaleSort(T arr[], int l, int h)
{
    if (l > h)
        return;

    if (arr[l] > arr[h])
        std::swap(arr[l], arr[h]);

    if (h - l + 1 >= 2) {
        int t = (h - l + 1) / 2;

        jaleSort<T>(arr, l, h - t);
        jaleSort<T>(arr, l + t, h);
        jaleSort<T>(arr, l + 1, h - t);
    }
}
template<typename T>
bool isSorted(T arr[], int n)
{
    jaleSort<T>(arr, 0, n - 1);
    for(int i = 0 ; i < n - 1; ++i)
        if(arr[i] > arr[ i + 1] )
            return false;
    return true;
}

TEST(NegativeNumbers, Negative)
{
    int arr[] = {1, 2, -1, 3, 1};
    EXPECT_EQ(true, isSorted<int>(arr, 5));
}

TEST(FloatNumbers, Float)
{
    float arr[] = {1.4, 2.2, -1.6, 3, 1};
    EXPECT_EQ(true, isSorted<float>(arr, 5));
}

TEST(DecreasingOrder, Decreasing)
{
    int arr[] = {9,8,7,6,5,4,3};
    EXPECT_EQ(true, isSorted<int>(arr, 7));
}

TEST(MiddleTest, Middle)
{
    int arr[] = {1, 2, 4, 3, 5, 6};
    EXPECT_EQ(true, isSorted<int>(arr, 6));
}

TEST(PowerOfTwo, Power)
{
    int arr[] = {2, 1, 3, 1, 4, 1, 5, 2};
    EXPECT_EQ(true, isSorted<int>(arr, 8));
}

TEST(ThreeNumbers, JustThree)
{
    int arr[] = {2, 3, 1};
    EXPECT_EQ(true, isSorted<int>(arr, 3));
}
