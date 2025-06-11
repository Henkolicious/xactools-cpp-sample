# C++ REST API Sample
Random library used:
https://github.com/yhirose/cpp-httplib

Target OS win-x64.
`$` denotes it's a CLI command.

To compile it on your own, use the make file - but then you might need to adjust the patch to the `OPENSSL` tool.

`$ make run`

Clean

`$ make clean`

Or just run the pre-compiled `server.exe` file like:

`$ .\server.exe`

Use whatever client you want (insomnia, postman, curl, httprepl , ...).

Here's a sample using `curl` for the `GET` request.

`$ curl -k --request GET --url https://localhost:5555/hi`

Here's a sample using `curl` for the `PUT` request.
<pre>$ curl -k --request PUT --url https://localhost:5555/foo --header 'Authorization: ApiKey MY_API_KEY' --header 'Content-Type: application/json' --data '{ "sample": "foo" }'</pre>
