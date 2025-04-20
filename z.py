import cv2
import numpy as np
import matplotlib.pyplot as plt

# --- 1. Create a Sample Low-Contrast Grayscale Image ---
# We create a synthetic image instead of loading one, so the code is runnable anywhere.
# This image will have pixel values concentrated in the middle gray range.
height, width = 256, 256
low_contrast_img = np.zeros((height, width), dtype=np.uint8)

# Create a gradient patch with low contrast (e.g., values from 80 to 180)
start_val = 80
end_val = 180
for i in range(height):
    for j in range(width):
        # Simple gradient based on distance from corner, scaled to low contrast range
        dist = np.sqrt(i**2 + j**2)
        max_dist = np.sqrt(height**2 + width**2)
        pixel_val = start_val + int((dist / max_dist) * (end_val - start_val))
        low_contrast_img[i, j] = pixel_val

# --- 2. Apply Global Histogram Equalization (HE) ---
he_img = cv2.equalizeHist(low_contrast_img)

# --- 3. Apply Contrast Limited Adaptive Histogram Equalization (CLAHE) ---
# Create a CLAHE object (Arguments are optional but shown for clarity)
# clipLimit: Threshold for contrast limiting. Higher values mean more contrast.
# tileGridSize: Size of grid for localized equalization.
clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
clahe_img = clahe.apply(low_contrast_img)

# --- 4. Calculate Histograms for Comparison ---
# Parameters for calcHist: [image], [channel], mask, [histSize], [ranges]
hist_original = cv2.calcHist([low_contrast_img], [0], None, [256], [0, 256])
hist_he = cv2.calcHist([he_img], [0], None, [256], [0, 256])
hist_clahe = cv2.calcHist([clahe_img], [0], None, [256], [0, 256])

# --- 5. Display Images and Histograms using Matplotlib ---
plt.style.use('seaborn-v0_8-darkgrid') # Use a nice style
fig, axs = plt.subplots(2, 3, figsize=(15, 8)) # 2 rows, 3 columns

# Row 1: Images
axs[0, 0].imshow(low_contrast_img, cmap='gray', vmin=0, vmax=255)
axs[0, 0].set_title('Original Low Contrast')
axs[0, 0].axis('off') # Hide axes ticks

axs[0, 1].imshow(he_img, cmap='gray', vmin=0, vmax=255)
axs[0, 1].set_title('Global HE Result')
axs[0, 1].axis('off')

axs[0, 2].imshow(clahe_img, cmap='gray', vmin=0, vmax=255)
axs[0, 2].set_title('CLAHE Result')
axs[0, 2].axis('off')

# Row 2: Histograms (Changed to Stem Plots)
# Note: .flatten() is used because calcHist returns a 2D array (shape [256, 1])
# and stem plot usually expects 1D data.
axs[1, 0].stem(hist_original.flatten(), linefmt='b-', markerfmt=' ', basefmt=" ") # Blue stems
axs[1, 0].set_title('Original Histogram (Stem)')
axs[1, 0].set_xlim([0, 256])
axs[1, 0].set_xlabel('Pixel Intensity')
axs[1, 0].set_ylabel('Frequency')

axs[1, 1].stem(hist_he.flatten(), linefmt='g-', markerfmt=' ', basefmt=" ") # Green stems
axs[1, 1].set_title('Global HE Histogram (Stem)')
axs[1, 1].set_xlim([0, 256])
axs[1, 1].set_xlabel('Pixel Intensity')


axs[1, 2].stem(hist_clahe.flatten(), linefmt='r-', markerfmt=' ', basefmt=" ") # Red stems
axs[1, 2].set_title('CLAHE Histogram (Stem)')
axs[1, 2].set_xlim([0, 256])
axs[1, 2].set_xlabel('Pixel Intensity')


# Adjust layout and show plot
plt.tight_layout()
plt.show()

print("Displayed original image, HE image, CLAHE image, and their histograms using STEM plots.")
print("Observe how HE spreads the histogram across the full range.")
print("Observe how CLAHE also enhances contrast, potentially more naturally,")
print("and its histogram reflects the local adjustments.")

