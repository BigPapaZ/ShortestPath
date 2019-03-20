#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "readGraph.hpp"
#include "fstream"
#include "iostream"

TEST_CASE("TESTS")
{
    SECTION("Matrix Read")
    {
        ifstream fin("graph.txt",ios_base::in);

        double** matrix;

        string* vLabels;

        string** eLabels;

        int n=readGraph(fin, matrix, vLabels, eLabels);        

        REQUIRE(n==4);
    }

    SECTION("Adjancey Read")
    {
        ifstream fin("graph.txt",ios_base::in);

        int** adj;

        double** weights;

        int* lengths;

        string* vLabels;

        string** eLabels;
        int n=readGraph(fin,adj, weights, lengths, vLabels, eLabels);

        REQUIRE(n==4);
   }

    SECTION("Bellmont Read")
    {
        ifstream fin("graph.txt",ios_base::in);

        int** edgeList;

        double* weights;

        int lengths;

        string* vLabels;

        string* eLabels;
        int n=readGraph(fin,edgeList, weights, lengths, vLabels, eLabels);

        REQUIRE(n==4);
    }
}