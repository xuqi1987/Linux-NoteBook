//
// Created by root on 19-6-24.
//

#ifndef INC_01_CPPPRIMER_TCPSERVER_H
#define INC_01_CPPPRIMER_TCPSERVER_H


class TCPServer {
public:
    static TCPServer* Inst();
    TCPServer();
    virtual ~TCPServer();
};


#endif //INC_01_CPPPRIMER_TCPSERVER_H
