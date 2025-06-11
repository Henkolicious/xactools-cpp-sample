#include "../lib/httplib/httplib.h"

const std::string APIKEY = "MY_API_KEY";

bool is_authenticated(const httplib::Request &req)
{
    std::string auth = req.get_header_value("Authorization");
    return auth == "ApiKey " + APIKEY;
}

int main(void)
{
    int port = 5555;
    // generated self signed development certificate
    httplib::SSLServer ssl_server("certificates/server.crt", "certificates/server.key");

    ssl_server
        .set_logger([](const httplib::Request &req, const httplib::Response &res)
        {
            std::cout << "[" << req.method << "] " << req.path << " " << res.status << std::endl; 
        })
        .Get("/hi", [](const httplib::Request &req, httplib::Response &res)
        { 
            res.set_content("Hello World!", "text/plain"); 
        })
        .Put("/foo", [](const httplib::Request &req, httplib::Response &res)
        {
            if (!is_authenticated(req)) {
                res.status = 401;
                res.set_content(R"({"error":"Unauthorized"})", "application/json");
                return;
            }

            std::cout << "Received PUT request on /foo:" << std::endl;
            std::cout << "--- START BODY ---" << std::endl;
            std::cout << req.body << std::endl;
            std::cout << "--- END BODY ---" << std::endl;
            res.set_content("Data received successfully! Body logged on server.", "text/plain");
            res.status = 200; 
        });

    std::cout << "Server listening on localhost:" << port << std::endl;
    std::cout << "Press Ctrl+C to stop." << std::endl;

    ssl_server.listen("localhost", port);
}
