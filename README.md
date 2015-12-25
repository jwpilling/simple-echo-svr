# Super Simple Threaded Echo Server

# Example Usage:
1. Install the repo
2. run 'make'
3. ./main 127.0.0.1 4112
4. From another terminal: nc localhost 4112 and send data!

# Todo:
* epoll() to handle multiple clients
* clients send name to be registered
* any data client sends is echoed to all clients.
* Socket class provdes a better wrapper.

# Goals
* Learn about socket programming.
* Learn more about C++.
* Provide an extremely simple, light-weight Socket class to abstract
working with sockets.
* Eventually transform into a chat server.
