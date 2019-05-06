//
// Created by root on 19-5-6.
//

#ifndef CONTAINERS_SEQUENCECONTAINER_H
#define CONTAINERS_SEQUENCECONTAINER_H


class SequenceContainer {
public:

    static SequenceContainer* Instance();
    virtual ~SequenceContainer();

    void ArrayDemo();
    void VectorDemo();
    void DequeDemo();
    void Forward_listDemo();
    void ListDemo();

private:
    SequenceContainer();
    static SequenceContainer *pInst;
};


#endif //CONTAINERS_SEQUENCECONTAINER_H
