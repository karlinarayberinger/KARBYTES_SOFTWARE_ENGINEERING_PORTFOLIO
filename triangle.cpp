/**
 * file: triangle.cpp
 * type: C++ (source file)
 * author: karbytes
 * date: 07_JULY_2023
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRIANGLE class.
#include "triangle.h" 

/**
 * Determine whether or not point_0, point_1, and point_2 each represent unique coordinate pairs.
 * 
 * (Assume that point_0, point_1, and point_2 each represent valid POINT instances).
 * 
 * If each of the three POINT objects represent unique coordinate pairs, return true.
 * 
 * Otherwise, return false.
 */
bool TRIANGLE::points_represent_unique_coordinate_pairs(POINT point_0, POINT point_1, POINT point_2)
{
    if ((point_0.get_X() == point_1.get_X()) && (point_0.get_Y() == point_1.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_1 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        return false;
    }
    if ((point_0.get_X() == point_2.get_X()) && (point_0.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_0 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_1.get_X() == point_2.get_X()) && (point_1.get_Y() == point_2.get_Y())) 
    {
        std::cout << "\n\npoint_1 and point_2 appear to represent the same coordinate pair.";
        std::cout << "\npoint_1 := POINT(" << point_1.get_X() << ", " << point_1.get_Y() << ").";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        return false;
    }
    if ((point_2.get_X() == point_0.get_X()) && (point_2.get_Y() == point_0.get_Y())) 
    {
        std::cout << "\n\npoint_2 and point_0 appear to represent the same coordinate pair.";
        std::cout << "\npoint_2 := POINT(" << point_2.get_X() << ", " << point_2.get_Y() << ").";
        std::cout << "\npoint_0 := POINT(" << point_0.get_X() << ", " << point_0.get_Y() << ").";
        return false;
    }
    return true;
}

/**
 * Determine whether or not point_0, point_1, and point_2 form a non-degenerate triangle.
 * 
 * (Assume that point_0, point_1, and point_2 each represent valid POINT instances).
 * 
 * A non-degenerate triangle is a triangle whose area is some positive real number quantity.
 * 
 * A degenerate triangle is a triangle whose area is zero (due to the fact that one line intersects each of the three points).
 * 
 * If point_0, point_1, and point_2 form a non-degenerate triangle, return true.
 * 
 * Otherwise, return false.
 */
bool TRIANGLE::points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2)
{
    if (!points_represent_unique_coordinate_pairs(point_0, point_1, point_2))
    {
        std::cout << "\n\npoint_0, point_1, and point_2 do not each represent unique coordinate pairs.";
        std::cout << "\nHence, points_form_degenerate_triangle(point_0, point_1, point_2) is returning false.";
        return false;
    }
    A = point_0;
    B = point_1;
    C = point_2;
    if (get_area() <= 0) 
    {
        std::cout << "\n\nWhen setting the POINT values of the caller TRIANGLE object using the given inputs, get_area() returned a non-positive number result.";
        std::cout << "\nHence, points_form_nondegenerate_triangle(POINT point_0, POINT point_1, POINT point_2) is returning false.";
        return false;
    }
    return true;
}

/**
 * The default constructor method of the TRIANGLE class returns a TRIANGLE object 
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE()
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << "...";
    A = POINT(0, 0);
    B = POINT(0, 1);
    C = POINT(1, 0);
}

/**
 * The normal constructor method of the TRIANGLE class (which takes six int type values as function inputs) returns a TRIANGLE object 
 * whose POINT property named A represents the coordinate pair (A_X, A_Y),
 * whose POINT property named B represents the coordinate pair (B_X, B_Y), and
 * whose POINT property named C represents the coordinate pair (C_X, C_Y)
 * if POINT(A_X, A_Y), POINT(B_X, B_Y), and POINT(C_X, C_Y) represent a non-degenerate triangle.
 * 
 * If POINT(A_X, A_Y, POINT(B_X, B_Y), and POINT(C_X, C_Y) do not represent a non-degenerate triangle,
 * this function will return a TRIANGLE object
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 */
TRIANGLE::TRIANGLE(int A_X, int A_Y, int B_X, int B_Y, int C_X, int C_Y)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << "...";
    POINT input_A = POINT(A_X, A_Y);
    POINT input_B = POINT(B_X, B_Y);
    POINT input_C = POINT(C_X, C_Y);
    if (points_form_nondegenerate_triangle(input_A, input_B, input_C))
    {
        A = input_A;
        B = input_B;
        C = input_C;
    }
    else
    {
        A = POINT(0, 0);
        B = POINT(0, 1);
        C = POINT(1, 0);
    }
}

/**
 * The normal constructor method of the TRIANGLE class (which takes three POINT objects as function inputs) returns a TRIANGLE object 
 * whose POINT property named A represents the same coordinate pair as the parameter named A,
 * whose POINT property named B represents the same coordinate pair as the parameter named B, and
 * whose POINT property named C represents the same coordinate pair as the parameter named C
 * if parameter A, parameter B, and parameter C represent a non-degenerate triangle.
 * 
 * If parameter A, parameter B, and parameter C do not represent a non-degenerate triangle,
 * this function will return a TRIANGLE object
 * whose POINT property named A represents the coordinate pair (0, 0),
 * whose POINT property named B represents the coordinate pair (0, 1), and
 * whose POINT property named C represents the coordinate pair (1, 0).
 * 
 * (The keyword this refers to the TRIANGLE object which is returned by the TRIANGLE(POINT A, POINT B, POINT C) method of the TRIANGLE class).
 */
TRIANGLE::TRIANGLE(POINT A, POINT B, POINT C)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << ".";
    if (points_form_nondegenerate_triangle(A, B, C))
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
    }
    else
    {
        this -> A = POINT(0, 0);
        this -> B = POINT(0, 1);
        this -> C = POINT(1, 0);
    }
}

/**
 * The copy constructor method of the TRIANGLE class returns a TRIANGLE object 
 * whose POINT property named A represents the same coordinate pair as the POINT property named A which belongs to the input TRIANGLE object,
 * whose POINT property named B represents the same coordinate pair as the POINT property named B which belongs to the input TRIANGLE object, and
 * whose POINT property named C represents the same coordinate pair as the POINT property named C which belongs to the input TRIANGLE object. 
 * 
 * (The keyword this refers to the TRIANGLE object which is returned by the copy constructor method of the TRIANGLE class).
 */
TRIANGLE::TRIANGLE(const TRIANGLE & triangle)
{
    std::cout << "\n\nCreating the TRIANGLE type object whose memory address is " << this << ".";
    this -> A = triangle.A;
    this -> B = triangle.B;
    this -> C = triangle.C;
}

/** 
 * The getter method of the TRIANGLE class named get_A() returns the POINT type value of the caller TRIANGLE object's A property.
 */
POINT TRIANGLE::get_A()
{
    return A;
}

/** 
 * The getter method of the TRIANGLE class named get_B() returns the POINT type value of the caller TRIANGLE object's B property.
 */
POINT TRIANGLE::get_B()
{
    return B;
}

/** 
 * The getter method of the TRIANGLE class named get_C() returns the POINT type value of the caller TRIANGLE object's C property.
 */
POINT TRIANGLE::get_C()
{
    return C;
}

/** 
 * The getter method of the TRIANGLE class named get_side_length_AB() returns the approximate length of the shortest path between points A and B.
 */
double TRIANGLE::get_side_length_AB()
{
    return A.get_distance_from(B);
}

/** 
 * The getter method of the TRIANGLE class named get_side_length_BC() returns the approximate length of the shortest path between points B and C.
 */
double TRIANGLE::get_side_length_BC()
{
    return B.get_distance_from(C);
}

/** 
 * The getter method of the TRIANGLE class named get_side_length_CA() returns the approximate length of the shortest path between points C and A.
 */
double TRIANGLE::get_side_length_CA()
{
    return C.get_distance_from(A);
}

/**
 * The getter method of the TRIANGLE class named get_interior_angle_ABC() returns the approximate angle measurement in degrees of the angle
 * formed by connecting points A, B, anc C in the order specified by this sentence.
 * 
 * The function below uses the Law of Cosines to compute the measurement of an interior angle of a triangle 
 * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
 */
double TRIANGLE::get_interior_angle_ABC()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A.
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_b;
}

/**
 * The getter method of the TRIANGLE class named get_interior_angle_BCA() returns the approximate angle measurement in degrees of the angle
 * formed by connecting points B, C, and A in the order specified by this sentence.
 * 
 * The function below uses the Law of Cosines to compute the measurement of an interior angle of a triangle 
 * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
 */
double TRIANGLE::get_interior_angle_BCA()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C.
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A.
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B.
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_c;
}

/**
 * The getter method of the TRIANGLE class named get_interior_angle_CAB() returns the approximate angle measurement in degrees of the angle
 * formed by connecting points C, A, and B in the order specified by this sentence.
 * 
 * The function below uses Law of Cosines to compute the measurement of an interior angle of a triangle 
 * using that triangle's three side lengths as function inputs to output some nonnegative real number of degrees.
 */   
double TRIANGLE::get_interior_angle_CAB()
{
    double a = 0.0, b = 0.0, c = 0.0, angle_opposite_of_a = 0.0, angle_opposite_of_b = 0.0, angle_opposite_of_c = 0.0;
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C (and which are points of the caller TRIANGLE object of this function represents).
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A (and which are points of the caller TRIANGLE object of this function represents).
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B (and which are points of the caller TRIANGLE object of this function represents).
    angle_opposite_of_a = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c)) * (180 / PI);
    angle_opposite_of_b = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)) * (180 / PI);
    angle_opposite_of_c = acos(((a * a) + (b * b) - (c * c)) / (2 * a * b)) * (180 / PI);
    return angle_opposite_of_a;
}

/** 
 * The getter method of the TRIANGLE class named get_perimeter() returns the approximate sum of the three side lengths 
 * of the triangle which the caller TRIANGLE object represents.
 */
double TRIANGLE::get_perimeter()
{
    return get_side_length_AB() + get_side_length_BC() + get_side_length_CA();
}

/** 
 * The getter method of the TRIANGLE class named get_area() returns the approximate area of the two-dimensional space whose bounds are 
 * the shortest paths between points A, B, and C of the triangle which the caller TRIANGLE object represents.
 * 
 * This function uses Heron's Formula to compute the area of a triangle using that triangle's side lengths as formula inputs.
 */
double TRIANGLE::get_area()
{
    double s = 0.0, a = 0.0, b = 0.0, c = 0.0;
    s = get_perimeter() / 2; // s is technically referred to as the semiperimter of the triangle which the caller TRIANGLE object of this function represents.
    a = get_side_length_BC(); // a represents the length of the line segment whose endpoints are B and C (and which are points of the caller TRIANGLE object of this function represents).
    b = get_side_length_CA(); // b represents the length of the line segment whose endpoints are C and A (and which are points of the caller TRIANGLE object of this function represents).
    c = get_side_length_AB(); // c represents the length of the line segment whose endpoints are A and B (and which are points of the caller TRIANGLE object of this function represents).
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Use Heron's Formula to compute the area of the triangle whose points are A, B, and C (and which are points of the caller TRIANGLE object of this function represents).
}

/**
 * The print method of the TRIANGLE class prints a description of the caller TRIANGLE object to the output stream.
 * 
 * Note that the default value of the function input parameter is the standard command line output stream (std::cout).
 * 
 * The default parameter is defined in the TRIANGLE class header file (i.e. triangle.h) and not in the TRIANGLE class source file (i.e. triangle.cpp).
 */
void TRIANGLE::print(std::ostream & output)
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a TRIANGLE sized chunk of contiguous memory cells which are allocated to the caller TRIANGLE object.";
    output << "\n&A = " << &A << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named A.";
    output << "\n&B = " << &B << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named B.";
    output << "\n&C = " << &C << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named C.";
    output << "\nsizeof(int) = " << sizeof(int) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which an int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(POINT) = " << sizeof(POINT) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a POINT type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(TRIANGLE) = " << sizeof(TRIANGLE) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a TRIANGLE type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nA = POINT(" << A.get_X() << "," << A.get_Y() << "). // A represents a point (which is neither B nor C) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nB = POINT(" << B.get_X() << "," << B.get_Y() << "). // B represents a point (which is neither A nor C) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nC = POINT(" << C.get_X() << "," << C.get_Y() << "). // C represents a point (which is neither A nor B) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\na = get_side_length_BC() = " << get_side_length_BC() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points B and C.";
    output << "\nb = get_side_length_CA() = " << get_side_length_CA() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points C and A.";
    output << "\nc = get_side_length_AB() = " << get_side_length_AB() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points A and B.";
    output << "\nA.get_slope_of_line_to(B) = " << A.get_slope_of_line_to(B) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points A and B.";
    output << "\nB.get_slope_of_line_to(C) = " << B.get_slope_of_line_to(C) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points B and C.";
    output << "\nC.get_slope_of_line_to(A) = " << C.get_slope_of_line_to(A) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points C and A.";
    output << "\nget_interior_angle_CAB() =  " << get_interior_angle_CAB() << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are C and A with the line segment whose endpoints are A and B such that those two line segments intersect at A (and the angle measurement is in degrees and not in radians).";
    output << "\nget_interior_angle_ABC() =  " << get_interior_angle_ABC() << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are A and B with the line segment whose endpoints are B and C such that those two line segments intersect at B (and the angle measurement is in degrees and not in radians).";
    output << "\nget_interior_angle_BCA() =  " << get_interior_angle_BCA() << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are B and C with the line segment whose endpoints are C and A such that those two line segments intersect at C (and the angle measurement is in degrees and not in radians).";
    output << "\nget_interior_angle_CAB() + get_interior_angle_ABC() + get_interior_angle_BCA() = " << get_interior_angle_CAB() + get_interior_angle_ABC() + get_interior_angle_BCA() << ". // sum of all three approximate interior angle measurements of the triangle represented by the caller TRIANGLE object (in degrees and not in radians)";
    output << "\nget_perimeter() = a + b + c = " << get_perimeter() << ". // The method returns the sum of the three approximated side lengths of the triangle which the caller TRIANGLE object represents.";
    output << "\nget_area() = " << get_area() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit squares which are enclosed inside of the two-dimensional region formed by the three line segments which connect points A, B, and C.";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (<<).
 * 
 * (Overloading an operator is assigning a different function to a native operator other than the function which that operator is used to represent by default).
 * 
 * Note that the default value of the leftmost function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the TRIANGLE class header file (i.e. triangle.h).
 * 
 * The friend function is not a member of the TRIANGLE class, 
 * but the friend function has access to the private and protected members 
 * of the TRIANGLE class and not just to the public members of the TRIANGLE class.
 * 
 * The friend keyword only prefaces the function prototype of this function 
 * (and the prototype of this function is declared in the TRIANGLE class header file (i.e. triangle.h)). 
 * 
 * The friend keyword does not preface the definition of this function
 * (and the definition of this function is specified in the TRIANGLE class source file (i.e. triangle.cpp)).
 * 
 * // overloaded print function example one
 * TRIANGLE triangle_0;
 * std::cout << triangle_0; // identical to triangle_0.print();
 * 
 * // overloaded print function example two
 * std::ofstream file;
 * TRIANGLE triangle_1;
 * file << triangle_1; // identical to triangle_1.print(file);
 */
std::ostream & operator << (std::ostream & output, TRIANGLE & triangle)
{
    triangle.print(output);
    return output;
}

/**
 * The destructor method of the TRIANGLE class de-allocates memory which was used to 
 * instantiate the TRIANGLE object which is calling this function.
 * 
 * The destructor method of the TRIANGLE class is automatically called when 
 * the program scope in which the caller TRIANGLE object was instantiated terminates.
 */
TRIANGLE::~TRIANGLE()
{
    std::cout << "\n\nDeleting the TRIANGLE type object whose memory address is " << this << "...";
}
