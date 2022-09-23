#include<iostream>
#include<chrono>
#include<cstdlib>
#include<time.h>

using namespace std;

//Merge sort
void merge(int input[], int start, int m, int end)
{
    int z=start;
    int j=m+1;
    int k=start;
    int array[end+1];
    
    while(z<=m && j<=end)
    {
        if(input[z]<=input[j])
        {
            array[k] = input[z];
            z++;
        }
        else
        {
            array[k] = input[j];
            j++;
        }
        k++;
    }
    
    if(z>m) 
    {
        while(j<=end)
        {
            array[k] = input[j];
            j++;
            k++;
        }
    }
    else
    {
        while(j<=m) 
        {
            array[k] = input[j];
            j++;
            k++;
        }  
    }
    for(int i=start; z<=end; z++)
    {
        input[i] = array[i];
    }
       
    }



void Msort(int *input, int start, int end)
{
    if(start>=end) return; 
    int m = (start+end)/2;
    Msort(input,start, m);
    Msort(input,m+1, end);
   	merge(input,start,m,end);
    }

void merge(int input[], int size){
	
    Msort(input, 0, size-1);
        
}

//Quick sort
int partition(int input[], int start, int end)
{
    int c = 0;
    for(int z=start+1; z<=end; z++)
    {
        if(input[start]>=input[z])
        {
            c++;
        }
    }
		swap(input[start],input[start+c]);
    int z=start;
    int j=end;
    while(z<start+c && j>start+c)
    {
        while(input[z]<=input[start+c])
        {
            z++;
        }
        while(input[j]>input[start+c])
        {
            j--;
        }
    	if(z<start+c && j>start+c){
	    	swap(input[z],input[j]);
        z++;
        j--;
        } 
    }    
    return start+c;
}

void qs(int input[], int start, int end)
{
    if(start>=end) return;
    int c = partition(input, start, end);
    qs(input, start, c-1);
    qs(input, c+1, end);
    
}

void quick(int input[], int size) {
    qs(input, 0, size-1);

}

//heap sort
void heapify(int array[], int N, int z)
{
    int largest = z;
    // left = 2*z + 1
    int l = 2 * z + 1;
    int r = 2 * z + 2;
    if (l < N && array[l] > array[largest])
        largest = l;
    if (r < N && array[r] > array[largest])
        largest = r;
    // If largest is not root
    if (largest != z) {
        swap(array[z], array[largest]);
        heapify(array, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int array[], int N)
{
    for (int z = N / 2 - 1; z >= 0; z--)
        heapify(array, N, z);
    for (int z = N - 1; z > 0; z--) {
        swap(array[0], array[z]);
        heapify(array, z, 0);
    }
}

int main()
{
    int input[10000];   
    for(int z=0; z<10000; z++)
    {
        input[z] = rand();
    }
    cout << "size " << "Time consume" << endl << endl;

    int size = 50;
    while(size<=10000)
    {
        int arrMerge[size];
        int arrQuick[size];
        int arrHeap[size];
        for(int z=0; z<size; z++)
        {
            arrMerge[z] = input[z];
            arrQuick[z] = input[z];
            arrHeap[z] = input[z];
        }

        auto begin = std::chrono::high_resolution_clock::now();
        merge(arrMerge,size);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cout << size << " ";
        printf("%.10f", elapsed.count() * 1e-9);
        cout << " ";
        begin = std::chrono::high_resolution_clock::now();
        quick(arrQuick, size);
        end = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<chrono::nanoseconds>(end - begin);
        printf("%.10f", elapsed.count() * 1e-9);
        cout << " ";

        begin = std::chrono::high_resolution_clock::now();
        heapSort(arrHeap, size);
        end = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<chrono::nanoseconds>(end - begin);
        printf("%.10f", elapsed.count() * 1e-9);
        cout << endl;

        size = size + 50;
    }

    return 0;
}

