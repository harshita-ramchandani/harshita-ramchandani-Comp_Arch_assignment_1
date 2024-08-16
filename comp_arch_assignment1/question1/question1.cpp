#include <iostream>
#include <vector>
#include <ctime>

// a. Recursive Fibonacci
long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// b. Iterative Fibonacci
void fibonacci_loop(int n) {
    long long a = 0, b = 1, c;
    // std::cout << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        c = a + b;
        // std::cout << c << " ";
        a = b;
        b = c;
    }
    std::cout << std::endl;
}

// c. Recursive Fibonacci with Memoization
long long fibonacci_recursive_memo(int n, std::vector<long long>& memo) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fibonacci_recursive_memo(n - 1, memo) + fibonacci_recursive_memo(n - 2, memo);
    return memo[n];
}

// d. Iterative Fibonacci with Memoization
void fibonacci_loop_memo(int n) {
    std::vector<long long> memo(n, 0);
    memo[0] = 0;
    memo[1] = 1;
    // std::cout << memo[0] << " " << memo[1] << " ";
    for (int i = 2; i < n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
        // std::cout << memo[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    struct timespec start, end;
    
    // Time the recursive method
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; i++) {
        fibonacci_recursive(i);
    }
    std::cout << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_recursive = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    std::cout << "Time taken by recursive method: " << time_recursive << " seconds" << std::endl;
    
    // Time the iterative method
    clock_gettime(CLOCK_MONOTONIC, &start);
    fibonacci_loop(50);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_loop = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    std::cout << "Time taken by iterative method: " << time_loop << " seconds" << std::endl;

    // Time the recursive method with memoization
    clock_gettime(CLOCK_MONOTONIC, &start);
    std::vector<long long> memo(50, -1);
    for (int i = 0; i < 50; i++) {
        fibonacci_recursive_memo(i, memo);
    }
    std::cout << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_recursive_memo = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    std::cout << "Time taken by recursive method with memoization: " << time_recursive_memo << " seconds" << std::endl;

    // Time the iterative method with memoization
    clock_gettime(CLOCK_MONOTONIC, &start);
    fibonacci_loop_memo(50);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_loop_memo = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    std::cout << "Time taken by iterative method with memoization: " << time_loop_memo << " seconds" << std::endl;

    double speedup_loop = time_recursive / time_loop;
    double speedup_recursive_memo = time_recursive / time_recursive_memo;
    double speedup_loop_memo = time_recursive / time_loop_memo;

    std::cout << "Speedup of iterative method: " << speedup_loop << std::endl;
    std::cout << "Speedup of recursive method with memoization: " << speedup_recursive_memo << std::endl;
    std::cout << "Speedup of iterative method with memoization: " << speedup_loop_memo << std::endl;

    return 0;
}
