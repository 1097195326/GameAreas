//
//  SocketClient.cpp
//  TestOpengles
//
//  Created by oceantech02 on 15/12/1.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#include "SocketClient.hpp"

#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <fcntl.h>

#define SERVER_PORT 6666
#define LENGTH_OF_LISTEN_QUEUE 20
#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "192.168.1.110"

SocketClient::SocketClient():
m_isConnect(false)
{
    sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));
    
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htons(INADDR_ANY);
    client_addr.sin_port = htons(0);
    
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
////    fcntl(m_socket, F_SETFL,O_NONBLOCK);
//    
//    if (m_socket < 0)
//    {
//        printf("client create socket faild");
//        return;
//    }
//    if (bind(m_socket, (sockaddr*)&client_addr, sizeof(client_addr)) < 0)
//    {
//        printf("client bind faild");
//        return;
//    }
    
//    sockaddr_in server_addr;
//    server_addr.sin_family = AF_INET;
//    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
//    server_addr.sin_port = htons(SERVER_PORT);
//    
//    socklen_t serverAddr_len = sizeof(server_addr);
//    if (connect(m_socket, (sockaddr*)&server_addr, serverAddr_len) < 0)
//    {
//        printf("client connect server faild\n");
//        
//    }else
//    {
//        m_isConnect = true;
//        char buffer[BUFFER_SIZE];
//        std::string str = "client 111222";
//        strncpy(buffer, str.c_str(), BUFFER_SIZE);
//        send(m_socket, buffer, BUFFER_SIZE, 0);
//    }
    
    
}
SocketClient::~SocketClient()
{
//    close(m_socket);
}
void SocketClient::run()
{
    if (m_isConnect) {
        printf("conect success to send\n");
        char buffer[BUFFER_SIZE];
        std::string str = "client 111";
        strncpy(buffer, str.c_str(), BUFFER_SIZE);
        send(m_socket, buffer, BUFFER_SIZE, 0);
    }else
    {
        sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
        server_addr.sin_port = htons(SERVER_PORT);
    
//        m_socket = socket(AF_INET, SOCK_STREAM, 0);
//        fcntl(m_socket, F_SETFL,O_NONBLOCK);
    
        socklen_t serverAddr_len = sizeof(server_addr);
        if (connect(m_socket, (sockaddr*)&server_addr, serverAddr_len) < 0)
        {
            printf("client connect server faild\n");
        }else
        {
            printf("client conect success\n");
            m_isConnect = true;
            char buffer[BUFFER_SIZE];
            std::string str = "client 1112";
            strncpy(buffer, str.c_str(), BUFFER_SIZE);
            send(m_socket, buffer, BUFFER_SIZE, 0);
        }
    }
    
    
//    bzero(buffer, BUFFER_SIZE);
//    
//    long lenght = 0;
//    lenght = recv(m_socket, buffer, BUFFER_SIZE, 0);
//    if (lenght < 0) {
//        return;
//    }
//    char recText[BUFFER_SIZE];
//    bzero(recText, BUFFER_SIZE);
//    strncpy(recText, buffer, BUFFER_SIZE);
//    
//    printf("recv server text :%s\n",recText);
    
}