#include <stdio.h>
#include <stdlib.h>

struct point{
    int index;
    int value;
    int xprime;
};

point sorted[1000000];

void merge1(point* points, int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right){
        if(points[i].value < points[j].value){
            sorted[k++] = points[i++];
        }
        else{
            sorted[k++] = points[j++];
        }
    }

    if(i <= mid){
        while(i <= mid){
            sorted[k++] = points[i++];
        }
    }
    else{
        while(j <= right){
            sorted[k++] = points[j++];
        }
    }

    for(int l = left; l <= right; l++){
        points[l] = sorted[l];
    }
}

void mergeSort1(point* points, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort1(points, left, mid);
        mergeSort1(points, mid + 1, right);
        merge1(points, left, mid, right);
    }
}

void merge2(point* points, int left, int mid, int right){
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while(i <= mid && j <= right){
        if(points[i].index < points[j].index){
            sorted[k++] = points[i++];
        }
        else{
            sorted[k++] = points[j++];
        }
    }

    if(i <= mid){
        while(i <= mid){
            sorted[k++] = points[i++];
        }
    }
    else{
        while(j <= right){
            sorted[k++] = points[j++];
        }
    }

    for(int l = left; l <= right; l++){
        points[l] = sorted[l];
    }
}

void mergeSort2(point* points, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort2(points, left, mid);
        mergeSort2(points, mid + 1, right);
        merge2(points, left, mid, right);
    }
}

int main(){
    int n;
    point* points;
    scanf("%d", &n);
    points = (point*)malloc(n * sizeof(point));

    for(int i = 0; i < n; i++){
        points[i].index = i;
        scanf("%d", &points[i].value);
    }

    mergeSort1(points, 0, n - 1);

    int dup, cnt = 0;
    points[0].xprime = 0;
    for(int i = 1; i < n; i++){
        dup = points[i - 1].value;
        if(points[i].value == dup){
            points[i].xprime = points[i - 1].xprime;
        }
        else{
            cnt++;
            points[i].xprime = cnt;
        }
    }

    mergeSort2(points, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", points[i].xprime);
    }

    free(points);

    return 0;
}