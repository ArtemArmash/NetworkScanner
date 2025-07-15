#include <iostream>
#include <unordered_map>
#include "Utils/include/network_utils.h"
using namespace std;

int main()
{
  // std::vector<std::string>hostnamesDNS=
  // {"google.com", "youtube.com", "chat.openai.com", "github.com"};

  // for (auto& hostname : hostnamesDNS)
  // {
  //     std::vector<std::string>hostnamesIP = resolve_hostname({hostname});

  //     cout << "IP address for: " << hostname<<endl;
  //     for (auto& IP : hostnamesIP)
  //     {
  //         cout << IP << endl;
  //     }
  //     cout << endl;
  // }
  map<string, pair<int, string>> IPandPort = {
      {"192.168.1.1", {8080, "Closed/Open"}},
      {"8.8.8.8", {53, "Closed/Open"}},
      {"542.321.3", {42344223, "Closed/Open"}},
      {"3542.321.3", {42344523, "Closed/Open"}},
      {"1542.321.3", {42334423, "Closed/Open"}}};
  is_port_open(IPandPort);
  for (const auto &[ip, host_port] : IPandPort)
  {
    const auto &[host, port] = host_port;
    cout << ip << " | " << host << " | " << port << endl;
  }
}