#!/bin/bash

ARDUINO_CLI="./bin/arduino-cli --config-file arduino-cli.yml"
ARDUINO_CLI_VERSION=$(cat .arduinocliversion)

function install {
    # apt install python-is-python3
    curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh -s $ARDUINO_CLI_VERSION
    $ARDUINO_CLI core update-index
    $ARDUINO_CLI core install esp32:esp32
    lib-install 'FastLED@3.4.0'
    lib-install 'Adafruit BNO055@1.5.0'
    lib-install 'FreeRTOS@10.4.4-2'
}

function lib-install {
    ARG=$@
    $ARDUINO_CLI lib install "${ARG}"
}

function list-boards {
    $ARDUINO_CLI board list
}

function compile {
    $ARDUINO_CLI compile --fqbn esp32:esp32:esp32 .
}

function help {
    echo "$0 <task> <args>"
    echo "Tasks:"
    compgen -A function | cat -n
}

TIMEFORMAT="Task completed in %3lR"
time ${@:-help}