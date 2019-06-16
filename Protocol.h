//
//  Protocol.h
//  wget
//
//  Created by Mykyta Cheshulko on 6/8/19.
//  Copyright © 2019 Mykyta Cheshulko. All rights reserved.
//

#ifndef Protocol_h
#define Protocol_h

#include <string>

namespace Network
{
    class Protocol
    {
    public:
        using Host = std::string;
        using Path = std::string;
        using Port = int;
        
        virtual const Host GetHost() const = 0;
        virtual void SetHost(const Host& host) = 0;
        
        virtual const Port GetPort() const = 0;
        virtual void SetPort(const Port& port) = 0;
        
        virtual void SendRequest(const Path& path) const = 0;
        virtual void ProcessResponse(std::ofstream& out_stream) const = 0;
        
        virtual ~Protocol() {};
    };
}

#endif /* Protocol_h */
