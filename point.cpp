/**
 * file: point.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/* preprocessing directives */
#include "point.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POINT class.

/**
 * The default constructor method of the POINT class 
 * instantiates POINT type objects 
 * whose X value is initially set to 0 and 
 * whose Y value is initially set to 0.
 * 
 * The default constructor method of the POINT class is invoked 
 * when a POINT type variable is declared as follows:
 * 
 * // variable declaration example one
 * POINT point_0; 
 * 
 * // variable declaration example two
 * POINT point_1 = POINT();
 */
POINT::POINT()
{
    std::cout << "\n\nCreating the POINT type object whose memory address is " << this << "...";
    X = 0;
    Y = 0;
}

/**
 * The normal constructor method of the POINT class 
 * instantiates POINT type objects 
 * whose X value is set to the leftmost function input value (if that input value is no smaller than MINIMUM_X and no larger than MAXIMUM_X) and 
 * whose Y value is set to the rightmost function input value (if that input value is no smaller than MINIMUM_Y and no larger than MAXIMUM_Y).
 * 
 * If a function input value is out of its specified range, then set the corresponding int type property of this to 0.
 * 
 * (The keyword this refers to the POINT object which is returned by this function).
 *
 * The normal constructor method of the POINT class is invoked when a POINT type variable is declared as follows:
 * 
 * // variable definition example one
 * POINT point_0 = POINT(-55,84);
 * 
 * // variable definition example two
 * POINT point_1 = POINT(3,-4);
 * 
 * // variable definition example three
 * POINT point_2 = POINT(-1000, 999); // point_2 = POINT(0,999).
 * 
 * // variable definition example four
 * POINT point_3 = POINT(1000,-999); // point_3 = POINT(0,-999).
 * 
 * // variable definition example five
 * POINT point_4 = POINT(999,-1000); // point_4 = POINT(999,0).
 * 
 * // variable definition example six
 * POINT point_5 = POINT(-999,1000); // point_5 = POINT(-999,0).
 */
POINT::POINT(int X, int Y)
{
    std::cout << "\n\nCreating the POINT type object whose memory address is " << this << "...";
    this -> X = ((X < MINIMUM_X) || (X > MAXIMUM_X)) ? 0 : X; // Set the X property of the POINT instance being created to 0 if the function input X value is out of range.
    this -> Y = ((Y < MINIMUM_Y) || (Y > MAXIMUM_Y)) ? 0 : Y; // Set the Y property of the POINT instance being created to 0 if the function input Y value is out of range.
}

/**
 * The copy constructor method of the POINT class 
 * instantiates POINT type objects 
 * whose X value is set to the X value of the input POINT object and 
 * whose Y value is set to the Y value of the input POINT object.
 *
 * The copy constructor method of the POINT class is invoked when a POINT type variable is declared as follows:
 * 
 * // variable definition example one
 * POINT point_0 = POINT(33,55);
 * POINT point_1 = POINT(point_0); // point_1 = POINT(33,55).
 * 
 * // variable definition example two
 * POINT point_2 = POINT(point_1); // point_2 = POINT(33,55).
 */
POINT::POINT(const POINT & point) 
{
    std::cout << "\n\nCreating the POINT type object whose memory address is " << this << "...";
    X = point.X;
    Y = point.Y;
}

/**
 * The getter method of the POINT class returns the value of the caller POINT object's X property.
 * 
 * X is an int type variable which stores exactly one integer value at a time which is no smaller than MINIMUM_X and which is no larger than MAXIMUM_X.
 * 
 * X represents a specific whole number position along the x-axis (i.e. horizontal dimension) of a two-dimensional Cartesian grid.
 */
int POINT::get_X()
{
    return X;
}

/**
 * The getter method of the POINT class returns the value of the caller POINT object's Y property.
 * 
 * Y is an int type variable which stores exactly one integer value at a time which is no smaller than MINIMUM_Y and which is no larger than MAXIMUM_Y.
 * 
 * Y represents a specific whole number position along the y-axis (i.e. vertical dimension) of a two-dimensional Cartesian grid.
 */
int POINT::get_Y()
{
    return Y;
}

/**
 * The setter method of the POINT class sets the POINT object's X property to the function input value 
 * if that value is no smaller than MINIMUM_X and which is no larger than MAXIMUM_X.
 * 
 * If the input value is in range, then return true. 
 * Otherwise, do not change the caller POINT object's X value and return false.
 * 
 * (The keyword this refers to the POINT object which calls this function).
 * 
 * (X represents a specific whole number position along the x-axis (i.e. horizontal dimension) of a two-dimensional Cartesian grid).
 */
bool POINT::set_X(int X)
{
    if ((X >= MINIMUM_X) && (X <= MAXIMUM_X)) 
    {
        this -> X = X;
        return true;
    }
    return false;
}

/**
 * The setter method of the POINT class sets the POINT object's Y property to the function input value 
 * if that value is no smaller than MINIMUM_Y and which is no larger than MAXIMUM_Y.
 * 
 * If the input value is in range, then return true. 
 * Otherwise, do not change the caller POINT object's Y value and return false.
 * 
 * (The keyword this refers to the POINT object which calls this function).
 * 
 * (Y represents a specific whole number position along the y-axis (i.e. vertical dimension) of a two-dimensional Cartesian grid).
 */
bool POINT::set_Y(int Y)
{
    if ((Y >= MINIMUM_Y) && (Y <= MAXIMUM_Y)) 
    {
        this -> Y = Y;
        return true;
    }
    return false;
}

/**
 * The getter method of the POINT class returns the length of the shortest path 
 * between the two-dimensional point represented by the the caller POINT object (i.e. this) 
 * and the two-dimensional point represented by the input POINT object (i.e. point).
 * 
 * Use the Pythagorean Theorem to compute the length of a right triangle's hypotenuse 
 * such that the two end points of that hypotenuse are represented by this and point.
 * 
 * (A hypotenuse is the only side of a right triangle which does not form a right angle 
 * with any other side of that triangle).
 * 
 * (A hypotenuse is the longest side of a triangle (and a triangle is a three-sided polygon 
 * in which three unique line segments connect three unique points)).
 * 
 * // c is the length of a right triangle's hypotenuse.
 * // a is the length of that right triangle's horizontal leg.
 * // b is the length of that triangle's vertical leg.
 * (c * c) = (a * a) + (b * b). 
 * 
 * // sqrt() is a native C++ function defined in the cmath library.
 * c = square_root( (a * a) + (b * b)). 
 */
double POINT::get_distance_from(POINT & point)
{
    int horizontal_difference = 0.0, vertical_difference = 0.0;
    horizontal_difference = X - point.X; // a
    vertical_difference = Y - point.Y; // b
    return sqrt((horizontal_difference * horizontal_difference) + (vertical_difference * vertical_difference)); // c
}

/**
 * The getter method of the POINT class returns the slope of the line which intersects 
 * the two-dimensional point represented by the caller POINT instance (i.e. this)
 * and the two-dimensional point represented by the input POINT instance (i.e. point).
 * 
 * // y := f(x), 
 * // b := f(0), 
 * // f is a function whose input is an x-axis position and whose output is a y-axis position.
 * y := mx + b.
 * 
 * // m is a constant which represents the rate at which y changes in relation to x changing.
 * m := (y - b) / x. 
 * 
 * // m represents the difference of the two y-values divided by the difference of the two x-values.
 * m := (point.Y - this.Y) / (point.X - this.X).
 */
double POINT::get_slope_of_line_to(POINT & point)
{
    double vertical_difference = 0.0, horizontal_difference = 0.0, result = 0.0;
    vertical_difference = point.Y - Y;
    horizontal_difference = point.X - X;
    result = vertical_difference / horizontal_difference;
    if (result == -0) result = 0; // Signed zeros sometimes occur inside of C++ program runtime instances.
    return result;
}

/**
 * The print method of the POINT class prints a description of the caller POINT object to the output stream.
 * 
 * Note that the default value of the function input parameter is the standard command line output stream (std::cout).
 * 
 * The default parameter is defined in the POINT class header file (i.e. point.h) and not in the POINT class source file (i.e. point.cpp).
 */
void POINT::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the caller POINT object.";
    output << "\n&X = " << &X << ". // The reference operation returns the memory address of the first memory cell of an int sized chunk of contiguous memory cells which are allocated to the caller POINT data attribute named X.";
    output << "\n&Y = " << &Y << ". // The reference operation returns the memory address of the first memory cell of an int sized chunk of contiguous memory cells which are allocated to the caller POINT data attribute named Y.";    
    output << "\nsizeof(int) = " << sizeof(int) << ". // The sizeof() operation returns the number of bytes of memory which an int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT) = " << sizeof(POINT) << ". // The sizeof() operation returns the number of bytes of memory which a POINT type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nX = " << X << ". // X stores one int type value at a time which represents the horizontal position of a two-dimensional point plotted on a Cartesian grid.";
    output << "\nY = " << Y << ". // Y stores one int type value at a time which represents the vertical position of a two-dimensional point plotted on a Cartesian grid.";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (<<).
 * 
 * (Overloading an operator is assigning a different function to a native operator other than the function which that operator is used to represent by default).
 * 
 * Note that the default value of the leftmost function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the POINT class header file (i.e. point.h).
 * 
 * The friend function is not a member of the POINT class, 
 * but the friend function has access to the private and protected members 
 * of the POINT class and not just to the public members of the POINT class.
 * 
 * The friend keyword only prefaces the function prototype of this function 
 * (and the prototype of this function is declared in the POINT class header file (i.e. point.h)). 
 * 
 * The friend keyword does not preface the definition of this function
 * (and the definition of this function is specified in the POINT class source file (i.e. point.cpp)).
 * 
 * // overloaded print function example one
 * POINT point_0; // identical to point_0.print();
 * std::cout << point_0; 
 * 
 * // overloaded print function example two
 * std::ofstream file;
 * POINT point_1; 
 * file << point_1; // identical to point_1.print(file);
 */
std::ostream & operator << (std::ostream & output, POINT & point)
{
    point.print(output);
    return output;
}

/**
 * The destructor method of the POINT class de-allocates memory which was used to 
 * instantiate the POINT object which is calling this function.
 * 
 * The destructor method of the POINT class is automatically called when 
 * the program scope in which the caller POINT object was instantiated terminates.
 */
POINT::~POINT()
{
    std::cout << "\n\nDeleting the POINT type object whose memory address is " << this << "...";
}
