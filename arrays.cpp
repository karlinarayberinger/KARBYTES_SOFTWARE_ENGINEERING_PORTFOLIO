/**
 * file: arrays.cpp
 * type: C++ (source file)
 * date: 05_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/* preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#include <stdio.h> // NULL macro
#include <stdlib.h> // srand(), rand()
#include <time.h> // time() 
#define MAXIMUM_S 1000 // constant which represents maximum value for S
#define MAXIMUM_T 1000 // constant which represents maximum value for T

/* function prototype */
void bubble_sort(int * A, int S);

/**
 * Use the Bubble Sort algorithm to arrange the elements of an int type array, A, 
 * in ascending order
 * such that A[0] represents the smallest integer value in that array and 
 * such that A[S - 1] represents the largest integer value in that array.
 * 
 * Assume that S is a natural number no larger than MAXIMUM_S.
 * 
 * Assume that A is a pointer to an int type variable and that 
 * A stores the memory address of the first element, A[0], 
 * of an int type array comprised of exactly S elements.
 * (In other words, assume that exactly S consecutive int-sized 
 * chunks of memory are allocated to the array represented by A).
 * 
 * Although this function returns no value, 
 * the array which the pointer variable, A, points to is updated 
 * if the elements of that array are not already arranged in ascending order. 
 */
void bubble_sort(int * A, int S)
{
    int i = 0, placeholder = 0; 
    bool array_is_sorted = false, adjacent_elements_were_swapped = false;
    while (!array_is_sorted)
    {
        adjacent_elements_were_swapped = false;
        for (i = 1; i < S; i += 1)
        {
            if (A[i] < A[i - 1])
            {
                placeholder = A[i];
                A[i] = A[i - 1];
                A[i - 1] = placeholder;
                adjacent_elements_were_swapped = true;
            }
        }
        if (!adjacent_elements_were_swapped) array_is_sorted = true;
    }
}

/* program entry point */
int main()
{
    // Declare four int type variables and set each of their initial values to 0.
    int S = 0, T = 0, i = 0, k = 0;

    // Declare two pointer-to-int type variables.
    int * A, * B;

    // Declare one pointer-to-pointer-to-char type variable.
    char ** C;

    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If the file named arrays_output.txt does not already exist 
     * inside of the same file directory as the file named arrays.cpp, 
     * create a new file named arrays_output.txt in that directory.
     * 
     * Open the plain-text file named arrays_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("arrays_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "The following statements describe the data capacities of various primitive C++ data types:" to the command line terminal.
    std::cout << "\n\nThe following statements describe the data capacities of various primitive C++ data types:";

    // Print "The following statements describe the data capacities of various primitive C++ data types:" to the file output stream.
    file << "\n\nThe following statements describe the data capacities of various primitive C++ data types:";

    // Print the data size of a bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool) = " << sizeof(bool) << ". // number of bytes which a bool type variable occupies";

    // Print the data size of a bool type variable to the file output stream.
    file << "\n\nsizeof(bool) = " << sizeof(bool) << ". // number of bytes which a bool type variable occupies";

    // Print the data size of a char type variable to the command line terminal.
    std::cout << "\n\nsizeof(char) = " << sizeof(char) << ". // number of bytes which a char type variable occupies";

    // Print the data size of a char type variable to the file output stream.
    file << "\n\nsizeof(char) = " << sizeof(char) << ". // number of bytes which a char type variable occupies";

    // Print the data size of an int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int) = " << sizeof(int) << ". // number of bytes which an int type variable occupies";

    // Print the data size of an int type variable to the file output stream.
    file << "\n\nsizeof(int) = " << sizeof(int) << ". // number of bytes which an int type variable occupies";

    // Print the data size of a long type variable to the command line terminal.
    std::cout << "\n\nsizeof(long) = " << sizeof(long) << ". // number of bytes which a long type variable occupies";

    // Print the data size of a long type variable to the file output stream.
    file << "\n\nsizeof(long) = " << sizeof(long) << ". // number of bytes which a long type variable occupies";

    // Print the data size of a float type variable to the command line terminal.
    std::cout << "\n\nsizeof(float) = " << sizeof(float) << ". // number of bytes which a float type variable occupies";

    // Print the data size of a float type variable to the file output stream.
    file << "\n\nsizeof(float) = " << sizeof(float) << ". // number of bytes which a float type variable occupies";

    // Print the data size of a double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double) = " << sizeof(double) << ". // number of bytes which a double type variable occupies";

    // Print the data size of a doudle type variable to the file output stream.
    file << "\n\nsizeof(double) = " << sizeof(double) << ". // number of bytes which a double type variable occupies";

    // Print the data size of a pointer-to-bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool *) = " << sizeof(bool *) << ". // number of bytes which a pointer-to-bool type variable occupies";

    // Print the data size of a pointer-to-bool type variable to the file output stream.
    file << "\n\nsizeof(bool *) = " << sizeof(bool *) << ". // number of bytes which a pointer-to-bool type variable occupies";

    // Print the data size of a pointer-to-char type variable to the command line terminal.
    std::cout << "\n\nsizeof(char *) = " << sizeof(char *) << ". // number of bytes which a pointer-to-char type variable occupies";

    // Print the data size of a pointer-to-char type variable to the file output stream.
    file << "\n\nsizeof(char *) = " << sizeof(char *) << ". // number of bytes which a pointer-to-char type variable occupies";

    // Print the data size of a pointer-to-int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int *) = " << sizeof(int *) << ". // number of bytes which a pointer-to-int type variable occupies";

    // Print the data size of a pointer-to-int type variable to the file output stream.
    file << "\n\nsizeof(int *) = " << sizeof(int *) << ". // number of bytes which a pointer-to-int type variable occupies";

    // Print the data size of a pointer-to-long type variable to the command line terminal.
    std::cout << "\n\nsizeof(long *) = " << sizeof(long *) << ". // number of bytes which a pointer-to-long type variable occupies";

    // Print the data size of a pointer-to-long type variable to the file output stream.
    file << "\n\nsizeof(long *) = " << sizeof(long *) << ". // number of bytes which a pointer-to-long type variable occupies";

    // Print the data size of a pointer-to-float type variable to the command line terminal.
    std::cout << "\n\nsizeof(float *) = " << sizeof(float *) << ". // number of bytes which a pointer-to-float type variable occupies";

    // Print the data size of a pointer-to-float type variable to the file output stream.
    file << "\n\nsizeof(float *) = " << sizeof(float *) << ". // number of bytes which a pointer-to-float type variable occupies";

    // Print the data size of a pointer-to-double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double *) = " << sizeof(double *) << ". // number of bytes which a pointer-to-double type variable occupies";

    // Print the data size of a pointer-to-double type variable to the file output stream.
    file << "\n\nsizeof(double *) = " << sizeof(double *) << ". // number of bytes which a pointer-to-double type variable occupies";

    // Print the data size of a pointer-to-pointer-to-bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool **) = " << sizeof(bool **) << ". // number of bytes which a pointer-to-pointer-to-bool type variable occupies";

    // Print the data size of a pointer-to-pointer-to-bool type variable to the file output stream.
    file << "\n\nsizeof(bool **) = " << sizeof(bool **) << ". // number of bytes which a pointer-to-pointer-to-bool type variable occupies";

    // Print the data size of a pointer-to-pointer-to-char type variable to the command line terminal.
    std::cout << "\n\nsizeof(char **) = " << sizeof(char **) << ". // number of bytes which a pointer-to-pointer-to-char type variable occupies";

    // Print the data size of a pointer-to-pointer-to-char type variable to the file output stream.
    file << "\n\nsizeof(char **) = " << sizeof(char **) << ". // number of bytes which a pointer-to-pointer-to-char type variable occupies";

    // Print the data size of a pointer-to-pointer-to-int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int **) = " << sizeof(int **) << ". // number of bytes which a pointer-to-pointer-to-int type variable occupies";

    // Print the data size of a pointer-to-pointer-to-int type variable to the file output stream.
    file << "\n\nsizeof(int **) = " << sizeof(int **) << ". // number of bytes which a pointer-to-pointer-to-int type variable occupies";

    // Print the data size of a pointer-to-pointer-to-long type variable to the command line terminal.
    std::cout << "\n\nsizeof(long **) = " << sizeof(long **) << ". // number of bytes which a pointer-to-pointer-to-long type variable occupies";

    // Print the data size of a pointer-to-pointer-to-long type variable to the file output stream.
    file << "\n\nsizeof(long **) = " << sizeof(long **) << ". // number of bytes which a pointer-to-pointer-to-long type variable occupies";

    // Print the data size of a pointer-to-pointer-to-float type variable to the command line terminal.
    std::cout << "\n\nsizeof(float **) = " << sizeof(float **) << ". // number of bytes which a pointer-to-pointer-to-float type variable occupies";

    // Print the data size of a pointer-to-pointer-to-float type variable to the file output stream.
    file << "\n\nsizeof(float **) = " << sizeof(float **) << ". // number of bytes which a pointer-to-pointer-to-float type variable occupies";

    // Print the data size of a pointer-to-pointer-to-double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double **) = " << sizeof(double **) << ". // number of bytes which a pointer-to-pointer-to-double type variable occupies";

    // Print the data size of a pointer-to-pointer-to-double type variable to the file output stream.
    file << "\n\nsizeof(double **) = " << sizeof(double **) << ". // number of bytes which a pointer-to-pointer-to-double type variable occupies";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMPRISED OF S INT TYPE VALUES." to the command line terminal.
    std::cout << "\n\nSTEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMPRISED OF S INT TYPE VALUES.";

    // Print "STEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMRPISED OF S INT TYPE VALUES." to the file output stream.
    file << "\n\nSTEP_0: CREATE A DYNAMIC ARRAY WHICH IS NAMED A AND WHICH IS COMPRISED OF S INT TYPE VALUES.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number, S, for representing the number of elements to include in an array which is no larger than than {MAXIMUM_S}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number, S, for representing the number of elements to include in an array which is no larger than " << MAXIMUM_S << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> S;

    // Print "The value which was entered for S is {S}." to the command line terminal.
    std::cout << "\nThe value which was entered for S is " << S << ".";

    // Print "The value which was entered for S is {S}." to the file output stream.
    file << "\n\nThe value which was entered for S is " << S << ".";

    // If S is smaller than 1 or if S is larger than MAXIMUM_S, set S to 10.
    S = ((S < 1) || (S > MAXIMUM_S)) ? 10 : S; 

    // Print "S := {S}. // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A" to the command line terminal.
    std::cout << "\n\nS := " << S << ". // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A";

    // Print "S := {S}. // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A" to the file output stream.
    file << "\n\nS := " << S << ". // number of consecutive int-sized chunks of memory to allocate to an array such that the memory address of the first element of that array, A[0], is stored in a pointer-to-int type variable named A";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Allocate S contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, A[0]. inside the pointer-to-int type variable named A.
    A = new int [S];

    // Print the program instruction used to generate the dynamic array represented by A to the command line terminal.
    std::cout << "\n\n// Declare a pointer-to-int type variable named A.";
    std::cout << "\nint * A;";
    std::cout << "\n\n// Allocate S contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, A[0], inside the pointer-to-int type variable named A.";
    std::cout << "\nA = new int [S];"; 

    // Print the program instruction used to generate the dynamic array represented by A to the file output stream.
    file << "\n\n// Declare a pointer-to-int type variable named A.";
    file << "\nint * A;";
    file << "\n\n// Allocate S contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, A[0], inside the pointer-to-int type variable named A.";
    file << "\nA = new int [S];"; 

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA = " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA = " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] = " << A[i] << ". \t\t// &A[" << i << "] = " << &A[i] << ". (memory address of the first byte-sized memory cell comprising the block of 4 contiguous byte-sized memory cells allocated to A[" << i << "]).";
        file << "\nA[" << i << "] = " << A[i] << ". \t\t// &A[" << i << "] = " << &A[i] << ". (memory address of the first byte-sized memory cell comprising the block of 4 contiguous byte-sized memory cells allocated to A[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_1: RANDOMLY ASSIGN ONE OF THE FIRST T RANDOM NONNEGATIVE INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A." to the command line terminal.
    std::cout << "\n\nSTEP_1: RANDOMLY ASSIGN ONE OF THE FIRST T RANDOM NONNEGATIVE INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A.";

    // Print "STEP_1: RANDOMLY ASSIGN ONE OF THE FIRST T RANDOM NONNEGATIVE INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A." to the file output stream.
    file << "\n\nSTEP_1: RANDOMLY ASSIGN ONE OF THE FIRST T RANDOM NONNEGATIVE INTEGERS TO EACH ELEMENT OF THE ARRAY NAMED A.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number, T, for representing the number of unique states which each element of the array can store exactly one of which is no larger than {MAXIMUM_T}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number, T, for representing the number of unique states which each element of the array can store exactly one of which is no larger than " << MAXIMUM_T << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> T;

    // Print "The value which was entered for T is {T}." to the command line terminal.
    std::cout << "\nThe value which was entered for T is " << T << ".";

    // Print "The value which was entered for T is {T}." to the file output stream.
    file << "\n\nThe value which was entered for T is " << T << ".";

    // If T is smaller than 1 or if T is larger than MAXIMUM_T, set T to 100.
    T = ((T < 1) || (T > MAXIMUM_T)) ? 100 : T; 

    // Print "T := {T}. // number of unique states which each element of array A can represent" to the command line terminal.
    std::cout << "\n\nT := " << T << ". // number of unique states which each element of array A can represent";

    // Print "T := {T}. // number of unique states which each element of array A can represent" to the file output stream.
    file << "\n\nT := " << T << ". // number of unique states which each element of array A can represent";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).
    srand(time(NULL));

    // Print the command to seed the pseudo random number generator to the command line.
    std::cout << "\n\n// Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    std::cout << "\nsrand(time(NULL));";

    // Print the command to seed the pseudo random number generator to the file output stream.
    file << "\n\n// Seed the pseudo random number generator with the integer number of seconds which have elapsed since the Unix Epoch (i.e. midnight of 01_JANUARY_1970).";
    file << "\nsrand(time(NULL));";

    // For each element, A[i], of the array named A, set A[i] to a randomly generated integer which is no smaller than 0 and no larger than (T - 1).
    for (i = 0; i < S; i += 1) A[i] = rand() % T;

    // Print the command to populate each element of the array named A with a randomly generated integer which is no smaller than 0 and no larger than (T - 1) to the command line terminal.
    std::cout << "\n\n// For each element, A[i], of the array named A, set A[i] to a randomly generated integer which is no smaller than 0 and no larger than (T - 1).";
    std::cout << "\nfor (i = 0; i < S; i += 1) A[i] = rand() % T;";

    // Print the command to populate each element of the array named A with a randomly generated integer which is no smaller than 0 and no larger than (T - 1) to the file output stream.
    file << "\n\n// For each element, A[i], of the array named A, set A[i] to a randomly generated integer which is no smaller than 0 and no larger than (T - 1).";
    file << "\nfor (i = 0; i < S; i += 1) A[i] = rand() % T;";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA = " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA = " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] = " << A[i] << ". \t\t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
        file << "\nA[" << i << "] = " << A[i] << ". \t\t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_2: SORT THE ELEMENT VALUES OF THE ARRAY NAMED A TO BE IN ASCENDING ORDER." to the command line terminal.
    std::cout << "\n\nSTEP_2: SORT THE ELEMENT VALUES OF THE ARRAY NAMED A TO BE IN ASCENDING ORDER.";

    // Print "STEP_2: SORT THE ELEMENT VALUES OF THE ARRAY NAMED A TO BE IN ASCENDING ORDER." to the file output stream.
    file << "\n\nSTEP_2: SORT THE ELEMENT VALUES OF THE ARRAY NAMED A TO BE IN ASCENDING ORDER.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Sort the integer values stored in array A to be in ascending order using the Bubble Sort algorithm.
    bubble_sort(A, S);

    // Print the command to sort the integer values stored in array A in ascending order to the command line.
    std::cout << "\n\n// Sort the integer values stored in array A to be in ascending order using the Bubble Sort algorithm.";
    std::cout << "\nbubble_sort(A, S);";

    // Print the command to sort the integer values stored in array A in ascending order to the file output stream.
    file << "\n\n// Sort the integer values stored in array A to be in ascending order using the Bubble Sort algorithm.";
    file << "\nbubble_sort(A, S);";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of A to the command line terminal.
    std::cout << "\n\nA = " << A << ". // memory address of A[0]\n";

    // Print the contents of A to the file output stream.
    file << "\n\nA = " << A << ". // memory address of A[0]\n";

    /**
     * For each element, i, of the array represented by A, 
     * print the contents of the ith element of the array, A[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < S; i += 1) 
    {
        std::cout << "\nA[" << i << "] = " << A[i] << ".\t\t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
        file << "\nA[" << i << "] = " << A[i] << ".\t\t// &A[" << i << "] = " << &A[i] << ". (memory address of the first memory cell comprising the block of 4 contiguous memory cells allocated to A[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_3: CREATE A DYNAMIC ARRAY WHICH IS NAMED B AND WHICH IS COMPRISED OF T INT TYPE VALUES." to the command line terminal.
    std::cout << "\n\nSTEP_3: CREATE A DYNAMIC ARRAY WHICH IS NAMED B AND WHICH IS COMPRISED OF T INT TYPE VALUES.";

    // Print "STEP_3: CREATE A DYNAMIC ARRAY WHICH IS NAMED B AND WHICH IS COMPRISED OF T INT TYPE VALUES." to the file output stream.
    file << "\n\nSTEP_3: CREATE A DYNAMIC ARRAY WHICH IS NAMED B AND WHICH IS COMPRISED OF T INT TYPE VALUES.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Allocate T contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, B[0]. inside the pointer-to-int type variable named B.
    B = new int [T];

    // Print the program instruction used to generate the dynamic array represented by B to the command line terminal.
    std::cout << "\n\n// Declare a pointer-to-int type variable named B.";
    std::cout << "\nint * B;";
    std::cout << "\n\n// Allocate T contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, B[0], inside the pointer-to-int type variable named B.";
    std::cout << "\nB = new int [T];"; 

    // Print the program instruction used to generate the dynamic array represented by B to the file output stream.
    file << "\n\n// Declare a pointer-to-int type variable named B.";
    file << "\nint * B;";
    file << "\n\n// Allocate T contiguous int-sized chunks of memory and store the memory address of the first int-sized chunk of memory, B[0], inside the pointer-to-int type variable named B.";
    file << "\nB = new int [T];"; 

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of B to the command line terminal.
    std::cout << "\n\nB = " << B << ". // memory address of B[0]\n";

    // Print the contents of B to the file output stream.
    file << "\n\nB = " << B << ". // memory address of B[0]\n";

    /**
     * For each element, i, of the array represented by B, 
     * print the contents of the ith element of the array, B[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < T; i += 1) 
    {
        std::cout << "\nB[" << i << "] = " << B[i] << ".\t\t// &B[" << i << "] = " << &B[i] << ". (memory address of the first byte-sized memory cell comprising the block of 4 contiguous byte-sized memory cells allocated to B[" << i << "]).";
        file << "\nB[" << i << "] = " << B[i] << ".\t\t// &B[" << i << "] = " << &B[i] << ". (memory address of the first byte-sized memory cell comprising the block of 4 contiguous byte-sized memory cells allocated to B[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_4: FOR EACH ELEMENT B[i] OF THE ARRAY NAMED B, STORE THE NUMBER OF TIMES i APPEARS AS AN ELEMENT VALUE IN THE ARRAY NAMED A." to the command line terminal.
    std::cout << "\n\nSTEP_4: FOR EACH ELEMENT B[i] OF THE ARRAY NAMED B, STORE THE NUMBER OF TIMES i APPEARS AS AN ELEMENT VALUE IN THE ARRAY NAMED A.";

    // Print "STEP_4: FOR EACH ELEMENT B[i] OF THE ARRAY NAMED B, STORE THE NUMBER OF TIMES i APPEARS AS AN ELEMENT VALUE IN THE ARRAY NAMED A." to the file output stream.
    file << "\n\nSTEP_4: FOR EACH ELEMENT B[i] OF THE ARRAY NAMED B, STORE THE NUMBER OF TIMES i APPEARS AS AN ELEMENT VALUE IN THE ARRAY NAMED A.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    /**
     * For each element, i, of the array represented by B, 
     * store the number of times i appears as an element value in the array represented by A
     * in B[i].
     */ 
    for (i = 0; i < T; i += 1)
    {
        for (k = 0; k < S; k += 1) 
        {
            if (i == A[k]) B[i] += 1;
        }
    }

    // Print the contents of B to the command line terminal.
    std::cout << "\n\nB = " << B << ". // memory address of B[0]\n";

    // Print the contents of B to the file output stream.
    file << "\n\nB = " << B << ". // memory address of B[0]\n";

    /**
     * For each element, i, of the array represented by B, 
     * print the contents of the ith element of the array, B[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < T; i += 1) 
    {
        std::cout << "\nB[" << i << "] = " << B[i] << ".\t\t// &B[" << i << "] = " << &B[i] << ". (memory address of the first byte-sized memory cell comprising the block of 4 contiguous byte-sized memory cells allocated to B[" << i << "]).";
        file << "\nB[" << i << "] = " << B[i] << ".\t\t// &B[" << i << "] = " << &B[i] << ". (memory address of the first byte-sized memory cell comprising the block of 4 contiguous byte-sized memory cells allocated to B[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_5: CREATE A DYNAMIC ARRAY WHICH IS NAMED C AND WHICH IS COMPRISED OF T POINTER-TO-CHAR TYPE VALUES." to the command line terminal.
    std::cout << "\n\nSTEP_5: CREATE A DYNAMIC ARRAY WHICH IS NAMED C AND WHICH IS COMPRISED OF T POINTER-TO-CHAR TYPE VALUES.";

    // Print "STEP_5: CREATE A DYNAMIC ARRAY WHICH IS NAMED C AND WHICH IS COMPRISED OF T POINTER-TO-CHAR TYPE VALUES." to the file output stream.
    file << "\n\nSTEP_5: CREATE A DYNAMIC ARRAY WHICH IS NAMED C AND WHICH IS COMPRISED OF T POINTER-TO-CHAR TYPE VALUES.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Allocate T contiguous pointer-to-char-sized chunks of memory and store the memory address of the first pointer-to-char-sized chunk of memory, C[0], inside the pointer-to-pointer-to-char type variable named C.
    C = new char * [T];

    // C is a two-dimensional array which depicts a histogram (i.e. bar graph) such the length of the ith row is identical to the value stored in B[i].
    for (i = 0; i < T; i += 1) 
    {
        C[i] = new char [B[i]];
        for (k = 0; k < B[i]; k += 1) C[i][k] = 'X';
    }

    // Print the program instruction used to generate the dynamic array represented by C to the command line terminal.
    std::cout << "\n\n// Declare one pointer-to-pointer-to-char type variable.";
    std::cout << "\nchar ** C;";
    std::cout << "\n\n// Allocate T contiguous pointer-to-char-sized chunks of memory and store the memory address of the first pointer-to-char-sized chunk of memory, C[0], inside the pointer-to-pointer-to-char type variable named C.";
    std::cout << "\nC = new char * [T];";
    std::cout << "\n\n// C is a two-dimensional array which depicts a histogram (i.e. bar graph) such the length of the ith row is identical to the value stored in B[i].";
    std::cout << "\nfor (i = 0; i < T; i += 1)";
    std::cout << "\n{";
    std::cout << "\n    C[i] = new char [B[i]];";
    std::cout << "\n    for (k = 0; k < B[i]; k += 1) C[i][k] = 'X';";
    std::cout << "\n}";

    // Print the program instruction used to generate the dynamic array represented by C to the file output stream.
    file << "\n\n// Declare one pointer-to-pointer-to-char type variable.";
    file << "\nchar ** C;";
    file << "\n\n// Allocate T contiguous pointer-to-char-sized chunks of memory and store the memory address of the first pointer-to-char-sized chunk of memory, C[0], inside the pointer-to-pointer-to-char type variable named C.";
    file << "\nC = new char * [T];";
    file << "\n\n// C is a two-dimensional array which depicts a histogram (i.e. bar graph) such the length of the ith row is identical to the value stored in B[i].";
    file << "\nfor (i = 0; i < T; i += 1)";
    file << "\n{";
    file << "\n    C[i] = new char [B[i]];";
    file << "\n    for (k = 0; k < B[i]; k += 1) C[i][k] = 'X';";
    file << "\n}";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print the contents of C to the command line terminal.
    std::cout << "\n\nC = " << C << ". // memory address of C[0]\n";

    // Print the contents of C to the file output stream.
    file << "\n\nC = " << C << ". // memory address of C[0]\n";

    /**
     * For each element, i, of the array represented by C, 
     * print the contents of the ith element of the array, C[i], 
     * and the memory address of that array element 
     * to the command line terminal and to the file output stream.
     */
    for (i = 0; i < T; i += 1) 
    {
        std::cout << "\nC[" << i << "] = " << C[i] << ".\t\t// &C[" << i << "] = " << &C[i] << ". (memory address of the first byte-sized memory cell comprising the block of 8 contiguous byte-sized memory cells allocated to C[" << i << "]).";
        file << "\nC[" << i << "] = " << C[i] << ".\t\t// &C[" << i << "] = " << &C[i] << ". (memory address of the first byte-sized memory cell comprising the block of 8 contiguous byte-sized memory cells allocated to C[" << i << "]).";
    }

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "STEP_6: RELEASE MEMORY WHICH WAS ALLOCATED TO THE DYNAMIC ARRAYS NAMED A, B, AND C." to the command line terminal.
    std::cout << "\n\nSTEP_6: RELEASE MEMORY WHICH WAS ALLOCATED TO THE DYNAMIC ARRAYS NAMED A, B, AND C.";

    // Print "STEP_6: RELEASE MEMORY WHICH WAS ALLOCATED TO THE DYNAMIC ARRAYS NAMED A, B, AND C." to the file output stream.
    file << "\n\nSTEP_6: RELEASE MEMORY WHICH WAS ALLOCATED TO THE DYNAMIC ARRAYS NAMED A, B, AND C.";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    /**
     * Note that, unlike a static array, a dynamic array is instantiated during program runtime instead of during program compile time.
     * (A static array is assigned memory during program compilation while a dynamic array is assigned memory during program runtime).
     * At compile time, the computer does not know how much memory space to allocate to a dynamic array because the number of elements
     * in that array may vary and is not specified in the program source code.
     */

    // De-allocate memory which was assigned to the dynamically-allocated array of S int type values
    delete [] A;

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of S int type values to the command line terminal.
    std::cout << "\n\n// De-allocate memory which was assigned to the dynamically-allocated array of S int type values.";
    std::cout << "\ndelete [] A; // Free up S contiguous int-sized chunks of memory which were assigned to the dynamic array named A.";

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of S int type values to the file output stream.
    file << "\n\n// De-allocate memory which was assigned to the dynamically-allocated array of S int type values.";
    file << "\ndelete [] A; // Free up S contiguous int-sized chunks of memory which were assigned to the dynamic array named A.";

    // De-allocate memory which was assigned to the dynamically-allocated array of T int type values.
    delete [] B;

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of T int type values to the command line terminal.
    std::cout << "\n\nDe-allocate memory which was assigned to the dynamically-allocated array of T int type values.";
    std::cout << "\ndelete [] B; // Free up T contiguous int-sized chunks of memory which were assigned to the dynamic array named B.";

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of T int type values to the file output stream.
    file << "\n\nDe-allocate memory which was assigned to the dynamically-allocated array of T int type values.";
    file << "\ndelete [] B; // Free up T contiguous int-sized chunks of memory which were assigned to the dynamic array named B.";

    // De-allocate memory which was assigned to the dynamically-allocated array of T pointer-to-char type values.
    for (i = 0; i < T; i += 1) delete [] C[i];
    delete [] C;

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of T pointer-to-char type values to the command line terminal.
    std::cout << "\n\n// De-allocate memory which was assigned to the dynamically-allocated array of T pointer-to-char type values.";
    std::cout << "\nfor (i = 0; i < T; i += 1) delete [] C[i]; // Free up B[i] char-sized chunks of memory which were assigned to the dynamic array named C[i].";
    std::cout << "\ndelete [] C; // Free up T contiguous pointer-to-char-sized chunks of memory which were assigned to the dynamic array named C.";

    // Print the command to de-allocate memory which was assigned to the dynamically-allocated array of T pointer-to-char type values to the file output stream.
    file << "\n\n// De-allocate memory which was assigned to the dynamically-allocated array of T pointer-to-char type values.";
    file << "\nfor (i = 0; i < T; i += 1) delete [] C[i]; // Free up B[i] char-sized chunks of memory which were assigned to the dynamic array named C[i].";
    file << "\ndelete [] C; // Free up T contiguous pointer-to-char-sized chunks of memory which were assigned to the dynamic array named C.";

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}
