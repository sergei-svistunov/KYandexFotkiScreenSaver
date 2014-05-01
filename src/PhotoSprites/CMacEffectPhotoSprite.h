#ifndef CMACEFFECTPHOTOSPRITE_H_
#define CMACEFFECTPHOTOSPRITE_H_

#include "CBaseRectPhotoSprite.h"

class CMacEffectPhotoSprite: public CBaseRectPhotoSprite {
public:
    CMacEffectPhotoSprite();
    virtual ~CMacEffectPhotoSprite();
private:
    void SetProperties(float EffectState, float ShowState);
    GLfloat _Angle;
};

#endif /* CMACEFFECTPHOTOSPRITE_H_ */
