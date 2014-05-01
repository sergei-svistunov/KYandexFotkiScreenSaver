#ifndef CBASEPHOTOSPRITE_H_
#define CBASEPHOTOSPRITE_H_

#include <pthread.h>
#include <inttypes.h>
#include <GL/gl.h>
#include "Magick++.h"

class CBasePhotoSprite {
public:
    CBasePhotoSprite();
    void Init(pthread_mutex_t * LockDraw, int EffectTime, int ShowTime, float BackgroundColor[4]);
    virtual ~CBasePhotoSprite();
    bool Load(char * FileName);
    void Draw(void);
    bool IsCompleted(void);

protected:
    void GetTextureOffset(GLfloat * dx, GLfloat * dy);
    pthread_mutex_t * _LockDraw;
    int Width, Height;
    GLuint Texture;

private:
    virtual void OnDraw(float EffectState, float ShowState) = 0;
    time_t _StartTime;
    int _EffectTime, _ShowTime;
    float _BackgroundColor[4];
    intmax_t _FirstTick;
    int _TexWidth, _TexHeight;
    unsigned char * _ImageData;
};

#endif /* CBASEPHOTOSPRITE_H_ */
