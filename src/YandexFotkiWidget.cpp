#include "YandexFotkiWidget.h"
#include <stdio.h>
#include <sys/stat.h>

#define FRAME_RATE 1000 / 60

YandexFotkiWidget::YandexFotkiWidget(QWidget* parent) :
        QGLWidget(parent) {

    char * HomeFolder = getenv("HOME");
    if (!HomeFolder)
        HomeFolder = (char*) "/tmp";

    _Folder = new char[strlen(HomeFolder) + 20];
    sprintf(_Folder, "%s/.KYandexFotkiSaver", HomeFolder);
    mkdir(_Folder, S_IRWXU | S_IRWXG | S_IREAD);

    _PhotoFolder = new char[strlen(_Folder) + 11];
    sprintf(_PhotoFolder, "%s/.download", _Folder);
    mkdir(_PhotoFolder, S_IRWXU | S_IRWXG | S_IREAD);

    char * ConfigFName = new char[strlen(_Folder) + 11];
    sprintf(ConfigFName, "%s/saver.cfg", _Folder);
    _Config = new CConfig();
    _Config->Load(ConfigFName);
    delete[] ConfigFName;

    pthread_mutex_init(&_LockDraw, NULL);

    _Timer = new QTimer(this);
    connect(_Timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

YandexFotkiWidget::~YandexFotkiWidget() {
    if (_Folder)
        delete[] _Folder;

    if (_PhotoFolder)
        delete[] _PhotoFolder;

    if (_Config)
        delete _Config;

    if (_Timer)
        delete _Timer;

    if (_Logo)
        delete _Logo;

    if (_Spinner)
        delete _Spinner;

    if (_PhotoSpriteLoader)
        delete _PhotoSpriteLoader;

    pthread_mutex_destroy(&_LockDraw);
}

void YandexFotkiWidget::initializeGL() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    _Logo = new CLogo;
    _PhotoSpriteLoader = new CPhotoSpriteLoader(_Folder, _PhotoFolder, &_LockDraw, _Config);
    _Spinner = new CSpinner;

    _Timer->setSingleShot(true);
    _Timer->start(FRAME_RATE);
}

void YandexFotkiWidget::resizeGL(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    glOrtho(-1, 1, -1, 1, -5, 5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void YandexFotkiWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glPushMatrix();

    switch (_PhotoSpriteLoader->GetStatus()) {
    case 1:
    case 3:
        _Logo->Draw();
        _Spinner->Draw();
        break;
    case 2:
        if (_PhotoSpriteQueue.size() == 0)
            _PhotoSpriteQueue.push(_PhotoSpriteLoader->GetPhotoSprite());

        if (_PhotoSpriteQueue.back()->IsCompleted()) {
            _PhotoSpriteQueue.push(_PhotoSpriteLoader->GetPhotoSprite());
            if (_PhotoSpriteQueue.size() > 2) {
                delete _PhotoSpriteQueue.front();
                _PhotoSpriteQueue.pop();
            };
        }

        pthread_mutex_lock(&_LockDraw);
        _PhotoSpriteQueue.front()->Draw();

        glTranslatef(0.0f, 0.0f, 0.5f);
        if (_PhotoSpriteQueue.size() > 1)
            _PhotoSpriteQueue.back()->Draw();

        glTranslatef(0.0f, 0.0f, 0.5f);
        _Logo->Draw();

        pthread_mutex_unlock(&_LockDraw);
        break;
    };

    glPopMatrix();
}

void YandexFotkiWidget::nextFrame() {
    updateGL();
    _Timer->setSingleShot(true);
    _Timer->start(FRAME_RATE);
}
