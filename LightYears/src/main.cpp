#include <iostream>
#include "framework/Application.h"
#include <memory>

int main(int argc, char *argv[]) {
    std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
    app->Run();
}
