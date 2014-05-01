#include "KYandexFotkiSaver.h"

KYandexFotkiSaver::KYandexFotkiSaver(WId id) : KScreenSaver(id) {
    _yf_widget = new YandexFotkiWidget;
    embed(_yf_widget);
    _yf_widget->show();
    show();
}

KYandexFotkiSaver::~KYandexFotkiSaver() {
    delete _yf_widget;
}
