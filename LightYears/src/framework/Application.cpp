#include "framework/Application.h"

namespace ly {
    Application::Application() : m_Window{sf::VideoMode({1024,1440}), "Light Years ~ Made by Hiraeth"} {

    }

    void Application::Run() {
        while (m_Window.isOpen()) {
            while (const std::optional event = m_Window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    m_Window.close();
            }
        }
    }
}
