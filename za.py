import numpy as np
import math

class ManualMeanFilter:

    def apply(self, image: np.ndarray, kernel_size: tuple[int, int]) -> np.ndarray:
        kh, kw = kernel_size
        if kh % 2 == 0 or kw % 2 == 0:
            raise ValueError("Kernel dimensions must be odd integers.")

        if image.ndim == 3:
            h, w, c = image.shape
        elif image.ndim == 2:
            h, w = image.shape
            c = 1
            image = image[..., np.newaxis]
        else:
            raise ValueError("Input image must be 2D (grayscale) or 3D (BGR).")

        pad_h = kh // 2
        pad_w = kw // 2

        padded_image = np.pad(image, ((pad_h, pad_h), (pad_w, pad_w), (0, 0)), mode='edge')

        output_image = np.zeros_like(image, dtype=np.float64)

        for y in range(h):
            for x in range(w):
                for channel in range(c):
                    neighborhood = padded_image[y:y + kh, x:x + kw, channel]
                    mean_val = np.mean(neighborhood)
                    output_image[y, x, channel] = mean_val

        if c == 1:
            output_image = output_image.squeeze(axis=2)

        return np.clip(output_image, 0, 255).astype(image.dtype)
 

class ManualMedianFilter:

    def apply(self, image: np.ndarray, kernel_size: int) -> np.ndarray:
        if kernel_size % 2 == 0:
            raise ValueError("Kernel size must be an odd integer.")

        if image.ndim == 3:
            h, w, c = image.shape
        elif image.ndim == 2:
            h, w = image.shape
            c = 1
            image = image[..., np.newaxis]
        else:
            raise ValueError("Input image must be 2D (grayscale) or 3D (BGR).")

        pad = kernel_size // 2

        padded_image = np.pad(image, ((pad, pad), (pad, pad), (0, 0)), mode='edge')

        output_image = np.zeros_like(image)

        for y in range(h):
            for x in range(w):
                for channel in range(c):
                    neighborhood = padded_image[y:y + kernel_size, x:x + kernel_size, channel]
                    median_val = np.median(neighborhood)
                    output_image[y, x, channel] = median_val

        if c == 1:
            output_image = output_image.squeeze(axis=2)

        return output_image.astype(image.dtype)


class ManualGaussianFilter:

    def _gaussian_kernel(self, kernel_size: tuple[int, int], sigma: float) -> np.ndarray:
        kh, kw = kernel_size
        if kh % 2 == 0 or kw % 2 == 0:
            raise ValueError("Kernel dimensions must be odd integers.")

        center_h = kh // 2
        center_w = kw // 2
        kernel = np.zeros((kh, kw), dtype=np.float64)
        sigma_sq = sigma * sigma
        coeff = 1 / (2 * math.pi * sigma_sq)

        for y in range(kh):
            for x in range(kw):
                dy = y - center_h
                dx = x - center_w
                exponent = -(dx**2 + dy**2) / (2 * sigma_sq)
                kernel[y, x] = coeff * math.exp(exponent)

        kernel /= np.sum(kernel)
        return kernel

    def apply(self, image: np.ndarray, kernel_size: tuple[int, int], sigma: float) -> np.ndarray:
        kh, kw = kernel_size
        if kh % 2 == 0 or kw % 2 == 0:
            raise ValueError("Kernel dimensions must be odd integers.")

        kernel = self._gaussian_kernel(kernel_size, sigma)

        if image.ndim == 3:
            h, w, c = image.shape
        elif image.ndim == 2:
            h, w = image.shape
            c = 1
            image = image[..., np.newaxis]
        else:
            raise ValueError("Input image must be 2D (grayscale) or 3D (BGR).")

        pad_h = kh // 2
        pad_w = kw // 2

        padded_image = np.pad(image, ((pad_h, pad_h), (pad_w, pad_w), (0, 0)), mode='edge')

        output_image = np.zeros_like(image, dtype=np.float64)

        for y in range(h):
            for x in range(w):
                for channel in range(c):
                    neighborhood = padded_image[y:y + kh, x:x + kw, channel]
                    filtered_val = np.sum(neighborhood * kernel)
                    output_image[y, x, channel] = filtered_val

        if c == 1:
            output_image = output_image.squeeze(axis=2)

        return np.clip(output_image, 0, 255).astype(image.dtype)

# Example usage section removed as it was mostly comments