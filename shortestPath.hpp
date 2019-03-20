#ifndef SHORTEST_PATH
#define SHORTEST_PATH

#include "BinaryHeap.hpp"

//
void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev);

//
int getPath(int source, int dest, const int* prev, int*& path);

//
int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev);

//
int getCycle(int vertex, const int* prev, int numVertices, int*& cycle);

//
void dijkstra(const double* const * graph, int numVertices, int source, double*& dist, int*& prev, int numThreads);
//
void dijkstra(const int* const * adj, const double* const * weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev);
//
void Initialise(int numVertices, int source,double* dist, int* prev, bool* trac,int numThreads);
//
void getMinVertex(int numVertices, int source,double* dist, bool* trac,int numThreads, int* return_Value);
//
void UpdateDistances(const double* const * graph,int numVertices,int source,double* dist, int* prev, bool* trac, int x,int numThreads);

#endif