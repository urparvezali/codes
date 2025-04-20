import numpy as np
import matplotlib.pyplot as plt
from PIL import Image


def load_grayscale_image(image_path):
    """Load an image and convert it to grayscale numpy array"""
    img = Image.open(image_path).convert("L")
    return np.array(img)


def manual_convolution(image, kernel):
    """Apply convolution manually using loops"""
    # Get dimensions
    img_height, img_width = image.shape
    kernel_height, kernel_width = kernel.shape

    # Calculate padding size
    pad_h = kernel_height // 2
    pad_w = kernel_width // 2

    # Create output array with same dimensions as input
    output = np.zeros_like(image, dtype=np.float64)

    # Pad the input image
    padded_image = np.pad(image, ((pad_h, pad_h), (pad_w, pad_w)), mode="reflect")

    # Perform convolution
    for i in range(img_height):
        for j in range(img_width):
            # Extract the region of interest
            region = padded_image[i : i + kernel_height, j : j + kernel_width]
            # Apply the kernel
            output[i, j] = np.sum(region * kernel)

    return output


def manual_sobel(image):
    """Apply Sobel edge detection manually"""
    # Define Sobel kernels
    sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])

    sobel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

    # Apply both kernels
    gradient_x = manual_convolution(image, sobel_x)
    gradient_y = manual_convolution(image, sobel_y)

    # Calculate gradient magnitude
    gradient_magnitude = np.sqrt(gradient_x**2 + gradient_y**2)

    # Normalize to 0-255
    gradient_magnitude = gradient_magnitude * 255.0 / np.max(gradient_magnitude)

    return gradient_magnitude.astype(np.uint8)


def manual_prewitt(image):
    """Apply Prewitt edge detection manually"""
    # Define Prewitt kernels
    prewitt_x = np.array([[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]])

    prewitt_y = np.array([[-1, -1, -1], [0, 0, 0], [1, 1, 1]])

    # Apply both kernels
    gradient_x = manual_convolution(image, prewitt_x)
    gradient_y = manual_convolution(image, prewitt_y)

    # Calculate gradient magnitude
    gradient_magnitude = np.sqrt(gradient_x**2 + gradient_y**2)

    # Normalize to 0-255
    gradient_magnitude = gradient_magnitude * 255.0 / np.max(gradient_magnitude)

    return gradient_magnitude.astype(np.uint8)


def manual_gaussian_blur(image, kernel_size=5, sigma=1.0):
    """Apply Gaussian blur manually"""
    # Create Gaussian kernel
    k = kernel_size // 2
    x, y = np.mgrid[-k : k + 1, -k : k + 1]
    kernel = np.exp(-(x**2 + y**2) / (2 * sigma**2))
    kernel = kernel / kernel.sum()

    # Apply convolution
    return manual_convolution(image, kernel)


def manual_canny(image, low_threshold=50, high_threshold=150):
    """Apply Canny edge detection manually"""
    # Step 1: Apply Gaussian blur
    blurred = manual_gaussian_blur(image)

    # Step 2: Calculate gradient magnitude and direction using Sobel
    sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    sobel_y = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])

    gradient_x = manual_convolution(blurred, sobel_x)
    gradient_y = manual_convolution(blurred, sobel_y)

    gradient_magnitude = np.sqrt(gradient_x**2 + gradient_y**2)
    gradient_direction = np.arctan2(gradient_y, gradient_x) * 180 / np.pi

    # Normalize gradient magnitude to 0-255
    gradient_magnitude = gradient_magnitude * 255.0 / np.max(gradient_magnitude)
    gradient_magnitude = gradient_magnitude.astype(np.uint8)

    # Step 3: Non-maximum suppression
    height, width = gradient_magnitude.shape
    suppressed = np.zeros_like(gradient_magnitude)

    for i in range(1, height - 1):
        for j in range(1, width - 1):
            # Get the angle and round to one of four directions (0, 45, 90, 135)
            angle = gradient_direction[i, j]
            if angle < 0:
                angle += 180

            # Check if pixel is a local maximum in the gradient direction
            if (0 <= angle < 22.5) or (157.5 <= angle <= 180):
                # Horizontal direction
                if (
                    gradient_magnitude[i, j] >= gradient_magnitude[i, j - 1]
                    and gradient_magnitude[i, j] >= gradient_magnitude[i, j + 1]
                ):
                    suppressed[i, j] = gradient_magnitude[i, j]
            elif 22.5 <= angle < 67.5:
                # Diagonal (top-right to bottom-left)
                if (
                    gradient_magnitude[i, j] >= gradient_magnitude[i - 1, j + 1]
                    and gradient_magnitude[i, j] >= gradient_magnitude[i + 1, j - 1]
                ):
                    suppressed[i, j] = gradient_magnitude[i, j]
            elif 67.5 <= angle < 112.5:
                # Vertical direction
                if (
                    gradient_magnitude[i, j] >= gradient_magnitude[i - 1, j]
                    and gradient_magnitude[i, j] >= gradient_magnitude[i + 1, j]
                ):
                    suppressed[i, j] = gradient_magnitude[i, j]
            else:
                # Diagonal (top-left to bottom-right)
                if (
                    gradient_magnitude[i, j] >= gradient_magnitude[i - 1, j - 1]
                    and gradient_magnitude[i, j] >= gradient_magnitude[i + 1, j + 1]
                ):
                    suppressed[i, j] = gradient_magnitude[i, j]

    # Step 4: Double threshold and hysteresis
    result = np.zeros_like(suppressed)

    # Strong edges
    strong_edges = suppressed >= high_threshold
    # Weak edges
    weak_edges = (suppressed >= low_threshold) & (suppressed < high_threshold)

    # Initialize result with strong edges
    result[strong_edges] = 255

    # Find connected weak edges
    for i in range(1, height - 1):
        for j in range(1, width - 1):
            if weak_edges[i, j]:
                # Check 8-connected neighbors
                if result[i - 1 : i + 2, j - 1 : j + 2].max() == 255:
                    result[i, j] = 255

    return result


def apply_manual_edge_detection(image_path):
    """Apply manual edge detection techniques and display results"""
    # Load image
    image = load_grayscale_image(image_path)

    # Apply edge detection techniques
    sobel_edges = manual_sobel(image)
    prewitt_edges = manual_prewitt(image)
    canny_edges = manual_canny(image)

    # Display results
    plt.figure(figsize=(15, 10))

    plt.subplot(2, 2, 1)
    plt.title("Original Image")
    plt.imshow(image, cmap="gray")
    plt.axis("off")

    plt.subplot(2, 2, 2)
    plt.title("Manual Sobel Operator")
    plt.imshow(sobel_edges, cmap="gray")
    plt.axis("off")

    plt.subplot(2, 2, 3)
    plt.title("Manual Prewitt Operator")
    plt.imshow(prewitt_edges, cmap="gray")
    plt.axis("off")

    plt.subplot(2, 2, 4)
    plt.title("Manual Canny Edge Detector")
    plt.imshow(canny_edges, cmap="gray")
    plt.axis("off")

    plt.tight_layout()
    plt.show()

    return {
        "original": image,
        "sobel": sobel_edges,
        "prewitt": prewitt_edges,
        "canny": canny_edges,
    }


# Example usage
if __name__ == "__main__":
    # Replace with the path to your image
    image_path = "/home/parvez/Pictures/IMG20241206102234-01~3.jpeg"
    results = apply_manual_edge_detection(image_path)
