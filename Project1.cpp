// Data Structures Spring 2023
// CS 2413
// Aditya Narasimhan
#include <iostream> 
#include <time.h> // for experiments
using namespace std;

int* A;
int* B;
int* findQueries;
int* sumPairQueries;
int* removeOperations;
int* insertionOperations;

int findElement(int* array, int target)
{
    //TODO: finish this method
    return 0;
}

int* sumPairs(int target)
{
    //TODO: finish this method
    return NULL;
}

int* removeElement(int target)
{
    //TODO: finish this method
    return NULL;
}

int* insertElement(int toInsert)
{
    //TODO: finish this method
    return NULL;
}

int* sort(int* toSort, int maxValues)
{
    int* B = new int[maxValues]; //create dynamic array B
    //loop to copy values of toSort(A) into B
    for(int i = 0; i < maxValues; i++)
    {
        B[i] = toSort[i];
    }

    //bubblesort algorithm to sort array
    //code inspiration derived from
    //https://www.softwaretestinghelp.com/bubble-sort/#:~:text=Bubble%20Sort%20Technique%20In%20C,%5B2%5D%20and%20so%20on.
    int temp;
    for(int i = 0; i<maxValues; i++) {
        for(int j = i+1; j<maxValues; j++)
        {
            if(B[j] < B[i]) {
            temp = B[i];
            B[i] = B[j];
            B[j] = temp;
            }
        }
    }
    return B;
}

int main()
{
    int maxValues; // max number of values to store / length of the arrays
    int currentValues; // as we add, the number of values in the arrays
    int tempVal; // variable used to read the number 
    cin >> maxValues; // read the maximum number of values from the redirected input file
    cout << "Length of the array: " << maxValues << endl;

    // TODO create a dynamic array A of size maxValues
    A = new int[maxValues];
    //REMEMBER TO DISPOSE OF DYNAMIC ARRAY AFTER USAGE!!
    //statically defined arrays do not need to be deleted
    //delete [] name

    // TODO read in the number from the redirected input
    for (int i = 0; i < maxValues; i++)
    {
        cin >> tempVal;
        A[i] = tempVal;
        cout << A[i];
        cout << " ";
    }
    cout<<'\n';

// TODO display the values in array A

// TODO sort the array A and store it in B - any sorting algorithm can be used
B = sort(A, maxValues);

//test code to check values of B
for (int i = 0; i < maxValues; i++)
    {
        cout << B[i];
        cout << " ";
    }
// TODO read the commands/options till the end of the file
// 
// TODO delete all the dynamically created arrays
    delete [] A;
    delete [] B;

    return 0;
}

