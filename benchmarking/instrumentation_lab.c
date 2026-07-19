#include <stdio.h>
#include <time.h>
#define DATASET_SIZE 50000
#define SEED_VALUE 42u
static int dataset[DATASET_SIZE];
static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}
static void build_dataset(void)
{
    unsigned int state = SEED_VALUE;
    int i;
    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}
static void process_dataset(void)
{
    int i, v;
    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}
static unsigned long reduce_checksum(void)
{
    unsigned long sum = 0;
    int i;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];
    return sum;
}
int main(void)
{
    unsigned long checksum;
    clock_t t_start, t_end, b_start, b_end, p_start, p_end, r_start, r_end;
    double elapsed_total, elapsed_build, elapsed_process, elapsed_reduce;
    t_start = clock();
    b_start = clock();
    build_dataset();
    b_end = clock();
    p_start = clock();
    process_dataset();
    p_end = clock();
    r_start = clock();
    checksum = reduce_checksum();
    r_end = clock();
    t_end = clock();
    if (checksum == 0ul)
        printf("impossible\n");
    elapsed_total = (double)(t_end - t_start) / (double)CLOCKS_PER_SEC;
    elapsed_build = (double)(b_end - b_start) / (double)CLOCKS_PER_SEC;
    elapsed_process = (double)(p_end - p_start) / (double)CLOCKS_PER_SEC;
    elapsed_reduce = (double)(r_end - r_start) / (double)CLOCKS_PER_SEC;
    printf("TOTAL seconds: %.6f\n", elapsed_total);
    printf("BUILD_DATA seconds: %.6f\n", elapsed_build);
    printf("PROCESS seconds: %.6f\n", elapsed_process);
    printf("REDUCE seconds: %.6f\n", elapsed_reduce);
    return 0;
}
