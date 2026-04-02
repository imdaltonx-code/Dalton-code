
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b){
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa - *pb;
}

// 升序排序
void BubbleSort(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int minMeetingRooms(int** meetings, int Size) {
    if (Size == 0) {
        return 0;
    }
    
    int* begin = (int*)malloc(Size * sizeof(int));
    int* end = (int*)malloc(Size * sizeof(int));
    if (!begin || !end) {
        free(begin);
        free(end);
        return -1; // 内存分配失败
    }
    
    for (int i = 0; i < Size; i++) {
        begin[i] = meetings[i][0];
        end[i] = meetings[i][1];
    }

    qsort(begin,Size,sizeof(int),cmp);
    qsort(end,Size,sizeof(int),cmp);


    /*BubbleSort(begin, Size);
    BubbleSort(end, Size);*/

    int count = 0;      // 同时会议的数量
    int max_count = 0;  // 最大数量
    int Btime = 0;      // 时间线begin
    int Etime = 0;      // 时间线end
    
    while (Etime < Size && Btime < Size) {
        if (begin[Btime] < end[Etime]) {
            count++;
            Btime++;
        } else {  // begin[Btime] >= end[Etime]，先释放会议室
            count--;
            Etime++;
        }
        max_count = (max_count > count) ? max_count : count;
    }
    
    free(begin);
    free(end);
    return max_count;
}