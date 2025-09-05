/**
 * file: hash_table_driver.cpp
 * type: C++ (source file)
 * date: 08_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

#include "hash_table.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the HASH_TABLE class.

/* function prototypes */
void unit_test_0(std::ostream & output);
void unit_test_1(std::ostream & output);
void unit_test_2(std::ostream & output);
void unit_test_3(std::ostream & output);
void unit_test_4(std::ostream & output);
void unit_test_5(std::ostream & output);

/**
 * Unit Test # 0: HASH_TABLE constructor, print method, and destructor.
 */
void unit_test_0(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 0: HASH_TABLE constructor, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nhash_table.print(output);";
    HASH_TABLE hash_table;
    hash_table.print(output);
}

/**
 * Unit Test # 1: HASH_TABLE constructor, insert method, print method, and destructor.
 */
void unit_test_1(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 1: HASH_TABLE constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nNODE node;";
    output << "\nnode.key = \"unit_test_1\";";
    output << "\nnode.next = NULL;";
    output << "\nhash_table.insert_node(&node);";
    output << "\nhash_table.print(output);";
    HASH_TABLE hash_table;
    NODE node;
    node.key = "unit_test_1";
    node.next = NULL;
    hash_table.insert_node(&node);
    hash_table.print(output);
}

/**
 * Unit Test # 2: HASH_TABLE constructor, insert method, print method, and destructor.
 */
void unit_test_2(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 2: HASH_TABLE constructor, insert method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nNODE node_A = { key : \"node_A\", next : NULL };";
    output << "\nNODE node_B = { key : \"node_B\", next : NULL };";
    output << "\nNODE node_C = { key : \"node_C\", next : NULL };";
    output << "\nhash_table.insert_node(&node_A);";
    output << "\nhash_table.insert_node(&node_B);";
    output << "\nhash_table.insert_node(&node_C);";
    output << "\noutput << hash_table; // functionally identical to hash_table.print(output)";
    HASH_TABLE hash_table;
    NODE node_A = { key : "node_A", next : NULL };
    NODE node_B = { key : "node_B", next : NULL };
    NODE node_C = { key : "node_C", next : NULL };
    hash_table.insert_node(&node_A);
    hash_table.insert_node(&node_B);
    hash_table.insert_node(&node_C);
    output << hash_table; // functionally identical to hash_table.print(output);
}

/**
 * Unit Test # 3: HASH_TABLE constructor, insert method, number of linked lists method, number of node method, print method, and destructor.
 */
void unit_test_3(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 3: HASH_TABLE constructor, insert method, number of linked lists method, number of node method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table = HASH_TABLE(5);";
    output << "\nNODE node_A = { key : \"node_A\", next : NULL };";
    output << "\nNODE node_B = { key : \"node_B\", next : NULL };";
    output << "\nNODE node_C = { key : \"node_C\", next : NULL };";
    output << "\nNODE node_AA = { key : \"node_AA\", next : NULL };";
    output << "\nNODE node_BB = { key : \"node_BB\", next : NULL };";
    output << "\nNODE node_CC = { key : \"node_CC\", next : NULL };";
    output << "\nNODE node_Z = { key : \"node_Z\", next : NULL };";
    output << "\nNODE node_666 = { key : \"node_666\", next : NULL };";
    output << "\nhash_table.insert_node(&node_A);";
    output << "\nhash_table.insert_node(&node_B);";
    output << "\nhash_table.insert_node(&node_C);";
    output << "\nhash_table.insert_node(&node_AA);";
    output << "\nhash_table.insert_node(&node_BB);";
    output << "\nhash_table.insert_node(&node_CC);";
    output << "\nhash_table.insert_node(&node_Z);";
    output << "\nhash_table.insert_node(&node_666);";
    output << "\noutput << hash_table; // functionally identical to hash_table.print(output)";
    HASH_TABLE hash_table = HASH_TABLE(5);
    NODE node_A = { key : "node_A", next : NULL };
    NODE node_B = { key : "node_B", next : NULL };
    NODE node_C = { key : "node_C", next : NULL };
    NODE node_AA = { key : "node_AA", next : NULL };
    NODE node_BB = { key : "node_BB", next : NULL };
    NODE node_CC = { key : "node_CC", next : NULL };
    NODE node_Z = { key : "node_Z", next : NULL };
    NODE node_666 = { key : "node_666", next : NULL };
    hash_table.insert_node(&node_A);
    hash_table.insert_node(&node_B);
    hash_table.insert_node(&node_C);
    hash_table.insert_node(&node_AA);
    hash_table.insert_node(&node_BB);
    hash_table.insert_node(&node_CC);
    hash_table.insert_node(&node_Z);
    hash_table.insert_node(&node_666);
    output << "\nhash_table.get_number_of_linked_lists_in_hash_table() = " << hash_table.get_number_of_linked_lists_in_hash_table() << ".";
    output << "\nhash_table.get_number_of_nodes_in_hash_table()= " << hash_table.get_number_of_nodes_in_hash_table() << ".";
    output << hash_table; // functionally identical to hash_table.print(output);
}

/**
 * Unit Test # 4: HASH_TABLE constructor, insert method, remove method, print method, and destructor.
 */
void unit_test_4(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 4: HASH_TABLE constructor, insert method, remove method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table;";
    output << "\nNODE node_0 = { key : \"XXX\", next : NULL };";
    output << "\nNODE node_1 = { key : \"YYY\", next : NULL };";
    output << "\nNODE node_2 = { key : \"ZZZ\", next : NULL };";
    output << "\nNODE node_3 = { key : \"XXX\", next : NULL };";
    output << "\nNODE node_4 = { key : \"YYY\", next : NULL };";
    output << "\nNODE node_5 = { key : \"ZZZ\", next : NULL };";
    output << "\nNODE node_6 = { key : \"XXX\", next : NULL };";
    output << "\nNODE node_7 = { key : \"YYY\", next : NULL };";
    output << "\nNODE node_8 = { key : \"ZZZ\", next : NULL };";
    output << "\nNODE node_9 = { key : \"XXX\", next : NULL };";
    output << "\nNODE node_10 = { key : \"YYY\", next : NULL };";
    output << "\nNODE node_11 = { key : \"ZZZ\", next : NULL };";
    output << "\nhash_table.insert_node(&node_0);";
    output << "\nhash_table.insert_node(&node_1);";
    output << "\nhash_table.insert_node(&node_2);";
    output << "\nhash_table.insert_node(&node_3);";
    output << "\nhash_table.insert_node(&node_4);";
    output << "\nhash_table.insert_node(&node_5);";
    output << "\nhash_table.insert_node(&node_6);";
    output << "\nhash_table.insert_node(&node_7);";
    output << "\nhash_table.insert_node(&node_8);";
    output << "\nhash_table.insert_node(&node_9);";
    output << "\nhash_table.insert_node(&node_10);";
    output << "\nhash_table.insert_node(&node_11);";
    output << "\nhash_table.print(output);";
    output << "\nhash_table.remove_nodes_with_key(\"XXX\");";
    output << "\nhash_table.print(output);";
    HASH_TABLE hash_table;
    NODE node_0 = { key : "XXX", next : NULL };
    NODE node_1 = { key : "YYY", next : NULL };
    NODE node_2 = { key : "ZZZ", next : NULL };
    NODE node_3 = { key : "XXX", next : NULL };
    NODE node_4 = { key : "YYY", next : NULL };
    NODE node_5 = { key : "ZZZ", next : NULL };
    NODE node_6 = { key : "XXX", next : NULL };
    NODE node_7 = { key : "YYY", next : NULL };
    NODE node_8 = { key : "ZZZ", next : NULL };
    NODE node_9 = { key : "XXX", next : NULL };
    NODE node_10 = { key : "YYY", next : NULL };
    NODE node_11 = { key : "ZZZ", next : NULL };
    hash_table.insert_node(&node_0);
    hash_table.insert_node(&node_1);
    hash_table.insert_node(&node_2);
    hash_table.insert_node(&node_3);
    hash_table.insert_node(&node_4);
    hash_table.insert_node(&node_5);
    hash_table.insert_node(&node_6);
    hash_table.insert_node(&node_7);
    hash_table.insert_node(&node_8);
    hash_table.insert_node(&node_9);
    hash_table.insert_node(&node_10);
    hash_table.insert_node(&node_11);
    hash_table.print(output);
    hash_table.remove_nodes_with_key("XXX");
    hash_table.print(output);
}

/**
 * HASH_TABLE constructor, insert method, get nodes with key method, print method, and destructor.
 */
void unit_test_5(std::ostream & output) 
{
    output << "\n\n************************************************";
    output << "\nUnit Test # 5: HASH_TABLE constructor, insert method, get nodes with key method, print method, and destructor.";
    output << "\n************************************************";
    output << "\nHASH_TABLE hash_table = HASH_TABLE(6);";
    output << "\nNODE node_0 = { key : \"AAAA\", next : NULL };";
    output << "\nNODE node_1 = { key : \"ABAB\", next : NULL };";
    output << "\nNODE node_2 = { key : \"AABB\", next : NULL };";
    output << "\nNODE node_3 = { key : \"CCCC\", next : NULL };";
    output << "\nNODE node_4 = { key : \"ABAB\", next : NULL };";
    output << "\nNODE node_5 = { key : \"CCCC\", next : NULL };";
    output << "\nNODE node_6 = { key : \"BBBB\", next : NULL };";
    output << "\nNODE node_7 = { key : \"ABAB\", next : NULL };";
    output << "\nNODE node_8 = { key : \"AAAA\", next : NULL };";
    output << "\nNODE node_9 = { key : \"CCCC\", next : NULL };";
    output << "\nNODE node_10 = { key : \"DDDD\", next : NULL };";
    output << "\nNODE node_11 = { key : \"AABB\", next : NULL };";
    output << "\nNODE node_12 = { key : \"EEEE\", next : NULL };";
    output << "\nNODE node_13 = { key : \"DDDD\", next : NULL };";
    output << "\nNODE node_14 = { key : \"ABAB\", next : NULL };";
    output << "\nhash_table.insert_node(&node_0);";
    output << "\nhash_table.insert_node(&node_1);";
    output << "\nhash_table.insert_node(&node_2);";
    output << "\nhash_table.insert_node(&node_3);";
    output << "\nhash_table.insert_node(&node_4);";
    output << "\nhash_table.insert_node(&node_5);";
    output << "\nhash_table.insert_node(&node_6);";
    output << "\nhash_table.insert_node(&node_7);";
    output << "\nhash_table.insert_node(&node_8);";
    output << "\nhash_table.insert_node(&node_9);";
    output << "\nhash_table.insert_node(&node_10);";
    output << "\nhash_table.insert_node(&node_11);";
    output << "\nhash_table.insert_node(&node_12);";
    output << "\nhash_table.insert_node(&node_13);";
    output << "\nhash_table.insert_node(&node_14);";
    output << "\noutput << hash_table; // functionally identical to hash_table.print(output)";
    output << "\nLINKED_LIST search_results = hash_table.get_nodes_with_key(\"AAAA\");";
    output << "\noutput << search_results; // functionally identical to search_results.print(output);";
    HASH_TABLE hash_table = HASH_TABLE(6);
    NODE node_0 = { key : "AAAA", next : NULL };
    NODE node_1 = { key : "ABAB", next : NULL };
    NODE node_2 = { key : "AABB", next : NULL };
    NODE node_3 = { key : "CCCC", next : NULL };
    NODE node_4 = { key : "ABAB", next : NULL };
    NODE node_5 = { key : "CCCC", next : NULL };
    NODE node_6 = { key : "BBBB", next : NULL };
    NODE node_7 = { key : "ABAB", next : NULL };
    NODE node_8 = { key : "AAAA", next : NULL };
    NODE node_9 = { key : "CCCC", next : NULL };
    NODE node_10 = { key : "DDDD", next : NULL };
    NODE node_11 = { key : "AABB", next : NULL };
    NODE node_12 = { key : "EEEE", next : NULL };
    NODE node_13 = { key : "DDDD", next : NULL };
    NODE node_14 = { key : "ABAB", next : NULL };
    hash_table.insert_node(&node_0);
    hash_table.insert_node(&node_1);
    hash_table.insert_node(&node_2);
    hash_table.insert_node(&node_3);
    hash_table.insert_node(&node_4);
    hash_table.insert_node(&node_5);
    hash_table.insert_node(&node_6);
    hash_table.insert_node(&node_7);
    hash_table.insert_node(&node_8);
    hash_table.insert_node(&node_9);
    hash_table.insert_node(&node_10);
    hash_table.insert_node(&node_11);
    hash_table.insert_node(&node_12);
    hash_table.insert_node(&node_13);
    hash_table.insert_node(&node_14);
    output << hash_table; // functionally identical to hash_table.print(output);
    LINKED_LIST search_results = hash_table.get_nodes_with_key("AAAA");
    output << search_results; // functionally identical to search_results.print(output);
}

/* program entry point */
int main()
{
    // Declare a file output stream object.
    std::ofstream file;

    /**
     * If hash_table_driver_output.txt does not already exist in the same directory as hash_table_driver.cpp, 
     * create a new file named hash_table_driver_output.txt.
     * 
     * Open the plain-text file named hash_table_driver_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("hash_table_driver_output.txt");

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
    unit_test_5(std::cout);
    unit_test_5(file);

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
