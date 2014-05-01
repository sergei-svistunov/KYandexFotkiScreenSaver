#ifndef CPANORAMPHOTOSPRITE_H_
#define CPANORAMPHOTOSPRITE_H_

#include "CBaseRectPhotoSprite.h"

class CPanoramPhotoSprite: public CBaseRectPhotoSprite {
public:
    CPanoramPhotoSprite();
    virtual ~CPanoramPhotoSprite();
private:
    void SetProperties(float EffectState, float ShowState);
    int _Type;
    bool _Fade;
};

#endif /* CPANORAMPHOTOSPRITE_H_ */
