#include "node_asfw.h"

using v8::FunctionTemplate;

NAN_MODULE_INIT(InitAll) {
    Nan::Set(target, Nan::New("AllowSetForegroundWindow").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(AllowSetForegroundWindow)).ToLocalChecked());
}

NODE_MODULE(asfw, InitAll)