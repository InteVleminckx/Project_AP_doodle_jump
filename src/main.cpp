#include <iostream>
#include "Logic_libary/Stopwatch.h"
#include "Game_Representation/Game.h"
#include "Game_Representation/Player.h"
#include "Logic_libary/Subject.h"
#include "Logic_libary/Player.h"

using namespace std;

int main() {

    logic::Player player_L = logic::Player();
    auto player_R = representation::Player(player_L);
    player_L.addObserver(&player_R);

    logic::Stopwatch* stopwatch = logic::Stopwatch::Instance();

    bool isRunning = true;
    float frameRate = 60.0f;

    representation::Game game;

    while (game.isRunning())
    {
        stopwatch->Tick();
        if (stopwatch->GetDeltaTime() >= 1/frameRate)
        {
            stopwatch->Reset();
            cout << 1 / stopwatch->GetDeltaTime() << endl;
            game.getWindow()->clear(sf::Color::White);
            game.getWindow()->draw(player_R.getSprite());
            game.getWindow()->display();

        }

        game.updateWindow();

    }

    logic::Stopwatch::Release();

    return 0;
}