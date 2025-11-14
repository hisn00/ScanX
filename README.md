# ⚡ ScanX – Multi‑IP Port Scanner (C++)

ScanX is a lightweight, fast and beginner friendly **multi IP port scanner** written in C++.  
It allows users to scan multiple targets across a custom port range and automatically saves the results to `scan_results.txt`.

---

## 🚀 Features
- 🔍 Scan **multiple IP addresses** in one run  
- 🟢 Detect **open** ports  
- 🔴 Show **closed** ports  
- 💾 Automatically saves results to a text file 
 
---
## 🛠️ Compile

Use `g++`:
g++ scanx.cpp -o scanx
▶️ Run
./scanx

You will be asked:

    Number of IPs
    The IP addresses
    Start port
    End port

Example:
Enter number of IPs to scan: 2
Enter IP 1: 192.168.1.1
Enter IP 2: 192.168.1.10
Enter start port: 20
Enter end port: 100


---
## 📄 Output File

All open ports for every IP are saved to:
scan_results.txt

---

## 📚 Requirements

    Linux environment (socket libraries)

    g++ compiler

---

## ⚠️ Legal & Ethical Notice

ScanX is created for educational and ethical security testing purposes only.
Do NOT scan systems you don't have permission to test.

---

## ⭐ Contribute

Welcome!
