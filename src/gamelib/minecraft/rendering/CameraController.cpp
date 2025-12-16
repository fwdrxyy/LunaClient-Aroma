#include "CameraController.h"

#include <Link/Link.h>

namespace mc {
    double* CameraController::getCurrentPos() {
        return Link::Func<double*, 0x02bf33a4, CameraController*>()(this);
    }

    double* CameraController::getCurrentRot() {
        return Link::Func<double*, 0x02bf33ac, CameraController*>()(this);
    }
}