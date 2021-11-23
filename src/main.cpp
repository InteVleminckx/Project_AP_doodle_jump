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

    logic::Player_L player_L = logic::Player_L();
    auto player_R = representation::Player(player_L);
    player_L.addObserver(&player_R);

    logic::Platform_L_horizontal platformLHorizontal = logic::Platform_L_horizontal();
    auto PlatformH = representation::Platform_horizontal(platformLHorizontal);
    platformLHorizontal.addObserver(&PlatformH);


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
            player_R.update();
            PlatformH.update();
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
