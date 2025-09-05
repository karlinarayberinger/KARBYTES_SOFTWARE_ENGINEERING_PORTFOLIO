#########################################################################################
# file: mp4_to_mp3.py
# type: Python
# date: 01_NOVEMBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################
from moviepy.editor import VideoFileClip
import os

def mp4_to_mp3(input_file, output_folder="output"):
    # Check if input file exists and is an MP4
    if not os.path.isfile(input_file) or not input_file.endswith('.mp4'):
        print("Please provide a valid MP4 file.")
        return

    # Create output folder if it doesn't exist
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # Extract base filename without extension
    base_filename = os.path.splitext(os.path.basename(input_file))[0]
    output_file = os.path.join(output_folder, f"{base_filename}.mp3")

    # Load the video file and extract audio
    try:
        video_clip = VideoFileClip(input_file)
        audio_clip = video_clip.audio
        audio_clip.write_audiofile(output_file)
        print(f"Successfully converted {input_file} to {output_file}")
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        # Release resources
        video_clip.close()
        if audio_clip:
            audio_clip.close()

input_mp4 = "input_video.mp4"  # Replace with your MP4 file path
mp4_to_mp3(input_mp4)
