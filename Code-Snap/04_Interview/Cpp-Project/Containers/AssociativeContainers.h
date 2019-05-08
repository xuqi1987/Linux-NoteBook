//
// Created by root on 19-5-8.
//

#ifndef CONTAINERS_ASSOCIATIVECONTAINERS_H
#define CONTAINERS_ASSOCIATIVECONTAINERS_H


class AssociativeContainers {
public:
    virtual ~AssociativeContainers();

    static AssociativeContainers* Instance();

    void setmapDemo();

    void multiDemo();
    void unorderedDemo();

private:
    AssociativeContainers();
    static AssociativeContainers *pInst;
};


#endif //CONTAINERS_ASSOCIATIVECONTAINERS_H
