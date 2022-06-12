#!/bin/sh

killall conky
conky -c "$HOME/.config/conky/qtile_red_conky.conf"
