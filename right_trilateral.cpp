/**
 * file: right_trilateral.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the RIGHT_TRILATERAL class.
#include "right_trilateral.h" 

/**
 * The default constructor of the RIGHT_TRILATERAL class calls the constructor of the TRILATERAL class and
 * sets the POINT type data member of the RIGHT_TRILATERAL object returned by this function named A to POINT(0,0), 
 * sets the POINT type data member of the RIGHT_TRILATERAL object returned by this function named B to POINT(0,1), and
 * sets the POINT type data member of the RIGHT_TRILATERAL object returned by this function named C to POINT(1,0).
 */
RIGHT_TRILATERAL::RIGHT_TRILATERAL()
{
    std::cout << "\n\nCreating the RIGHT_TRILATERAL type object whose memory address is " << this << "...";
    A = POINT(0,0);
    B = POINT(0,1);
    C = POINT(1,0);
}
    
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
RIGHT_TRILATERAL::RIGHT_TRILATERAL(std::string color, POINT A, POINT B, POINT C)
{
    bool is_right_triangle = false;
    int test_interior_angle_A = 0.0, test_interior_angle_B = 0.0, test_interior_angle_C = 0.0;
    std::cout << "\n\nCreating the RIGHT_TRILATERAL type object whose memory address is " << this << "...";
    RIGHT_TRILATERAL test_right_trilateral;
    test_right_trilateral.A.set_X(A.get_X());
    test_right_trilateral.A.set_Y(A.get_Y());
    test_right_trilateral.B.set_X(B.get_X());
    test_right_trilateral.B.set_Y(B.get_Y());
    test_right_trilateral.C.set_X(C.get_X());
    test_right_trilateral.C.set_Y(C.get_Y());
    test_interior_angle_A = (int) floor(test_right_trilateral.get_interior_angle_CAB()); // coerce the data type to be int
    test_interior_angle_B = (int) floor(test_right_trilateral.get_interior_angle_ABC()); // coerce the data type to be int
    test_interior_angle_C = (int) floor(test_right_trilateral.get_interior_angle_BCA()); // coerce the data type to be int
    if ((test_interior_angle_A == 90) && (test_interior_angle_B < 90) && (test_interior_angle_C < 90)) is_right_triangle = true;
    if ((test_interior_angle_B == 90) && (test_interior_angle_A < 90) && (test_interior_angle_C < 90)) is_right_triangle = true;
    if ((test_interior_angle_C == 90) && (test_interior_angle_A < 90) && (test_interior_angle_B < 90)) is_right_triangle = true;
    if (test_right_trilateral.interior_angles_add_up_to_180_degrees() && (test_right_trilateral.get_area() > 0) && (is_right_triangle))
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
    }
    else
    {
        this -> A = POINT(0,0);
        this -> B = POINT(0,1);
        this -> C = POINT(1,0);
    }
    this -> color = color;
}

/**
 * The copy constructor method of the RIGHT_TRILATERAL class 
 * instantiates RIGHT_TRILATERAL type objects 
 * whose A value is set to the A value of the input RIGHT_TRILATERAL object,
 * whose B value is set to the B value of the input RIGHT_TRILATERAL object, and
 * whose C value is set to the C value of the input RIGHT_TRILATERAL object.
 */
RIGHT_TRILATERAL::RIGHT_TRILATERAL(RIGHT_TRILATERAL & right_trilateral)
{
    std::cout << "\n\nCreating the RIGHT_TRILATERAL type object whose memory address is " << this << "...";
    A = right_trilateral.A;
    B = right_trilateral.B;
    C = right_trilateral.C;
    color = right_trilateral.color;
}
    
/** 
 * This method overrides the TRILATERAL class's print method.
 * 
 * The descriptor method prints a description of the caller RIGHT_TRILATERAL instance to the output stream.
 * 
 * If no function input is supplied, output is set to the command line terminal.
 */
void RIGHT_TRILATERAL::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a RIGHT_TRILATERAL sized chunk of contiguous memory cells which are allocated to the caller RIGHT_TRILATERAL object.";
    output << "\n&category = " << &category << ". // The reference operation returns the memory address of the first memory cell of a string sized chunk of contiguous memory cells which are allocated to the string data attribute named category.";
    output << "\n&color = " << &color << ". // The reference operation returns the memory address of the first memory cell of a string sized chunk of contiguous memory cells which are allocated to the string data attribute named color..";
    output << "\n&A = " << &A << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named A.";
    output << "\n&B = " << &B << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named B.";
    output << "\n&C = " << &C << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named C.";
    output << "\nsizeof(int) = " << sizeof(int) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which an int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(int *) = " << sizeof(int *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(int **) = " << sizeof(int **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which an pointer-to-pointer-to-int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string) = " << sizeof(std::string) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string *) = " << sizeof(std::string *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string **) = " << sizeof(std::string **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT) = " << sizeof(POINT) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a POINT type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT *) = " << sizeof(POINT *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-POINT type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT **) = " << sizeof(POINT **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-POINT type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POLYGON) = " << sizeof(POLYGON) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a POLYGON type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POLYGON *) = " << sizeof(POLYGON *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-POLYGON type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POLYGON **) = " << sizeof(POLYGON **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-POLYGON type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRILATERAL) = " << sizeof(TRILATERAL) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a TRILATERAL type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRILATERAL *) = " << sizeof(TRILATERAL *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-TRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRILATERAL **) = " << sizeof(TRILATERAL **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-TRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(RIGHT_TRILATERAL) = " << sizeof(RIGHT_TRILATERAL) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a RIGHT_TRILATERAL type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(RIGHT_TRILATERAL *) = " << sizeof(RIGHT_TRILATERAL *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-RIGHT_TRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(RIGHT_TRILATERAL **) = " << sizeof(RIGHT_TRILATERAL **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-RIGHT_TRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\ncategory = " << category << ". // This is an immutable string type value which is a data member of the caller RIGHT_TRILATERAL object.";
    output << "\ncolor = " << color << ". // This is a string type value which is a data member of the caller RIGHT_TRILATERAL object.";
    output << "\nA = POINT(" << A.get_X() << "," << A.get_Y() << "). // A represents a point (which is neither B nor C nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nB = POINT(" << B.get_X() << "," << B.get_Y() << "). // B represents a point (which is neither A nor C nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nC = POINT(" << C.get_X() << "," << C.get_Y() << "). // C represents a point (which is neither A nor B nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\na = B.get_distance_from(C) = " << B.get_distance_from(C) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points B and C.";
    output << "\nb = C.get_distance_from(A) = " << C.get_distance_from(A) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points C and A.";
    output << "\nc = A.get_distance_from(B) = " << A.get_distance_from(B) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points A and B.";
    output << "\nslope_of_side_a = B.get_slope_of_line_to(C) = " << B.get_slope_of_line_to(C) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points B and C.";
    output << "\nslope_of_side_b = C.get_slope_of_line_to(A) = " << C.get_slope_of_line_to(A) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points C and A.";
    output << "\nslope_of_side_c = A.get_slope_of_line_to(B) = " << A.get_slope_of_line_to(B) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points A and B.";
    output << "\ninterior_angle_of_A = get_interior_angle_CAB() = " << get_interior_angle_CAB() << ". // The value represents the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are C and A with the line segment whose endpoints are A and B such that those two line segments intersect at A (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_of_B = get_interior_angle_ABC() = " << get_interior_angle_ABC() << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are A and B with the line segment whose endpoints are B and C such that those two line segments intersect at B (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_of_C = get_interior_angle_BCA() = " << get_interior_angle_BCA() << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are B and C with the line segment whose endpoints are C and A such that those two line segments intersect at C (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_of_A + interior_angle_of_B + interior_angle_of_C = " << get_interior_angle_CAB() + get_interior_angle_ABC() + get_interior_angle_BCA() << ". // sum of all three approximate interior angle measurements of the trilateral represented by the caller TRILATERAL object (in degrees and not in radians)";
    output << "\nget_perimeter() = a + b + c = " << get_perimeter() << ". // The method returns the sum of the three approximated side lengths of the trilateral which the caller TRILATERAL object represents.";
    output << "\nget_area() = " << get_area() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit squares which are enclosed inside of the two-dimensional region formed by the three line segments which connect points A to B, B to C, and C to A.";
    output << "\n--------------------------------------------------------------------------------------------------";
}
    
/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the RIGHT_TRILATERAL class,
 * but the friend function does have access to the private and protected members of the RIGHT_TRILATERAL class as though
 * the friend function was a member of the RIGHT_TRILATERAL class.
 */
std::ostream & operator << (std::ostream & output, RIGHT_TRILATERAL & right_trilateral)
{
    right_trilateral.print(output);
    return output;
}

/**
 * The destructor method of the RIGHT_TRILATERAL class de-allocates memory which was used to 
 * instantiate the RIGHT_TRILATERAL object which is calling this function.
 * 
 * The destructor method of the RIGHT_TRILATERAL class is automatically called when 
 * the program scope in which the caller RIGHT_TRILATERAL object was instantiated terminates.
 */
RIGHT_TRILATERAL::~RIGHT_TRILATERAL()
{
    std::cout << "\n\nDeleting the RIGHT_TRILATERAL type object whose memory address is " << this << "...";  
}
