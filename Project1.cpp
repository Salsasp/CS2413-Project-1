// Data Structures Spring 2023
// CS 2413
// Aditya Narasimhan
#include <iostream> 
#include <time.h> // for experiments
using namespace std;

int* A;
int ASize;
int* B;
int BSize;
int* findQueries;
int fsize;
int* sumPairQueries;
int asize;
int* removeOperations;
int rsize;
int* insertionOperations;
int isize;

int linearSearch(int* array, int target, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == target)
        {
            return i;
        }
    }
    return -1;
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

int* sumPairs(int*array, int target, int size)
{
    static int pair[2];
    int val1;
    int val2;
    for(int i = 0; i < size; i++)
    {
        val1 = array[i];
        for(int j = i+1; j < size; j++)
        {
            val2 = array[j];
            if(val1 + val2 == target)
            {
                pair[0] = val1;
                pair[1] = val2;
                return pair;
            }
        }
    }
    return NULL;
}

int removeElement(int* array, int target, int size, char arrName)
{
    
    for(int i = 0; i < size; i++)
    {
        if(array[i] == target)
        {
            if(arrName == 'A')
                ASize -= 1;
            else BSize -= 1;
            for(int j = i; j < size; j++)
            {
                array[j] = array[j+1];
            }
            return i;
        }
    }
    return -1;
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
    ASize = maxValues;
    BSize = maxValues;
    cout << "Length of the array: " << maxValues << endl;

    A = new int[maxValues];//dynamic array containing unsorted values

    //read in the number from the redirected input
    for (int i = 0; i < maxValues; i++)
    {
        cin >> tempVal;
        A[i] = tempVal;
    }
    cout<<"Array A: ";
    for(int i = 0; i < maxValues; i++)
    {
        cout << A[i] << " ";
    }
    cout << '\n';
    // sort the array A and store it in B
    B = sort(A, maxValues);
    cout<<"Array B: ";
    for(int i = 0; i < maxValues; i++)
    {
        cout << B[i];
        cout << " ";
    }
    cout<<'\n'<<'\n';

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
/**************************************************************************************************************************************/
//output section
    cout<<"Find: "<<'\n';
    for(int i = 0; i < fsize; i++)
    {
        if(binarySearch(B, maxValues, 0, findQueries[i]) != -1)
            cout<<"Element "<< findQueries[i] << "  found at " << binarySearch(B, maxValues, 0, findQueries[i]) << " in B" << '\n';
        else cout<<"Element "<< findQueries[i] << "  not found in B" << '\n';
    }
    cout<<'\n';
    for(int i = 0; i < fsize; i++)
    {
        if(linearSearch(A, findQueries[i], maxValues) != -1)
            cout<<"Element "<< findQueries[i] << "  found at " << linearSearch(A, findQueries[i], maxValues) << " in A" << '\n';
        else cout<<"Element "<< findQueries[i] << "  not found in A" << '\n';
    }
    cout<<'\n'<<"SumPairs: "<<'\n';
    cout<<"B:"<<'\n';
    for(int i = 0; i < asize; i++)
    {
        int* pair = sumPairs(B, sumPairQueries[i], maxValues);
        cout << sumPairQueries[i] << '\n';
        if(pair != NULL)
            cout << " = " << pair[0]<<" + "<<pair[1]<<'\n';
    }
    cout << '\n';
    cout<<"A:"<<'\n';
    for(int i = 0; i < asize; i++)
    {
        int* pair = sumPairs(A, sumPairQueries[i], maxValues);
        cout << sumPairQueries[i] << '\n';
        if(pair != NULL)
            cout << " = " << pair[0]<<" + "<<pair[1]<<'\n';
    }
    cout << '\n';
    cout<<"Remove: "<<'\n';
    for(int i = 0; i < rsize; i++)
    {
        int index = removeElement(B, removeOperations[i], maxValues, 'B');
        if(index != -1)
            cout<<"Removing " << removeOperations[i] << " at " << index << " in " << "B" << '\n';
        else cout << "Element " << removeOperations[i] << " not found in " << "B" << '\n';
    }
    cout << '\n';
    for(int i = 0; i < rsize; i++)
    {
        int index = removeElement(A, removeOperations[i], maxValues, 'A');
        if(index != -1)
            cout<<"Removing " << removeOperations[i] << " at " << index << " in " << "A" << '\n';
        else cout << "Element " << removeOperations[i] << " not found in " << "A" << '\n';
    }
    cout << '\n';
    cout << "After removal Array A: ";
    for(int i = 0; i < ASize; i++)
    {
        cout<<A[i]<<" ";
    }
    cout << '\n' << "After removal Array B: ";
    for(int i = 0; i < BSize; i++)
    {
        cout<<B[i]<<" ";
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

