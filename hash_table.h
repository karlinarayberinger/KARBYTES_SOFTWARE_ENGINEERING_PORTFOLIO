/**
 * file: hash_table.h
 * type: C++ (header file)
 * author: karbytes
 * date: 08_JULY_2023
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#ifndef HASH_TABLE_H // If hash_table.h has not already been linked to a source file (.cpp), 
#define HASH_TABLE_H // then link this header file to the source file(s) which include this header file.

/* preprocessing directives */
#include "public_linked_list.h" // Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the LINKED_LIST class.
#define MAXIMUM_N 100 // constant which represents maximum N value

/**
 * A variable whose data type is HASH_TABLE is a software object whose data attributes
 * consist of exactly one pointer-to-LINKED_LIST type variable named array 
 * and exactly one int type variable named N.
 * 
 * N stores a nonnegative integer value no larger than MAXIMUM_N.
 * 
 * array stores the memory address of the first memory cell of a LINKED_LIST sized chunk of contiguous memory cells
 * (and array is a pointer to the first element of an array comprised of N LINKED_LIST type elements).
 * 
 * When a HASH_TABLE type variable is declared, a dynamic LINKED_LIST type variable is created
 * and the memory address of that dynamic LINKED_LIST type variable is stored in a pointer-to-LINKED_LIST
 * type variable named array.
 * 
 * After a HASH_TABLE type variable is created and before that variable is deleted, 
 * NODE type elements can be inserted into the hash table array and
 * NODE type elements can be removed from the hash table array.
 * 
 * When a NODE is inserted into the hash table array, a hash function takes that NODE's key as 
 * a hash function input and then the hash function outputs a corresponding nonnegative integer
 * no larger than (N - 1) which represents the index of the hash table array where that
 * NODE will be inserted (and that NODE will be appended to the end of the LINKED_LIST which is stored at 
 * that particular array index).
 * 
 * After a HASH_TABLE type variable is created and before that variable is deleted,
 * that variable (i.e. object) can invoke a print function which prints a description
 * of the caller HASH_TABLE object.
 * 
 * When a HASH_TABLE variable is deleted, the pointer-to-LINKED_LIST type variable named array 
 * (which was assigned memory during program runtime rather than during program compilation time) 
 * and every head property of every LINKED_LIST type element of that array
 * is deleted.
 */
class HASH_TABLE
{
private:

    // array stores the memory address of the first element of an array of N LINKED_LIST type elements.
    LINKED_LIST * array; 

    // N stores a nonnegative integer value no larger than MAXIMUM_N.
    int N; 

    // The hash function returns an array index which corresponds with the input key value.
    int hash(std::string key); 

public:

    // The default constructor sets the length of the hash table array to 10 by default.
    HASH_TABLE(int hash_table_length = 10); 

    // The setter method appends the input NODE to the end of the LINKED_LIST located at array[hash(node -> key)].
    void insert_node(NODE * node); 

    // The setter method removes all NODE type instances from the hash table array whose key values match the input key value.
    void remove_nodes_with_key(std::string key);

    // The getter method returns a singly-linked list of all NODE type instances in the hash table array whose key values match the input key value.
    LINKED_LIST get_nodes_with_key(std::string key);

    // The getter method returns the number of LINKED_LIST type values stored in the hash table array (and the value returned is N).
    int get_number_of_linked_lists_in_hash_table(); 

    // The getter method returns the total number of NODE type values stored in the hash table array (and the value returned is an integer which is equal to or larger than N).
    int get_number_of_nodes_in_hash_table(); 
    
    // The descriptor method prints a description of the caller HASH_TABLE object to the output stream (and the command line terminal is the default output stream parameter).
    void print(std::ostream & output = std::cout); 
    
    // The descriptor method overloads the ostream operator to make it identical to calling the HASH_TABLE print function.
    friend std::ostream & operator << (std::ostream & output, HASH_TABLE & hash_table); 
    
    // The destructor de-allocates memory which was assigned to the caller HASH_TABLE object.
    ~HASH_TABLE(); 
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
