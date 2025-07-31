#include "crow.h"
#include "requests.h"
#include "utils.h"
#include <jsoncpp/json/json.h>
#include <string>

int main() {
  crow::SimpleApp server;
  // Parse the JSON string

  CROW_ROUTE(server, "/")
  ([]() {
    auto page = crow::mustache::load_text("index.html");
    return page;
  });

  server.port(9090).multithreaded().run();
}