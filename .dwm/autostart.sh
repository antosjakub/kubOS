#!/bin/bash

compton &
~/.fehbg &
dwmblocks &
xbindkeys &
tilda &
stw -x 50% -y 50% -X -50% -Y -50% -p 1 -A 1.0 -F monospace:size=16 date '+%Z %I:%M:%S %p %Y'
