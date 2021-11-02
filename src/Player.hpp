class Player
{
public:
    Player() = default;
    virtual ~Player();

private:
    unsigned int livesLeft = 0;
};