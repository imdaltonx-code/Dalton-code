#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 声明
void dfs(char** grid, int i, int j, int m, int n);

//计算岛屿数量 0=海水;1=陆地
int numIslands(char** grid,int m,int n){
    int res = 0;
    //遍历 grid
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(grid[i][j] == '1'){
                res++;
                dfs(grid, i, j, m, n);
            }
        }
    }
    return res;
}

//从(i,j) 开始，将坐标相邻的陆地都变为海水
void dfs(char **grid, int i, int j, int m, int n){
    if(i < 0 || j < 0 || i >= m || j >= n){
        return;//超出边界
    }
    if(grid[i][j] == '0'){
        return;//已经是海水了
    }
    grid[i][j] = '0';//把陆地变成海水
    dfs(grid, i+1, j, m, n);
    dfs(grid, i-1, j, m, n);
    dfs(grid, i, j+1, m, n);
    dfs(grid, i, j-1, m, n);
}