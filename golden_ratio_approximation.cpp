/**
 * file: golden_ratio_approximation.cpp
 * type: C++ (source file)
 * date: 14_JUNE_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_N 92 // constant which represents maximum N value

/* function prototypes */
unsigned long long compute_Nth_fibonacci_sequence_term_using_iteration(int N);
long double golden_ratio_approximation(int N, std::ostream & output);

/**
 * Compute the Nth term of the Fibonacci Sequence using an iterative algorithm.
 * 
 * Assume that N is an integer value.
 * 
 * For each while loop iteration, i, 
 * print an algebraic expression which represents the ith term of the Fibonacci Sequence.
 * 
 * fibonacci(0) := 1. // The first term of the Fibonacci Sequence is 1.
 * fibonacci(1) := 1. // The second term of the Fibonacci Sequence is 1.
 * fibonacci(i) := fibonacci(i - 2) + fibonacci(i - 1). // if i is a natural number larger than 1
 */
unsigned long long compute_Nth_fibonacci_sequence_term_using_iteration(int N)
{
    int i = 0;
    unsigned long long A = 1, B = 1, C = 0;
    if ((N < 2) || (N > MAXIMUM_N)) return 1;
    for (i = 1; i < N; i += 1) 
    {
        C = A;
        A = B;
        B += C;
    }
    return B;
}

/**
 * Compute the approximate value of the Golden Ratio by dividing the Nth term of the Fibonacci Sequence by the (N - 1)th term of the Fibonacci Sequence.
 * 
 * Assume that N is an integer value and that output is an output stream object.
 * 
 * For each Golden Ratio approximation, i,
 * print an algebraic expression which represents the ith Golden Ratio approximation 
 * (and the ith Golden Ratio approximation is produced by dividing fibonacci(i) by fibonacci(i - 1)).
 * 
 * golden_ratio := (1 + square_root(2)) / 5. 
 * golden_ratio_approximation(N) := fibonacci(N) / fibonacci(N - 1). 
 */
long double golden_ratio_approximation(int N, std::ostream & output)
{
    unsigned long long A = 0, B = 0; 
    long double C = 0.0;
    if ((N < 0) || (N > MAXIMUM_N)) N = 0;
    A = compute_Nth_fibonacci_sequence_term_using_iteration(N);
    B = compute_Nth_fibonacci_sequence_term_using_iteration(N - 1);
    C = (long double) A / B;
    output << "\n\ngolden_ratio_approximation(" << N << ") = fibonacci(" << N << ") / fibonacci(" << N - 1 << ").";
    output << "\ngolden_ratio_approximation(" << N << ") = " << A << " / " << B << ".";
    output << "\ngolden_ratio_approximation(" << N << ") = " << C << ".";
    return C;
}

/* program entry point */
int main()
{
    // Declare two int type variables for storing whole numbers and set their initial values to 0.
    int N = 0, i = 0;

    // Declare a long double type variable for storing floating-point numbers and set its initial value to 0. 
    long double G = 0.0;

    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If golden_ratio_approximation_output.txt does not already exist in the same directory as golden_ratio_approximation.cpp, 
     * create a new file named golden_ratio_approximation_output.txt .
     * 
     * Open the plain-text file named golden_ratio_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("golden_ratio_approximation_output.txt");

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

    // Print the data size of an int type variable to the command line terminal.
    std::cout << "\n\nsizeof(int) = " << sizeof(int) << " byte(s).";

    // Print the data size of an int type variable to the file output stream.
    file << "\n\nsizeof(int) = " << sizeof(int) << " byte(s).";

    // Print the data size of an unsigned int type variable to the command line terminal.
    std::cout << "\n\nsizeof(unsigned int) = " << sizeof(unsigned int) << " byte(s).";

    // Print the data size of an unsigned int type variable to the file output stream.
    file << "\n\nsizeof(unsigned int) = " << sizeof(unsigned int) << " byte(s).";

    // Print the data size of a long type variable to the command line terminal.
    std::cout << "\n\nsizeof(long) = " << sizeof(long) << " byte(s).";

    // Print the data size of a long type variable to the file output stream.
    file << "\n\nsizeof(long) = " << sizeof(long) << " byte(s).";

    // Print the data size of an unsigned long type variable to the command line terminal.
    std::cout << "\n\nsizeof(unsigned long) = " << sizeof(unsigned long) << " byte(s).";

    // Print the data size of an unsigned long type variable to the file output stream.
    file << "\n\nsizeof(unsigned long) = " << sizeof(unsigned long) << " byte(s).";

    // Print the data size of a long long type variable to the command line terminal.
    std::cout << "\n\nsizeof(long long) = " << sizeof(long long) << " byte(s).";

    // Print the data size of a long long type variable to the file output stream.
    file << "\n\nsizeof(long long) = " << sizeof(long long) << " byte(s).";

    // Print the data size of an unsigned long long  type variable to the command line terminal.
    std::cout << "\n\nsizeof(unsigned long long) = " << sizeof(unsigned long long) << " byte(s).";

    // Print the data size of an unsigned long long type variable to the file output stream.
    file << "\n\nsizeof(unsigned long long) = " << sizeof(unsigned long long) << " byte(s).";

    // Print the data size of a bool type variable to the command line terminal.
    std::cout << "\n\nsizeof(bool) = " << sizeof(bool) << " byte(s).";

    // Print the data size of a bool type variable to the file output stream.
    file << "\n\nsizeof(bool) = " << sizeof(bool) << " byte(s).";

    // Print the data size of a char type variable to the command line terminal.
    std::cout << "\n\nsizeof(char) = " << sizeof(char) << " byte(s).";

    // Print the data size of a char type variable to the file output stream.
    file << "\n\nsizeof(char) = " << sizeof(char) << " byte(s).";

    // Print the data size of a float type variable to the command line terminal.
    std::cout << "\n\nsizeof(float) = " << sizeof(float) << " byte(s).";

    // Print the data size of a float type variable to the file output stream.
    file << "\n\nsizeof(float) = " << sizeof(float) << " byte(s).";

    // Print the data size of a double type variable to the command line terminal.
    std::cout << "\n\nsizeof(double) = " << sizeof(double) << " byte(s).";

    // Print the data size of a double type variable to the file output stream.
    file << "\n\nsizeof(double) = " << sizeof(double) << " byte(s).";

    // Print the data size of a long double type variable to the command line terminal.
    std::cout << "\n\nsizeof(long double) = " << sizeof(long double) << " byte(s).";

    // Print the data size of a long double type variable to the file output stream.
    file << "\n\nsizeof(long double) = " << sizeof(long double) << " byte(s).";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Enter a natural number which is no larger than {MAXIMUM_N}: " to the command line terminal.
    std::cout << "\n\nEnter a natural number which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal.
    std::cout << "\nThe value which was entered for N is " << N << ".";

    // Print "The value which was entered for N is {N}." to the file output stream.
    file << "\n\nThe value which was entered for N is " << N << ".";

    // If N is smaller than 1 or if N is larger than MAXIMUM_N, set N to 1.
    N = ((N < 1) || (N > MAXIMUM_N)) ? 1 : N; // A tertiary operation (using the tertiary operator (?)) is an alternative to using if-else statements.

    // Print "N := {N}." to the command line terminal.
    std::cout << "\n\nN := " << N << ".";

    // Print "N := {N}." to the file output stream.
    file << "\n\nN := " << N << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Computing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:" to the command line terminal.
    std::cout << "\n\nComputing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:";

    // Print "Computing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:" to the file output stream.
    file << "\n\nComputing the first N Golden Ratio approximations by dividing adjacent terms of the Fibonacci Sequence:";

    // Print the first N Golden Ratio approximations to the command line terminal and to the file output stream.
    for (i = 1; i <= N; i += 1) 
    {
        G = golden_ratio_approximation(i, std::cout); // Print comments to the command line terminal.
        golden_ratio_approximation(i, file); // Print comments to the file output stream.
        std::cout << "\nG = golden_ratio_approximation(" << i << ") = " << G << ".";
        file << "\nG = golden_ratio_approximation(" << i << ") = " << G << ".";
    }

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
