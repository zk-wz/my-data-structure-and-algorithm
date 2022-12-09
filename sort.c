#include <stdio.h>
#include <stdlib.h>

#define arr_size 8

void copy_array(int *array, int *s){
    for(int i = 0; i < arr_size; i++){
        s[i] = array[i];
    }
}

void print_array(int *s){
    for(int i = 0; i < arr_size; i++){
        printf("%d ",s[i]);
    }
}

void insert_sort(int *array){
    int s[arr_size];
    copy_array(array,s);
    for(int i = 0; i < arr_size - 1; i++){
        if(s[i+1] < s[i]){
            int temp = s[i+1];
            int j = i;
            while(temp < s[j]){
                if(j < 0) break;
                s[j+1] = s[j];
                j--;
            }
            s[j+1] = temp;
        }
    }
    printf("Insert sort:");
    print_array(s);
    printf("\n");
}

void shell_sort(int *array){
    int s[arr_size];
    copy_array(array,s);

    for(int gap = arr_size/2; gap >= 1; gap /= 2){
        for(int i = gap; i < arr_size; i++){
            int temp = s[i];
            int j = i;
            while(j >= gap && temp < s[j - gap]){
                s[j] = s[j - gap];
                j -= gap;
            }
            s[j] = temp;
        }
    }

    printf("Shell sort:");
    print_array(s);
    printf("\n");
}

void bubble_sort(int *array){
    int s[arr_size];
    copy_array(array,s);
    
    for(int i = 0; i < arr_size - 1; i++){
        for(int j = 0; j < arr_size - 1; j++){
            if(s[j]>s[j+1]){
                int temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    printf("Bubble sort:");
    print_array(s);
    printf("\n");    
}

void quick_sort(int *p, int left, int right)
{
	if (left >= right)
		return;
	
	int pivot = p[left];
	int i = left, j = right;
	
	while (i < j)
	{
		while (i < j && p[j] >= pivot)
			j--;
		p[i] = p[j];
		
		while (i < j && p[i] < pivot)
			i++;
		p[j] = p[i];
	}
	p[i] = pivot;
	
	quick_sort(p, left, i-1);
	quick_sort(p, i+1, right);

}

void select_sort(int *array){
    int s[arr_size];
    copy_array(array,s);

    for(int i = 0; i < arr_size - 1; i++){
        int min = s[i];
        int min_count = i;
        for(int j = i; j < arr_size; j++){
            if(min > s[j]){
                min = s[j];
                min_count = j;
            }
        }
        int temp = s[i];
        s[i] = s[min_count];
        s[min_count] = temp;
    }

    printf("Select sort:");
    print_array(s);
    printf("\n");
}

void heapify(int *array, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && array[l] > array[largest]){
        largest = l;
    }

    if(r < n && array[r] > array[largest]){
        largest = r;
    }

    if(largest != i){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array,n,largest);
    }
}

void heap_sort(int *array){
    int s[arr_size];
    copy_array(array,s);

    for(int i = arr_size/2 - 1; i >= 0; i--){
        heapify(s,arr_size,i);
    }

    for(int i = arr_size - 1; i >= 0; i--){
        int temp = s[0];
        s[0] = s[i];
        s[i] = temp;

        heapify(s,i,0);
    }

    printf("Heap sort:");
    print_array(s);
    printf("\n");
}

// Merge sort
void merge(int *array, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = array[l + i];
    }

    for(j = 0; j < n2; j++){
        R[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }else{
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int l, int r){
    if(l < r){
        int m = l + (r - l)/2;
        merge_sort(array,l,m);
        merge_sort(array,m+1,r);
        merge(array,l,m,r);
    }
}

int main(){
    int array[arr_size] = {49,31,63,85,75,15,26,49};
    printf("Origin array:");
    print_array(array);
    printf("\n");
    insert_sort(array);
    shell_sort(array);
    bubble_sort(array);
    int s[arr_size];
    copy_array(array,s);
    quick_sort(s,0,arr_size-1);
    printf("Quick sort:");
    print_array(s);
    printf("\n");
    select_sort(array);
    heap_sort(array);
    int t[arr_size];
    copy_array(array,t);
    merge_sort(t,0,arr_size-1);
    printf("Merge sort:");
    print_array(t);

    return 0;
}

