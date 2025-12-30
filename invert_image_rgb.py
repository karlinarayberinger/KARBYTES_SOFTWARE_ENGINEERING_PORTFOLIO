#########################################################################################
# file: invert_image_rgb.py
# type: Python
# date: 30_DECEMBER_2025
# author: karbytes 
# license: PUBLIC_DOMAIN
#########################################################################################

from PIL import Image
import os

# Define the only function in this program.
def invert_image_rgb(input_image_path, output_image_path):

    print("\n\n--------------------------------")
    print("\n\nThis Python program inverts the RGB color values of each pixel in an image.")
    print("\n\n--------------------------------")

    # Verify that the input file exists.
    if not os.path.isfile(input_image_path):
        print(f"\n\nERROR: Input image not found: {input_image_path}")
        print("\n\n--------------------------------\n\n")
        return

    # Open the image.
    image = Image.open(input_image_path)

    # Ensure the image is in RGB mode.
    image = image.convert("RGB")

    width, height = image.size
    pixels = image.load()

    print(f"\n\nProcessing image: {input_image_path}")
    print(f"Image size: {width} x {height}")

    # Iterate over every pixel.
    for y in range(height):
        for x in range(width):
            r, g, b = pixels[x, y]

            # Invert RGB values.
            inverted_r = 255 - r
            inverted_g = 255 - g
            inverted_b = 255 - b

            pixels[x, y] = (inverted_r, inverted_g, inverted_b)
            #end of nested for loop definition
    
    # Save the modified image.
    image.save(output_image_path)

    print(f"\n\nInverted image written to: {output_image_path}")
    print("\n\n--------------------------------\n\n")
    # end of function definition

# Set file paths.
input_image_path = "abstract_drawing_karbytes_26december2025_p0.jpg"      # Replace with your actual image path.
output_image_path = "input_image_inverted.png"

# Execute the function defined in this program file.
invert_image_rgb(input_image_path, output_image_path)
