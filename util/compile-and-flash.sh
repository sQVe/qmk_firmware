#!/usr/bin/env bash

#  ┏━╸┏━┓┏┳┓┏━┓╻╻  ┏━╸   ┏━┓┏┓╻╺┳┓   ┏━╸╻  ┏━┓┏━┓╻ ╻
#  ┃  ┃ ┃┃┃┃┣━┛┃┃  ┣╸    ┣━┫┃┗┫ ┃┃   ┣╸ ┃  ┣━┫┗━┓┣━┫
#  ┗━╸┗━┛╹ ╹╹  ╹┗━╸┗━╸   ╹ ╹╹ ╹╺┻┛   ╹  ┗━╸╹ ╹┗━┛╹ ╹

case "$1" in
  ergodox)
    sudo ./util/docker_build.sh ergodox_ez:sqve && teensy-loader-cli -mmcu=atmega32u4 -w .build/ergodox_ez_sqve.hex
    ;;
  moonlander)
    sudo ./util/docker_build.sh moonlander:sqve:flash
    ;;
  preonic)
    sudo ./util/docker_build.sh preonic/rev3:sqve:dfu-util
    ;;
esac
