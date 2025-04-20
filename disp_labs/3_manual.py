import cv2
import numpy as np
import matplotlib.pyplot as plt


def manual_erode(image, kernel):
    h, w = image.shape
    kh, kw = kernel.shape
    pad_h, pad_w = kh // 2, kw // 2

    padded = np.pad(
        image, ((pad_h, pad_h), (pad_w, pad_w)), mode="constant", constant_values=0
    )
    result = np.zeros_like(image)

    for i in range(h):
        for j in range(w):
            region = padded[i : i + kh, j : j + kw]
            if np.all(region[kernel == 1] == 255):
                result[i, j] = 255
    return result


def manual_dilate(image, kernel):
    h, w = image.shape
    kh, kw = kernel.shape
    pad_h, pad_w = kh // 2, kw // 2

    padded = np.pad(
        image, ((pad_h, pad_h), (pad_w, pad_w)), mode="constant", constant_values=0
    )
    result = np.zeros_like(image)

    for i in range(h):
        for j in range(w):
            region = padded[i : i + kh, j : j + kw]
            if np.any(region[kernel == 1] == 255):
                result[i, j] = 255
    return result


def manual_open(image, kernel):
    return manual_dilate(manual_erode(image, kernel), kernel)


def manual_close(image, kernel):
    return manual_erode(manual_dilate(image, kernel), kernel)


# Create binary noisy image
image = np.zeros((256, 256), dtype=np.uint8)
cv2.rectangle(image, (60, 60), (180, 180), 255, -1)
noise = np.random.randint(0, 2, (256, 256), dtype=np.uint8) * 255
noisy_image = cv2.bitwise_or(image, noise)

# Structuring element
kernel = np.ones((3, 3), np.uint8)

# Apply manual operations
erosion = manual_erode(noisy_image, kernel)
dilation = manual_dilate(noisy_image, kernel)
opening = manual_open(noisy_image, kernel)
closing = manual_close(noisy_image, kernel)

# Show all results
titles = [
    "Original (Noisy)",
    "Manual Erosion",
    "Manual Dilation",
    "Manual Opening",
    "Manual Closing",
]
images = [noisy_image, erosion, dilation, opening, closing]

plt.figure(figsize=(12, 6))
for i in range(len(images)):
    plt.subplot(2, 3, i + 1)
    plt.imshow(images[i], cmap="gray")
    plt.title(titles[i])
    plt.axis("off")
plt.tight_layout()
plt.show()
