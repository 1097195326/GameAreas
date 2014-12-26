//
//  MovingEntity.h
//  AiGame
//
//  Created by admin on 12/25/14.
//
//

#ifndef __AiGame__MovingEntity__
#define __AiGame__MovingEntity__

#include <stdio.h>
#include <cassert>
#include "BaseGameEntity.h"

class MovingEntity : public BaseGameEntity
{
protected:
    Vector2D            m_vVelocity;
    Vector2D            m_vHeading;
    Vector2D            m_vSide;
    double              m_dMass;
    double              m_dMaxSpeed;
    double              m_dMaxForce;
    double              m_dMaxTurnRate;
public:
    MovingEntity(Vector2D   position,
                 double     radius,
                 Vector2D   velocity,
                 double     max_speed,
                 Vector2D   heading,
                 double     mass,
                 Vector2D   scale,
                 double     turn_rate,
                 double     max_force):
    
                BaseGameEntity(0,position,radius),
                m_vHeading(heading),
                m_vVelocity(velocity),
                m_dMass(mass),
                m_vSide(m_vHeading.Perp()),
                m_dMaxSpeed(max_speed),
                m_dMaxTurnRate(turn_rate),
                m_dMaxForce(max_force)
    {
        m_vScale = scale;
    }
    virtual             ~MovingEntity(){}
    
    Vector2D            Velocity()const{return m_vVelocity;}
    void                SetVelocity(const Vector2D& NewVel){m_vVelocity = NewVel;}
    
    double              Mass()const{return m_dMass;}
    Vector2D            Side()const{return m_vSide;}
    
    double              MaxSpeed()const{return m_dMaxSpeed;}
    void                SetMaxSpeed(double new_speed){m_dMaxSpeed = new_speed;}
    
    double              MaxForce()const{return m_dMaxForce;}
    void                SetMaxForce(double mf){m_dMaxForce = mf;}
    
    bool                IsSpeedMaxedOut()const
    {
        return m_dMaxSpeed * m_dMaxSpeed >= m_vVelocity.LengthSq();
    }
    double              Speed()const{return m_vVelocity.Length();}
    double              SpeedSq()const{return m_vVelocity.LengthSq();}
    
    Vector2D            Heading()const{return m_vHeading;}
    void                SetHeading(Vector2D new_heading);
    bool                RotateHeadingToFacePosition(Vector2D target);
    
    double              MaxTurnRate()const{return m_dMaxTurnRate;}
    void                SetMaxTurnRate(double val){m_dMaxTurnRate = val;}
    
};
inline bool MovingEntity::RotateHeadingToFacePosition(Vector2D target)
{
    Vector2D toTarget = Vec2DNormalize(target - m_vPos);
    
    double angle = acos(m_vHeading.Dot(toTarget));
    if (angle < 0.00001) return true;
    
    if (angle > m_dMaxTurnRate) angle = m_dMaxTurnRate;
    
    C2DMatrix RotationMatrix;
    
    RotationMatrix.Rotate(angle * m_vHeading.Sign(toTarget));
    RotationMatrix.TransformVector2Ds(m_vHeading);
    RotationMatrix.TransformVector2Ds(m_vVelocity);
    
    m_vSide = m_vHeading.Perp();
    
    return false;
}
inline void MovingEntity::SetHeading(Vector2D new_heading)
{
    assert( (new_heading.LengthSq() - 1.0) < 0.00001);
    
    m_vHeading = new_heading;
    m_vSide = m_vHeading.Perp();
}
#endif /* defined(__AiGame__MovingEntity__) */
