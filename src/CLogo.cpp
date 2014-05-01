#include "CLogo.h"

#include "LogoImageData.h"

CLogo::CLogo() {
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &_Texture);
    glBindTexture(GL_TEXTURE_2D, _Texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, LogoImageData);
}

CLogo::~CLogo() {
    glDeleteTextures(1, &_Texture);
}

void CLogo::Draw(void) {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    GLint Viewport[4];
    glGetIntegerv(GL_VIEWPORT, Viewport);

    GLfloat x = 256.0f * (2.0f / (GLfloat) Viewport[2]);
    GLfloat y = 64.0f * (2.0f / (GLfloat) Viewport[3]);

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, _Texture);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f + x, 1.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f + x, 1.0f - y, 0.0f);

    glTexCoord2f(0.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f - y, 0.0f);
    glEnd();

    glPopAttrib();
    glPopMatrix();
}
