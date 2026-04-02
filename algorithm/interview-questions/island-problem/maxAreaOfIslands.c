#include <stdio.h>


//求岛屿的最大面积  0=海水,1=陆地
int maxAreaOfIslands(int** grid, int m,int n){
    //最大面积
    int maxArea = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                int Area = dfs(grid, i, j, m, n);
                maxArea = (maxArea> Area) ? maxArea: Area;
            }
        }
    }
    return maxArea;
}

int dfs(int** grid, int i, int j, int m, int n){
    if(i < 0 || j < 0 || i >= m || j >= n){
        return;
    }
    if(grid[i][j] == 0){
        return;
    }
    grid[i][j] = 0;
    return dfs(grid, i+1, j, m, n)
    + dfs(grid, i-1, j, m, n)
    + dfs(grid, i, j-1, m ,n)
    + dfs(grid, i, j-1, m, n);
}