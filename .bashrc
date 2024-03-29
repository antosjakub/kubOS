# .bashrc


# My

# start julia from anywhere
export PATH="$PATH:$HOME/bins/julia-1.7.2/bin"
# set default text editor to vim
export EDITOR=vim

# alias
alias clc="clear"
alias qt="bash /home/antos_j/bins/Qt/Tools/QtCreator/bin/qtcreator.sh"




# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific environment
if ! [[ "$PATH" =~ "$HOME/.local/bin:$HOME/bin:" ]]
then
    PATH="$HOME/.local/bin:$HOME/bin:$PATH"
fi
export PATH

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
if [ -d ~/.bashrc.d ]; then
	for rc in ~/.bashrc.d/*; do
		if [ -f "$rc" ]; then
			. "$rc"
		fi
	done
fi

unset rc
