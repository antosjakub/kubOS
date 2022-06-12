#!/bin/bash

compton &
~/.fehbg &
dwmblocks &
xbindkeys &
tilda &
#killall conky
#conky -b --double-buffer -c "$HOME.config/conky/conky_neptun.conf"
stw -x 50% -y 50% -X -50% -Y -50% -p 1 -A 1.0 -F monospace:size=16 date
