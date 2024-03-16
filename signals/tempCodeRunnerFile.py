
plt.subplot(5,1,1)
plt.stem(n,x)
plt.grid(True)
plt.xlabel('Sequence')
plt.ylabel('Amp')

plt.subplot(5,1,2)
plt.stem(n,y)
plt.grid(True)
plt.xlabel('Sequence')
plt.ylabel('Amp')

plt.subplot(5,1,3)
plt.stem(n,z)
plt.grid(True)
plt.xlabel('Sequence')
plt.ylabel('Amp')

plt.subplot(5,1,4)
plt.stem(n,mul)
plt.grid(True)
plt.xlabel('Sequence')
plt.ylabel('Amp')

plt.subplot(5,1,5)
plt.stem(n,fld)
plt.grid(True)
plt.xlabel('Sequence')
plt.ylabel('Amp')

plt.show()
