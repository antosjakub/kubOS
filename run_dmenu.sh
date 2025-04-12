#!/bin/bash

# Source the aliases file
source ~/kubos/.bash_aliases_dmenu

# Define dmenu arguments in a separate variable for readability
DMENU_ARGS="-nb #000000 -nf #bbbbbb -sb #005577 -sf #eeeeee -fn monospace-18 -y 14"

# Get the list of alias names (without the command) 
alias_names=$(alias | sed -E "s/alias ([^=]*)='.*'/\1/")

# Show them in dmenu with the alias names only
selected=$(echo "$alias_names" | dmenu $DMENU_ARGS)

# If an alias was selected, find the full command and execute it
if [ -n "$selected" ]; then
    # Get the full alias command for the selected alias
    alias_command=$(alias "$selected" | sed -E "s/alias [^=]*='(.*)'/\1/")

    # Execute the command associated with the alias
    eval "$alias_command"
fi

