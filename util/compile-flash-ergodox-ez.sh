#!/usr/bin/env bash

sudo ./util/docker_build.sh ergodox_ez:sqve && teensy-loader-cli -mmcu=atmega32u4 -w .build/ergodox_ez_sqve.hex
