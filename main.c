#include <stdio.h>
#include "utils.c"
#include <stdlib.h>
#include <string.h> // important for git github understanding
#include <math.h>
#define MAX_SIZE 1000000
#define MAX_BINS 1000
#define MAX_STARS 50
double array[MAX_SIZE];
// global variable dec. 
double mean, max, min, stddev, median;
int size;
void help_command()
{
    printf("Commands:\n");
    printf("Set       -Set array size,seed, and distribution (uniform or gaussian)\n");
    printf("min       -Print minimum value \n");
    printf("max       -Print maximum value\n");
    printf("mean      -Print mean value \n");
    printf("stddev    -Print standard deviation\n");
    printf("hist      -Print histogram \n");
    printf("median    -Print median value\n");
    printf("summary   -Print min,max,mean,stddev,median\n");
    printf("help      -Show the help message \n");
    printf("exit      -Exit the loop \n");
}
// necessary for qsort double func
int comp(const void *a, const void *b)
{
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0) - (diff < 0);
}
int main()
{
    help_command();
    int set = 0;
    while (1)
    {
        char str1[12];
        // taking text input
        printf("Enter commands : ");
        scanf("%s", str1);
        // exit
        if (strcmp(str1, "exit") == 0)
            break;
        // help
        if (strcmp(str1, "help") == 0)
        {
            help_command();
            continue;
        }
        // input without setting value
        if ((strcmp(str1, "min") == 0 || strcmp(str1, "max") == 0 || strcmp(str1, "mean") == 0 || strcmp(str1, "stddev") == 0 || strcmp(str1, "hist") == 0 || strcmp(str1, "summary") == 0 || strcmp(str1, "median") == 0) && set == 0)
        {
            printf("Array not initialized. Use 'set' command first.\n\n");
            continue;
        }
        // set value seed size dibya 
        if (strcmp(str1, "set") == 0)
        {
            set = 1;
            unsigned int seed;
            char str2[12];
            printf("Enter number of elements (<=100000):\n");
            scanf("%d", &size);
            printf("Enter seed:\n");
            scanf("%u", &seed);
            // continuous distribuition until valid
            while (1)
            {
                printf("Distribution? (uniform/gaussian):\n");
                scanf("%s", str2);
                if (strcmp(str2, "gaussian") == 0)
                {
                    double mean1, stddev1;
                    printf("Enter mean and stddev:");
                    scanf("%lf%lf", &mean1, &stddev1);
                    printf("Array initialized with gaussian distribuiton\n");
                    populate_array_gaussian(array, size, mean1, stddev1, seed);
                    break;
                }

                else if (strcmp(str2, "uniform") == 0)
                {
                    double max1, min1;
                    printf("Enter min and max:\n");
                    scanf("%lf%lf", &min1, &max1);
                    printf("Array initialized with uniform distribuiton\n");
                    populate_array_uniform(array, size, min1, max1, seed);
                    break;
                }
                else
                    printf("Invalid distribuition\n");
            }

            // max min mean median stddev calculation
            double sum1 = 0;
            for (int i = 0; i < size; i++)
            {

                sum1 += array[i];
            }
            mean = sum1 / size;
            min = array[0];
            for (int i = 1; i < size; i++)
            {
                if (min > array[i])
                    min = array[i];
            }
            max = array[0];
            for (int i = 1; i < size; i++)
            {
                if (max < array[i])
                    max = array[i];
            }

            double sum2 = 0;
            for (int i = 0; i < size; i++)
            {
                sum2 += (array[i] - mean) * (array[i] - mean);
            }
            stddev = sqrt(sum2 / size);
            // array sorting using func
            qsort(array, size, sizeof(double), comp);

            if (size % 2 == 0)
            {
                median = (array[size / 2] + array[size / 2 - 1]) / 2;
            }
            else
                median = array[size / 2];
        }
        // output showing
        else if (strcmp(str1, "stddev") == 0)
            printf("Std Dev   :%.4lf\n\n", stddev);
        else if (strcmp(str1, "max") == 0)
            printf("Max        :%.4lf\n\n", max);
        else if (strcmp(str1, "min") == 0)
            printf("Min        :%.4lf\n\n", min);
        else if (strcmp(str1, "median") == 0)
            printf("Median     :%.4lf\n\n", median);
        else if (strcmp(str1, "mean") == 0)
            printf("Mean       :%.4lf\n\n", mean);
        else if (strcmp(str1, "summary") == 0)
        {
            printf("Min        :%.4lf\n", min);
            printf("Max        :%.4lf\n", max);
            printf("Mean       :%.4lf\n", mean);
            printf("Std Dev    :%.4lf\n", stddev);
            printf("Median     :%.4lf\n", median);
        }

        // histrogram....
        else if (strcmp(str1, "hist") == 0)
        {
            int bin_counts[MAX_BINS] = {0};
            int bins;
            // continus value taking until break
            while (1)
            {
                printf("Enter number of bins :");
                scanf("%d", &bins);
                if (bins >= 1 && bins <= MAX_BINS)
                {
                    double bin_width = (max - min) / bins;
                    // bin counting bin_count[0]=343,bin_count[1]=3212 ......
                    for (int i = 0; i < size; i++)
                    {
                        int bin_index = (int)((array[i] - min) / bin_width);
                        if (bin_index == bins)
                            bin_index = bins - 1;
                        bin_counts[bin_index]++;
                    }
                    // bin count max find
                    int bin_max = bin_counts[0];
                    for (int i = 1; i < bins; i++)
                    {
                        if (bin_counts[i] > bin_max)
                            bin_max = bin_counts[i];
                    }
                    // star print rescalling
                    for (int i = 0; i < bins; i++)
                    {
                        printf("[%10.2lf - %10.2lf]: ", min + i * bin_width, min + (i + 1) * bin_width);
                        int stars = (bin_counts[i] * MAX_STARS) / bin_max;
                        for (int j = 0; j < stars; j++)
                            printf("*");
                        printf("\n");
                    }
                    break;
                }
                else
                {
                    printf("Invalid number of bins\n");
                }
            }
        }
        else
            printf("Unknown command. Type 'help' for list of commands.\n\n");
    }
    return 0;
}
