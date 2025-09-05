/**
 * file: trapezoid.h
 * type: C++ (header file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// If trapezoid.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef TRAPEZOID_H 
#define TRAPEZOID_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the QUADRILATERAL class.
#include "quadrilateral.h" 

/**
 * TRAPEZOID is a class which inherits the protected and public data
 * attributes and methods of QUADRILATERAL.
 * 
 * A TRAPEZOID object represents a four-sided polygon such that exactly two opposite sides
 * are parallel to each other and not the same length.
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
class TRAPEZOID: public QUADRILATERAL
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a const (i.e. const (i.e. immutable)) value.
     */
    const std::string category = "POLYGON/QUADRILATERAL/TRAPEZOID";

    /**
     * The helper method determines whether or not the caller TRAPEZOID instance represents a
     * quadrilateral with exactly two parallel opposite sides whose lengths are not identical.
     * Return true if the caller TRAPEZOID satisfies those conditions. Otherwise, return false.
     */
    bool is_trapezoid();
    
public:
    
    /**
     * The default constructor of the TRAPEZOID class calls the constructor of the QUADRILATERAL class and
     * sets the POINT type data member of the TRAPEZOID object returned by this function named A to POINT(0,0), 
     * sets the POINT type data member of the TRAPEZOID object returned by this function named B to POINT(1,1), 
     * sets the POINT type data member of the TRAPEZOID object returned by this function named C to POINT(2,1), and
     * sets the POINT type data member of the TRAPEZOID object returned by this function named D to POINT(3,0).
     */
    TRAPEZOID();

    /**
     * The normal constructor of TRAPEZOID attempts to set
     * the string type data member of this to the input string type value named color and
     * the POINT type data member of this named A to the input POINT type value named A and
     * the POINT type data member of this named B to the input POINT type value named B and
     * the POINT type data member of this named C to the input POINT type value named C and
     * the POINT type data member of this named D to the input POINT type value named D.
     * 
     * (The keyword this refers to the TRAPEZOID object which is returned by this function).
     * 
     * If A, B, C, and D represent unique points on a Cartesian plane and
     * if the interior angles of the quadrilateral which those points would represent add up to 360 degrees and
     * if the area of the quadrilateral which those points represents is larger than zero, and
     * if exactly two sides of the quadrilateral are parallel to each other,
     * use the input POINT values as the POINT values for the TRAPEZOID object which is returned by this function.
     */
    TRAPEZOID(std::string color, POINT A, POINT B, POINT C, POINT D);
    
    /**
     * The copy constructor of TRAPEZOID creates a clone of 
     * the input TRAPEZOID instance.
     */
    TRAPEZOID(TRAPEZOID & trapezoid);
    
    /** 
     * This method overrides the QUADRILATERAL class's print method.
     * 
     * The descriptor method prints a description of the caller TRAPEZOID instance to the output stream.
     * 
     * If no function input is supplied, output is set to the command line terminal.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the TRAPEZOID class,
     * but the friend function does have access to the private and protected members of the TRAPEZOID class as though
     * the friend function was a member of the TRAPEZOID class.
     */
    friend std::ostream & operator << (std::ostream & output, TRAPEZOID & trapezoid);

    /**
     * The destructor method of the TRAPEZOID class de-allocates memory which was used to 
     * instantiate the TRAPEZOID object which is calling this function.
     * 
     * The destructor method of the TRAPEZOID class is automatically called when 
     * the program scope in which the caller TRAPEZOID object was instantiated terminates.
     */
    ~TRAPEZOID();
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
