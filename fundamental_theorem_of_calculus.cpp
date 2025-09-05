/**
 * file: fundamental_theorem_of_calculus.cpp
 * type: C++ (source file)
 * date: 21_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output, file open, file close
#include <cmath> // sine function (sin(x)), cosine function (cos(x)), square root function (sqrt(x))
#include <functional> // define custom Function type
#include <array> // returning an array of Function type values
#define MINIMUM_a -100 // constant which represents the minimum a value
#define MAXIMUM_a 100 // constant which represents the maximum a value
#define MINIMUM_b -100 // constant which represents the minimum b value
#define MAXIMUM_b 100 // constant which represents the maximum b value
#define MINIMUM_n 1 // constant which represents the minimum n value
#define MAXIMUM_n 1000 // constant which represents the maximum n value

// Define the data type for an object which represents a single variable function (in the format y = f(x)).
using Function = std::function<double(double)>;

/** 
 * The following code struct definition was copied from the C++ source code file featured on the following
 * tutorial web page:
 * 
 * https://karbytesforlifeblog.wordpress.com/reimann_sum/
 * 
 * The Reimann Sum is an approximation of an integral (and an integral, in the context of this program,
 * is a two-dimensional area whose boundaries are y = 0, x = a, x = b, and some function, y = f(x)).
 * 
 * As n approaches infinity, the Reiman Sum approaches the integral.
 *-------------------------------------------------------------------------------------------------------------------
 * Define a struct-type variable named Parameters which stores the three variables needed to take the Reimann Sum 
 * of some single-variable function (whose dependent variable is x) over some positive-length interval of the x-axis
 * of a Cartesian grid
 * where the left end of that interval is represented by a double-type variable named a,
 * where the right end of that interval is represented by a double-type variable named b,
 * and where the natural number of times which that interval is divided into equally-sized partitions 
 * is represented by an int-type variable named n.
 */
struct Parameters { 
    double a; 
    double b; 
    int n; 
};

/** function prototypes */
std::array<Function, 6> generate_array_of_functions();
Parameters selectPartitioningValues(std::ofstream & file);
Function selectFunctionFromListOfFunctions(std::ofstream & file);
double selectIntervalPoint(Parameters params, std::ofstream & file);
Function derivative(Function f, double h = 1e-5);
double computeRiemannSum(Function func, double a, double b, int n, const std::string& method);
Function integral(Function f, double a, double b);

/** program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If the file named fundamental_theorem_of_calculus_output.txt does not already exist 
     * inside of the same file directory as the file named fundamental_theorem_of_calculus.cpp, 
     * create a new file named fundamental_theorem_of_calculus_output.txt in that directory.
     * 
     * Open the plain-text file named fundamental_theorem_of_calculus_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("fundamental_theorem_of_calculus_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program demonstrates the Fundamental Theorem of Calculus." to the command line terminal and to the file output stream.
    std::cout << "\n\nThis C++ program demonstrates the Fundamental Theorem of Calculus.";
    file << "\n\nThis C++ program demonstrates the Fundamental Theorem of Calculus.";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    /**
     * Prompt the user to select one of multiple single-variable functions from a list.
     * Store the selected function in a Function type variable named func.
     */
    Function func = selectFunctionFromListOfFunctions(file);

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    /**
     * Prompt the user to select end-point values for an interval of the x-axis, [a,b], 
     * Store the selected x-axis interval end-point values in a Parameters type variable named params.
     */
    Parameters params = selectPartitioningValues(file);

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    /**
     * Prompt the user to select an value inside of the x-axis interval, [a,b].
     * Store the selected x-value in a double type variable named x.
     */
    double x = selectIntervalPoint(params, file);

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Obtain the value of f(x).
    double func_of_x = func(x);

    // Obtain the derivative of the selected function, f'.
    Function func_prime = derivative(func);

    // Obtain the value of f'(x).
    double func_prime_of_x = func_prime(x);

    // Print the value of f(x) to the command line terminal and to the file output stream.
    std::cout << "\n\nf(x) = f(" << x << ") ≈ " << func_of_x << ".";
    file << "\n\nf(x) = f(" << x << ") ≈ " << func_of_x << ".";

    // Print the value of f'(x) to the command line terminal and to the file output stream.
    std::cout << "\n\nf'(x) = f'(" << x << ") ≈ " << func_prime_of_x << ". // derivative";
    file << "\n\nf'(x) = f'(" << x << ") ≈ " << func_prime_of_x << ". // derivative";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Obtain the value of the definite integral of y = f(t) on the x-axis interval [a,b].
    Function integ = integral(func, params.a, params.b);

    // Obtain the value of the definite integral of y = f(t) on the x-axis interval [a,b].
    double whole_interval_area = integ(params.b);

    // Obtain the value of the definite integral of y = f(t) on the x-axis interval [a,x].
    double selected_interval_area = integ(x);

    // Print the value of the definite integral (of y = f(t) on the x-axis interval [a,b]) to the command line terminal and to the output file stream.
    std::cout << "\n\nwhole_interval_area ≈ " << whole_interval_area << " // value of the definite integral of y = f(t) on the x-axis interval [a,b]";
    file << "\n\nwhole_interval_area ≈ " << whole_interval_area << " // value of the definite integral of y = f(t) on the x-axis interval [a,b]";

    // Print the value of the definite integral (of y = f(t) on the x-axis interval [x,b]) to the command line terminal and to the output file stream.
    std::cout << "\n\nS f(x) dt (where dt is the interval [a,b]) = selected_interval_area = " << selected_interval_area << " // value of the definite integral of y = f(t) on the x-axis interval [a,x]";
    file << "\n\nS f(x) dt (where dt is the interval [a,b]) = selected_interval_area = " << selected_interval_area << " // value of the definite integral of y = f(t) on the x-axis interval [a,x]";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Obtain the value which represents f(x) = d/dx ( S integ(t) dt ) = ( S integ(t) dt )'.
    Function original_function = derivative(integ, x);

    // Print the derivative of the integral at x to the command line terminal and to the output file stream.
    std::cout << "\n\noriginal_function ≈ derivative(integ, x) --> original_function(x) ≈ " << "original_function(" << x << ") = " << original_function(x) << "  // f(x) = d/dx ( S integ(t) dt ) = ( S integ(t) dt )'";
    file << "\n\noriginal_function ≈ derivative(integ, x) --> original_function(x) ≈ " << "original_function(" << x << ") = " << original_function(x) << "  // f(x) = d/dx ( S integ(t) dt ) = ( S integ(t) dt )'";

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
 * This function returns an array of six Function type objects.
 */
std::array<Function, 6> generate_array_of_functions()
{
    /**
     * function_0: y = f(x) = x ^ 2
     * (y is equal to x raised to the power of two)
     * 
     * input_range: x ∈ (-INFINITY, INFINITY)
     * output_range: y ∈ (-INFINITY, INFINITY)
     */
    Function function_0 = [](double x) { return x * x; };

    /**
     * function_1: y = f(x) = x ^ 3
     * (y is equal to x raised to the power of three)
     * 
     * input_range: x ∈ (-INFINITY, INFINITY)
     * output_range: y ∈ (-INFINITY, INFINITY)
     */
    Function function_1 = [](double x) { return x * x * x; };

    /**
     * function_2: y = f(x) = sin(x)
     * (y is equal to sine of x (where x is in radians))
     * 
     * input_range: x ∈ (-INFINITY, INFINITY)
     * output_range: y ∈ [-1, 1]
     */
    Function function_2 = [](double x) { return sin(x); };

    /**
     * function_3: y = f(x) = cos(x)
     * (y is equal to cosine of x (where x is in radians))
     * 
     * input_range: x ∈ (-INFINITY, INFINITY)
     * output_range: y ∈ [-1, 1]
     */
    Function function_3 = [](double x) { return cos(x); };

    /**
     * function_4: y = f(x) = sqrt(x)
     * (y is equal to the square root of x)
     * 
     * input_range: x ∈ [0, INFINITY)
     * output_range: y ∈ [0, INFINITY)
     */
    Function function_4 = [](double x) { return sqrt(x); };

    /**
     * function_5: y = f(x) = (2 * x) + 3
     * (y is equal to two times x plus 3)
     * 
     * input_range: x ∈ (-INFINITY, INFINITY)
     * output_range: y ∈ (-INFINITY, INFINITY)
     */
    Function function_5 = [](double x) { return 2 * x + 3; };

    // Return the static array of the aforementioned six Function type objects.
    return {function_0, function_1, function_2, function_3, function_4, function_5};
}

/**
 * The following code struct definition was slightly modified after being copied from the C++ source code file 
 * featured on the following tutorial web page:
 * 
 * https://karbytesforlifeblog.wordpress.com/reimann_sum/
 *-------------------------------------------------------------------------------------------------------------------
 * This function displays a list of single-variable algebraic functions
 * on the command line terminal and in the output file stream and
 * prompts the program user to input an option number which corresponds
 * with exactly one of the aforementioned functions. 
 * 
 * After the user enters some value, the corresponding Function type
 * object is returned.
 */
Function selectFunctionFromListOfFunctions(std::ofstream & file)
{
    // Define an array of six Function type objects (which corresponds with the menu interface below).
    std::array<Function, 6> functions_array = generate_array_of_functions();

    // Initialize option to represent 0 (which is the associated with the first function in the array above).
    int option = 0;

    // Print menu options and the instruction to input an option number to the command line terminal.
    std::cout << "\n\nEnter the number which corresponds with one of the following functions:";
    std::cout << "\n\n0 --> f(x) = x^2";
    std::cout << "\n\n1 --> f(x) = x^3";
    std::cout << "\n\n2 --> f(x) = sin(x)";
    std::cout << "\n\n3 --> f(x) = cos(x)";
    std::cout << "\n\n4 --> f(x) = sqrt(x)";
    std::cout << "\n\n5 --> f(x) = 2x + 3";
    std::cout << "\n\nEnter Option Here: ";

    // Print menu options and the instruction to input an option number to the file output stream.
    file << "\n\nEnter the number which corresponds with one of the following functions:";
    file << "\n\n0 --> f(x) = x^2";
    file << "\n\n1 --> f(x) = x^3";
    file << "\n\n2 --> f(x) = sin(x)";
    file << "\n\n3 --> f(x) = cos(x)";
    file << "\n\n4 --> f(x) = sqrt(x)";
    file << "\n\n5 --> f(x) = 2x + 3";
    file << "\n\nEnter Option Here: ";

    /**
     * Scan the command line terminal for the most recent keyboard input value. 
     * Store that value (which is coerced to be of type int upon storage) in the variable named option.
     */
    std::cin >> option;

    // Print "The value which was entered for option is {option}." to the command line terminal.
    std::cout << "\nThe value which was entered for option is " << option << ".";

    // Print "The value which was entered for option is {option}." to the file output stream.
    file << "\n\nThe value which was entered for option is " << option << ".";

    /**
     * If option is smaller than 0 or if option is larger than 5, set option to 0
     * and print a message stating that fact to the command line terminal and to the output file stream.
     */
    if ((option < 0) || (option > 5))
    {
        option = 0;
        std::cout << "\n\noption was set to 0 by default due to the fact that the value input by the user was not recognized.";
        file << "\n\noption was set to 0 by default due to the fact that the value input by the user was not recognized.";
    }

    /**
     * Print a message about which function was selected by the user to the command line terminal and to the file output stream 
     * and return that selected function's corresponding Function type object.
     */
    if (option == 0) 
    {
        std::cout << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^2.";
        file << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^2.";
        return functions_array[0];
    }
    if (option == 1) 
    {
        std::cout << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^3.";
        file << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = x^3.";
        return functions_array[1];
    }
    if (option == 2) 
    {
        std::cout << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = sin(x).";
        file << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = sin(x).";
        return functions_array[2];
    }
    if (option == 3) 
    {
        std::cout << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = cos(x).";
        file << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = cos(x).";
        return functions_array[3];
    }
    if (option == 4) 
    {
        std::cout << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = sqrt(x).";
        file << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = sqrt(x).";
        return functions_array[4];
    }
    if (option == 5) 
    {
        std::cout << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = 2x + 3.";
        file << "\n\nThe single-variable function which was selected from the list of such functions is f(x) = 2x + 3.";
        return functions_array[5];
    }

    // This statement should never be executed.
    return functions_array[0];
}

/**
 * The following code struct definition was slightly modified after being copied from the C++ source code file 
 * featured on the following tutorial web page:
 * 
 * https://karbytesforlifeblog.wordpress.com/reimann_sum/
 *-------------------------------------------------------------------------------------------------------------------
 * This function prompts the user to input three numerical values related to partitioning the x-axis of a Cartesian grid
 * for the purpose of using each those partitions to instantiate a rectangle whose width is the partition length
 * and whose height is where that rectangle's top left corner intersects with the graph of some single-variable function y = f(x).
 * 
 * a represents the left-most point of the aforementioned x-axis partition.
 * 
 * b represents the right-most point of the aforementioned x-axis partition.
 * 
 * n represents the number of equally-sized partitions to divide the x-axis partition, [a,b], into.
 * 
 * If an invalid input to this function is detected, then this function will return a Parameters instance with default values as follows:
 * 
 * { a : 0.0, b : 1.0, n : 10 }.
 */
Parameters selectPartitioningValues(std::ofstream & file)
{
    // Define two double-type variables for storing values which represent the end points of an x-axis interval.
    double a = 0.0, b = 0.0;

    // Define one int-type variable for storing the number of equally sized partitions to divide the aforementioned x-axis interval into.
    int n = 1000;

    // Define a read-only default Parameters value to use as a reference to replace invalid user-input values with correct values.
    const Parameters default_params = { 0.0, 1.0, n };

    /*****************************/
    /* Get User Input: a         */
    /*****************************/

    // Print a message to the command line terminal which prompts the user to input a value to store in the variable named a.
    std::cout << "\n\nEnter a value to store in double-type variable a (which represents the left end of the x-axis interval): ";

    // Print a message to the output file stream which prompts the user to input a value to store in the variable named a.
    file << "\n\nEnter a value to store in double-type variable a (which represents the left end of the x-axis interval): ";

    /**
     * Scan the command line terminal for the most recent keyboard input value. 
     * Store that value in the variable named a.
     */
    std::cin >> a;

    // Print "The value which was entered for a is {a}." to the command line terminal.
    std::cout << "\nThe value which was entered for a is " << a << ".";

    // Print "The value which was entered for a is {a}." to the file output stream.
    file << "\n\nThe value which was entered for a is " << a << ".";

    /**
     * Print an error message to the command line terminal and to the output file stream if
     * a is smaller than MINIMUM_a or if
     * a is larger than MAXIMUM_a
     * and return a default Parameters instance.
     */
    if ((a < MINIMUM_a) || (a > MAXIMUM_a))
    {
        std::cout << "\n\nInvalid interval end-point. a is required to be within range [" << MINIMUM_a << "," << MAXIMUM_a << "].";
        std::cout << "\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.";
        file << "\n\nInvalid interval end-point. a is required to be within range [" << MINIMUM_a << "," << MAXIMUM_a << "].";
        file << "\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.";
        return default_params;
    }

    /*****************************/
    /* Get User Input: b         */
    /*****************************/

    // Print a message to the command line terminal which prompts the user to input a value to store in the variable named b.
    std::cout << "\n\nEnter a value to store in double-type variable b (which represents the right end of the x-axis interval): ";

    // Print a message to the output file stream which prompts the user to input a value to store in the variable named b.
    file << "\n\nEnter a value to store in double-type variable b (which represents the right end of the x-axis interval): ";

    /**
     * Scan the command line terminal for the most recent keyboard input value. 
     * Store that value in the variable named a.
     */
    std::cin >> b;

    // Print "The value which was entered for b is {b}." to the command line terminal.
    std::cout << "\nThe value which was entered for b is " << b << ".";

    // Print "The value which was entered for b is {b}." to the file output stream.
    file << "\n\nThe value which was entered for b is " << b << ".";

    /**
     * Print an error message to the command line terminal and to the output file stream if
     * b is smaller than or equal to a or if
     * a is larger than MAXIMUM_a
     * and return a default Parameters instance.
     */
    if ((b <= a) || (b > MAXIMUM_a))
    {
        std::cout << "\n\nInvalid interval end-point. b is required to be within range (" << a << "," << MAXIMUM_a << "].";
        std::cout << "\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.";
        file << "\n\nInvalid interval end-point. b is required to be within range (" << a << "," << MAXIMUM_a << "].";
        file << "\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.";
        return default_params;
    }

    /*****************************/
    /* Get User Input: n         */
    /*****************************/

    // Print a message to the command line terminal which prompts the user to input a value to store in the variable named n.
    // std::cout << "\n\nEnter a value to store in int-type variable n (which represents the number of equally-sized partitions to divide x-axis interval [a,b] into): ";

    // Print a message to the output file stream which prompts the user to input a value to store in the variable named n.
    // file << "\n\nEnter a value to store in int-type variable n (which represents the number of equally-sized partitions to divide x-axis interval [a,b] into): ";

    /**
     * Scan the command line terminal for the most recent keyboard input value. 
     * Store that value in the variable named a.
     */
    // std::cin >> n;

    // Print "The value which was entered for n is {n}." to the command line terminal.
    // std::cout << "\nThe value which was entered for n is " << n << ".";

    // Print "The value which was entered for n is {n}." to the file output stream.
    // file << "\n\nThe value which was entered for n is " << n << ".";

    /**
     * Print an error message to the command line terminal and to the output file stream if
     * n is smaller than one or if
     * n is larger than MAXIMUM_a
     * and return a default Parameters instance.
     */
    // if ((n < 1) || (n > MAXIMUM_a))
    // {
    //    std::cout << "\n\nInvalid partition number. n is required to be a natural number within range [1," << MAXIMUM_a << "].";
    //    std::cout << "\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.";
    //    file << "\n\nInvalid partition number. n is required to be a natural number within range [1," << MAXIMUM_a << "].";
    //    file << "\n\nHence, default program values are being used to replace user inputs for the Reimann Sum partitioning parameters.";
    //    return default_params;
    // }

    /**
     * Print a message about which x-axis interval and partition number were selected 
     * by the user to the command line terminal and to the file output stream.
     */
    // std::cout << "\n\nThe x-axis interval which was selected to partition is [" << a << "," << b << "].";
    // std::cout << "\n\nThe selected number of equally-sized partitions to divide that interval into is " << n << ".";
    // file << "\n\nThe x-axis interval which was selected to partition is [" << a << "," << b << "].";
    // file << "\n\nThe selected number of equally-sized partitions to divide that interval into is " << n << ".";

    // Return a struct whose data type is Parameters and whose data attributes are the values which the user entered during a runtime instance of this function.
    return {a, b, n};
}

/**
 * This function prompts the user to select a value inside of the x-axis interval, [a,b].
 * 
 * If the entered value is not within those bounds, then set that value to b.
 */
double selectIntervalPoint(Parameters params, std::ofstream & file)
{
    // Declare one double type variable named x for storing floating-point number values.
    double x = 0.0;

    // Print a message to the command line terminal which prompts the user to input a value to store in the variable named x.
    std::cout << "\n\nEnter a value to store in double-type variable x (which represents a point inside of the selected x-axis interval): ";

    // Print a message to the output file stream which prompts the user to input a value to store in the variable named x.
    file << "\n\nEnter a value to store in double-type variable x (which represents a point inside of the selected x-axis interval): ";

    /**
     * Scan the command line terminal for the most recent keyboard input value. 
     * Store that value in the variable named x.
     */
    std::cin >> x;

    // Print "The value which was entered for x is {x}." to the command line terminal.
    std::cout << "\nThe value which was entered for x is " << x << ".";

    // Print "The value which was entered for x is {x}." to the file output stream.
    file << "\n\nThe value which was entered for x is " << x << ".";

    /**
     * If x is smaller than a or larger than b, set x to b 
     * and print a resulting message to the command line terminal and file output stream.
     */
    if ((x < params.a) || (x > params.b))
    {
        x = params.b;
        std::cout << "\n\nThe value entered for x was either smaller than " << params.a << " or else larger than " << params.b << ".";
        std::cout << "\n\nHence, x has been reset to " << params.b << ".";
    }

    // Return the validated value of x.
    return x;
}

/**
 * This function returns a Function type object which represents the 
 * (approximate) derivative of the (single variable) function represented by 
 * the input Function type object, f, using central difference approximation.
 * 
 * A derivative is a term in calculus which refers to the rate at which
 * a function's output changes when that function's input changes 
 * (at a particular input value).
 * 
 * f'(x), which is referred to as f prime, represents the derivative of a function, f(x).
 * 
 * f'(x) ≈ (f(x + h) - f(x - h)) / (2 * f)
 * 
 * h is the small step size used to calculate the difference between the function values which 
 * are relatively close together (in terms of function input values).
 * 
 * According to ChatGPT-4o, the default parameter for h is assigned "1e-5 (which is 0.000010.00001) is a 
 * typical choice for hh, as it is small enough to provide a precise approximation without introducing too 
 * much numerical error due to floating-point precision."
 * 
 * A physics example of a derivative is the velocity function, v(t), 
 * which is derived from a position function, s(t):
 * 
 * v(t) = s'(t) 
 * 
 * s(t) describes the position of an object in space at a particular point in time, t.
 * 
 * v(t) describes the rate at which that object's position is changing at a particular point in time, t.
 * 
 * Another physics example of a derivative is the acceleration function, a(t),
 * which is derived from a velocity function, v(t).
 * 
 * a(t) = v'(t) = s''(t) // s''(t) is "s double prime of t"
 */
Function derivative(Function f, double h) 
{
    // Return a lambda function which calculates the derivative of f.
    return [f, h](double x) -> double 
    {
        return (f(x + h) - f(x - h)) / (2 * h);
    };
}

/**
 * The following code struct definition was slightly modified after being copied from the C++ source code file 
 * featured on the following tutorial web page:
 * 
 * https://karbytesforlifeblog.wordpress.com/reimann_sum/
 *-------------------------------------------------------------------------------------------------------------------
 * This function computes the Reimann sum for some arbitrary interval of the x-axis, 
 * some arbitrary number of equally sized partitions of the x-axis, 
 * some arbitrary single variable function (whose dependent variable is x), 
 * and the option to generate rectangles whose left sides either align with 
 * the left end point, 
 * right end point, 
 * or middle point of that rectangle's respective x-axis partition.
 */
double computeRiemannSum(Function func, double a, double b, int n, const std::string& method) 
{
    // Initialize sum, dx, and x to each store the value zero.
    double sum = 0.0, dx = 0.0, x = 0.0;

    /**
     * Print an error message to the console window (and output file) if
     * a is smaller than MINIMUM_a or if
     * a is larger than MAXIMUM_a
     * and exit the function by returning zero.
     */
    if ((a < MINIMUM_a) || (a > MAXIMUM_a))
    {
        // std::cout << "\n\nInvalid interval end-point. a is required to be within range [" << MINIMUM_a << "," << MAXIMUM_a << "].";
        // file << "\n\nInvalid interval end-point. a is required to be within range [" << MINIMUM_a << "," << MAXIMUM_a << "].";
        return 0.0;
    }

    /**
     * Print an error message to the console window (and output file) if
     * b is smaller than or equal to a or if
     * b is larger than MAXIMUM_b
     * and exit the function by returning zero.
     */
    if ((b <= a) || (b > MAXIMUM_b))
    {
        // std::cout << "\n\nInvalid interval. b is required to represent a value which is larger than a and no larger than " << MAXIMUM_b << ".";
        // file << "\n\nInvalid interval. b is required to represent a value which is larger than a and no larger than " << MAXIMUM_b << ".";
        return 0.0;
    }

    /**
     * Print an error message to the console window (and output file) if
     * n is smaller than one (or larger than MAXIMUM_a)
     * and exit the function by returning zero.
     */
    if ((n < 1) || (n > MAXIMUM_n))
    {
        // std::cout << "Invalid partition number. n is required to represent a natural number no larger than " << MAXIMUM_n << ".";
        // file << "Invalid partition number. n is required to represent a natural number no larger than " << MAXIMUM_n << ".";
        return 0.0;
    }

    // Set dx to represent the length of each one of the n equally-sized partitions of the x-axis interval [a,b].
    dx = (b - a) / n;

    // Print the value of dx and the above equation to the command line terminal and to the output file stream.
    // std::cout << "\n\ndx = (b - a) / n = (" << b << " - " << a << ") / " << n << " = " << dx << ". // the length of each of the n equally-sized partitions of x-axis interval, [a,b]";
    // file << "\n\ndx = (b - a) / n = (" << b << " - " << a << ") / " << n << " = " << dx << ". // the length of each of the n equally-sized partitions of x-axis interval, [a,b]";
   
    // Print a horizontal divider line to the command line terminal and to the file output stream.
    // std::cout << "\n\n~~~~~~~~~~~~~~";
    // file << "\n\n~~~~~~~~~~~~~~";

    /**
     * For each one of the n equally-sized partitions of the x-axis,
     * compute the approximate area of the region bounded by y = f(x) = func,
     * the x-axis, and the vertical lines which intersect with the endpoints (or mid points)
     * of the respective x-axis partition.
     *
     * Then add that area (which is the area of some rectangle) to sum.
     */
    for (int i = 0; i < n; ++i) 
    {
        // Print the value of i to the command line terminal and to the output file stream.
        // std::cout << "\n\ni = " << i << ". // current iteration of the for loop (of " << n << " iterations)";
        // file << "\n\ni = " << i << ". // current iteration of the for loop (of " << n << " iterations)";

        if (method == "left") 
        {
            // Determine the left end-point of the ith partition of [a,b].
            x = a + i * dx;

            // Print the value of x and the above equation to the command line terminal and to the output file stream.
            // std::cout << "\n\nx = a + i * dx = " << a << " + " << i << " * " << dx << " = " << x << ". // the left end-point of the ith partition of [a,b].";
            // file << "\n\nx = a + i * dx = " << a << " + " << i << " * " << dx << " = " << x << ". // the left end-point of the ith partition of [a,b].";
        } 
        else if (method == "right") 
        {
            // Determine the right end-point of the ith partition of [a,b].
            x = a + (i + 1) * dx;

            // Print the value of x and the above equation to the command line terminal and to the output file stream.
            // std::cout << "\n\nx = a + (i + 1) * dx = " << a << " + (" << i << " + 1) * " << dx << " = " << x << ". // the right end-point of the ith partition of [a,b].";
            // file << "\n\nx = a + (i + 1) * dx = " << a << " + (" << i << " + 1) * " << dx << " = " << x << ". // the right end-point of the ith partition of [a,b].";
        } 
        else if (method == "midpoint") 
        {
            // Determine the middle point of the ith partition of [a,b].
            x = a + (i + 0.5) * dx;

            // Print the value of x and the above equation to the command line terminal and to the output file stream.
            // std::cout << "\n\nx = a + (i + 0.5) * dx = " << a << " + (" << i << " + 0.5) * " << dx << " = " << x << ". // the middle point of the ith partition of [a,b].";
            // file << "\n\nx = a + (i + 0.5) * dx = " << a << " + (" << i << " + 0.5) * " << dx << " = " << x << ". // the middle point of the ith partition of [a,b].";
        }

        /**
         * Print an error message to the console window if 
         * method is not either 'left', 'right', or 'midpoint'
         * and exit the function by returning the value 0.0.
         */
        else 
        {
            std::cout << "\n\nInvalid method. Use 'left', 'right', or 'midpoint'.";
            return 0.0;
        }

        // Add the area of the current rectangle to the running total sum.
        sum += func(x) * dx; 

        // Print the right-hand value of the above equation to the command line terminal and to the output file stream.
        // std::cout << "\n\nrectangle_area_x = func(x) * dx = " << func(x) << " * " << dx << " = " << (func(x) * dx) << ". // area of the ith rectangle";
        // file << "\n\nrectangle_area_x = func(x) * dx = " << func(x) << " * " << dx << " = " << (func(x) * dx) << ". // area of the ith rectangle";

        // Print the running total obtained by adding the area of the ith rectangle to the value stored in the variable named sum to the command line terminal and to the output file stream.
        // std::cout << "\n\nsum += rectangle_x; // Add rectangle_x to sum and store the result in sum (in the C++ program).";
        // std::cout << "\n\nsum = " << sum << ". // the current value stored in the variable named sum";
        // file << "\n\nsum += rectangle_x; // Add rectangle_x to sum and store the result in sum (in the C++ program).";
        // file << "\n\nsum = " << sum << ". // the current value stored in the variable named sum";

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        // std::cout << "\n\n~~~~~~~~~~~~~~";
        // file << "\n\n~~~~~~~~~~~~~~";
    }

    // Return the Reimann sum obtained by adding each of the n rectangle areas.
    return sum;
}

/**
 * The following function computes the (approximate) definite integral of a single variable function, y = f(x),
 * on the x-axis interval whose lower boundary is x = a and whose upper boundary is x = b.
 * 
 * The integral of y = f(x) on the x-axis interval [a,b] is the area of the region bounded by
 * y = f(x), x = a, x = b, and y = 0.
 */
Function integral(Function f, double a, double b)
{
    // Return a lambda function which calculates the integral of f using the Reimann Sum.
    return [f, a](double x) -> double
    {
        double result = computeRiemannSum(f, a, x, 1000, "midpoint");
        return result;
    };
}
