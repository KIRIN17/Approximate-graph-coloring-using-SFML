#pragma once

#include <SFML/Graphics.hpp>
#include "Graph.h"
#include <vector>

DynamicArray<Pair<int,int>> Painting_vertices(Graph& graph){
    std::srand(0);

    DynamicArray<Pair<int,DynamicArray<int>>> tmp_graph = graph.data;
    for (int i = 0; i < tmp_graph.GetSize(); ++i) {
        for (int j = 0; j < tmp_graph.GetSize(); ++j) {
            if(tmp_graph.Get(i).second.GetSize() >= tmp_graph.Get(j).second.GetSize()){
                Pair<int,DynamicArray<int>> tmp = tmp_graph.Get(i);
                tmp_graph.Get(i) = tmp_graph.Get(j);
                tmp_graph.Get(j) = tmp;
            }
        }
    }

    DynamicArray<int> vert(tmp_graph.GetSize());
    for (int i = 0; i < tmp_graph.GetSize(); ++i) {
        vert[i] = tmp_graph.Get(i).first;
    }

    DynamicArray<Pair<int,int>> ans(vert.GetSize());
    for (int i = 0; i < ans.GetSize(); ++i) {
        ans[i] = {vert[i],0};
    }

    int curr_color = rand();
    bool flag = true;

    for (int k = 0; k < ans.GetSize(); ++k) {
        if(ans[k].second == 0){
            ans[k].second = curr_color;

            for (int i = k; i < ans.GetSize(); ++i) {

                for (int j = i; j >= 0; --j) {
                    if (graph.Get(ans[j].first).is_there(ans[i].first) && ans[j].second == curr_color)
                        flag = false;
                }

                if (flag)
                    ans[i].second = curr_color;
                flag = true;
            }
            curr_color = rand();
        }
    }

    return ans;
}

void f(sf::RenderWindow& window,sf::CircleShape& shape,Graph& graph,DynamicArray<Pair<int,int>>& pos,
       DynamicArray<Pair<int,Pair<int,int>>>& colors,DynamicArray<Pair<int,int>>& res){

    int corr = 30;

    for (int i = 0; i < graph.vertices_count; ++i) {
        for (int j = 0; j < graph.Get(i).GetSize(); ++j) {
            sf::Vertex a(sf::Vector2f(pos[graph.Get(i).Get(j)].first + corr,pos[graph.Get(i).Get(j)].second + corr));
            a.color = sf::Color::Black;

            sf::Vertex b(sf::Vector2f(pos[i].first + corr,pos[i].second + corr));
            b.color = sf::Color::Black;
            sf::Vertex line[]{a, b};

            window.draw(line,2,sf::Lines);
        }
    }

    for (int i = 0; i < graph.vertices_count; ++i) {
        shape.setPosition(pos[i].first,pos[i].second);
        shape.setFillColor(sf::Color(colors[i].first,colors[i].second.first,colors[i].second.second));
        window.draw(shape);
    }

    sf::Font font;
    font.loadFromFile("Fonts/FontsFree-Net-Komika.ttf");

    for (int i = 0; i < graph.vertices_count; ++i) {
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(50);
        text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setString(std::to_string(i));
        text.setPosition(pos[i].first + corr / 2,pos[i].second);
        window.draw(text);
    }

}