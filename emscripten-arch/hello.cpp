#include <iostream>
#include <stdexcept>

int main() try
{
    throw std::runtime_error{"hello world"};
}
catch (std::exception const& ex) {
    std::cerr << ex.what() << "\n";
}
