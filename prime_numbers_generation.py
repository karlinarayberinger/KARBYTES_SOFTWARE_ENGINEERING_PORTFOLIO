#########################################################################################
# file: prime_numbers_generation.py
# type: Python
# date: 05_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

import math # math.log(), math.sqrt() # Note that the math.log() is the natural logarithm 

def generate_primes(N):
    """Generate an array of the first N prime numbers using the Sieve of Eratosthenes algorithm."""
    
    # Validate the function input and correct that input if it is determined to be an "out of range" value.
    if N < 1 or N > 10000:
        N = 10

    # Calculate an upper limit for the sieve
    limit = 15 if N < 6 else int(N * math.log(N) + N * math.log(math.log(N)))
    
    # Create a boolean array "is_prime[0..limit]" and initialize all entries as true.
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False  # 0 and 1 are not prime numbers.
    
    # Use the Sieve of Eratosthenes.
    for p in range(2, int(math.sqrt(limit)) + 1):
        if is_prime[p]:
            for i in range(p * p, limit + 1, p):
                is_prime[i] = False
    
    # Collect the first N primes.
    primes = []
    count = 0
    for p in range(2, limit + 1):
        if is_prime[p]:
            primes.append(p)
            count += 1
        if count == N:
            break
    
    return primes

def main():
    # Declare and initialize the number of primes to generate.
    N = 1

    # Declare an empty array to store the first N primes.
    A = []

    # Open the output file for writing
    with open("prime_numbers_generation_output.txt", "w") as file:

        # Print an opening message to the command line terminal.
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")

        # Print an opening message to the output file.
        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        # Print "This Python program generates the first N prime numbers using an algorithm named the Sieve of Eratosthenes." to the command line terminal and to the output file.
        print("\n\nThis Python program generates the first N prime numbers using an algorithm named the Sieve of Eratosthenes.")
        file.write("\n\nThis Python program generates the first N prime numbers using an algorithm named the Sieve of Eratosthenes.")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Get user input for the number of primes to generate
        N = int(input("\n\nEnter the number of prime numbers to generate (N): "))

        # Log user input to the file after it is entered.
        file.write(f"\n\nEntered value: N = {N}")
        print(f"\n\nEntered value: N = {N}")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Execute the prime number generation function
        A = generate_primes(N)

        # Print each element of A to the command line terminal and to the output file.
        for i in range(len(A)):
            print(f"\n\nA[{i}] := {A[i]}.")
            file.write(f"\n\nA[{i}] := {A[i]}.")

        # Print a closing message to the command line terminal.
        print("\n\n--------------------------------")
        print("End Of Program")
        print("--------------------------------\n\n")

        # Print a closing message to the output file.
        file.write("\n\n--------------------------------\n")
        file.write("End Of Program\n")
        file.write("--------------------------------\n")

# Program entry point
if __name__ == "__main__":
    main()
