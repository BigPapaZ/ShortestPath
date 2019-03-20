#include "readGraph.hpp"
#include "iostream"
#include <fstream>
#include "vector"
#include <limits>

using namespace std;

int readGraph(ifstream& fin, double**& matrix, string*& vLabels, string**& eLabels)
{
    string d;
    string n;
    fin>>d;
    fin>>n;

    int numVertices=stoi(d);
    int numEdges=stoi(n);

    matrix=new double*[numVertices];
    vLabels=new string[numVertices];
    eLabels=new string*[numVertices];

    for(int i=0;i<numVertices;i++)
    {
        string* temp=new string[numVertices];
//        string* x=eLabels[i];

        eLabels[i]=temp;
        //delete x;
    }

    for(int i=0;i<numVertices;i++)
    {
        double* temp=new double[numVertices];

        matrix[i]=temp;

        for(int j=0;j<numVertices;j++)
        {
            if(i==j)matrix[i][j]=0;
            else matrix[i][j]=numeric_limits<double>::infinity();
        }
    }

    for(int i=0;i<numVertices;i++)
    {
        fin>>vLabels[i];
    }

    for(int i=0;i<numEdges;i++)
    {
        string start; fin>>start;         
        string ed; fin>>ed;               
        string weight; fin>>weight;    
        string name; fin>>name;        

        matrix[stoi(start)][stoi(ed)]=stod(weight);
        eLabels[stoi(start)][stoi(ed)]=name;
    }

    return numVertices;
}


int readGraph(ifstream& fin, int**& adj, double**& weights, int*& lengths, string*& vLabels, string**& eLabels)
{
    //maybe might need an array copier method which increments things by one
    string d;
    string n;
    fin>>d;
    fin>>n;

    int numVertices=stoi(d);
    int numEdges=stoi(n);



    string* names=new string[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        fin>>names[i];
//        cout<<i<<" "<<names[i]<<endl;
    }


    int* lengths1=new int[numVertices];
    double** weight=new double*[numVertices];
    string** edge_names=new string*[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        lengths1[i]=0;
    }

    int** m=new int*[numVertices];
    
    string previous;
    fin>>previous;


    int traker=0;
    for(int i=0;i<numVertices;i++)
    {
        //assuming that everything has an edge with something else
        vector<int>* v=new vector<int>(0);
        vector<double>* v1=new vector<double>(0);
        vector<string>* v2=new vector<string>(0);
        int x=0;
        while(traker<numEdges&&stoi(previous)==i)
        {
            string link;
            fin>>link;
            v->insert(v->begin()+x,stoi(link));
            fin>>link;
            v1->insert(v1->begin()+x,stod(link));
            fin>>link;
            v2->insert(v2->begin()+x,link);
            fin>>previous;
            x++;
            traker++;
        }
        lengths1[i]=x;

        vector<int>::iterator iter = v->begin();
        vector<double>::iterator iter1 = v1->begin();
        vector<string>::iterator iter2 = v2->begin();

        int* temp_adj=new int[x];
        double* temp_weights=new double[x];
        string* temp_names=new string[x];

        for(int j=0;j<x;j++)
        {
            temp_adj[j]=*(iter+j);
            temp_weights[j]=*(iter1+j);
            temp_names[j]=*(iter2+j);
        }

        m[i]=temp_adj;
        weight[i]=temp_weights;
        edge_names[i]=temp_names;
    }

    adj=m;
    vLabels=names;
    lengths=lengths1;
    weights=weight;
    eLabels=edge_names;

    return numVertices;
}

int readGraph(ifstream& fin, int**& edgeList, double*& weights, int& numEdges, string*& vLabels, string*& eLabels)
{
    string d;
    string n;
    fin>>d;
    fin>>n;

    int numVertices=stoi(d);
    numEdges=stoi(n);

    vLabels=new string[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        fin>>vLabels[i];
    }

    edgeList=new int*[numEdges];
    weights=new double[numEdges];
    eLabels=new string[numEdges];
    
    for(int i=0;i<numEdges;i++)
    {
        string prev; fin>>prev;
        string next; fin>>next;

        int* temp=new int[2];
        temp[0]=stoi(prev);temp[1]=stoi(next);
        edgeList[i]=temp;

        string weight; fin>>weight;
        weights[i]=stod(weight);
        
        string edge_Name; fin>>edge_Name;
        eLabels[i]=edge_Name;
    }

    return numVertices;
}