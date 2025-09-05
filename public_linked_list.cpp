/**
 * file: public_linked_list.cpp
 * type: C++ (source file)
 * author: karbytes
 * date: 08_JULY_2023
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the LINKED_LIST class.
#include "public_linked_list.h" 

/**
 * Starting at the NODE type element whose memory address is stored in head and ending at NULL,
 * traverse the singly-linked list comprised of NODE type elements such that each of those elements are visited.
 * 
 * If the current element's key is identical to the input key,
 * set the next property of the previous node to 
 * the memory address of the node which is next in the list after the current element
 * and return true.
 * 
 * If at least one node in the list has a key which is identical to the input key,
 * the function will return true. Otherwise, the function will return false.
 * 
 * (The method of using two pointers, p and q, to traverse the list is colloquially described as "inchworming"
 * because those two pointers metaphorically resemble opposite ends of an inchworm as that insect stretches its
 * front end forward by approximately one inch before moving its back end to where its front end is located).
 */
bool LINKED_LIST::remove_node_with_key(std::string key)
{
    NODE * p = head;
    NODE * q = head;
    while (q)
    {
        if ((q -> key == key) && (q != head))
        {
            std::cout << "\n\nThe NODE whose memory address is " << q << " is being removed from the LINKED_LIST...";
            p -> next = q -> next;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

/**
 * Instantiate an "empty" linked list (i.e. a linked list with only a head node and no "body nodes").
 * 
 * Note that only "body nodes" may be inserted into or else removed from a linked list which a LINKED_LIST type object represents.
 */
LINKED_LIST::LINKED_LIST()
{
    std::cout << "\n\nCreating the LINKED_LIST type object whose memory address is " << this << "...";
    head = new NODE;
    head -> key = "HEAD";
    head -> next = NULL;
}

/**
 * Make the input NODE type variable the last element of the linked list represented by the caller LINKED_LIST object.
 * 
 * (Note that using a NODE which is currently an element of the caller LINKED_LIST as the input to this function
 * will turn the linked list represented by the caller LINKED_LIST object into a closed loop rather than a finite linear sequence). 
 * 
 * (The method of using two pointers, p and q, to traverse the list is colloquially described as "inchworming"
 * because those two pointers metaphorically resemble opposite ends of an inchworm as that insect stretches its
 * front end forward by approximately one inch before moving its back end to where its front end is located).
 */
void LINKED_LIST::insert_node_at_end_of_list(NODE * node)
{
    NODE * p = head;
    NODE * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    std::cout << "\n\nThe NODE whose memory address is " << p << " is being inserted into the LINKED_LIST as the last element of that list...";
    p -> next = node; 
    node -> next = NULL;
}

/**
 * Remove all nodes from the linked list represented by the caller LINKED_LIST object 
 * whose key values are identical to the input key value.
 */
void LINKED_LIST::remove_nodes_with_key(std::string key)
{
    bool at_least_one_node_was_removed = false;
    at_least_one_node_was_removed = remove_node_with_key(key);
    while (at_least_one_node_was_removed) at_least_one_node_was_removed = remove_node_with_key(key);
}

/**
 * Return the natural number count of NODE type elements inside the singly-linked list which
 * the caller LINKED_LIST object represents.
 * 
 * Starting with the head and ending with NULL,
 * traverse sequentially down the list of NODE type elements and
 * count each element in the exist. 
 * 
 * If the linked list is "empty" (i.e. the head is the only NODE in the caller LINKED_LIST),
 * one will be returned.
 * 
 * (The method of using two pointers, p and q, to traverse the list is colloquially described as "inchworming"
 * because those two pointers metaphorically resemble opposite ends of an inchworm as that insect stretches its
 * front end forward by approximately one inch before moving its back end to where its front end is located).
 */
int LINKED_LIST::get_number_of_nodes_in_list()
{
    int node_count = 0;
    NODE * p = head;
    NODE * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        node_count += 1;
    }
    return node_count;
}

/**
 * The print method of the LINKED_LIST class prints a description of the caller LINKED_LIST object to the output stream.
 * 
 * A description of each NODE type element of the linked list which the caller LINKED_LIST object represents will be printed to the output stream
 * in the order those elements were inserted into the list by "inchworming" from NODE_0 to NODE_N (where N is the total number of nodes in the list).
 * 
 * (The method of using two pointers, p and q, to traverse the list is colloquially described as "inchworming"
 * because those two pointers metaphorically resemble opposite ends of an inchworm as that insect stretches its
 * front end forward by approximately one inch before moving its back end to where its front end is located).
 * 
 * Note that the default value of the function input parameter is the standard command line output stream (std::cout).
 * 
 * The default parameter is defined in the LINKED_LIST class header file (i.e. public_linked_list.h) and not in the LINKED_LIST class source file (i.e. public_linked_list.cpp).
 */
void LINKED_LIST::print(std::ostream & output)
{
    int node_count = 0;
    NODE * p = head;
    NODE * q = head;
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a LINKED_LIST sized chunk of contiguous memory cells which are allocated to the caller LINKED_LIST object.";
    output << "\n&head = " << &head << ". // The reference operation returns the memory address of the first memory cell of a pointer-to-NODE sized chunk of contiguous memory cells which are allocated to the caller LINKED_LIST data attribute named head.";
    output << "\nsizeof(NODE) = " << sizeof(NODE) << ". // The sizeof() operation returns the number of bytes of memory which a NODE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string) = " << sizeof(std::string) << ". // The sizeof() operation returns the number of bytes of memory which a string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(NODE *) = " << sizeof(NODE *) << ". // The sizeof() operation returns the number of bytes of memory which a pointer-to-NODE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(LINKED_LIST) = " << sizeof(LINKED_LIST) << ". // The sizeof() operation returns the number of bytes of memory which a LINKED_LIST type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nhead = " << head << ". // head stores either the first memory cell of a contiguous chunk of memory cells which are allocated to a NODE type variable or else head stores NULL (and the value NULL is displayed as 0).";
    output << "\nhead -> key = " << head -> key << ". // The arrow operator returns the string type property named key of the NODE type variable which head points to.";
    output << "\nhead -> next = " << head -> next << ". // The arrow operator returns the pointer-to-NODE type property named next of the NODE type variable which head points to.";
    output << "\nget_number_of_nodes_in_list() = " << get_number_of_nodes_in_list() << ".";
    output << "\n// p is a pointer to a NODE type variable.";
    output << "\nLINKED_LIST := {";
    while (q) 
    {
        p = q;
        output << "\n\tNODE_" << node_count << " := {";
        output << "\n\t\tp := " << p << ".";
        output << "\n\t\tp -> key = " << p -> key << ".";
        output << "\n\t\tp -> next = " << p -> next << ".";
        output << "\n\t}.";
        q = p -> next;
        node_count += 1;
    }
    output << "\n}.";
    output << "\n--------------------------------------------------------------------------------------------------";
}

/**
 * The friend function is an alternative to the print method.
 * The friend function overloads the ostream operator (<<).
 * 
 * (Overloading an operator is assigning a different function to a native operator other than the function which that operator is used to represent by default).
 * 
 * Note that the default value of the leftmost function input parameter is the standard command line output stream (std::cout).
 * The default parameter is defined in the LINKED_LIST class header file (i.e. public_linked_list.h).
 * 
 * The friend function is not a member of the LINKED_LIST class, 
 * but the friend function has access to the private and protected members 
 * of the LINKED_LIST class and not just to the public members of the LINKED_LIST class.
 * 
 * The friend keyword only prefaces the function prototype of this function 
 * (and the prototype of this function is declared in the LINKED_LIST class header file (i.e. public_linked_list.h)). 
 * 
 * The friend keyword does not preface the definition of this function
 * (and the definition of this function is specified in the LINKED_LIST class source file (i.e. public_linked_list.cpp)).
 * 
 * // overloaded print function example one
 * LINKED_LIST linked_list_0;
 * std::cout << linked_list_0; // identical to linked_list_0.print();
 * 
 * // overloaded print function example two
 * std::ofstream file;
 * LINKED_LIST linked_list_1;
 * file << linked_list_1; // identical to linked_list_1.print(file);
 */
std::ostream & operator << (std::ostream & output, LINKED_LIST & linked_list)
{
    linked_list.print(output);
    return output;
}

/**
 * The destructor method of the LINKED_LIST class de-allocates memory which was used to 
 * instantiate the LINKED_LIST object which is calling this function.
 * 
 * The destructor method of the LINKED_LIST class is automatically called when 
 * the program scope in which the caller LINKED_LIST object was instantiated terminates.
 */
LINKED_LIST::~LINKED_LIST()
{
    std::cout << "\n\nDeleting the LINKED_LIST type object whose memory address is " << this << "...";
    delete head;
}
