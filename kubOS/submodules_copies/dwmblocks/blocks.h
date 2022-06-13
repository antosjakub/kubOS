// acpi: if .. condition for (charging, remaining, charged)


// after making changes here do: $ sudo make clean install, and then $ dwmblocks &
static const Block blocks[] = {
	/* Icon, Command, Update Interval [s], Update Signal */
	{"", "date '+%m %B (%a) %H:%M'", 5, 0},
	{"", "echo $(cat /sys/class/power_supply/BAT1/capacity)%", 30, 0},
	//{"", "acpi | awk '{print $4}'", 30, 0}
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
