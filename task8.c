#include <stdio.h>

void RecursivePrinting(int Array[], int N){
    if (N == 0){
        return;
    }
    printf("%d,", Array[0]);
    RecursivePrinting(Array + 1, N-1);
}

int main(){
    int N;
    printf("Enter the size of an Array: ");
    scanf("%d", &N);
    printf("\n");
    int Array[N];
    for (int i = 0; i < N; i++){
        printf("Enter Element[%d]: ", i+1);
        scanf("%d", &Array[i]);
    }
    printf("\n Array: {");
    RecursivePrinting(Array, N);
    printf("}");
    return 0;
}