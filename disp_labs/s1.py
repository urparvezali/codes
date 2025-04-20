import numpy as np
import pyaudio
import webrtcvad
import speech_recognition as sr


class RealTimeASR:
    def __init__(self):
        self.vad = webrtcvad.Vad(3)  # Aggressive mode
        self.recognizer = sr.Recognizer()
        self.audio = pyaudio.PyAudio()
        self.sample_rate = 16000
        self.frame_duration = 30  # ms
        self.frame_size = int(self.sample_rate * self.frame_duration / 1000)
        self.silence_threshold = 500
        self.buffer = []

    def is_speech(self, frame):
        """VAD using energy and WebRTC"""
        # Energy check
        rms = np.sqrt(np.mean(np.frombuffer(frame, dtype=np.int16) ** 2))
        if rms < self.silence_threshold:
            return False
        # WebRTC VAD check
        return self.vad.is_speech(frame, self.sample_rate)

    def process_frame(self, frame):
        if self.is_speech(frame):
            self.buffer.append(frame)
            if len(self.buffer) > 10:  # ~300ms buffer
                audio_data = sr.AudioData(b"".join(self.buffer), self.sample_rate, 2)
                try:
                    text = self.recognizer.recognize_google(audio_data)
                    print(f"\rRecognized: {text}", end="", flush=True)
                except Exception as e:
                    print(f"\rRecognition error: {str(e)}", end="")
                self.buffer = []
        else:
            if len(self.buffer) > 0:
                self.buffer = []  # Reset on silence

    def run(self):
        stream = self.audio.open(
            format=pyaudio.paInt16,
            channels=1,
            rate=self.sample_rate,
            input=True,
            frames_per_buffer=self.frame_size,
        )
        print("Real-time ASR started. Press Ctrl+C to stop.")
        try:
            while True:
                frame = stream.read(self.frame_size, exception_on_overflow=False)
                self.process_frame(frame)
        except KeyboardInterrupt:
            print("\nStopping...")
        finally:
            stream.stop_stream()
            stream.close()
            self.audio.terminate()


if __name__ == "__main__":
    asr = RealTimeASR()
    asr.run()
