/**
 * file: hash_table.cpp
 * type: C++ (source file)
 * author: karbytes
 * date: 08_JULY_2023
 * license: PUBLIC_DOMAIN
 */

// Include the C++ header file which contains preprocessing directives, variable declarations, and function prototypes for the HASH_TABLE class.
#include "hash_table.h" 

/**
 * The hash function returns an array index which corresponds with the input key value.
 */
int HASH_TABLE::hash(std::string key)
{
    int value = 0, i = 0;
    for (i = 0; i < key.length(); i += 1) value += int(key[i]);
    return value % N;
}

/**
 * The default constructor sets the length of the hash table array to 10 by default.
 * 
 * The function returns a HASH_TABLE type object.
 */
HASH_TABLE::HASH_TABLE(int hash_table_length)
{
    std::cout << "\n\nCreating the HASH_TABLE type object whose memory address is " << this << "...";
    N = ((hash_table_length < 1) || (hash_table_length > MAXIMUM_N)) ? 10 : hash_table_length;
    array = new LINKED_LIST[N];
}

/**
 * The setter method appends the input NODE to the end of the LINKED_LIST located at array[hash(node -> key)].
 */
void HASH_TABLE::insert_node(NODE * node)
{
    int index = hash(node -> key);
    array[index].insert_node_at_end_of_list(node);
}

/**
 * The setter method removes all NODE type instances from the hash table array whose key values match the input key value.
 */
void HASH_TABLE::remove_nodes_with_key(std::string key)
{
    int index = hash(key);
    return array[index].remove_nodes_with_key(key);
}

/**
 * The getter method returns a singly-linked list of all NODE type instances in the hash table array whose key values match the input key value.
 * 
 * Set the next pointer value of the final NODE element in the returned LINKED_LIST to NULL.
 */
LINKED_LIST HASH_TABLE::get_nodes_with_key(std::string key)
{
    int index = hash(key);
    LINKED_LIST search_results;
    NODE * p = array[index].head;
    NODE * q = array[index].head;
    while (q)
    {
        if ((p -> key == key) && (p != array[index].head)) 
        {
            search_results.insert_node_at_end_of_list(p);
            p -> next = NULL;
        }
        p = q;
        q = p -> next;
    }

    return search_results;
}

/**
 * The getter method returns the number of LINKED_LIST type values stored in the hash table array (and the value returned is N).
 */
int HASH_TABLE::get_number_of_linked_lists_in_hash_table()
{
    return N;
}

/**
 * The getter method returns the total number of NODE type values stored in the hash table array (and the value returned is an integer which is equal to or larger than N).
 */
int HASH_TABLE::get_number_of_nodes_in_hash_table()
{
    int node_count = 0, i = 0;
    for (i = 0; i < N; i += 1) node_count += array[i].get_number_of_nodes_in_list();
    return node_count;
}

/**
 * The descriptor method prints a description of the caller HASH_TABLE object to the output stream (and the command line terminal is the default output stream parameter).
 */
void HASH_TABLE::print(std::ostream & output)
{
    int i = 0;
    output << "\n\n--------------------------------------------------------------------------------------------------";
    output << "\nthis = " << this << ". // The keyword named this is a pointer which stores the memory address of the first memory cell of a HASH_TABLE sized chunk of contiguous memory cells which are allocated to the caller HASH_TABLE object.";
    output << "\n&array = " << &array << ". // The reference operation returns the memory address of the first memory cell of a pointer-to-LINKED_LIST sized chunk of contiguous memory cells which are allocated to the caller HASH_TABLE data attribute named array.";
    output << "\n&N = " << &N << ". // The reference operation returns the memory address of the first memory cell of a pointer-to-int sized chunk of contiguous memory cells which are allocated to the caller HASH_TABLE data attribute named N.";
    output << "\nsizeof(int) = " << sizeof(int) << ". // The sizeof() operation returns the number of bytes of memory which a int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(int *) = " << sizeof(int *) << ". // The sizeof() operation returns the number of bytes of memory which a pointer-to-int type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string) = " << sizeof(std::string) << ". // The sizeof() operation returns the number of bytes of memory which a string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(std::string *) = " << sizeof(std::string *) << ". // The sizeof() operation returns the number of bytes of memory which a pointer-to-string type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(NODE) = " << sizeof(NODE) << ". // The sizeof() operation returns the number of bytes of memory which a NODE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(NODE *) = " << sizeof(NODE *) << ". // The sizeof() operation returns the number of bytes of memory which a pointer-to-NODE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(LINKED_LIST) = " << sizeof(LINKED_LIST) << ". // The sizeof() operation returns the number of bytes of memory which a LINKED_LIST type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(LINKED_LIST *) = " << sizeof(LINKED_LIST *) << ". // The sizeof() operation returns the number of bytes of memory which a pointer-to-LINKED_LIST type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(HASH_TABLE) = " << sizeof(HASH_TABLE) << ". // The sizeof() operation returns the number of bytes of memory which a HASH_TABLE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\nsizeof(HASH_TABLE *) = " << sizeof(HASH_TABLE *) << ". // The sizeof() operation returns the number of bytes of memory which a pointer-to-HASH_TABLE type variable occupies. (Each memory cell has a data capacity of 1 byte).";
    output << "\narray = " << array << ". // array stores either the first memory cell of a contiguous chunk of memory cells which are allocated to a LINKED_LIST type variable or else array stores NULL (and the value NULL is displayed as 0).";
    output << "\nN = " << N << ". // N stores the total number of LINKED_LIST types elements which are represented by the array property of the caller HASH_TABLE object.";
    output << "\nHASH_TABLE := {";
    for (i = 0; i < N; i += 1)
    {
        output << "\n\n############################################################";
        output << "\narray[" << i << "] := {";
        output << array[i];
        output << "\n}.";
        output << "\n############################################################";
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
 * The default parameter is defined in the HASH_TABLE class header file (i.e. hash_table.h).
 * 
 * The friend function is not a member of the HASH_TABLE class, 
 * but the friend function has access to the private and protected members 
 * of the HASH_TABLE class and not just to the public members of the HASH_TABLE class.
 * 
 * The friend keyword only prefaces the function prototype of this function 
 * (and the prototype of this function is declared in the HASH_TABLE class header file (i.e. hash_table.h)). 
 * 
 * The friend keyword does not preface the definition of this function
 * (and the definition of this function is specified in the HASH_TABLE class source file (i.e. hash_table.cpp)).
 * 
 * // overloaded print function example one
 * HASH_TABLE hash_table_0;
 * std::cout << hash_table_0; // identical to hash_table_0.print();
 * 
 * // overloaded print function example two
 * std::ofstream file;
 * HASH_TABLE hash_table_1;
 * file << hash_table_1; // identical to hash_table_1.print(file);
 */
std::ostream & operator << (std::ostream & output, HASH_TABLE & hash_table)
{
    hash_table.print(output);
    return output;
}

/**
 * The destructor method of the HASH_TABLE class de-allocates memory which was used to 
 * instantiate the HASH_TABLE object which is calling this function.
 * 
 * The destructor method of the HASH_TABLE class is automatically called when 
 * the program scope in which the caller HABLE_TABLE object was instantiated terminates.
 */
HASH_TABLE::~HASH_TABLE()
{
    std::cout << "\n\nDeleting the HASH_TABLE type object whose memory address is " << this << "...";
    delete [] array;
}
