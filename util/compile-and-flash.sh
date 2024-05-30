#!/usr/bin/env bash

#  ┏━╸┏━┓┏┳┓┏━┓╻╻  ┏━╸   ┏━┓┏┓╻╺┳┓   ┏━╸╻  ┏━┓┏━┓╻ ╻
#  ┃  ┃ ┃┃┃┃┣━┛┃┃  ┣╸    ┣━┫┃┗┫ ┃┃   ┣╸ ┃  ┣━┫┗━┓┣━┫
#  ┗━╸┗━┛╹ ╹╹  ╹┗━╸┗━╸   ╹ ╹╹ ╹╺┻┛   ╹  ┗━╸╹ ╹┗━┛╹ ╹

case "$1" in
  ergodox)
    sudo ./util/docker_build.sh ergodox_ez:sqve && teensy_loader_cli -mmcu=atmega32u4 -w .build/ergodox_ez_sqve.hex
    ;;
  kbd67)
    sudo ./util/docker_build.sh kbdfans/kbd67/mkiirgb_iso:default && teensy_loader_cli -mmcu=atmega32u4 -w .build/kbdfans_kbd67_mkiirgb_iso_default.hex
    ;;
  manibus)
    sudo ./util/docker_build.sh blank_tehnologii/manibus:sqve:flash
    ;;
  moonlander)
    sudo ./util/docker_build.sh moonlander:sqve:flash
    ;;
  preonic)
    sudo ./util/docker_build.sh preonic/rev3:sqve:dfu-util
    ;;
esac
