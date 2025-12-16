#include "MultiListSliderLogic.h"

#include <Link/Link.h>

namespace mc {
    MultiListSliderLogic::MultiListSliderLogic() { 
        Link::Func<void, 0x02E6CB0C, MultiListSliderLogic*>()(this);
    }

    void MultiListSliderLogic::AddTo(UIControl_MultiList &list, int32_t param_2) {
        Link::Func<void, 0x02E6CFF8, MultiListSliderLogic*, UIControl_MultiList&, int32_t>()(this, list, param_2);
    }
}