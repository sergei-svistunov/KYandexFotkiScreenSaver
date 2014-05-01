#ifndef CFADERECTPHOTOSPRITE_H_
#define CFADERECTPHOTOSPRITE_H_

#include "CBaseRectPhotoSprite.h"

class CFadeRectPhotoSprite: public CBaseRectPhotoSprite {
public:
    CFadeRectPhotoSprite();
    virtual ~CFadeRectPhotoSprite();
private:
    virtual void SetProperties(float EffectState, float ShowState);
};

#endif /* CFADERECTPHOTOSPRITE_H_ */
