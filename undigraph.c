#include <stdio.h>
#include <stdlib.h>

#define n 3 // the number of vertex
#define e 3// the number of edge
typedef char vextype; // the type of vertex
typedef float adjtype; // the type of weight

// define the structure of graph
typedef struct 
{
    vextype vexs[n]; // the vertex
    adjtype arcs[n][n];
}graph;


// create adj array
void create_adjarray(graph *g){
    int i,j,k;
    for(i=0;i<n;){
        char temp;
        temp = getchar();
        if(temp!='\n'){
            g->vexs[i] = temp;
            i++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            g->arcs[i][j] = 0; // initailize the array
        }
    }
    for(k=0;k<e;k++){
        scanf("%d%d", &i, &j);
        g->arcs[i][j] = 1;
        g->arcs[j][i] = 1;
    }
}

//DFS
void DFS(graph *g, int i, int visited[]){
    int j;
    visited[i] = 1;
    printf("%c", g->vexs[i]);
    for(j=0;j<n;j++){
        if(g->arcs[i][j] == 1 && visited[j] == 0){
            DFS(g, j, visited);
        }
    }
}

// BFS
void BFS(graph *g, int i, int visited[]){
    int j;
    int queue[n];
    int front = 0;
    int rear = 0;
    queue[rear] = i;
    rear++;
    visited[i] = 1;
    while(front != rear){
        i = queue[front];
        front++;
        printf("%c", g->vexs[i]);
        for(j=0;j<n;j++){
            if(g->arcs[i][j] == 1 && visited[j] == 0){
                queue[rear] = j;
                rear++;
                visited[j] = 1;
            }
        }
    }
}

int main(){
    graph g;
    int visited[n];
    int i;
    create_adjarray(&g);
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    printf("DFS: ");
    DFS(&g, 0, visited);
    printf("\n");
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    printf("BFS: ");
    BFS(&g, 0, visited);
    printf("\n");
    return 0;
}