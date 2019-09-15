#include<stdio.h>
#include<stdlib.h>
 #include<stdio.h>

int BinarySearch(int n, int *p, int value) 
{
    int low=0, high=n, mid;
    while(low <= high) 
    {
        mid = (low + high) / 2;
        printf("%d: %d\n", mid, p[mid]);
        if(p[mid] > value)
            high = mid - 1;
        else if(p[mid] < value)
            low = mid+1;
        else
            return mid;
    }
    return -1;
}


int main() {
  
  int a1[] = {11,33,44,55,88,99};
  
  int pos;
  
 // pos = BinarySearch(6, a1, 55);
  pos = BinarySearch(6, a1, 99);
 // pos = BinarySearch(6, a1, 44);
  //pos = BinarySearch(6, a1, 100);
  
  return 0;
}
