//
// Created by root on 19-6-24.
//

#include "TCPServer.h"

TCPServer::TCPServer() {}

TCPServer::~TCPServer() {

}

TCPServer *TCPServer::Inst() {
    static TCPServer sInst;
    return &sInst;
}
