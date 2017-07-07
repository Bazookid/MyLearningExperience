#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
private:
    int maxHealth;
    int health;
    int gold;
    bool isAlive;
public:
    Player();

    int GetMaxHealth();
    int CurHealth();
    void Heal(int amountRestored);
    void Damage(int damageTaken);

    int CurGold();
    void GainGold(int goldObtained);
    void LoseGold(int goldLost);
};

#endif // PLAYER_H_INCLUDED
