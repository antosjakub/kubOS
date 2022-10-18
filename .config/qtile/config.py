# my config in .config/qtile/config.py


jmol_version = "jmol-14.32.62"


import os
import subprocess
from libqtile import hook

from libqtile import bar, layout, widget, extension
from libqtile.config import Click, Drag, Group, Key, KeyChord, Match, Screen
from libqtile.lazy import lazy
from libqtile.utils import guess_terminal

mod = "mod4"
terminal = guess_terminal()

keys = [
    # Switch between windows
    Key([mod], "h", lazy.layout.left(), desc="Move focus to left"),
    Key([mod], "l", lazy.layout.right(), desc="Move focus to right"),
    Key([mod], "j", lazy.layout.down(), desc="Move focus down"),
    Key([mod], "k", lazy.layout.up(), desc="Move focus up"),
    Key([mod], "space", lazy.layout.next(), desc="Move window focus to other window"),
    # Move windows between left/right columns or move up/down in current stack.
    Key([mod, "shift"], "h", lazy.layout.shuffle_left(), desc="Move window to the left"),
    Key([mod, "shift"], "l", lazy.layout.shuffle_right(), desc="Move window to the right"),
    Key([mod, "shift"], "j", lazy.layout.shuffle_down(), desc="Move window down"),
    Key([mod, "shift"], "k", lazy.layout.shuffle_up(), desc="Move window up"),
    # Grow windows. If current window is on the edge of screen and direction
    # will be to screen edge - window would shrink.
    Key([mod, "control"], "h", lazy.layout.grow_left(), desc="Grow window to the left"),
    Key([mod, "control"], "l", lazy.layout.grow_right(), desc="Grow window to the right"),
    Key([mod, "control"], "j", lazy.layout.grow_down(), desc="Grow window down"),
    Key([mod, "control"], "k", lazy.layout.grow_up(), desc="Grow window up"),
    Key([mod], "n", lazy.layout.normalize(), desc="Reset all window sizes"),
    
    # Toggle between split and unsplit sides of stack.
    Key([mod, "shift"], "Return", lazy.layout.toggle_split(), desc="Toggle between split and unsplit sides of stack"),
    Key([mod], "Return", lazy.spawn(terminal), desc="Launch terminal"),
    
    # Toggle between different layouts as defined below
    Key([mod], "Tab", lazy.next_layout(), desc="Toggle between layouts"),
    Key([mod], "w", lazy.window.kill(), desc="Kill focused window"),
    Key([mod, "control"], "r", lazy.reload_config(), desc="eeload the config"),
    Key([mod, "control"], "e", lazy.shutdown(), desc="exit - logout"),
    Key([mod], "r", lazy.spawncmd(), desc="Spawn a command using a prompt widget"),



        # My shortcuts

    # Brightness
    Key([], "XF86MonBrightnessUp", lazy.spawn("brightnessctl set +1%")),
    Key([], "XF86MonBrightnessDown", lazy.spawn("brightnessctl set 1%-")),

    # Audio
    #Key([], "XF86AudioMute", lazy.spawn("amixer -q set Master toggle")),
    #Key([], "XF86AudioLowerVolume", lazy.spawn("amixer -c 0 -q set Master 1%- unmute")),
    #Key([], "XF86AudioRaiseVolume", lazy.spawn("amixer -c 0 -q set Master 1%+ unmute")),

    # Keyboard Layout
    Key(["mod1"], "y", lazy.spawn("setxkbmap -layout cz")),
    Key(["mod1"], "z", lazy.spawn("setxkbmap -layout us")),

    # Lauch apps 
    KeyChord([mod], "s", [
        Key([], "f", lazy.spawn("firefox")),
        Key([], "c", lazy.spawn("code")),
        Key([], "g", lazy.spawn("google-chrome-stable")),
        Key([], "j", lazy.spawn("java -jar /home/antos_j/bins/{}/Jmol.jar".format(jmol_version))),
    ]),

    # Copy text to clipboard
    KeyChord([mod], "c", [
        Key([], "p", lazy.spawn("bash /home/antos_j/kubOS/clipboard/psswrd.sh")),
        Key([], "t", lazy.spawn("bash /home/antos_j/kubOS/clipboard/token.sh")),
        Key([], "b", lazy.spawn("bash /home/antos_j/kubOS/clipboard/bazzinga.sh"))
    ]), 
    
    # dmenu
    Key([mod], "d", lazy.run_extension(extension.Dmenu(dmenu_command="dmenu_run", dmenu_bottom = True))),
]


group_keys = "uiopm"
group_names = "1234M"
groups = [Group(i) for i in group_names]

for i in range(0, len(groups)):
    keys.extend([
        Key([mod], group_keys[i], lazy.group[group_names[i]].toscreen(), 
            desc = "Switch focus to group {}".format(group_names[i])),
        Key([mod, "shift"], group_keys[i], lazy.window.togroup(group_names[i], switch_group = False),
            desc = "Move window with focus to group {}".format(group_names[i]))
    ])



layouts = [
    layout.Columns(border_on_single = True, border_focus_stack = ["#d75f5f", "#8f3d3d"], border_width = 2),
    layout.Max(border_width = 5),
    layout.Floating(border_width = 2),
    #layout.MonadTall(),
    #layout.MonadWide(),
]

widget_defaults = dict(
    font="sans",
    fontsize=12,
    padding=3,
)
extension_defaults = widget_defaults.copy()

screens = [
    Screen(
        top=bar.Bar(
            [
                widget.Spacer(),
                widget.CurrentScreen(fontsize = 12),
                widget.CurrentLayoutIcon(scale = 0.65),
                widget.Sep(padding = 10, linewidth = 1, size_percent = 80, foreground = 'ffffff'),
                widget.GroupBox(highlight_method='block', rounded = True, this_screen_border = 'cc0000', this_current_screen_border = 'cc0000', fontsize = 14),
                widget.Spacer(),
                widget.Clock(fontsize = 16, format="%H : %M")
            ],
            24,
            margin = [10, 20, 10, 20],
        ),
        bottom = bar.Gap(0),
        left = bar.Gap(0),
        right = bar.Gap(0),
        wallpaper = "/usr/share/images/red.png", wallpaper_mode = "fill",
    ),
]

#Drag floating layouts.
#mouse = [
    #Drag([mod], "Button1", lazy.window.set_position_floating(), start=lazy.window.get_position()),
    #Drag([mod], "Button2", lazy.window.set_size_floating(), start=lazy.window.get_size()),
    #Click([mod], "Button3", lazy.window.bring_to_front()),
#]

dgroups_key_binder = None
dgroups_app_rules = []  # type: list
follow_mouse_focus = True
bring_front_click = False
cursor_warp = False
floating_layout = layout.Floating(
    float_rules=[
        # Run the utility of `xprop` to see the wm class and name of an X client.
        *layout.Floating.default_float_rules,
        Match(wm_class="confirmreset"),  # gitk
        Match(wm_class="makebranch"),  # gitk
        Match(wm_class="maketag"),  # gitk
        Match(wm_class="ssh-askpass"),  # ssh-askpass
        Match(title="branchdialog"),  # gitk
        Match(title="pinentry"),  # GPG key password entry
    ]
)
auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

# If things like steam games want to auto-minimize themselves when losing
# focus, should we respect this or not?
auto_minimize = True

# When using the Wayland backend, this can be used to configure input devices.
wl_input_rules = None


wmname = "LG3D"


@hook.subscribe.startup
def autostart():
    home = os.path.expanduser("~/.config/qtile/autostart.sh")
    subprocess.run([home])
