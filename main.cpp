#include <SFML/Graphics.hpp>

#include <math.h>
#include <iostream>
#include "Functions.h"
#include "Tests.h"

int main()
{
    Test();

    const double PI = 3.141592653589793;
    std::srand(0);



    std::ifstream input1("Graph1.txt");
    Graph graph1(input1);

    int N = graph1.vertices_count;
    int width = 1200;
    int height = 900;
    int R = 30.f;

    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    sf::CircleShape shape(R);

    DynamicArray<Pair<int,int>> pos(N);
    int R_res_circle = std::sqrt(width*height/(PI * 3));

    double phi = 2 * PI / N;
    double step = 2 * PI / N;
    for (int i = 0; i < N; ++i) {
        pos[i].first = R_res_circle * std::sin(phi) + width/2;
        pos[i].second = R_res_circle * std::cos(phi) + height/2;

        phi += step;
    }




    DynamicArray<Pair<int,int>> colors_res = Painting_vertices(graph1);
    DynamicArray<Pair<int,Pair<int,int>>> colors(N);
    for (int i = 0; i < N; ++i) {
        colors[i].first = (1000 * colors_res[i].second) % 255;
        colors[i].second.first = (100 * colors_res[i].second) % 255;
        colors[i].second.second = (10 * colors_res[i].second) % 255;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));

        f(window,shape,graph1,pos,colors,colors_res);

        window.display();
    }

    return 0;
}