// abstract class to keep SRP

class IMovement
{
public:
    IMovement() = default;
    virtual ~IMovement(){};

    virtual void move(sf::Shape&) = 0;
};

class KeyboardMovement : public IMovement
{
public:
    KeyboardMovement() = default;
    ~KeyboardMovement() override = default;

    void move(sf::Shape& shape) override
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            shape.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            shape.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            shape.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            shape.move(0.0f, 0.1f);
        }
    }
};

class MouseMovement : public IMovement
{
public:
    MouseMovement(std::unique_ptr<IWrapper>& _wrapper) : wrapper(_wrapper) {} //problem tutaj - dla mouse musze podac wrapper, dla keyboard nie, przez to sie robi problem w innych miejscach
    ~MouseMovement() override = default;

    void move(sf::Shape& shape) override
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(wrapper->getWindow()); //wyodrebnij do innej klasy
            shape.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        }
    }

private:
    std::unique_ptr<IWrapper>& wrapper;
};