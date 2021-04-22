#include<stdio.h>

int max(int a, int b){
    return (a >b)? a:b;
}
int knapsack(int w, int val[], int wt[], int n){
    //we define the base case
    if (n == 0 || w==0)
    return 0;

    if(wt[n-1]> w)
      knapsack(w, val, wt, n-1);
    else{
        return max(val[n-1]+knapsack(w- wt[n-1], val, wt, n-1),
        knapsack(w, val, wt, n-1));
    }
    return 0;
}

int main (){
    int val[] ={1, 4, 5, 7};
    int wt[] ={1, 3, 4, 5};
    int w = 7;

    int n = sizeof(val)/ sizeof(val[0]);
    printf("Result: %d\n", knapsack(w, val, wt, n));



    return 0;
}