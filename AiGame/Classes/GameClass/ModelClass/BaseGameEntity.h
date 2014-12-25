//
//  BaseGameEntity.h
//  AiGame
//
//  Created by admin on 12/25/14.
//
//

#ifndef __AiGame__BaseGameEntity__
#define __AiGame__BaseGameEntity__

#include <stdio.h>
#include <string>
#include <vector>
#include "../../Common/2D/Vector2D.h"
#include "../../Common/2D/geometry.h"
#include "../../Common/2D/utils.h"


struct Telegram;

class BaseGameEntity
{
public:
    enum {default_entity_type = -1};
private:
    int             m_ID;
    int             m_EntityType;
    int             m_bTag;
    int             NextValidID(){static int NextID = 1; return ++NextID;}
protected:
    Vector2D        m_vPos;
    Vector2D        m_vScale;
    double          m_dBoundingRadius;
    
    BaseGameEntity():   m_ID(NextValidID()),
                        m_dBoundingRadius(0.0),
                        m_vPos(Vector2D()),
                        m_vScale(Vector2D(1.0,1.0)),
                        m_EntityType(default_entity_type),
                        m_bTag(false)
    {}
    BaseGameEntity(int entity_type):
                        m_ID(NextValidID()),
                        m_dBoundingRadius(0.0),
                        m_vPos(Vector2D()),
                        m_vScale(Vector2D(1.0,1.0)),
                        m_EntityType(entity_type),
                        m_bTag(false)
    {}
    BaseGameEntity(int entity_type, Vector2D pos, double r):
                        m_ID(NextValidID()),
                        m_dBoundingRadius(r),
                        m_vPos(pos),
                        m_vScale(Vector2D(1.0,1.0)),
                        m_EntityType(entity_type),
                        m_bTag(false)
    {}
    BaseGameEntity(int entity_type, int ForcedID):
                        m_ID(ForcedID),
                        m_dBoundingRadius(0.0),
                        m_vPos(Vector2D()),
                        m_vScale(Vector2D(1.0,1.0)),
                        m_EntityType(entity_type),
                        m_bTag(false)
    {}
public:
    virtual         ~BaseGameEntity(){}
    int             ID(){return m_ID;}
    virtual void    Update(double time_elapsed){}
    virtual bool    HandleMessage(const Telegram& msg){return false;}
    
    virtual void    Write(std::ostream& os)const{}
    virtual void    Read(std::ostream& is){}
    
    Vector2D        Pos()const{return m_vPos;}
    void            setPos(Vector2D new_pos){m_vPos = new_pos;}
    
    double          BRadius()const{return m_dBoundingRadius;}
    void            setBRadius(double r){m_dBoundingRadius = r;}
    
    bool            IsTagged(){return m_bTag;}
    void            Tag(){m_bTag = true;}
    void            UnTag(){m_bTag = false;}
    
    Vector2D        Scale()const{return m_vScale;}
    void            SetScale(Vector2D val)
    {
        m_dBoundingRadius *= MaxOf(val.x, val.y)/MaxOf(m_vScale.x, m_vScale.y);
        m_vScale = val;
    }
    void            SetScale(double val)
    {
        m_dBoundingRadius *= (val/MaxOf(m_vScale.x, m_vScale.y));
        m_vScale = Vector2D(val, val);
    }
    
    int             EntityType()const{return m_EntityType;}
    void            SetEntityType(int new_type){m_EntityType = new_type;}
    
};

#endif /* defined(__AiGame__BaseGameEntity__) */
