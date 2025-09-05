/**
 * file: polygon.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "polygon.h" 

/**
 * The default POLYGON constructor sets the color value to "orange".
 * 
 * Note that POLYGON type objects cannot be instantiated (i.e. occupy space in memory)
 * because the POLYGON class is abstract. 
 * 
 * (pointer-to-POLYGON type variables can be instantiated, however, and used to store the memory addresses
 * of objects whose classes are derived from the POLYGON).
 * 
 * POLYGON polygon; // This command does not work because POLYGON is an abstract class.
 * POLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.
 * pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of during program compile time).
 * pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method and not the QUADRILATERAL print method.
 * 
 * The POLYGON constructor is implemented only by classes which are
 * descendents of the POLYGON class.
 */
POLYGON::POLYGON()
{
    std::cout << "\n\nCreating the POLYGON type object whose memory address is " << this << "...";
    color = "orange";
}

/**
 * The virtual methods get_area() and get_perimeter() must be defined by 
 * classes which are derived from the POLYGON class.
 */
double POLYGON::get_area() { return 0.0; }
double POLYGON::get_perimeter() { return 0.0; }

/**
 * The descriptor method prints a description of the caller POLYGON instance to the output stream.
 * If no function input is supplied, output is set to the command line terminal.
 */
void POLYGON::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nmemory_address = " << this << ".";
    output << "\ncategory = " << category << ".";
    output << "\ncolor = " << color << ".";
    output << "\n&category = " << &category << ".";
    output << "\n&color = " << &color << ".";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the POLYGON class,
 * but that friend function does have access to the private and protected members of the POLYGON class
 * as though that friend function was a member of the POLYGON class.
 */
std::ostream & operator << (std::ostream & output, POLYGON & polygon)
{
    polygon.print(output);
    return output;
}

/**
 * The destructor method of the POLYGON class de-allocates memory which was used to 
 * instantiate the POLYGON object which is calling this function.
 * 
 * The destructor method of the POLYGON class is automatically called when 
 * the program scope in which the caller POLYGON object was instantiated terminates.
 */
POLYGON::~POLYGON()
{
    std::cout << "\n\nDeleting the POLYGON type object whose memory address is " << this << "...";
}
