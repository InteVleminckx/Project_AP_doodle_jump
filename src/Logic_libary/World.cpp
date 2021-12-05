//
// Created by inte on 11/18/21.
//

#include "World.h"

namespace logic {


    World::World() {

    }

    void World::createPlayer(shared_ptr<EntityFactory> &factory)
    {
        m_player = std::make_shared<logic::Player_L> (.0f, 1.f, .15f, .09f);
        factory->createPlayer(m_player);
        m_player->jump();
    }

    void World::createPlatform(shared_ptr<EntityFactory> &factory)
    {
        shared_ptr<logic::Subject> platform;

        //ToDo: bepaal een random type van het platform met de random functie
        _Platform type  = Static;

        switch (type) {
            case Static:
                platform = make_shared<logic::Platform_L_static>(0.0f, -.75f, .2f, .035f);
                break;
            case Horizontal:
                 platform = std::make_shared<logic::Platform_L_horizontal> (0.0f, -.5f, .2f, .035f);
                break;
            case Vertical:
                platform = std::make_shared<logic::Platform_L_vertical> (0.0f, -.5f, .2f, .035f);
                break;
            case Temporary:
                platform = std::make_shared<logic::Platform_L_temporary> (0.0f, -.5f, .2f, .035f);
        }
        factory->createPlatform(platform, type);
        m_platforms.push_back(platform);
    }

    void World::createBonus(shared_ptr<EntityFactory> &factory)
    {
        shared_ptr<logic::Subject> bonus;
//        switch (type) {
//            case Rocket:
//
//            case Spring:
//
//        }
    }

    void World::createBG_Tile(shared_ptr<EntityFactory> &factory)
    {
        shared_ptr<logic::Subject> tile = std::make_shared<logic::BG_Tile> ();
        factory->createBG_Tile(tile);
        m_BGtiles.push_back(tile);
    }

    void World::updateEntities() {

        m_player->gravity();
        if (playerTouchesPlatform()) m_player->jump();
        else {
        }
        m_player->Notify();
        for (const auto& entity : m_BGtiles) entity->Notify();
        for (const auto& entity : m_platforms) entity->Notify();
        for (const auto& entity : m_bonussen) entity->Notify();
    }

    void World::releaseObservers() {
        m_player->emptyObserver();
        for (const auto& entity : m_BGtiles) entity->emptyObserver();
        for (const auto& entity : m_platforms) entity->emptyObserver();
        for (const auto& entity : m_bonussen) entity->emptyObserver();
    }

    void World::movePlayerRight() {
        m_player->moveRight();
    }

    void World::movePlayerLeft() {
        m_player->moveLeft();
    }

    bool World::playerTouchesPlatform() {

        vector<pair<float, float>> leftPlayer, rightPlayer;
        getPointsBetweenFrames(leftPlayer, rightPlayer, m_player);

        for (const auto &platform : m_platforms)
        {
            vector<pair<float, float>> leftPlatform, rightPlatfrom;
            getPointsBetweenFrames(leftPlatform, rightPlatfrom, platform);

            for (int i = 0; i < leftPlayer.size(); i++) {

                //static, controller of de y-waarde van de player tussen het platform ligt
                if (leftPlatform.size() == 1 &&
                    leftPlatform[0].second - (platform->getHeight()/2) <= leftPlayer[i].second + (m_player->getHeight()/2) &&
                    leftPlayer[i].second + (m_player->getHeight()/2) <= leftPlatform[0].second + (platform->getHeight()/2) )
                {
                    // nu nog controlleren of de x-waarde ertussen zit zodat de player effectief het platform geraakt heeft
                    float Bx0 = leftPlatform[0].first;
                    float Bx1 = rightPlatfrom[0].first;

//                    cout << "PlatformLeft: " << Bx0 << " <= PlayerLeft: " << leftPlayer[i].first << " <= PlatformRight: " << Bx1 << endl;

                    if (Bx0 < leftPlayer[i].first && leftPlayer[i].first < Bx1)
                    {
                        return true;
                    }

//                    cout << "PlatformLeft: " << Bx0 << " <= PlayerRight: " << rightPlayer[i].first << " <= PlatformRight: " << Bx1 << endl;
                    if (Bx0 < rightPlayer[i].first && rightPlayer[i].first < Bx1) {
                        return true;
                    }

                }

                //dynamic
                else  {


                }


            }

        }
        return false;
    }

    void World::getPointsBetweenFrames(vector<pair<float, float>> &left, vector<pair<float, float>> &right, const shared_ptr<Subject>& subject) {

        float a; float aantalPoints;
        float x0 = subject->getXprev();
        float x1 = subject->getX();
        float y0 = subject->getYprev();
        float y1 = subject->getY();

        if(x0 == x1){
            if (y0 > y1){swap(y0,y1);}
            a = y1-y0;
            aantalPoints = a+0.001f;
            if (a==0) a = 0.001f;
        }

        else if(y0 == y1){
            if (x0 > x1){swap(x0,x1);}
            a = x1-x0;
            aantalPoints = a+0.001f;
            if (a==0) a=0.001f;
        }

        else{

            float x = x0-x1;
            float y = y0-y1;

            //als ze negatief zijn maken we ze eerst positief
            if (x < 0){x*=-1;} if (y < 0){y*=-1;}

            //we nemen hier de lengte van y als aantalpixels
            if (x < y){a = y;}

                //we nemen hier de lengte van x als aantalpixels
            else{ a = x;}
            aantalPoints = a+0.001f;
        }

        for (float i = 0; i < aantalPoints; i+=0.001) {

            float p = i/a;
            float Xi = p*x0 + (1-p)*x1;
            float Yi = p*y0 + (1-p)*y1;

            left.push_back(make_pair(Xi-subject->getWidth()/2, Yi));
            right.push_back(make_pair(Xi+subject->getWidth()/2, Yi));
        }



    }


}