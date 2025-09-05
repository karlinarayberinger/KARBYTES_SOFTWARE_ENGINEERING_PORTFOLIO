/**
 * file: square.h
 * type: C++ (header file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// If square.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef SQUARE_H 
#define SQUARE_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the RECTANGLE class.
#include "rectangle.h" 

/**
 * SQUARE is a class which inherits the protected and public data
 * attributes and methods of RECTANGLE.
 * 
 * A SQUARE object represents a four-sided polygon such that each side of that
 * quadrilateral is the same length and each interior angle measurement of that 
 * quadrilateral is 90 degrees.
 * 
 * Class members which are set to the protected access specifier
 * are accessible to the base class and to derived classes.
 * 
 * Class members which are set to the private access specifier
 * are only accessible to the base class.
 * 
 * Class members which are set to the public access specifier
 * are accessible to any scope within the program where
 * the base class and its derived classes are implemented.
 */
class SQUARE: public RECTANGLE
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a const (i.e. const (i.e. immutable)) value.
     */
    const std::string category = "POLYGON/QUADRILATERAL/RECTANGLE/SQUARE";

    /**
     * The helper method determines whether or not the caller SQUARE instance represents a
     * quadrilateral such that each side is the same length and each interior angle measurement of that is 90 degrees.
     * Return true if the caller SQUARE satisfies those conditions. Otherwise, return false.
     */
    bool is_square();
    
public:
    
    /**
     * The default constructor of the SQUARE class calls the constructor of the RECTANGLE class and
     * sets the POINT type data member of the SQUARE object returned by this function named A to POINT(0,0), 
     * sets the POINT type data member of the SQUARE object returned by this function named B to POINT(0,5), 
     * sets the POINT type data member of the SQUARE object returned by this function named C to POINT(5,5), and
     * sets the POINT type data member of the SQUARE object returned by this function named D to POINT(5,0).
     */
    SQUARE();

    /**
     * The normal constructor of SQUARE attempts to set
     * the string type data member of this to the input string type value named color and
     * the POINT type data member of this named A to the input POINT type value named A and
     * the POINT type data member of this named B to the input POINT type value named B and
     * the POINT type data member of this named C to the input POINT type value named C and
     * the POINT type data member of this named D to the input POINT type value named D.
     * 
     * (The keyword this refers to the SQUARE object which is returned by this function).
     * 
     * If A, B, C, and D represent unique points on a Cartesian plane and
     * if the interior angles of the quadrilateral which those points would represent add up to 360 degrees and
     * if the area of the quadrilateral which those points represents is larger than zero,
     * if each interior angle of that quadrilateral has an angle measurement of 90 degrees, and
     * if each side of that quadrilateral has the same length,
     * use the input POINT values as the POINT values for the SQUARE object which is returned by this function.
     */
    SQUARE(std::string color, POINT A, POINT B, POINT C, POINT D);
    
    /**
     * The copy constructor of SQUARE creates a clone of 
     * the input SQUARE instance.
     */
    SQUARE(SQUARE & square);
    
    /** 
     * This method overrides the RECTANGLE class's print method.
     * 
     * The descriptor method prints a description of the caller SQUARE instance to the output stream.
     * 
     * If no function input is supplied, output is set to the command line terminal.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the SQUARE class,
     * but the friend function does have access to the private and protected members of the SQUARE class as though
     * the friend function was a member of the SQUARE class.
     */
    friend std::ostream & operator << (std::ostream & output, SQUARE & square);

    /**
     * The destructor method of the SQUARE class de-allocates memory which was used to 
     * instantiate the SQUARE object which is calling this function.
     * 
     * The destructor method of the SQUARE class is automatically called when 
     * the program scope in which the caller SQUARE object was instantiated terminates.
     */
    ~SQUARE();
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
