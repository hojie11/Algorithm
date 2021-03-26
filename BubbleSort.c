#include <stdio.h>

int isSorted(int DataSet[], int Length){
    int sorted = 0;

    for(int i=0; i<Length-1; i++){
        if(DataSet[i] <= DataSet[i+1]){
            sorted = 1;
        }else{
            sorted = 0;
            break;
        }
    }

    return sorted;
}

void BubbleSort(int DataSet[], int Length){
    int temp = 0;

    // Repeat for loop as much as size of Data Set
    for(int i=0; i<Length-1; i++){

        if(isSorted(DataSet, Length)){
            printf("Is already sorted!\n");
            break;
        }

        // Repetation count is decreased by outside loop
        // Cause the size of Sort Object is decreased 
        for(int j=0; j<Length-(i+1); j++){
            if(DataSet[j]>DataSet[j+1]){
                temp = DataSet[j+1];
                DataSet[j+1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }
}

int main(void){
    //int DataSet[] = {6, 4, 2, 3, 1, 5};
    int DataSet[] = {1, 2, 3, 4, 5, 6};
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);
    
    printf("Before: ");
    for(int i=0; i<Length; i++){
        printf("%d ", DataSet[i]);
    }
    printf("\n");

    BubbleSort(DataSet, Length);

    printf("After: ");
    for(int i=0; i<Length; i++){
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}