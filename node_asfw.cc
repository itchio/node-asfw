
#include "node_asfw.h"
#include <string>
#include <sstream>

#if defined(WIN32)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#else // defined(WIN32)

#define HWND uintptr_t
#define DWORD uint32_t
#define BOOL bool

static AllowSetForegroundWindow(DWORD pid) BOOL {
    return 0;
}

static SetForegroundWindow(HWND h) BOOL {
    return 0;
}

static GetLastError() DWORD {
    return 0;
}

#endif // defined(WIN32)

NAN_METHOD(_AllowSetForegroundWindow) {
    if (info[0]->IsUndefined()) {
        Nan::ThrowError("AllowSetForegroundWindow needs one argument");
    }
    auto maybeArg = Nan::To<int64_t>(info[0]);
    if (maybeArg.IsNothing()) {
        Nan::ThrowError("AllowSetForegroundWindow needs a number argumeng");
    }

    DWORD pid = (DWORD)(maybeArg.FromJust());
    BOOL ret = AllowSetForegroundWindow(pid);
    info.GetReturnValue().Set(ret);

    if (ret == 0) {
        DWORD lastError = GetLastError();
        if (lastError != 0) {
            std::stringstream ss;
            ss << "Windows error code " << lastError;
            auto err = ss.str();
            Nan::ThrowError(err.c_str());
        }
    }
}

NAN_METHOD(_SetForegroundWindow) {
    if (info[0]->IsUndefined()) {
        Nan::ThrowError("SetForegroundWindow needs one argument");
    }
    auto maybeArg = Nan::To<int64_t>(info[0]);
    if (maybeArg.IsNothing()) {
        Nan::ThrowError("SetForegroundWindow needs a number argumeng");
    }

    HWND hwnd = (HWND)(maybeArg.FromJust());
    BOOL ret = SetForegroundWindow(hwnd);
    info.GetReturnValue().Set(ret);

    if (ret == 0) {
        DWORD lastError = GetLastError();
        if (lastError != 0) {
            std::stringstream ss;
            ss << "Windows error code " << lastError;
            auto err = ss.str();
            Nan::ThrowError(err.c_str());
        }
    }
}
