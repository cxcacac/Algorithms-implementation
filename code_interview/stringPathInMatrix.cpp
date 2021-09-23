#include <stdio.h>
#include <string>

using namespace std;

bool dfs(const char *matrix, int rows, int cols, int row, int col, const char *str, int &pathLength, bool *visited);

bool hasPath(char* matrix, int rows, int cols, char* str){
    if(matrix==nullptr || rows < 1 || cols < 1 || str==nullptr){
        return false;
    }
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    int pathLength = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(dfs(matrix, rows, cols, i, j, str, pathLength, visited)){
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

bool dfs(const char *matrix, int rows, int cols, int row, int col, const char *str, int &pathLength, bool *visited){
    // 回溯终止条件
    if(str[pathLength]=='\0'){
        return true;
    }
    bool hasPath = false;
    if(row<0 || row >= rows || col < 0 || col>=cols||matrix[row*cols+col]!=str[pathLength]||visited[row*cols+col]){
        return false;
    }
    visited[row * cols + col] = true;
    pathLength++;
    hasPath = dfs(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
              dfs(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
              dfs(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
              dfs(matrix, rows, cols, row, col - 1, str, pathLength, visited);
    if(!hasPath){
        --pathLength;
        visited[row * cols + col] = false;
    }
    return hasPath;
}
