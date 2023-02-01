// Data Structures Spring 2023
// CS 2413
// Aditya Narasimhan
#include <iostream> 
#include <time.h> // for experiments
using namespace std;

int* A;
int* B;
int* findQueries;
int fsize;
int* sumPairQueries;
int asize;
int* removeOperations;
int rsize;
int* insertionOperations;
int isize;

int linearSearch(int* array, int target)
{
    //TODO: finish this method
    return 0;
}

int binarySearch(int* array, int upper, int lower, int target)
{
    //base case
    if(lower > upper)
    {
        return -1;
    }
    int middle = (upper+lower)/2;
    //if target is found
    if(array[middle] == target)
        return middle;
    //if the target is in the upper half of the array, recur function
    if(target > array[middle])
        return binarySearch(array, upper, middle+1, target);
    //if the target is in the lower half of the array, recur function
    else if(target < array[middle])
        return binarySearch(array, middle-1, lower, target);
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

    A = new int[maxValues];//dynamic array containing unsorted values

    //read in the number from the redirected input
    for (int i = 0; i < maxValues; i++)
    {
        cin >> tempVal;
        A[i] = tempVal;
    }
   
    // sort the array A and store it in B
    B = sort(A, maxValues);
    for(int i = 0; i < maxValues; i++)
    {
        cout << B[i];
        cout << " ";
    }
    cout<<'\n';

    //this for loop reads in all operation data
    char operation;
    int size;
    int* currentOp;
    for(int i = 0; i < 4; i++)
    {
    cin >> operation;
    cin >> size;
       switch (operation)
        {
        case 'F':
            findQueries = new int[size];
            currentOp = findQueries;
            fsize = size;
            break;
        case 'A':
            sumPairQueries = new int[size];
            currentOp = sumPairQueries;
            asize = size;
            break;
        case 'R':
            removeOperations = new int[size];
            currentOp = removeOperations;
            rsize = size;
            break;
        case 'I':
            insertionOperations = new int[size];
            currentOp = insertionOperations;
            isize = size;
            break;
        default:
            break;
        }
        for(int i = 0; i < size; i++)
        {
            cin >> currentOp[i];
        }
    }

    cout<<"Binary searches: "<<'\n';
    for(int i = 0; i < fsize; i++)
    {
       cout << binarySearch(B, maxValues, 0, findQueries[i]) << " ";
    }

    //delete all arrays to clear memory
    delete [] A;
    delete [] B;
    delete [] insertionOperations;
    delete [] sumPairQueries;
    delete [] removeOperations;
    delete [] findQueries;

    return 0;
}

