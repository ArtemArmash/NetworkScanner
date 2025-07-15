#pragma once
#include <vector>
#include <string>
#include <map>
std::vector<std::string> resolve_hostname(const std::vector<std::string> &hostnames);
bool is_port_open(std::map<std::string, std::pair<int, std::string>> &IPandPort);