#include "ClientPacketListener.h"

#include <Link/Link.h>

namespace mc {
    void ClientPacketListener::send(mc_boost::shared_ptr<Packet> packet) {
    	Link::Func<void, 0x0304A5D8, ClientPacketListener*, mc_boost::shared_ptr<Packet>>()(this, packet);
	}

	void ClientPacketListener::sendCommand(uint32_t commandAddr) {
    	Link::Func<void, 0x0304A5D8, ClientPacketListener*, uint32_t>()(this, commandAddr);
	}

	void ClientPacketListener::handleSoundEvent(const mc_boost::shared_ptr<ClientboundSoundPacket>& packet) {
		Link::Func<void, 0x0306EB2C, ClientPacketListener*, const mc_boost::shared_ptr<ClientboundSoundPacket>&>()(this, packet);
    }
}