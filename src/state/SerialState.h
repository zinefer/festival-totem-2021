#include <Arduino.h>
#include "BaseState.h"

namespace state {

    class SerialState: public BaseState {            
        public:
            void write(char msg[]);
            
    };

}