/**
 * file: quadrilateral.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the QUADRILATERAL class.
#include "quadrilateral.h" 

/**
 * If each of the four whole number coordinate pairs represented by the POINT type input values named _A, _B, _C, and _D are unique whole number coordinate pairs, 
 * return true. 
 * Otherwise, return false.
 */
bool QUADRILATERAL::points_represent_unique_coordinate_pairs(POINT _A, POINT _B, POINT _C, POINT _D)
{
    if ((_A.get_X() == _B.get_X()) && (_A.get_Y() == _B.get_Y())) return false;
    if ((_A.get_X() == _C.get_X()) && (_A.get_Y() == _C.get_Y())) return false;
    if ((_A.get_X() == _D.get_X()) && (_A.get_Y() == _D.get_Y())) return false;
    if ((_B.get_X() == _C.get_X()) && (_B.get_Y() == _C.get_Y())) return false;
    if ((_B.get_X() == _D.get_X()) && (_B.get_Y() == _D.get_Y())) return false;
    if ((_C.get_X() == _D.get_X()) && (_C.get_Y() == _D.get_Y())) return false;
    return true;
}

/**
 * If sum of the interior angle measurements of the quadrilateral which the caller QUADRILATERAL object represents add up to approximately 360 degrees, 
 * return true.
 * Otherwise, return false.
 */
bool QUADRILATERAL::interior_angles_add_up_to_360_degrees()
{
    double a0 = 0.0, b0 = 0.0, c0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0;
    double angle_opposite_of_a0 = 0.0, angle_opposite_of_b0 = 0.0, angle_opposite_of_c0 = 0.0; 
    double angle_opposite_of_a1 = 0.0, angle_opposite_of_b1 = 0.0, angle_opposite_of_c1 = 0.0; 
    double interior_angle_of_A = 0.0, interior_angle_of_B = 0.0, interior_angle_of_C = 0.0, interior_angle_of_D = 0.0;
    double sum_of_interior_angles = 0.0;

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

    sum_of_interior_angles = interior_angle_of_A + interior_angle_of_B + interior_angle_of_C + interior_angle_of_D;

    // Allow for there to be a +/- 2 margin of error for the value stored in sum_of_interior_angles with the ideal value being 360.
    if ((sum_of_interior_angles >= 358) && (sum_of_interior_angles <= 362)) return true;
    return false;
}

/**
 * The test function helps to illustrate how pointers work.
 */
int QUADRILATERAL::quadrilateral_test()
{
    return 555;
}
    
/**
 * The default constructor of the QUADRILATERAL class calls the constructor of the POLYGON class and
 * sets the POINT type data member of the QUADRILATERAL object returned by this function named A to POINT(0,0), 
 * sets the POINT type data member of the QUADRILATERAL object returned by this function named B to POINT(0,5), 
 * sets the POINT type data member of the QUADRILATERAL object returned by this function named C to POINT(4,5), and
 * sets the POINT type data member of the QUADRILATERAL object returned by this function named D to POINT(4,0).
 */
QUADRILATERAL::QUADRILATERAL()
{
    std::cout << "\n\nCreating the QUADRILATERAL type object whose memory address is " << this << "...";
    A = POINT(0,0);
    B = POINT(0,5);
    C = POINT(4,5);
    D = POINT(4,0);
}
    
/**
 * The normal constructor of QUADRILATERAL attempts to set
 * the string type data member of this to the input string type value named color and
 * the POINT type data member of this named A to the input POINT type value named A and
 * the POINT type data member of this named B to the input POINT type value named B and
 * the POINT type data member of this named C to the input POINT type value named C and
 * the POINT type data member of this named D to the input POINT type value named D.
 * 
 * (The keyword this refers to the QUADRILATERAL object which is returned by this function).
 * 
 * If A, B, C, and D represent unique points on a Cartesian plane and
 * if the interior angles of the quadrilateral which those points would represent add up to 360 degrees and
 * if the area of the quadrilateral which those points represents is larger than zero,
 * use the input POINT values as the POINT values for the QUADRILATERAL object which is returned by this function.
 */
QUADRILATERAL::QUADRILATERAL(std::string color, POINT A, POINT B, POINT C, POINT D)
{
    std::cout << "\n\nCreating the QUADRILATERAL type object whose memory address is " << this << "...";
    QUADRILATERAL test_quadrilateral;
    test_quadrilateral.A.set_X(A.get_X());
    test_quadrilateral.A.set_Y(A.get_Y());
    test_quadrilateral.B.set_X(B.get_X());
    test_quadrilateral.B.set_Y(B.get_Y());
    test_quadrilateral.C.set_X(C.get_X());
    test_quadrilateral.C.set_Y(C.get_Y());
    test_quadrilateral.D.set_X(D.get_X());
    test_quadrilateral.D.set_Y(D.get_Y());
    if (points_represent_unique_coordinate_pairs(A, B, C, D) && test_quadrilateral.interior_angles_add_up_to_360_degrees() && (test_quadrilateral.get_area() > 0))
    {
        this -> A = A;
        this -> B = B;
        this -> C = C;
        this -> D = D;
    }
    else
    {
        this -> A = POINT(0,0);
        this -> B = POINT(0,5);
        this -> C = POINT(4,5);
        this -> D = POINT(4,0);
    }
    this -> color = color;
}

/**
 * The copy constructor method of the QUADRILATERAL class 
 * instantiates QUADRILATERAL type objects 
 * whose A value is set to the A value of the input QUADRILATERAL object,
 * whose B value is set to the B value of the input QUADRILATERAL object,
 * whose C value is set to the C value of the input QUADRILATERAL object, and
 * whose D value is set to the D value of the input QUADRILATERAL object.
 */
QUADRILATERAL::QUADRILATERAL(QUADRILATERAL & quadrilateral)
{
    std::cout << "\n\nCreating the QUADRILATERAL type object whose memory address is " << this << "...";
    A = quadrilateral.A;
    B = quadrilateral.B;
    C = quadrilateral.C;
    D = quadrilateral.D;
    color = quadrilateral.color;
}

/**
 * The QUADRILATERAL class implements the virtual get_area() method of the POLYGON class.
 * 
 * The getter method returns the area of the quadrilateral represented by the caller QUADRILATERAL object
 * using using Heron's Formula to 
 * compute the area of each of the two triangles which comprise that quadrilateral.
 * 
 * Let AB be the length of the line segment whose endpoints are A and B.
 * Let BC be the length of the line segment whose endpoints are B and C.
 * Let CA be the length of the line segment whose endpoints are C and A.
 * Let CD be the length of the line segment whose endpoints are C and D.
 * Let DA be the length of the line segment whose endpoints are D and A.
 * 
 * Let the first triangle be the area which is enclosed inside line segments represented by AB, BC, and CA.
 * Let the second triangle be the area which is enclosed inside line segments represented by AC, CD, and DA.
 * 
 * Then compute the area of each triangle using Heron's Formula as follows:
 * 
 * Let s be the semiperimeter of a triangle (i.e. the perimeter divided by 2).
 * Let a, b, and c be the side lengths of a triangle.
 * 
 * Then 
 * 
 * area = square_root( s * (s - a) * (s - b) * (s - c) ).
 * 
 * Finally, return the sum of the two triangle areas.
 */
double QUADRILATERAL::get_area()
{
    double a0 = 0.0, b0 = 0.0, c0= 0.0, s0 = 0.0, area_0 = 0.0;
    double a1 = 0.0, b1 = 0.0, c1 = 0.0, s1 = 0.0, area_1 = 0.0;

    // first triangle
    a0 = A.get_distance_from(B);
    b0 = B.get_distance_from(C);
    c0 = C.get_distance_from(A);
    s0 = (a0 + b0 + c0) / 2;
    area_0 = sqrt(s0 * (s0 - a0) * (s0 - b0) * (s0 - c0));

    // second triangle
    a1 = A.get_distance_from(C);
    b1 = C.get_distance_from(D);
    c1 = D.get_distance_from(A);
    s1 = (a1 + b1 + c1) / 2;
    area_1 = sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));

    // Return the sum of the two triangle areas.
    return area_0 + area_1;
}

/**
 * The QUADRILATERAL class implements the virtual get_perimeter() method of the POLYGON class.
 * 
 * The getter method returns the perimeter of the quadrilateral represented by the caller QUADRILATERAL object
 * by adding up the four side lengths of that quadrilateral.
 * 
 * Let AB be the length of the line segment whose endpoints are A and B.
 * Let BC be the length of the line segment whose endpoints are B and C.
 * Let CD be the length of the line segment whose endpoints are C and D.
 * Let DA be the length of the line segment whose endpoints are D and A.
 * 
 * Then return the sum of AB, BC, CD, and DA.
 */
double QUADRILATERAL::get_perimeter()
{
    double AB = 0.0, BC = 0.0, CD = 0.0, DA = 0.0;
    AB = A.get_distance_from(B);
    BC = B.get_distance_from(C);
    CD = C.get_distance_from(D);
    DA = D.get_distance_from(A);
    return AB + BC + CD + DA;
}
    
/** 
 * This method overrides the POLYGON class's print method.
 * 
 * The descriptor method prints a description of the caller QUADRILATERAL instance to the output stream.
 * 
 * If no function input is supplied, output is set to the command line terminal.
 */
void QUADRILATERAL::print(std::ostream & output)
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
    output << "\ncategory = " << category << ". // This is an immutable string type value which is a data member of the caller QUADRILATERAL object.";
    output << "\ncolor = " << color << ". // This is a string type value which is a data member of the caller QUADRILATERAL object.";
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
    output << "\nget_perimeter() = a + b + c + d = " << get_perimeter() << ". // The method returns the sum of the four approximated side lengths of the quadrilateral which the caller QUADRILATERAL object represents.";
    output << "\nget_area() = " << get_area() << ". // The method returns the approximate nonnegative real number of Cartesian grid unit squares which are enclosed inside of the two-dimensional region formed by the four line segments which connect points A to B, B to C, C to D, and D to A.";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (i.e. <<).
 * 
 * The friend function is not a member of the QUADRILATERAL class,
 * but it does have access to the members of QUADRILATERAL as though
 * it were a member of that class.
 */
std::ostream & operator << (std::ostream & output, QUADRILATERAL & quadrilateral)
{
    quadrilateral.print(output);
    return output;
}

/**
 * The destructor method of the QUADRILATERAL class de-allocates memory which was used to 
 * instantiate the QUADRILATERAL object which is calling this function.
 * 
 * The destructor method of the QUADRILATERAL class is automatically called when 
 * the program scope in which the caller QUADRILATERAL object was instantiated terminates.
 */
QUADRILATERAL::~QUADRILATERAL()
{
    std::cout << "\n\nDeleting the QUADRILATERAL type object whose memory address is " << this << "...";
}
