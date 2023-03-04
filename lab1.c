#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

// heap sort

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;

}
  
void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {

        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);

    }

  }
  
  
void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  

    for (int i = n - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);

    }

}

// end heap sort


// selection sort

void swap2(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;

}

void selectionSort(int array[], int size) {

    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;

        }

        swap2(&array[min_idx], &array[step]);

    }
    
}

// end selection sort


// radix sort 

int getMax(int array[], int n) {

    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;

}

void countingSort(int array[], int size, int place) {

    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++) {

        if (((array[i] / place) % 10) > max)
            max = array[i];

    }

    int count[max + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {

        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;

    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];

}

void radixsort(int array[], int size) {

    int max = getMax(array, size);


    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);

}

// end radix sort


int RandNum(){

    int num;
    num = rand() % 10000;
    return num;

}

double wtime(){

    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;

}

int main() {
    
    int s = 100000;
    printf("\n%d elements:\n\n", s);
    int array[s];
    for(int i = 0; i < s; i++)
        array[i] = RandNum();
    int n = sizeof(array) / sizeof(array[0]);

    double sTime = wtime();
    radixsort(array, n);
    double endTime = wtime() - sTime;
    printf("radix sort: %lf\n", endTime);

    double sTime2 = wtime();
    selectionSort(array, n);
    double endTime2 = wtime() - sTime2;
    printf("selection sort: %lf\n", endTime2);

    double sTime3 = wtime();
    heapSort(array, n);
    double endTime3 = wtime() - sTime3;
    printf("heap sort: %lf\n\n", endTime3);

}