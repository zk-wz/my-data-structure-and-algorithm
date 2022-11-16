#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define M N * 2 - 1   
#define N 30          
#define MAX 999

typedef struct tree {
    char ch;         
    double weight;   
    int parent;     
    int L, R;        
    struct tree *LChild;
    struct tree *RChild;
    char hashcode[N];   
    int is_leaves;
} tree, Htree[M];


void Select(Htree ht, int n, int *s1, int *s2) {
    int i;
    double min1 = MAX, min2 = MAX;
    *s1 = 0;
    *s2 = 0;
    for (i = 1; i <= n; i++) {
        if (ht[i].parent == 0) {
            if (ht[i].weight < min1) {
                min2 = min1;
                *s2 = *s1;
                min1 = ht[i].weight;
                *s1 = i;
            } else if (ht[i].weight < min2) {
                min2 = ht[i].weight;
                *s2 = i;
            }
        }
    }
}


void crateHtree(Htree ht, int n) {
    int i;
    
    char s[10];
    for (i = 1; i <= n; i++) {
        ht[i].parent = 0;
        ht[i].L = 0;
        ht[i].R = 0;
        ht[i].is_leaves = 1;
        ht[i].RChild = NULL;
        ht[i].LChild = NULL;
    }
    
    for (i = n + 1; i <= 2 * n - 1; i++) {
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].L = 0;
        ht[i].R = 0;
        ht[i].is_leaves = 0;
        ht[i].RChild = NULL;
        ht[i].LChild = NULL;
    }
    
    int s1, s2;
    for (i = n + 1; i <= n * 2 - 1; i++) {
        Select(ht, i - 1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].parent = 0;
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].L = s1;
        ht[i].R = s2;
        ht[i].RChild = &ht[s2];
        ht[i].LChild = &ht[s1];
    }
}


void crateTcode(Htree ht, int n) {
    int i;
    char cd[n];
    for (i = 1; i <= n; i++) {
        int start = n - 1, c = i, p = ht[i].parent;
        while (p != 0) {
            start--;
            if (ht[p].L == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = p;
            p = ht[c].parent;
        }
        
        
        int t = 0;
        for (int j = 0; j < n; j++) {
            if (cd[j] == '0' || cd[j] == '1') {
                ht[i].hashcode[t] = cd[j];
                t++;
            }
        }
        memset(cd, 0, sizeof cd);     
    }
}



void PreOder(tree *root) {
    if (root->is_leaves)
        printf("%c:%s\n", root->ch, root->hashcode);
    if (root->LChild) PreOder(root->LChild);
    if (root->RChild) PreOder(root->RChild);
}


void Search(Htree ht, const char String[2000], int n) {
    int t = 2 * n - 1;
    printf("original:");
    unsigned long len = strlen(String); 
    for (int i = 0; i < len; i++) {
        if (String[i] == '0') {
            t = ht[t].L;
            if (ht[t].is_leaves) {
                printf("%c", ht[t].ch);
                t = 2 * n - 1;
            }
        } else {
            t = ht[t].R;
            if (ht[t].is_leaves) {
                printf("%c", ht[t].ch);
                t = 2 * n - 1;
            }
        }
    }
}

int main() {
    Htree ht;
    char String[2000];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char s[10];
        scanf("%s", s);
        ht[i].ch = s[0];                                            
        ht[i].weight = strtod(strcpy(s, s + 1), NULL);  
    }
    scanf("%s", String);            
    crateHtree(ht, n);              
    crateTcode(ht, n);              
    PreOder(&ht[2 * n - 1]);   		
    Search(ht, String, n);          
    return 0;
}


