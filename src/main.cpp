#include <cstdlib>
#include <iostream>
#include <string>
#include <zmq.hpp>

int main() {
  zmq::context_t ctx;
  zmq::socket_t sock(ctx, zmq::socket_type::pull);
  sock.bind(std::string("tcp://*:") + std::getenv("SERVICE_PORT"));
  for (;;) {
    std::cout << "waiting for message" << std::endl;
    auto message = zmq::message_t{};
    if (sock.recv(message)) {
      std::cout << "received " << message << std::endl;
      zmq::socket_t monitor(ctx, zmq::socket_type::push);
      monitor.connect(std::getenv("MONITOR_URL"));
      monitor.send(zmq::buffer("ping"));
    }
  }
}
