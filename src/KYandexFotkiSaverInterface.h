#ifndef KYANDEXFOTKISAVERINTERFACE_H_
#define KYANDEXFOTKISAVERINTERFACE_H_

#include "kscreensaver.h"
#include "KYandexFotkiSaver.h"
#include <qmessagebox.h>

class KYandexFotkiSaverInterface: public KScreenSaverInterface {
public:
    virtual KAboutData* aboutData() {
        return new KAboutData("kyandexfotki.kss", "klock", ki18n("Yandex.Fotki"), "1.0", ki18n("Yandex.Fotki"));
    }

    virtual KScreenSaver* create(WId id) {
        return new KYandexFotkiSaver(id);
    }

    virtual QDialog* setup() {
        return new QMessageBox(QMessageBox::Information, "Setup", "Not realized yet", QMessageBox::Ok);
    }
};

#endif /* KYANDEXFOTKISAVERINTERFACE_H_ */
