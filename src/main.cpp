#include <iostream>
#include "Logic_libary/Stopwatch.h"
using namespace std;

int main() {

    logic::Stopwatch* stopwatch = logic::Stopwatch::Instance();

    bool isRunning = true;
    float frameRate = 60.0f;

    while (isRunning)
    {
        stopwatch->Tick();

        if (stopwatch->GetDeltaTime() >= 1/frameRate)
        {
            stopwatch->Reset();
            cout << 1 / stopwatch->GetDeltaTime() << endl;
            //update()
            //Render()
        }

    }

    logic::Stopwatch::Release();

    return 0;
}