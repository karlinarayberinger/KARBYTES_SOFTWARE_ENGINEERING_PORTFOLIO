/**
 * file: trilateral.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRILATERAL class.
#include "trilateral.h" 

/**
 * If each of the three whole number coordinate pairs represented by the POINT type input values named _A, _B, and _C are unique whole number coordinate pairs, 
 * return true. 
 * Otherwise, return false.
 */
bool TRILATERAL::points_represent_unique_coordinate_pairs(POINT _A, POINT _B, POINT _C)
{
    if ((_A.get_X() == _B.get_X()) && (_A.get_Y() == _B.get_Y())) return false;
    if ((_A.get_X() == _C.get_X()) && (_A.get_Y() == _C.get_Y())) return false;
    if ((_B.get_X() == _C.get_X()) && (_B.get_Y() == _C.get_Y())) return false;
    return true;
}

/**
 * The getter method of the TRILATERAL class named get_interior_angle_ABC() returns the approximate angle measurement in degrees of the angle
 * formed by connecting points A, B, anc C in the order specified by this sentence.
 * 
 * The function below uses the Law of Cosines to compute the measurement of an interior angle of a triangle 
 * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
 */
double TRILATERAL::get_interior_angle_ABC()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = B.get_distance_from(C); // a represents the length of the line segment whose endpoints are B and C.
    b = C.get_distance_from(A); // b represents the length of the line segment whose endpoints are C and A.
    c = A.get_distance_from(B); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_b;
}

/**
 * The getter method of the TRILATERAL class named get_interior_angle_BCA() returns the approximate angle measurement in degrees of the angle
 * formed by connecting points B, C, and A in the order specified by this sentence.
 * 
 * The function below uses the Law of Cosines to compute the measurement of an interior angle of a triangle 
 * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
 */
double TRILATERAL::get_interior_angle_BCA()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = B.get_distance_from(C); // a represents the length of the line segment whose endpoints are B and C.
    b = C.get_distance_from(A); // b represents the length of the line segment whose endpoints are C and A.
    c = A.get_distance_from(B); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_c;
}

/**
 * The getter method of the TRILATERAL class named get_interior_angle_CAB() returns the approximate angle measurement in degrees of the angle
 * formed by connecting points C, A, and B in the order specified by this sentence.
 * 
 * The function below uses Law of Cosines to compute the measurement of an interior angle of a triangle 
 * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
 */   
double TRILATERAL::get_interior_angle_CAB()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = B.get_distance_from(C); // a represents the length of the line segment whose endpoints are B and C (and which are points of the caller TRIANGLE object of this function represents).
    b = C.get_distance_from(A); // b represents the length of the line segment whose endpoints are C and A (and which are points of the caller TRIANGLE object of this function represents).
    c = A.get_distance_from(B); // c represents the length of the line segment whose endpoints are A and B (and which are points of the caller TRIANGLE object of this function represents).
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_a;
}

/**
 * If sum of the interior angle measurements of the quadrilateral which the caller TRILATERAL object represents add up to approximately 180 degrees, 
 * return true.
 * Otherwise, return false.
 */
bool TRILATERAL::interior_angles_add_up_to_180_degrees()
{
    return floor(get_interior_angle_ABC()) + floor(get_interior_angle_BCA()) + floor(get_interior_angle_CAB());
}
    
/**
 * The default constructor of the TRILATERAL class calls the constructor of the POLYGON class and
 * sets the POINT type data member of the TRILATERAL object returned by this function named A to POINT(0,0), 
 * sets the POINT type data member of the TRILATERAL object returned by this function named B to POINT(4,3), and
 * sets the POINT type data member of the TRILATERAL object returned by this function named C to POINT(4,0).
 */
TRILATERAL::TRILATERAL()
{
    std::cout << "\n\nCreating the TRILATERAL type object whose memory address is " << this << "...";
    A = POINT(0,0);
    B = POINT(4,3);
    C = POINT(4,0);
}
    
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
 * use the input POINT values as the POINT values for the TRILATERAL object which is returned by this function.
 */
TRILATERAL::TRILATERAL(std::string color, POINT A, POINT B, POINT C)
{
    std::cout << "\n\nCreating the TRILATERAL type object whose memory address is " << this << "...";
    TRILATERAL test_trilateral;
    test_trilateral.A.set_X(A.get_X());
    test_trilateral.A.set_Y(A.get_Y());
    test_trilateral.B.set_X(B.get_X());
    test_trilateral.B.set_Y(B.get_Y());
    test_trilateral.C.set_X(C.get_X());
    test_trilateral.C.set_Y(C.get_Y());
    if (test_trilateral.interior_angles_add_up_to_180_degrees() && (test_trilateral.get_area() > 0))
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
    }
    else
    {
        this -> A = POINT(0,0);
        this -> B = POINT(4,3);
        this -> C = POINT(4,0);
    }
    this -> color = color;
}

/**
 * The copy constructor method of the TRILATERAL class 
 * instantiates TRILATERAL type objects 
 * whose A value is set to the A value of the input TRILATERAL object,
 * whose B value is set to the B value of the input TRILATERAL object, and
 * whose C value is set to the C value of the input TRILATERAL object.
 */
TRILATERAL::TRILATERAL(TRILATERAL & trilateral)
{
    std::cout << "\n\nCreating the TRILATERAL type object whose memory address is " << this << "...";
    A = trilateral.A;
    B = trilateral.B;
    C = trilateral.C;
    color = trilateral.color;
}

/**
 * The TRILATERAL class implements the virtual get_area() method of the POLYGON class.
 * 
 * The getter method returns the approximate area of the two-dimensional space whose bounds are 
 * the shortest paths between points A, B, and C of the triangle which the caller TRILATERAL object represents
 * This function uses Heron's Formula to compute the area of a triangle using that triangle's side lengths as formula inputs.
 */
double TRILATERAL::get_area()
{
    double s = 0.0, a = 0.0, b = 0.0, c = 0.0;
    s = get_perimeter() / 2; // s is technically referred to as the semiperimter of the triangle which the caller TRIANGLE object of this function represents.
    a = B.get_distance_from(C); // a represents the length of the line segment whose endpoints are B and C (and which are points of the caller TRIANGLE object of this function represents).
    b = C.get_distance_from(A); // b represents the length of the line segment whose endpoints are C and A (and which are points of the caller TRIANGLE object of this function represents).
    c = A.get_distance_from(B); // c represents the length of the line segment whose endpoints are A and B (and which are points of the caller TRIANGLE object of this function represents).
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Use Heron's Formula to compute the area of the triangle whose points are A, B, and C (and which are points of the caller TRIANGLE object of this function represents).
}

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
double TRILATERAL::get_perimeter()
{
    return A.get_distance_from(B) + B.get_distance_from(C) + C.get_distance_from(A);
}
    
/** 
 * This method overrides the POLYGON class's print method.
 * 
 * The descriptor method prints a description of the caller TRILATERAL instance to the output stream.
 * 
 * If no function input is supplied, output is set to the command line terminal.
 */
void TRILATERAL::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a TRILATERAL sized chunk of contiguous memory cells which are allocated to the caller TRILATERAL object.";
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
    output << "\ncategory = " << category << ". // This is an immutable string type value which is a data member of the caller TRILATERAL object.";
    output << "\ncolor = " << color << ". // This is a string type value which is a data member of the caller TRILATERAL object.";
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
 * The friend function is not a member of the TRILATERAL class,
 * but the friend function does have access to the private and protected members of the TRILATERAL class as though
 * the friend function was a member of the TRILATERAL class.
 */
std::ostream & operator << (std::ostream & output, TRILATERAL & trilateral)
{
    trilateral.print(output);
    return output;
}

/**
 * The destructor method of the TRILATERAL class de-allocates memory which was used to 
 * instantiate the TRILATERAL object which is calling this function.
 * 
 * The destructor method of the TRILATERAL class is automatically called when 
 * the program scope in which the caller TRILATERAL object was instantiated terminates.
 */
TRILATERAL::~TRILATERAL()
{
    std::cout << "\n\nDeleting the TRILATERAL type object whose memory address is " << this << "...";  
}
