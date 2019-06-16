//
//  HttpProtocol.hpp
//  wget
//
//  Created by Mykyta Cheshulko on 6/8/19.
//  Copyright © 2019 Mykyta Cheshulko. All rights reserved.
//

#ifndef HttpProtocol_hpp
#define HttpProtocol_hpp

#include "Protocol.h"
#include "TCPSocket.hpp"

#include <regex>
#include <string>
#include <fstream>

#include <iostream>

namespace Network
{
    class HttpProtocol : public Protocol
    {
    public:
        using Domain = Protocol::Host;
        using Path   = std::string;
        
        HttpProtocol();
        ~HttpProtocol() = default;
        
        const Host GetHost() const override;
        void SetHost(const Host& host) override;
        
        const Port GetPort() const override;
        void SetPort(const Port& port) override;
        
        void SendRequest(const Path& path) const override;
        void ProcessResponse(std::ofstream& out_stream) const override;
        
    private:
        Protocol::Host host_;
        Protocol::Port port_;
        Path path_;
        
        std::unique_ptr<Sockets::TcpSocket> socket_ptr_;
        
    public:
        const static Protocol::Port default_http_port;
        const static size_t buffer_size_;
    };
    
    namespace Utils
    {
        std::pair<std::string, std::string> parseUrl(const std::string& url);
        const static std::regex url_regex{"http://([a-z-.]*)/(.*)"};
    }
}

#endif /* HttpProtocol_hpp */
