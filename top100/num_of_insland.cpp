#include <head.hpp>
using namespace std;
/**
 * 岛屿数量
 * https://leetcode-cn.com/problems/number-of-islands/
 * 思想就是走过的置0
 */
class Solution {
public:
    // 深度优先搜索 走过置0
    int numIslands(vector<vector<char>>& grid) {
        // 获取行列
        int nr = grid.size();
        int nc = grid[0].size();
        int ans=0;
        for(int r=0;r<nr;++r){
            for(int c=0;c<nc;++c){
                if(grid[r][c]=='1'){
                    ++ans;
                    dfs(grid,r,c);
                }
            }
        }
        return ans ;
    }
    void dfs(vector<vector<char>>& grid, int r,int c){
        // 返回界定 需要边界范围
        int nr = grid.size();
        int nc = grid[0].size();
        // 标记
        grid[r][c] = '0';
        // 上下左右
        if(r-1>=0 && grid[r-1][c]=='1') dfs(grid,r-1,c);
        if(r+1<nr && grid[r+1][c]=='1') dfs(grid,r+1,c);
        if(c-1>=0 && grid[r][c-1]=='1') dfs(grid,r,c-1);
        if(c+1<nc && grid[r][c+1]=='1') dfs(grid,r,c+1);
    }
};