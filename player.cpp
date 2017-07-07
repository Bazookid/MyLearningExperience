#include "player.h"

//Player constructor
Player::Player()
{
    maxHealth = 10;
    health = maxHealth;
    gold = 0;
    isAlive = true;
}

int Player::GetMaxHealth()
{
    return maxHealth;
}

int Player::CurHealth()
{
    return health;
}

void Player::Heal(int amountRestored)
{
    if(amountRestored + health <= maxHealth)
        health += amountRestored;
    else
        health = maxHealth;
}

void Player::Damage(int damageTaken)
{
    if(damageTaken>health)
        health = 0;
    else
        health -= damageTaken;
}

int Player::CurGold()
{
    return gold;
}

void Player::GainGold(int goldObtained)
{
    gold += goldObtained;
}

void Player::LoseGold(int goldLost)
{
    if(gold<goldLost)
        gold = 0;
    else
        gold -= goldLost;
}
