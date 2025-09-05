/**
 * file: public_linked_list.h
 * type: C++ (header file)
 * author: karbytes
 * date: 08_JULY_2023
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#ifndef LINKED_LIST_H // If public_linked_list.h has not already been linked to a source file (.cpp), 
#define LINKED_LIST_H // then link this header file to the source file(s) which include this header file.

/* preprocessing directives */
#include <iostream> // library for defining objects which handle command line input and command line output
#include <fstream> // library for defining objects which handle file input and file output
#include <string> // library which defines a sequence of text characters (i.e. char type values) as a string type variable

/**
 * A variable whose data type is NODE is a tuple consisting of two variables
 * such that one of those variables stores some arbitrary piece of information (i.e. key)
 * while the other variable stores the address of a NODE variable (i.e. next).
 * 
 * Like a C++ class, a C++ struct is a user defined data type.
 * 
 * Note that each of the members of a struct variable is public and neither private nor protected.
 * 
 * Note that each of the members of a struct variable is a variable and not a function.
 */
struct NODE
{
    std::string key; // key stores an arbitrary sequence of characters
    NODE * next; // next stores the memory address of a NODE type variable.
};

/**
 * A variable whose data type is LINKED_LIST is a software object whose data attributes
 * consist of exactly one pointer-to-NODE type variable which is assumed to be the 
 * first node of a linear and unidirectional (i.e. singly-linked) linked list.
 * 
 * When a LINKED_LIST type variable is declared, a dynamic NODE type variable is created
 * and the memory address of that dynamic NODE type variable is stored in a pointer-to-NODE
 * type variable named head.
 * 
 * After a LINKED_LIST type variable is created and before that variable is deleted, 
 * NODE type elements can be inserted into the list which the LINKED_LIST type variable represents
 * and NODE type elements can be removed from the list which the LINKED_LIST type variable represents.
 * 
 * After a LINKED_LIST type variable is created and before that variable is deleted,
 * that variable (i.e. object) can invoke a print function which prints a description
 * of the caller LINKED_LIST object.
 * 
 * When a LINKED_LIST variable is deleted, the pointer-to-NODE type variable named head 
 * (which was assigned memory during program runtime rather than during program compilation time) 
 * is deleted.
 */
class LINKED_LIST
{
public:
    NODE * head; // head stores the memory address of the first NODE type element of a LINKED_LIST type data structure.
    bool remove_node_with_key(std::string key); // helper method
    LINKED_LIST(); // constructor
    void insert_node_at_end_of_list(NODE * node); // setter method
    void remove_nodes_with_key(std::string key); // setter method
    int get_number_of_nodes_in_list(); // getter method
    void print(std::ostream & output = std::cout); // descriptor method
    friend std::ostream & operator << (std::ostream & output, LINKED_LIST & linked_list); // descriptor method
    ~LINKED_LIST(); // destructor
};

/* preprocessing directives */
#endif // Terminate the conditional preprocessing directives code block in this header file.
