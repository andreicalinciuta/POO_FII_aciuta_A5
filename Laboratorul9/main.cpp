#include"Map.h"

int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    //m.printForTest();
    
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    Map<int, const char*> mCopie;
    mCopie[10] = "C++";
    mCopie[20] = "result";
    mCopie[30] = "Poo";

    printf("Number of elements: %d\n", m.Count());

    if (m.Includes(mCopie))
    {
        printf("m inclus in mCopie\n");
    }
    else
        printf("m NU inclus in mCopie\n");

    mCopie.Set(10, "Python");
    int x = 10;
    mCopie.Delete(x);

    if (m.Includes(mCopie))
    {
        printf("m inclus in mCopie\n");
    }
    else
        printf("m NU inclus in mCopie\n");
    for (auto [key, value, index] : mCopie)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    mCopie.Clear();
    for (auto [key, value, index] : mCopie)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}