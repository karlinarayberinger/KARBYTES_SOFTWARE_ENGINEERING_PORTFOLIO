#########################################################################################
# file: rsa_encryption.py
# type: Python
# date: 07_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

import random
import math

#
# Define a constant which represents the maximum value for N.
# (Access constants as Constants.MAXIMUM_N).
#
class Constants:
    MAXIMUM_N = 1000

# Function to generate an array of the first N prime numbers
def generate_array_of_first_n_primes(N):
    primes = []
    num = 2  # Starting from the first prime number
    while len(primes) < N:
        is_prime = all(num % i != 0 for i in range(2, int(math.sqrt(num)) + 1))
        if is_prime:
            primes.append(num)
        num += 1
    return primes

# Function to select a random element from an array
def select_random_element_from_array_of_integers(A):
    return random.choice(A)

# Function to compute the greatest common divisor (GCD)
def gcd(A, B):
    while B != 0:
        A, B = B, A % B
    return A

# Function for modular exponentiation
def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp // 2
        base = (base * base) % mod
    return result

# Function to calculate the modular inverse using the extended Euclidean algorithm
def mod_inverse(e, phi):
    t, new_t = 0, 1
    r, new_r = phi, e
    while new_r != 0:
        quotient = r // new_r
        t, new_t = new_t, t - quotient * new_t
        r, new_r = new_r, r - quotient * new_r
    if r > 1:
        return -1  # e is not invertible
    if t < 0:
        t += phi
    return t

# Function to select a random natural number
def select_random_natural_number(maximum_value):
    return random.randint(1, maximum_value)

def main():
    #
    # Unlike C++ variables, Python variables have no data types and must be assigned initial values.
    # 
    # Basically, none of the following variable definitions before the following statement are necessary: 
    #
    #     with open("rsa_encryption_output.txt", "w") as file:
    #

    # p and q will be assigned non-identical prime numbers.
    p = 0
    q = 0

    # n will be assigned the product of p and q and which is part of a public key and private key pairing in an RSA cryptographic system.
    n = 0

    #
    # phi will be assigned the value representing the output of the following Euler's Totient function of n: 
    # ϕ(n) = (p − 1) * (q − 1).
    #
    # The totient function represents the number of integers less than n which are coprime with n 
    # (i.e. the number of integers which are no smaller than 1 and which are no larger than (n - 1) 
    # which share no common factors with n other than 1).
    #
    phi = 0

    # e will be assigned a value such that 1 < e < phi and gcd(e, phi) = 1.
    e = 0

    # d will be assigned a value which represents a private key value such that (e ∗ d) % ϕ(n) = 1.
    d = 0

    # m will be assigned a value which represent a "message" in the form of a natural number no larger than n.
    m = 0

    # c will be assigned a value which represents the cyphertext such that m = (c ^ d) % n.
    c = 0

    # decrypted_message will be assigned a value which represents the decrypted message such that m = (c ^ d) % n.
    decrypted_message = 0

    # N will now be initially assigned a value which represents the number of elements to store in the dymanic array named A.
    N = Constants.MAXIMUM_N

    #
    # A will store the first N prime numbers in ascending order.
    # p and q will each be set to different prime numbers which are randomly selected from A.
    #
    A = []

    # file will represent the plain-text file to write program data to.
    file = 0

	#
    # If the file named rsa_encryption_output.txt does not already exist 
    # inside of the same file directory as the file named rsa_encryption.py, 
    # create a new file named rsa_encryption_output.txt in that directory.
    #
    # Open the plain-text file named rsa_encryption_output.txt
    # and set that file to be overwritten with program data.
    #
    with open("rsa_encryption_output.txt", "w") as file:

        # Print an opening message to the command line terminal.
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")

        # Print an opening message to the output file.
        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        # Print "This Python program demonstrates RSA (Rivest–Shamir–Adleman) encryption and decryption." to the command line terminal and to the output file.
        print("\n\nThis Python program demonstrates RSA (Rivest–Shamir–Adleman) encryption and decryption.")
        file.write("\n\nThis Python program demonstrates RSA (Rivest–Shamir–Adleman) encryption and decryption.")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print "STEP_0: Key Generation" to the command line terminal and to the output file.
        print("\n\nSTEP_0: Key Generation")
        file.write("\n\nSTEP_0: Key Generation")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Call the function which generates the first N primes and returns a dynamic array which is populated by those primes.
        A = generate_array_of_first_n_primes(N)

        # Set the value of p to a randomly-selected value in A (which is a prime number).
        p = select_random_element_from_array_of_integers(A)

        # Set the value of q to a randomly-selected value in A which is not the same value as p (and which is also a prime number).
        q = p
        while p == q:
            q = select_random_element_from_array_of_integers(A)

        # Print the values of p and q to the command line terminal and to the output file.
        print(f"\n\np = {p} // first prime number")
        print(f"\n\nq = {q} // second prime number")
        file.write(f"\n\np = {p} // first prime number")
        file.write(f"\n\nq = {q} // second prime number")

        # Print the value of n to the command line terminal and to the output file.
        n = p * q
        print(f"\n\nn = p * q = {n} // the modulus in both the encryption and the decryption processes")
        file.write(f"\n\nn = p * q = {n} // the modulus in both the encryption and the decryption processes")

        # Print the value of phi to the command line terminal and to the output file.
        phi = (p - 1) * (q - 1)
        print(f"\n\nphi = (p - 1) * (q - 1) = {phi} // Euler's Totient function: ϕ(n) = (p − 1) * (q − 1)")
        file.write(f"\n\nphi = (p - 1) * (q - 1) = {phi} // Euler's Totient function: ϕ(n) = (p − 1) * (q − 1)")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print "STEP_1: Choose e such that 1 < e < phi and gcd(e, phi) = 1" to the command line terminal and to the output file.
        print("\n\nSTEP_1: Choose e such that 1 < e < phi and gcd(e, phi) = 1")
        file.write("\n\nSTEP_1: Choose e such that 1 < e < phi and gcd(e, phi) = 1")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Select a value for e which is no smaller than one and no larger than phi.
        e = select_random_natural_number(phi)
        while (gcd(e, phi) != 1):
            e = select_random_natural_number(phi)

        # Print the value of e to the command line terminal and to the output file stream.
        print(f"\n\ne = {e} // public exponent")
        file.write(f"\n\ne = {e} // public exponent")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print "STEP_2: Compute the private key (d)" to the command line terminal and to the output file.
        print("\n\nSTEP_2: Compute the private key (d)")
        file.write("\n\nSTEP_2: Compute the private key (d)")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print the value of d to the command line terminal and to the output file.
        d = mod_inverse(e, phi)
        print(f"\n\nd = {d} // such that (e ∗ d) % ϕ(n) = 1")
        file.write(f"\n\nd = {d} // such that (e ∗ d) % ϕ(n) = 1")

        # Print a warning message if the modular inverse of d is determined by the program logic not to exist.
        if (d == -1):
            print("\n\nWARNING: Modular inverse of e does not exist.")
            file.write("\n\nWARNING: Modular inverse of e does not exist.")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print "STEP_3: Display the public and private keys" to the command line terminal and to the output file.
        print("\n\nSTEP_3: Display the public and private keys")
        file.write("\n\nSTEP_3: Display the public and private keys")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print the public and private keys to the command line terminal and to the output file.
        print(f"\n\nPublic Key: ({e}, {n})")
        print(f"\n\nPrivate Key: ({d}, {n})")
        file.write(f"\n\nPublic Key: ({e}, {n})")
        file.write(f"\n\nPrivate Key: ({d}, {n})")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print "STEP_4: Encrypt a message (m must be less than n)" to the command line terminal and to the output file.
        print("\n\nSTEP_4: Encrypt a message (m must be less than n)")
        file.write("\n\nSTEP_4: Encrypt a message (m must be less than n)")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        #
        # Prompt the user to enter a positive integer value to store in the variable named m.
        # Scan the command line terminal for the most recent keyboard input value. 
        # Convert that value to an integer value.
        # Store that integer value in m.
        #
        m = int(input(f"\n\nEnter a message to encrypt (as a positive integer less than {n}): "))

        # Print "The value which was entered for m is {m}." to the command line terminal and to the output file.
        print(f"\n\nThe value which was entered for m is {m}.")
        file.write(f"\n\nThe value which was entered for m is {m}.")

        #
        # If m is smaller than 1 or if m is larger than or equal to n, set m to (n - 1). 
        #
        # Print "m has been reset to {n - 1} due to the fact that the input value for m was either less than one or else greater than {n - 1}." 
        # to the command line terminal and to the file output stream.
        #
        if ((m < 1) or (m >= n)):
            m = n - 1
            print(f"\n\nm has been reset to {n - 1} due to the fact that the input value for m was either less than one or else greater than {n - 1}.")
            file.write(f"\n\nm has been reset to {n - 1} due to the fact that the input value for m was either less than one or else greater than {n - 1}.")

        # Print the value of d to the command line terminal and to the output file stream.
        c = mod_exp(m, e, n)
        print(f"\n\nc = (m ^ e) % n = {c} // encryption such that m = (c ^ d) % n")
        file.write(f"\n\nc = (m ^ e) % n = {c} // encryption such that m = (c ^ d) % n")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print "STEP_5: Decrypt the message" to the command line terminal and to the output file.
        print("\n\nSTEP_5: Decrypt the message")
        file.write("\n\nSTEP_5: Decrypt the message")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Print the value of decrypted_message to the command line terminal and to the output file.
        decrypted_message = mod_exp(c, d, n)
        print(f"\n\ndecrypted_message = {decrypted_message} // such that m = (c ^ d) % n")
        file.write(f"\n\ndecrypted_message = {decrypted_message} // such that m = (c ^ d) % n")
    
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
