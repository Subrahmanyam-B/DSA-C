#include <stdio.h>


//linear probing
int linear_probing(int arr[], int n, int key)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == key)
        {
            return i;
        }
        i++;
    }
    return -1;
}

//hashing
int hashing(int arr[], int n, int key)
{
    int i = key % n;
    while (arr[i] != 0)
    {
        if (arr[i] == key)
        {
            return i;
        }
        i++;
        if (i == n)
        {
            i = 0;
        }
    }
    return -1;
}

//double hashing
int double_hashing(int arr[], int n, int key)
{
    int i = key % n;
    while (arr[i] != 0)
    {
        if (arr[i] == key)
        {
            return i;
        }
        i = (i + 1) % n;
    }
    return -1;
}

//chaining
int chaining(int arr[], int n, int key)
{
    int i = key % n;
    while (arr[i] != 0)
    {
        if (arr[i] == key)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int main(){
    int arr[100];
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key:");
    scanf("%d", &key);
    int i = hashing(arr, n, key);
    if (i == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("Found at %d", i);
    }
    return 0;
}