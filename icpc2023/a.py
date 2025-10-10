def count_prime_factors(num):
    # Helper function to count prime factors
    factors = set()
    while num % 2 == 0:
        factors.add(2)
        num //= 2
    for i in range(3, int(num**0.5) + 1, 2):
        while num % i == 0:
            factors.add(i)
            num //= i
    if num > 2:
        factors.add(num)
    return factors

def find_longest_subarray(A, K):
    left, right = 0, 0
    longest_subarray = (0, 0)
    prime_factor_count = {}

    while right < len(A):
        num = A[right]
        factors = count_prime_factors(num)

        for factor in factors:
            prime_factor_count[factor] = prime_factor_count.get(factor, 0) + 1

        while len(prime_factor_count) > K or any(v > 1 for v in prime_factor_count.values()):
            # If there are more than K prime factors or a perfect prime factor, move the left pointer
            left_num = A[left]
            left_factors = count_prime_factors(left_num)
            for factor in left_factors:
                prime_factor_count[factor] -= 1
                if prime_factor_count[factor] == 0:
                    del prime_factor_count[factor]
            left += 1

        if len(prime_factor_count) == K:
            # Update the longest subarray if the conditions are met
            if right - left > longest_subarray[1] - longest_subarray[0]:
                longest_subarray = (left, right)

        right += 1

    return A[longest_subarray[0]:longest_subarray[1] + 1]

# Example usage:
A = [3, 5, 12, 15, 21]
K = 3
result = find_longest_subarray(A, K)
print(result)  # This will print the longest subarray with 2 almost prime factors and no perfect prime factors.
