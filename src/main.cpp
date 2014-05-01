#include <iostream>

#include "KYandexFotkiSaverInterface.h"

int main(int argc, char* argv[]) {
    KYandexFotkiSaverInterface kss;
    return kScreenSaverMain(argc, argv, kss);
}
