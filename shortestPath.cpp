#include <limits>
#include "shortestPath.hpp"
#include "BinaryHeap.hpp"
#include "iostream"
#include "thread"
#include <cstdlib>

using namespace std;

void dijkstra(const double* const * matrix, int numVertices, int source, double*& dist, int*& prev)
{
    double min=numeric_limits<double>::infinity();

    bool* tracker=new bool[numVertices];

    int* prev1=new int[numVertices];
    double* dist1=new double[numVertices];

    for(int i=0;i<numVertices;i++)
    {
        dist1[i]=numeric_limits<double>::infinity();
        tracker[i]=0;
        prev1[i]=0;
    }

    dist1[source]=0;
    tracker[source]=1;
    int n=source;

    for(int i=1;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            if(!tracker[j]&&dist1[n]+matrix[n][j]<dist1[j])
            {
                dist1[j]=dist1[n]+matrix[n][j];
                prev1[j]=n;
            }
        }
        
        min=numeric_limits<double>::infinity();

        for(int j=0;j<numVertices;j++)
        {
            if(!tracker[j]&&dist1[j]<min)
            {
                n=j;
                min=dist1[j];
            }
        }
        tracker[n]=1;
    }

    delete[] tracker;

    prev=prev1;
    dist=dist1;
}


int getPath(int source, int dest, const int* prev, int*& path)
{ 
    int destination=dest;
    int size=0;

    int arr[100] = {};

    while(dest!=source)
    {
        arr[size]=prev[dest];
        dest=prev[dest];
        size++;
    }

    path = new int[size+1];

    for(int i=0;i<size;i++)
    {
        path[i]=arr[size-i-1];
    }

    path[size]=destination;

    return size;
}

int bellmanFord(const int* const * edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev)
{
    dist=new double[numEdges];
    prev=new int[numEdges];

    for(int i=0;i<numEdges;i++)
    {
        dist[i]=numeric_limits<double>::infinity();
    }

    dist[source]=0;

    for(int i=0;i<numVertices-1;i++)
    {
        for(int j=0;j<numEdges;j++)
        {
            if(dist[edges[j][1]]>dist[edges[j][0]]+weights[j])
            {
                dist[edges[j][1]]=dist[edges[j][0]]+weights[j];
                prev[edges[j][1]]=edges[j][0];
            }
        }
    }

    int whatever=-1;
    bool x=1;
    for(int j=0;j<numEdges;j++)
    {
        if(dist[edges[j][1]]>dist[edges[j][0]]+weights[j])
        {
            dist[edges[j][1]]=dist[edges[j][0]]+weights[j];
            prev[edges[j][1]]=edges[j][0];
            if(x){whatever=edges[j][1];x=0;}
        }
    }
    return whatever;
}

int getCycle(int vertex, const int* prev, int numVertices, int*& cycle)
{
    int dest=prev[vertex];
    int size=0;
    bool trac[numVertices]={0};

    int arr[100] = {};

    int size_repeats=0;

    while(dest!=vertex&&!trac[dest])
    {
        arr[size]=dest;
        trac[dest]=1;
        dest=prev[dest];
        size++;

        if(trac[dest])
        {
            size_repeats++;
            int dest1=prev[vertex];
            while(dest!=dest1)
            {
                dest1=prev[dest1];
                size_repeats++;
            }
        }
    }

    arr[size]=dest;
    dest=prev[dest];
    size++;

    cycle= new int[size+1-size_repeats];

    for(int i=0;i<size-size_repeats;i++)
    {
        cycle[i]=arr[size-i-1-size_repeats];
    }

    cycle[size-size_repeats]=vertex;

    return size;
}


void dijkstra(const double* const * graph, int numVertices, int source, double*& dist, int*& prev, int numThreads)
{
    if(numThreads>numVertices)
    {
        numThreads=numVertices;
    }

    bool* trac=new bool[numVertices];

    prev=new int[numVertices];
    dist=new double[numVertices];

    Initialise(numVertices,0,dist,prev,trac,numThreads);

    dist[source]=0;

    for(int j=1;j<numVertices;j++)
    {
        int x;
        getMinVertex(numVertices,0,dist,trac,numThreads,&x);

        trac[x]=1;

        UpdateDistances(graph,numVertices,0,dist,prev,trac,x,numThreads);
    }
    delete[] trac;
}


void getMinVertex(int numVertices,int source,double* dist, bool* trac,int numThreads,int* return_Value)
{
    if(numVertices==source+1)
    {
        if((!trac[source])&&dist[source]<numeric_limits<double>::infinity()){*return_Value=source;}
        else
        {
            *return_Value=-1;
        }
    }
    else if(numThreads==1)
    {
        double min_dist=numeric_limits<double>::infinity();
        int minVeretex=-1;

        for(int i=source;i<numVertices;i++)
        {if(!trac[i]&&dist[i]<min_dist)
        {minVeretex=i;min_dist=dist[i];}}
        *return_Value=minVeretex;
    }

    else
    {
        int q = numThreads/2;
        int m=source+q*((numVertices-source)/numThreads);

        int x;
        int y;

        thread leftT(getMinVertex,m,source,dist,trac,q,&x);
        getMinVertex(numVertices,m,dist,trac,numThreads-q,&y);

        leftT.join();

        if(x!=-1&&y!=-1)
        {
            if(dist[x]>dist[y]){*return_Value=y;}
            else{*return_Value=x;}
        }
        else if(x!=-1){*return_Value=x;}
        else{*return_Value=y;}
    }
}

void UpdateDistances(const double* const * graph,int numVertices,int source,double* dist, int* prev, bool* trac, int n,int numThreads)
{
    if(numVertices==source+1)
    {
        if(!trac[source]&&dist[n]+graph[n][source]<dist[source])
        {
            dist[source]=dist[n]+graph[n][source];
            prev[source]=n;
        }
    }

    else if(numThreads==1)
    {
        for(int j=source;j<numVertices;j++)
        {
            if(!trac[j]&&dist[n]+graph[n][j]<dist[j])
            {dist[j]=dist[n]+graph[n][j];prev[j]=n;}
        }
    }

    else if(numVertices!=0)
    {
        int q = numThreads/2;
        int m=source+q*((numVertices-source)/numThreads);
        thread leftT(UpdateDistances,graph,m,source,dist,prev,trac,n,q);
        UpdateDistances(graph,numVertices,m,dist,prev,trac,n,numThreads-q);
        leftT.join();
    }
}

void Initialise(int numVertices, int source,double* dist, int* prev, bool* trac,int numThreads)
{
    if(numVertices==source+1)
    {
        dist[source]=numeric_limits<double>::infinity();
        trac[source]=0;
        prev[source]=0;
    }

    else if(numThreads==1)
    {
        for(int i=source;i<numVertices;i++)
        {
            dist[i]=numeric_limits<double>::infinity();
            trac[i]=0;
            prev[i]=0;
        }
    }
    else if(numVertices!=0)
    {
        int q = numThreads/2;
        int m=source+q*((numVertices-source)/numThreads);
        thread leftT(Initialise,m,source,dist,prev,trac,q);
        Initialise(numVertices,m,dist,prev,trac,numThreads-q);
        leftT.join();
    }
}

void dijkstra(const int* const * adj, const double* const * weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev)
{
    prev=new int[numVertices];
    dist=new double[numVertices];

    for(int i=0;i<numVertices;i++)
    {
        dist[i]=numeric_limits<double>::infinity();
        prev[i]=0;
    }

    BinaryHeap H=BinaryHeap(dist,numVertices);

    H.decreasePriority(source,0);

    int n=H.getMin();

    H.popMin();

    dist[n]=0;

    for(int i=0;i<numVertices-1;i++)
    {
        for(int j=0;j<lengths[n];j++)
        {
            int x=adj[n][j];

            if(H.contains(x)&&dist[n]+weights[n][j]<H.getPriority(x))
            {
                H.decreasePriority(x,dist[n]+weights[n][j]);
                prev[x]=n;
            }
        }

        n=H.getMin();
        dist[n]=H.getPriority(n);
        H.popMin();
    }
}