/**
 * file: greatest_common_divisor.cpp
 * type: C++ (source file)
 * date: 26_SEPTEMBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // output file creation, output file overwriting, output file open, output file close
#define MAXIMUM_INPUT_VALUE 10000 // constant which represents the maximum value for A and for B

/** function prototype */
void print_greatest_common_divisor_computation_steps(int A, int B, std::ostream& output);

/** program entry point */
int main() 
{
    // Declare and initialize three int type variables.
    int A = 1, B = 1, input_additional_values = 1;

    // Declare a file output stream handler.
    std::ofstream file;

    /**
     * If the file named greatest_common_divisor.txt does not already exist 
     * inside of the same file directory as the file named greatest_common_divisor.cpp, 
     * create a new file named greatest_common_divisor_output.txt in that directory.
     * 
     * Open the plain-text file named greatest_common_divisor_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("greatest_common_divisor_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program computes the greatest common divisor of two natural numbers and prints the steps involved." to the command line terminal and to the file output stream.
    std::cout << "\n\nThis C++ program computes the greatest common divisor of two natural numbers and prints the steps involved.";
    file << "\n\nThis C++ program computes the greatest common divisor of two natural numbers and prints the steps involved.";

    while (input_additional_values != 0) 
    {

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Prompt the user to enter an input value for A (and print that prompt to the command line terminal and to the file output stream).
        std::cout << "\n\nEnter the first of two natural numbers (which will be stored in an int type variable named A) which is no larger than " << MAXIMUM_INPUT_VALUE << ": ";
        file << "\n\nEnter the first of two natural numbers (which will be stored in an int type variable named A) which is no larger than " << MAXIMUM_INPUT_VALUE << ": ";

        // Scan the command line terminal for the most recent keyboard input value. Store that value in A.
        std::cin >> A;

        // Print "The value which was entered for A is {A}." to the command line terminal and to the file output stream.
        std::cout << "\nThe value which was entered for A is " << A << ".";
        file << "\n\nThe value which was entered for A is " << A << ".";

        /**
         * If A is smaller than 1 or if A is larger than MAXIMUM_INPUT_VALUE, set A to 1. 
         * 
         * Print "A has been reset to 1 due to the fact that the input value for A was either less than one or else greater than {MAXIMUM_INPUT_VALUE}." 
         * to the command line terminal and to the file output stream.
         */
        if ((A < 1) || (A > MAXIMUM_INPUT_VALUE)) 
        {
            A = 1;
            std::cout << "\n\nA has been reset to 1 due to the fact that the input value for A was either less than one or else greater than " << MAXIMUM_INPUT_VALUE << ".";
            file << "\n\nA has been reset to 1 due to the fact that the input value for A was either less than one or else greater than " << MAXIMUM_INPUT_VALUE << ".";
        }

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Prompt the user to enter an input value for B (and print that prompt to the command line terminal and to the file output stream).
        std::cout << "\n\nEnter the second of two natural numbers (which will be stored in an int type variable named B) which is no larger than " << MAXIMUM_INPUT_VALUE << ": ";
        file << "\n\nEnter the second of two natural numbers (which will be stored in an int type variable named B) which is no larger than " << MAXIMUM_INPUT_VALUE << ": ";

        // Scan the command line terminal for the most recent keyboard input value. Store that value in B.
        std::cin >> B;

        // Print "The value which was entered for B is {B}." to the command line terminal and to the file output stream.
        std::cout << "\nThe value which was entered for B is " << B << ".";
        file << "\n\nThe value which was entered for B is " << B << ".";

        /**
         * If B is smaller than 1 or if B is larger than MAXIMUM_INPUT_VALUE, set B to 1. 
         * 
         * Print "B has been reset to 1 due to the fact that the input value for B was either less than one or else greater than {MAXIMUM_INPUT_VALUE}." 
         * to the command line terminal and to the file output stream.
         */
        if ((B < 1) || (B > MAXIMUM_INPUT_VALUE)) 
        {
            B = 1;
            std::cout << "\n\nB has been reset to 1 due to the fact that the input value for B was either less than one or else greater than " << MAXIMUM_INPUT_VALUE << ".";
            file << "\n\nB has been reset to 1 due to the fact that the input value for B was either less than one or else greater than " << MAXIMUM_INPUT_VALUE << ".";
        }

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Execute the greatest common divisor function (defined by this C++ source file) such that the computation steps and final result are printed to the comand line terminal.
        print_greatest_common_divisor_computation_steps(A, B, std::cout);

        // Execute the greatest common divisor function (defined by this C++ source file) such that the computation steps and final result are printed to the file output stream.
        print_greatest_common_divisor_computation_steps(A, B, file);

        // Ask the user whether or not to continue inputing values.
        std::cout << "\n\nWould you like to input new values for A and B? (Enter 1 if YES. Enter 0 if NO): ";

        // Scan the command line terminal for the most recent keyboard input value.
        std::cin >> input_additional_values;
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

/**
 * Use the Euclidean algorithm to compute the greatest common divisor of positive integers A and B.
 *
 * (This function assumes that A and B are each natural numbers which are not too large to be overflow values (i.e. values which are too large to be properly represented as positive quantities in the C++ int type variable)).
 *
 * (This function assumes that output is either std::cout, some ofstream object (pointing to a valid output file), or some other valid C++ output stream object).
 * 
 * Print each step of that iterative process to the output stream.
 */
void print_greatest_common_divisor_computation_steps(int A, int B, std::ostream& output)
{
    int i = 0, remainder = 0;
    output << "\n\nComputing the greatest common divisor of A and B using the Euclidean algorithm...";
    while (B != 0) 
    {
        remainder = A % B;
        output << "\n\nstep_" << i << ": ";
        output << "A = " << A << ", B = " << B << ", gcd(A,B) = A % B = " << remainder << ".";
        A = B;
        B = remainder;
        i += 1;
    }
    output << "\n\nThe greatest common divisor of A and B is " << A;
}
