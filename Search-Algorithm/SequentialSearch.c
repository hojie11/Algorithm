#include <stdio.h>
#include <string.h>

int Array_SequentialSearch(int DataSet[], int Length, int Target){
    int match = 0;

    for(int i=0; i<Length; i++){
        if(DataSet[i] == Target){
            break;
        }else{
            match++;
        }
    }

    return match;
}

void Array_MoveToFront(int DataSet[], int Length, int Target){
    int match = 0;
    int value = 0;

    for(int i=0; i<Length; i++){
        if(DataSet[i] == Target){
            break;
        }else{
            match++;
        }
    }

    value = DataSet[match];

    for(int j=match-1; j>=0; j--){
        DataSet[j+1] = DataSet[j];
    }
    DataSet[0] = value;
}

void Array_Transpose(int DataSet[], int Length, int Target){
    while(DataSet[0] != Target){
        int match = 0;

        for(int i=0; i<Length; i++){
            if(DataSet[i] == Target){
                break;
            }else{
                match++;
            }
        }

        int temp = DataSet[match-1];
        DataSet[match] = temp;
        DataSet[match-1] = temp;
    }
}

int main(void){
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Target = 1;
    int match = 0;

    int Length = sizeof DataSet / sizeof DataSet[0];

    printf("%d \n", Length);

    for(int i=0; i<Length; i++){
        printf("%d ", DataSet[i]);
    }
    printf("\n\n");

    match = Array_SequentialSearch(DataSet, Length, Target);
    printf("I found %d in the array %d\n\n", Target, match);

    Array_MoveToFront(DataSet, Length, Target);
    printf("I move %d to the front of array\n\n", Target);

    for(int i=0; i<Length; i++){
        printf("%d ", DataSet[i]);
    }
    printf("\n\n");

    Array_Transpose(DataSet, Length, Target);
    printf("I transpose %d to the front of array\n\n", Target);

    for(int i=0; i<Length; i++){
        printf("%d ", DataSet[i]);
    }
    printf("\n\n");

    return 0;
}
