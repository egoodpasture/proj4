// dijsktras.cpp

// Main Execution

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int row, col, cost;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

int main() {
    int tiles_n;
    cin >> tiles_n;

    // Step 1: Read tile costs
    map<char, int> tile_costs;
    for (int i = 0; i < tiles_n; i++) {
        char tile;
        int cost;
        cin >> tile >> cost;
        tile_costs[tile] = cost;
    }

    // Step 2: Read map dimensions
    int map_rows, map_cols;
    cin >> map_rows >> map_cols;

    vector<vector<char>> map(map_rows, vector<char>(map_cols));
    for (int i = 0; i < map_rows; i++) {
        for (int j = 0; j < map_cols; j++) {
            cin >> map[i][j];
        }
    }

    // Step 3: Read runner's start and end positions
    int start_row, start_col, end_row, end_col;
    cin >> start_row >> start_col >> end_row >> end_col;

    // Step 4: Initialize Dijkstra
    vector<vector<int>> dist(map_rows, vector<int>(map_cols, INT_MAX));
    vector<vector<pair<int, int>>> parent(map_rows, vector<pair<int, int>>(map_cols, {-1, -1}));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Starting point
    dist[start_row][start_col] = 0;
    pq.push({start_row, start_col, 0});

    // Directions for movement: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int cur_row = current.row;
        int cur_col = current.col;
        int cur_cost = current.cost;

        if (cur_row == end_row && cur_col == end_col) {
            break;
        }

        // Explore neighbors
        for (auto [dr, dc] : directions) {
            int new_row = cur_row + dr;
            int new_col = cur_col + dc;

            if (new_row >= 0 && new_row < map_rows && new_col >= 0 && new_col < map_cols) {
                int new_cost = cur_cost + tile_costs[map[new_row][new_col]];

				if (new_cost < dist[new_row][new_col]) {
					dist[new_row][new_col] = new_cost;
					parent[new_row][new_col] = {cur_row, cur_col};
					pq.push({new_row, new_col, new_cost}); // Ensure this tile is revisited with updated cost
				}
                /*if (new_cost < dist[new_row][new_col]) {
                    dist[new_row][new_col] = new_cost;
                    parent[new_row][new_col] = {cur_row, cur_col};
                    pq.push({new_row, new_col, new_cost});
                }*/
            }
        }
    }

    // Step 5: Reconstruct the path
    vector<pair<int, int>> path;
    int row = end_row, col = end_col;
    while (row != -1 && col != -1) {
        path.push_back({row, col});
        tie(row, col) = parent[row][col];
    }

    reverse(path.begin(), path.end());

    // Step 6: Output the result
    cout << dist[end_row][end_col] << endl;
    for (auto [r, c] : path) {
        cout << r << " " << c << endl;
    }

    return 0;
}

/*int main(int argc, char *argv[]) {
    return 0;
}*/

