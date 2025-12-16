#pragma once

#include <utils/Logger.h>

#include "../LunaButton.h"

class LunaButtonChat : public LunaButton {
public:
    LunaButtonChat() : LunaButton("Chat") {}

    void onPress() override {
        CInput::GetInput()->RequestKeyboard(
                L"", L"", 0, 0x96,
                [](void *, bool ok) -> int32_t {
                    if (ok) {
                        wchar_t buffer[0x96];
                        CInput::GetInput()->GetText(buffer, 0x96);
                        Minecraft::getInstance()->getConnection(0)->send(new ClientboundChatPacket(buffer));
                    }

                    return 0;
                },
                nullptr, CInput::KeyboardMode::FULL);
    }
};