#include <iostream>
#include <vector>
#include <ctime>

// Function to multiply matrices
template <typename T>
void multiplyMatrices(const std::vector<std::vector<T> >& A, const std::vector<std::vector<T> >& B, std::vector<std::vector<T> >& C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Define the set of values for N
    int sizes[] = {64, 128, 256, 512, 1024};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < num_sizes; s++) {
        int N = sizes[s];
        std::cout << "Matrix size: " << N << "x" << N << std::endl;

        // Define matrices
        std::vector<std::vector<int> > A(N, std::vector<int>(N, 1));
        std::vector<std::vector<int> > B(N, std::vector<int>(N, 2));
        std::vector<std::vector<int> > C(N, std::vector<int>(N, 0));

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Perform matrix multiplication
        multiplyMatrices(A, B, C, N);

        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        std::cout << "Time taken by matrix multiplication: " << time_taken << " seconds" << std::endl;
        std::cout << std::endl;  // Add a newline for better readability
    }

    return 0;
}
