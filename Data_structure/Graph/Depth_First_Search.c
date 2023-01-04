#include <stdio.h>
/* GIVEN GRAPH
             0------1
             |  \  |
             |   \ |
             3-----2
              \   /
               \ /
                4
               / \
              /   \
             5     6
    */
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int a){
    printf("%d ",a);
    visited[a]=1;
    for (int j = 0; j< 7; j++)
{
        if(A[a][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}
int main(){
    DFS(2);
    return 0;
}