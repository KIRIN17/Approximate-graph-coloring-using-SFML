#pragma once

#include "DynamicArray.h"
#include "Pair.h"
#include <fstream>

class Graph{
public:
    int vertices_count;

    DynamicArray<Pair<int,DynamicArray<int>>> data;
    Graph(std::ifstream& input){

        input >> vertices_count;
        data.Resize(vertices_count);

        int index = 0;
        for (int i = 0; i < vertices_count; ++i) {

            int tmp_v;
            int size_of_close_set;
            input >> tmp_v >> size_of_close_set;

            DynamicArray<int> tmp_vicinity;
            for (int j = 0; j < size_of_close_set; ++j) {
                int tmp_vicinity_vertice;
                input >> tmp_vicinity_vertice;
                tmp_vicinity.Append(tmp_vicinity_vertice);
            }
            data[index] = {tmp_v,tmp_vicinity};
            index++;
        }

    }

    DynamicArray<int> Get(int value_num){

        for (int i = 0; i < data.GetSize(); ++i) {
            if(data.Get(i).first == value_num)
                return data.Get(i).second;
        }
        return DynamicArray<int>();
    }
};
