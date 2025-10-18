#########################################################################################
# file: print_folder_checksums.py
# type: Python
# date: 17_OCTOBER_2025
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################

import os
import hashlib

# Define the only function in this program.
def list_file_checksums(folder_path, output_file):
    file_count = 0
    i = 0

    # Define the output file handler.
    with open(output_file, 'w') as f:

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        f.write("--------------------------------")

        # Print description to both terminal and file.
        print("\n\nThis Python program prints the SHA-256 checksum of each file inside of a particular folder.")
        f.write("\n\nThis Python program prints the SHA-256 checksum of each file inside of a particular folder.")

        # Print a horizontal divider line to the command line terminal and to the output file.
        print("\n\n--------------------------------")
        f.write("\n\n--------------------------------")

        # Walk through the folder and its subfolders.
        for root, dirs, files in os.walk(folder_path):
            f.write(f"\n\nDirectory: {root}")
            print(f"\n\nDirectory: {root}")
            for file in files:
                file_path = os.path.join(root, file)
                if os.path.isfile(file_path):  # Only process files, not subdirectories.
                    # Compute SHA-256 checksum.
                    sha256_hash = hashlib.sha256()
                    with open(file_path, "rb") as file_handle:
                        # Read and update hash in chunks of 4MB to handle large files efficiently.
                        for chunk in iter(lambda: file_handle.read(4 * 1024 * 1024), b""):
                            sha256_hash.update(chunk)
                    checksum = sha256_hash.hexdigest()
                    file_count += 1
                    f.write(f"\n\nfile_{i}: {file} // SHA-256: {checksum}")
                    print(f"\n\nfile_{i}: {file} // SHA-256: {checksum}")
                    i += 1
        
        # Print totals to the output file.
        f.write("\n\n--------------------------------")
        f.write(f"\n\nTotal number of files processed: {file_count}")
        f.write("\n\n--------------------------------")

        # Print totals to the command line terminal.
        print("\n\n--------------------------------")
        print(f"\n\nTotal number of files processed: {file_count}")
        print("\n\n--------------------------------")

    # Print a final message to the command line terminal.
    print(f"\n\nResults have been written to '{output_file}'.")

    # Print a horizontal divider line to the command line terminal.
    print("\n\n--------------------------------\n\n")

# Set the folder path to the folder you would like to analyze.
folder_path = 'test_folder'  # Replace with your actual folder path.
output_file = 'test_folder_checksums.txt'  # Output file (gets overwritten or created new).

# Execute the function which is defined in this program file.
list_file_checksums(folder_path, output_file)
