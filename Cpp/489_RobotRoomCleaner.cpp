/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:

    const vector<int> dx = {-1,0,1,0};
    const vector<int> dy = {0,1,0,-1};
    unordered_map<int, unordered_map<int,int>> visited;
    void cleanRoom(Robot& robot) {
        int dir = 0;
        int row = 0, col = 0;
        dfs(row,col,robot,dir);
    }
    
    void dfs(int& row, int& col, Robot& robot, int &dir) {

        if(visited[row][col] == 1)
            return;
        visited[row][col] = 1;
        robot.clean();
        for(int i = 0; i < 4; ++i) {
            if(robot.move()) {
                row += dx[dir];
                col += dy[dir];
                dfs(row, col, robot, dir);
                //back to initial state
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                row -= dx[dir];
                col -= dy[dir];
            } 
            robot.turnRight();
            dir = (dir+1)%4;
        }
        
    }
};

