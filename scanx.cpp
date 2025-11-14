#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define GREEN  "\033[32m"
#define RED    "\033[31m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

bool scanPort(const string& ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return false;

    sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

    int result = connect(sock, (struct sockaddr*)&target, sizeof(target));
    close(sock);

    return result == 0;
}

int main() {
    vector<string> targets;
    int startPort, endPort;

    cout << CYAN << "=== ScanX Multi-IP Port Scanner ===" << RESET << endl;

    int count;
    cout << "Enter number of IPs to scan: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        string ip;
        cout << "Enter IP " << i + 1 << ": ";
        cin >> ip;
        targets.push_back(ip);
    }

    cout << "Enter start port: ";
    cin >> startPort;

    cout << "Enter end port: ";
    cin >> endPort;

    ofstream file("scan_results.txt");

    cout << CYAN << "\nStarting scan...\n" << RESET;

    for (const string& ip : targets) {
        cout << CYAN << "\nScanning IP: " << ip << RESET << endl;
        file << "Scan Results for " << ip << ":\n";

        for (int port = startPort; port <= endPort; port++) {
            if (scanPort(ip, port)) {
                cout << GREEN << "[OPEN] Port " << port << RESET << endl;
                file << "[OPEN] Port " << port << "\n";
            } else {
                cout << RED << "[CLOSED] Port " << port << RESET << endl;
            }
        }

        file << "\n";
    }

    file.close();
    cout << CYAN << "\nScan complete. Results saved to scan_results.txt\n" << RESET;

    return 0;
}
