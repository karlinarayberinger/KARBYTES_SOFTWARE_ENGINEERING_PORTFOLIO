/**
 * file: linked_list_driver.cpp
 * type: C++ (source file)
 * date: 07_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include "linked_list.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the LINKED_LIST class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);
void unit_test_3(std::ostream & output);
void unit_test_4(std::ostream & output);

/**
 * Unit Test # 0: LINKED_LIST constructor, print method, and destructor.
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 0: LINKED_LIST constructor, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nlinked_list.print(output);";
    LINKED_LIST linked_list;
    linked_list.print(output);
}

/**
 * Unit Test # 1: LINKED_LIST constructor, insert method, print method, and destructor.
 */
void unit_test_1(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 1: LINKED_LIST constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nNODE node;";
    output << "\nnode.key = \"unit_test_1\";";
    output << "\nnode.next = NULL;";
    output << "\nlinked_list.insert_node_at_end_of_list(&node);";
    output << "\nlinked_list.print(output);";
    LINKED_LIST linked_list;
    NODE node;
    node.key = "unit_test_1";
    node.next = NULL;
    linked_list.insert_node_at_end_of_list(&node);
    linked_list.print(output);
}

/**
 * Unit Test # 2: LINKED_LIST constructor, insert method, print method, and destructor.
 */
void unit_test_2(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 2: LINKED_LIST constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nNODE node_A = { key : \"node_A\", next : NULL };";
    output << "\nNODE node_B = { key : \"node_B\", next : NULL };";
    output << "\nNODE node_C = { key : \"node_C\", next : NULL };";
    output << "\nlinked_list.insert_node_at_end_of_list(&node_A);";
    output << "\nlinked_list.insert_node_at_end_of_list(&node_B);";
    output << "\nlinked_list.insert_node_at_end_of_list(&node_C);";
    output << "\noutput << linked_list; // functionally identical to linked_list.print(output)";
    LINKED_LIST linked_list;
    NODE node_A = { key : "node_A", next : NULL };
    NODE node_B = { key : "node_B", next : NULL };
    NODE node_C = { key : "node_C", next : NULL };
    linked_list.insert_node_at_end_of_list(&node_A);
    linked_list.insert_node_at_end_of_list(&node_B);
    linked_list.insert_node_at_end_of_list(&node_C);
    output << linked_list;
}

/**
 * Unit Test # 3: LINKED_LIST constructor, insert method, remove method, print method, and destructor.
 */
void unit_test_3(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 3: LINKED_LIST constructor, insert method, remove method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nNODE node_X = { key : \"node_X\", next : NULL };";
    output << "\nNODE node_Y = { key : \"node_Y\", next : NULL };";
    output << "\nNODE node_Z = { key : \"node_Z\", next : NULL };";
    output << "\nlinked_list.insert_node_at_end_of_list(&node_X);";
    output << "\nlinked_list.insert_node_at_end_of_list(&node_Y);";
    output << "\nlinked_list.insert_node_at_end_of_list(&node_Z);";
    output << "\nlinked_list.print(output);";
    output << "\nlinked_list.remove_nodes_with_key(\"node_Y\");";
    output << "\nlinked_list.print(output);";
    LINKED_LIST linked_list;
    NODE node_X = { key : "node_X", next : NULL };
    NODE node_Y = { key : "node_Y", next : NULL };
    NODE node_Z = { key : "node_Z", next : NULL };
    linked_list.insert_node_at_end_of_list(&node_X);
    linked_list.insert_node_at_end_of_list(&node_Y);
    linked_list.insert_node_at_end_of_list(&node_Z);
    linked_list.print(output);
    linked_list.remove_nodes_with_key("node_Y");
    linked_list.print(output);
}

/**
 * Unit Test # 4: LINKED_LIST constructor, insert method, remove method, print method, and destructor.
 */
void unit_test_4(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 4: LINKED_LIST constructor, insert method, remove method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nLINKED_LIST linked_list;";
    output << "\nNODE n0 = { key : \"red\", next : NULL };";
    output << "\nNODE n1 = { key : \"blue\", next : NULL };";
    output << "\nNODE n2 = { key : \"green\", next : NULL };";
    output << "\nNODE n3 = { key : \"red\", next : NULL };";
    output << "\nNODE n4 = { key : \"green\", next : NULL };";
    output << "\nNODE n5 = { key : \"red\", next : NULL };";
    output << "\nNODE n6 = { key : \"red\", next : NULL };";
    output << "\nNODE n7 = { key : \"red\", next : NULL };";
    output << "\nlinked_list.insert_node_at_end_of_list(&n0);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n1);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n2);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n3);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n4);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n5);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n6);";
    output << "\nlinked_list.insert_node_at_end_of_list(&n7);";
    output << "\nlinked_list.print(output);";
    output << "\nlinked_list.remove_nodes_with_key(\"red\");";
    output << "\nlinked_list.print(output);";
    output << "\nlinked_list.remove_nodes_with_key(\"green\");";
    output << "\nlinked_list.print(output);";
    output << "\nlinked_list.remove_nodes_with_key(\"blue\");";
    output << "\nlinked_list.print(output);";
    LINKED_LIST linked_list;
    NODE n0 = { key : "red", next : NULL };
    NODE n1 = { key : "blue", next : NULL };
    NODE n2 = { key : "green", next : NULL };
    NODE n3 = { key : "red", next : NULL };
    NODE n4 = { key : "green", next : NULL };
    NODE n5 = { key : "red", next : NULL };
    NODE n6 = { key : "red", next : NULL };
    NODE n7 = { key : "red", next : NULL };
    linked_list.insert_node_at_end_of_list(&n0);
    linked_list.insert_node_at_end_of_list(&n1);
    linked_list.insert_node_at_end_of_list(&n2);
    linked_list.insert_node_at_end_of_list(&n3);
    linked_list.insert_node_at_end_of_list(&n4);
    linked_list.insert_node_at_end_of_list(&n5);
    linked_list.insert_node_at_end_of_list(&n6);
    linked_list.insert_node_at_end_of_list(&n7);
    linked_list.print(output);
    linked_list.remove_nodes_with_key("red");
    linked_list.print(output);
    linked_list.remove_nodes_with_key("green");
    linked_list.print(output);
    linked_list.remove_nodes_with_key("blue");
    linked_list.print(output);
}

/* program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If linked_list_driver_output.txt does not already exist in the same directory as linked_list_driver.cpp, 
     * create a new file named linked_list_driver_output.txt.
     * 
     * Open the plain-text file named linked_list_driver_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("linked_list_driver_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Implement a series of unit tests which demonstrate the functionality of LINKED_LIST class variables.
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
