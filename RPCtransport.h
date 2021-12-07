#pragma once
#include <array>

class RPCtransport
{
public:
    size_t send(const void* buffer, size_t size);
    size_t recv(void* buffer, size_t size);

private:
    std::array<char, 8192> m_buffer;
    size_t m_message;
};


