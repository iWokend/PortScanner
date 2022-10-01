// PortScanner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <SFML/Network/Socket.hpp>
#include<SFML/Network.hpp>
#include <string>

using namespace std;
using namespace sf;
bool port_is_open(const std::string& address, int port)
{
    sf::TcpSocket socket;
    bool open = (socket.connect(sf::IpAddress(address), port) == sf::Socket::Done);
    socket.disconnect();


    return open;
}


    int main()
    {
        
        double total_ports = pow(2, 16); //total number or ports
        for (int i = 1; i < total_ports; ++i) {
            if (port_is_open("localhost", i)) {
                std::cout << "OPEN " << i << std::endl;
            }
            else {
                std::cout << "CLOSED " << i << std::endl;
            }
      
            
        }
    }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
