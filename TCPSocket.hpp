//
//  TCPSocket.hpp
//  wget
//
//  Created by Mykyta Cheshulko on 6/8/19.
//  Copyright © 2019 Mykyta Cheshulko. All rights reserved.
//

#ifndef TCPSocket_hpp
#define TCPSocket_hpp

#include <string>
#include <memory>

#include <arpa/inet.h>
#include <netdb.h>

//connect
#include <sys/socket.h>

namespace Sockets
{
    using SocketDescriptor = int;
    
    class TcpSocket
    {
    public:
        TcpSocket(int family, int flags);
        virtual ~TcpSocket();
        
        TcpSocket(const TcpSocket &socket) = delete;
        TcpSocket& operator=(const TcpSocket &socket) = delete;
        
        void connect(std::string adress, int port);
        
        void send(const char *data, unsigned int length, int flags);
        long receive(char* msg, int len, int flags);
        
    private:
        struct CloseSocketDescriptor
        {
            void operator()(SocketDescriptor* socket_desc_) const;
        };
        
        struct sockaddr_in sockaddr_in_;
        
        std::unique_ptr<SocketDescriptor, CloseSocketDescriptor> socket_desc_ptr_;
        std::unique_ptr<addrinfo, decltype(&freeaddrinfo)> addr_info_ptr_;
    };
}
#endif /* TCPSocket_hpp */
