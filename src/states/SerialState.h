#include <Arduino.h>
#include "BaseState.h"

namespace states {

    class SerialState: public BaseState {            
        public:
            void write(char msg[]);
            
    };

}