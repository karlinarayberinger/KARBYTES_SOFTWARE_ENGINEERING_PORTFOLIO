/**
 * file: trilateral.h
 * type: C++ (header file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// If trilateral.h has not already been linked to a source file (.cpp), then link this header file to the source file(s) which include this header file.
#ifndef TRILATERAL_H 
#define TRILATERAL_H

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "polygon.h" 

/**
 * TRILATERAL is a class which inherits the protected and public data
 * attributes and methods of POLYGON (and POLYGON is an abstract class).
 * 
 * A TRILATERAL object represents an instance in which three unique POINT instances exist 
 * such that each one of those three POINT instances represents a unique coordinate pair within the tuple of three POINT instances 
 * (such that each coordinate pair represents exactly one two-dimensional point, POINT(X,Y), on a Cartesian grid).
 * 
 * Each TRILATERAL object represents a specific three-sided polygon whose area is a positive real number.
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
class TRILATERAL: public POLYGON
{
protected:

    /**
     * category is a description of the POLYGON instance.
     * category is set to a constant (i.e. immutable) string type value.
     */
    const std::string category = "POLYGON/TRILATERAL";

    /**
     * POINT type objects A, B, and C represent points on a Cartesian plane.
     * Each POINT type object has two int type variables for representing a two-dimensional whole number coordinate pair.
     * The X data attribute of a POINT object represents a whole number position on the horizontal axis (i.e. x-axis) of a Cartesian plane.
     * The Y data attribute of a POINT object represents a whole number position on the vertical axis (i.e. y-axis) of the same Cartesian plane.
     */
    POINT A, B, C;

    /**
     * If each of the three whole number coordinate pairs represented by the POINT type input values named _A, _B, and _C are unique whole number coordinate pairs, 
     * return true. 
     * Otherwise, return false.
     */
    bool points_represent_unique_coordinate_pairs(POINT _A, POINT _B, POINT _C);

    /**
     * The getter method of the TRILATERAL class named get_interior_angle_ABC() returns the approximate angle measurement in degrees of the angle
     * formed by connecting points A, B, anc C in the order specified by this sentence.
     * 
     * The function below uses the Law of Cosines to compute the measurement of an interior angle of a triangle 
     * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
     */
    double get_interior_angle_ABC();

    /**
     * The getter method of the TRILATERAL class named get_interior_angle_BCA() returns the approximate angle measurement in degrees of the angle
     * formed by connecting points B, C, and A in the order specified by this sentence.
     * 
     * The function below uses the Law of Cosines to compute the measurement of an interior angle of a triangle 
     * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
     */
    double get_interior_angle_BCA();

    /**
     * The getter method of the TRILATERAL class named get_interior_angle_CAB() returns the approximate angle measurement in degrees of the angle
     * formed by connecting points C, A, and B in the order specified by this sentence.
     * 
     * The function below uses Law of Cosines to compute the measurement of an interior angle of a triangle 
     * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
     */   
    double get_interior_angle_CAB();

    /**
     * If sum of the interior angle measurements of the quadrilateral which the caller TRILATERAL object represents add up to approximately 180 degrees, 
     * return true.
     * Otherwise, return false.
     */
    bool interior_angles_add_up_to_180_degrees();
    
public:
    
    /**
     * The default constructor of the TRILATERAL class calls the constructor of the POLYGON class and
     * sets the POINT type data member of the TRILATERAL object returned by this function named A to POINT(0,0), 
     * sets the POINT type data member of the TRILATERAL object returned by this function named B to POINT(4,3), and
     * sets the POINT type data member of the TRILATERAL object returned by this function named C to POINT(4,0).
     */
    TRILATERAL();
    
    /**
     * The normal constructor of TRILATERAL attempts to set
     * the string type data member of this to the input string type value named color and
     * the POINT type data member of this named A to the input POINT type value named A and
     * the POINT type data member of this named B to the input POINT type value named B and
     * the POINT type data member of this named C to the input POINT type value named C.
     * 
     * (The keyword this refers to the TRILATERAL object which is returned by this function).
     * 
     * If A, B, and C represent unique points on a Cartesian plane,
     * if the interior angles of the trilatreal which those points would represent add up to 180 degrees, and
     * if the area of the trilateral which those points represents is larger than zero,
     */
    TRILATERAL(std::string color, POINT A, POINT B, POINT C);

    /**
     * The copy constructor method of the TRILATERAL class 
     * instantiates TRILATERAL type objects 
     * whose A value is set to the A value of the input TRILATERAL object,
     * whose B value is set to the B value of the input TRILATERAL object, and
     * whose C value is set to the C value of the input TRILATERAL object.
     */
    TRILATERAL(TRILATERAL & trilateral);

    /**
     * The TRILATERAL class implements the virtual get_area() method of the POLYGON class.
     * 
     * The getter method returns the approximate area of the two-dimensional space whose bounds are 
     * the shortest paths between points A, B, and C of the triangle which the caller TRILATERAL object represents.
     * This function uses Heron's Formula to compute the area of a triangle using that triangle's side lengths as formula inputs.
     */
    double get_area();

    /**
     * The TRILATERAL class implements the virtual get_perimeter() method of the POLYGON class.
     * 
     * The getter method returns the perimeter of the trilateral represented by the caller TRILATERAL object
     * by adding up the three side lengths of that trilateral.
     * 
     * Let AB be the length of the line segment whose endpoints are A and B.
     * Let BC be the length of the line segment whose endpoints are B and C.
     * Let CA be the length of the line segment whose endpoints are C and A.
     * 
     * Then return the sum of AB, BC, and CA.
     */
    double get_perimeter();
    
    /** 
     * This method overrides the POLYGON class's print method.
     * 
     * The descriptor method prints a description of the caller TRILATERAL instance to the output stream.
     * 
     * If no function input is supplied, output is set to the command line terminal.
     */
    void print(std::ostream & output = std::cout);
    
    /**
     * The friend function is an alternative to the print method.
     * The friend function overloads the ostream operator (i.e. <<).
     * 
     * The friend function is not a member of the TRILATERAL class,
     * but the friend function does have access to the private and protected members of the TRILATERAL class as though
     * the friend function was a member of the TRILATERAL class.
     */
    friend std::ostream & operator << (std::ostream & output, TRILATERAL & trilateral);

    /**
     * The destructor method of the TRILATERAL class de-allocates memory which was used to 
     * instantiate the TRILATERAL object which is calling this function.
     * 
     * The destructor method of the TRILATERAL class is automatically called when 
     * the program scope in which the caller TRILATERAL object was instantiated terminates.
     */
    ~TRILATERAL();
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
