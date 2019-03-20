#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "readGraph.hpp"
#include "shortestPath.hpp"
#include "BinaryHeap.hpp"
#include "fstream"
#include "iostream"
#include <atomic>
#include "mutex"

TEST_CASE("TESTS")
{
    SECTION("Matrix")
    {
        SECTION("dijkstra")
        {
            ifstream fin("graph.txt",ios_base::in);

            double** matrix;

            string* vLabels;

            string** eLabels;

            int n=readGraph(fin, matrix, vLabels, eLabels);        
            
            REQUIRE(n==4);

            double* distances;
            int* previous;

            dijkstra(matrix,n,0,distances,previous);
        }


        SECTION("pathFinder")
        {
            ifstream fin("graph.txt",ios_base::in);

            double** matrix;

            string* vLabels;

            string** eLabels;

            int n=readGraph(fin, matrix, vLabels, eLabels);        
            
            REQUIRE(n==4);

            double* distances;
            int* previous;

            int* path;

            dijkstra(matrix,n,0,distances,previous);
            int size=getPath(0,1,previous,path);
            REQUIRE(size==2);
            size=getPath(0,2,previous,path);
            REQUIRE(size==3);
            size=getPath(0,3,previous,path);
            REQUIRE(size==1);
            size=getPath(0,0,previous,path);
            REQUIRE(size==0);

            dijkstra(matrix,n,1,distances,previous);
            size=getPath(1,0,previous,path);
            REQUIRE(size==2);
            size=getPath(1,1,previous,path);
            REQUIRE(size==0);
            size=getPath(1,2,previous,path);
            REQUIRE(size==1);
            size=getPath(1,3,previous,path);
            REQUIRE(size==2);            
            
            dijkstra(matrix,n,2,distances,previous);
            size=getPath(2,0,previous,path);
            REQUIRE(size==1);
            size=getPath(2,1,previous,path);
            REQUIRE(size==2);
            size=getPath(2,2,previous,path);
            REQUIRE(size==0);
            size=getPath(2,3,previous,path);
            REQUIRE(size==1);
            
            dijkstra(matrix,n,3,distances,previous);
            size=getPath(3,0,previous,path);
            REQUIRE(size==3);
            size=getPath(3,1,previous,path);
            REQUIRE(size==1);
            size=getPath(3,2,previous,path);
            REQUIRE(size==2);
            size=getPath(3,3,previous,path);
            REQUIRE(size==0);
       }

        SECTION("dijkstra..mutithread")
        {
            ifstream fin("graph.txt",ios_base::in);

            double** matrix;

            string* vLabels;

            string** eLabels;

            int* path;

            int n=readGraph(fin, matrix, vLabels, eLabels);

            double* distances;
            int* previous;

            dijkstra(matrix,n,0,distances,previous,1);
            int size=getPath(0,1,previous,path);
            REQUIRE(size==2);
            size=getPath(0,2,previous,path);
            REQUIRE(size==3);
            size=getPath(0,3,previous,path);
            REQUIRE(size==1);
            size=getPath(0,0,previous,path);
            REQUIRE(size==0);

            dijkstra(matrix,n,1,distances,previous,1);
            size=getPath(1,0,previous,path);
            REQUIRE(size==2);
            size=getPath(1,1,previous,path);
            REQUIRE(size==0);
            size=getPath(1,2,previous,path);
            REQUIRE(size==1);
            size=getPath(1,3,previous,path);
            REQUIRE(size==2);            
            
            dijkstra(matrix,n,2,distances,previous,1);
            size=getPath(2,0,previous,path);
            REQUIRE(size==1);
            size=getPath(2,1,previous,path);
            REQUIRE(size==2);
            size=getPath(2,2,previous,path);
            REQUIRE(size==0);
            size=getPath(2,3,previous,path);
            REQUIRE(size==1);
            
            dijkstra(matrix,n,3,distances,previous,1);
            size=getPath(3,0,previous,path);
            REQUIRE(size==3);
            size=getPath(3,1,previous,path);
            REQUIRE(size==1);
            size=getPath(3,2,previous,path);
            REQUIRE(size==2);
            size=getPath(3,3,previous,path);
            REQUIRE(size==0);

            dijkstra(matrix,n,0,distances,previous,2);
            size=getPath(0,1,previous,path);
            REQUIRE(size==2);
            size=getPath(0,2,previous,path);
            REQUIRE(size==3);
            size=getPath(0,3,previous,path);
            REQUIRE(size==1);
            size=getPath(0,0,previous,path);
            REQUIRE(size==0);

            dijkstra(matrix,n,1,distances,previous,2);
            size=getPath(1,0,previous,path);
            REQUIRE(size==2);
            size=getPath(1,1,previous,path);
            REQUIRE(size==0);
            size=getPath(1,2,previous,path);
            REQUIRE(size==1);
            size=getPath(1,3,previous,path);
            REQUIRE(size==2);            
            
            dijkstra(matrix,n,2,distances,previous,2);
            size=getPath(2,0,previous,path);
            REQUIRE(size==1);
            size=getPath(2,1,previous,path);
            REQUIRE(size==2);
            size=getPath(2,2,previous,path);
            REQUIRE(size==0);
            size=getPath(2,3,previous,path);
            REQUIRE(size==1);
            
            dijkstra(matrix,n,3,distances,previous,2);
            size=getPath(3,0,previous,path);
            REQUIRE(size==3);
            size=getPath(3,1,previous,path);
            REQUIRE(size==1);
            size=getPath(3,2,previous,path);
            REQUIRE(size==2);
            size=getPath(3,3,previous,path);
            REQUIRE(size==0);
            
            dijkstra(matrix,n,0,distances,previous,3);
            size=getPath(0,1,previous,path);
            REQUIRE(size==2);
            size=getPath(0,2,previous,path);
            REQUIRE(size==3);
            size=getPath(0,3,previous,path);
            REQUIRE(size==1);
            size=getPath(0,0,previous,path);
            REQUIRE(size==0);

            dijkstra(matrix,n,1,distances,previous,3);
            size=getPath(1,0,previous,path);
            REQUIRE(size==2);
            size=getPath(1,1,previous,path);
            REQUIRE(size==0);
            size=getPath(1,2,previous,path);
            REQUIRE(size==1);
            size=getPath(1,3,previous,path);
            REQUIRE(size==2);            
            
            dijkstra(matrix,n,2,distances,previous,3);
            size=getPath(2,0,previous,path);
            REQUIRE(size==1);
            size=getPath(2,1,previous,path);
            REQUIRE(size==2);
            size=getPath(2,2,previous,path);
            REQUIRE(size==0);
            size=getPath(2,3,previous,path);
            REQUIRE(size==1);
            
            dijkstra(matrix,n,3,distances,previous,3);
            size=getPath(3,0,previous,path);
            REQUIRE(size==3);
            size=getPath(3,1,previous,path);
            REQUIRE(size==1);
            size=getPath(3,2,previous,path);
            REQUIRE(size==2);
            size=getPath(3,3,previous,path);
            REQUIRE(size==0);
            
            dijkstra(matrix,n,0,distances,previous,4);
            size=getPath(0,1,previous,path);
            REQUIRE(size==2);
            size=getPath(0,2,previous,path);
            REQUIRE(size==3);
            size=getPath(0,3,previous,path);
            REQUIRE(size==1);
            size=getPath(0,0,previous,path);
            REQUIRE(size==0);

            dijkstra(matrix,n,1,distances,previous,4);
            size=getPath(1,0,previous,path);
            REQUIRE(size==2);
            size=getPath(1,1,previous,path);
            REQUIRE(size==0);
            size=getPath(1,2,previous,path);
            REQUIRE(size==1);
            size=getPath(1,3,previous,path);
            REQUIRE(size==2);            
            
            dijkstra(matrix,n,2,distances,previous,4);
            size=getPath(2,0,previous,path);
            REQUIRE(size==1);
            size=getPath(2,1,previous,path);
            REQUIRE(size==2);
            size=getPath(2,2,previous,path);
            REQUIRE(size==0);
            size=getPath(2,3,previous,path);
            REQUIRE(size==1);
            
            dijkstra(matrix,n,3,distances,previous,4);
            size=getPath(3,0,previous,path);
            REQUIRE(size==3);
            size=getPath(3,1,previous,path);
            REQUIRE(size==1);
            size=getPath(3,2,previous,path);
            REQUIRE(size==2);
            size=getPath(3,3,previous,path);
            REQUIRE(size==0);
        }
   }

    SECTION("Adjancey List")
    {
        SECTION("dijkstra")
        {
            ifstream fin("graph.txt",ios_base::in);

            int** adj;

            double** weights;

            int* lengths;

            string* vLabels;

            string** eLabels;
            
            int n=readGraph(fin,adj, weights, lengths, vLabels, eLabels);

            double* distances;
            int* previous;

            dijkstra(adj, weights, lengths, n, 0,distances,previous);
            REQUIRE(distances[0]==0);
            dijkstra(adj, weights, lengths, n, 1,distances,previous);
            REQUIRE(distances[1]==0);
            dijkstra(adj, weights, lengths, n, 2,distances,previous);
            REQUIRE(distances[2]==0);
            dijkstra(adj, weights, lengths, n, 3,distances,previous);
            REQUIRE(distances[3]==0);
        }
    }

    SECTION("Bellmont ford")
    {
        ifstream fin("graph.txt",ios_base::in);

        int** edgeList;

        double* weights;

        int numEdges;

        string* vLabels;

        string* eLabels;
        int n=readGraph(fin,edgeList, weights, numEdges, vLabels, eLabels);

        double* dist;
        int* prev;

        int stuff=bellmanFord(edgeList, weights, n, numEdges, 0, dist, prev);
        REQUIRE(stuff==-1);

        stuff=bellmanFord(edgeList, weights, n, numEdges, 1, dist, prev);
        REQUIRE(stuff==-1);

        stuff=bellmanFord(edgeList, weights, n, numEdges, 2, dist, prev);
        REQUIRE(stuff==-1);

        stuff=bellmanFord(edgeList, weights, n, numEdges, 3, dist, prev);
        REQUIRE(stuff==-1);
    }

    SECTION("getCycle")
    {
        ifstream fin("graph2.txt",ios_base::in);

        int** edgeList;

        double* weights;

        int numEdges;

        string* vLabels;

        string* eLabels;
        int n=readGraph(fin,edgeList, weights, numEdges, vLabels, eLabels);

        double* dist;
        int* prev;

        int size;

        int stuff=bellmanFord(edgeList, weights, n, numEdges, 0, dist, prev);
        size=getCycle(stuff,prev,n,prev);
        REQUIRE(size==4);
        stuff=bellmanFord(edgeList, weights, n, numEdges, 1, dist, prev);
        size=getCycle(stuff,prev,n,prev);
        REQUIRE(size==4);
        stuff=bellmanFord(edgeList, weights, n, numEdges, 2, dist, prev);
        size=getCycle(stuff,prev,n,prev);
        REQUIRE(size==4);
        stuff=bellmanFord(edgeList, weights, n, numEdges, 3, dist, prev);
        size=getCycle(stuff,prev,n,prev);
        REQUIRE(size==4);
    }
}