//
//  SocketServer.hpp
//  TestOpengles
//
//  Created by oceantech02 on 15/12/1.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#ifndef SocketServer_hpp
#define SocketServer_hpp

#include <sys/socket.h>

class SocketServer {
private:
    int m_socket_server;
    int m_socket_client;
public:
    SocketServer();
    ~SocketServer();
    void run();
};

#endif /* SocketServer_hpp */
