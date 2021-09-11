/*template<uint8_t DATA_PIN, EOrder RGB_ORDER>
using LED_TYPE = WS2811*/

#define DATA_PIN             23
#define CLK_PIN              22
#define LED_TYPE             APA102
#define COLOR_ORDER          BGR
#define FRAMES_PER_SECOND    120

#define NUM_LEDS             145
#define BRIGHTNESS           25