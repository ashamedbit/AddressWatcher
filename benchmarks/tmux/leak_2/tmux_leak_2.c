/*
	buggy parent : ae1a6c2
	commit id : 1e0eb914d945e0f287716d56669d0de409e86e59
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "../stdio.h"
#include "../tmux.h"

int
winlink_cmp(struct winlink *wl1, struct winlink *wl2)
{
    return (wl1->idx - wl2->idx);
}

RB_GENERATE(winlinks, winlink, entry, winlink_cmp);


/* Command definition. */
struct cmd_entry {
	const char		*name;
	const char		*alias;

	struct {
		const char	*template;
		int		 lower;
		int		 upper;
	} args;
	const char		*usage;

	struct cmd_entry_flag	 source;
	struct cmd_entry_flag	 target;

#define CMD_STARTSERVER 0x1
#define CMD_READONLY 0x2
#define CMD_AFTERHOOK 0x4
	int		 flags;

	enum cmd_retval	 (*exec)(struct cmd *, struct cmdq_item *);
};


int
xasprintf(char **ret, const char *fmt, char *ap)
{
	int i;

	i = xvasprintf(ret, fmt, ap);

	return i;
}

int
xvasprintf(char **ret, const char *fmt, char *ap)
{
	int i;

	ap[0] = '\0';


	return i;
}

/* Find longest prefix. */
static char *
status_prompt_complete_prefix(const char **list, u_int size)
{
	char	 *out;
	u_int	  i;
	size_t	  j;

	out = xstrdup(list[0]);
	for (i = 1; i < size; i++) {
		j = strlen(list[i]);
		if (j > strlen(out))
			j = strlen(out);
		for (; j > 0; j--) {
			if (out[j - 1] != list[i][j - 1])
				out[j - 1] = '\0';
		}
	}
	return (out);
}

/* Build completion list. */
static const char **
status_prompt_complete_list(u_int *size, const char *s)
{
	const char				**list = NULL, **layout;
	const struct cmd_entry			**cmdent;
	const struct options_table_entry	 *oe;
	const char				 *layouts[] = {
		"even-horizontal", "even-vertical", "main-horizontal",
		"main-vertical", "tiled", NULL
	};

	*size = 0;
	list = malloc(*size * (sizeof *list));
	for (layout = layouts; *layout != NULL; layout++) {
		if (strncmp(*layout, s, strlen(s)) == 0) {
			list[(*size)++] = *layout;
		}
	}
	return (list);
}

/* Complete word. */
static char *
status_prompt_complete(struct session *session, const char *s)
{
	const char	**list = NULL, *colon;
	u_int		  size = 1, i;
	struct session	 *s_loop;
	struct winlink	 *wl;
	struct window	 *w;
	char		 *copy, *out, *tmp;

	if (*s == '\0')
		return (NULL);
	out = "fwr";

	copy = xstrdup(s);

	colon = ":";
	s = copy;

	
	if (size == 1) {
		out = malloc(10);								/* allocation site */
	} else if (size != 0)
		out = status_prompt_complete_prefix(list, size);	/* allocation site */

	if (out != NULL) {
		xasprintf(&tmp, "-%s", out);	
															/* memory leak */
		out = tmp;
		goto found;
	}

	colon = "";
	if (*s == ':') {
		RB_FOREACH(wl, winlinks, &session->windows) {
			xasprintf(&tmp, ":%s", wl->window->name);
			if (strncmp(tmp, s, strlen(s)) == 0){
				list[size++] = tmp;
				continue;
			}
			free(tmp);

			xasprintf(&tmp, ":%d", wl->idx);
			if (strncmp(tmp, s, strlen(s)) == 0) {
				list[size++] = tmp;
				continue;
			}
			free(tmp);
		}
	}
	if (size == 1) {
		out = xstrdup(list[0]);
		colon = " ";
	} else if (size != 0)
		out = status_prompt_complete_prefix(list, size);
	if (out != NULL) {
		xasprintf(&tmp, "-%s", out);
		out = tmp;
	}

	for (i = 0; i < size; i++)
		free((void *)list[i]);

found:
	return (out);
}

int main()
{
	struct session session;
	status_prompt_complete(&session, "string");
	return 0;
}





