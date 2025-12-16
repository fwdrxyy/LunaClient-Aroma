#include "Minecraft.h"

#include <Link/Link.h>

namespace mc {
    Minecraft* Minecraft::getInstance() {
        return Link::Func<Minecraft*, 0x03166818>()();
    }
        
    Level* Minecraft::getLevel(int i) {
		return Link::Func<Level*, 0x0318C878, Minecraft*, int>()(this, i);
	}
		
	ClientPacketListener* Minecraft::getConnection(int i) {
		return Link::Func<ClientPacketListener*, 0x031B2654, Minecraft*, int>()(this, i); 
	}

	mc_boost::shared_ptr<LocalPlayer>* Minecraft::GetPlayerByPlayerIndex(int idx, const mc_boost::shared_ptr<LocalPlayer>& dest) {
    	return Link::Func<mc_boost::shared_ptr<LocalPlayer>*, 0x031b3644, Minecraft*, const mc_boost::shared_ptr<LocalPlayer>&, int>()(this, dest, idx);
  	}
}