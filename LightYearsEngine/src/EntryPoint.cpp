#include <iostream>
#include "EntryPoint.h"
#include "framework/Application.h"
#include "framework/World.h"


int main()
{
    // actually got to the Game application
    ly::Application* app = GetApplication();

    if (!app) {
        std::cerr << "Failed to create application instance." << std::endl;
        return -1;
    }

    // loaded level here - was using to debug and testing
    //app->LoadWorld<ly::World>();



    app->Run();
    delete app;
    return 0;
}


