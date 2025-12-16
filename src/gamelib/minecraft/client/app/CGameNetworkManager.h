#ifndef CGAMENETWORKMANAGER_H
#define CGAMENETWORKMANAGER_H

namespace mc {
    class CGameNetworkManager {
    public:
        static CGameNetworkManager* getInstance();

        bool IsHost();

        static void FakeLocalPlayerJoined();
    };
} // namespace mc

#endif // CGAMENETWORKMANAGER_H
