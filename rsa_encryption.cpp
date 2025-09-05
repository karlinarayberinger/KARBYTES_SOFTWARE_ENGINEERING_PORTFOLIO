/**
 * file: rsa_encryption.cpp
 * type: C++ (source file)
 * date: 06_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // output file creation, output file overwriting, output file open, output file close
#include <cmath> // std::log(), std::sqrt()
#include <stdio.h> // NULL macro
#include <cstdlib> // std::srand(), std::rand()
#include <ctime> // std::time() 
#define MAXIMUM_N 1000 // constant which represents the maximum value for N

/** function prototypes */
int * generate_array_of_first_n_primes(int N);
int select_random_element_from_array_of_integers(int * A, int N);
int gcd(int A, int B);
long long mod_exp(long long base, long long exp, long long mod);
long long mod_inverse(long long e, long long phi);
long long select_random_natural_number(int maximum_value);

/** program entry point */
int main() 
{
    // Declare two int type variables which will each store a non-identical prime number.
    int p, q;

    // Declare one long long type variable which will represent the product of p and q and which is part of a public key and private key pairing in an RSA cryptographic system.
    long long n;

    /**
     * Declare one long long type variable which will represent, ϕ(n), the output of the following Euler's Totient function of n: 
     * ϕ(n) = (p − 1) * (q − 1).
     * 
     * The totient function represents the number of integers less than n which are coprime with n 
     * (i.e. the number of integers which are no smaller than 1 and which are no larger than (n - 1) 
     * which share no common factors with n other than 1).
     */
    long long phi;

    // Declare one long long type variable to represent a value e such that 1 < e < phi and gcd(e, phi) = 1.
    long long e;

    // Declare one long long type variable to represent a private key value such that (e ∗ d) % ϕ(n) = 1.
    long long d;

    // Declare one long long type variable to represent a "message" in the form of a natural number no larger than n.
    long long m;

    // Declare one long long type variable to represent the cyphertext such that m = (c ^ d) % n.
    long long c;

    // Declare one long long type variable to represent the decrypted message such that m = (c ^ d) % n.
    long long decrypted_message;

    // Declare and initialize one int type variable which represents the number of elements to store in the dymanic array named A.
    int N = MAXIMUM_N;

    /**
     * Declare a pointer-to-int type variable for storing the address of the first element of a dynamic array of N int type values.
     * A will store the first N prime numbers in ascending order.
     * p and q will each be set to different prime numbers which are randomly selected from A.
     */
    int * A;

    // Declare a file output stream handler.
    std::ofstream file;

    /**
     * If the file named rsa_encryption_output.txt does not already exist 
     * inside of the same file directory as the file named rsa_encryption.cpp, 
     * create a new file named rsa_encryption_output.txt in that directory.
     * 
     * Open the plain-text file named rsa_encryption_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("rsa_encryption_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program demonstrates RSA (Rivest–Shamir–Adleman) encryption and decryption." to the command line terminal and to the file output stream.
    std::cout << "\n\nThis C++ program demonstrates RSA (Rivest–Shamir–Adleman) encryption and decryption.";
    file << "\n\nThis C++ program demonstrates RSA (Rivest–Shamir–Adleman) encryption and decryption.";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print "STEP_0: Key Generation" to the command line terminal and to the file output stream.
    std::cout << "\n\nSTEP_0: Key Generation";
    file << "\n\nSTEP_0: Key Generation";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Call the function which generates the first N primes and returns a dynamic array which is populated by those primes.
    A = generate_array_of_first_n_primes(N);

    // Set the value of p to a randomly-selected value in A (which is a prime number).
    p = select_random_element_from_array_of_integers(A, N);

    // Set the value of q to a randomly-selected value in A which is not the same value as p (and which is also a prime number).
    q = p;
    while (p == q) q = select_random_element_from_array_of_integers(A, N);

    // Print the values of p and q to the command line terminal and to the output file stream.
    std::cout << "\n\np = " << p << " // first prime number";
    std::cout << "\n\nq = " << q << " // second prime number";
    file << "\n\np = " << p << " // first prime number";
    file << "\n\nq = " << q << " // second prime number";

    // Print the value of n to the command line terminal and to the output file stream.
    n = p * q;
    std::cout << "\n\nn = p * q = " << n << " // the modulus in both the encryption and the decryption processes";
    file << "\n\nn = p * q = " << n << " // the modulus in both the encryption and the decryption processes";

    // Print the value of phi to the command line terminal and to the output file stream.
    phi = (p - 1) * (q - 1); 
    std::cout << "\n\nphi = (p - 1) * (q - 1) = " << phi << " // Euler's Totient function: ϕ(n) = (p − 1) * (q − 1)";
    file << "\n\nphi = (p - 1) * (q - 1) = " << phi << " // Euler's Totient function: ϕ(n) = (p − 1) * (q − 1)";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print "STEP_1: Choose e such that 1 < e < phi and gcd(e, phi) = 1" to the command line terminal and to the file output stream.
    std::cout << "\n\nSTEP_1: Choose e such that 1 < e < phi and gcd(e, phi) = 1";
    file << "\n\nSTEP_1: Choose e such that 1 < e < phi and gcd(e, phi) = 1";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Select a value for e which is no smaller than one and no larger than phi.
    e = select_random_natural_number(phi); 
    while (gcd(e, phi) != 1) e = select_random_natural_number(phi);

    // Print the value of e to the command line terminal and to the output file stream.
    std::cout << "\n\ne = " << e << " // public exponent";
    file << "\n\ne = " << e << " // public exponent";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print "STEP_2: Compute the private key (d)" to the command line terminal and to the file output stream.
    std::cout << "\n\nSTEP_2: Compute the private key (d)";
    file << "\n\nSTEP_2: Compute the private key (d)";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print the value of d to the command line terminal and to the output file stream.
    d = mod_inverse(e, phi);
    std::cout << "\n\nd = " << d << " // such that (e ∗ d) % ϕ(n) = 1";
    file << "\n\nd = " << d << " // such that (e ∗ d) % ϕ(n) = 1";

    // Print a warning message if the modular inverse of d is determined by the program logic not to exist.
    if (d == -1) 
    {
        std::cout << "\n\nWARNING: Modular inverse of e does not exist.";
        file << "\n\nWARNING: Modular inverse of e does not exist.";
    }

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print "STEP_3: Display the public and private keys" to the command line terminal and to the file output stream.
    std::cout << "\n\nSTEP_3: Display the public and private keys";
    file << "\n\nSTEP_3: Display the public and private keys";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print the public and private keys to the command line terminal and to the file output stream.
    std::cout << "\n\nPublic Key: (" << e << ", " << n << ")";
    std::cout << "\n\nPrivate Key: (" << d << ", " << n << ")";
    file << "\n\nPublic Key: (" << e << ", " << n << ")";
    file << "\n\nPrivate Key: (" << d << ", " << n << ")";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print "STEP_4: Encrypt a message (m must be less than n)" to the command line terminal and to the file output stream.
    std::cout << "\n\nSTEP_4: Encrypt a message (m must be less than n)";
    file << "\n\nSTEP_4: Encrypt a message (m must be less than n)";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Prompt the user to enter a positive integer value to store in the variable named m.
    std::cout << "\n\nEnter a message to encrypt (as a positive integer less than " << n << "): ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in m.
    std::cin >> m;

    // Print "The value which was entered for m is {m}." to the command line terminal and to the file output stream.
    std::cout << "\n\nThe value which was entered for m is " << m << ".";
    file << "\n\nThe value which was entered for m is " << m << ".";

    /**
     * If m is smaller than 1 or if m is larger than or equal to n, set m to (n - 1). 
     * 
     * Print "m has been reset to {n - 1} due to the fact that the input value for m was either less than one or else greater than {n - 1}." 
     * to the command line terminal and to the file output stream.
     */
    if ((m < 1) || (m >= n)) 
    {
        m = n - 1;
        std::cout << "\n\nm has been reset to " << (n - 1) << " due to the fact that the input value for m was either less than one or else greater than " << (n - 1) << ".";
        file << "\n\nm has been reset to " << (n - 1)  << " due to the fact that the input value for m was either less than one or else greater than " << (n - 1) << ".";
    }

    // Print the value of d to the command line terminal and to the output file stream.
    c = mod_exp(m, e, n);
    std::cout << "\n\nc = (m ^ e) % n = " << c << " // encryption such that m = (c ^ d) % n";
    file << "\n\nc = (m ^ e) % n = " << c << " // encryption such that m = (c ^ d) % n";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print "STEP_5: Decrypt the message" to the command line terminal and to the file output stream.
    std::cout << "\n\nSTEP_5: Decrypt the message";
    file << "\n\nSTEP_5: Decrypt the message";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Print the value of decrypted_message to the command line terminal and to the output file stream.
    decrypted_message = mod_exp(c, d, n);
    std::cout << "\n\ndecrypted_message = " << decrypted_message << " // such that m = (c ^ d) % n";
    file << "\n\ndecrypted_message = " << decrypted_message << " // such that m = (c ^ d) % n";

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
 * 
 * Note that this function was copied from the C++ source code featured on the following tutorial web page: 
 * https://karbytesforlifeblog.wordpress.com/prime_number_generation/
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

/**
 * Randomly select an element from an array containing N int-type values.
 * 
 * Assume that A stores the memory address of the first element of an array of N int-type values.
 * 
 * Assume that N is a natural number no larger than MAXIMUM_N (and return -1 if N is "out of range").
 * 
 * Physically (and not just logically), A is assumed to represent N contiguous four-byte chunks of random access memory.
 * 
 * For details on how arrays and pointers work in C++ (and how to determine the number of bytes which a particular variable occupies),
 * visit the following tutorial web page:
 * 
 * https://karlinaobject.wordpress.com/pointers_and_arrays
 */
int select_random_element_from_array_of_integers(int * A, int N)
{
    if ((N < 1) || (N > MAXIMUM_N)) 
    {
        std::cout << "\n\nError: the N value passed into select_random_element_from_array_of_integers(int * A, int N) must be a natural number no larger than " << MAXIMUM_N << ".";
        return -1;
    }

    /**
     * Seed the pseudo-random number generator with the number of non-leap seconds 
     * elapsed since some epoch such as the Unix Epoch (which is 01_JANUARY_1970).
     * 
     * According to ChatGPT-4o, "Leap seconds are extra seconds added to Coordinated Universal Time (UTC) 
     * to keep it synchronized with Earth's irregular rotation. The Earth's rotation is not perfectly consistent, 
     * so occasionally, a leap second is added to adjust the difference between atomic time (measured by highly accurate 
     * atomic clocks) and astronomical time (based on Earth's rotation). These adjustments ensure that UTC remains within 
     * 0.9 seconds of UT1, the time standard based on Earth's rotation."
     */
    srand(time(NULL));
    
    // Generate a random array index number (which is a value in the set [0, (N - 1)]).
    int random_index = std::rand() % N;

    // Return the integer value stored in the array named A at the randomly-selected array index.
    return A[random_index];
}

/**
 * Use the Euclidean algorithm to compute the greatest common divisor of positive integers A and B.
 *
 * (This function assumes that A and B are each natural numbers which are not too large to be overflow values (i.e. values which are too large to be properly represented as positive quantities in the C++ int type variable)).
 * 
 * This function is a simplified version (i.e. without printing computational steps to an output stream) of a function which was copied from the following tutorial web page:
 * 
 * https://karbytesforlifeblog.wordpress.com/greatest_common_divisor/
 */
int gcd(int A, int B)
{
    int i = 0, remainder = 0;
    while (B != 0) 
    {
        remainder = A % B;
        A = B;
        B = remainder;
        i += 1;
    }
    return A;
}

/**
 * Calculate (base ^ exp) % mod using modular exponentiation.
 * 
 * base may be any integer value (positive, zero, or negative), provided that it can be represented within the type long long (typically a 64-bit signed integer).
 * 
 * (For a typical 64-bit operating system, LLONG_MIN = -9,223,372,036,854,775,808 and LLONG_MAX = 9,223,372,036,854,775,807).
 * 
 * exp may be any non-negative integer provided it can be represented within the type long long (typically a 64-bit signed integer).
 * 
 * mod may be any positive integer provided it can be represented within the type long long (typically a 64-bit signed integer).
 */
long long mod_exp(long long base, long long exp, long long mod) 
{
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd, multiply base with result
            result = (result * base) % mod;
        exp = exp >> 1;   // Divide exp by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

/**
 * Calculate the modular multiplicative inverse of e using the Extended Euclidean Algorithm.
 * 
 * If e does not have an inverse (that is, if e and phi are not coprime), the function returns -1.
 * 
 * e is the number whose modular inverse is to be calculated.
 * 
 * e should be a positive integer in the set [1, (phi - 1)].
 * 
 * phi is the modulus (often referred to as ϕ in cryptographic applications).
 * 
 * phi should be a positive integer.
 */
long long mod_inverse(long long e, long long phi) {
    long long t = 0, new_t = 1;
    long long r = phi, new_r = e;
    while (new_r != 0) 
    {
        long long quotient = r / new_r;
        t = t - quotient * new_t;
        std::swap(t, new_t);
        r = r - quotient * new_r;
        std::swap(r, new_r);
    }
    if (r > 1) return -1;  // e is not invertible
    if (t < 0) t += phi;
    return t;
}

// Return a natural number which is no smaller than 1 and no larger than maximum_value.
long long select_random_natural_number(int maximum_value)
{
    /**
     * Seed the pseudo-random number generator with the number of non-leap seconds 
     * elapsed since some epoch such as the Unix Epoch (which is 01_JANUARY_1970).
     * 
     * According to ChatGPT-4o, "Leap seconds are extra seconds added to Coordinated Universal Time (UTC) 
     * to keep it synchronized with Earth's irregular rotation. The Earth's rotation is not perfectly consistent, 
     * so occasionally, a leap second is added to adjust the difference between atomic time (measured by highly accurate 
     * atomic clocks) and astronomical time (based on Earth's rotation). These adjustments ensure that UTC remains within 
     * 0.9 seconds of UT1, the time standard based on Earth's rotation."
     */
    srand(time(NULL));

    // Return a randomly generated integer which is no smaller than one and no larger than maximum_value.
    return (std::rand() % maximum_value) + 1;
}
