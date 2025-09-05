/**
 * file: prime_factorization.cpp
 * type: C++ (source file)
 * date: 04_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // output file creation, output file overwriting, output file open, output file close
#define MAXIMUM_N 10000 // constant which represents the maximum value for N

/** function prototype */
void print_prime_factorization(int N, std::ostream& output);

/** program entry point */
int main() 
{
    // Declare and initialize two int type variables.
    int N = 0, input_additional_values = 1;

    // Declare a file output stream handler.
    std::ofstream file;

    /**
     * If the file named prime_factorization_output.txt does not already exist 
     * inside of the same file directory as the file named prime_factorization.cpp, 
     * create a new file named prime_factorization_output.txt in that directory.
     * 
     * Open the plain-text file named prime_factorization_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("prime_factorization_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    while (input_additional_values != 0) 
    {
        // Prompt the user to enter an input value for N.
        std::cout << "\n\nEnter a nonnegative integer value to store in the variable named N which is no larger than " << MAXIMUM_N << " to factor into its constituent prime number multiplicative terms: ";
        file << "\n\nEnter a nonnegative integer value to store in the variable named N which is no larger than " << MAXIMUM_N << " to factor into its constituent prime number multiplicative terms: ";

        // Scan the command line terminal for the most recent keyboard input value. Store that value in N.
        std::cin >> N;

        // Print "The value which was entered for N is {N}." to the command line terminal.
        std::cout << "\nThe value which was entered for N is " << N << ".";

        // Print "The value which was entered for N is {N}." to the file output stream.
        file << "\n\nThe value which was entered for N is " << N << ".";

        // If N is smaller than 0 or if N is larger than MAXIMUM_N, set N to 10.
        N = ((N < 0) || (N > MAXIMUM_N)) ? 10 : N; 

        // Print the prime number factorization for N to the command line terminal.
        print_prime_factorization(N, std::cout);

        // Print the prime number factorization for N to the file output stream.
        print_prime_factorization(N, file);

        // Ask the user whether or not to continue inputing values.
        std::cout << "\n\nWould you like to continue inputting program values? (Enter 1 if YES. Enter 0 if NO): ";

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
 * Use an iterative method to generate each of the prime number multiplicative terms of some nonnegative integer, N.
 * 
 * A prime number is a natural number which is larger than or equal to 2 and which is the multiplicative product of only itself and 1.
 * 
 * A composite number is a natural number which is larger than 1 and which is the multiplicative product of two or more prime numbers.
 */
void print_prime_factorization(int N, std::ostream& output) 
{
    if (N <= 1) 
    {
        output << "\n\n" << N << " is not factorizable into multiple prime number multiplicative terms.";
        return;
    }

    output << "\n\nPrime factorization of " << N << " is: ";
    
    int divisor = 2; // Start with the smallest prime number.
    bool first_factor = true;
    
    while (N > 1) 
    {
        while (N % divisor == 0) 
        {
            if (!first_factor)
            {
                output << " * "; // Separate factors with a multiplication symbol.
            }
            output << divisor;
            N /= divisor;
            first_factor = false;
        }
        divisor++;
    }
    output << ".";
}
