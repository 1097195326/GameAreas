//
//  SocketServer.cpp
//  TestOpengles
//
//  Created by oceantech02 on 15/12/1.
//  Copyright © 2015年 张洪星. All rights reserved.
//

#include "SocketServer.hpp"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <string>


#define SERVER_PORT 6666
#define LENGTH_OF_LISTEN_QUEUE 20
#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "127.0.0.1"

SocketServer::SocketServer():m_isAccept(false)
{
    m_socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket_server < 0) {
        printf("create server socket faild");
        return;
    }
    fcntl(m_socket_server, F_SETFL, O_NONBLOCK);
    
    int opt = 1;
    setsockopt(m_socket_server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    
    sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    serverAddr.sin_port = htons(SERVER_PORT);
    
    if (bind(m_socket_server, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("server port :%d bind faild",SERVER_PORT);
        return;
    }
    if (listen(m_socket_server, LENGTH_OF_LISTEN_QUEUE) < 0)
    {
        printf("server listen faild ");
        return;
    }
    
    
}
SocketServer::~SocketServer()
{
    close(m_socket_server);
}
void SocketServer::run()
{
    printf("222\n");
    if (!m_isAccept)
    {
        sockaddr_in clientAddr ;
        socklen_t length = sizeof(clientAddr);
        printf("server status:%d\n",m_socket_server);
        m_socket_client = accept(m_socket_server, (sockaddr*)&clientAddr, &length);
        
        printf("server status:%d\n",m_socket_server);
        if (m_socket_client < 0)
        {
            return;
        }else
        {
            m_isAccept = true;
        }
    }
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    
    long recvLength = recv(m_socket_client, buffer, BUFFER_SIZE, 0);
    if (recvLength < 0)
    {
        printf("server recv faild\n");
        return;
    }
    char clientText[BUFFER_SIZE];
    bzero(clientText, BUFFER_SIZE);
    strncpy(clientText, buffer, BUFFER_SIZE);
    printf(" client text :%s\n",clientText);
    
    bzero(buffer, BUFFER_SIZE);
//    char serverText[] = {'1','2','3'};
    std::string str = "server 1234";
//    strncpy(buffer, serverText, BUFFER_SIZE);
    strncpy(buffer, str.c_str(), BUFFER_SIZE);
    
    if (send(m_socket_client, buffer, BUFFER_SIZE, 0) < 0)
    {
        printf("server send faild");
        return;
    }
//    close(m_socket_client);
    
}