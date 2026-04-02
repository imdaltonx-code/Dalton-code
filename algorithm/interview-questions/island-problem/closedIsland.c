#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dfs(int** grid, int i, int j, int m, int n);

//0=陆地，1=海水 计算封闭岛屿数量
int closedIsland(int** grid, int m, int n){
    //先淹没上下界的岛屿
    for(int i = 0; i < n; i++){
        dfs(grid, 0, i, m, n);
        dfs(grid, m-1, i, m, n);
    }
    //在淹没左右界的岛屿
    for(int j = 0; j < m; j++){
        dfs(grid, j, 0, m, n);
        dfs(grid, j, n-1, m, n);
    }

    int res = 0;//数量
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                res++;
                dfs(grid, i, j, m, n);
            }
        }
    }
    return res;
}

void dfs(int** grid, int i, int j, int m, int n){
    if(i >= m || j >= n || i < 0 || j < 0){
        return;
    }
    if(grid[i][j] == 1){
        return;
    }
    grid[i][j] = 1;
    dfs(grid, i+1, j, m, n);
    dfs(grid, i-1, j, m, n);
    dfs(grid, i, j+1, m, n);
    dfs(grid, i, j-1, m, n);
}