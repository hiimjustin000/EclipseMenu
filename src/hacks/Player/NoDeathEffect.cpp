#include <modules/gui/gui.hpp>
#include <modules/hack/hack.hpp>
#include <modules/config/config.hpp>

#include <Geode/modify/PlayerObject.hpp>

namespace eclipse::hacks::Player {

    class NoDeathEffect : public hack::Hack {
        void init() override {
            auto tab = gui::MenuTab::find("Player");
            tab->addToggle("No Death Effect", "player.nodeatheffect");
        }

        void update() override {}
        [[nodiscard]] bool isCheating() override { return false; }
        [[nodiscard]] const char* getId() const override { return "No Death Effect"; }
    };

    REGISTER_HACK(NoDeathEffect)

    class $modify(PlayerObject) {
        void playerDestroyed(bool p0) {
            if (!config::get<bool>("player.nodeatheffect", false)) return PlayerObject::playerDestroyed(p0);
        }
    };

}
