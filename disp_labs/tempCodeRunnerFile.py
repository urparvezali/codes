plt.imshow(np.log(np.abs(f)), cmap="gray"), plt.title("FFT without shift")
plt.show()
plt.imshow(np.log(np.abs(fshift)), cmap="gray"), plt.title("FFT with shift")
plt.show()