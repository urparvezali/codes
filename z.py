import wave
w = wave.open('wave.wav','r')

for i in range(w.getnframes()):
	frame = w.readframes(i)
	print(frame)
