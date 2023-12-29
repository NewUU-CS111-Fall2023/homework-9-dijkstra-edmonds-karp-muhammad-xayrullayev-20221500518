/*
 * Author: Muhammad Xayrullayev
 * Date: 29.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Problem3 {
    public:
        const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Cell {
    int row, col;
};
// Time complexity: O(N * M)
bool isValid(int row, int col, const vector<vector<char>>& maze) {
    int numRows = maze.size();
    int numCols = maze[0].size();
    return (row >= 0 && row < numRows && col >= 0 && col < numCols && maze[row][col] == '.');
}
// Time complexity: O(N * M)
int shortestPath(const vector<vector<char>>& maze, const Cell& start, const Cell& end) {
    int numRows = maze.size();
    int numCols = maze[0].size();

    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    queue<pair<Cell, int>> bfsQueue;
    bfsQueue.push({start, 0});  

    visited[start.row][start.col] = true;

    while (!bfsQueue.empty()) {
        Cell currentCell = bfsQueue.front().first;
        int currentDistance = bfsQueue.front().second;
        bfsQueue.pop();

        if (currentCell.row == end.row && currentCell.col == end.col) {
            return currentDistance;
        }

        for (const auto& dir : directions) {
            int newRow = currentCell.row + dir[0];
            int newCol = currentCell.col + dir[1];

            if (isValid(newRow, newCol, maze) && !visited[newRow][newCol]) {
                bfsQueue.push({{newRow, newCol}, currentDistance + 1});
                visited[newRow][newCol] = true;
            }
        }
    }

    return -1;
}
};