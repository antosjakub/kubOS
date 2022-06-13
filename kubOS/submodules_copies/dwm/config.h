/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Tilda",    NULL,       NULL,       0,            True,        -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN, KEY,TAG) \
	{ MODKEY,                       CHAIN, KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN, KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN, KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };


static Key keys[] = {
	/* { modifier, chain, key, function, argument } */
	{ MODKEY,                       -1, XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,			-1, XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       -1, XK_b,      togglebar,      {0} },
	{ MODKEY,                       -1, XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       -1, XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       -1, XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       -1, XK_l,      setmfact,       {.f = +0.05} },

	{ MODKEY,			-1, XK_i,		incnmaster, 	{.i = +1} },
	{ MODKEY,			-1, XK_o,		incnmaster, 	{.i = -1} },
	
	{ MODKEY|ShiftMask,             -1, XK_Return, zoom,           {0} },
	{ MODKEY,			-1, XK_w,      killclient,     {0} },
	{ MODKEY,           	-1,XK_u,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,            	-1,XK_i,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,            	-1,XK_o,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       -1, XK_Tab,    setlayout,      {0} },
	{ MODKEY|ShiftMask,             -1, XK_space,  togglefloating, {0} },
	{ MODKEY,                       -1, XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             -1, XK_0,      tag,            {.ui = ~0 } },
	
	{ MODKEY,                       -1, XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       -1, XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             -1, XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             -1, XK_period, tagmon,         {.i = +1 } },
	
	TAGKEYS(                        -1, XK_1,                      0)
	TAGKEYS(                        -1, XK_2,                      1)
	TAGKEYS(                        -1, XK_3,                      2)
	TAGKEYS(                        -1, XK_4,                      3)
	{ MODKEY|ControlMask,           -1, XK_e,      quit,           {0} },
	{ MODKEY|ControlMask,		-1, XK_r,      quit,           {1} },


	{ MODKEY,			-1,	XK_f,	spawn,		CMD("firefox") },
	{ MODKEY,			-1,	XK_g,	spawn,		CMD("google-chrome") },
	{ MODKEY,			-1,	XK_c,	spawn,		CMD("code") },

	{ Mod1Mask,			-1,	XK_y,	spawn,		CMD("setxkbmap -layout cz") },
	{ Mod1Mask,			-1,	XK_z,	spawn,		CMD("setxkbmap -layout us") },

	{ MODKEY|ShiftMask,		XK_c, XK_p,	spawn, CMD("bash /home/antos_j/kubOS/clipboard/psswrd.sh") },
	{ MODKEY|ShiftMask,		XK_c, XK_t,	spawn, CMD("bash /home/antos_j/kubOS/clipboard/token.sh") },
	{ MODKEY|ShiftMask,		XK_c, XK_b,	spawn, CMD("bash /home/antos_j/kubOS/clipboard/bazzinga.sh") },
	
};



/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
