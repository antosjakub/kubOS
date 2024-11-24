
if [ -f ~/.kubos/.bash_aliases_dmenu ]; then
    . ~/.kubos/.bash_aliases_dmenu
fi

alias sound='alsamixer'
alias battery='cat /sys/class/power_supply/BAT1/capacity'

alias c='clear'

# export PATH='/home/anto_j/miniconda3/bin:$PATH'  # commented out by conda initialize
