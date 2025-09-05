/**
 * file: pascals_triangle_generator.cpp
 * type: C++ (source file)
 * date: 04_OCTOBER_2024
 * author: karbytes
 * license: PUBLIC_DOMAIN 
 */

/** preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // output file creation, output file overwriting, output file open, output file close
#include <vector> // data type for representing mutable arrays in C++ 
#include <iomanip>  // set width function (std::setw)
#define MAXIMUM_N 20 // constant which represents the maximum value for N
using namespace std; // including standard namespace makes use of std:: preface optional

/** function prototypes */
vector<vector<int>> generate_first_N_rows_of_Pascals_Triangle(int N);
void print_pascals_triangle(const vector<vector<int>> & pascals_triangle, ostream & output);

/** program entry point */
int main() 
{
    // Declare and initialize one int type variable (which represents the number of rows in the Pascal's Triangle to generate).
    int N = 0;

    // Declare a file output stream handler (which represents the plain-text file to generate and/or overwrite with program data).
    ofstream file;

    /**
     * Declare a vector which stores int-type values and which will be used to store the values representing the first N rows of Pascal's Triangle.
     * 
     * Note that a C++ vector is an allocation of contiguous memory cells for the purpose of storing elements of a single data type
     * and that elements of a vector can be inserted and removed during that vector's instantiation.
     * 
     * In this case, pascals_triangle is a vector containing vectors containing int-type values.
     */
    vector<vector<int>> pascals_triangle;

    /**
     * If the file named pascals_triangle_generator_output.txt does not already exist 
     * inside of the same file directory as the file named pascals_triangle_generator.cpp, 
     * create a new file named pascals_triangle_generator_output.txt in that directory.
     * 
     * Open the plain-text file named pascals_triangle_generator_output.txt
     * and set that file to be overwritten with program data.
     */
    file.open("pascals_triangle_generator_output.txt");

    // Print an opening message to the command line terminal.
    cout << "\n\n--------------------------------";
    cout << "\nStart Of Program";
    cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "This C++ program generates the first N rows of Pascal's Triangle." to the command line terminal and to the file output stream.
    cout << "\n\nThis C++ program generates the first N rows of Pascal's Triangle.";
    file << "\n\nThis C++ program generates the first N rows of Pascal's Triangle.";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    std::cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Prompt the user to enter an input value for N (and print that prompt to the command line terminal and to the file output stream).
    cout << "\n\nEnter a natural number, N, which is the number of rows in Pascal's Triangle to generate and which is no larger than " << MAXIMUM_N << ": ";
    file << "\n\nEnter a natural number, N, which is the number of rows in Pascal's Triangle to generate and which is no larger than " << MAXIMUM_N << ": ";

    // Scan the command line terminal for the most recent keyboard input value. Store that value in N.
    cin >> N;

    // Print "The value which was entered for N is {N}." to the command line terminal and to the file output stream.
    cout << "\nThe value which was entered for N is " << N << ".";
    file << "\n\nThe value which was entered for N is " << N << ".";

    // Print a horizontal divider line to the command line terminal and to the file output stream.
    cout << "\n\n--------------------------------";
    file << "\n\n--------------------------------";

    // Populate the two-dimensional vector array with values representing the first N rows of Pascal's Triangle.
    pascals_triangle = generate_first_N_rows_of_Pascals_Triangle(N);

    // Print the first N rows of Pascal's Triangle (in the spatial configuration of an isosceles triangle) to the command line terminal.
    print_pascals_triangle(pascals_triangle, cout);

    // Print the first N rows of Pascal's Triangle (in the spatial configuration of an isosceles triangle) to the output file stream.
    print_pascals_triangle(pascals_triangle, file);

    // Print a closing message to the command line terminal.
    cout << "\n\n--------------------------------";
    cout << "\nEnd Of Program";
    cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0; 
}

/**
 * Return a two-dimensional mutable array which represents the first N rows of Pascal's Triangle.
 * 
 * Pascal's Triangle is a triangular arrangement of natural numbers (resembling an isosceles triangle)
 * such that the top row consists solely of the number 1,
 * each subsequent row begins and ends with 1,
 * and every other number in the arrangement is the sum of the two numbers directly above it.
 * 
 * Example: 
 * 
 * If N = 10, then the rows of Pascal's Triangle which are stored in the object returned 
 * by this function depict the following arrangement of natural numbers...
 * 
 *                    1 
 *                  1   1 
 *                1   2   1 
 *              1   3   3   1 
 *            1   4   6   4   1 
 *          1   5  10  10   5   1 
 *        1   6  15  20  15   6   1 
 *      1   7  21  35  35  21   7   1 
 *    1   8  28  56  70  56  28   8   1 
 *  1   9  36  84 126 126  84  36   9   1 
 */
vector<vector<int>> generate_first_N_rows_of_Pascals_Triangle(int N) 
{
    // Declare loop control variables and set each of their initial values to zero.
    int i = 0, j = 0;

    // Declare a vector of vectors (which is a mutable two-dimensional array) for storing values representing the first N rows of Pascal's Triangle.
    vector<vector<int>> pascals_triangle(N);

    // If N is smaller than one or larger than MAXIMUM_N, set N to ten.
    if ((N < 1) || (N > MAXIMUM_N)) N = 10;

    /** 
     * For each row of Pascal's Triangle up to the Nth row 
     * (starting at the top row (row # 0) and ending at the bottom row (row # (N -1)) in ascending row number)...
     */
    for (i = 0; i < N; i += 1) 
    {
        // expand the size of the otherwise empty one-dimensional vector representing a particular row to fit all the numbers of that row...
        pascals_triangle[i].resize(i + 1);

        // and set the first and last element of that expanded one-dimensional array to 1.
        pascals_triangle[i][0] = pascals_triangle[i][i] = 1;  

        /** 
         * For each element of the ith row of Pascal's Triangle,
         * (starting at the leftmost element, pascals_triangle[i][0], and ending at the rightmost element, pascals_triangle[i][i - 1], in ascending row number)...
         */
        for (j = 1; j < i; j += 1) 
        {
            // set the value of the current Pascal's Triangle entry to the sum of the two entries directly above it.
            pascals_triangle[i][j] = pascals_triangle[i - 1][j - 1] + pascals_triangle[i - 1][j];
        }
    }

    // Return the populated two-dimensional mutable array which represents the first N rows of Pascal's Triangle.
    return pascals_triangle;
}

/**
 *  Print Pascal's Triangle (up to some natural number of rows) in isosceles triangle form
 *  such that the number in the top row is positioned along the vertical line which divides the 
 *  triangular permutation of numbers in half to the output stream.
 */
void print_pascals_triangle(const vector<vector<int>> & pascals_triangle, ostream & output) 
{
    int N = pascals_triangle.size();
    int max_width = to_string(pascals_triangle[N - 1][N / 2]).length();  // Get the width of the largest number in the pascals_triangle object.
    output << "\n\nPrinting the first " << N << " rows of Pascal's Triangle...\n\n";
    for (int i = 0; i < N; i += 1) 
    {
        // Print leading spaces to align the numbers in the output stream such that the numbers visually depict an isosceles triangle.
        output << setw((N - i) * (max_width + 1) / 2) << "";

        for (int j = 0; j <= i; ++j) output << setw(max_width) << pascals_triangle[i][j] << " ";

        // Print the new line character after the last element of the ith row.
        output << "\n";
    }
}
