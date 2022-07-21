/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 500;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {
	/* function format          argument */
	{run_command, " %%{+u}%s%%{-u}", "~/Code/Scripts/get_current_group.py"},
	{ datetime, " %%{r}%%{F#ff5555}%%{U#ff5555}%%{+u}Datetime: %s%%{-u}%%{F-}%%{U-} ",           "%I:%M%p / %d %B %Y" },
	/*{ separator, "%s",	"|"},*/
	{ battery_state, " %%{F#50fa7b}%%{U#50fa7b}%%{+u}Battery: %s", 	"BAT0"},
	{ battery_perc, " %s%%", 	"BAT0"},
	{ battery_remaining, " %s%%{-u}%%{F-}%%{U-} ", "BAT0"},
	{ wifi_essid, " %%{F#ffb86c}%%{U#ffb86c}%%{!u}Net: %s ", "wlp2s0"},
	{ wifi_perc, " \.%s%%{F-}%%{U-}%%{!u} ", "wlp2s0"},
	{ run_command,
      " %%{A:amixer -D pulse sset Master toggle:}%%{F#8be9fd}%%{U#8be9fd}%%{!u}Volume: %s%%{F-}%%{U-}%%{!u}%%{A} ",
      "amixer -D pulse sget Master | rg 'Front Left: Playback' | tr -d '[]' | rg -o '[0-9][0-9]% (on|off)'"
    },
	{ run_command,
	  " %%{T2}%%{+u}%s ",
	  "echo -n '%{A:slock:}\uf023%{A}'"
	},
	{ run_command,
	  " %s ",
	  "echo -n '%{A:systemctl suspend:}\uf186%{A}'"
	},
	{ run_command,
	  " %s ",
	  "echo -n '%{A:qtile cmd-obj -o cmd -f shutdown:}\uf08b%{A}'"
	},
	{ run_command,
	  " %s%%{-u} ",
	  "echo -n '%{A:shutdown --now:}\uf011%{A}'"
	},
	//{ separator, "%s", "%{r}%{A:systemctl suspend:}\uf186%{A}"},
	//{ separator, "%s", "%{r}%{A:qtile cmd-obj -o cmd -f shutdown:}\uf08b%{A}"},
	//{ separator, "%s%%{-u}", "%{r}%{A:shutdown --now:}\uf011%{A}"},
};
