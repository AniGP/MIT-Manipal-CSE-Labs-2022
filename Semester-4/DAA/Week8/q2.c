#include <stdio.h>
#include <stdlib.h>

int op = 0;

void heapify(int h[], int l, int n)
{
    int i, k, v, heapify, j;
    for(i = (n/2); i>=l; i--)
    {
        k = i; v = h[k]; heapify = 0;
        while(heapify == 0 && 2*k <= n)
        {
            j = 2*k;
            op++;
            if(j<n)
                if(h[j]<h[j+1])
                    j = j+1;
            if(v>=h[j])
                heapify = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
    return;
}

void HeapSort(int arr[], int n)
{
    int k = 0;
    for(int i = 1; i<=n; i++)
    {
        heapify(arr, 1, n - k);
        int temp = arr[1];
        arr[1] = arr[n-k];
        arr[n-k] = temp;
        k++;
    }
}

int main()
{
    int arr[20], n;
   
    printf("Enter the Number of Elements : \n");
    scanf("%d", &n);
    
    printf("Enter the Elements : \n");
    
    for(int i = 1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    HeapSort(arr, n);
    
    printf("The Sorted List is : \n");
    
    for(int i = 1; i<=n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    printf("Count = %d\n", op);

    return 0;
}