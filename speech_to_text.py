#########################################################################################
# file: speech_to_text.py
# type: Python
# date: 01_NOVEMBER_2024
# author: karbytes
# license: PUBLIC_DOMAIN 
#########################################################################################
import speech_recognition as sr
from pydub import AudioSegment

def mp3_to_text():
    # Hardcoded file paths
    mp3_file_path = "input_audio.mp3"
    output_file_path = "output_text.txt"
    
    # Convert MP3 to WAV
    audio = AudioSegment.from_mp3(mp3_file_path)
    wav_file_path = "temp_audio.wav" # user can manually delete or keep the intermediary WAV file
    audio.export(wav_file_path, format="wav")

    # Initialize recognizer
    recognizer = sr.Recognizer()

    # Load the WAV file and transcribe it
    with sr.AudioFile(wav_file_path) as source:
        audio_data = recognizer.record(source)
        try:
            text = recognizer.recognize_google(audio_data)
            print("Transcription successful!")

            # Write transcription to a text file
            with open(output_file_path, "w") as text_file:
                text_file.write(text)

            print(f"Transcription saved to {output_file_path}")

        except sr.UnknownValueError:
            print("Could not understand audio")
        except sr.RequestError as e:
            print(f"Could not request results from Speech Recognition service; {e}")

if __name__ == "__main__":
    mp3_to_text()
