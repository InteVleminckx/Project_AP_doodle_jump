#include <iostream>
#include "Logic_libary/Stopwatch.h"
#include "Game_Representation/Game.h"
#include "Game_Representation/Player.h"
#include "Logic_libary/Player.h"
#include "Game_Representation/Window.h"
#include "Game_Representation/Platform.h"
#include "Logic_libary/Platform.h"

using namespace std;

int main() {

    shared_ptr<logic::Subject> player_L = shared_ptr<logic::Player_L> (new logic::Player_L);
    player_L->addObserver(shared_ptr<logic::Observer> (new representation::Player(player_L)));

    shared_ptr<logic::Subject> platform_L = shared_ptr<logic::Platform_L_horizontal> (new logic::Platform_L_horizontal);
    platform_L->addObserver(shared_ptr<logic::Observer> (new representation::Platform_horizontal(platform_L)));


    logic::Stopwatch* stopwatch = logic::Stopwatch::Instance();
    representation::Window* window = representation::Window::Instance();

    float frameRate = 60.0f;

    representation::Game game;

    while (window->isOpen())
    {
        stopwatch->Tick();
        if (stopwatch->GetDeltaTime() >= 1/frameRate)
        {
            window->getWindow()->clear(sf::Color::White);
            player_L->Notify();
            platform_L->Notify();

            window->getWindow()->display();
            stopwatch->Reset();
//            cout << 1 / stopwatch->GetDeltaTime() << endl;

        }
        window->update();
    }

    logic::Stopwatch::Release();
    representation::Window::Release();

    return 0;
}
