# Wget-CPP

## Overview
Wget is a C++ program that retrieves content from web servers. 
Written in C++17 using BSD sockets.
Now it supports downloading via HTTP only.

## Build and run
To build use Makefile (C++17 needed)
```
make
./wget http://{domain}/{path}
```
For instance,
```
./wget http://www.orimi.com/pdf-test.pdf
```
The output is a path to downloaded file
```
Downloaded file: /Cheshulko/wget/pdf-test.pdf
```
