def find_original_array(B):
    N = len(B) // 2
    A = [0] * (2 * N)
    
    # Sort B in descending order
    B.sort(reverse=True)
    
    # Split B into positive and negative parts
    positive_part = [x for x in B if x > 0]
    negative_part = [x for x in B if x < 0]
    
    # Merge positive and negative parts into A
    for i in range(N):
        A[i] = positive_part[i] + negative_part[i]
        A[i + N] = positive_part[i] - negative_part[i]
    
    return A

# Example usage:
B = [5, 2, -3, -1, 8, -4]
result = find_original_array(B)

if result == -1:
    print(-1)
else:
    print(result)
