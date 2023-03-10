/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 141 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __suseconds_t;
#line 172 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __ssize_t;
#line 102 "/usr/include/stdio.h"
typedef __ssize_t ssize_t;
#line 75 "/usr/include/time.h"
typedef __time_t time_t;
#line 30 "/usr/include/x86_64-linux-gnu/bits/time.h"
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
#line 192 "../stdio.h"
typedef unsigned short u_short___0;
#line 193 "../stdio.h"
typedef unsigned int u_int___0;
#line 204 "../stdio.h"
typedef unsigned char u_char___0;
#line 210 "../stdio.h"
typedef int pid_t___0;
#line 38 "../tmux.h"
typedef char bitstr_t;
#line 40 "../tmux.h"
struct event {

};
#line 41 "../tmux.h"
struct termios {

};
#line 47
struct args;
#line 47
struct args;
#line 48
struct client;
#line 48
struct client;
#line 49
struct cmd_find_state;
#line 49
struct cmd_find_state;
#line 50
struct cmdq_item;
#line 50
struct cmdq_item;
#line 51
struct cmdq_list;
#line 51
struct cmdq_list;
#line 52
struct environ;
#line 52
struct environ;
#line 53
struct format_job_tree;
#line 53
struct format_job_tree;
#line 54
struct input_ctx;
#line 54
struct input_ctx;
#line 56
struct mouse_event;
#line 56
struct mouse_event;
#line 57
struct options;
#line 57
struct options;
#line 59
struct session;
#line 59
struct session;
#line 60
struct tmuxpeer;
#line 60
struct tmuxpeer;
#line 137 "../tmux.h"
typedef unsigned long long key_code;
#line 519 "../tmux.h"
struct utf8_data {
   u_char___0 data[9] ;
   u_char___0 have ;
   u_char___0 size ;
   u_char___0 width ;
};
#line 527
enum utf8_state {
    UTF8_MORE = 0,
    UTF8_DONE = 1,
    UTF8_ERROR = 2
} ;
#line 561 "../tmux.h"
struct grid_cell {
   u_char___0 flags ;
   u_short___0 attr ;
   int fg ;
   int bg ;
   struct utf8_data data ;
};
#line 568 "../tmux.h"
struct __anonstruct_data_27 {
   u_char___0 attr ;
   u_char___0 fg ;
   u_char___0 bg ;
   u_char___0 data ;
};
#line 568 "../tmux.h"
union __anonunion____missing_field_name_26 {
   u_int___0 offset ;
   struct __anonstruct_data_27 data ;
};
#line 568 "../tmux.h"
struct grid_cell_entry {
   u_char___0 flags ;
   union __anonunion____missing_field_name_26 __annonCompField1 ;
};
#line 582 "../tmux.h"
struct grid_line {
   u_int___0 cellused ;
   u_int___0 cellsize ;
   struct grid_cell_entry *celldata ;
   u_int___0 extdsize ;
   struct grid_cell *extddata ;
   int flags ;
};
#line 594 "../tmux.h"
struct grid {
   int flags ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 hscrolled ;
   u_int___0 hsize ;
   u_int___0 hlimit ;
   struct grid_line *linedata ;
};
#line 609
struct cmd_list;
#line 622
struct bufferevent;
#line 647
enum __anonenum_lineflag_31 {
    LINE_SEL_NONE = 0,
    LINE_SEL_LEFT_RIGHT = 1,
    LINE_SEL_RIGHT_LEFT = 2
} ;
#line 647 "../tmux.h"
struct screen_sel {
   int flag ;
   int hidden ;
   int rectflag ;
   enum __anonenum_lineflag_31 lineflag ;
   int modekeys ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 ex ;
   u_int___0 ey ;
   struct grid_cell cell ;
};
#line 670
struct screen_titles;
#line 670
struct screen_titles;
#line 671 "../tmux.h"
struct screen {
   char *title ;
   struct screen_titles *titles ;
   struct grid *grid ;
   u_int___0 cx ;
   u_int___0 cy ;
   u_int___0 cstyle ;
   char *ccolour ;
   u_int___0 rupper ;
   u_int___0 rlower ;
   int mode ;
   bitstr_t *tabs ;
   struct screen_sel sel ;
};
#line 694
struct screen_write_collect_item;
#line 694
struct screen_write_collect_item;
#line 695
struct screen_write_collect_line;
#line 695
struct screen_write_collect_line;
#line 696
struct window_pane;
#line 696 "../tmux.h"
struct screen_write_ctx {
   struct window_pane *wp ;
   struct screen *s ;
   struct screen_write_collect_item *item ;
   struct screen_write_collect_line *list ;
   u_int___0 scrolled ;
   u_int___0 bg ;
   u_int___0 cells ;
   u_int___0 written ;
   u_int___0 skipped ;
};
#line 720 "../tmux.h"
struct window_mode {
   char const   *name ;
   struct screen *(*init)(struct window_pane * , struct cmd_find_state * , struct args * ) ;
   void (*free)(struct window_pane * ) ;
   void (*resize)(struct window_pane * , u_int___0  , u_int___0  ) ;
   void (*key)(struct window_pane * , struct client * , struct session * , key_code  ,
               struct mouse_event * ) ;
   char const   *(*key_table)(struct window_pane * ) ;
   void (*command)(struct window_pane * , struct client * , struct session * , struct args * ,
                   struct mouse_event * ) ;
};
#line 738
struct winlink;
#line 738
struct format_tree;
#line 760
struct window;
#line 760
struct layout_cell;
#line 760 "../tmux.h"
struct __anonstruct_entry_32 {
   struct window_pane *tqe_next ;
   struct window_pane **tqe_prev ;
};
#line 760 "../tmux.h"
struct __anonstruct_tree_entry_33 {
   struct window_pane *rbe_left ;
   struct window_pane *rbe_right ;
   struct window_pane *rbe_parent ;
   int rbe_color ;
};
#line 760 "../tmux.h"
struct window_pane {
   u_int___0 id ;
   u_int___0 active_point ;
   struct window *window ;
   struct layout_cell *layout_cell ;
   struct layout_cell *saved_layout_cell ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 osx ;
   u_int___0 osy ;
   u_int___0 xoff ;
   u_int___0 yoff ;
   int flags ;
   int argc ;
   char **argv ;
   char *shell ;
   char const   *cwd ;
   pid_t___0 pid ;
   char tty[10] ;
   int status ;
   int fd ;
   struct bufferevent *event ;
   struct event resize_timer ;
   struct input_ctx *ictx ;
   struct grid_cell colgc ;
   int *palette ;
   int pipe_fd ;
   struct bufferevent *pipe_event ;
   size_t pipe_off ;
   struct screen *screen ;
   struct screen base ;
   struct screen status_screen ;
   size_t status_size ;
   u_int___0 saved_cx ;
   u_int___0 saved_cy ;
   struct grid *saved_grid ;
   struct grid_cell saved_cell ;
   struct window_mode  const  *mode ;
   void *modedata ;
   struct event modetimer ;
   time_t modelast ;
   u_int___0 modeprefix ;
   char *searchstr ;
   struct __anonstruct_entry_32 entry ;
   struct __anonstruct_tree_entry_33 tree_entry ;
};
#line 837 "../tmux.h"
struct window_panes {
   struct window_pane *tqh_first ;
   struct window_pane **tqh_last ;
};
#line 841 "../tmux.h"
struct __anonstruct_alerts_entry_34 {
   struct window *tqe_next ;
   struct window **tqe_prev ;
};
#line 841 "../tmux.h"
struct __anonstruct_winlinks_35 {
   struct winlink *tqh_first ;
   struct winlink **tqh_last ;
};
#line 841 "../tmux.h"
struct __anonstruct_entry_36 {
   struct window *rbe_left ;
   struct window *rbe_right ;
   struct window *rbe_parent ;
   int rbe_color ;
};
#line 841 "../tmux.h"
struct window {
   u_int___0 id ;
   char *name ;
   struct event name_event ;
   struct timeval name_time ;
   struct event alerts_timer ;
   struct timeval activity_time ;
   struct window_pane *active ;
   struct window_pane *last ;
   struct window_panes panes ;
   int lastlayout ;
   struct layout_cell *layout_root ;
   struct layout_cell *saved_layout_root ;
   char *old_layout ;
   u_int___0 sx ;
   u_int___0 sy ;
   int flags ;
   int alerts_queued ;
   struct __anonstruct_alerts_entry_34 alerts_entry ;
   struct options *options ;
   struct grid_cell style ;
   struct grid_cell active_style ;
   u_int___0 references ;
   struct __anonstruct_winlinks_35 winlinks ;
   struct __anonstruct_entry_36 entry ;
};
#line 891 "../tmux.h"
struct __anonstruct_entry_37 {
   struct winlink *rbe_left ;
   struct winlink *rbe_right ;
   struct winlink *rbe_parent ;
   int rbe_color ;
};
#line 891 "../tmux.h"
struct __anonstruct_wentry_38 {
   struct winlink *tqe_next ;
   struct winlink **tqe_prev ;
};
#line 891 "../tmux.h"
struct __anonstruct_sentry_39 {
   struct winlink *tqe_next ;
   struct winlink **tqe_prev ;
};
#line 891 "../tmux.h"
struct winlink {
   int idx ;
   struct session *session ;
   struct window *window ;
   size_t status_width ;
   struct grid_cell status_cell ;
   char *status_text ;
   int flags ;
   struct __anonstruct_entry_37 entry ;
   struct __anonstruct_wentry_38 wentry ;
   struct __anonstruct_sentry_39 sentry ;
};
#line 910 "../tmux.h"
struct winlinks {
   struct winlink *rbh_root ;
};
#line 911 "../tmux.h"
struct winlink_stack {
   struct winlink *tqh_first ;
   struct winlink **tqh_last ;
};
#line 914
enum layout_type {
    LAYOUT_LEFTRIGHT = 0,
    LAYOUT_TOPBOTTOM = 1,
    LAYOUT_WINDOWPANE = 2
} ;
#line 921 "../tmux.h"
struct layout_cells {
   struct layout_cell *tqh_first ;
   struct layout_cell **tqh_last ;
};
#line 924 "../tmux.h"
struct __anonstruct_entry_40 {
   struct layout_cell *tqe_next ;
   struct layout_cell **tqe_prev ;
};
#line 924 "../tmux.h"
struct layout_cell {
   enum layout_type type ;
   struct layout_cell *parent ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 xoff ;
   u_int___0 yoff ;
   struct window_pane *wp ;
   struct layout_cells cells ;
   struct __anonstruct_entry_40 entry ;
};
#line 958
struct hooks;
#line 958 "../tmux.h"
struct __anonstruct_gentry_44 {
   struct session *tqe_next ;
   struct session **tqe_prev ;
};
#line 958 "../tmux.h"
struct __anonstruct_entry_45 {
   struct session *rbe_left ;
   struct session *rbe_right ;
   struct session *rbe_parent ;
   int rbe_color ;
};
#line 958 "../tmux.h"
struct session {
   u_int___0 id ;
   char *name ;
   char const   *cwd ;
   struct timeval creation_time ;
   struct timeval last_attached_time ;
   struct timeval activity_time ;
   struct timeval last_activity_time ;
   struct event lock_timer ;
   u_int___0 sx ;
   u_int___0 sy ;
   struct winlink *curw ;
   struct winlink_stack lastw ;
   struct winlinks windows ;
   int statusat ;
   struct hooks *hooks ;
   struct options *options ;
   int flags ;
   u_int___0 attached ;
   struct termios *tio ;
   struct environ *environ ;
   int references ;
   struct __anonstruct_gentry_44 gentry ;
   struct __anonstruct_entry_45 entry ;
};
#line 1020 "../tmux.h"
struct mouse_event {
   int valid ;
   key_code key ;
   int statusat ;
   u_int___0 x ;
   u_int___0 y ;
   u_int___0 b ;
   u_int___0 lx ;
   u_int___0 ly ;
   u_int___0 lb ;
   int s ;
   int w ;
   int wp ;
   u_int___0 sgr_type ;
   u_int___0 sgr_b ;
};
#line 1043 "../tmux.h"
struct tty_key {
   char ch ;
   key_code key ;
   struct tty_key *left ;
   struct tty_key *right ;
   struct tty_key *next ;
};
#line 1053
struct tty_code;
#line 1053
struct tty_code;
#line 1054 "../tmux.h"
struct __anonstruct_entry_46 {

};
#line 1054 "../tmux.h"
struct tty_term {
   char *name ;
   u_int___0 references ;
   char acs[11][2] ;
   struct tty_code *codes ;
   int flags ;
   struct __anonstruct_entry_46 entry ;
};
#line 1070
struct evbuffer;
#line 1070
enum __anonenum_term_type_47 {
    TTY_VT100 = 0,
    TTY_VT101 = 1,
    TTY_VT102 = 2,
    TTY_VT220 = 3,
    TTY_VT320 = 4,
    TTY_VT420 = 5,
    TTY_UNKNOWN = 6
} ;
#line 1070 "../tmux.h"
struct tty {
   struct client *client ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 cx ;
   u_int___0 cy ;
   u_int___0 cstyle ;
   char *ccolour ;
   int mode ;
   u_int___0 rlower ;
   u_int___0 rupper ;
   u_int___0 rleft ;
   u_int___0 rright ;
   int fd ;
   struct event event_in ;
   struct evbuffer *in ;
   struct event event_out ;
   struct evbuffer *out ;
   struct event timer ;
   size_t discarded ;
   struct termios tio ;
   struct grid_cell cell ;
   int last_wp ;
   struct grid_cell last_cell ;
   int flags ;
   struct tty_term *term ;
   char *term_name ;
   int term_flags ;
   enum __anonenum_term_type_47 term_type ;
   struct mouse_event mouse ;
   int mouse_drag_flag ;
   void (*mouse_drag_update)(struct client * , struct mouse_event * ) ;
   void (*mouse_drag_release)(struct client * , struct mouse_event * ) ;
   struct event key_timer ;
   struct tty_key *key_tree ;
};
#line 1169 "../tmux.h"
struct __anonstruct_entry_48 {
   struct message_entry *tqe_next ;
   struct message_entry **tqe_prev ;
};
#line 1169 "../tmux.h"
struct message_entry {
   char *msg ;
   u_int___0 msg_num ;
   time_t msg_time ;
   struct __anonstruct_entry_48 entry ;
};
#line 1177
struct args_entry;
#line 1177
struct args_entry;
#line 1178 "../tmux.h"
struct args_tree {
   struct args_entry *rbh_root ;
};
#line 1179 "../tmux.h"
struct args {
   struct args_tree tree ;
   int argc ;
   char **argv ;
};
#line 1191 "../tmux.h"
struct cmd_find_state {
   int flags ;
   struct cmd_find_state *current ;
   struct session *s ;
   struct winlink *wl ;
   struct window *w ;
   struct window_pane *wp ;
   int idx ;
};
#line 1212
struct cmd_entry;
#line 1212 "../tmux.h"
struct __anonstruct_qentry_49 {
   struct cmd *tqe_next ;
   struct cmd **tqe_prev ;
};
#line 1212 "../tmux.h"
struct cmd {
   struct cmd_entry  const  *entry ;
   struct args *args ;
   char *file ;
   u_int___0 line ;
   int flags ;
   struct __anonstruct_qentry_49 qentry ;
};
#line 1225 "../tmux.h"
struct __anonstruct_list_50 {
   struct cmd *tqh_first ;
   struct cmd **tqh_last ;
};
#line 1225 "../tmux.h"
struct cmd_list {
   int references ;
   struct __anonstruct_list_50 list ;
};
#line 1260
struct cmdq_item;
#line 1261 "../tmux.h"
struct cmdq_list {
   struct cmdq_item *tqh_first ;
   struct cmdq_item **tqh_last ;
};
#line 1271
struct cmd_entry;
#line 1276
struct key_table;
#line 1276 "../tmux.h"
struct __anonstruct_message_log_51 {
   struct message_entry *tqh_first ;
   struct message_entry **tqh_last ;
};
#line 1276
enum __anonenum_prompt_mode_52 {
    PROMPT_ENTRY = 0,
    PROMPT_COMMAND = 1
} ;
#line 1276 "../tmux.h"
struct __anonstruct_entry_53 {
   struct client *tqe_next ;
   struct client **tqe_prev ;
};
#line 1276 "../tmux.h"
struct client {
   char const   *name ;
   struct tmuxpeer *peer ;
   struct cmdq_list queue ;
   pid_t___0 pid ;
   int fd ;
   struct event event ;
   int retval ;
   struct timeval creation_time ;
   struct timeval activity_time ;
   struct environ *environ ;
   struct format_job_tree *jobs ;
   char *title ;
   char const   *cwd ;
   char *term ;
   char *ttyname ;
   struct tty tty ;
   size_t written ;
   size_t discarded ;
   size_t redraw ;
   void (*stdin_callback)(struct client * , int  , void * ) ;
   void *stdin_callback_data ;
   struct evbuffer *stdin_data ;
   int stdin_closed ;
   struct evbuffer *stdout_data ;
   struct evbuffer *stderr_data ;
   struct event repeat_timer ;
   struct event click_timer ;
   u_int___0 click_button ;
   struct event status_timer ;
   struct screen status ;
   struct screen *old_status ;
   int flags ;
   struct key_table *keytable ;
   struct event identify_timer ;
   void (*identify_callback)(struct client * , struct window_pane * ) ;
   void *identify_callback_data ;
   char *message_string ;
   struct event message_timer ;
   u_int___0 message_next ;
   struct __anonstruct_message_log_51 message_log ;
   char *prompt_string ;
   struct utf8_data *prompt_buffer ;
   size_t prompt_index ;
   int (*prompt_inputcb)(struct client * , void * , char const   * , int  ) ;
   void (*prompt_freecb)(void * ) ;
   void *prompt_data ;
   u_int___0 prompt_hindex ;
   enum __anonenum_prompt_mode_52 prompt_mode ;
   int prompt_flags ;
   struct session *session ;
   struct session *last_session ;
   int wlmouse ;
   int references ;
   struct __anonstruct_entry_53 entry ;
};
#line 1384 "../tmux.h"
struct __anonstruct_entry_54 {
   struct key_binding *rbe_left ;
   struct key_binding *rbe_right ;
   struct key_binding *rbe_parent ;
   int rbe_color ;
};
#line 1384 "../tmux.h"
struct key_binding {
   key_code key ;
   struct cmd_list *cmdlist ;
   int flags ;
   struct __anonstruct_entry_54 entry ;
};
#line 1393 "../tmux.h"
struct key_bindings {
   struct key_binding *rbh_root ;
};
#line 1395 "../tmux.h"
struct __anonstruct_entry_55 {
   struct key_table *rbe_left ;
   struct key_table *rbe_right ;
   struct key_table *rbe_parent ;
   int rbe_color ;
};
#line 1395 "../tmux.h"
struct key_table {
   char const   *name ;
   struct key_bindings key_bindings ;
   u_int___0 references ;
   struct __anonstruct_entry_55 entry ;
};
#line 1510
struct format_tree;
#line 13 "tmux_leak_1.c"
struct format_entry;
#line 13 "tmux_leak_1.c"
struct format_entry_tree {
   struct format_entry *rbh_root ;
};
#line 13 "tmux_leak_1.c"
struct format_tree {
   struct window *w ;
   struct winlink *wl ;
   struct session *s ;
   struct window_pane *wp ;
   struct client *client ;
   u_int___0 tag ;
   int flags ;
   struct format_entry_tree tree ;
};
#line 362 "/usr/include/stdio.h"
extern int printf(char const   * __restrict  __format  , ...) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 1934 "../tmux.h"
int grid_compare(struct grid *ga , struct grid *gb ) ;
#line 91 "tmux_leak_1.c"
extern int ( /* missing proto */  vasprintf)() ;
#line 86 "tmux_leak_1.c"
int xvasprintf(char **ret , char const   *fmt , char *ap ) 
{ 
  int i ;

  {
#line 91
  i = vasprintf(ret, fmt, ap);
#line 93
  if (i < 0) {
#line 94
    printf((char const   * __restrict  )"xasprintf: %s", "");
#line 94
    exit(1);
  } else
#line 93
  if ((unsigned long )*ret == (unsigned long )((void *)0)) {
#line 94
    printf((char const   * __restrict  )"xasprintf: %s", "");
#line 94
    exit(1);
  }
#line 96
  return (i);
}
}
#line 111
extern int ( /* missing proto */  memcpy)() ;
#line 119
extern int ( /* missing proto */  strcspn)() ;
#line 133
extern int ( /* missing proto */  strlen)() ;
#line 100 "tmux_leak_1.c"
void screen_write_cnputs(struct screen_write_ctx *ctx , ssize_t maxlen , struct grid_cell  const  *gcp ,
                         char const   *fmt , char *ap ) 
{ 
  struct grid_cell gc ;
  struct utf8_data *ud ;
  char *msg ;
  u_char___0 *ptr ;
  u_char___0 *last ;
  size_t left ;
  size_t size ;
  enum utf8_state more ;
  int tmp ;
  int tmp___0 ;

  {
#line 105
  ud = & gc.data;
#line 108
  size = (size_t )0;
#line 111
  memcpy(& gc, gcp, sizeof(gc));
#line 113
  xvasprintf(& msg, fmt, ap);
#line 115
  ptr = (u_char___0 *)msg;
#line 116
  while ((int )*ptr != 0) {
#line 117
    if ((int )*(ptr + 0) == 35) {
#line 117
      if ((int )*(ptr + 1) == 91) {
#line 118
        ptr += 2;
#line 119
        tmp = strcspn(ptr, "]");
#line 119
        last = ptr + tmp;
#line 120
        if ((int )*last == 0) {
#line 122
          break;
        }
#line 124
        *last = (u_char___0 )'\000';
#line 126
        ptr = last + 1;
#line 127
        continue;
      }
    }
#line 130
    if ((int )*ptr > 127) {
#line 131
      ptr ++;
#line 133
      tmp___0 = strlen(ptr);
#line 133
      left = (size_t )tmp___0;
#line 134
      if (left < (size_t )ud->size - 1UL) {
#line 135
        break;
      }
#line 136
      ptr ++;
#line 138
      if ((unsigned int )more != 1U) {
#line 139
        continue;
      }
#line 140
      if (maxlen > 0L) {
#line 140
        if (size + (size_t )ud->width > (size_t )maxlen) {
#line 141
          while (size < (size_t )maxlen) {
#line 142
            size ++;
          }
#line 144
          break;
        }
      }
#line 146
      size += (size_t )ud->width;
    } else {
#line 148
      if (maxlen > 0L) {
#line 148
        if (size + 1UL > (size_t )maxlen) {
#line 149
          break;
        }
      }
#line 151
      if ((int )*ptr > 31) {
#line 151
        if ((int )*ptr < 127) {
#line 152
          size ++;
        }
      }
#line 154
      ptr ++;
    }
  }
#line 158
  free((void *)msg);
#line 159
  return;
}
}
#line 162 "tmux_leak_1.c"
size_t screen_write_cstrlen(char const   *fmt , char *ap ) 
{ 
  char *msg ;
  char *msg2 ;
  char *ptr ;
  char *ptr2 ;
  size_t size ;
  int tmp ;
  void *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;

  {
#line 168
  xvasprintf(& msg, fmt, ap);
#line 169
  tmp = strlen(msg);
#line 169
  tmp___0 = malloc((size_t )(tmp + 1));
#line 169
  msg2 = (char *)tmp___0;
#line 171
  ptr = msg;
#line 172
  ptr2 = msg2;
#line 173
  while ((int )*ptr != 0) {
#line 174
    if ((int )*(ptr + 0) == 35) {
#line 174
      if ((int )*(ptr + 1) == 91) {
#line 175
        while (1) {
#line 175
          if ((int )*ptr != 93) {
#line 175
            if (! ((int )*ptr != 0)) {
#line 175
              break;
            }
          } else {
#line 175
            break;
          }
#line 176
          ptr ++;
        }
#line 177
        if ((int )*ptr == 93) {
#line 178
          ptr ++;
        }
#line 179
        continue;
      }
    }
#line 181
    tmp___1 = ptr2;
#line 181
    ptr2 ++;
#line 181
    tmp___2 = ptr;
#line 181
    ptr ++;
#line 181
    *tmp___1 = *tmp___2;
  }
#line 183
  *ptr2 = (char )'\000';
#line 185
  free((void *)msg);
#line 186
  free((void *)msg2);
#line 188
  return (size);
}
}
#line 192 "tmux_leak_1.c"
int grid_compare(struct grid *ga , struct grid *gb ) 
{ 


  {
#line 199
  if (ga->sx != gb->sx) {
#line 200
    return (1);
  } else
#line 199
  if (ga->sy != gb->sy) {
#line 200
    return (1);
  }
#line 202
  return (0);
}
}
#line 206 "tmux_leak_1.c"
static int screen_redraw_make_pane_status(struct client *c , struct window *w , struct window_pane *wp ) 
{ 
  struct grid_cell gc ;
  char const   *fmt ;
  char *out ;
  size_t outlen ;
  struct screen_write_ctx ctx ;
  struct screen old ;
  int tmp ;
  void *tmp___0 ;
  int tmp___1 ;

  {
#line 218
  memcpy(& old, & wp->status_screen, sizeof(old));
#line 219
  wp->status_screen.mode = 0;
#line 221
  tmp = strlen(fmt);
#line 221
  tmp___0 = malloc((size_t )tmp);
#line 221
  out = (char *)tmp___0;
#line 222
  outlen = screen_write_cstrlen("%s", out);
#line 224
  screen_write_cnputs(& ctx, (ssize_t )outlen, (struct grid_cell  const  *)(& gc),
                      "%s", out);
#line 226
  tmp___1 = grid_compare(wp->status_screen.grid, old.grid);
#line 226
  if (tmp___1 == 0) {
#line 227
    return (0);
  }
#line 229
  return (1);
}
}
#line 232 "tmux_leak_1.c"
int main(void) 
{ 
  struct client c ;
  struct window w ;
  struct window_pane wp ;

  {
#line 237
  screen_redraw_make_pane_status(& c, & w, & wp);
#line 238
  return (0);
}
}
