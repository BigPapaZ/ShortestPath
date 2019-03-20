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

    double** matrix;
    string* vLabels; 
    string** eLabels;

    int n=readGraph(fin, matrix, vLabels, eLabels);

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

    double* dist;
    int* prev;

    auto start = chrono::system_clock::now(); 
    dijkstra(matrix,n, head_num, dist, prev);
    int* path;
    int size=getPath(head_num,tail_num,prev,path);
    fstream output(out_file_name,ios_base::out);
    output<<n<<" ";
    output<<size<<endl;
    for(int i=0;i<n;i++){output<<vLabels[i]<<endl;}
    double total_distance=0;
    for(int i=0;i<size;i++)
    {
        output<<path[i]<<" ";
        output<<path[i+1]<<" ";
        total_distance+=matrix[path[i]][path[i+1]];
        output<<matrix[path[i]][path[i+1]]<<" ";
        output<<eLabels[path[i]][path[i+1]]<<endl;
    }

    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto durS = chrono::duration_cast<chrono::microseconds>(dur);
    long long serialTime = durS.count();
    cout<< "Total Distance: "<<total_distance<<endl;
    cout<< "Runtime: " << serialTime << " microseconds" << endl;

    for(int i=0;i<n;i++)
    {
        delete[] matrix[i];
        delete[] eLabels[i];
    }
    
    delete[] matrix;
    delete[] vLabels; 
    delete[] eLabels;
    delete[] dist;
    delete[] prev;
    delete[] path;
}