project(KYandexFotkiScreenSaver)

cmake_minimum_required(VERSION 2.8)
aux_source_directory(./src SRC_LIST)
aux_source_directory(./src/PhotoSprites SRC_LIST)

find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)
find_package(KDE4Workspace REQUIRED)
find_package(OpenGL REQUIRED)
find_package(CURL REQUIRED)
find_package(ImageMagick COMPONENTS Magick++ REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(Threads)

include(KDE4Defaults)
include(${QT_USE_FILE})

add_definitions(
    ${QT_DEFINITIONS}
    ${KDE4_DEFINITIONS}
    ${LIBXML2_DEFINITIONS}
    -fexceptions
)

set(
    FOO_MOC_HEADERS
    src/KYandexFotkiSaver.h
    src/YandexFotkiWidget.h
)
qt4_wrap_cpp(FOO_MOC_OUTFILES ${FOO_MOC_HEADERS})

include_directories(
    src
    src/PhotoSprites
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${KDE4_INCLUDES}
    ${OPENGL_INCLUDE_DIR}
    ${CURL_INCLUDE_DIRS}
    ${ImageMagick_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIR}
)

add_executable(kyandexfotki.kss ${SRC_LIST} ${FOO_MOC_OUTFILES})

target_link_libraries(
    kyandexfotki.kss
    ${KDE4_KDEUI_LIBS}
    ${KDE4WORKSPACE_KSCREENSAVER_LIBRARY}
    ${QT_QTOPENGL_LIBRARY}
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    ${CURL_LIBRARIES}
    ${ImageMagick_LIBRARIES}
    ${LIBXML2_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS kyandexfotki.kss ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES KYandexFotki.desktop DESTINATION ${SERVICES_INSTALL_DIR}/ScreenSavers)