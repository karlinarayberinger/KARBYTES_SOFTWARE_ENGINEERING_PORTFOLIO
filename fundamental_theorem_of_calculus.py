#########################################################################################
# file: fundamental_theorem_of_calculus.py
# type: Python
# date: 22_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################
import math
from typing import Callable, List, NamedTuple, TextIO

# Define a class to represent the Parameters struct in C++
class Parameters(NamedTuple):
    a: float
    b: float
    n: int

# Define some constants for validation purposes
MINIMUM_a = -100.0
MAXIMUM_a = 100.0
MAXIMUM_n = 1000
DEFAULT_PARAMETERS = Parameters(a=0.0, b=1.0, n=MAXIMUM_n)

def generate_array_of_functions() -> List[Callable[[float], float]]:
    """
    This function returns a list of six function objects.
    """

    def function_0(x: float) -> float:
        """
        function_0: y = f(x) = x ^ 2
        (y is equal to x raised to the power of two)
        
        input_range: x ∈ (-INFINITY, INFINITY)
        output_range: y ∈ (-INFINITY, INFINITY)
        """
        return x * x

    def function_1(x: float) -> float:
        """
        function_1: y = f(x) = x ^ 3
        (y is equal to x raised to the power of three)
        
        input_range: x ∈ (-INFINITY, INFINITY)
        output_range: y ∈ (-INFINITY, INFINITY)
        """
        return x * x * x

    def function_2(x: float) -> float:
        """
        function_2: y = f(x) = sin(x)
        (y is equal to sine of x (where x is in radians))
        
        input_range: x ∈ (-INFINITY, INFINITY)
        output_range: y ∈ [-1, 1]
        """
        return math.sin(x)

    def function_3(x: float) -> float:
        """
        function_3: y = f(x) = cos(x)
        (y is equal to cosine of x (where x is in radians))
        
        input_range: x ∈ (-INFINITY, INFINITY)
        output_range: y ∈ [-1, 1]
        """
        return math.cos(x)

    def function_4(x: float) -> float:
        """
        function_4: y = f(x) = sqrt(x)
        (y is equal to the square root of x)
        
        input_range: x ∈ [0, INFINITY)
        output_range: y ∈ [0, INFINITY)
        """
        return math.sqrt(x)

    def function_5(x: float) -> float:
        """
        function_5: y = f(x) = (2 * x) + 3
        (y is equal to two times x plus 3)
        
        input_range: x ∈ (-INFINITY, INFINITY)
        output_range: y ∈ (-INFINITY, INFINITY)
        """
        return 2 * x + 3

    # Return the list of the aforementioned six function objects.
    return [function_0, function_1, function_2, function_3, function_4, function_5]

def select_function_from_list_of_functions(file: 'TextIO') -> Callable[[float], float]:
    """
    This function displays a list of single-variable algebraic functions
    on the command line terminal and in the output file stream and
    prompts the program user to input an option number which corresponds
    with exactly one of the aforementioned functions. 
    
    After the user enters some value, the corresponding function object
    is returned.
    """

    # Define a list of six function objects (which corresponds with the menu interface below).
    functions_list = generate_array_of_functions()

    # Initialize option to represent 0 (which is associated with the first function in the list above).
    option = 0

    # Print menu options and the instruction to input an option number to the command line terminal.
    print("\n\nEnter the number which corresponds with one of the following functions:")
    print("\n\n0 --> f(x) = x^2")
    print("\n\n1 --> f(x) = x^3")
    print("\n\n2 --> f(x) = sin(x)")
    print("\n\n3 --> f(x) = cos(x)")
    print("\n\n4 --> f(x) = sqrt(x)")
    print("\n\n5 --> f(x) = 2x + 3")
    print("\n\nEnter Option Here: ")

    # Print menu options and the instruction to input an option number to the file output stream.
    file.write("\n\nEnter the number which corresponds with one of the following functions:")
    file.write("\n\n0 --> f(x) = x^2")
    file.write("\n\n1 --> f(x) = x^3")
    file.write("\n\n2 --> f(x) = sin(x)")
    file.write("\n\n3 --> f(x) = cos(x)")
    file.write("\n\n4 --> f(x) = sqrt(x)")
    file.write("\n\n5 --> f(x) = 2x + 3")
    file.write("\n\nEnter Option Here: ")

    # Scan the command line terminal for the most recent keyboard input value.
    option = int(input())

    # Print "The value which was entered for option is {option}." to the command line terminal.
    print(f"\nThe value which was entered for option is {option}.")

    # Print "The value which was entered for option is {option}." to the file output stream.
    file.write(f"\n\nThe value which was entered for option is {option}.")

    # If option is smaller than 0 or if option is larger than 5, set option to 0
    # and print a message stating that fact to the command line terminal and to the output file stream.
    if option < 0 or option > 5:
        option = 0
        print("\n\nOption was set to 0 by default due to the fact that the value input by the user was not recognized.")
        file.write("\n\nOption was set to 0 by default due to the fact that the value input by the user was not recognized.")

    # Print a message about which function was selected by the user and return the selected function.
    if option == 0:
        print("\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^2.")
        file.write("\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^2.")
        return functions_list[0]
    elif option == 1:
        print("\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^3.")
        file.write("\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^3.")
        return functions_list[1]
    elif option == 2:
        print("\n\nThe single-variable function which was selected from the list of such functions is f(x) = sin(x).")
        file.write("\n\nThe single-variable function which was selected from the list of such functions is f(x) = sin(x).")
        return functions_list[2]
    elif option == 3:
        print("\n\nThe single-variable function which was selected from the list of such functions is f(x) = cos(x).")
        file.write("\n\nThe single-variable function which was selected from the list of such functions is f(x) = cos(x).")
        return functions_list[3]
    elif option == 4:
        print("\n\nThe single-variable function which was selected from the list of such functions is f(x) = sqrt(x).")
        file.write("\n\nThe single-variable function which was selected from the list of such functions is f(x) = sqrt(x).")
        return functions_list[4]
    elif option == 5:
        print("\n\nThe single-variable function which was selected from the list of such functions is f(x) = 2x + 3.")
        file.write("\n\nThe single-variable function which was selected from the list of such functions is f(x) = 2x + 3.")
        return functions_list[5]

    # This statement should never be executed.
    return functions_list[0]

def select_partitioning_values(file: TextIO) -> Parameters:
    """
    This function prompts the user to input three numerical values related to partitioning the x-axis of a Cartesian grid
    for the purpose of using each of those partitions to instantiate a rectangle whose width is the partition length
    and whose height is where that rectangle's top left corner intersects with the graph of some single-variable function y = f(x).

    a represents the left-most point of the aforementioned x-axis partition.
    b represents the right-most point of the aforementioned x-axis partition.
    n represents the number of equally-sized partitions to divide the x-axis partition, [a,b], into.

    If an invalid input to this function is detected, then this function will return a Parameters instance with default values as follows:
    { a: 0.0, b: 1.0, n: 10 }.
    """

    # Define two float-type variables for storing values representing the endpoints of an x-axis interval.
    a = 0.0
    b = 0.0

    # Define one int-type variable for storing the number of equally sized partitions to divide the x-axis interval into.
    n = MAXIMUM_n

    # /*****************************/
    # Get User Input: a
    # /*****************************/

    # Print a message to the command line terminal which prompts the user to input a value to store in the variable named a.
    print("\n\nEnter a value to store in variable a (which represents the left end of the x-axis interval): ")

    # Print a message to the output file stream which prompts the user to input a value to store in the variable named a.
    file.write("\n\nEnter a value to store in variable a (which represents the left end of the x-axis interval): ")

    # Read the user input and store the value in a
    a = float(input())

    # Print the value entered for a to the terminal and the file
    print(f"\nThe value which was entered for a is {a}.")
    file.write(f"\n\nThe value which was entered for a is {a}.")

    # Validate a: if out of range, return default Parameters
    if a < MINIMUM_a or a > MAXIMUM_a:
        print(f"\n\nInvalid interval end-point. a is required to be within range [{MINIMUM_a}, {MAXIMUM_a}].")
        print("\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.")
        file.write(f"\n\nInvalid interval end-point. a is required to be within range [{MINIMUM_a}, {MAXIMUM_a}].")
        file.write("\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.")
        return DEFAULT_PARAMETERS

    # /*****************************/
    # Get User Input: b
    # /*****************************/

    # Prompt the user for a value for b
    print("\n\nEnter a value to store in variable b (which represents the right end of the x-axis interval): ")
    file.write("\n\nEnter a value to store in variable b (which represents the right end of the x-axis interval): ")

    # Read the user input for b
    b = float(input())

    # Print the value entered for b to the terminal and file
    print(f"\nThe value which was entered for b is {b}.")
    file.write(f"\n\nThe value which was entered for b is {b}.")

    # Validate b: must be greater than a and within the allowed range
    if b <= a or b > MAXIMUM_a:
        print(f"\n\nInvalid interval end-point. b is required to be within range ({a}, {MAXIMUM_a}].")
        print("\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.")
        file.write(f"\n\nInvalid interval end-point. b is required to be within range ({a}, {MAXIMUM_a}].")
        file.write("\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.")
        return DEFAULT_PARAMETERS

    # /*****************************/
    # Get User Input: n
    # /*****************************/

    # Prompt the user for a value for n (the number of partitions)
    print("\n\nEnter a value to store in variable n (which represents the number of equally-sized partitions to divide the x-axis interval into): ")
    file.write("\n\nEnter a value to store in variable n (which represents the number of equally-sized partitions to divide the x-axis interval into): ")

    # Read the user input for n
    # n = int(input())

    # Print the value entered for n to the terminal and file
    # print(f"\nThe value which was entered for n is {n}.")
    # file.write(f"\n\nThe value which was entered for n is {n}.")

    # Validate n: must be a positive integer greater than 0
    if n < 1:
        print(f"\n\nInvalid partition number. n is required to be a natural number greater than or equal to 1.")
        print("\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.")
        file.write(f"\n\nInvalid partition number. n is required to be a natural number greater than or equal to 1.")
        file.write("\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.")
        return DEFAULT_PARAMETERS

    # Print the selected x-axis interval and partition number
    print(f"\n\nThe x-axis interval which was selected to partition is [{a}, {b}].")
    print(f"\n\nThe selected number of equally-sized partitions to divide that interval into is {n}.")
    file.write(f"\n\nThe x-axis interval which was selected to partition is [{a}, {b}].")
    file.write(f"\n\nThe selected number of equally-sized partitions to divide that interval into is {n}.")

    # Return a Parameters instance with the user inputs
    return Parameters(a, b, n)

def select_interval_point(params: Parameters, file: 'TextIO') -> float:
    """
    This function prompts the user to select a value inside of the x-axis interval, [a, b].
    
    If the entered value is not within those bounds, then set that value to b.
    """

    # Declare one float variable named x for storing floating-point number values.
    x = 0.0

    # Print a message to the command line terminal which prompts the user to input a value to store in the variable named x.
    print("\n\nEnter a value to store in variable x (which represents a point inside of the selected x-axis interval): ")

    # Print a message to the output file stream which prompts the user to input a value to store in the variable named x.
    file.write("\n\nEnter a value to store in variable x (which represents a point inside of the selected x-axis interval): ")

    # Scan the command line terminal for the most recent keyboard input value and store that value in the variable named x.
    x = float(input())

    # Print the value entered for x to the terminal and the file output stream.
    print(f"\nThe value which was entered for x is {x}.")
    file.write(f"\n\nThe value which was entered for x is {x}.")

    # If x is smaller than a or larger than b, set x to b and print a resulting message to the terminal and the file.
    if x < params.a or x > params.b:
        x = params.b
        print(f"\n\nThe value entered for x was either smaller than {params.a} or larger than {params.b}.")
        print(f"\n\nHence, x has been reset to {params.b}.")
        file.write(f"\n\nThe value entered for x was either smaller than {params.a} or larger than {params.b}.")
        file.write(f"\n\nHence, x has been reset to {params.b}.")

    # Return the validated value of x.
    return x

def derivative(f: Callable[[float], float], h: float = 1e-5) -> Callable[[float], float]:
    """
    This function returns a function object which represents the 
    (approximate) derivative of the (single-variable) function represented by 
    the input function object, f, using central difference approximation.

    A derivative is a term in calculus which refers to the rate at which
    a function's output changes when that function's input changes 
    (at a particular input value).

    f'(x), which is referred to as f prime, represents the derivative of a function, f(x).

    f'(x) ≈ (f(x + h) - f(x - h)) / (2 * h)

    h is the small step size used to calculate the difference between the function values which 
    are relatively close together (in terms of function input values).

    According to ChatGPT-4, the default parameter for h is assigned "1e-5 (which is 0.00001) as a 
    typical choice for h, as it is small enough to provide a precise approximation without introducing 
    too much numerical error due to floating-point precision."

    A physics example of a derivative is the velocity function, v(t), 
    which is derived from a position function, s(t):

    v(t) = s'(t) 

    s(t) describes the position of an object in space at a particular point in time, t.

    v(t) describes the rate at which that object's position is changing at a particular point in time, t.

    Another physics example of a derivative is the acceleration function, a(t),
    which is derived from a velocity function, v(t).

    a(t) = v'(t) = s''(t) // s''(t) is "s double prime of t"
    """

    # Return a lambda function which calculates the derivative of f using central difference approximation.
    return lambda x: (f(x + h) - f(x - h)) / (2 * h)

def compute_riemann_sum(func: Callable[[float], float], a: float, b: float, n: int, method: str) -> float:
    """
    This function computes the Riemann sum for some arbitrary interval of the x-axis, 
    some arbitrary number of equally sized partitions of the x-axis, 
    some arbitrary single-variable function (whose dependent variable is x), 
    and the option to generate rectangles whose left sides either align with 
    the left end point, 
    right end point, 
    or middle point of that rectangle's respective x-axis partition.
    """

    # Initialize sum, dx, and x to store the value zero.
    sum = 0.0
    dx = 0.0
    x = 0.0

    # Validate the inputs
    if a < MINIMUM_a or a > MAXIMUM_a:
        # Invalid interval end-point for a
        print(f"\n\nInvalid interval end-point. a is required to be within range [{MINIMUM_a}, {MAXIMUM_a}].")
        return 0.0

    if b <= a or b > MAXIMUM_a:
        # Invalid interval for b
        print(f"\n\nInvalid interval. b is required to be larger than a and no larger than {MAXIMUM_a}.")
        return 0.0

    if n < 1 or n > MAXIMUM_n:
        # Invalid partition number n
        print(f"Invalid partition number. n is required to represent a natural number no larger than {MAXIMUM_n}.")
        return 0.0

    # Set dx to represent the length of each one of the n equally-sized partitions of the x-axis interval [a,b].
    dx = (b - a) / n
    # print(f"\n\ndx = (b - a) / n = ({b} - {a}) / {n} = {dx}. // The length of each partition")

    # Calculate the Riemann sum based on the selected method (left, right, or midpoint).
    for i in range(n):
        if method == "left":
            # Determine the left end-point of the ith partition
            x = a + i * dx
            # print(f"\n\nx = a + i * dx = {a} + {i} * {dx} = {x}. // Left end-point of the ith partition")

        elif method == "right":
            # Determine the right end-point of the ith partition
            x = a + (i + 1) * dx
            # print(f"\n\nx = a + (i + 1) * dx = {a} + ({i} + 1) * {dx} = {x}. // Right end-point of the ith partition")

        elif method == "midpoint":
            # Determine the middle point of the ith partition
            x = a + (i + 0.5) * dx
            # print(f"\n\nx = a + (i + 0.5) * dx = {a} + ({i} + 0.5) * {dx} = {x}. // Midpoint of the ith partition")

        else:
            # Invalid method
            # print("\n\nInvalid method. Use 'left', 'right', or 'midpoint'.")
            return 0.0

        # Add the area of the current rectangle to the running total sum.
        rectangle_area = func(x) * dx
        sum += rectangle_area
        # print(f"\n\nrectangle_area = func(x) * dx = {func(x)} * {dx} = {rectangle_area}. // Area of the ith rectangle")
        # print(f"\n\nsum = {sum}. // Current sum")

    # Return the final Riemann sum
    return sum

def integral(f: Callable[[float], float], a: float, b: float) -> Callable[[float], float]:
    """
    The following function computes the (approximate) definite integral of a single-variable function, y = f(x),
    on the x-axis interval whose lower boundary is x = a and whose upper boundary is x = b.
    
    The integral of y = f(x) on the x-axis interval [a, b] is the area of the region bounded by
    y = f(x), x = a, x = b, and y = 0.
    """

    # Return a lambda function that calculates the integral of f using the Riemann sum.
    return lambda x: compute_riemann_sum(f, a, x, 1000, "midpoint")

def main():
    """
    Program entry point
    """

    # Open a file for writing the output
    with open("fundamental_theorem_of_calculus_output.txt", "w") as file:
        
        # Print an opening message to the command line terminal
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")
        
        # Print an opening message to the file output stream
        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        # Print "This Python program demonstrates the Fundamental Theorem of Calculus."
        print("\n\nThis Python program demonstrates the Fundamental Theorem of Calculus.")
        file.write("\n\nThis Python program demonstrates the Fundamental Theorem of Calculus.\n")

        # Print a horizontal divider line
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------\n")

        # Prompt the user to select a single-variable function from a list
        func = select_function_from_list_of_functions(file)

        # Print a horizontal divider line
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------\n")

        # Prompt the user to select end-point values for an interval of the x-axis, [a,b]
        params = select_partitioning_values(file)

        # Print a horizontal divider line
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------\n")

        # Prompt the user to select a value inside of the x-axis interval, [a,b]
        x = select_interval_point(params, file)

        # Print a horizontal divider line
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------\n")

        # Obtain the value of f(x)
        func_of_x = func(x)

        # Obtain the derivative of the selected function, f'
        func_prime = derivative(func, 1e-5)

        # Obtain the value of f'(x)
        func_prime_of_x = func_prime(x)

        # Print the value of f(x) to the terminal and file
        print(f"\n\nf(x) = f({x}) ≈ {func_of_x}.")
        file.write(f"\n\nf(x) = f({x}) ≈ {func_of_x}.\n")

        # Print the value of f'(x) to the terminal and file
        print(f"\n\nf'(x) = f'({x}) ≈ {func_prime_of_x}. // derivative")
        file.write(f"\n\nf'(x) = f'({x}) ≈ {func_prime_of_x}. // derivative\n")

        # Print a horizontal divider line
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------\n")

        # Compute the definite integral of y = f(t) on the x-axis interval [a,b]
        integ = integral(func, params.a, params.b)

        # Obtain the value of the definite integral on the x-axis interval [a,b]
        whole_interval_area = integ(params.b)

        # Obtain the value of the definite integral on the x-axis interval [a,x]
        selected_interval_area = integ(x)

        # Print the value of the definite integral on the x-axis interval [a,b]
        print(f"\n\nwhole_interval_area ≈ {whole_interval_area} // value of the definite integral on [a,b]")
        file.write(f"\n\nwhole_interval_area ≈ {whole_interval_area} // value of the definite integral on [a,b]\n")

        # Print the value of the definite integral on the x-axis interval [a,x]
        print(f"\n\nS f(x) dt (interval [a,b]) = selected_interval_area = {selected_interval_area} // value of the definite integral on [a,x]")
        file.write(f"\n\nS f(x) dt (interval [a,b]) = selected_interval_area = {selected_interval_area} // value of the definite integral on [a,x]\n")

        # Print a horizontal divider line
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------\n")

        # Obtain the value representing f(x) = d/dx ( S integ(t) dt )
        original_function = derivative(integ, 1e-5)

        # Print the derivative of the integral at x
        print(f"\n\noriginal_function ≈ derivative(integ, x) --> original_function({x}) = {original_function(x)}")
        file.write(f"\n\noriginal_function ≈ derivative(integ, x) --> original_function({x}) = {original_function(x)}\n")

        # Print a closing message to the command line terminal
        print("\n\n--------------------------------")
        print("End Of Program")
        print("--------------------------------\n\n")

        # Print a closing message to the file output stream
        file.write("\n\n--------------------------------\n")
        file.write("End Of Program\n")
        file.write("--------------------------------\n")

# Run the main function when the script is executed
if __name__ == "__main__":
    main()
