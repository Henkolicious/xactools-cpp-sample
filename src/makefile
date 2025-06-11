server: main.cpp
	g++ -o server main.cpp -I "C:\Program Files\OpenSSL-Win64\include" -L "C:\Program Files\OpenSSL-Win64\lib" -lssl -lcrypto -lws2_32 -DCPPHTTPLIB_OPENSSL_SUPPORT

run: server
	server.exe

clean:
	del server.exe