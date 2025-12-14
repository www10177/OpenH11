// Custom Raw HID commands for layer monitoring
// This file handles custom VIA commands

#include "quantum.h"
#include "via.h"
#include "raw_hid.h"

// Override VIA's weak via_command_kb function
// This is called BEFORE VIA processes any command
bool via_command_kb(uint8_t *data, uint8_t length) {
    uint8_t cmd = data[0];
    
    // Custom command 0xFE: Query current layer
    if (cmd == 0xFE) {
        uint8_t response[32] = {0};
        response[0] = 0xFE;  // Echo command
        response[1] = get_highest_layer(layer_state);
        raw_hid_send(response, length);
        return true;  // Command handled, don't let VIA process it
    }
    
    // Test command 0xFD: Echo with test value (for debugging)
    if (cmd == 0xFD) {
        uint8_t response[32] = {0};
        response[0] = 0xFD;
        response[1] = 0x42;  // Magic test value
        raw_hid_send(response, length);
        return true;
    }
    
    return false;  // Let VIA handle other commands
}
