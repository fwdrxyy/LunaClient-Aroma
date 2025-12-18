#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>

#include "../LunaToggle.h"

class LunaToggleWelcomeMessage : public LunaToggle {
public:
    void C();

    LunaToggleWelcomeMessage():
};

LunaToggleWelcomeMessage() : LunaToggle("Welcome Message", false) {}

int peopleInWorld(bool fix) {
    return fix ? MinecraftServer::GetInstance()->GetPlayers()->players.size() : MinecraftServer::GetInstance()->GetPlayers()->players.size() - 1;
}

void personJoinEvent() {
    wchar_t temp[0x40];
    swprintf(temp, 0x40, L"Welcome To The Server! I Hope You Enjoy Alot");
    swprintf(temp, 0x40, L"サーバーへようこそ。この世界で楽しんでください");
    swprintf(temp, 0x40, L"¡Bienvenido al servidor! Espero que lo disfrutes mucho.")
    auto server = MinecraftServer::GetInstance();
    if (!server) return;
    auto players = server->GetPlayers();
    if (!players) return;
    for (auto& _player : players->players) {
        _player->listener->send(new ClientboundChatPacket(temp));
        _player->listener->send(new ClientboundSoundPacket(SoundEvent::random_successful_hit));
    }
}

void LunaToggleWelcomeMessage::C() {
    if (isEnabled) { // Only Host Check
        if (CGameNetworkManager::GetNetworkManager()->IsHost() == false) {
            isEnabled = false;
            return;
        }
    }

    if (isEnabled) {
        static int prevPeople = peopleInWorld(false);
        int currentPeople = peopleInWorld(false);
        
        if (currentPeople > prevPeople) {
            // Someone has joined, send the welcome message
            personJoinEvent();
        }
        
        prevPeople = currentPeople;
    }
} // neko's old welcome message from Latte