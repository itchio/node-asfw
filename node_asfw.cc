
#include "node_asfw.h"

#if defined(WIN32)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#else // defined(WIN32)

#define DWORD uint32_t
#define BOOL bool

static AllowSetForegroundWindow(DWORD pid) BOOL {
    return 0;
}

#endif // defined(WIN32)

NAN_METHOD(AllowSetForegroundWindow) {
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
}
