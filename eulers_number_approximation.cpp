/**
 * file: eulers_number_approximation.cpp
 * type: C++ (source file)
 * date: 16_SEPTEMBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // command line user interface input and output
#include <fstream> // file input and output
#define MAXIMUM_N 65 // constant which represents maximum N value 

/* function prototypes */
unsigned long long compute_factorial_of_N(int N);
long double approximate_eulers_number(int N, std::ostream & output);

/**
 * Compute N factorial (N!) using an iterative algorithm.
 * 
 * If N is a natural number, then N! is the product of exactly one instance 
 * of each unique natural number which is smaller than or equal to N. 
 * N! := N * (N - 1) * (N - 2) * (N - 3) * ... * 3 * 2 * 1. 
 * 
 * If N is zero, then N! is one.
 * 0! := 1.
 * 
 * The value returned by this function is a nonnegative integer (which is N factorial).
 * 
 * Assume that N is a nonnegative integer no larger than MAXIMUM_N.
 */
unsigned long long compute_factorial_of_N(int N)
{
    // Declare an int type variable (i.e. a variable for storing integer values) named i. 
    // Set the initial value which is stored in i to zero.
    int i = 0;

    // Declare an unsigned long long type variable (i.e. a variable for storing nonnegative integer values) named F. 
    // Set the initial value which is stored in F to zero.
    unsigned long long int F = 0; 

    // If N is larger than negative one and if N is not larger than MAXIMUM_N, set i to N. 
    // Otherwise, set i to 0.
    i = ((N > -1) && (N <= MAXIMUM_N)) ? N : 0; 

    // If N is larger than zero, set F to N.
    // Otherwise, set F to 1.
    F = (N > 0) ? N : 1; 

    // While i is larger than zero: execute the code block enclosed by the following curly braces.
    while (i > 0) 
    {
        // If i is larger than 1, multiply F by (i - 1).
        if (i > 1) F *= i - 1; 

        // Decrement i by 1.
        i -= 1; 
    }

    // Return the value stored in F.
    // The value stored in F is factorial N.
    // Factorial N is denoted by N followed by the exclamation mark.
    return F; // Return the value represented by N!
}

/**
 * Generate an approximation of the the mathematical constant named e (i.e. Euler’s Number).
 * 
 * Euler's Number can be defined as follows:
 * Let N be a natural number. Then,
 * as the value of N approaches INFINITY,
 * the value of (1 + (1/N)) ^ N approaches Euler's Number.
 * 
 * Euler's Number can also be defined as follows:
 * Let N be a nonnegative integer. Then,
 * as the value of N approaches INFINITY,
 * the sum of each instance of N unique terms such that each term of those N terms is
 * 1 divided by the factorial of some nonnegative integer which is smaller than or equal to N 
 * approaches Euler's Number.
 * 
 * The value returned by this function is a positive floating-point number (which is the Nth approximation of Euler's Number).
 * 
 * Assume that N is a nonnegative integer no larger than MAXIMUM_N.
 */
long double approximate_eulers_number(int N, std::ostream & output)
{
    // Declare a long double type variable (i.e. a variable for storing floating-point number values) named A. 
    // Set the initial value which is stored in A to zero.
    long double A = 0.0;

    // Declare an int type variable (i.e. a variable for storing integer values) named i. 
    // Set the initial value which is stored in i to zero.
    int i = 0;

    // Declare a pointer to an unsigned long long type variable named T.
    // T initially stores the value 0 and will later be used to store the memory address of a dynamically-allocated array of N unsigned long long type values.
    //
    // A pointer variable stores 0 or else the memory address of a variable of the corresponding data type.
    // The value stored in a pointer is a sixteen-character memory address which denotes the first memory cell in a chunk of contiguous memory cells
    // (and that chunk of contiguous memory cells is exactly as large as is the data capacity of a variable of that pointer's corresponding data type).
    // Note that each memory cell has a data capacity of one byte.
    unsigned long long * T;

    // If N is smaller than one or if N is larger than MAXIMUM_N, set N to one. 
    if ((N < 1) || (N > MAXIMUM_N)) N = 1;

    // Dynamically allocate N contiguous unsigned long long sized chunks of memory to an array for storing N floating-point values.
    // Store the memory address of the first element of that array in T.
    T = new unsigned long long [N];

    // Print the previous command and comments associated with that command to the output stream.
    output << "\n\n// Dynamically allocate N contiguous unsigned long long sized chunks of memory to an array for storing N floating-point values.";
    output << "\n// Store the memory address of the first element of that array in T.";
    output << "\nT = new unsigned long long [N];";

    // Print "A := {A}. // variable to store the Nth approximation of Euler's Number" to the output stream.
    output << "\n\nA := " << A << ". // variable to store the Nth approximation of Euler's Number";

    // Print "N := {N}. // number of elements in the array of unsigned long long type values pointed to by T" to the output stream.
    output << "\n\nN := " << N << ". // number of elements in the array of unsigned long long type values pointed to by T";

    // Print "sizeof(unsigned long long) = {sizeof(unsigned long long)}. // number of bytes" to the output stream.
    output << "\n\nsizeof(unsigned long long) = " << sizeof(unsigned long long) << ". // number of bytes";

    // Print "&T = {&T}. // memory address of unsigned long long type variable named T" to the output stream.
    output << "\n\n&T = " << &T << ". // memory address of unsigned long long type variable named T";

    // Print "T := {T}. // memory address which is stored in T" to the output stream.
    output << "\n\nT = " << T << ". // memory address which is stored in T";

    // Print "(*T) := {*T}. // unsigned long long type value whose address is stored in T" to the output stream.
    output << "\n\n(*T) = " << (*T) << ". // unsigned long long type value whose address is stored in T";

    // Print "Displaying the memory address of each element of array T..." to the output stream.
    output << "\n\nDisplaying the memory address of each element of array T...\n";

    // For each integer value represented by i (starting with 0 and ending with (N - 1) in ascending order): 
    // print the memory address of the ith element of the array represented by T to the output stream.
    for (i = 0; i < N; i += 1) 
    {
        // Print "&T[{i}] = {&T[i]}. // memory address of T[{i}]" to the output stream.
        output << "\n&T[" << i << "] = " << &T[i] << ". // memory address of T[" << i << "]";
    }

    // Print "Storing the factorial of each nonnegative integer which is smaller than N in array T..." to the output stream.
    output << "\n\nStoring the factorial of each nonnegative integer which is smaller than N in array T...\n";

    // For each integer value represented by i (starting with 0 and ending with (N - 1) in ascending order):
    // set the value of the ith element of array T to i! and
    // print the data value which is stored in the ith element of the array to the output stream.
    for (i = 0; i < N; i += 1) 
    {
        // Print "T[{i}] := factorial({i}) = {i}! = " to the output stream.
        output << "\nT[" << i << "] := factorial(" << i << ") = (" << i << ")! = ";

        // Store i! in T[i].
        T[i] = compute_factorial_of_N(i);

        // Print "{T[i]}." to the output stream.
        output << T[i] << ".";
    }

    // Print "Computing the appoximate value of Euler's Number by adding up the reciprocal of each value in array T..." to the output stream.
    output << "\n\nComputing the appoximate value of Euler's Number by adding up the reciprocal of each value in array T...\n";

    // For each integer value represented by i (starting with 0 and ending with (N - 1) in ascending order):
    // print the value of (1 / T[i]) to the output stream.
    for (i = 0; i < N; i += 1) output << "\n(1 / T[" << i << "]) = (1 / " << T[i] << ") = " << (long double) 1 / T[i] << ".";

    // For each integer value represented by i (starting with 0 and ending with (N - 1) in ascending order):
    // add the value of (1 / (N - i)!) to A and print the data value which is stored in A to the output stream.
    for (i = 0; i < N; i += 1) 
    {
        output << "\n\nA := A + (1 / (" << i << ")!)";
        output << "\n   = " << A << " + (1 / " << T[i] << ")";
        output << "\n   = " << A << " + " << (long double) 1 / T[i];
        A += (long double) 1 / T[i];
        output << "\n   = " << A << ".";
    }

    // De-allocate memory which was dynamically assigned to the array named T.
    delete [] T;

    // Return the value which is stored in A.
    return A;
}

/* program entry point */
int main()
{
    // Declare a file output stream object named file.
    std::ofstream file;

    // Declare an int type variable (i.e. a variable for storing integer values) named N. 
    // Set the initial value which is stored in N to one.
    int N = 1;

    // Declare a long double type variable (i.e. a variable for storing floating-point number values) named B. 
    // Set the initial value which is stored in B to one.
    long double B = 1.0;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If the file named eulers_number_approximation_output.txt does not already exist 
     * inside of the same file directory as the file named eulers_number_approximation.cpp, 
     * create a new file named eulers_number_approximation_output.txt in that directory.
     * 
     * Open the plain-text file named eulers_number_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("eulers_number_approximation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nSTART OF PROGRAM";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nSTART OF PROGRAM";
    file << "\n--------------------------------";

    // Print "Enter a nonnegative integer which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a nonnegative integer which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> N;

    // Compute the Nth approximation of Euler's Number and store the result in B.
    // Print the steps involved in generating the Nth approximation of Euler's Number to the command line terminal.
    B = approximate_eulers_number(N, std::cout);

    // Print the steps involved in generating the Nth approximation of Euler's Number to the file output stream.
    approximate_eulers_number(N, file);

    // Print "B ::= eulers_number_approximation(N) = {B}." to the command line terminal.
    std::cout << "\n\nB := eulers_number_approximation(N) := " << B << ".";

    // Print "B := eulers_number_approximation(N) := {B}." to the file output stream.
    file << "\n\nB = eulers_number_approximation(N) := " << B << ".";

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEND OF PROGRAM";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEND OF PROGRAM";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}
