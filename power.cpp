/**
 * file: power.cpp
 * type: C++ (source file)
 * date: 16_SEPTEMBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
// #include <cmath> // exp() and log() functions
#define MAXIMUM_ABSOLUTE_VALUE_BASE 100 // constant which represents maximum absolute value for base
#define MAXIMUM_ABSOLUTE_VALUE_EXPONENT 100 // constant which represents maximum absolute value for exponent

/* function prototypes */
bool is_whole_number(double x);
double absolute_value(double x);
double power_of_e_to_x(double x);
float ln(float x);
double power(double base, double exponent);

/* program entry point */
int main()
{
    // Declare a file output stream object named file.
    std::ofstream file;

    // Declare three variables for storing floating-point number values.
    double base = 0.0, exponent = 0.0, result = 0.0;

    // Declare a variable for storing the program user's answer of whether or not to continue inputting values.
    int input_additional_values = 1;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If the file named power_output.txt does not already exist 
     * inside of the same file directory as the file named power.cpp, 
     * create a new file named power_output.txt in that directory.
     * 
     * Open the plain-text file named power_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("power_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nSTART OF PROGRAM";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nSTART OF PROGRAM";
    file << "\n--------------------------------";

    // Print some program-related data to the command line terminal.
    std::cout << "\n\npower(base, exponent) = base ^ exponent.";

    // Print some program-related data to the file output stream.
    file << "\n\npower(base, exponent) = base ^ exponent.";

    while (input_additional_values != 0)
    {
        // Print a divider line to the command line terminal.
        std::cout << "\n\n--------------------------------";

        // Print a divider line to the file output stream.
        file << "\n\n--------------------------------";

        // Prompt the user to enter a value to store in the variable named base (to the command line terminal).
        std::cout << "\n\nEnter a real number value for base which is no larger than ";
        std::cout << MAXIMUM_ABSOLUTE_VALUE_BASE;
        std::cout << " and no smaller than ";
        std::cout << (-1 * MAXIMUM_ABSOLUTE_VALUE_BASE) << ": ";

        // Print the prompt for entering a base value to the file output stream.
        file << "\n\nEnter a real number value for base which is no larger than ";
        file << MAXIMUM_ABSOLUTE_VALUE_BASE;
        file << " and no smaller than ";
        file << (-1 * MAXIMUM_ABSOLUTE_VALUE_BASE) << ": ";

        // Scan the command line terminal for the most recent keyboard input value.
        std::cin >> base;

        // Print the most recently input keyboard value to the command line terminal.
        std::cout << base;

        // Print the most recently input keyboard value to the file output stream.
        file << base;

        // Prompt the user to enter a value to store in the variable named exponent (to the command line terminal).
        std::cout << "\n\nEnter a real number value for exponent which is no larger than ";
        std::cout << MAXIMUM_ABSOLUTE_VALUE_EXPONENT;
        std::cout << " and no smaller than ";
        std::cout << (-1 * MAXIMUM_ABSOLUTE_VALUE_EXPONENT) << ": ";

        // Print the prompt for entering an exponent value to the output file.
        file << "\n\nEnter a real number value for exponent which is no larger than ";
        file << MAXIMUM_ABSOLUTE_VALUE_EXPONENT;
        file << " and no smaller than ";
        file << (-1 * MAXIMUM_ABSOLUTE_VALUE_EXPONENT) << ": ";

        // Scan the command line terminal for the most recent keyboard input value.
        std::cin >> exponent;

        // Print the most recently input keyboard value to the command line terminal.
        std::cout << exponent;

        // Print the most recently input keyboard value to the file output stream.
        file << exponent;

        // If base is not within the range of accepted values, set base to 1.
        if ((base < (-1 * MAXIMUM_ABSOLUTE_VALUE_BASE)) || (base > MAXIMUM_ABSOLUTE_VALUE_BASE)) 
        {
            base = 1;
            std::cout << "\n\nBecause the input value for base was not within the range of accepted values, base was set to the default value of 1.";
            file << "\n\nBecause the input value for base was not within the range of accepted values, base was set to the default value of 1.";
        }

        // If exponent is not within the range of accepted values, set exponent to 0.
        if ((exponent < (-1 * MAXIMUM_ABSOLUTE_VALUE_EXPONENT)) || (exponent > MAXIMUM_ABSOLUTE_VALUE_EXPONENT)) 
        {
            exponent = 0;
            std::cout << "\n\nBecause the input value for exponent was not within the range of accepted values, exponent was set to the default value of 0.";
            file << "\n\nBecause the input value for exponent was not within the range of accepted values, exponent was set to the default value of 0.";
        }

        // Compute base to the power of exponent.
        result = power(base, exponent);

        // Print the result returned by the power function defined in this program to the command line terminal.
        std::cout << "\n\nresult = power(base,exponent) = power(" << base << ", " << exponent << ") = " << base << " ^ " << exponent << " = " << result << ".";

        // Print the result returned by the power function defined in this program to the file output stream.
        file << "\n\nresult = power(base,exponent) = power(" << base << ", " << exponent << ") = " << base << " ^ " << exponent << " = " << result << ".";

        // Ask the user whether or not to continue inputing values.
        std::cout << "\n\nWould you like to continue inputting program values? (Enter 1 if YES. Enter 0 if NO): ";

        // Scan the command line terminal for the most recent keyboard input value.
        std::cin >> input_additional_values;
    }

    // Print a closing message to the command line terminal.
    std::cout << "\n--------------------------------";
    std::cout << "\nEND OF PROGRAM";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEND OF PROGRAM";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}

/**
 * If x is determined to be a whole number, return true.
 * Otherwise, return false.
 */
bool is_whole_number(double x)
{
    return (x == (long int) x); 
}

/**
 * Return the absolute value of a real number input, x.
 */
double absolute_value(double x)
{
    if (x < 0) return -1 * x;
    return x;
}

/**
 * Return the approximate value of Euler's Number to the power of some real number x.
 * 
 * This function is essentially identical to the C++ library math.h function exp().
 */
double power_of_e_to_x(double x) {
    double a = 1.0, e = a;
    int n = 1;
    int invert = x < 0;
    x = absolute_value(x);
    for (n = 1; e != e + a; n += 1) {
        a = a * x / n;
        e += a;
    }
    return invert ? (1 / e) : e;
}

//-----------------------------------------------------------------------------------------------
// The following function and associated comments were not written by karbytes. 
//
// The following function is essentially identical to the C++ library math.h function log().
//-----------------------------------------------------------------------------------------------

// ln.c
//
// simple, fast, accurate natural log approximation
// when without 

// featuring * floating point bit level hacking,
//           * x=m*2^p => ln(x)=ln(m)+ln(2)p,
//           * Remez algorithm

// by Lingdong Huang, 2020. Public domain.

// ============================================

float ln(float x) {
  unsigned int bx = * (unsigned int *) (&x);
  unsigned int ex = bx >> 23;
  signed int t = (signed int)ex-(signed int)127;
  unsigned int s = (t < 0) ? (-t) : t;
  bx = 1065353216 | (bx & 8388607);
  x = * (float *) (&bx);
  return -1.49278+(2.11263+(-0.729104+0.10969*x)*x)*x+0.6931471806*t;
}
// done.

//-----------------------------------------------------------------------------------------------
// End of code which was not written by karbytes. 
//-----------------------------------------------------------------------------------------------

/**
 * Reverse engineer the cmath pow() function 
 * using the following properties of natural logarithms:
 * 
 * ln(x ^ y) = y * ln(x).
 * 
 * ln(e ^ x) = x. // e is approximately Euler's Number.
 * 
 * Note that the base of the logarithmic function 
 * used by the cmath log() function is e.
 * 
 * Hence, log(x) is approximately the 
 * natural log of x (i.e. ln(x)).
 * 
 * Note that the base of the exponential function
 * used by the cmath exp() function is
 * (approximately) Euler's Number.
 * 
 * Hence, exp(x) is approximately 
 * x ^ e (where e is approximately Euler's Number).
 * 
 * Note that any number, x, raised to the power of 0 is 1.
 * In more succinct terms, x ^ 0 = 1.
 * 
 * Note that any number, x, raised to the power of 1 is x.
 * In more succinct terms, x ^ 1 = x.
 * 
 * Note that any whole number, x, 
 * raised to the power of a positive whole number exponent, y, 
 * is x multiplied by itself y times.
 * For example, if x is 2 and y is 3, 
 * 2 ^ 3 = power(2, 3) = 2 * 2 * 2 = 8.
 * 
 * Note that any whole number, x, 
 * raised to the power of a negative exponent, y, 
 * is 1 / (x ^ (-1 * y)).
 * For example, if x is 2 and y is -3,
 * 2 ^ -3 = power(2, -3) = 1 / (2 * 2 * 2) = 1 / 8 = 0.125.
 */
double power(double base, double exponent)
{
    double output = 1.0;
    if (exponent == 0) return 1; 
    if (exponent == 1) return base;
    // if ((base == 0) && (exponent < 0)) return -666; // Technically 0 raised to the power of some negative exponent is undefined (i.e. not a number).
    if (is_whole_number(exponent))
    {
        if (exponent > 0)
        {
            while (exponent > 0) 
            {
                output *= base;
                exponent -= 1;
            }
            return output;
        }
        else 
        {
            exponent = absolute_value(exponent);
            while (exponent > 0)
            {
                output *= base;
                exponent -= 1;
            }
            return 1 / output;
        }
    }
    if (exponent > 0) return power_of_e_to_x(ln(base) * exponent); // Return e ^ (ln(base) * exponent).
    return power_of_e_to_x(power_of_e_to_x(ln(base) * absolute_value(exponent))); // Return e ^ (e ^ (ln(base) * absolute_value(exponent))).
}
