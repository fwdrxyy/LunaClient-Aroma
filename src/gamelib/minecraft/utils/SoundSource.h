#pragma once

namespace mc {
    class SoundSource {
    public:
        enum ESoundSource : int {
            field_0x0,
		    field_0x1,
		    noteblock,
		    lightningBolt,
		    field_0x4,
		    monster,
		    entity,
		    player
        };
    };
}