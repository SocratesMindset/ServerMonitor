# ServerMonitor
Web-App for monitoring server status

#StartBackend

g++ -std=c++17 main.cpp -lpthread -o server
./server

#Could be troubles with ASIO - try 'sudo apt install libasio-dev libssl-dev'

#StartFrontend
cd frontend
npm start
