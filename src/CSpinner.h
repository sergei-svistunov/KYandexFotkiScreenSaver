#ifndef CSPINNER_H_
#define CSPINNER_H_

#include <GL/glu.h>
#include <sys/time.h>

class CSpinner {
public:
    CSpinner();
    virtual ~CSpinner();
    void Draw();

private:
    GLUquadricObj* _QObj = NULL;
    time_t _StartTime;
    intmax_t _FirstTick = 0;
};

#endif /* CSPINNER_H_ */
