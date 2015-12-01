//
//  SocketClient.hpp
//  TestOpengles
//
//  Created by oceantech02 on 15/12/1.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#ifndef SocketClient_hpp
#define SocketClient_hpp

#include <stdio.h>
#include <sys/socket.h>


class SocketClient {
private:
    int m_socket;
public:
    SocketClient();
    ~SocketClient();
    void run();
};

#endif /* SocketClient_hpp */
