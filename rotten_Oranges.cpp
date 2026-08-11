#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        int fresh_count = 0;

        // Step 1: Initialize the queue with rotten oranges and count fresh ones
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) return 0;

        int minutes = 0;
        // Direction vectors for moving up, down, left, and right
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Step 2: Process the grid level-by-level (each level = 1 minute)
        while (!q.empty() && fresh_count > 0) {
            int level_size = q.size();
            
            for (int i = 0; i < level_size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // If neighbor is valid and is a fresh orange, rot it
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh_count--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }

        // Step 3: Return result based on remaining fresh oranges
        return fresh_count == 0 ? minutes : -1;
    }
};
