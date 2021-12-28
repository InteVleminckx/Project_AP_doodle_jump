#include "EntityView.h"


namespace representation {

    EntityView::EntityView() = default;

    EntityView::EntityView(float width, float height, const string& filepath){
        setWidth(width * logic::Camera::Instance()->getCameraWidth());
        setHeight(height * logic::Camera::Instance()->getCameraHeight());
        createSprite(filepath);
        getSprite().setScale(getWidth()/getTexture().getSize().x, getHeight()/getTexture().getSize().y);
    }

    void EntityView::createSprite(const string& filepath)
    {
        try {
            if (!m_modelTexture.loadFromFile(filepath))
                throw InputImageException();
        }
        catch (InputImageException& exception) {
            cout << exception.what() << filepath << endl;
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

    void EntityView::setEntityModel(shared_ptr<logic::Player_L> player){
        m_entityModel = move(player);
    }
    void EntityView::setEntityModel(shared_ptr<logic::Platform_L> platform){
        m_entityModel = move(platform);
    }
    void EntityView::setEntityModel(shared_ptr<logic::Bonus_L> bonus){
        m_entityModel = move(bonus);
    }
    void EntityView::setEntityModel(shared_ptr<logic::BG_Tile_L> bg_tile){
        m_entityModel = move(bg_tile);
    }

//    shared_ptr<logic::EntityModel> EntityView::getEntityModel() {
//        return m_entityModel;
//    }

    void EntityView::update() {
        getSprite().setPosition(m_entityModel->getProjectedX(), m_entityModel->getProjectedY() - getHeight());
        representation::Window::Instance()->getWindow().draw(getSprite());
    }

    EntityView::~EntityView() {cout << "delete EntityView observer" << endl;}


}

