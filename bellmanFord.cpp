#include "readGraph.hpp"
#include "shortestPath.hpp"
#include "fstream"
#include "iostream"
#include "chrono"
#include "ctime"



double printer(int n,int size,int numEdges,string out_file_name,int* cycle_path,string* vLabels,double* weights,string* eLabels,int** edgeList)
{
    fstream output(out_file_name,ios_base::out);

    output<<n<<" ";
    output<<size<<" "<<endl;

    for(int i=0;i<n;i++)
    {
        output<<vLabels[i]<<endl;
    }
    double y=0;

    for(int i=0;i<size;i++)
    {
        output<<cycle_path[i]<<" ";
        output<<cycle_path[i+1]<<" ";

        for(int j=0;j<numEdges;j++)
        {
            if(cycle_path[i]==edgeList[j][0]&&cycle_path[i+1]==edgeList[j][1])
            {
                y+=weights[j];
                output<<weights[j]<<" ";
                output<<eLabels[j]<<endl;
            }
        }
    }
    return y;
}


int main(int argc, char** argv)
{
    string in_file_name=argv[1];
    string out_file_name=argv[2];
    string head=argv[3];
    string tail=argv[4];

    ifstream fin(in_file_name,ios_base::in);

    int** edgeList;

    double* weights;

    int numEdges;

    string* vLabels;

    string* eLabels;
    int n=readGraph(fin,edgeList, weights, numEdges, vLabels, eLabels);

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

    int stuff=bellmanFord(edgeList, weights, n, numEdges, head_num, dist, prev);

    double y=0;

    int* cycle_path;


    int size;
    if(stuff>-1)
    {
        size=getCycle(stuff,prev,n,cycle_path);
        cout<<"Negative Cycle detected"<<endl;
    }

    else
    {
        size=getPath(head_num,tail_num,prev,cycle_path);
    }
    
    y=printer(n,size,numEdges,out_file_name,cycle_path,vLabels,weights,eLabels,edgeList);

    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto durS = chrono::duration_cast<chrono::microseconds>(dur);
    long long serialTime = durS.count();
    cout << "Total Distance: "<<y<<endl;
    cout << "Runtime: " << serialTime << " microseconds" << endl;


    for(int i=0;i<n;i++){delete[] edgeList[i];}
    delete[] edgeList;
    delete[] weights;
    delete[] vLabels;
    delete[] eLabels;
    delete[] dist;
    delete[] prev;
    delete[] cycle_path;
}