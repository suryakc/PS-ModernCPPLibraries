#include "Precompiled.h"
#include <crtdbg.h>
#include <stdio.h>
#include <Windows.h>

#define ASSERT _ASSERTE
#ifdef _DEBUG
#define VERIFY ASSERT
#else
#define VERIFY(expression) (expression)
#endif

static_assert(sizeof(float) == 4, "can't serialize floats!");

struct LastException
{
    DWORD result;

    LastException() : result{ GetLastError() } {}
};

struct ManualResetEvent
{
    HANDLE m_handle;
    ManualResetEvent()
    {
        m_handle = CreateEvent(nullptr,
                               true,
                               false,
                               nullptr);
        if (!m_handle)
        {
            throw LastException();
        }
    }

    ~ManualResetEvent()
    {
        VERIFY(CloseHandle(m_handle));
    }
};

auto main() -> int
{
    //ASSERT(4 == 5);
    //static_assert(sizeof(float) == 4, "can't serialize floats!");
    printf("Hello world!!!");

    auto e = ManualResetEvent{};
    auto e2 = e;
}