//#include "../config.h"

#include <Vector.h>

#include "KeyFrame.h"

namespace animator {
    typedef Vector<KeyFrame*> KeyFrames;

    class Timeline {
        private:
            //KeyFrame* frameArray[EFFECT_LIST_MAX];
            KeyFrame* frameArray[32];
            KeyFrames frames;
            int currentFrame = 0;
        
        public:
            Timeline();
            void add(KeyFrame* frame);
            void remove(int i);
            void advance();
            KeyFrame* current();
    };
}