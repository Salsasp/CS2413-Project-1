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

void readSection()
{
    char operation;
    int size;
    int* currentOp;
    cin >> operation;
    cin >> size;
       switch (operation)
    {
    case 'F':
        findQueries = new int[size];
        currentOp = findQueries;
        break;
    case 'A':
        sumPairQueries = new int[size];
        currentOp = sumPairQueries;
        break;
    case 'R':
        removeOperations = new int[size];
        currentOp = removeOperations;
        break;
    case 'I':
        insertionOperations = new int[size];
        currentOp = insertionOperations;
        break;
    default:
        break;
    }
    for(int i = 0; i < size; i++)
    {
        cin >> currentOp[i];
        cout << currentOp[i];
        cout << " ";
    }
    cout << endl;
 
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
        cout << A[i];
        cout << " ";
    }
    cout<<'\n';
   
    // sort the array A and store it in B
    B = sort(A, maxValues);

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
           cout << currentOp[i];
           cout << " ";
        }
        cout << endl;
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

