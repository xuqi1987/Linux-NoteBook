#include <QApplication>
#include <QGridLayout>
#include <QtGlobal>
#include <QObject>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>
#include <QPushButton>
#include <QWebView>
#include <QMainWindow>

#define MAX_PATH 256
#define MAX_NUM  128
#define BUFFER_LEN 2048
#define LOCAL_LISTEN_QUEUE 1024

//static Widget *pWidget = NULL;
static bool bThreadExit = false;
static int ProcessId = -1;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    char pluginPath[MAX_PATH] = {0};
    char platform[MAX_NUM] = {0};
    char fontDir[MAX_PATH] = {0};

    sprintf(pluginPath,  "QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/qt/plugins");
    sprintf(platform,    "QT_QPA_PLATFORM=eglfs");
    sprintf(fontDir,     "QT_QPA_FONTDIR=/usr/app/NativeApps/sys/fonts");

    putenv(pluginPath);
    putenv(platform);
    putenv(fontDir);

    QCursor cursor(Qt::BlankCursor);
    QApplication::setOverrideCursor(cursor);
    QApplication::changeOverrideCursor(cursor);


    QMainWindow window;
    window.setGeometry(0, 0, 800, 480);
    QWebView view(&window);
    view.setGeometry(0, 0, 800, 480);
    view.load(QUrl("file:///home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/09Qt/cmake-build-debug/bin/index.html"));
    window.show();

    return app.exec();
/*
   // view->setGeometry(QRect(100,100,800,480));
    //window->setAttribute(Qt::WA_TranslucentBackground);
//
//    auto button = new QPushButton("OK");
//
//    auto layout = new QGridLayout;
//
//    //layout->addRow("spin box:", button);
//    view->setLayout(layout);
  //  view->show();

  //  return app.exec();

  */
}
