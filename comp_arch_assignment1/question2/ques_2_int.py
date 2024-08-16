import time

# Function to multiply matrices without NumPy
def multiply_matrices(A, B, N):
    # Initialize the result matrix with zeros
    C = [[0 for _ in range(N)] for _ in range(N)]
    
    # Perform matrix multiplication
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    
    return C

# List of N values to iterate through
N_values = [64, 128, 256, 512, 1024]

for N in N_values:
    print(f"\nMatrix size: {N}x{N}")

    # Integer matrix multiplication
    A = [[1 for _ in range(N)] for _ in range(N)]
    B = [[2 for _ in range(N)] for _ in range(N)]

    # Measure wall-clock time and CPU time
    start_time = time.time()

    # Perform matrix multiplication
    C = multiply_matrices(A, B, N)

    end_time = time.time()
    

    print(f"Time taken by integer matrix multiplication: {end_time - start_time:.6f} seconds (Execution Time)")

    # Double matrix multiplication
    A = [[1.0 for _ in range(N)] for _ in range(N)]
    B = [[2.0 for _ in range(N)] for _ in range(N)]

    # Measure wall-clock time and CPU time
    start_time = time.time()
    

    # Perform matrix multiplication
    C = multiply_matrices(A, B, N)

    end_time = time.time()

    print(f"Time taken by double matrix multiplication: {end_time - start_time:.6f} seconds (Execution Time)")