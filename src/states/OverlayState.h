#ifndef OVERLAYSTATE
#define OVERLAYSTATE
#include "BaseState.h"
#include "../overlays/BaseOverlay.h"

using namespace overlays;

namespace states {

    class OverlayState: public BaseState {
        private:
            BaseOverlay *overlay = NULL;
            
        public:
            BaseOverlay *get();
            void set(BaseOverlay *o);
    };

}
#endif