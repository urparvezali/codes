import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

# Function to generate a continuous-time sine wave


def generate_continuous_signal(frequency, amplitude, duration, sampling_rate):
    t = np.linspace(0, duration, int(sampling_rate * duration), endpoint=False)
    signal = amplitude * np.sin(2 * np.pi * frequency * t)
    return t, signal

# Function to sample a signal


def sample_signal(t, signal, sampling_rate):
    sampling_interval = int(len(t) // (sampling_rate * max(t)))
    sampled_t = t[::sampling_interval]
    sampled_signal = signal[::sampling_interval]
    return sampled_t, sampled_signal

# Function to reconstruct the signal using linear interpolation


def reconstruct_signal(sampled_t, sampled_signal, t_original):
    interp_func = interp1d(sampled_t, sampled_signal,
                           kind='linear', fill_value="extrapolate")
    reconstructed_signal = interp_func(t_original)
    return reconstructed_signal


# Define parameters
frequency = 5  # Signal frequency in Hz
amplitude = 1  # Signal amplitude
duration = 2   # Duration of the signal in seconds
continuous_sampling_rate = 1000  # Sampling rate for continuous signal

# Generate continuous signal
t_continuous, signal_continuous = generate_continuous_signal(
    frequency, amplitude, duration, continuous_sampling_rate)

# Sample the signal at different rates
below_nyquist_rate = 8  # Below Nyquist rate (should cause aliasing)
nyquist_rate = 10       # Nyquist rate (2 times the frequency)
above_nyquist_rate = 20  # Above Nyquist rate

# Sampling the signal at different rates
sampled_t_below, sampled_signal_below = sample_signal(
    t_continuous, signal_continuous, below_nyquist_rate)
sampled_t_nyquist, sampled_signal_nyquist = sample_signal(
    t_continuous, signal_continuous, nyquist_rate)
sampled_t_above, sampled_signal_above = sample_signal(
    t_continuous, signal_continuous, above_nyquist_rate)

# Reconstruct the signal from samples using linear interpolation
reconstructed_signal_below = reconstruct_signal(
    sampled_t_below, sampled_signal_below, t_continuous)
reconstructed_signal_nyquist = reconstruct_signal(
    sampled_t_nyquist, sampled_signal_nyquist, t_continuous)
reconstructed_signal_above = reconstruct_signal(
    sampled_t_above, sampled_signal_above, t_continuous)

# Plotting the original, sampled, and reconstructed signals
plt.figure(figsize=(15, 12))

# Plot continuous signal
plt.subplot(3, 1, 1)
plt.plot(t_continuous, signal_continuous,
         label="Original Continuous Signal", color='gray', linestyle='--')
plt.scatter(sampled_t_below, sampled_signal_below, color='red',
            label="Sampled (Below Nyquist)", zorder=3)
plt.plot(t_continuous, reconstructed_signal_below,
         label="Reconstructed (Below Nyquist)", color='blue')
plt.title("Sampling and Reconstruction (Below Nyquist)")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.legend()
plt.grid(True)

# Plot Nyquist sampling and reconstruction
plt.subplot(3, 1, 2)
plt.plot(t_continuous, signal_continuous,
         label="Original Continuous Signal", color='gray', linestyle='--')
plt.scatter(sampled_t_nyquist, sampled_signal_nyquist,
            color='red', label="Sampled (Nyquist Rate)", zorder=3)
plt.plot(t_continuous, reconstructed_signal_nyquist,
         label="Reconstructed (Nyquist Rate)", color='blue')
plt.title("Sampling and Reconstruction (At Nyquist Rate)")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.legend()
plt.grid(True)

# Plot above Nyquist sampling and reconstruction
plt.subplot(3, 1, 3)
plt.plot(t_continuous, signal_continuous,
         label="Original Continuous Signal", color='gray', linestyle='--')
plt.scatter(sampled_t_above, sampled_signal_above, color='red',
            label="Sampled (Above Nyquist)", zorder=3)
plt.plot(t_continuous, reconstructed_signal_above,
         label="Reconstructed (Above Nyquist)", color='blue')
plt.title("Sampling and Reconstruction (Above Nyquist Rate)")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()
