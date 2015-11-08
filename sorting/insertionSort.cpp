#include <iostream>
#include <vector>
#include <string>

std::vector<int> insertionSortVector(std::vector<int> A)
{
    using namespace std;
    for (int j=1; j<A.size();j++)
    {
        int key = A[j];
        int i = j-1;
        while (i >= 0 and A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
    return A;
}

int printVect(std::vector<int> A)
{
    using namespace std;
    for (int i=0; i<A.size();i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}

void insertionSort(int A[], int sizeA)
{
    using namespace std;
    for (int j=1; j<sizeA ;j++)
    {
        int key = A[j];
        int i = j-1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
} 

int printArray(int A[], int sizeA)
{
    using namespace std;
    for (int i=0; i<sizeA; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}

int printStringArray(std::string A[], int sizeA)
{
    using namespace std;
    for (int i=0; i<sizeA; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}

void insertionSortString(std::string A[], int sizeA)
{
    using namespace std;
    for (int j=1; j<sizeA;j++)
    {
        std::string key = A[j];
        int i = j-1;
        while (i >= 0 and A[i].compare(key) > 0) //A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main()
{
    using namespace std;
    int p[] = {3, 2, 1, 5, 5, 4};
    int sizeP =  sizeof(p) / sizeof(*p);
    cout << sizeof(p) << " " <<  sizeof(*p) << " " << sizeof(p) / sizeof(*p) << "\n";
    printArray(p, sizeP);
    std::vector<int> B(p, p+6);
    std::vector<int> C = insertionSortVector(B);

    insertionSort(p, sizeP);
    printArray(p, sizeP);
   
    string mystring[] = {"zaxbvg", "snoof", "bunnyy", "love"};
    int sizeS =  sizeof(mystring) / sizeof(*mystring);
    printStringArray(mystring,sizeS);
    insertionSortString(mystring, sizeS);
        printStringArray(mystring,sizeS);

    return 0;
}