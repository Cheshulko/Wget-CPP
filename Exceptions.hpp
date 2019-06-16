//
//  Exceptions.hpp
//  wget
//
//  Created by Mykyta Cheshulko on 6/9/19.
//  Copyright © 2019 Mykyta Cheshulko. All rights reserved.
//

#ifndef Exceptions_h
#define Exceptions_h

class SocketException : public std::runtime_error
{
public:
    explicit SocketException(const std::string& message)
        : std::runtime_error{"[Socket] " + message}
    {}
};

class HttpProtocolException : public std::runtime_error
{
public:
    explicit HttpProtocolException(const std::string& message)
        : std::runtime_error{"[HttpProtocol] " + message}
    {}
};

class WgetException : public std::runtime_error
{
public:
    explicit WgetException(const std::string& message)
        : std::runtime_error{"[Wget] " + message}
    {}
};

#endif /* Exceptions_h */
