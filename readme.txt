Name: Zaigham A. Randhawa

Project no. ShortestPath

Files submitted: 

1. readGraph.hpp/cpp: Implementation to read a given graph file.

2. shortestPath.hpp/cpp: A set of functions to find the shortest path between 2 given points using various implementations of Dijkstra's algorithm.

3. BinaryHeap.hpp/cpp: A binary heap implemntaion.

4. matrixDijkstra.cpp: Uses the matrixDijkstra implementation to find the shortest path b/w 2 given points in a graph.

5. listDijkstra.cpp: Uses the listDijkstra implementation to find the shortest path b/w 2 given points in a graph.

6. bellmanFord.cpp: Uses the Bellmond-Ford approach to find the shortest path b/w 2 given points in a graph.

7. currency.cpp: Uses the Bellmond-Ford approach to find the cheapest conversion path b/w 2 given currencies.

8. parallelDijkstra.cpp: Uses the multi-threaded matrixDijkstra implementation to find the shortest path b/w 2 given points in a graph.

9. mapqueue.cpp: An implementation of mapqueues.

10. readGraph_TEST.cpp: Tests for the readGraph methods.

11. shortestPath_TEST.cpp: Tests for the shortestPath methods.

12. BinaryHeap_TEST.cpp: Tests for the binary heap.

13. Makefile: A set of rules to run the code.

14. analysis.pdf: An analysis of the mutithreaded Matrix Dijkstra's implementation.

15. mapqueuefix.txt: A description of the mix to the mapqueue.

16. readme.txt: A guide to running this project
 



How to run ShortestPath:

    You will need the makefile.

    Basic:
        Let us have a .txt file named "graph.txt" in a folder with the above files. Choose a command (let us call x) from below, then open the command line terminal and type: make x followed by ./x graph.txt <output file name>.txt <Start Vertex Name> <End Vertex Name>. A file with the output file name will appear in the folder with the results. 

        matrixDijkstra: To run the matrixDijkstra algorithm.

        listDijkstra: To run the listDijkstra algorithm.

        bellmanFord: To run the bellman ford algorithm.

        currency: To find the currency concersion rates.

        parallelDijkstra: To find the shortest distance b/w two given points by a multithreaded matrixDijkstra. Here, you will also have to give the number of threads to use. The command should be like this ./x graph.txt <output file name>.txt <Start Vertex Name> <End Vertex Name> <number threads>.


How to run the mapqueue:

    Open the command line terminal and type: make mapqueue followed by ./mapqueue, and let the magic happen.


How to run tests:

    Write 'make runtests' (without the commas) on the command line terminal. The tests will run automatically. 




Bugs:

    If the length of the path/cycle is greater than the length of the "arr" array, it will be a problem. A remedy is just to go inside the code and change the length of the array.
