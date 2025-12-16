#include "C4JThreadImpl.h"

#include <Link/Link.h>

namespace mc {
    C4JThreadImpl::C4JThreadImpl(int(*func)(void*), void* data, const char* name, int stack_size) {
        Link::Func<void, 0x034acac0, C4JThreadImpl*, int(*)(void*), void*, const char*, int>()(this, func, data, name, stack_size);
    }

    void C4JThreadImpl::SetDeleteOnExit(bool ex) {
        Link::Func<void, 0x034ad0b0, C4JThreadImpl*, bool>()(this, ex);
    }

    void C4JThreadImpl::Run() {
        Link::Func<void, 0x034acf6c, C4JThreadImpl*>()(this);
    }

    bool C4JThreadImpl::isRunning() {
        return Link::Func<bool, 0x034acfcc, C4JThreadImpl*>()(this);
    }
}