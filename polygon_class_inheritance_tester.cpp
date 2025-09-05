/**
 * file: polygon_class_inheritance_tester.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include "polygon.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the POLYGON class.
#include "quadrilateral.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the QUADRILATERAL class.
#include "trapezoid.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRAPEZOID class.
#include "rectangle.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the RECTANGLE class.
#include "square.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the SQUARE class.
#include "trilateral.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the TRILATERAL class.
#include "right_trilateral.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the RIGHT_TRILATERAL class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);
void unit_test_3(std::ostream & output);
void unit_test_4(std::ostream & output);
void unit_test_5(std::ostream & output);
void unit_test_6(std::ostream & output);
void unit_test_7(std::ostream & output);
void unit_test_8(std::ostream & output);
void unit_test_9(std::ostream & output);
void unit_test_10(std::ostream & output);
void unit_test_11(std::ostream & output);
void unit_test_12(std::ostream & output);
void unit_test_13(std::ostream & output);
void unit_test_14(std::ostream & output);
void unit_test_15(std::ostream & output);
void unit_test_16(std::ostream & output);
void unit_test_17(std::ostream & output);
void unit_test_18(std::ostream & output);
void unit_test_19(std::ostream & output);
void unit_test_20(std::ostream & output);
void unit_test_21(std::ostream & output);
void unit_test_22(std::ostream & output);
void unit_test_23(std::ostream & output);
void unit_test_24(std::ostream & output);
void unit_test_25(std::ostream & output);
void unit_test_26(std::ostream & output);
void unit_test_27(std::ostream & output);
void unit_test_28(std::ostream & output);
void unit_test_29(std::ostream & output);

/**
 * Unit Test # 0: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 0: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
    output << "\npointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.
    pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    output << "\npointer_to_polygon -> get_area() = " << pointer_to_polygon -> get_area() << ". // Indirectly call the POLYGON get_area() method.";
    output << "\npointer_to_polygon -> get_perimeter() = " << pointer_to_polygon -> get_perimeter() << ". // Indirectly call the POLYGON get_permieter() method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.
}

/**
 * Unit Test # 1: Test the default QUADRILATERAL constructor and the QUADRILATERAL print method.
 */
void unit_test_1(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 1: Test the default QUADRILATERAL constructor and the QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL quadrilateral;";
    output << "\nquadrilateral.print(); // Test the default argument (which is std::cout).";
    output << "\nquadrilateral.print(output);";
    output << "\noutput << quadrilateral; // overloaded ostream operator as defined in quadrilateral.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL quadrilateral;
    quadrilateral.print(); // Test the default argument (which is std::cout).
    quadrilateral.print(output);
    output << quadrilateral; // overloaded ostream operator as defined in quadrilateral.cpp
}

/** 
 * Unit Test # 2: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-POLYGON to call the overloaded ostream operator method of the POLYGON class (and not of the QUADRILATERAL class).
 */
void unit_test_2(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 2: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-POLYGON to call the overloaded ostream operator method of the POLYGON class (and not of the QUADRILATERAL class).";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.";
    output << "\npointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\noutput << * pointer_to_polygon; // Use the overloaded ostream operator as defined in polygon.cpp to print the data which is stored at the memory address which pointer_to_polygon stores.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    POLYGON * pointer_to_polygon; // The pointer-to-polygon type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as QUADRILATERAL.
    pointer_to_polygon = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    output << * pointer_to_polygon; // Use the overloaded ostream operator as defined in polygon.cpp to print the data which is stored at the memory address which pointer_to_polygon stores.
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.
}

/** 
 * Unit Test # 3: Unit Test # 3: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. 
 * Use that pointer-to-QUADRILATERAL to call the overloaded ostream operator method of the QUADRILATERAL class and the public getter methods of the QUADRILATERAL class.
 */
void unit_test_3(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 3: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated QUADRILATERAL instance. Use that pointer-to-QUADRILATERAL to call the overloaded ostream operator method of the QUADRILATERAL class and the public getter methods of the QUADRILATERAL class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is QUADRILATERAL or else a non-abstract derived class of QUADRILATERAL such as TRAPEZOID.";
    output << "\npointer_to_quadrilateral = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\noutput << * pointer_to_quadrilateral; // Use the overloaded ostream operator as defined in quadrilateral.cpp to print the data which is stored at the memory address which pointer_to_quadrilateral stores.";
    output << "\ndelete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRATERAL type variable can store the memory address of an object whose data type is QUADRILATERAL or else a non-abstract derived class of QUADRILATERAL such as TRAPEZOID.
    pointer_to_quadrilateral = new QUADRILATERAL; // Assign memory to a dynamic QUADRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    output << * pointer_to_quadrilateral; // Use the overloaded ostream operator as defined in quadrilateral.cpp to print the data which is stored at the memory address which pointer_to_quadrilateral stores.
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\npointer_to_quadrilateral -> get_area() = " << pointer_to_quadrilateral -> get_area() << ". // Indirectly call the get_area() method of the QUADRILATERAL class.";
    output << "\npointer_to_quadrilateral -> get_perimeter() = " << pointer_to_quadrilateral -> get_perimeter() << ". // Indirectly call the get_perimeter() method of the QUADRILATERAL class.";
    delete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated QUADRILATERAL instance.
}

/**
 * Unit Test # 4: Test the normal QUADRILATERAL constructor and QUADRILATERAL copy constructor using valid function inputs and the QUADRILATERAL print method.
 */
void unit_test_4(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 4: Test the normal QUADRILATERAL constructor and QUADRILATERAL copy constructor using valid function inputs and the QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL quadrilateral_0 = QUADRILATERAL(\"green\", POINT(-2,-2), POINT(-2,2), POINT(2,2), POINT(2,-2));";
    output << "\nquadrilateral_0.print(output);";
    output << "\nQUADRILATERAL quadrilateral_1 = QUADRILATERAL(\"blue\", POINT(0,0), POINT(3,2), POINT(5,1), POINT(-1,-2));";
    output << "\nquadrilateral_1.print(output);";
    output << "\nQUADRILATERAL quadrilateral_2 = QUADRILATERAL(quadrilateral_0);";
    output << "\nquadrilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL quadrilateral_0 = QUADRILATERAL("green", POINT(-2,-2), POINT(-2,2), POINT(2,2), POINT(2,-2));
    quadrilateral_0.print(output);
    QUADRILATERAL quadrilateral_1 = QUADRILATERAL("blue", POINT(0,0), POINT(3,2), POINT(5,1), POINT(-1,-2));
    quadrilateral_1.print(output);
    QUADRILATERAL quadrilateral_2 = QUADRILATERAL(quadrilateral_0);
    quadrilateral_2.print(output);
}

/**
 * Unit Test # 5: Test the normal QUADRILATERAL constructor using invalid function inputs and the QUADRILATERAL print method.
 */
void unit_test_5(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 5: Test the normal QUADRILATERAL constructor using invalid function inputs and the QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL quadrilateral_0 = QUADRILATERAL(\"red\", POINT(-2,-2), POINT(0,0), POINT(1,1), POINT(2,2)); // A line intersects all four points.";
    output << "\nquadrilateral_0.print(output);";
    output << "\nQUADRILATERAL quadrilateral_1 = QUADRILATERAL(\"purple\", POINT(0,0), POINT(3,2), POINT(0,0), POINT(-1,-2)); // Not all point coordinate pairs are unique.";
    output << "\nquadrilateral_1.print(output);";
    output << "\nQUADRILATERAL quadrilateral_2 = QUADRILATERAL(\"yellow\", POINT(0,0), POINT(0,2), POINT(4,0), POINT(4,2)); // The points form a bow-tie shaped polygon.";
    output << "\nquadrilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL quadrilateral_0 = QUADRILATERAL("red", POINT(-2,-2), POINT(0,0), POINT(1,1), POINT(2,2)); // A line intersects all four points.
    quadrilateral_0.print(output);
    QUADRILATERAL quadrilateral_1 = QUADRILATERAL("purple", POINT(0,0), POINT(3,2), POINT(0,0), POINT(-1,-2)); // Not all point coordinate pairs are unique.
    quadrilateral_1.print(output);
    QUADRILATERAL quadrilateral_2 = QUADRILATERAL("yellow", POINT(0,0), POINT(0,2), POINT(4,0), POINT(4,2)); // The points form a bow-tie shaped polygon.
    quadrilateral_2.print(output);
}

/**
 * Unit Test # 6: Test the default TRAPEZOID constructor and the TRAPEZOID print method.
 */
void unit_test_6(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 6: Test the default TRAPEZOID constructor and the TRAPEZOID print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRAPEZOID trapezoid;";
    output << "\ntrapezoid.print(); // Test the default argument (which is std::cout).";
    output << "\ntrapezoid.print(output);";
    output << "\noutput << trapezoid; // overloaded ostream operator as defined in trapezoid.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    TRAPEZOID trapezoid;
    trapezoid.print(); // Test the default argument (which is std::cout).
    trapezoid.print(output);
    output << trapezoid; // overloaded ostream operator as defined in trapezoid.cpp
}

/**
 * Unit Test # 7: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated TRAPEZOID instance. 
 * Use that pointer-to-POLYGON type variable to call the POLYGON print method and the POLYGON getter methods.
 */
void unit_test_7(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 7: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated TRAPEZOID instance. Use that pointer-to-POLYGON type variable to call the POLYGON print method and the POLYGON getter methods.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as TRAPEZOID.";
    output << "\npointer_to_polygon = new TRAPEZOID; // Assign memory to a dynamic TRAPEZOID instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as TRAPEZOID.
    pointer_to_polygon = new TRAPEZOID; // Assign memory to a dynamic TRAPEZOID instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    output << "\npointer_to_polygon -> get_area() = " << pointer_to_polygon -> get_area() << ". // Indirectly call the POLYGON get_area() method.";
    output << "\npointer_to_polygon -> get_perimeter() = " << pointer_to_polygon -> get_perimeter() << ". // Indirectly call the POLYGON get_permieter() method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.
}

/**
 * Unit Test # 8: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated TRAPEZOID instance. 
 * Use that pointer-to-QUADRILATERAL type variable to call the QUADRILATERAL print method.
 */
void unit_test_8(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 8: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated TRAPEZOID instance. Use that pointer-to-QUADRILATERAL type variable to call the QUADRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of QUADRILATERAL such as TRAPEZOID.";
    output << "\npointer_to_quadrilateral = new TRAPEZOID; // Assign memory to a dynamic TRAPEZOID instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_quadrilateral -> print(output); // Indirectly call the QUADRILATERAL print method.";
    output << "\ndelete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    QUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of QUADRILATERAL such as TRAPEZOID.
    pointer_to_quadrilateral = new TRAPEZOID; // Assign memory to a dynamic TRAPEZOID instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_quadrilateral -> print(output); // Indirectly call the QUADRILATERAL print method.
    delete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.
}

/**
 * Unit Test # 9: Test the normal TRAPEZOID constructor and TRAPEZOID copy constructor using valid function inputs and the TRAPEZOID print method.
 */
void unit_test_9(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 9: Test the normal TRAPEZOID constructor and TRAPEZOID copy constructor using valid function inputs and the TRAPEZOID print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRAPEZOID trapezoid_0 = TRAPEZOID(\"pink\", POINT(-5,-10), POINT(0,5), POINT(15,5), POINT(30,-10));";
    output << "\ntrapezoid_0.print(output);";
    output << "\nTRAPEZOID trapezoid_1 = TRAPEZOID(\"brown\", POINT(0,0), POINT(4,-5), POINT(15,-5), POINT(45,0));";
    output << "\ntrapezoid_1.print(output);";
    output << "\nTRAPEZOID trapezoid_2 = TRAPEZOID(trapezoid_0);";
    output << "\ntrapezoid_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    TRAPEZOID trapezoid_0 = TRAPEZOID("pink", POINT(-5,-10), POINT(0,5), POINT(15,5), POINT(30,-10));
    trapezoid_0.print(output);
    TRAPEZOID trapezoid_1 = TRAPEZOID("brown", POINT(0,0), POINT(4,-5), POINT(15,-5), POINT(45,0));
    trapezoid_1.print(output);
    TRAPEZOID trapezoid_2 = TRAPEZOID(trapezoid_0);
    trapezoid_2.print(output);
}

/**
 * Unit Test # 10: Test the default RECTANGLE constructor and the RECTANGLE print method.
 */
void unit_test_10(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 10: Test the default RECTANGLE constructor and the RECTANGLE print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRECTANGLE rectangle;";
    output << "\nrectangle.print(); // Test the default argument (which is std::cout).";
    output << "\nrectangle.print(output);";
    output << "\noutput << rectangle; // overloaded ostream operator as defined in rectangle.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    RECTANGLE rectangle;
    rectangle.print(); // Test the default argument (which is std::cout).
    rectangle.print(output);
    output << rectangle; // overloaded ostream operator as defined in rectangle.cpp
}

/**
 * Unit Test # 11: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated RECTANGLE instance. 
 * Use that pointer-to-POLYGON type variable to call the POLYGON print method and the POLYGON getter methods.
 */
void unit_test_11(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 11: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated RECTANGLE instance. Use that pointer-to-POLYGON type variable to call the POLYGON print method and the POLYGON getter methods.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as RECTANGLE.";
    output << "\npointer_to_polygon = new RECTANGLE; // Assign memory to a dynamic RECTANGLE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as RECTANGLE.
    pointer_to_polygon = new RECTANGLE; // Assign memory to a dynamic RECTANGLE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    output << "\n// COMMENTED OUT (does not work): pointer_to_polygon -> quadrilateral_test(). // Indirectly call the QUADRILATERAL quadrilateral_test() method.";
    output << "\npointer_to_polygon -> get_area() = " << pointer_to_polygon -> get_area() << ". // Indirectly call the POLYGON get_area() method.";
    output << "\npointer_to_polygon -> get_perimeter() = " << pointer_to_polygon -> get_perimeter() << ". // Indirectly call the POLYGON get_permieter() method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated RECTANGLE instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRAPEZOID instance.
}

/**
 * Unit Test # 12: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated RECTANGLE instance. 
 * Use that pointer-to-QUADRILATERAL type variable to call the QUADRILATERAL print method and the QUADRILATERAL getter methods.
 */
void unit_test_12(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 12: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated RECTANGLE instance. Use that pointer-to-QUADRILATERAL type variable to call the POLYGON print method and the QUADRILATERAL getter methods.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of QUADRILATERAL such as RECTANGLE.";
    output << "\npointer_to_quadrilateral = new RECTANGLE; // Assign memory to a dynamic RECTANGLE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_quadrilateral -> print(output); // Indirectly call the QUADRILATERAL print method.";
    QUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of QUADRILATERAL such as RECTANGLE.
    pointer_to_quadrilateral = new RECTANGLE; // Assign memory to a dynamic RECTANGLE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_quadrilateral -> print(output); // Indirectly call the POLYGON print method.
    output << "\n// COMMENTED OUT (does not work): pointer_to_quadrilateral -> rectangle_test(); // Indirectly call the RECTANGLE rectangle_test() method.";
    output << "\npointer_to_quadrilateral -> get_area() = " << pointer_to_quadrilateral -> get_area() << ". // Indirectly call the QUADRILATERAL get_area() method.";
    output << "\npointer_to_quadrilateral -> get_perimeter() = " << pointer_to_quadrilateral -> get_perimeter() << ". // Indirectly call the QUADRILATERAL get_permieter() method.";
    output << "\ndelete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated RECTANGLE instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated RECTANGLE instance.
}

/**
 * Unit Test # 13: Test the normal RECTANGLE constructor and RECTANGLE copy constructor using valid function inputs and the RECTANGLE print method.
 */
void unit_test_13(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 13: Test the normal RECTANGLE constructor and RECTANGLE copy constructor using valid function inputs and the RECTANGLE print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRECTANGLE rectangle_0 = RECTANGLE(\"gray\", POINT(9,10), POINT(9,5), POINT(3,5), POINT(3,10));";
    output << "\nrectangle_0.print(output);";
    output << "\nRECTANGLE rectangle_1 = RECTANGLE(\"black\", POINT(0,0), POINT(0,1), POINT(1,1), POINT(1,0));";
    output << "\nrectangle_1.print(output);";
    output << "\nRECTANGLE rectangle_2 = RECTANGLE(rectangle_0);";
    output << "\nrectangle_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    RECTANGLE rectangle_0 = RECTANGLE("gray", POINT(9,10), POINT(9,5), POINT(3,5), POINT(3,10));
    rectangle_0.print(output);
    RECTANGLE rectangle_1 = RECTANGLE("black", POINT(0,0), POINT(0,1), POINT(1,1), POINT(1,0));
    rectangle_1.print(output);
    RECTANGLE rectangle_2 = RECTANGLE(rectangle_0);
    rectangle_2.print(output);
}

/**
 * Unit Test # 14: Test the normal RECTANGLE constructor using invalid function inputs and the RECTANGLE print method.
 */
void unit_test_14(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 14: Test the normal RECTANGLE constructor using invalid function inputs and the RECTANGLE print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRECTANGLE rectangle_0 = RECTANGLE(\"red\", POINT(-1,-1), POINT(0,0), POINT(1,1), POINT(2,2));";
    output << "\nrectangle_0.print(output);";
    output << "\nRECTANGLE rectangle_1 = RECTANGLE(\"green\", POINT(-5,-10), POINT(0,5), POINT(15,5), POINT(30,-10));";
    output << "\nrectangle_1.print(output);";
    output << "\nRECTANGLE rectangle_2 = RECTANGLE(\"blue\", POINT(-5,-5), POINT(0,0), POINT(-5,-5), POINT(0,0));";
    output << "\nrectangle_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    RECTANGLE rectangle_0 = RECTANGLE("red", POINT(-1,-1), POINT(0,0), POINT(1,1), POINT(2,2));
    rectangle_0.print(output);
    RECTANGLE rectangle_1 = RECTANGLE("green", POINT(-5,-10), POINT(0,5), POINT(15,5), POINT(30,-10));
    rectangle_1.print(output);
    RECTANGLE rectangle_2 = RECTANGLE("blue", POINT(-5,-5), POINT(0,0), POINT(-5,-5), POINT(0,0));
    rectangle_2.print(output);
}

/**
 * Unit Test # 15: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated SQUARE instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.
 */
void unit_test_15(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 15: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated SQUARE instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as SQUARE.";
    output << "\npointer_to_polygon = new SQUARE; // Assign memory to a dynamic SQUARE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as SQUARE.
    pointer_to_polygon = new SQUARE; // Assign memory to a dynamic SQUARE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    output << "\npointer_to_polygon -> get_area() = " << pointer_to_polygon -> get_area() << ". // Indirectly call the POLYGON get_area() method.";
    output << "\npointer_to_polygon -> get_perimeter() = " << pointer_to_polygon -> get_perimeter() << ". // Indirectly call the POLYGON get_permieter() method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated SQUARE instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated SQUARE instance.
}

/**
 * Unit Test # 16: Test the default SQUARE constructor and the SQUARE print method.
 */
void unit_test_16(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 16: Test the default SQUARE constructor and the SQUARE print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nSQUARE square;";
    output << "\nsquare.print(); // Test the default argument (which is std::cout).";
    output << "\nsquare.print(output);";
    output << "\noutput << square; // overloaded ostream operator as defined in square.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    SQUARE square;
    square.print(); // Test the default argument (which is std::cout).
    square.print(output);
    output << square; // overloaded ostream operator as defined in square.cpp
}

/**
 * Unit Test # 17: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated SQUARE instance. 
 * Use that pointer-to-QUADRILATERAL type variable to call the QUADRILATERAL print method and the QUADRILATERAL getter methods.
 */
void unit_test_17(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 17: Create a pointer-to-QUADRILATERAL type variable to store the memory address of a dynamically allocated SQUARE instance. Use that pointer-to-QUADRILATERAL type variable to call the QUADRILATERAL print method and the QUADRILATERAL getter methods.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nQUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of QUADRILATERAL such as SQUARE.";
    output << "\npointer_to_quadrilateral = new SQUARE; // Assign memory to a dynamic SQUARE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_quadrilateral -> print(output); // Indirectly call the QUADRILATERAL print method.";
    QUADRILATERAL * pointer_to_quadrilateral; // The pointer-to-QUADRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of QUADRILATERAL such as SQUARE.
    pointer_to_quadrilateral = new SQUARE; // Assign memory to a dynamic SQUARE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_quadrilateral -> print(output); // Indirectly call the POLYGON print method.
    output << "\npointer_to_quadrilateral -> get_area() = " << pointer_to_quadrilateral -> get_area() << ". // Indirectly call the QUADRILATERAL get_area() method.";
    output << "\npointer_to_quadrilateral -> get_perimeter() = " << pointer_to_quadrilateral -> get_perimeter() << ". // Indirectly call the QUADRILATERAL get_permieter() method.";
    output << "\ndelete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated SQUARE instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_quadrilateral; // De-allocate memory which was assigned to the dynamically allocated SQUARE instance.
}

/**
 * Unit Test # 18: Create a pointer-to-RECTANGLE type variable to store the memory address of a dynamically allocated SQUARE instance. 
 * Use that pointer-to-RECTANGLE type variable to call the RECTANGLE print method and the RECTANGLE getter methods.
 */
void unit_test_18(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 18: Create a pointer-to-RECTANGLE type variable to store the memory address of a dynamically allocated SQUARE instance. Use that pointer-to-RECTANGLE type variable to call the RECTANGLE print method and the RECTANGLE getter methods.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRECTANGLE * pointer_to_rectangle; // The pointer-to-RECTANGLE type variable can store the memory address of an object whose data type is a non-abstract derived class of RECTANGLE such as SQUARE.";
    output << "\npointer_to_rectangle = new SQUARE; // Assign memory to a dynamic SQUARE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_rectangle -> print(output); // Indirectly call the RECTANGLE print method.";
    RECTANGLE * pointer_to_rectangle; // The pointer-to-RECTANGLE type variable can store the memory address of an object whose data type is a non-abstract derived class of RECTANGLE such as SQUARE.
    pointer_to_rectangle = new SQUARE; // Assign memory to a dynamic SQUARE instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_rectangle -> print(output); // Indirectly call the RECTANGLE print method.
    output << "\npointer_to_rectangle -> get_area() = " << pointer_to_rectangle -> get_area() << ". // Indirectly call the RECTANGLE get_area() method.";
    output << "\npointer_to_rectangle -> get_perimeter() = " << pointer_to_rectangle -> get_perimeter() << ". // Indirectly call the RECTANGLE get_permieter() method.";
    output << "\ndelete pointer_to_rectangle; // De-allocate memory which was assigned to the dynamically allocated SQUARE instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_rectangle; // De-allocate memory which was assigned to the dynamically allocated SQUARE instance.
}

/**
 * Unit Test # 19: Test the normal SQUARE constructor and SQUARE copy constructor using valid function inputs and the SQUARE print method.
 */
void unit_test_19(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 19: Test the normal SQUARE constructor and SQUARE copy constructor using valid function inputs and the SQUARE print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nSQUARE square_0 = SQUARE(\"yellow\", POINT(-3,-3), POINT(-3,0), POINT(0,0), POINT(0,-3));";
    output << "\nsquare_0.print(output);";
    output << "\nSQUARE square_1 = SQUARE(\"white\", POINT(-1,-1), POINT(-1,1), POINT(1,1), POINT(1,-1));";
    output << "\nsquare_1.print(output);";
    output << "\nSQUARE square_2 = SQUARE(square_0);";
    output << "\nsquare_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    SQUARE square_0 = SQUARE("yellow", POINT(-3,-3), POINT(-3,0), POINT(0,0), POINT(0,-3));
    square_0.print(output);
    SQUARE square_1 = SQUARE("white", POINT(-1,-1), POINT(-1,1), POINT(1,1), POINT(1,-1));
    square_1.print(output);
    SQUARE square_2 = SQUARE(square_0);
    square_2.print(output);
}

/**
 * Unit Test # 20: Test the normal SQUARE constructor using invalid function inputs and the SQUARE print method.
 */
void unit_test_20(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 20: Test the normal SQUARE constructor using invalid function inputs and the SQUARE print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nSQUARE square_0 = SQUARE(\"red\", POINT(0,0), POINT(0,1), POINT(0,2), POINT(0,3));";
    output << "\nsquare_0.print(output);";
    output << "\nSQUARE square_1 = SQUARE(\"green\", POINT(0,0), POINT(0,1), POINT(5,1), POINT(5,0));";
    output << "\nsquare_1.print(output);";
    output << "\nSQUARE square_2 = SQUARE(\"blue\", POINT(0,0), POINT(0,1), POINT(1,1), POINT(0,0));";
    output << "\nsquare_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    SQUARE square_0 = SQUARE("red", POINT(0,0), POINT(0,1), POINT(0,2), POINT(0,3));
    square_0.print(output);
    SQUARE square_1 = SQUARE("green", POINT(0,0), POINT(0,1), POINT(5,1), POINT(5,0));
    square_1.print(output);
    SQUARE square_2 = SQUARE("blue", POINT(0,0), POINT(0,1), POINT(1,1), POINT(0,0));
    square_2.print(output);
}

/**
 * Unit Test # 21: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated TRILATERAL instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.
 */
void unit_test_21(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 21: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated TRILATERAL instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as TRILATERAL.";
    output << "\npointer_to_polygon = new TRILATERAL; // Assign memory to a dynamic TRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as SQUARE.
    pointer_to_polygon = new TRILATERAL; // Assign memory to a dynamic TRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    output << "\npointer_to_polygon -> get_area() = " << pointer_to_polygon -> get_area() << ". // Indirectly call the POLYGON get_area() method.";
    output << "\npointer_to_polygon -> get_perimeter() = " << pointer_to_polygon -> get_perimeter() << ". // Indirectly call the POLYGON get_permieter() method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated TRILATERAL instance.
}

/**
 * Unit Test # 22: Test the default TRILATERAL constructor and the TRILATERAL print method.
 */
void unit_test_22(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 22: Test the default TRILATERAL constructor and the TRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRILATERAL trilateral;";
    output << "\ntrilateral.print(); // Test the default argument (which is std::cout).";
    output << "\ntrilateral.print(output);";
    output << "\noutput << trilateral; // overloaded ostream operator as defined in trilateral.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    TRILATERAL trilateral;
    trilateral.print(); // Test the default argument (which is std::cout).
    trilateral.print(output);
    output << trilateral; // overloaded ostream operator as defined in trilateral.cpp
}

/**
 * Unit Test # 23: Test the normal TRILATERAL constructor and TRILATERAL copy constructor using valid function inputs and the TRILATERAL print method.
 */
void unit_test_23(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 23: Test the normal TRILATERAL constructor and TRILATREAL copy constructor using valid function inputs and the TRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRILATERAL trilateral_0 = TRILATERAL(\"purple\", POINT(0,0), POINT(10,0), POINT(10,-10));";
    output << "\ntrilateral_0.print(output);";
    output << "\nTRILATERAL trilateral_1 = TRILATERAL(\"green\", POINT(-1,-1), POINT(4,4), POINT(7,-18);";
    output << "\ntrilateral_1.print(output);";
    output << "\nTRILATERAL trilateral_2 = TRILATERAL(trilateral_0);";
    output << "\ntrilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    TRILATERAL trilateral_0 = TRILATERAL("purple", POINT(0,0), POINT(10,0), POINT(10,-10));
    trilateral_0.print(output);
    TRILATERAL trilateral_1 = TRILATERAL("green", POINT(-1,-1), POINT(4,4), POINT(7,-18));
    trilateral_1.print(output);
    TRILATERAL trilateral_2 = TRILATERAL(trilateral_0);
    trilateral_2.print(output);
}

/**
 * Unit Test # 24: Test the normal SQUARE constructor using invalid function inputs and the SQUARE print method.
 */
void unit_test_24(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 24: Test the normal TRILATERAL constructor using invalid function inputs and the TRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRILATERAL trilateral_0 = TRILATERAL(\"red\", POINT(-1,-1), POINT(0,0), POINT(1,1));";
    output << "\ntrilateral_0.print(output);";
    output << "\nTRILATERAL trilateral_1 = TRILATERAL(\"green\", POINT(5,0), POINT(5,1), POINT(5,0));";
    output << "\ntrilateral_1.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    TRILATERAL trilateral_0 = TRILATERAL("red", POINT(-1,-1), POINT(0,0), POINT(1,1));
    trilateral_0.print(output);
    TRILATERAL trilateral_1 = TRILATERAL("green", POINT(5,0), POINT(5,1), POINT(5,0));
    trilateral_1.print(output);
}

/**
 * Unit Test # 25: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated RIGHT_TRILATERAL instance. 
 * Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.
 */
void unit_test_25(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 25: Create a pointer-to-POLYGON type variable to store the memory address of a dynamically allocated RIGHT_TRILATERAL instance. Use that pointer-to-POLYGON type variable to call the print method of the POLYGON class and the getter methods of the POLYGON class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\n// COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.";
    output << "\nPOLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as RIGHT_TRILATERAL.";
    output << "\npointer_to_polygon = new RIGHT_TRILATERAL; // Assign memory to a dynamic RIGHT_TRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.";
    // COMMENTED OUT: POLYGON polygon; // This command does not work because POLYGON is an abstract class.
    POLYGON * pointer_to_polygon; // The pointer-to-POLYGON type variable can store the memory address of an object whose data type is a non-abstract derived class of POLYGON such as RIGHT_TRILATERAL.
    pointer_to_polygon = new RIGHT_TRILATERAL; // Assign memory to a dynamic RIGHT_TRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_polygon -> print(output); // Indirectly call the POLYGON print method.
    output << "\npointer_to_polygon -> get_area() = " << pointer_to_polygon -> get_area() << ". // Indirectly call the POLYGON get_area() method.";
    output << "\npointer_to_polygon -> get_perimeter() = " << pointer_to_polygon -> get_perimeter() << ". // Indirectly call the POLYGON get_permieter() method.";
    output << "\ndelete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated RIGHT_TRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_polygon; // De-allocate memory which was assigned to the dynamically allocated RIGHT_TRILATERAL instance.
}

/**
 * Unit Test # 26: Create a pointer-to-TRILATERAL type variable to store the memory address of a dynamically allocated RIGHT_TRILATERAL instance. 
 * Use that pointer-to-TRILATERAL type variable to call the print method of the TRILATERAL class and the getter methods of the TRILATERAL class.
 */
void unit_test_26(std::ostream & output) 
{
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 25: Create a pointer-to-TRILATERAL type variable to store the memory address of a dynamically allocated RIGHT_TRILATERAL instance. Use that pointer-to-TRILATERAL type variable to call the print method of the TRILATERAL class and the getter methods of the TRILATERAL class.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nTRILATERAL * pointer_to_trilateral; // The pointer-to-TRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of TRILATERAL such as RIGHT_TRILATERAL.";
    output << "\npointer_to_trilateral = new RIGHT_TRILATERAL; // Assign memory to a dynamic RIGHT_TRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).";
    output << "\npointer_to_trilateral -> print(output); // Indirectly call the TRILATERAL print method.";

    TRILATERAL * pointer_to_trilateral; // The pointer-to-TRILATERAL type variable can store the memory address of an object whose data type is a non-abstract derived class of TRILATERAL such as RIGHT_TRILATERAL.
    pointer_to_trilateral = new RIGHT_TRILATERAL; // Assign memory to a dynamic RIGHT_TRILATERAL instance (i.e. and dynamic implies that the variable was created during program runtime instead of program compile time).
    pointer_to_trilateral -> print(output); // Indirectly call the TRILATERAL print method.
    output << "\npointer_to_trilateral -> get_area() = " << pointer_to_trilateral -> get_area() << ". // Indirectly call the TRILATERAL get_area() method.";
    output << "\npointer_to_trilateral -> get_perimeter() = " << pointer_to_trilateral -> get_perimeter() << ". // Indirectly call the TRILATERAL get_permieter() method.";
    output << "\ndelete pointer_to_trilateral; // De-allocate memory which was assigned to the dynamically allocated RIGHT_TRILATERAL instance.";
    output << "\n--------------------------------------------------------------------------------------------------";
    delete pointer_to_trilateral; // De-allocate memory which was assigned to the dynamically allocated RIGHT_TRILATERAL instance.
}

/**
 * Unit Test # 27: Test the default TRILATERAL constructor and the TRILATERAL print method.
 */
void unit_test_27(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 27: Test the default RIGHT_TRILATERAL constructor and the RIGHT_TRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRIGHT_TRILATERAL right_trilateral;";
    output << "\nright_trilateral.print(); // Test the default argument (which is std::cout).";
    output << "\nright_trilateral.print(output);";
    output << "\noutput << right_trilateral; // overloaded ostream operator as defined in right_trilateral.cpp";
    output << "\n--------------------------------------------------------------------------------------------------";
    RIGHT_TRILATERAL right_trilateral;
    right_trilateral.print(); // Test the default argument (which is std::cout).
    right_trilateral.print(output);
    output << right_trilateral; // overloaded ostream operator as defined in right_trilateral.cpp
}

/**
 * Unit Test # 28: Test the normal RIGHT_TRILATERAL constructor and RIGHT_TRILATERAL copy constructor using valid function inputs and the RIGHT_TRILATERAL print method.
 */
void unit_test_28(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 28: Test the normal RIGHT_TRILATERAL constructor and RIGHT_TRILATERAL copy constructor using valid function inputs and the RIGHT_TRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRIGHT_TRILATERAL right_trilateral_0 = RIGHT_TRILATERAL(\"purple\", POINT(0,0), POINT(0,100), POINT(100,0));";
    output << "\nright_trilateral_0.print(output);";
    output << "\nRIGHT_TRILATERAL right_trilateral_1 = RIGHT_TRILATERAL(\"green\", POINT(-3,0), POINT(0,-4), POINT(0,0);";
    output << "\nright_trilateral_1.print(output);";
    output << "\nRIGHT_TRILATERAL right_trilateral_2 = RIGHT_TRILATERAL(right_trilateral_0);";
    output << "\nright_trilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    RIGHT_TRILATERAL right_trilateral_0 = RIGHT_TRILATERAL("purple", POINT(0,0), POINT(0,100), POINT(100,0));
    right_trilateral_0.print(output);
    RIGHT_TRILATERAL right_trilateral_1 = RIGHT_TRILATERAL("green", POINT(-3,0), POINT(0,-4), POINT(0,0));
    right_trilateral_1.print(output);
    RIGHT_TRILATERAL right_trilateral_2 = RIGHT_TRILATERAL(right_trilateral_0);
    right_trilateral_2.print(output);
}

/**
 * Unit Test # 29: Test the normal RIGHT_TRILATERAL constructor using invalid function inputs and the RIGHT_TRILATERAL print method.
 */
void unit_test_29(std::ostream & output)
{
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nUnit Test # 29: Test the normal RIGHT_TRILATERAL constructor using invalid function inputs and the RIGHT_TRILATERAL print method.";
    output << "\n--------------------------------------------------------------------------------------------------";
    output << "\nRIGHT_TRILATERAL right_trilateral_0 = RIGHT_TRILATERAL(\"red\", POINT(-2,-2), POINT(0,0), POINT(4,4));";
    output << "\nright_trilateral_0.print(output);";
    output << "\nRIGHT_TRILATERAL right_trilateral_1 = RIGHT_TRILATERAL(\"green\", POINT(0,0), POINT(4,5), POINT(9,-3));";
    output << "\nright_trilateral_1.print(output);";
    output << "\nRIGHT_TRILATERAL right_trilateral_2 = RIGHT_TRILATERAL(\"blue\", POINT(0,0), POINT(4,5), POINT(0,0));";
    output << "\nright_trilateral_2.print(output);";
    output << "\n--------------------------------------------------------------------------------------------------";
    RIGHT_TRILATERAL right_trilateral_0 = RIGHT_TRILATERAL("red", POINT(-2,-2), POINT(0,0), POINT(4,4));
    right_trilateral_0.print(output);
    RIGHT_TRILATERAL right_trilateral_1 = RIGHT_TRILATERAL("green", POINT(0,0), POINT(4,5), POINT(9,-3));
    right_trilateral_1.print(output);
    RIGHT_TRILATERAL right_trilateral_2 = RIGHT_TRILATERAL("blue", POINT(0,0), POINT(4,5), POINT(0,0));
    right_trilateral_2.print(output);
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
     * If polygon_class_inheritance_tester_output.txt does not already exist in the same directory as polygon_class_inheritance_tester.cpp, 
     * create a new file named polygon_class_inheritance_tester_output.txt.
     * 
     * Open the plain-text file named polygon_class_inheritance_tester_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("polygon_class_inheritance_tester_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Implement a series of unit tests which demonstrate the functionality of POLYGON class variables.
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
    unit_test_5(std::cout);
    unit_test_5(file);
    unit_test_6(std::cout);
    unit_test_6(file);
    unit_test_7(std::cout);
    unit_test_7(file);
    unit_test_8(std::cout);
    unit_test_8(file);
    unit_test_9(std::cout);
    unit_test_9(file);
    unit_test_10(std::cout);
    unit_test_10(file);
    unit_test_11(std::cout);
    unit_test_11(file);
    unit_test_12(std::cout);
    unit_test_12(file);
    unit_test_13(std::cout);
    unit_test_13(file);
    unit_test_14(std::cout);
    unit_test_14(file);
    unit_test_15(std::cout);
    unit_test_15(file);
    unit_test_16(std::cout);
    unit_test_16(file);
    unit_test_17(std::cout);
    unit_test_17(file);
    unit_test_18(std::cout);
    unit_test_18(file);
    unit_test_19(std::cout);
    unit_test_19(file);
    unit_test_20(std::cout);
    unit_test_20(file);
    unit_test_21(std::cout);
    unit_test_21(file);
    unit_test_22(std::cout);
    unit_test_22(file);
    unit_test_23(std::cout);
    unit_test_23(file);
    unit_test_24(std::cout);
    unit_test_24(file);
    unit_test_25(std::cout);
    unit_test_25(file);
    unit_test_26(std::cout);
    unit_test_26(file);
    unit_test_27(std::cout);
    unit_test_27(file);
    unit_test_28(std::cout);
    unit_test_28(file);
    unit_test_29(std::cout);
    unit_test_29(file);

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
