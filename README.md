# To-Do

- [] Server handle http requests. test them with curl.
    - After that, re-build the project or some parts to hit it from another angle, like multithreading, load balancer... 
- [] Compartmentalize the project files and functions.
- [] non blocking syscals with poll epoll and fnctl and so...


| Stage                | Goals                                            |
| -------------------- | ------------------------------------------------ |
| ✅ **MVP**            | Handle GET `/`, respond with hardcoded HTML      |
| 🔍 **Basic Parsing** | Extract method, path, headers                    |
| 📂 **Serve Files**   | Serve static `.html`, `.jpg`, etc. from a folder |
| 📬 **Handle POST**   | Read body, maybe echo it                         |
| 🔒 **Robustness**    | Handle malformed requests gracefully             |
| 📈 **Performance**   | Add multithreading (e.g., `fork()` or `pthread`) |


