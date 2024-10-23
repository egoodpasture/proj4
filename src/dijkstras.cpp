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
    // Overload the operator to allow us to compare nodes
	bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

int main(int argc, char **argv) {
    //  Read number of different tiles
    int num_tiles;
    cin >> num_tiles;

    // Store tile costs in a map
    map<char, int> tile_costs;
    for (int i = 0; i < num_tiles; i++) {
        char tile;
        int cost;
        cin >> tile >> cost;
        tile_costs[tile] = cost;
    }

    // Read map size (rows and columns)
    int rows, cols;
    cin >> rows >> cols;

    // Read the map
    vector<vector<char>> game_map(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> game_map[i][j];
        }
    }

    // Read the starting and ending positions of the runner
    int start_row, start_col, end_row, end_col;
    cin >> start_row >> start_col >> end_row >> end_col;

    // Set up Dijkstra's algorithm
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    vector<vector<pair<int, int>>> prev(rows, vector<pair<int, int>>(cols, {-1, -1}));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Start from the runner's starting position
    dist[start_row][start_col] = 0;
    pq.push({start_row, start_col, 0});

    // Directions for moving: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Dijkstra's loop to find the shortest path
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int r = current.row;
        int c = current.col;
        int cur_cost = current.cost;

        // Stop if we reached the destination
        if (r == end_row && c == end_col) {
            break;
        }

        // Explore neighbors
        for (auto dir : directions) {
            int new_r = r + dir.first;
            int new_c = c + dir.second;

            // Make sure the new position is inside the map
            if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols) {
                // Calculate cost based on the tile we are leaving
                int new_cost = cur_cost + tile_costs[game_map[r][c]];

                // Update distance if we found a cheaper path
                if (new_cost < dist[new_r][new_c]) {
                    dist[new_r][new_c] = new_cost;
                    prev[new_r][new_c] = {r, c};
                    pq.push({new_r, new_c, new_cost});
                }
            }
        }
    }

    // Reconstruct the path
    vector<pair<int, int>> path;
    int r = end_row, c = end_col;
    while (r != -1 && c != -1) {
        path.push_back({r, c});
        tie(r, c) = prev[r][c];
    }

    // Reverse the path so we can print it from start to end
    reverse(path.begin(), path.end());

    // Output the result
    cout << dist[end_row][end_col] << endl;
    for (auto p : path) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
