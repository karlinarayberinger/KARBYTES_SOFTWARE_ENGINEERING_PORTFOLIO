# /**
#  * file: prime_factorization.py
#  * type: Python
#  * date: 22_SEPTEMBER_2024
#  * author: karbytes
#  * license: PUBLIC_DOMAIN
#  */

import os

# Define the maximum value for N
MAXIMUM_N = 10000

# Function to print the prime factorization of a number N to an output stream (console and file)
def print_prime_factorization(N, output):
    if N <= 1:
        output.write(f"\n\n{N} is not factorizable into multiple prime number multiplicative terms.")
        return
    
    output.write(f"\n\nPrime factorization of {N} is: ")
    
    divisor = 2  # Start with the smallest prime number
    first_factor = True
    
    while N > 1:
        while N % divisor == 0:
            if not first_factor:
                output.write(" * ")
            output.write(f"{divisor}")
            N //= divisor
            first_factor = False
        divisor += 1
    output.write(".\n")

# Program entry point
def main():
    # Initialize N and input_additional_values
    N = 0
    input_additional_values = 1

    # Open the output file for writing
    with open("prime_factorization_two_output.txt", "w") as file:

        # Print an opening message to the console and the file
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")
        
        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        while input_additional_values != 0:
            # Prompt the user to enter a value for N
            try:
                N = int(input(f"\n\nEnter a nonnegative integer value to store in the variable named N which is no larger than {MAXIMUM_N}: "))
                if 0 <= N <= MAXIMUM_N:
                    # Print the prime factorization of N to the file and console
                    print_prime_factorization(N, file)
                    print_prime_factorization(N, output=os.sys.stdout)
                else:
                    print(f"Error: N must be between 0 and {MAXIMUM_N}.")
            except ValueError:
                print("Invalid input. Please enter a valid integer.")
            
            # Ask if the user wants to input another value
            input_additional_values = int(input("\n\nWould you like to continue inputting program values? (Enter 1 if YES, Enter 0 if NO): "))

        # Print a closing message to the console and the file
        print("\n\n--------------------------------")
        print("End Of Program")
        print("--------------------------------\n\n")

        file.write("\n\n--------------------------------\n")
        file.write("End Of Program\n")
        file.write("--------------------------------\n")

if __name__ == "__main__":
    main()
