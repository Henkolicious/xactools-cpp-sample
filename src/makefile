server: main.cpp
	g++ -static -o server main.cpp -I "C:\Program Files\OpenSSL-Win64\include" -L "C:\Program Files\OpenSSL-Win64\lib" -Wl,-Bstatic -lssl -lcrypto -Wl,-Bdynamic -lws2_32 -lcrypt32 -DCPPHTTPLIB_OPENSSL_SUPPORT

run: server
	server.exe

clean:
	del server.exe