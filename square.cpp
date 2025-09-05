/**
 * file: square.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the SQUARE class.
#include "square.h" 

/**
 * The helper method determines whether or not the caller SQUARE instance represents a
 * quadrilateral such that each side is the same length and each interior angle measurement of that is 90 degrees.
 * Return true if the caller SQUARE satisfies those conditions. Otherwise, return false.
 */
bool SQUARE::is_square()
{
    double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
    double a0 = 0.0, b0 = 0.0, c0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double angle_opposite_of_a0 = 0.0, angle_opposite_of_b0 = 0.0, angle_opposite_of_c0 = 0.0; 
    double angle_opposite_of_a1 = 0.0, angle_opposite_of_b1 = 0.0, angle_opposite_of_c1 = 0.0; 
    double interior_angle_of_A = 0.0, interior_angle_of_B = 0.0, interior_angle_of_C = 0.0, interior_angle_of_D = 0.0;

    // first triangle
    a0 = A.get_distance_from(B);
    b0 = B.get_distance_from(D);
    c0 = D.get_distance_from(A);
    angle_opposite_of_a0 = acos(((b0 * b0) + (c0 * c0) - (a0 * a0)) / (2 * b0 * c0)) * (180 / PI);
    angle_opposite_of_b0 = acos(((a0 * a0) + (c0 * c0) - (b0 * b0)) / (2 * a0 * c0)) * (180 / PI);
    angle_opposite_of_c0 = acos(((a0 * a0) + (b0 * b0) - (c0 * c0)) / (2 * a0 * b0)) * (180 / PI);

    // second triangle
    a1 = D.get_distance_from(B);
    b1 = B.get_distance_from(C);
    c1 = C.get_distance_from(D);
    angle_opposite_of_a1 = acos(((b1 * b1) + (c1 * c1) - (a1 * a1)) / (2 * b1 * c1)) * (180 / PI);
    angle_opposite_of_b1 = acos(((a1 * a1) + (c1 * c1) - (b1 * b1)) / (2 * a1 * c1)) * (180 / PI);
    angle_opposite_of_c1 = acos(((a1 * a1) + (b1 * b1) - (c1 * c1)) / (2 * a1 * b1)) * (180 / PI);

    interior_angle_of_A = angle_opposite_of_b0;
    interior_angle_of_B = angle_opposite_of_c0 + angle_opposite_of_c1;
    interior_angle_of_C = angle_opposite_of_a1;
    interior_angle_of_D = angle_opposite_of_b1 + angle_opposite_of_a0;

    /* sides of quadrilateral */
    a = B.get_distance_from(C);
    b = C.get_distance_from(D);
    c = D.get_distance_from(A);
    d = A.get_distance_from(B);

    if (!is_rectangle()) return false;

    // Determine whether each side of the quadrilateral has the same length.
    if ((a == b) && (b == c) && (c == d) && (d == a)) return true;
    return false;
}

/**
 * The default constructor of the SQUARE class calls the constructor of the RECTANGLE class and
 * sets the POINT type data member of the SQUARE object returned by this function named A to POINT(0,0), 
 * sets the POINT type data member of the SQUARE object returned by this function named B to POINT(0,5), 
 * sets the POINT type data member of the SQUARE object returned by this function named C to POINT(5,5), and
 * sets the POINT type data member of the SQUARE object returned by this function named D to POINT(5,0).
 */
SQUARE::SQUARE()
{
    std::cout << "\n\nCreating the SQUARE type object whose memory address is " << this << "...";
    A = POINT(0,0);
    B = POINT(0,5);
    C = POINT(5,5);
    D = POINT(5,0);
}

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
SQUARE::SQUARE(std::string color, POINT A, POINT B, POINT C, POINT D)
{
    std::cout << "\n\nCreating the SQUARE type object whose memory address is " << this << "...";
    SQUARE test_square;
    test_square.A.set_X(A.get_X());
    test_square.A.set_Y(A.get_Y());
    test_square.B.set_X(B.get_X());
    test_square.B.set_Y(B.get_Y());
    test_square.C.set_X(C.get_X());
    test_square.C.set_Y(C.get_Y());
    test_square.D.set_X(D.get_X());
    test_square.D.set_Y(D.get_Y());
    if (test_square.is_square())
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
        this -> D = D;
    }
    else
    {
        this -> A = POINT(0,0);
        this -> B = POINT(0,3);
        this -> C = POINT(4,3);
        this -> D = POINT(4,0);
    }
    this -> color = color;
}
    
/**
 * The copy constructor of SQUARE creates a clone of 
 * the input SQUARE instance.
 */
SQUARE::SQUARE(SQUARE & square)
{
    std::cout << "\n\nCreating the SQUARE type object whose memory address is " << this << "...";
    A = square.A;
    B = square.B;
    C = square.C;
    D = square.D;
    color = square.color;
}
    
/** 
 * This method overrides the RECTANGLE class's print method.
 * 
 * The descriptor method prints a description of the caller SQUARE instance to the output stream.
 * 
 * If no function input is supplied, output is set to the command line terminal.
 */
void SQUARE::print(std::ostream & output)
{
    double a0 = 0.0, b0 = 0.0, c0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double angle_opposite_of_a0 = 0.0, angle_opposite_of_b0 = 0.0, angle_opposite_of_c0 = 0.0; 
    double angle_opposite_of_a1 = 0.0, angle_opposite_of_b1 = 0.0, angle_opposite_of_c1 = 0.0; 
    double interior_angle_of_A = 0.0, interior_angle_of_B = 0.0, interior_angle_of_C = 0.0, interior_angle_of_D = 0.0;

    // first triangle
    a0 = A.get_distance_from(B);
    b0 = B.get_distance_from(D);
    c0 = D.get_distance_from(A);
    angle_opposite_of_a0 = acos(((b0 * b0) + (c0 * c0) - (a0 * a0)) / (2 * b0 * c0)) * (180 / PI);
    angle_opposite_of_b0 = acos(((a0 * a0) + (c0 * c0) - (b0 * b0)) / (2 * a0 * c0)) * (180 / PI);
    angle_opposite_of_c0 = acos(((a0 * a0) + (b0 * b0) - (c0 * c0)) / (2 * a0 * b0)) * (180 / PI);

    // second triangle
    a1 = D.get_distance_from(B);
    b1 = B.get_distance_from(C);
    c1 = C.get_distance_from(D);
    angle_opposite_of_a1 = acos(((b1 * b1) + (c1 * c1) - (a1 * a1)) / (2 * b1 * c1)) * (180 / PI);
    angle_opposite_of_b1 = acos(((a1 * a1) + (c1 * c1) - (b1 * b1)) / (2 * a1 * c1)) * (180 / PI);
    angle_opposite_of_c1 = acos(((a1 * a1) + (b1 * b1) - (c1 * c1)) / (2 * a1 * b1)) * (180 / PI);

    interior_angle_of_A = angle_opposite_of_b0;
    interior_angle_of_B = angle_opposite_of_c0 + angle_opposite_of_c1;
    interior_angle_of_C = angle_opposite_of_a1;
    interior_angle_of_D = angle_opposite_of_b1 + angle_opposite_of_a0;

    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a QUADRILATERAL sized chunk of contiguous memory cells which are allocated to the caller TRIANGLE object.";
    output << "\n&category = " << &category << ". // The reference operation returns the memory address of the first memory cell of a string sized chunk of contiguous memory cells which are allocated to the string data attribute named category.";
    output << "\n&color = " << &color << ". // The reference operation returns the memory address of the first memory cell of a string sized chunk of contiguous memory cells which are allocated to the string data attribute named color..";
    output << "\n&A = " << &A << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named A.";
    output << "\n&B = " << &B << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named B.";
    output << "\n&C = " << &C << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named C.";
    output << "\n&D = " << &D << ". // The reference operation returns the memory address of the first memory cell of a POINT sized chunk of contiguous memory cells which are allocated to the POINT data attribute named D.";
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
    output << "\nsizeof(QUADRILATERAL) = " << sizeof(QUADRILATERAL) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a QUADRILATERAL type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(QUADRILATERAL *) = " << sizeof(QUADRILATERAL *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-QUADRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(QUADRILATERAL **) = " << sizeof(QUADRILATERAL **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-QUADRILATERAL type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(RECTANGLE) = " << sizeof(RECTANGLE) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a RECTANGLE type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(RECTANGLE *) = " << sizeof(RECTANGLE *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-RECTANGLE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(RECTANGLE **) = " << sizeof(RECTANGLE **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-RECTANGLE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(SQUARE) = " << sizeof(SQUARE) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a SQUARE type object occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(SQUARE *) = " << sizeof(SQUARE *) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-SQUARE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(SQUARE **) = " << sizeof(SQUARE **) << ". // The sizeof() operation returns the nonnegative integer number of bytes of memory which a pointer-to-pointer-to-SQUARE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\ncategory = " << category << ". // This is an immutable string type value which is a data member of the caller RECTANGLE object.";
    output << "\ncolor = " << color << ". // This is a string type value which is a data member of the caller RECTANGLE object.";
    output << "\nA = POINT(" << A.get_X() << "," << A.get_Y() << "). // A represents a point (which is neither B nor C nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nB = POINT(" << B.get_X() << "," << B.get_Y() << "). // B represents a point (which is neither A nor C nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nC = POINT(" << C.get_X() << "," << C.get_Y() << "). // C represents a point (which is neither A nor B nor D) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\nD = POINT(" << D.get_X() << "," << D.get_Y() << "). // D represents a point (which is neither A nor B nor C) plotted on a two-dimensional Cartesian grid (such that the X value represents a real whole number position along the horizontal axis of the Cartesian grid while Y represents a real whole number position along the vertical axis of the same Cartesian grid).";
    output << "\na = B.get_distance_from(C) = " << B.get_distance_from(C) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points B and C.";
    output << "\nb = C.get_distance_from(D) = " << C.get_distance_from(D) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points C and D.";
    output << "\nc = D.get_distance_from(A) = " << D.get_distance_from(A) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points D and A.";
    output << "\nd = A.get_distance_from(B) = " << A.get_distance_from(B) << ". // The method returns the approximate nonnegative real number of Cartesian grid unit lengths which span the length of the shortest path between points A and B.";
    output << "\nA.get_slope_of_line_to(B) = " << A.get_slope_of_line_to(B) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points A and B.";
    output << "\nB.get_slope_of_line_to(C) = " << B.get_slope_of_line_to(C) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points B and C.";
    output << "\nC.get_slope_of_line_to(D) = " << C.get_slope_of_line_to(D) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points C and D.";
    output << "\nD.get_slope_of_line_to(A) = " << D.get_slope_of_line_to(A) << ". // The method returns the approximate nonnegative real number which represents the slope of the line which intersects points B and C.";
    output << "\ninterior_angle_DAB = interior_angle_of_A = " << interior_angle_of_A << ". // The value represents the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are D and A with the line segment whose endpoints are A and B such that those two line segments intersect at A (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_ABC = interior_angle_of_B = " << interior_angle_of_B << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are A and B with the line segment whose endpoints are B and C such that those two line segments intersect at B (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_BCD = interior_angle_of_C = " << interior_angle_of_C << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are B and C with the line segment whose endpoints are C and D such that those two line segments intersect at C (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_CDA = interior_angle_of_D = " << interior_angle_of_D << ". // The method returns the approximate nonnegative real number angle measurement of the acute or else right angle formed by the intersection of the line segment whose endpoints are C and D with the line segment whose endpoints are D and A such that those two line segments intersect at D (and the angle measurement is in degrees and not in radians).";
    output << "\ninterior_angle_of_A + interior_angle_of_B + interior_angle_of_C + interior_angle_of_D = " << interior_angle_of_A + interior_angle_of_B + interior_angle_of_C + interior_angle_of_D << ". // sum of all four approximate interior angle measurements of the quadrilateral represented by the caller QUADRILATERAL object (in degrees and not in radians)";
    output << "\nget_perimeter() = a + b + c + d = " << get_perimeter() << ". // The method returns the sum of the four approximated side lengths of the rectangle which the caller RECTANGLE object represents.";
    output << "\nget_area() = " << get_area() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit squares which are enclosed inside of the two-dimensional region formed by the four line segments which connect points A to B, B to C, C to D, and D to A.";
    output << "\n--------------------------------------------------------------------------------------------------";
}
    
/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the SQUARE class,
 * but the friend function does have access to the private and protected members of the SQUARE class as though
 * the friend function was a member of the SQUARE class.
 */
std::ostream & operator << (std::ostream & output, SQUARE & square)
{
    square.print(output);
    return output;
}

/**
 * The destructor method of the SQUARE class de-allocates memory which was used to 
 * instantiate the SQUARE object which is calling this function.
 * 
 * The destructor method of the SQUARE class is automatically called when 
 * the program scope in which the caller SQUARE object was instantiated terminates.
 */
SQUARE::~SQUARE()
{
    std::cout << "\n\nDeleting the SQUARE type object whose memory address is " << this << "...";
}
