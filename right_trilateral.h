/**
 * file: right_trilateral.h
 * type: C++ (header file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// If right_trilateral.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef RIGHT_TRILATERAL_H 
#define RIGHT_TRILATERAL_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRILATERAL class.
#include "trilateral.h" 

/**
 * RIGHT_TRILATERAL is a class which inherits the protected and public data
 * attributes and methods of TRILATERAL.
 * 
 * A RIGHT_TRILATERAL object represents an instance in which three unique POINT instances exist 
 * such that each one of those three POINT instances represents a unique coordinate pair within the tuple of three POINT instances 
 * (such that each coordinate pair represents exactly one two-dimensional point, POINT(X,Y), on a Cartesian grid) and
 * such that exactly one interior angle of the triangle which that RIGHT_TRILATERAL object represents is 90 degrees.
 * 
 * Each RIGHT_TRILATERAL object represents a specific three-sided polygon whose area is a positive real number.
 * 
 * (A synonym for "trilateral" is "triangle").
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
class RIGHT_TRILATERAL: public TRILATERAL
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a constant (i.e. immutable) string type value.
     */
    const std::string category = "POLYGON/TRILATERAL/RIGHT_TRILATERAL";
    
public:
    
    /**
     * The default constructor of the RIGHT_TRILATERAL class calls the constructor of the TRILATERAL class and
     * sets the POINT type data member of the RIGHT_TRILATERAL object returned by this function named A to POINT(0,0), 
     * sets the POINT type data member of the RIGHT_TRILATERAL object returned by this function named B to POINT(0,1), and
     * sets the POINT type data member of the RIGHT_TRILATERAL object returned by this function named C to POINT(1,0).
     */
    RIGHT_TRILATERAL();
    
    /**
     * The normal constructor of RIGHT_TRILATERAL attempts to set
     * the string type data member of this to the input string type value named color and
     * the POINT type data member of this named A to the input POINT type value named A and
     * the POINT type data member of this named B to the input POINT type value named B and
     * the POINT type data member of this named C to the input POINT type value named C.
     * 
     * (The keyword this refers to the RIGHT_TRILATERAL object which is returned by this function).
     * 
     * If A, B, and C represent unique points on a Cartesian plane,
     * if the interior angles of the trilatreal which those points would represent add up to 180 degrees, 
     * if the area of the trilateral which those points represents is larger than zero, and
     * if one of the interior angles which the trilateral those points represnts is 90 degrees,
     * use the input POINT values as the POINT values for the RIGHT_TRILATERAL object which is returned by this function.
     */
    RIGHT_TRILATERAL(std::string color, POINT A, POINT B, POINT C);

    /**
     * The copy constructor method of the RIGHT_TRILATERAL class 
     * instantiates RIGHT_TRILATERAL type objects 
     * whose A value is set to the A value of the input RIGHT_TRILATERAL object,
     * whose B value is set to the B value of the input RIGHT_TRILATERAL object, and
     * whose C value is set to the C value of the input RIGHT_TRILATERAL object.
     */
    RIGHT_TRILATERAL(RIGHT_TRILATERAL & right_trilateral);
    
    /** 
     * This method overrides the TRILATERAL class's print method.
     * 
     * The descriptor method prints a description of the caller RIGHT_TRILATERAL instance to the output stream.
     * 
     * If no function input is supplied, output is set to the command line terminal.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the RIGHT_TRILATERAL class,
     * but the friend function does have access to the private and protected members of the RIGHT_TRILATERAL class as though
     * the friend function was a member of the RIGHT_TRILATERAL class.
     */
    friend std::ostream & operator << (std::ostream & output, RIGHT_TRILATERAL & right_trilateral);

    /**
     * The destructor method of the RIGHT_TRILATERAL class de-allocates memory which was used to 
     * instantiate the RIGHT_TRILATERAL object which is calling this function.
     * 
     * The destructor method of the RIGHT_TRILATERAL class is automatically called when 
     * the program scope in which the caller RIGHT_TRILATERAL object was instantiated terminates.
     */
    ~RIGHT_TRILATERAL();
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
