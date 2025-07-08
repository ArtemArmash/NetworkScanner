#include <iostream>

#include "Utils/include/network_utils.h"
using namespace std;


int main(){
    std::vector<std::string>hostnamesDNS=
    {"google.com", "youtube.com", "chat.openai.com", "github.com"};
    
    for (auto& hostname : hostnamesDNS)
    {
        std::vector<std::string>hostnamesIP = resolve_hostname({hostname});

        cout << "IP address for: " << hostname<<endl;
        for (auto& IP : hostnamesIP)
        {
            cout << IP << endl;
        }
        cout << endl;
    }
    
}