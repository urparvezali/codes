import cv2
import matplotlib.pyplot as plt

# Load grayscale image
image = cv2.imread("stdimgs/lena.bmp", cv2.IMREAD_GRAYSCALE)
image = cv2.resize(image, (256, 256))  # Optional resizing

# Global thresholding using Otsu’s method
_, otsu_thresh = cv2.threshold(image, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

# Adaptive Mean Thresholding
adaptive_mean = cv2.adaptiveThreshold(
    image, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 11, 2
)

# Adaptive Gaussian Thresholding
adaptive_gaussian = cv2.adaptiveThreshold(
    image, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2
)

# Display results
titles = [
    "Original Image",
    "Otsu's Global Threshold",
    "Adaptive Mean Threshold",
    "Adaptive Gaussian Threshold",
]
images = [image, otsu_thresh, adaptive_mean, adaptive_gaussian]

plt.figure(figsize=(10, 8))
for i in range(4):
    plt.subplot(2, 2, i + 1)
    plt.imshow(images[i], cmap="gray")
    plt.title(titles[i])
    plt.axis("off")
plt.tight_layout()
plt.show()
