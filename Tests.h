#include "Graph.h"
void Test(){

    {
        std::ifstream input1("Graph3.txt");
        Graph graph2(input1);
        DynamicArray<Pair<int,int>> res = Painting_vertices(graph2);
        if(res[0].second != res[1].second){
            std::cerr << "ERROR !\n";
            std::exit(0);
        }

        std::cerr << "ALL TESTS ARE DONE !\n";
    }
}