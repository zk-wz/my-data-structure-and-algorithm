#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000 // the max count of non-zero elements
typedef int datatype; // the type of data

typedef struct{
    int i,j; // the row and column of the element
    datatype data; // the value of the element
}node;

typedef struct{
    int m,n,t; // the row, column and count of non-zero elements
    node data[maxsize]; // the array of non-zero elements
}spmatrix;

// create sparse matrix
void create_spmatrix(spmatrix *s){
    printf("Please input row:");
    scanf("%d", &(s->m));
    printf("Please input column:");
    scanf("%d", &(s->n));
    s->t = 0;
    printf("Please input the sparse matrix:\n");
    for (int i = 0; i < s->m; i++)
    {
        for(int j = 0; j < s->n; j++){
            datatype temp;
            scanf("%d", &temp);
            if(temp!=0){
                s->data[s->t].i = i;
                s->data[s->t].j = j;
                s->data[s->t].data = temp;
                (s->t)++;
            }
        }
    }
}

// print sparse matrix
void print_spmatrix(spmatrix *s){
    int k = 0;
    for(int i = 0; i < s->m; i++){
        for(int j = 0; j < s->n; j++){
            if(i==s->data[k].i && j==s->data[k].j){
                printf("%d ", s->data[k].data);
                k++;
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// get value of the element
datatype get_value(spmatrix *s, int i, int j){
    for(int k = 0; k < s->t; k++){
        if(s->data[k].i==i && s->data[k].j==j){
            return s->data[k].data;
        }
    }
    return 0;
}

// add sparse matrix
spmatrix add_spmatrix(spmatrix *s1, spmatrix *s2){
    if(s1->m!=s2->m || s1->n!=s2->n){
        printf("The two sparse matrix can't be added!\n");
        return;
    }

    // initialize the result matrix
    spmatrix s;
    s.m = s1->m;
    s.n = s1->n;
    s.t = 0;

    // add
    int count1=0,count2=0,count3=0;
    while(count1<s1->t && count2<s2->t){

        if(s1->data[count1].i==s2->data[count2].i){
            // if row and col are same, add
            if(s1->data[count1].j==s2->data[count2].j){
                if(s1->data[count1].data + s2->data[count2].data != 0){
                    s.data[count3].data = s1->data[count1].data + s2->data[count2].data;
                    s.data[count3].i = s1->data[count1].i;
                    s.data[count3].j = s1->data[count1].j;
                    count3++;
                }
                count1++; count2++;
            }
            // s1.col < s2.col
            else if(s1->data[count1].j<s2->data[count2].j){
                s.data[count3].data = s1->data[count1].data;
                s.data[count3].i = s1->data[count1].i;
                s.data[count3].j = s1->data[count1].j;
                count3++; count1++;
            }
            // s1.col > s2.col
            else if(s1->data[count1].j>s2->data[count2].j){
                s.data[count3].data = s2->data[count2].data;
                s.data[count3].i = s2->data[count2].i;
                s.data[count3].j = s2->data[count2].j;
                count3++; count2++;
            }
        }
        // s1.row < s2.row
        else if(s1->data[count1].i<s2->data[count2].i){
            s.data[count3].data = s1->data[count1].data;
            s.data[count3].i = s1->data[count1].i;
            s.data[count3].j = s1->data[count1].j;
            count3++; count1++;
        }
        // s1.row > s2.row
        else if(s1->data[count1].i>s2->data[count2].i){
            s.data[count3].data = s2->data[count2].data;
            s.data[count3].i = s2->data[count2].i;
            s.data[count3].j = s2->data[count2].j;
            count3++; count2++;
        }       
    }
    // add the rest of s1
    while(count1<s1->t){
        s.data[count3].data = s1->data[count1].data;
        s.data[count3].i = s1->data[count1].i;
        s.data[count3].j = s1->data[count1].j;
        count3++; count1++;
    }
    // add the rest of s2
    while(count2<s2->t){
        s.data[count3].data = s2->data[count2].data;
        s.data[count3].i = s2->data[count2].i;
        s.data[count3].j = s2->data[count2].j;
        count3++; count2++;
    }
    s.t = count3;
    return s;
}

// multiply sparse matrix
spmatrix multiply_spmatrix(spmatrix *s1, spmatrix *s2){
    if(s1->n!=s2->m){
        printf("The two sparse matrix can't be multiplied!\n");
        return;
    }

    // initialize the result matrix
    spmatrix s;
    s.m = s1->m;
    s.n = s2->n;
    s.t = 0;

    // multiply
    int count=0;
 
    for(int i = 0; i < s1->m; i++){
        for(int j = 0; j < s2->n; j++){
            int sum = 0;
            for(int k = 0; k < s1->n; k++){
                sum += get_value(s1, i, k) * get_value(s2, k, j);
            }
            if(sum!=0){
                s.data[count].i = i;
                s.data[count].j = j;
                s.data[count].data = sum;
                count++;
            }
        }
    }

    s.t = count;
    return s;
}

int main(){
    spmatrix s1,s2,s3; // spmatrix for add
    spmatrix s4,s5,s6; // spmatrix for multiply
    printf("Please input the first sparse matrix to add:\n");
    create_spmatrix(&s1);
    printf("Please input the second sparse matrix to add:\n");
    create_spmatrix(&s2);
    printf("The addition of the two sparse matrix is:\n");
    s3 = add_spmatrix(&s1, &s2);
    print_spmatrix(&s3);
    printf("Please input the first sparse matrix to multiply:\n");
    create_spmatrix(&s4);
    printf("Please input the second sparse matrix to multiply:\n");
    create_spmatrix(&s5);
    printf("The multiplication of the two sparse matrix is:\n");
    s6 = multiply_spmatrix(&s4, &s5);
    print_spmatrix(&s6);
    return 0;
}