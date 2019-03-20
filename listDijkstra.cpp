#include "readGraph.hpp"
#include "shortestPath.hpp"
#include "fstream"
#include "iostream"
#include "chrono"
#include "ctime"

int main(int argc, char** argv)
{
    string in_file_name=argv[1];
    string out_file_name=argv[2];
    string head=argv[3];
    string tail=argv[4];


    ifstream fin(in_file_name,ios_base::in);

    int** adj;
    double** weights;
    int* lengths;
    string* vLabels;
    string** eLabels;
    int* path;
    double* distances;
    int* previous;
    double total_distance;

    int n=readGraph(fin,adj, weights, lengths, vLabels, eLabels);

    int head_num;
    int tail_num;

    for(int i=0;i<n;i++)
    {
        if(vLabels[i]==head)
        {
            head_num=i;
        }
        else if(vLabels[i]==tail)
        {
            tail_num=i;
        }
    }


    auto start = chrono::system_clock::now(); 
    dijkstra(adj, weights, lengths, n, head_num,distances,previous);

    int size=getPath(head_num,tail_num,previous,path);

    fstream output(out_file_name,ios_base::out);

    output<<n<<" ";
    output<<size<<endl;
    for(int i=0;i<n;i++){output<<vLabels[i]<<endl;}
    for(int i=0;i<size;i++)
    {
        output<<path[i]<<" ";
        output<<path[i+1]<<" ";
        int next_index=0;
        if(lengths[path[i]]>1)
        {
            while(adj[path[i]][next_index]!=path[i+1]&&next_index<lengths[path[i]])
            {
                next_index++;
            }
        }
        total_distance+=weights[path[i]][next_index];
        output<<weights[path[i]][next_index]<<" ";
        output<<eLabels[path[i]][next_index]<<endl;
    }

    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto durS = chrono::duration_cast<chrono::microseconds>(dur);
    long long serialTime = durS.count();
    cout<< "Total Distance: "<<total_distance<<endl;
    cout<< "Runtime: " << serialTime << " microseconds" << endl;

    for(int i=0;i<n;i++)
    {
        delete[] adj[i];
        delete[] weights[i];
        delete[] eLabels[i];
    }

    delete[] adj;
    delete[] weights;
    delete[] eLabels;
    delete[] lengths;
    delete[] vLabels;
    delete[] path;
    delete[] distances;
    delete[] previous;
}