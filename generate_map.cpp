#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

int main (int argc, char *argv[]) {
	srand(time(NULL));

	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <integer>" << std::endl;
        return 1;
    }

	// Get n from command line
    int n = std::atoi(argv[1]);

	// Initialize our tiles and their points
	vector<pair<char, int>> tiles = { {'f', 3}, {'g', 1}, {'G', 2}, {'h', 4}, {'m', 7}, {'r', 5} }; 

	// Print tiles and points
	cout << (int)tiles.size() << endl;
	for (auto& pair : tiles) 
        cout << pair.first << " " << pair.second << endl;

	// Print map dimensions and map
	cout << n << " " << n << endl;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cout << tiles[rand() % (int)tiles.size()].first << " ";
		}
		cout << endl;
	}
	
	// Print start and end (top left and bottom right)
	cout << "0 0" << endl;
	cout << n-1 << " " << n-1 << endl;
	
	return 0;
}
