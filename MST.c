#include <stdio.h>
#include <stdlib.h>

#define n 6

typedef struct 
{
    int fromvex, endvex;
    int weight;
    int sign;
}edge;

// input the first vertex
edge* prim(int i, edge *tree){
    int j,k,m,v,min,max=100000;
    int d;
    edge e;
    v=i;
    int matrix[n][n] = {{0,9,4,max,max,max},{9,0,6,10,7,max},{4,6,0,8,max,5},{max,10,8,0,3,max},{max,7,max,3,0,2},{max,max,5,max,2,0}};
    // initialize the tree
    for(j = 0; j < n-1; j++){
        tree[j].fromvex = v;
        if(j>=v){
            tree[j].endvex = j+1;
            tree[j].weight = matrix[v][j+1];
        }
        else{
            tree[j].endvex = j;
            tree[j].weight = matrix[v][j];
        }
    }

    for(k = 0; k < n-1; k++){
        min = max;
        for(j = k; j < n-1; j++){
            if(tree[j].weight<min){
                min = tree[j].weight;
                m = j;
            }
        }
        e = tree[m];
        tree[m] = tree[k];
        tree[k] = e; // get the edge with the min weight
        v = tree[k].endvex;
        for(j = k + 1; j < n-1; j++){
            d = matrix[v][tree[j].endvex];
            if(d<tree[j].weight){
                tree[j].weight = d;
                tree[j].fromvex = v;
            }
        }
    }

    return tree;
}

// a is the num of the vertex, e is the num of the edge
void kruskal(int a, int e, edge *tree){
    int h,i,j,k,l,m,t,min;
    int G[n];
    for(i = 0; i<= a-1; i++){
        G[i] = i;
    }
    for(i = 0; i<= e-1; i++){
        scanf("%d%d%d",&tree[i].fromvex,&tree[i].endvex,&tree[i].weight);
        tree[i].sign = 0;
    }
    j=0;
    while (j < a-1)
    {
        min = 1000;
        for(i = 0; i <= e-1; i++){
            if(tree[i].sign == 0){
                if (tree[i].weight<min)
                {
                    min = tree[i].weight;
                    m = i;
                }
                k = tree[m].fromvex;
                l = tree[m].endvex;
                tree[m].sign = 1;
                if(G[k]==G[1]){
                    tree[m].sign = 2;
                }
                else{
                    j++;
                    h = G[l];
                    for(t = 0; t < a; t++){
                        if(G[t]==h){
                            G[t]=G[k];
                        }
                    }
                }                
            }
        }
    }

}

int main(){
    int i,sum=0;
    edge tree_prim[n-1];
    prim(3,tree_prim);
    for(i = 0; i < n-1; i++){
        sum+=tree_prim[i].weight;
    }
    printf("prim:%d\n",sum);
    sum = 0;
    edge tree_kruskal[n-1];
    kruskal(6,9,tree_kruskal);
    for(i = 0; i < n-1; i++){
        sum+=tree_kruskal[i].weight;
    }
    printf("kruskal:%d\n",sum);
}