#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include "Utils/include/network_utils.h"

using namespace std;

mutex lock_mutex;

void check_port_worker(const std::string &ip, int port)
{
  lock_guard<mutex> guard(lock_mutex);
  cout << ip << " | " << port << " | ";
  if (is_port_open(ip, port))
    cout << "Open";
  else
    cout << "Closed";
  cout << endl;
}

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

  std::map<std::string, int> IPandPort = {
      {"8.8.8.8", 53},         // Google DNS
      {"1.1.1.1", 53},         // Cloudflare DNS
      {"9.9.9.9", 53},         // Quad9 DNS
      {"208.67.222.222", 53},  // OpenDNS
      {"172.217.22.14", 80},   // google.com HTTP
      {"172.217.22.14", 443},  // google.com HTTPS
      {"151.101.1.69", 80},    // stackoverflow.com HTTP
      {"151.101.1.69", 443},   // stackoverflow.com HTTPS
      {"104.244.42.65", 443},  // twitter.com HTTPS
      {"104.244.42.65", 80},   // twitter.com HTTP
      {"93.184.216.34", 80},   // example.com HTTP
      {"93.184.216.34", 443},  // example.com HTTPS
      {"23.23.23.23", 22},     // (AWS EC2 example IP, SSH)
      {"52.95.110.1", 22},     // AWS EC2 SSH
      {"142.250.190.14", 80},  // youtube.com HTTP
      {"142.250.190.14", 443}, // youtube.com HTTPS
      {"13.35.6.157", 3389},   // Microsoft RDP server example
      {"64.233.187.99", 443},  // gmail.com HTTPS
      {"64.233.187.99", 80}    // gmail.com HTTP
  };
  const int max_threads = 16;
  vector<thread> threads;

  for (const auto &[ip, port] : IPandPort)
  {
    threads.emplace_back(check_port_worker, ip, port);
    if (threads.size() == max_threads)
    {
      for (thread &th : threads)
      {
        th.join();
      }
      threads.clear();
    }
  }

  for (thread &th : threads)
  {
    th.join();
  }
}