#ifndef KYANDEXFOTKISAVER_H_
#define KYANDEXFOTKISAVER_H_

#include <kscreensaver.h>
#include "YandexFotkiWidget.h"

class KYandexFotkiSaver : public KScreenSaver {
    Q_OBJECT

public:
    KYandexFotkiSaver(WId id);
    virtual ~KYandexFotkiSaver();

private:
    YandexFotkiWidget* _yf_widget;
};

#endif /* KYANDEXFOTKISAVER_H_ */
