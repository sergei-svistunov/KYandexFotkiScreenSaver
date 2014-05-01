#ifndef CLOGO_H_
#define CLOGO_H_

#include "GL/gl.h"

class CLogo {
public:
    CLogo();
    virtual ~CLogo();
    void Draw(void);
private:
    void PrintData(void);
    GLuint _Texture;
};

#endif /* CLOGO_H_ */
