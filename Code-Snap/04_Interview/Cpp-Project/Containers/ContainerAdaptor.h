//
// Created by root on 19-5-10.
//

#ifndef CONTAINERS_CONTAINERADAPTOR_H
#define CONTAINERS_CONTAINERADAPTOR_H


class ContainerAdaptor {
public:
    static ContainerAdaptor * Instance() {
        static ContainerAdaptor sInst;
        return &sInst;
    };

    void stackDemo();
    void queueDemo();
private:

    ContainerAdaptor();

};


#endif //CONTAINERS_CONTAINERADAPTOR_H
