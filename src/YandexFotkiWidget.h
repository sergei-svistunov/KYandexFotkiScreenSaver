#ifndef YANDEXFOTKIWIDGET_H_
#define YANDEXFOTKIWIDGET_H_

#include <qgl.h>
#include <qtimer.h>
#include <pthread.h>
#include <queue>

#include "CLogo.h"
#include "CConfig.h"
#include "CPhotoSpriteLoader.h"
#include "CSpinner.h"

class YandexFotkiWidget: public QGLWidget {
    Q_OBJECT
public:
    YandexFotkiWidget(QWidget* parent = 0);
    ~YandexFotkiWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private slots:
    void nextFrame();

private:
    char* _Folder = NULL;
    char* _PhotoFolder = NULL;
    pthread_mutex_t _LockDraw;
    CConfig * _Config = NULL;
    QTimer* _Timer = NULL;
    CLogo* _Logo = NULL;
    CPhotoSpriteLoader* _PhotoSpriteLoader;
    CSpinner* _Spinner;
    std::queue <CBasePhotoSprite *> _PhotoSpriteQueue;
};

#endif /* YANDEXFOTKIWIDGET_H_ */
