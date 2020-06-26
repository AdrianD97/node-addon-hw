#include <nan.h>

#include <mymath.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  if (info.Length() < 1) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Wrong argument");
    return;
  }

  double arg0 = info[0]->NumberValue(context).FromJust();
  v8::Local<v8::Number> num = Nan::New(mysqrt(arg0));

  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(context,
               Nan::New("mysqrt").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(addon, Init)
