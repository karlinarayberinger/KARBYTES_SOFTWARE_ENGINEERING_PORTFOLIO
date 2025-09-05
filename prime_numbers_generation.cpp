/**
 * file: prime_numbers_generation.cpp
 * type: C++ (source file)
 * date: 04_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // output file creation, output file overwriting, output file open, output file close
#include <cmath> // std::log(), std::sqrt()
#include <algorithm> // std::fill()
#define MAXIMUM_N 10000 // constant which represents the maximum value for N

/** function prototype(s) */
int * generate_array_of_first_n_primes(int N);

/** program entry point */
int main() 
{
    // Declare and initialize one int type variable for defining the number of elements to store in an array named A.
    int N = 1;

    // Declare and initialize one int type variable for incrementing across each element of array A when printing the contents of that array.
    int i = 0;

    // Declare a pointer-to-int type variable for storing the address of the first element of a dynamic array of N int type values.
    int * A;

    // Declare a file output stream handler.
    std::ofstream file;

    /**
     * If the file named prime_numbers_generation_output.txt does not already exist 
     * inside of the same file directory as the file named prime_numbers_generation.cpp, 
     * create a new file named prime_numbers_generation_output.txt in that directory.
     * 
     * Open the plain-text file named prime_numbers_generation_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("prime_numbers_generation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program generates the first N prime numbers using an algorithm named the Sieve of Eratosthenes." to the command line terminal and to the file output stream.
    std::cout << "\n\nThis C++ program generates the first N prime numbers using an algorithm named the Sieve of Eratosthenes.";
    file << "\n\nThis C++ program generates the first N prime numbers using an algorithm named the Sieve of Eratosthenes.";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Prompt the user to enter an input value for N (and print that prompt to the command line terminal and to the file output stream).
    std::cout << "\n\nEnter a natural number, N, which is the number of prime numbers to generate and which is no larger than " << MAXIMUM_N << ": ";
    file << "\n\nEnter a natural number, N, which is the number of prime numbers to generate and which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in N.
    std::cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal and to the file output stream.
    std::cout << "\nThe value which was entered for N is " << N << ".";
    file << "\n\nThe value which was entered for N is " << N << ".";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Call the function which generates the first N primes and returns a dynamic array which is populated by those primes.
    A = generate_array_of_first_n_primes(N);

    // Print the contents of the array named A to the command line terminal and to the file output stream.
    for (i = 0; i < N; i += 1)
    {
        std::cout << "\n\nA[" << i << "] := " << A[i] << ". // memory address: " << &A[i] << ".";
        file << "\n\nA[" << i << "] := " << A[i] << ". // memory address: " << &A[i] << ".";
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

    // De-allocate memory which was allocated to the int array's instantiation.
    delete [] A;

    // Exit the program.
    return 0; 
}

/**
 * Generate the first N prime numbers using an algorithm named the Sieve of Eratosthenes.
 * 
 * If N is smaller than one or larger than MAXIMUM_N, set N to ten.
 * 
 * Return a pointer to a dynamically-allocated int-type array whose elements are the aforementioned prime numbers
 * listed in order of increasing size (with the first element of that array (i.e. A[0]) storing the smallest prime number).
 */
int * generate_array_of_first_n_primes(int N) 
{
    // Declare and initialize an incrementor variable for traversing each array element of an array.
    int i = 0;

    // Validate the function input and correct that input if it is determined to be an "out of range" value.
    if ((N < 1) || (N > MAXIMUM_N)) N = 10;

    /**
     * Estimate an upper bound for the Nth prime number using the Prime Number Theorem.
     * 
     * According to Wikipedia, the Prime Number Theorem, "formalizes the intuitive idea that primes 
     * become less common as they become larger by precisely quantifying the rate at which this occurs."
     * 
     * In the following command, if N is less than six, then set the upper bound limit to fifteen.
     * Otherwise (if N is larger than or equal to six), set N to the rounded down integer value of
     * (log_base_e(N) + (N * log_base_e(log_base_e(N)))).
     */
    int limit = (N < 6) ? 15 : (int) (N * std::log(N) + N * std::log(std::log(N)));

    // Create a (local to this function) dynamic array of Boolean-type values which identifies which numbers are prime numbers.
    bool * isPrime = new bool[limit + 1];

    // Assume that all numbers are prime initially.
    std::fill(isPrime, isPrime + limit + 1, true); 

    // 0 and 1 are not prime numbers.
    isPrime[0] = isPrime[1] = false;  

    /**
     * Deploy the Sieve of Eratosthenes.
     * 
     * Initialize p to 2
     * While p is less than or equal to the square root of the limit:
     *     If isPrime[p] is true:
     *         For each i starting from p squared and going up to the limit:
     *             Mark isPrime[i] as false (i is not a prime)
     *     Increment p by 1
     */
    for (int p = 2; p <= std::sqrt(limit); ++p) 
    {
        if (isPrime[p]) 
        {
            for (int i = p * p; i <= limit; i += p) 
            {
                isPrime[i] = false;
            }
        }
    }

    // Instantiate a dynamic array of int-type values which represents the first N prime numbers listed in ascending order.
    int * primes = new int[N];

    // Set count to zero.
    int count = 0;

    /**
     * For each p starting from 2, while p is less than or equal to the limit and count is less than N:
     *     If isPrime[p] is true:
     *         Store p in primes[count]
     *         Increment count by 1
     */
     for (int p = 2; p <= limit && count < N; ++p) 
     {
        if (isPrime[p]) 
        {
            primes[count] = p;
            ++count;
        }
    }

    // De-allocate memory which was allocated to the Boolean array's instantiation.
    delete [] isPrime;

    // Return the dynamic array of prime numbers.
    return primes;  
}
