# OpenH11 - QMK Firmware for DOIO KBGM-H11

This repository contains a QMK firmware implementation for the DOIO KBGMH11 keyboard, referred to here as OpenH11. The specific keyboard definition is located within the `keyboards/open_h11/` directory.

## WARNING: Flashing Risks

**Flashing custom firmware can potentially brick your keyboard.** If the flashing process fails or overwrites the STM32duino bootloader, you might be unable to enter bootloader mode again via standard methods.

**Recovery may require:**
*   An ST-Link programmer/debugger.
*   Soldering skills to connect the ST-Link to the appropriate pins on the PCB.

**Proceed with caution and at your own risk.**

## Main Features

This firmware aims to provide an open-source alternative for the DOIO KBGM-H11, enabling features and customizations available through QMK. Key features include:

*   **OLED Screen Modification:** Allows customization of the OLED display content. (Implementation details can be found in the keyboard-specific code).
*   **Low Latency:** Configured for a 1000Hz polling rate and utilizes QMK's debounce algorithms for responsiveness.
*   **Fully Open Source:** Leverages the QMK framework, allowing users to implement any QMK feature, customize keymaps, and contribute to the project.

## Building the Firmware

Ensure this `OpenH11` directory is placed within your `qmk_firmware/keyboards/` directory.

After setting up your [QMK build environment](https://docs.qmk.fm/#/getting_started_build_tools), build the firmware using the `qmk compile` command:

```bash
qmk compile -kb open_h11 -km via
```

This will generate a `.hex` or `.bin` file in your QMK root directory (`qmk_firmware/`).

## Flashing the Firmware

**Refer to the WARNING section above before proceeding.**

You can flash the compiled firmware using several methods:

1.  **QMK Toolbox:** A graphical tool for flashing. Download it [here](https://github.com/qmk/qmk_toolbox/releases). Put your keyboard into bootloader mode, load the compiled `.hex` or `.bin` file into QMK Toolbox, and press "Flash".
2.  **`qmk flash` command:** Use the QMK CLI to flash:
    ```bash
    qmk flash -kb open_h11 -km via
    ```
    This command compiles and flashes in one step.
3.  **Pre-compiled Firmware:** If pre-compiled `.hex` or `.bin` files are provided (e.g., in a releases section), you can flash them directly using QMK Toolbox or other flashing tools compatible with the STM32Duino bootloader (like STM32CubeProgrammer if using the ST-Link method after a bad flash).

## Entering the Bootloader

If you need to manually enter the bootloader:

*   **Keycode in layout:** Press the key mapped to `QK_BOOT` (if you have one mapped in your keymap).
*   **Physical reset button:** Briefly press the reset button on the PCB (location may vary).
*   **Bootmagic reset:** Hold down the top-left key (usually Escape) while plugging in the keyboard. *(Note: Bootmagic might need to be explicitly enabled in `keyboards/open_h11/rules.mk` or `keyboards/open_h11/config.h`)*

See the QMK [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
