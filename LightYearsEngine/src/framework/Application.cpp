#include "framework/Application.h"
#include <iostream>

namespace ly {
    Application::Application()
        : m_Window{sf::VideoMode({1024, 1440}), "Light Years ~ Made by Hiraeth"},
          m_TargetFrameRate{30.00f},
          m_TickClock{} {
    }

    void Application::Run() {
        m_TickClock.reset();
        float accumulatedTime = 0.00f;
        float targetDeltaTime = 1.00f / m_TargetFrameRate;
        while (m_Window.isOpen()) {
            while (const std::optional event = m_Window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    m_Window.close();
            }

            accumulatedTime += m_TickClock.restart().asSeconds();
            while (accumulatedTime >= targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }

    void Application::TickInternal(float deltaTime) {
        Tick(deltaTime);
    }

    void Application::Tick(float deltaTime) {
        std::cout << "ticking at framerate: " << 1.00f / deltaTime << std::endl;
    }

    void Application::RenderInternal() {
        m_Window.clear();

        Render();

        m_Window.display();
    }

    void Application::Render() {
        sf::RectangleShape rect{sf::Vector2f(100.00f, 100.00f)};
        rect.setFillColor(sf::Color::Green);
        m_Window.draw(rect);
    }
}
