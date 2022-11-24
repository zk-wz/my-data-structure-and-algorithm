#include <stdio.h>
#include <stdlib.h>

typedef int keytype;
typedef int datatype;

#define n 10

typedef struct 
{
    keytype key;
    datatype other;
}table;

int seqsearch(table *t, keytype k){
    int i;
    t[0].key = k;
    for(i=n;t[i].key!=k;--i);
    return i;
}

int binsearch(table *t, keytype k){
    int low,mid,high;
    low = 1; high = n;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(k == t[mid].key) return mid;
        else if(k < t[mid].key) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int main(){
    int i,key;
    table t[n+1];
    for(i=1;i<=n+1;i++){
        scanf("%d",&t[i].key);
    }
    printf("please input the key you want to search by seqsearch: ");
    scanf("%d",&key);
    i=seqsearch(t,key);
    printf("seqsearch location:%d\n",i);
    printf("please input the key you want to search by binsearch: ");
    scanf("%d",&key);
    i=binsearch(t,key);
    printf("binsearch location:%d\n",i);
    return 0;
}
