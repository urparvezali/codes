def factorial_mod(n, x):
    """Compute n! % x using modular arithmetic."""
    result = 1
    for i in range(2, x + 1):
        result = (result * i) % x
    return result

def solve():
    t = int(input())  # Number of test cases
    results = []
    
    for _ in range(t):
        n, d = map(int, input().split())
        divisors = []
        
        for x in [1, 3, 5, 7, 9]:
            if n >= 5:
                # For n >= 5, n! is divisible by x (if x divides d)
                if d % x == 0:
                    divisors.append(x)
            else:
                # For n < 5, explicitly calculate n!
                n_fact_mod_x = factorial_mod(n, x)
                if (d * n_fact_mod_x) % x == 0:
                    divisors.append(x)
        
        print(*divisors)
    

# Example usage
solve()
