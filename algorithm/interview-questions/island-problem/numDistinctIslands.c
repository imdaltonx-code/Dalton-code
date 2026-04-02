
#include <stdio.h>
#include <string.h>

int rows = 1000;//行
int cols = 100;//列

void dfs(int** grid, int i, int j, int m, int n, char* lands, int dir){
    if(i < 0|| j < 0|| i >= m|| j >= n){
        return;
    }
    if(grid[i][j] == 0){
        return;
    }
    grid[i][j] = 0;
    int len = strlen(lands);
    //前进：0(起点) 1 2 3 4 回溯：a(起点) b c d e
    lands[len] = dir + '0';
    lands[len + 1] = '\0';
    dfs(grid, i+1, j, m, n, lands, 1);
    dfs(grid, i-1, j, m, n, lands, 2);
    dfs(grid, i, j+1, m, n, lands, 3);
    dfs(grid, i, j-1, m, n, lands, 4);
    int flen = strlen(lands);
    lands[flen] = dir + 'a';
    lands[flen + 1] = '\0';
}

int AddIslands(char Islands[][cols], char* lands, int count){
    for(int i = 0; i < count; i++){
        if(!strcmp(lands, Islands[i])){
            return count;
        }
    }
    strcpy(Islands[count++], lands);
    return count;
}

//0=海水， 1=陆地
int numDistinctIslands(int** grid, int m, int n){
    //创建二维数组来存储每一个序列化
    char Islands[rows][cols];
    memset(Islands, 0, sizeof(Islands));//初始化
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                char lands[cols];
                memset(lands, 0, sizeof(lands));//初始化
                dfs(grid, i, j , m, n, lands, 0);
                count = AddIslands(Islands, lands, count);
            }
        }
    }
    return count;
}