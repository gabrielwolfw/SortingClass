#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


//Part of sorting algorithm quicksort
int partition(int arr[], int low, int high, int pivot){
	int PIndex = low;
	//traverse the array from low to high
    for(int i=low;i<=high;i++)
    {    //If current element is smaller than the pivot element
        if(arr[i]<=pivot)
        {   // swap PIndex element with current element
            swap(arr[PIndex],arr[i]);
            //increment the pointer
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}

//Tomando de: 
void quicksorting(int arr[], int low,int high){
    if(low < high){
        int pivot = arr[high];
        
    
	    int PIndex = partition(arr, low, high, pivot);
	
    
	    quicksorting(arr, low, PIndex-1);
	    quicksorting(arr, PIndex+1, high);
    }
}

void insertionSorting(int arr[], int n){
        int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    }  
}


//Part of the algorithm of selectionSorting
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSorting(int arr[], int n){
    int i, j, min_idx;
 
    
    for (i = 0; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
}


void evaluate(string algorithmMode){
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    if (algorithmMode == "QS"){
        quicksorting(arr,0,n - 1);
    }else if(algorithmMode == "IS"){
        insertionSorting(arr, n);
    }else{
        selectionSorting(arr,n);   
    }
}


int main(){
    string algorithmMode;
    evaluate(algorithmMode);
    return 1;
    
}