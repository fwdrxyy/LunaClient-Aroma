#include "UIScene.h"

#include <Link/Link.h>

namespace mc {
    UIScene::UIScene() {
        Link::Func<void, 0x02E39FD8, UIScene*>()(this);
    }
    
    UIScene::UIScene(int32_t id, UILayer *layer) { 
        Link::Func<void, 0x02E39FD8, UIScene*, int32_t, UILayer*>()(this, id, layer);
    }

	UIScene::~UIScene() {
        Link::Func<void, 0x02E30050, UIScene*>()(this);
    }

    void UIScene::initialiseMovie() {
        Link::Func<void, 0x02E3A79C, UIScene*>()(this);
    }

    void UIScene::doHorizontalResizeCheck() { 
        Link::Func<void, 0x02E637C0, UIScene*>()(this);
    }

    void UIScene::SetBackScene(UIScene *backScene) { 
        Link::Func<void, 0x02E84614, UIScene*, UIScene*>()(this, backScene);
    }
    
	void UIScene::setOpacity(float opacity) { 
        Link::Func<void, 0x02E89B38, UIScene*, float>()(this, opacity);
    }

	void UIScene::navigateBack() { 
        Link::Func<void, 0x02E365B4, UIScene*>()(this);
    }

	void UIScene::sendInputToMovie(uint32_t param_1, bool param_2, bool param_3, bool param_4) { 
        Link::Func<void, 0x02E3CBD0, UIScene*, int32_t, bool, bool, bool>()(this, param_1, param_2, param_3, param_4);
    }
}