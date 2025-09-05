/**
 * file: trigonometric_functions.cpp
 * type: C++ (source file)
 * date: 18_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_i 10000 // constant which represents maximum number of iterations in Leibniz series
#define MAXIMUM_t 10000 // constant which represents maximum number of terms in Taylor series
#define MAXIMUM_x 10000 // constant which represents maximum value of x

/** function prototypes */
double computePi(int iterations);
double sine(double x);
double cosine(double x);
double tangent(double x);
double cotangent(double x);
double secant(double x);
double cosecant(double x);
double arctangent(double x);
double arcsine(double x);
double arccosine(double x);

/** program entry point */
int main() 
{

    // Define one double type variable for storing a floating-point number value.
    double x;

    // Declare a variable for storing the program user's answer of whether or not to continue inputting values.
    int input_additional_values = 1;

    // Declare a file output stream handler (which represents the plain-text file to generate and/or overwrite with program data).
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If the file named trigonometric_functions_output.txt does not already exist 
     * inside of the same file directory as the file named trigonometric_functions.cpp, 
     * create a new file named trigonometric_functions_output.txt in that directory.
     * 
     * Open the plain-text file named trigonometric_functions_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("trigonometric_functions_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program computes sine, cosine, tangent, cotangent, secant, cosecant, arctangent, arcsine, and arccosine of some angle measurement in radians, x.
    std::cout << "\n\nThis C++ program computes sine, cosine, tangent, cotangent, secant, cosecant, arctangent, arcsine, and arccosine of some angle measurement in radians, x.";
    file << "\n\nThis C++ program computes sine, cosine, tangent, cotangent, secant, cosecant, arctangent, arcsine, and arccosine of some angle measurement in radians, x.";

    // Execute the code inside of the while loop block at least once (and until the program user inputs a value specifying to exit the program).
    while (input_additional_values != 0)
    {
        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Prompt the user to enter an input value for x (and print that prompt to the command line terminal and to the file output stream).
        std::cout << "\n\nEnter a real number of radians, x, to input into trigonometric functions which is no smaller than " << (-1 * MAXIMUM_x) << " and no larger than " << MAXIMUM_x << ": ";
        file << "\n\nEnter a real number of radians, x, to input into trigonometric functions which is no smaller than " << (-1 * MAXIMUM_x) << " and no larger than " << MAXIMUM_x << ": ";

        // Scan the command line terminal for the most recent keyboard input value. Store that value in x.
        std::cin >> x;

        // Print "The value which was entered for x is {x}." to the command line terminal and to the file output stream.
        std::cout << "\nThe value which was entered for x is " << x << ".";
        file << "\n\nThe value which was entered for x is " << x << ".";

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Print the value of sine of x to the command line terminal and to the output file.
        std::cout << "\n\nsine(x) = " << sine(x) << ".";
        file << "\n\nsine(x) = " << sine(x) << ".";

        // Print the value of cosine of x to the command line terminal and to the output file.
        std::cout << "\n\ncosine(x) = " << cosine(x) << ".";
        file << "\n\ncosine(x) = " << cosine(x) << ".";

        // Print the value of tangent of x to the command line terminal and to the output file.
        std::cout << "\n\ntangent(x) = " << tangent(x) << ".";
        file << "\n\ntangent(x) = " << tangent(x) << ".";

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Print the value of cotangent of x to the command line terminal and to the output file.
        std::cout << "\n\ncotangent(x) = " << cotangent(x) << ".";
        file << "\n\ncotangent(x) = " << cotangent(x) << ".";

        // Print the value of secant of x to the command line terminal and to the output file.
        std::cout << "\n\nsecant(x) = " << secant(x) << ".";
        file << "\n\nsecant(x) = " << secant(x) << ".";

        // Print the value of cosecant of x to the command line terminal and to the output file.
        std::cout << "\n\ncosecant(x) = " << secant(x) << ".";
        file << "\n\ncosecant(x) = " << secant(x) << ".";

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

        // Print the value of arctangent of x to the command line terminal and to the output file.
        std::cout << "\n\narctangent(x) = " << arctangent(x) << ".";
        file << "\n\narctangent(x) = " << arctangent(x) << ".";

        // Print the value of arcsine of x to the command line terminal and to the output file.
        std::cout << "\n\narcsine(x) = " << arcsine(x) << ".";
        file << "\n\narcsine(x) = " << arcsine(x) << ".";

        // Print the value of arccosine of x to the command line terminal and to the output file.
        std::cout << "\n\narccosine(x) = " << arccosine(x) << ".";
        file << "\n\narccosine(x) = " << arccosine(x) << ".";

        // Print a horizontal divider line to the command line terminal and to the file output stream.
        std::cout << "\n\n--------------------------------";
        file << "\n\n--------------------------------";

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
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function computes the approximate value of Pi using the Leibniz series.
 * 
 * Pi ≈ 4 * (1 - (1 / 3) + (1 / 5) - (1 / 7) + (1 / 9) - ...)
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * Pi is a mathematical constant that is the ratio of a circle's circumference to 
 * its diameter (which is approximately equal to 3.14159).
 * 
 * For more information on how to compute the approximate value of Pi
 * (using a Monte Carlo dart-throwing simulation in JavaScript), visit
 * the tutorial web page at the following Uniform Resource Locator:
 * 
 * https://karlinaobject.wordpress.com/pi_approximation/
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * iterations is assumed to be a nonnegative integer no larger than MAXIMUM_iteratons.
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double computePi(int iterations) 
{
    int i = 0;
    double pi = 0.0;
    double sign = 1.0; // alternates between positive and negative

    // Set iterations to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((iterations < 0) || (iterations > MAXIMUM_i)) 
    {
        iterations = 1;
        std::cout << "\n\nThe number of iterations for the Leibniz series in computePi(iterations) was out of range. Hence, iterations has been reset to 1.";
    }

    for (i = 0; i < iterations; i += 1) 
    {
        pi += sign / (2.0 * i + 1.0); // add next term in the series
        sign = -sign; // alternate the sign for each term
    }

    pi *= 4.0; // multiply by 4 to get Pi
    return pi;
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function uses the Taylor series to compute the approximate value of sine of x (which is also expressed as sin(x)).
 * 
 * The value returned by this function is no smaller than -1 and no larger than 1:
 * 
 * -1 <= sin(x) <= 1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The sine of an angle, x, in a right triangle is defined as the ratio of the length of 
 * the side opposite the angle to the length of the hypotenuse (the longest side of the triangle):
 * 
 * sin(x) = opposite / hypotenuse
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * Note that an angle measurement in degrees can be converted to radians using the following formula:
 * 
 * radians = degrees * (Pi / 180)
 * 
 * If x is 30 degrees, then the right triangle it is the interior angle measurement of is a triangle
 * whose side opposite of x is 1 and whose hypotenuse is 2.
 * 
 * Hence, sine of 30 degrees can be computed as follows:
 * 
 * 30 degrees = Pi / 6 radians ≈ 0.5236
 * 
 * sin(0.5236) = 1 / 2 = 0.5
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double sine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in sine(x) was out of range. Hence, x has been reset to 1.";
    }

    int i = 0;
    const int terms = MAXIMUM_t; // number of terms in the Taylor series
    double result = 0.0;
    double term = x; // first term: ((x ^ 1) / 1!)
    int sign = 1; // alternating signs for each term
    for (i = 1; i <= terms; i += 1) 
    {
        result += sign * term;
        sign *= -1; // alternating sign
        term *= x * x / (2 * i * (2 * i + 1)); // update term for the next iteration
    }
    return result;
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function uses the Taylor series to compute the approximate value of cosine of x (which is also expressed as cos(x)).
 * 
 * The value returned by this function is no smaller than -1 and no larger than 1:
 * 
 * -1 <= cos(x) <= 1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The cosine of an angle, x, in a right triangle is defined as the ratio of the length of 
 * the side adjacent to the angle to the length of the hypotenuse (the longest side of the triangle):
 * 
 * cos(x) = adjacent / hypotenuse
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * Note that an angle measurement in degrees can be converted to radians using the following formula:
 * 
 * radians = degrees * (Pi / 180)
 * 
 * If x is 60 degrees, then the right triangle it is the interior angle measurement of is a triangle
 * whose side adjacent to x is 1 and whose hypotenuse is 2.
 * 
 * Hence, cosine of 60 degrees can be computed as follows:
 * 
 * 60 degrees = Pi / 3 radians ≈ 1.047
 * 
 * cos(1.047) = 1 / 2 = 0.5
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double cosine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in cosine(x) was out of range. Hence, x has been reset to 1.";
    }

    int i = 0;
    const int terms = MAXIMUM_t; // number of terms in the Taylor series
    double result = 1.0; // first term: ((x ^ 0) / 0!)
    double term = 1.0; 
    int sign = -1; // alternating signs for each term
    for (i = 1; i <= terms; i += 1) 
    {
        term *= x * x / (2 * i * (2 * i - 1)); // update term for the next iteration
        result += sign * term;
        sign *= -1; // alternating sign
    }
    return result;
}

/**
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function computes the approximate value of tangent of x (which is also expressed as tan(x)).
 * 
 * The value returned by this function can theoretically be any real number:
 * 
 * tan(x) ∈ (-INFINITY, INFINITY)
 * 
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * The tangent of an angle, x, in a right triangle is defined as the ratio of the length of the side opposite 
 * the angle to the length of the adjacent side:
 * 
 * tan(x) = opposite / adjacent
 * 
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians such that, theoretically speaking,
 * 
 * x = (((2 * n) + 1) * Pi) / 2 
 * 
 * where n is any integer
 * 
 * (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but 
 * 
 * x != (((2 * n) + 1) * Pi) / 2 
 * 
 * where n is theoretically any integer,
 * 
 * then the output value returned by this function will be "not a number".
 * 
 * For example, if x = Pi /2, then tan(x) = "not a number".
 *
 *-----------------------------------------------------------------------------------------------------------------------------------
 */
double tangent(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in tangent(x) was out of range. Hence, x has been reset to 1.";
    }

    return sine(x) / cosine(x);
}

/**
 *-----------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the reciprocal of the tangent function:
 * 
 * cotangent(x) = cot(x) = 1 / tan(x)
 * 
 *------------------------------------------------------------------------------------------------------------------------------------
 *
 * The value returned by this function can theoretically be any real number:
 * 
 * cot(x) ∈ (-INFINITY, INFINITY)
 * 
 *------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians such that, theoretically speaking,
 * 
 * sin(x) != 0
 * 
 * (i.e. 
 * 
 * x != (Pi * n) 
 * 
 * where n is any integer)
 * 
 * (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
 * 
 * x = Pi * n 
 * 
 * where n is any integer
 * 
 * then the output value returned by this function will be "not a number".
 * 
 * For example, if x = Pi, then cot(x) = "not a number".
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double cotangent(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in cotangent(x) was out of range. Hence, x has been reset to 1.";
    }

    return 1.0 / tangent(x);
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the reciprocal of the cosine function:
 * 
 * secant(x) = sec(x) = 1 / cos(x)
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The value returned by this function can theoretically be any real number less than or equal to -1 
 * or else any real number greater than or equal to 1:
 * 
 * sec(x) ∈ (-INFINITY, -1] ∪ [1, INFINITY)
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians such that, theoretically speaking,
 * 
 * cos(x) != 0
 * 
 * (i.e. 
 * 
 * x != (((2 * n) + 1) * Pi) / 2
 * 
 * where n is any integer)
 * 
 * (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
 * 
 * x = (((2 * n) + 1) * Pi) / 2
 * 
 * where n is any integer
 * 
 * then the output value returned by this function will be "not a number".
 * 
 * For example, if x = Pi / 2, then cot(x) = "not a number".
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double secant(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in secant(x) was out of range. Hence, x has been reset to 1.";
    }

    return 1.0 / cosine(x);
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the reciprocal of the sine function:
 * 
 * cosecant(x) = cos(x) = 1 / sin(x)
 *
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The value returned by this function can theoretically be any real number less than or equal to -1 
 * or else any real number greater than or equal to 1:
 * 
 * csc(x) ∈ (-INFINITY, -1] ∪ [1, INFINITY)
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians such that, theoretically speaking,
 * 
 * sin(x) != 0
 * 
 * (i.e. 
 * 
 * x != (Pi * n) 
 * 
 * where n is any integer)
 * 
 * (but, in this program function, x is allowed to be any integer in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is within [(-1 * MAXIMUM_x), MAXIMUM_x] but also
 * 
 * x = Pi * n 
 * 
 * where n is any integer
 * 
 * then the output value returned by this function will be "not a number".
 * 
 * For example, if x = Pi, then csc(x) = "not a number".
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double cosecant(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in cosecant(x) was out of range. Hence, x has been reset to 1.";
    }

    return 1.0 / sine(x);
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the inverse of the cosine function using the Taylor series:
 * 
 * arctangent(x) = atan(x) = tan ^ -1 (x) != 1 / tan(x) = (tan(x)) ^ -1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 *
 * The value returned by this function can theoretically be any real number less than or equal to (-1 * (Pi / 2))
 * or any real number greater than or equal to (Pi / 2):
 * 
 * atan(x) ∈ [(-1 * (Pi / 2)), (Pi / 2)]
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and can theoretically be any real number (but is constrained to be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double arctangent(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in arctangent(x) was out of range. Hence, x has been reset to 1.";
    }

    int i = 0;
    const int terms = MAXIMUM_t; // number of terms in the series
    double result = 0.0;
    double term = x; // first term
    int sign = 1; // alternating signs for each term
    for (i = 0; i < terms; i += 1) 
    {
        result += sign * term;
        sign *= -1; // alternating sign
        term *= x * x * (2 * i + 1) / (2 * i + 3); // update term for the next iteration
    }
    return result;
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the inverse of the sine function using the Taylor series:
 * 
 * arcsine(x) = asin(x) = sin ^ -1 (x) != 1 / sin(x) = (sin(x)) ^ -1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 *
 * The value returned by this function can theoretically be any real number less than or equal to (-1 * (Pi / 2))
 * or any real number greater than or equal to (Pi / 2):
 * 
 * asin(x) ∈ [(-1 * (Pi / 2)), (Pi / 2)]
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and is only valid if
 * 
 * x ∈ [-1, 1]
 * 
 * where x is a real number
 * 
 * (but, in this program, x can be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is out of range of [-1, 1], then asin(x) = "not a number".
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double arcsine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in arcsine(x) was out of range. Hence, x has been reset to 1.";
    }

    const int terms = MAXIMUM_t;
    double result = x;
    double term = x;
    for (int i = 1; i < terms; ++i) 
    {
        term *= (x * x * (2 * i - 1)) / (2 * i);
        result += term / (2 * i + 1);
    }
    return result;
}

/**
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * This function returns the inverse of the cosine function using the following formula: acos(x) = pi/2 - asin(x)
 * 
 * arccosine(x) = acos(x) = cos ^ -1 (x) != 1 / cos(x) = (cos(x)) ^ -1
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * The value returned by this function can theoretically be any real number less than or equal to 0
 * or any real number greater than or equal to Pi:
 * 
 * acos(x) ∈ [0, Pi]
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 * 
 * x is an angle measurement in radians and is only valid if
 * 
 * x ∈ [-1, 1]
 * 
 * where x is a real number
 * 
 * (but, in this program, x can be in [(-1 * MAXIMUM_x), MAXIMUM_x]).
 * 
 * If x is out of range of [-1, 1], then acos(x) = "not a number".
 * 
 *----------------------------------------------------------------------------------------------------------------------------------------------
 */
double arccosine(double x) 
{
    // Set x to 1 if the function input value is out or range. Then print a message about that change to the command line terminal.
    if ((x < (-1 * MAXIMUM_x)) || (x > MAXIMUM_x)) 
    {
        x = 1;
        std::cout << "\n\nThe number of radians, x, in arccosine(x) was out of range. Hence, x has been reset to 1.";
    }

    return computePi(MAXIMUM_i) / 2 - arcsine(x);  
}
