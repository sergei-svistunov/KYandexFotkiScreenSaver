#include <CSpinner.h>

CSpinner::CSpinner() {
    struct timeval CurTime;
    gettimeofday(&CurTime, NULL);
    _StartTime = CurTime.tv_sec;

    _QObj = gluNewQuadric();
}

CSpinner::~CSpinner() {
    gluDeleteQuadric(_QObj);
}

void CSpinner::Draw() {
    struct timeval CurTime;
    gettimeofday(&CurTime, NULL);
    intmax_t CurTick = (CurTime.tv_sec - _StartTime) * 1000 + CurTime.tv_usec / 1000;

    if (_FirstTick == 0)
        _FirstTick = CurTick;

    uint16_t Angle = ((CurTick - _FirstTick) / 5) % 360;

    gluPartialDisk(_QObj, 0.1f, 0.15f, 90, 8, Angle, 270);
}
