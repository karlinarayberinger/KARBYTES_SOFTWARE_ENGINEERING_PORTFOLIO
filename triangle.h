/**
 * file: triangle.h
 * type: C++ (header file)
 * author: karbytes
 * date: 07_JULY_2023
 * license: PUBLIC_DOMAIN
 */

// If TRIANGLE.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef TRIANGLE_H // If triangle.h has not already been linked to a source file (.cpp), 
#define TRIANGLE_H // then link this header file to the source file(s) which include this header file.

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POINT class.
#include "point.h" 

/**
 * Define a class which is used to instantiate TRIANGLE type objects.
 * 
 * (An object is a variable whose data type is user defined rather than native to the C++ programming language).
 * 
 * A TRIANGLE object represents an instance in which three unique POINT instances exist 
 * (and such that each one of those three POINT instances represents a unique coordinate pair within the tuple of three objects 
 *  which each represent exactle one two-dimensional point, POINT(X,Y), on a Cartesian grid).
 * 
 * A POINT object represents a whole number coordinate pair in the form (X,Y).
 * 
 * X represents a specific whole number position along the x-axis (i.e. horizontal dimension) of a two-dimensional Cartesian grid.
 * Y represents a specific whole number position along the y-axis (i.e. vertical dimension) of the same two-dimensional Cartesian grid.
 * 
 * X stores one integer value at a time which is no smaller than MINIMUM_X and which is no larger than MAXIMUM_X.
 * Y stores one integer value at a time which is no smaller than MINIMUM_Y and which is no larger than MAXIMUM_Y.
 */
class TRIANGLE
{
private:
    POINT A, B, C; // data attributes
    bool points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2); // helper method
    bool points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2); // helper method
public:
    TRIANGLE(); // default constructor
    TRIANGLE(POINT A, POINT B, POINT C); // normal constructor
    TRIANGLE(int A_X, int A_Y, int B_X, int B_Y, int C_X, int C_Y); // normal constructor
    TRIANGLE(const TRIANGLE & triangle); // copy constructor
    POINT get_A(); // getter method
    POINT get_B(); // getter method
    POINT get_C(); // getter method
    double get_side_length_AB(); // getter method
    double get_side_length_BC(); // getter method
    double get_side_length_CA(); // getter method
    double get_interior_angle_ABC(); // getter method
    double get_interior_angle_BCA(); // getter method
    double get_interior_angle_CAB(); // getter method
    double get_perimeter(); // getter method
    double get_area(); // getter method
    void print(std::ostream & output = std::cout); // descriptor method
    friend std::ostream & operator << (std::ostream & output, TRIANGLE & triangle); // descriptor method
    ~TRIANGLE(); // destructor
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
