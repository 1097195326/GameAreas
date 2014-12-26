//
//  Velicle.h
//  AiGame
//
//  Created by admin on 12/26/14.
//
//

#ifndef __AiGame__Velicle__
#define __AiGame__Velicle__

#include <stdio.h>
#include "MovingEntity.h"

#include <vector>
#include <list>
#include <string>
class GameWorld;
class SteeringBehavior;

class Vehicle : public MovingEntity
{
private:
    GameWorld *         m_pWorld;
    SteeringBehavior *  m_pSteering;
    // smoother
    
    double m_dTimeElapsed;
    
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);
public:
    Vehicle(GameWorld * world,
            Vector2D    position,
            double      rotation,
            Vector2D    velocity,
            double      mass,
            double      max_force,
            double      max_speed,
            double      max_turn_rate,
            double      scale);
    ~Vehicle();
    
    void            Update(double time_elapsed);
    
    double          TimeElapsed()const{return m_dTimeElapsed;}
};
#endif /* defined(__AiGame__Velicle__) */
