#include "EntityView.h"

namespace representation {

EntityView::EntityView() = default;

EntityView::EntityView(float width, float height, const string& filepath)
{
        m_width = width * (float)logic::Camera::Instance()->getCameraWidth();
        m_height = height * (float)logic::Camera::Instance()->getCameraHeight();
        createSprite(filepath);
        m_modelSprite.setScale(m_width / (float)m_modelTexture.getSize().x,
                               m_height / (float)m_modelTexture.getSize().y);
}

void EntityView::createSprite(const string& filepath)
{
        try {
                if (!m_modelTexture.loadFromFile(filepath))
                        throw InputImageException();
        } catch (InputImageException& exception) {
                cout << exception.what() << filepath << endl;
                exit(1);
        }

        this->m_modelSprite.setTexture(m_modelTexture);
}

void EntityView::update()
{
        ControllingPointers::control(m_entityModel, "EntityView", "update()");
        m_modelSprite.setPosition((float)m_entityModel->getProjectedX(),
                                  (float)m_entityModel->getProjectedY() - m_height);
}

void EntityView::draw() { representation::Window::Instance()->getWindow().draw(m_modelSprite); }

void EntityView::setEntityModel(shared_ptr<logic::Player_L> player)
{
        ControllingPointers::control(player, "EntityView", "setEntityModel(shared_ptr<logic::Player_L> platform)");
        m_entityModel = move(player);
}
void EntityView::setEntityModel(shared_ptr<logic::Platform_L> platform)
{
        ControllingPointers::control(platform, "EntityView", "setEntityModel(shared_ptr<logic::Platform_L> platform)");
        m_entityModel = move(platform);
}

void EntityView::setEntityModel(shared_ptr<logic::Bonus_L> bonus)
{
        ControllingPointers::control(bonus, "EntityView", "setEntityModel(shared_ptr<logic::Bonus_L> platform)");
        m_entityModel = move(bonus);
}

void EntityView::setEntityModel(shared_ptr<logic::BG_Tile_L> bg_tile)
{
        ControllingPointers::control(bg_tile, "EntityView", "setEntityModel(shared_ptr<logic::BG_Tile_L> platform)");
        m_entityModel = move(bg_tile);
}

EntityView::~EntityView() = default;

} // namespace representation
