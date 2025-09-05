/**
 * file: triangle_class_tester.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include "triangle.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRIANGLE class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);
void unit_test_3(std::ostream & output);
void unit_test_4(std::ostream & output);

// Unit Test # 0: TRIANGLE class default constructor, TRIANGLE class print method, and TRIANGLE class destructor.
void unit_test_0(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 0: TRIANGLE class default constructor, TRIANGLE class print method, and TRIANGLE class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE point;";
    output << "\ntriangle.print(output);";
    TRIANGLE triangle;
    triangle.print(output);
}

// Unit Test # 1: TRIANGLE class default constructor, TRIANGLE class overloaded ostream operator method, TRIANGLE getter methods, and TRIANGLE class destructor.
void unit_test_1(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 1: TRIANGLE class default constructor, TRIANGLE class overloaded ostream operator method, TRIANGLE getter methods, and TRIANGLE class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE triangle;";
    output << "\nPOINT copy_of_point_A = triangle.get_A();";
    output << "\nPOINT copy_of_point_B = triangle.get_B();";
    output << "\nPOINT copy_of_point_C = triangle.get_C();";
    output << "\noutput << triangle;";
    TRIANGLE triangle;
    POINT copy_of_point_A = triangle.get_A();
    POINT copy_of_point_B = triangle.get_B();
    POINT copy_of_point_C = triangle.get_C();
    output << triangle;
    output << "\n\ncopy_of_point_A.print(output);";
    copy_of_point_A.print(output);
    output << "\n\noutput << copy_of_point_A;";
    output << copy_of_point_A;
    output << "\n\ncopy_of_point_B.print(output);";
    copy_of_point_B.print(output);
    output << "\n\noutput << copy_of_point_B;";
    output << copy_of_point_B;
    output << "\n\ncopy_of_point_C.print(output);";
    copy_of_point_C.print(output);
    output << "\n\noutput << copy_of_point_C;";
    output << copy_of_point_C;
    output << "\n\ntriangle.get_side_length_AB() = " << triangle.get_side_length_AB() << ".";
    output << "\ntriangle.get_side_length_BC() = " << triangle.get_side_length_BC() << ".";
    output << "\ntriangle.get_side_length_CA() = " << triangle.get_side_length_CA() << ".";
    output << "\ntriangle.get_interior_angle_ABC() = " << triangle.get_interior_angle_ABC() << ".";
    output << "\ntriangle.get_interior_angle_BCA() := " << triangle.get_interior_angle_BCA() << ".";
    output << "\ntriangle.get_interior_angle_CAB() = " << triangle.get_interior_angle_CAB() << ".";
    output << "\ntriangle.get_perimeter() = " << triangle.get_perimeter() << ".";
    output << "\ntriangle.get_area() = " << triangle.get_area() << ".";
}


// Unit Test # 2: TRIANGLE class normal constructors, TRIANGLE class copy constructor, TRIANGLE class print method, and TRIANGLE class destructor.
void unit_test_2(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 2: TRIANGLE class normal constructors, TRIANGLE class copy constructor, TRIANGLE class print method, and TRIANGLE class destructor.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE triangle_0 = TRIANGLE(-1, -1, 0, 5, 2, -5); // normal constructor which takes exactly 6 int type values as function inputs";
    output << "\nTRIANGLE triangle_1 = TRIANGLE( POINT(-3,-3), POINT(-4,-8), POINT(0,1) ); // normal constructor which takes 3 POINT type values as function inputs";
    output << "\nTRIANGLE triangle_2 = TRIANGLE(triangle_0); // copy constructor which takes 1 TRIANGLE type value as function input";
    output << "\ntriangle_0.print(output);";
    output << "\ntriangle_1.print(output);";
    output << "\ntriangle_2.print(output);";
    TRIANGLE triangle_0 = TRIANGLE(-1, -1, 0, 5, 2, -5); // normal constructor which takes exactly 6 int type values as function inputs
    TRIANGLE triangle_1 = TRIANGLE( POINT(-3,-3), POINT(-4,-8), POINT(0,1) ); // normal constructor which takes 3 POINT type values as function inputs
    TRIANGLE triangle_2 = TRIANGLE(triangle_0); // copy constructor which takes 1 TRIANGLE type value as function input
    triangle_0.print(output);
    triangle_1.print(output);
    triangle_2.print(output);
}

// Unit Test # 3: degenerate triangle examples.
void unit_test_3(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 3: degenerate triangle examples.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE triangle_0 = TRIANGLE( POINT(-1,-1), POINT(0,0), POINT(1,1) ); // Because these inputs would generate a degenerate triangle, default coordinate values are used for A, B, and C instead of the input values.";
    output << "\nTRIANGLE triangle_1 = TRIANGLE( POINT(-1,-1), POINT(0,0), POINT(-1,-1) ); // Because these inputs represent only 2 unique points instead of 3 unique points, default coordinate values are used for A, B, and C instead of the input values.";
    output << "\ntriangle_0.print(output);";
    output << "\ntriangle_1.print(output);";
    TRIANGLE triangle_0 = TRIANGLE( POINT(-1,-1), POINT(0,0), POINT(1,1) ); // Because these inputs would generate a degenerate triangle, default coordinate values are used for A, B, and C instead of the input values.
    TRIANGLE triangle_1 = TRIANGLE(-1, -1, 0, 0, -1, -1); // Because these inputs represent only 2 unique points instead of 3 unique points, default coordinate values are used for A, B, and C instead of the input values.
    triangle_0.print(output);
    triangle_1.print(output);
}

// Unit Test # 4: Demonstrate how the methods of the POINT class cannot be called by a TRIANGLE object due to the fact that the methods of the POINT class each have uniquely corresponding function prototypes which are prefaced with the private access specifier in the POINT class header file (i.e. POINT.h).
void unit_test_4(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\n// Unit Test # 4: Demonstrate how the methods of the POINT class cannot be called by a TRIANGLE object due to the fact that the methods of the POINT class each have uniquely corresponding function prototypes which are prefaced with the private access specifier in the POINT class header file (i.e. POINT.h).";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRIANGLE triangle;";
    output << "\ntriangle.print(output);";
    TRIANGLE triangle;
    triangle.print(output);
    output << "\nPOINT copy_A = triangle.get_A();";
    output << "\ncopy_A.print(output);";
    POINT copy_A = triangle.get_A();
    copy_A.print(output);
    copy_A.set_X(33); // The setter method of the POINT class is public. Therefore, that method can be invoked from the program scope in which the POINT type variable copy_A is instantiated.
    output << "\ncopy_A.set_X(33); // The setter method of the POINT class is public. Therefore, that method can be invoked from the program scope in which the POINT type variable copy_A is instantiated.";
    output << "\ncopy_A.print(output); // The print method of the POINT class is public. Therefore, that method can be invoked from the program scope in which the POINT type variable copy_A is insstantiated.";
    /*
    output << "\ntriangle.A.get_X() = " << triangle.A.get_X() << ". // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    output << "\ntriangle.A.get_Y() = " << triangle.A.get_Y() << ". // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    output << "\ntriangle.A.set_X(25) = " << triangle.A.set_X(25) << ". // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    output << "\ntriangle.A.get_Y(666) = " << triangle.A.set_Y(666) << ". // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    triangle.print(output);
    */
    output << "\n// COMMENTED OUT: triangle.A.get_X(); // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    output << "\n// COMMENTED OUT: triangle.A.get_Y(); // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    output << "\n// COMMENTED OUT: triangle.A.set_X(25); // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
    output << "\n// COMMENTED OUT: triangle.A.get_Y(666); // Note that this command can only be executed if the POINT type data member named A of a TRIANGLE instance is public.";
}

/* program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If triangle_class_tester_output.txt does not already exist in the same directory as triangle_class_tester.cpp, 
     * create a new file named triangle_class_tester_output.txt.
     * 
     * Open the plain-text file named triangle_class_tester_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("triangle_class_tester_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Implement a series of unit tests which demonstrate the functionality of TRIANGLE class variables.
    unit_test_0(std::cout);
    unit_test_0(file);
    unit_test_1(std::cout);
    unit_test_1(file);
    unit_test_2(std::cout);
    unit_test_2(file);
    unit_test_3(std::cout);
    unit_test_3(file);
    unit_test_4(std::cout);
    unit_test_4(file);

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}
