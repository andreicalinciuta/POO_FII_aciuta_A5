#pragma once
class Sort
{
    // add data members
    int numberOfElements;
    int* myArray;

    int partition(int low, int high, int type);
    void theRealQuickSort(int low, int high, int type);

public:

    // add constuctors
    Sort(int numberOfElements, int minimumValue, int maximumValue);
    Sort();
    Sort(int* arrayA, int numberOfElements);
    Sort(int count,...);
    Sort(char* arrayA);


    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};