#ifndef MYOBJECT_H
#define MYOBJECT_H

#include<QObject>
#include<QWebPage>
#include<QWebFrame>
#include <unistd.h>

class MyObject: public QObject
{
Q_OBJECT
private:
    QWebPage *page;
public:
    MyObject(QWebPage *page)
        : page(page)
    {}
signals:
    void sceneChange();
public slots:
    void viewLoad()
    {
        this->page->mainFrame()->evaluateJavaScript("qt.sceneChange.connect(Scene2);");
        emit sceneChange();
    }
};

#endif // MYOBJECT_H