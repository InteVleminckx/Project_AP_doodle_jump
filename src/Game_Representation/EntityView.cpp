#include "EntityView.h"


namespace representation {

    EntityView::EntityView() = default;

    EntityView::EntityView(float width, float height, string& image){
        setWidth(width * logic::Camera::Instance()->getCameraWidth());
        setHeight(height * logic::Camera::Instance()->getCameraHeight());
        createSprite(image);
        getSprite().setScale(getWidth()/getTexture().getSize().x, getHeight()/getTexture().getSize().y);
    }

    void EntityView::createSprite(const string& filepath)
    {
        try {
            if (!m_modelTexture.loadFromFile(filepath))
                throw InputException();
        }
        catch (InputException& exception) {
            cout << exception.what() << filepath;
            exit(1);
        }

        this->m_modelSprite.setTexture(m_modelTexture);

    }

    void EntityView::setSprite(sf::Sprite& sprite) {m_modelSprite = sprite;}

    void EntityView::setTexture(sf::Texture& texture) {m_modelTexture = texture;}

    void EntityView::setHeight(float height) {m_height = height;}

    void EntityView::setWidth(float width) {m_width = width;}

    sf::Sprite& EntityView::getSprite() { return m_modelSprite; }

    sf::Texture& EntityView::getTexture() {return m_modelTexture;}

    float EntityView::getHeight() const  {return m_height;}

    float EntityView::getWidth() const {return m_width;}

    void EntityView::setEntityModel(shared_ptr<logic::Player_L>& player){
        m_entityModel = player;
    }
    void EntityView::setEntityModel(shared_ptr<logic::Platform_L>& platform){
        m_entityModel = platform;
    }
    void EntityView::setEntityModel(shared_ptr<logic::Bonus_L>& bonus){
        m_entityModel = bonus;
    }
    void EntityView::setEntityModel(shared_ptr<logic::BG_Tile_L>& bg_tile){
        m_entityModel = bg_tile;
    }

    shared_ptr<logic::EntityModel> EntityView::getEntityModel() {
        return m_entityModel;
    }

    void EntityView::update() {
        getSprite().setPosition(m_entityModel->getProjectedX(), m_entityModel->getProjectedY() - getHeight());
        representation::Window::Instance()->getWindow()->draw(getSprite());
    }


}

