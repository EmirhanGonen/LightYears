#include <iostream>
#include "SFML/Graphics.hpp"

int main(int argc, char *argv[]) {
    sf::RenderWindow renderWindow{sf::VideoMode(sf::VideoMode({100, 100})), "My Window"};
    std::cout << "Hello World!" << std::endl;
}
