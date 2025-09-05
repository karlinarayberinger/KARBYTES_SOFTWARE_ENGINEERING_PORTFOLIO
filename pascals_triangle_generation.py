#########################################################################################
# file: pascals_triangle_generation.py
# type: Python
# date: 05_OCTOBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

def generate_first_N_rows_of_pascals_triangle(N):
    # Initialize Pascal's triangle as a list of lists.
    pascals_triangle = [[1]]

    # If N is smaller than one or larger than twenty, set N to ten.
    if N < 1 or N > 20:
        N = 10

    # Generate each row of Pascal's Triangle.
    for i in range(1, N):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = pascals_triangle[i - 1][j - 1] + pascals_triangle[i - 1][j]
        pascals_triangle.append(row)

    return pascals_triangle

def print_pascals_triangle(pascals_triangle, output):
    N = len(pascals_triangle)
    
    # Find the width of the largest number in the last row for formatting.
    max_width = len(str(pascals_triangle[N - 1][N // 2]))

    # Output header to both file and console
    output.write("\n\nPrinting the first {} rows of Pascal's Triangle...\n\n".format(N))
    print("\n\nPrinting the first {} rows of Pascal's Triangle...\n\n".format(N))

    # Print the Pascal's triangle
    for i in range(N):
        # Create the leading spaces for aligning the triangle shape
        leading_spaces = " " * ((N - i) * (max_width + 1) // 2)
        
        # Output leading spaces and row numbers to both file and console
        output.write(leading_spaces)
        print(leading_spaces, end="")

        # Output each number in the current row to both file and console
        row_numbers = " ".join(f"{pascals_triangle[i][j]:{max_width}}" for j in range(i + 1))
        output.write(row_numbers + "\n")
        print(row_numbers)

def main():

    # Open the file for writing (and generate that file if it does not exist).
    with open("pascals_triangle_generator_output.txt", "w") as file:

        # Print an opening message to the command line terminal.
        print("\n\n--------------------------------")
        print("Start Of Program")
        print("--------------------------------")

        # Print an opening message to the output file.
        file.write("--------------------------------\n")
        file.write("Start Of Program\n")
        file.write("--------------------------------\n")

        # Print "This C++ program generates the first N rows of Pascal's Triangle." to the command line terminal and to the output file.
        print("\n\nThis Python program generates the first N rows of Pascal's Triangle.")
        file.write("\n\nThis Python program generates the first N rows of Pascal's Triangle.")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        file.write("\n\n--------------------------------")

        # Prompt the user to enter an input value and store that value in N.
        N = int(input("\n\nEnter the number of rows for Pascal's Triangle: "))

        # Log user input to the file after it is entered.
        file.write(f"\n\nEntered value: N = {N}")
        print(f"\n\nEntered value: N = {N}")

        # Generate Pascal's Triangle
        pascals_triangle = generate_first_N_rows_of_pascals_triangle(N)

        # Print Pascal's Triangle to both the output file and to the command line terminal.
        print_pascals_triangle(pascals_triangle, file)

        # Print a closing message to the command line terminal.
        print("\n\n--------------------------------")
        print("End Of Program")
        print("--------------------------------\n\n")

        # Print a closing message to the output file.
        file.write("\n\n--------------------------------\n")
        file.write("End Of Program\n")
        file.write("--------------------------------\n")

# Program entry point
if __name__ == "__main__":
    main()
