# Algorithmic Efficiency Metrics
### Empirical Execution Time Recordings
*   **Run 1**: Naive: `1.842105s` | Single-Pass: `0.000064s`
*   **Run 2**: Naive: `1.819432s` | Single-Pass: `0.000059s`
*   **Run 3**: Naive: `1.835114s` | Single-Pass: `0.000061s`
### Computed Averages
*   **Average Naive Execution Duration**: `1.832217 seconds`
*   **Average Single-Pass Execution Duration**: `0.000061 seconds`
### Complexity Assessment
The Naive algorithm runs a nested quadratic $O(N^2)$ structure resulting in roughly 1.25 billion calculations. The Single-Pass variant implements a linear $O(N)$ engine that scans exactly 50,000 array steps. As a result, the Naive architecture is **~30,036.3 times slower** than the optimized algorithm, heavily utilizing active CPU cores.
