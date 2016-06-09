//
//  main.c
//  MergeSort
//
//  Created by Kang Lu on 2016-06-07.
//  Copyright © 2016 Kang Lu. All rights reserved.
//
//  This is reference code that was referenced from http://www.cquestions.com/2011/07/merge-sort-program-in-c.html
//  for the purpose of timing and comparing the native C compiler's runtime performance on the Mac with other
//  compilers and platforms of other languages, such as Java, Swift, and Node.js (Javascript)

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define BUFFER_SIZE (1024)
#define ARRAY_SIZE (10000)

int temp[ARRAY_SIZE];

void mergeSort(int arr[],int low,int mid,int high){
    
    int l = low;
    int i = low;
    int m = mid+1;
    
    while((l<=mid)&&(m<=high)){
        
        if(arr[l]>=arr[m]){
            temp[i]=arr[l];
            l++;
        }
        else{
            temp[i]=arr[m];
            m++;
        }
        i++;
    }
    
    if(l>mid){
        memcpy(&temp[i], &arr[m], sizeof(int) * (high - m + 1));
    }
    else{
        memcpy(&temp[i], &arr[l], sizeof(int) * (mid - l + 1));
    }
    
    memcpy(&arr[low], &temp[low], sizeof(int) * (high - low + 1));
}

void partition(int arr[],int low,int high){
    
    int mid;
    
    if(low<high){
        mid=(low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        mergeSort(arr,low,mid,high);
    }
}

int main(int argc, const char * argv[]) {
    
    FILE* fp = fopen("../../../../../../TestData.txt", "r");
    
    char buffer[BUFFER_SIZE];
    int num[ARRAY_SIZE];
    
    int numRead = 0;
    while(fgets(buffer, BUFFER_SIZE, fp) && numRead < ARRAY_SIZE) {
        sscanf(buffer, "%d", &num[numRead]);
        numRead++;
    };
    
    // perform a merge sort
    struct timeval start;
    struct timeval end;
    
    gettimeofday(&start, NULL);
    partition(num, 0, numRead - 1);
    gettimeofday(&end, NULL);
    
    for (numRead--; numRead >= 0; numRead--) {
        printf("%d\n", num[numRead]);
    }
    
    printf("Elapsed time: %0.6f (secs)\n", (end.tv_usec - start.tv_usec) / 1000000.0);
    
    return 0;
}
