#########################################################################################
# file: mp4_compressor.py
# type: Python
# date: 01_NOVEMBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################
from moviepy.editor import VideoFileClip
import os

def compress_mp4(input_file, output_folder="compressed_output", target_size_mb=24):
    # Convert target size to bytes
    target_size_bytes = target_size_mb * 1024 * 1024

    # Check if input file exists and is an MP4
    if not os.path.isfile(input_file) or not input_file.endswith('.mp4'):
        print("Please provide a valid MP4 file.")
        return

    # Load the video to get its duration
    video = VideoFileClip(input_file)
    duration = video.duration  # in seconds

    # Calculate the current file size and bitrate
    current_size = os.path.getsize(input_file)
    current_bitrate = (current_size * 8) / duration  # in bits per second

    # Calculate target bitrate based on desired file size
    target_bitrate = (target_size_bytes * 8) / duration  # in bits per second

    # Check if we need to compress (if the target bitrate is lower than current)
    if target_bitrate >= current_bitrate:
        print(f"The file is already under {target_size_mb} MB.")
        video.close()
        return

    # Create output directory if it doesn't exist
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # Define output file path
    output_file = os.path.join(output_folder, os.path.basename(input_file))

    try:
        # Compress video using the target bitrate
        video.write_videofile(
            output_file,
            codec="libx264",
            bitrate=f"{int(target_bitrate)}",
            audio_codec="aac",
            threads=4,
            preset="medium"
        )
        print(f"Compression completed: {output_file}")
    except Exception as e:
        print(f"An error occurred during compression: {e}")
    finally:
        video.close()

input_mp4 = "input_video.mp4"  # Replace with your MP4 file path
compress_mp4(input_mp4)
