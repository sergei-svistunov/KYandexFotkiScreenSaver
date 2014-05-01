#include "CFadeRectPhotoSprite.h"

CFadeRectPhotoSprite::CFadeRectPhotoSprite() {

}

CFadeRectPhotoSprite::~CFadeRectPhotoSprite() {

}

void CFadeRectPhotoSprite::SetProperties(float EffectState, float ShowState) {
    Alpha_LT = Alpha_RT = Alpha_RB = Alpha_LB = EffectState;
}
