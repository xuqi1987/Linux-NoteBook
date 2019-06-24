//
// Created by root on 19-6-21.
//

#ifndef INC_01_CPPPRIMER_THREADDEMO_H
#define INC_01_CPPPRIMER_THREADDEMO_H


class ThreadDemo {
public:
    static ThreadDemo *Inst();

    ThreadDemo();

    void testCase();
    void testCase2();
    virtual ~ThreadDemo();
private:
    int m_i;
};


#endif //INC_01_CPPPRIMER_THREADDEMO_H
