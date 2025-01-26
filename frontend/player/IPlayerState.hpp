//
// Created by fikkie on 28/10/24.
//

#ifndef IPLAYERSTATE_HPP
#define IPLAYERSTATE_HPP



class IPlayerState {
public:
    virtual ~IPlayerState() = default;
    virtual void TakeDamage(int damage) = 0;
    virtual int Attack() = 0;
};



#endif //IPLAYERSTATE_HPP
