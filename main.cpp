//
//  main.cpp
//  wget
//
//  Created by Mykyta Cheshulko on 6/8/19.
//  Copyright © 2019 Mykyta Cheshulko. All rights reserved.
//

#include "Wget.hpp"
#include "TCPSocket.hpp"

#include <iostream>
#include <fstream>

int main(int argc, const char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Wrong number of parameters\n. Try $ wget http://domain/{path}\n";
        return 0;
    }
    
    const std::string& url = argv[1];
    
    Wget wget(Wget::ProtocolType::HTTP);
    
    try
    {
        const auto& filepath = wget.Download(url);
        std::cout << "Downloaded file: " << filepath << std::endl;
    }catch(std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}

// http://www.axmag.com/download/pdfurl-guide.pdf
// http://www.orimi.com/pdf-test.pdf
