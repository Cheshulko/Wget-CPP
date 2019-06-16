//
//  Wget.hpp
//  wget
//
//  Created by Mykyta Cheshulko on 6/8/19.
//  Copyright © 2019 Mykyta Cheshulko. All rights reserved.
//

#ifndef Wget_hpp
#define Wget_hpp

#include <string>
#include <fstream>
#include <regex>

#include "TCPSocket.hpp"
#include "Protocol.h"

#include <sstream>

class Wget
{
public:    
    enum class ProtocolType
    {
        HTTP
    };
    
    Wget(ProtocolType protocolType);
    ~Wget() = default;
    
    Wget(const Wget &wget) = delete;
    Wget& operator=(const Wget &wget) = delete;
    
    std::string Download(const std::string& url);
    
    
private:
    std::unique_ptr<Network::Protocol> http_;
    std::unique_ptr<Network::Protocol> BuildProtocol(Wget::ProtocolType protocolType) const;
    
    const std::string GetOutputFilename(const std::string& path) const;
    const std::string GetOutputFilePath(const std::string& filename) const;
};

#endif /* Wget_hpp */
