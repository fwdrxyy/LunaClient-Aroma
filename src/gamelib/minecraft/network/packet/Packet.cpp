#include "Packet.h"

#include <Link/Link.h>

namespace mc {
    Packet::~Packet() { Link::Func<void, 0x027CD034, Packet *>()(this); }
} // namespace mc
