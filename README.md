Eric Goodpasture and Travis Tyimok
Project 4: Dijkstra's Algorithm and path finding

Contributions (Eric):
Helped write dijkstras.cpp
Wrote generate_map.cpp
Performed benchmarking

| N             | Elapsed Time     | Memory Usage        |
|---------------|------------------|---------------------|
| 10            | 0.0024           | 85602               |
| 20            | 0.0022           | 91632               |
| 50            | 0.0042           | 124042              |
| 100           | 0.0130           | 230912              |
| 200           | 0.0470           | 639652              |
| 500           | 0.2960           | 3440208             |
| 1000          | 1.2330           | 13298244            |
|---------------|------------------|---------------------|

Questions:
1.The graph is represented as vertices, edges, and weights. It is stored in a 2D vector which has each vertex in a cell. 
2.The program seems to be around O(nlog(n)). The elapsed time doesn't quite quadruple when n doubles which implies 
	that the time complexity is less than O(n^2).

3.Our implementation does not scale well. The memory usage was increasing very rapidly (almost an 4x increase from n=500 to n=1000)
