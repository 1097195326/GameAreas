//
//  Velicle.cpp
//  AiGame
//
//  Created by admin on 12/26/14.
//
//

#include "Vehicle.h"

Vehicle::Vehicle(GameWorld * world,
                 Vector2D   position,
                 double     rotation,
                 Vector2D   velocity,
                 double     mass,
                 double     max_force,
                 double     max_speed,
                 double     max_turn_rate,
                 double     scale):
                MovingEntity(position,
                             scale,
                             velocity,
                             max_speed,
                             Vector2D(sin(rotation),-cos(rotation)),
                             mass,
                             Vector2D(scale,scale),
                             max_turn_rate,
                             max_force),
                m_pWorld(world),
                m_dTimeElapsed(0.0)

{
//    m_pSteering = new SteeringBehavior(this);
}
Vehicle::~Vehicle()
{
//    delete m_pSteering;
}
void Vehicle::Update(double time_elapsed)
{
    m_dTimeElapsed = time_elapsed;
    
    Vector2D OldPos = Pos();
    
    Vector2D SteeringForce;
    
//    SteeringForce = m_pSteering->Calculate();
    Vector2D acceleration = SteeringForce / m_dMass;
    m_vVelocity += acceleration * time_elapsed;
    m_vVelocity.Truncate(m_dMaxSpeed);
    m_vPos += m_vVelocity * time_elapsed;
    
    if (m_vVelocity.LengthSq() > 0.00000001)
    {
        m_vHeading = Vec2DNormalize(m_vVelocity);
        m_vSide = m_vHeading.Perp();
    }
    
}
