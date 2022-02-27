# _[Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)_

## 1. [Sorting Algorithms](#1)
### 1.1 [Selection Sort](#11)
### 1.2 [Bubble Sort](#12)
### 1.3 [Recursive Bubble Sort](#13)
### 1.4 [Insertion Sort](#14)
### 1.5 [Recursive Insertion Sort](#15)
### 1.6 [Merge Sort](#16)
### 1.7 [Iterative Merge Sort](#17)
### 1.8 [Quick Sort](#)
### 1.9 [Iterative Quick Sort](#)
### 1.10 [Heap Sort](#)
### 1.11 [Counting Sort](#)
### 1.12 [Radix Sort](#)
### 1.13 [Bucket Sort](#)
### 1.14 [ShellSort](#)
### 1.15 [TimSort](#)
### 1.16 [Comb Sort](#)
### 1.17 [Pigeonhole Sort](#)
### 1.18 [Cycle Sort](#)
### 1.19 [Cocktail Sort](#)
### 1.20 [Strand Sort](#)
### 1.21 [Bitonic Sort](#)
### 1.22 [Pancake sorting](#)
### 1.23 [Binary Insertion Sort](#)
### 1.24 [BogoSort or Permutation Sort](#)
### 1.25 [Gnome Sort](#)
### 1.26 [Sleep Sort – The King of Laziness / Sorting while Sleeping](#)
### 1.27 [Structure Sorting (By Multiple Rules) in C++](#)
### 1.28 [Stooge Sort](#)
### 1.29 [Tag Sort (To get both sorted and original)](#)
### 1.30 [Tree Sort](#)
### 1.31 [Cartesian Tree Sorting](#)
### 1.32 [Odd-Even Sort / Brick Sort](#)
### 1.33 [QuickSort on Singly Linked List](#)
### 1.34 [QuickSort on Doubly Linked List](#)
### 1.35 [3-Way QuickSort (Dutch National Flag)](#)
### 1.36 [Merge Sort for Linked Lists](#)
### 1.37 [Merge Sort for Doubly Linked List](#)
### 1.38 [3-way Merge Sort](#)

#

## 1. <a id="1"></a> Sorting Algorithms :

### 1.1 <a id="11"></a> Selection Sort

```sh
    // C program for implementation of selection sort
    #include <stdio.h>
    
    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    
    void selectionSort(int arr[], int n)
    {
        int i, j, min_idx;
    
        // One by one move boundary of unsorted subarray
        for (i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
    
            // Swap the found minimum element with the first element
            swap(&arr[min_idx], &arr[i]);
        }
    }
    
    /* Function to print an array */
    void printArray(int arr[], int size)
    {
        int i;
        for (i=0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    
    // Driver program to test above functions
    int main()
    {
        int arr[] = {64, 25, 12, 22, 11};
        int n = sizeof(arr)/sizeof(arr[0]);
        selectionSort(arr, n);
        printf("Sorted array: \n");
        printArray(arr, n);
        return 0;
    }

    // C++ program for implementation of selection sort 
    #include <bits/stdc++.h>
    using namespace std;
    
    void swap(int *xp, int *yp) 
    { 
        int temp = *xp; 
        *xp = *yp; 
        *yp = temp; 
    } 
    
    void selectionSort(int arr[], int n) 
    { 
        int i, j, min_idx; 
    
        // One by one move boundary of unsorted subarray 
        for (i = 0; i < n-1; i++) 
        { 
            // Find the minimum element in unsorted array 
            min_idx = i; 
            for (j = i+1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
    
            // Swap the found minimum element with the first element 
            swap(&arr[min_idx], &arr[i]); 
        } 
    } 
    
    /* Function to print an array */
    void printArray(int arr[], int size) 
    { 
        int i; 
        for (i=0; i < size; i++) 
            cout << arr[i] << " "; 
        cout << endl; 
    } 
    
    // Driver program to test above functions 
    int main() 
    { 
        int arr[] = {64, 25, 12, 22, 11}; 
        int n = sizeof(arr)/sizeof(arr[0]); 
        selectionSort(arr, n); 
        cout << "Sorted array: \n"; 
        printArray(arr, n); 
        return 0; 
    } 
    
    // This is code is contributed by rathbhupendra

```

### 1.2 <a id="12"></a> Bubble Sort

```sh
    // C program for implementation of Bubble sort
    #include <stdio.h>
    
    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    
    // A function to implement bubble sort
    void bubbleSort(int arr[], int n)
    {
    int i, j;
    for (i = 0; i < n-1; i++)      
    
        // Last i elements are already in place   
        for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
    
    /* Function to print an array */
    void printArray(int arr[], int size)
    {
        int i;
        for (i=0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    
    // Driver program to test above functions
    int main()
    {
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr)/sizeof(arr[0]);
        bubbleSort(arr, n);
        printf("Sorted array: \n");
        printArray(arr, n);
        return 0;
    }

    // C++ program for implementation of Bubble sort
    #include <bits/stdc++.h>
    using namespace std;

    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    // A function to implement bubble sort
    void bubbleSort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n-1; i++)	
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }

    /* Function to print an array */
    void printArray(int arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Driver code
    int main()
    {
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr)/sizeof(arr[0]);
        bubbleSort(arr, n);
        cout<<"Sorted array: \n";
        printArray(arr, n);
        return 0;
    }

    // This code is contributed by rathbhupendra

```
### 1.3 <a id="13"></a> Recursive Bubble Sort

```sh
    // C/C++ program for recursive implementation
    // of Bubble sort
    #include <bits/stdc++.h>
    using namespace std;

    // A function to implement bubble sort
    void bubbleSort(int arr[], int n)
    {
        // Base case
        if (n == 1)
            return;

        // One pass of bubble sort. After
        // this pass, the largest element
        // is moved (or bubbled) to end.
        for (int i=0; i<n-1; i++)
            if (arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);

        // Largest element is fixed,
        // recur for remaining array
        bubbleSort(arr, n-1);
    }

    /* Function to print an array */
    void printArray(int arr[], int n)
    {
        for (int i=0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    // Driver program to test above functions
    int main()
    {
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr)/sizeof(arr[0]);
        bubbleSort(arr, n);
        printf("Sorted array : \n");
        printArray(arr, n);
        return 0;
    }

```
### 1.4 <a id="14"></a> Insertion Sort
### 1.5 <a id="15"></a> Recursive Insertion Sort
### 1.6 <a id="16"></a> Merge Sort
### 1.7 <a id="17"></a> Iterative Merge Sort
### 1.8 <a id="18"></a> Quick Sort
### 1.9 <a id="19"></a> Iterative Quick Sort
### 1.10 <a id="110"></a> Heap Sort
### 1.11 <a id="111"></a> Counting Sort
### 1.12 <a id="112"></a> Radix Sort
### 1.13 <a id="113"></a> Bucket Sort
### 1.14 <a id="114"></a> ShellSort
### 1.15 <a id="115"></a> TimSort
### 1.16 <a id="116"></a> Comb Sort
### 1.17 <a id="117"></a> Pigeonhole Sort
### 1.18 <a id="118"></a> Cycle Sort
### 1.19 <a id="119"></a> Cocktail Sort
### 1.20 <a id="120"></a> Strand Sort
### 1.21 <a id="121"></a> Bitonic Sort
### 1.22 <a id="122"></a> Pancake sorting
### 1.23 <a id="123"></a> Binary Insertion Sort
### 1.24 <a id="124"></a> BogoSort or Permutation Sort
### 1.25 <a id="125"></a> Gnome Sort
### 1.26 <a id="126"></a> Sleep Sort – The King of Laziness / Sorting while Sleeping
### 1.27 <a id="127"></a> Structure Sorting (By Multiple Rules) in C++
### 1.28 <a id="128"></a> Stooge Sort
### 1.29 <a id="129"></a> Tag Sort (To get both sorted and original)
### 1.30 <a id="130"></a> Tree Sort
### 1.31 <a id="131"></a> Cartesian Tree Sorting
### 1.32 <a id="132"></a> Odd-Even Sort / Brick Sort
### 1.33 <a id="133"></a> QuickSort on Singly Linked List
### 1.34 <a id="134"></a> QuickSort on Doubly Linked List
### 1.35 <a id="135"></a> 3-Way QuickSort (Dutch National Flag)
### 1.36 <a id="136"></a> Merge Sort for Linked Lists
### 1.37 <a id="137"></a> Merge Sort for Doubly Linked List
### 1.38 <a id="138"></a> 3-way Merge Sort
