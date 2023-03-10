/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

#line 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h"
typedef unsigned long size_t;
#line 131 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off_t;
#line 132 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __off64_t;
#line 139 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __time_t;
#line 141 "/usr/include/x86_64-linux-gnu/bits/types.h"
typedef long __suseconds_t;
#line 44 "/usr/include/stdio.h"
struct _IO_FILE;
#line 44
struct _IO_FILE;
#line 48 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;
#line 144 "/usr/include/libio.h"
struct _IO_FILE;
#line 150 "/usr/include/libio.h"
typedef void _IO_lock_t;
#line 156 "/usr/include/libio.h"
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
#line 241 "/usr/include/libio.h"
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
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
#line 242 "../stdio.h"
struct passwd {
   char *pw_name ;
   char *pw_passwd ;
   int pw_uid ;
   int pw_gid ;
   int pw_change ;
   char *pw_class ;
   char *pw_gecos ;
   char *pw_dir ;
   char *pw_shell ;
   int pw_expire ;
};
#line 39 "../tmux.h"
typedef char bitstr_t;
#line 41 "../tmux.h"
struct event {

};
#line 42 "../tmux.h"
struct termios {

};
#line 48
struct args;
#line 48
struct args;
#line 49
struct client;
#line 49
struct client;
#line 50
struct cmd_find_state;
#line 50
struct cmd_find_state;
#line 51
struct cmdq_item;
#line 51
struct cmdq_item;
#line 52
struct cmdq_list;
#line 52
struct cmdq_list;
#line 53
struct environ;
#line 53
struct environ;
#line 54
struct format_job_tree;
#line 54
struct format_job_tree;
#line 55
struct input_ctx;
#line 55
struct input_ctx;
#line 57
struct mouse_event;
#line 57
struct mouse_event;
#line 58
struct options;
#line 58
struct options;
#line 59
struct options_entry;
#line 59
struct options_entry;
#line 60
struct session;
#line 60
struct session;
#line 61
struct tmuxpeer;
#line 61
struct tmuxpeer;
#line 138 "../tmux.h"
typedef unsigned long long key_code;
#line 469 "../tmux.h"
struct options_tree {
   struct options_entry *rbh_root ;
};
#line 469 "../tmux.h"
struct options {
   struct options_tree tree ;
   struct options *parent ;
};
#line 486 "../tmux.h"
struct msg_command_data {
   int argc ;
};
#line 532 "../tmux.h"
struct utf8_data {
   u_char___0 data[9] ;
   u_char___0 have ;
   u_char___0 size ;
   u_char___0 width ;
};
#line 574 "../tmux.h"
struct grid_cell {
   u_char___0 flags ;
   u_short___0 attr ;
   int fg ;
   int bg ;
   struct utf8_data data ;
};
#line 581 "../tmux.h"
struct __anonstruct_data_27 {
   u_char___0 attr ;
   u_char___0 fg ;
   u_char___0 bg ;
   u_char___0 data ;
};
#line 581 "../tmux.h"
union __anonunion____missing_field_name_26 {
   u_int___0 offset ;
   struct __anonstruct_data_27 data ;
};
#line 581 "../tmux.h"
struct grid_cell_entry {
   u_char___0 flags ;
   union __anonunion____missing_field_name_26 __annonCompField1 ;
};
#line 595 "../tmux.h"
struct grid_line {
   u_int___0 cellused ;
   u_int___0 cellsize ;
   struct grid_cell_entry *celldata ;
   u_int___0 extdsize ;
   struct grid_cell *extddata ;
   int flags ;
};
#line 607 "../tmux.h"
struct grid {
   int flags ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 hscrolled ;
   u_int___0 hsize ;
   u_int___0 hlimit ;
   struct grid_line *linedata ;
};
#line 622
struct cmd_list;
#line 635
struct bufferevent;
#line 660
enum __anonenum_lineflag_31 {
    LINE_SEL_NONE = 0,
    LINE_SEL_LEFT_RIGHT = 1,
    LINE_SEL_RIGHT_LEFT = 2
} ;
#line 660 "../tmux.h"
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
#line 683
struct screen_titles;
#line 683
struct screen_titles;
#line 684 "../tmux.h"
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
#line 709
struct window_pane;
#line 733 "../tmux.h"
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
#line 751
struct winlink;
#line 773
struct window;
#line 773
struct layout_cell;
#line 773 "../tmux.h"
struct __anonstruct_entry_32 {
   struct window_pane *tqe_next ;
   struct window_pane **tqe_prev ;
};
#line 773 "../tmux.h"
struct __anonstruct_tree_entry_33 {
   struct window_pane *rbe_left ;
   struct window_pane *rbe_right ;
   struct window_pane *rbe_parent ;
   int rbe_color ;
};
#line 773 "../tmux.h"
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
#line 850 "../tmux.h"
struct window_panes {
   struct window_pane *tqh_first ;
   struct window_pane **tqh_last ;
};
#line 854 "../tmux.h"
struct __anonstruct_alerts_entry_34 {
   struct window *tqe_next ;
   struct window **tqe_prev ;
};
#line 854 "../tmux.h"
struct __anonstruct_winlinks_35 {
   struct winlink *tqh_first ;
   struct winlink **tqh_last ;
};
#line 854 "../tmux.h"
struct __anonstruct_entry_36 {
   struct window *rbe_left ;
   struct window *rbe_right ;
   struct window *rbe_parent ;
   int rbe_color ;
};
#line 854 "../tmux.h"
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
#line 904 "../tmux.h"
struct __anonstruct_entry_37 {
   struct winlink *rbe_left ;
   struct winlink *rbe_right ;
   struct winlink *rbe_parent ;
   int rbe_color ;
};
#line 904 "../tmux.h"
struct __anonstruct_wentry_38 {
   struct winlink *tqe_next ;
   struct winlink **tqe_prev ;
};
#line 904 "../tmux.h"
struct __anonstruct_sentry_39 {
   struct winlink *tqe_next ;
   struct winlink **tqe_prev ;
};
#line 904 "../tmux.h"
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
#line 923 "../tmux.h"
struct winlinks {
   struct winlink *rbh_root ;
};
#line 924 "../tmux.h"
struct winlink_stack {
   struct winlink *tqh_first ;
   struct winlink **tqh_last ;
};
#line 927
enum layout_type {
    LAYOUT_LEFTRIGHT = 0,
    LAYOUT_TOPBOTTOM = 1,
    LAYOUT_WINDOWPANE = 2
} ;
#line 934 "../tmux.h"
struct layout_cells {
   struct layout_cell *tqh_first ;
   struct layout_cell **tqh_last ;
};
#line 937 "../tmux.h"
struct __anonstruct_entry_40 {
   struct layout_cell *tqe_next ;
   struct layout_cell **tqe_prev ;
};
#line 937 "../tmux.h"
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
#line 955 "../tmux.h"
struct __anonstruct_entry_41 {
   struct environ_entry *rbe_left ;
   struct environ_entry *rbe_right ;
   struct environ_entry *rbe_parent ;
   int rbe_color ;
};
#line 955 "../tmux.h"
struct environ_entry {
   char *name ;
   char *value ;
   struct __anonstruct_entry_41 entry ;
};
#line 971
struct hooks;
#line 971 "../tmux.h"
struct __anonstruct_gentry_44 {
   struct session *tqe_next ;
   struct session **tqe_prev ;
};
#line 971 "../tmux.h"
struct __anonstruct_entry_45 {
   struct session *rbe_left ;
   struct session *rbe_right ;
   struct session *rbe_parent ;
   int rbe_color ;
};
#line 971 "../tmux.h"
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
#line 1033 "../tmux.h"
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
#line 1056 "../tmux.h"
struct tty_key {
   char ch ;
   key_code key ;
   struct tty_key *left ;
   struct tty_key *right ;
   struct tty_key *next ;
};
#line 1066
struct tty_code;
#line 1066
struct tty_code;
#line 1067 "../tmux.h"
struct __anonstruct_entry_46 {

};
#line 1067 "../tmux.h"
struct tty_term {
   char *name ;
   u_int___0 references ;
   char acs[11][2] ;
   struct tty_code *codes ;
   int flags ;
   struct __anonstruct_entry_46 entry ;
};
#line 1083
struct evbuffer;
#line 1083
enum __anonenum_term_type_47 {
    TTY_VT100 = 0,
    TTY_VT101 = 1,
    TTY_VT102 = 2,
    TTY_VT220 = 3,
    TTY_VT320 = 4,
    TTY_VT420 = 5,
    TTY_UNKNOWN = 6
} ;
#line 1083 "../tmux.h"
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
#line 1182 "../tmux.h"
struct __anonstruct_entry_48 {
   struct message_entry *tqe_next ;
   struct message_entry **tqe_prev ;
};
#line 1182 "../tmux.h"
struct message_entry {
   char *msg ;
   u_int___0 msg_num ;
   time_t msg_time ;
   struct __anonstruct_entry_48 entry ;
};
#line 1191 "../tmux.h"
struct __anonstruct_entry_49 {
   struct args_entry *rbe_left ;
   struct args_entry *rbe_right ;
   struct args_entry *rbe_parent ;
   int rbe_color ;
};
#line 1191 "../tmux.h"
struct args_entry {
   u_char___0 flag ;
   char *value ;
   struct __anonstruct_entry_49 entry ;
};
#line 1197 "../tmux.h"
struct args_tree {
   struct args_entry *rbh_root ;
};
#line 1198 "../tmux.h"
struct args {
   struct args_tree tree ;
   int argc ;
   char **argv ;
};
#line 1210 "../tmux.h"
struct cmd_find_state {
   int flags ;
   struct cmd_find_state *current ;
   struct session *s ;
   struct winlink *wl ;
   struct window *w ;
   struct window_pane *wp ;
   int idx ;
};
#line 1231
struct cmd_entry;
#line 1231 "../tmux.h"
struct __anonstruct_qentry_50 {
   struct cmd *tqe_next ;
   struct cmd **tqe_prev ;
};
#line 1231 "../tmux.h"
struct cmd {
   struct cmd_entry  const  *entry ;
   struct args *args ;
   char *file ;
   u_int___0 line ;
   int flags ;
   struct __anonstruct_qentry_50 qentry ;
};
#line 1244 "../tmux.h"
struct __anonstruct_list_51 {
   struct cmd *tqh_first ;
   struct cmd **tqh_last ;
};
#line 1244 "../tmux.h"
struct cmd_list {
   int references ;
   struct __anonstruct_list_51 list ;
};
#line 1250
enum cmd_retval {
    CMD_RETURN_ERROR = -1,
    CMD_RETURN_NORMAL = 0,
    CMD_RETURN_WAIT = 1,
    CMD_RETURN_STOP = 2
} ;
#line 1279
struct cmdq_item;
#line 1280 "../tmux.h"
struct cmdq_list {
   struct cmdq_item *tqh_first ;
   struct cmdq_item **tqh_last ;
};
#line 1290
struct cmd_entry;
#line 1295
struct key_table;
#line 1295 "../tmux.h"
struct __anonstruct_message_log_52 {
   struct message_entry *tqh_first ;
   struct message_entry **tqh_last ;
};
#line 1295
enum __anonenum_prompt_mode_53 {
    PROMPT_ENTRY = 0,
    PROMPT_COMMAND = 1
} ;
#line 1295
struct cmd_q;
#line 1295 "../tmux.h"
struct __anonstruct_entry_54 {
   struct client *tqe_next ;
   struct client **tqe_prev ;
};
#line 1295 "../tmux.h"
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
   struct __anonstruct_message_log_52 message_log ;
   char *prompt_string ;
   struct utf8_data *prompt_buffer ;
   size_t prompt_index ;
   int (*prompt_inputcb)(struct client * , void * , char const   * , int  ) ;
   void (*prompt_freecb)(void * ) ;
   void *prompt_data ;
   u_int___0 prompt_hindex ;
   enum __anonenum_prompt_mode_53 prompt_mode ;
   int prompt_flags ;
   struct session *session ;
   struct session *last_session ;
   int wlmouse ;
   int references ;
   struct cmd_q *cmdq ;
   struct __anonstruct_entry_54 entry ;
};
#line 1405 "../tmux.h"
struct __anonstruct_entry_55 {
   struct key_binding *rbe_left ;
   struct key_binding *rbe_right ;
   struct key_binding *rbe_parent ;
   int rbe_color ;
};
#line 1405 "../tmux.h"
struct key_binding {
   key_code key ;
   struct cmd_list *cmdlist ;
   int flags ;
   struct __anonstruct_entry_55 entry ;
};
#line 1414 "../tmux.h"
struct key_bindings {
   struct key_binding *rbh_root ;
};
#line 1416 "../tmux.h"
struct __anonstruct_entry_56 {
   struct key_table *rbe_left ;
   struct key_table *rbe_right ;
   struct key_table *rbe_parent ;
   int rbe_color ;
};
#line 1416 "../tmux.h"
struct key_table {
   char const   *name ;
   struct key_bindings key_bindings ;
   u_int___0 references ;
   struct __anonstruct_entry_56 entry ;
};
#line 16 "tmux_leak_10.c"
struct cmd_ctx {
   struct client *curclient ;
   struct client *cmdclient ;
   struct msg_command_data *msgdata ;
   void (*print)(struct cmd_ctx * , char const   *  , ...) ;
   void (*info)(struct cmd_ctx * , char const   *  , ...) ;
   void (*error)(struct cmd_ctx * , char const   *  , ...) ;
};
#line 40 "tmux_leak_10.c"
struct causelist {
   char **list ;
   u_int___0 num ;
   size_t space ;
};
#line 237 "/usr/include/stdio.h"
extern int fclose(FILE *__stream ) ;
#line 272
extern FILE *fopen(char const   * __restrict  __filename , char const   * __restrict  __modes ) ;
#line 362
extern int printf(char const   * __restrict  __format  , ...) ;
#line 622
extern char *fgets(char * __restrict  __s , int __n , FILE * __restrict  __stream ) ;
#line 466 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
#line 480
extern  __attribute__((__nothrow__)) void *( __attribute__((__warn_unused_result__,
__leaf__)) realloc)(void *__ptr , size_t __size ) ;
#line 483
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 543
extern  __attribute__((__nothrow__, __noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
#line 42 "tmux_leak_10.c"
char *cfg_cause  ;
#line 43 "tmux_leak_10.c"
int cfg_finished  ;
#line 44 "tmux_leak_10.c"
int cfg_references  ;
#line 45 "tmux_leak_10.c"
struct causelist cfg_causes  ;
#line 47 "tmux_leak_10.c"
void *xrealloc(void *oldptr , size_t nmemb , size_t size ) 
{ 
  size_t newsize ;
  void *newptr ;

  {
#line 50
  newsize = nmemb * size;
#line 53
  if (newsize == 0UL) {
#line 54
    printf((char const   * __restrict  )"zero size%s", "");
#line 54
    exit(1);
  }
#line 55
  if ((size_t )(1 << 30UL / nmemb) < size) {
#line 56
    printf((char const   * __restrict  )"nmemb * size > SIZE_MAX%s", "");
#line 56
    exit(1);
  }
#line 57
  newptr = realloc(oldptr, newsize);
#line 57
  if ((unsigned long )newptr == (unsigned long )((void *)0)) {
#line 58
    printf((char const   * __restrict  )"xrealloc failed%s", "");
#line 58
    exit(1);
  }
#line 60
  return (newptr);
}
}
#line 63 "tmux_leak_10.c"
int cmd_string_getc(char const   *s , size_t *p ) 
{ 
  u_char___0 const   *ucs ;
  size_t tmp ;

  {
#line 66
  ucs = (u_char___0 const   *)s;
#line 68
  if ((int const   )*(ucs + *p) == 0) {
#line 69
    return (-1);
  }
#line 70
  tmp = *p;
#line 70
  (*p) ++;
#line 70
  return ((int )*(ucs + tmp));
}
}
#line 73 "tmux_leak_10.c"
void cmd_string_ungetc(size_t *p ) 
{ 


  {
#line 76
  (*p) --;
#line 77
  return;
}
}
#line 138
extern int ( /* missing proto */  strdup)() ;
#line 79 "tmux_leak_10.c"
char *cmd_string_variable(char const   *s , size_t *p ) 
{ 
  int ch ;
  int fch ;
  char *buf ;
  char *t ;
  size_t len ;
  struct environ_entry *envent ;
  void *tmp ;
  size_t tmp___0 ;
  void *tmp___1 ;
  size_t tmp___2 ;
  void *tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;

  {
#line 93
  buf = (char *)((void *)0);
#line 94
  len = (size_t )0;
#line 96
  fch = -1;
#line 97
  ch = cmd_string_getc(s, p);
#line 97
  switch (ch) {
  case -1: 
#line 99
  goto error;
  case 123: 
#line 101
  fch = '{';
#line 103
  ch = cmd_string_getc(s, p);
#line 104
  if (! (ch == 95)) {
#line 104
    if (ch >= 97) {
#line 104
      if (! (ch <= 122)) {
#line 104
        goto _L;
      }
    } else
    _L: /* CIL Label */ 
#line 104
    if (ch >= 65) {
#line 104
      if (! (ch <= 90)) {
#line 105
        goto error;
      }
    } else {
#line 105
      goto error;
    }
  }
  default: 
#line 108
  if (! (ch == 95)) {
#line 108
    if (ch >= 97) {
#line 108
      if (! (ch <= 122)) {
#line 108
        goto _L___0;
      }
    } else
    _L___0: /* CIL Label */ 
#line 108
    if (ch >= 65) {
#line 108
      if (! (ch <= 90)) {
#line 109
        return (t);
      }
    } else {
#line 109
      return (t);
    }
  }
#line 112
  tmp = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 112
  buf = (char *)tmp;
#line 113
  tmp___0 = len;
#line 113
  len ++;
#line 113
  *(buf + tmp___0) = (char )ch;
#line 115
  while (1) {
#line 116
    ch = cmd_string_getc(s, p);
#line 117
    if (ch == -1) {
#line 118
      break;
    } else
#line 117
    if (ch == 95) {
#line 117
      goto _L___1;
    } else
#line 117
    if (ch >= 97) {
#line 117
      if (ch <= 122) {
#line 117
        goto _L___1;
      } else {
#line 117
        goto _L___3;
      }
    } else
    _L___3: /* CIL Label */ 
#line 117
    if (ch >= 65) {
#line 117
      if (ch <= 90) {
#line 117
        goto _L___1;
      } else {
#line 117
        goto _L___2;
      }
    } else
    _L___2: /* CIL Label */ 
#line 117
    if (ch >= 48) {
#line 117
      if (ch <= 57) {
        _L___1: /* CIL Label */ 
#line 120
        if (len >= (size_t )((1 << 30) - 3)) {
#line 121
          goto error;
        }
#line 122
        tmp___1 = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 122
        buf = (char *)tmp___1;
#line 123
        tmp___2 = len;
#line 123
        len ++;
#line 123
        *(buf + tmp___2) = (char )ch;
      } else {
#line 118
        break;
      }
    } else {
#line 118
      break;
    }
  }
  }
#line 128
  if (fch == 123) {
#line 128
    if (ch != 125) {
#line 129
      goto error;
    }
  }
#line 130
  if (ch != -1) {
#line 130
    if (fch != 123) {
#line 131
      cmd_string_ungetc(p);
    }
  }
#line 133
  tmp___3 = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 133
  buf = (char *)tmp___3;
#line 134
  *(buf + len) = (char )'\000';
#line 136
  free((void *)buf);
#line 137
  if ((unsigned long )envent == (unsigned long )((void *)0)) {
#line 138
    tmp___4 = strdup("");
#line 138
    return ((char *)tmp___4);
  }
#line 139
  tmp___5 = strdup(envent->value);
#line 139
  return ((char *)tmp___5);
  error: 
#line 142
  free((void *)buf);
#line 143
  return ((char *)((void *)0));
}
}
#line 146 "tmux_leak_10.c"
char *cmd_string_string(char const   *s , size_t *p , char endch , int esc ) 
{ 
  int ch ;
  char *buf ;
  char *t ;
  size_t len ;
  void *tmp ;
  size_t tmp___0 ;
  void *tmp___1 ;

  {
#line 153
  buf = (char *)((void *)0);
#line 154
  len = (size_t )0;
#line 156
  while (1) {
#line 156
    ch = cmd_string_getc(s, p);
#line 156
    if (! (ch != (int )endch)) {
#line 156
      break;
    }
#line 157
    switch (ch) {
    case -1: 
#line 159
    goto error;
    case 92: 
#line 161
    if (! esc) {
#line 162
      break;
    }
#line 163
    ch = cmd_string_getc(s, p);
#line 163
    switch (ch) {
    case -1: 
#line 165
    goto error;
    case 101: 
#line 167
    ch = '\033';
#line 168
    break;
    case 114: 
#line 170
    ch = '\r';
#line 171
    break;
    case 110: 
#line 173
    ch = '\n';
#line 174
    break;
    case 116: 
#line 176
    ch = '\t';
#line 177
    break;
    }
#line 179
    break;
    case 36: 
#line 181
    if (! esc) {
#line 182
      break;
    }
#line 183
    t = cmd_string_variable(s, p);
#line 183
    if ((unsigned long )t == (unsigned long )((void *)0)) {
#line 184
      goto error;
    }
#line 185
    continue;
    }
#line 188
    if (len >= (size_t )((1 << 30) - 2)) {
#line 189
      goto error;
    }
#line 190
    tmp = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 190
    buf = (char *)tmp;
#line 191
    tmp___0 = len;
#line 191
    len ++;
#line 191
    *(buf + tmp___0) = (char )ch;
  }
#line 194
  tmp___1 = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 194
  buf = (char *)tmp___1;
#line 195
  *(buf + len) = (char )'\000';
#line 196
  return (buf);
  error: 
#line 199
  free((void *)buf);
#line 200
  return ((char *)((void *)0));
}
}
#line 214
extern int ( /* missing proto */  getpwuid)() ;
#line 214
extern int ( /* missing proto */  getuid)() ;
#line 220
extern int ( /* missing proto */  getpwnam)() ;
#line 203 "tmux_leak_10.c"
char *cmd_string_expand_tilde(char const   *s , size_t *p ) 
{ 
  struct passwd *pw ;
  struct environ_entry *envent ;
  char *home ;
  char *username ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;

  {
#line 210
  home = (char *)((void *)0);
#line 211
  tmp___2 = cmd_string_getc(s, p);
#line 211
  if (tmp___2 == 47) {
#line 212
    if ((unsigned long )envent != (unsigned long )((void *)0)) {
#line 212
      if ((int )*(envent->value) != 0) {
#line 213
        home = envent->value;
      } else {
#line 212
        goto _L;
      }
    } else {
      _L: /* CIL Label */ 
#line 214
      tmp = getuid();
#line 214
      tmp___0 = getpwuid(tmp);
#line 214
      pw = (struct passwd *)tmp___0;
#line 214
      if ((unsigned long )pw != (unsigned long )((void *)0)) {
#line 215
        home = pw->pw_dir;
      }
    }
  } else {
#line 217
    cmd_string_ungetc(p);
#line 218
    username = cmd_string_string(s, p, (char )'/', 0);
#line 218
    if ((unsigned long )username == (unsigned long )((void *)0)) {
#line 219
      return ((char *)((void *)0));
    }
#line 220
    tmp___1 = getpwnam(username);
#line 220
    pw = (struct passwd *)tmp___1;
#line 220
    if ((unsigned long )pw != (unsigned long )((void *)0)) {
#line 221
      home = pw->pw_dir;
    }
#line 222
    free((void *)username);
  }
#line 224
  if ((unsigned long )home == (unsigned long )((void *)0)) {
#line 225
    return ((char *)((void *)0));
  }
#line 227
  tmp___3 = strdup(home);
#line 227
  return ((char *)tmp___3);
}
}
#line 292
extern int ( /* missing proto */  strchr)() ;
#line 293
extern int ( /* missing proto */  strcspn)() ;
#line 297
extern int ( /* missing proto */  memmove)() ;
#line 233 "tmux_leak_10.c"
int cmd_string_parse(char const   *s , struct cmd_list **cmdlist , char **cause ) 
{ 
  size_t p ;
  int ch ;
  int i ;
  int argc ;
  int rval ;
  char **argv ;
  char *buf ;
  char *t ;
  char const   *whitespace ;
  char const   *equals ;
  size_t len ;
  void *tmp ;
  void *tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  void *tmp___4 ;
  size_t tmp___5 ;

  {
#line 242
  argv = (char **)((void *)0);
#line 243
  argc = 0;
#line 245
  buf = (char *)((void *)0);
#line 246
  len = (size_t )0;
#line 248
  *cause = (char *)((void *)0);
#line 250
  *cmdlist = (struct cmd_list *)((void *)0);
#line 251
  rval = -1;
#line 253
  p = (size_t )0;
#line 254
  while (1) {
#line 255
    ch = cmd_string_getc(s, & p);
#line 256
    switch (ch) {
    case 39: 
#line 258
    t = cmd_string_string(s, & p, (char )'\'', 0);
#line 258
    if ((unsigned long )t == (unsigned long )((void *)0)) {
#line 259
      goto error;
    }
#line 260
    break;
    case 34: 
#line 262
    t = cmd_string_string(s, & p, (char )'\"', 1);
#line 262
    if ((unsigned long )t == (unsigned long )((void *)0)) {
#line 263
      goto error;
    }
#line 264
    break;
    case 36: 
#line 266
    t = cmd_string_variable(s, & p);
#line 266
    if ((unsigned long )t == (unsigned long )((void *)0)) {
#line 267
      goto error;
    }
#line 268
    break;
    case 35: 
#line 271
    while (1) {
#line 271
      ch = cmd_string_getc(s, & p);
#line 271
      if (! (ch != -1)) {
#line 271
        break;
      }
    }
    case 9: 
    case 32: 
    case -1: 
#line 277
    if ((unsigned long )buf != (unsigned long )((void *)0)) {
#line 278
      tmp = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 278
      buf = (char *)tmp;
#line 279
      *(buf + len) = (char )'\000';
#line 281
      tmp___0 = xrealloc((void *)argv, (size_t )(argc + 1), sizeof(*argv));
#line 281
      argv = (char **)tmp___0;
#line 282
      tmp___1 = argc;
#line 282
      argc ++;
#line 282
      *(argv + tmp___1) = buf;
#line 284
      buf = (char *)((void *)0);
#line 285
      len = (size_t )0;
    }
#line 288
    if (ch != -1) {
#line 289
      break;
    }
#line 291
    while (argc != 0) {
#line 292
      tmp___2 = strchr(*(argv + 0), '=');
#line 292
      equals = (char const   *)tmp___2;
#line 293
      tmp___3 = strcspn(*(argv + 0), " \t");
#line 293
      whitespace = (char const   *)(*(argv + 0) + tmp___3);
#line 294
      if ((unsigned long )equals == (unsigned long )((void *)0)) {
#line 295
        break;
      } else
#line 294
      if ((unsigned long )equals > (unsigned long )whitespace) {
#line 295
        break;
      }
#line 296
      argc --;
#line 297
      memmove(argv, argv + 1, (unsigned long )argc * sizeof(*argv));
    }
#line 299
    if (argc == 0) {
#line 300
      goto error;
    }
#line 302
    if ((unsigned long )*cmdlist == (unsigned long )((void *)0)) {
#line 303
      goto error;
    }
#line 305
    rval = 0;
#line 306
    goto error;
    case 126: 
#line 308
    if ((unsigned long )buf == (unsigned long )((void *)0)) {
#line 309
      t = cmd_string_expand_tilde(s, & p);
#line 310
      if ((unsigned long )t == (unsigned long )((void *)0)) {
#line 311
        goto error;
      }
#line 312
      break;
    }
    default: 
#line 316
    if (len >= (size_t )((1 << 30) - 2)) {
#line 317
      goto error;
    }
#line 319
    tmp___4 = xrealloc((void *)buf, (size_t )1, len + 1UL);
#line 319
    buf = (char *)tmp___4;
#line 320
    tmp___5 = len;
#line 320
    len ++;
#line 320
    *(buf + tmp___5) = (char )ch;
#line 321
    break;
    }
  }
  error: 
#line 327
  free((void *)buf);
#line 329
  if ((unsigned long )argv != (unsigned long )((void *)0)) {
#line 330
    i = 0;
#line 330
    while (i < argc) {
#line 331
      free((void *)*(argv + i));
#line 330
      i ++;
    }
#line 332
    free((void *)argv);
  }
#line 335
  return (rval);
}
}
#line 371
extern int ( /* missing proto */  strlen)() ;
#line 379
extern int ( /* missing proto */  memcpy)() ;
#line 397
extern int ( /* missing proto */  isspace)() ;
#line 343 "tmux_leak_10.c"
enum cmd_retval load_cfg(char const   *path , struct cmd_ctx *ctxin , struct causelist *causes ) 
{ 
  FILE *f ;
  u_int___0 n ;
  char *buf ;
  char *copy ;
  char *line ;
  char *cause ;
  size_t len ;
  size_t oldlen ;
  struct cmd_list *cmdlist ;
  struct cmd_ctx ctx ;
  enum cmd_retval retval ;
  int tmp ;
  void *tmp___0 ;
  void *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;

  {
#line 354
  f = fopen((char const   * __restrict  )path, (char const   * __restrict  )"rb");
#line 354
  if ((unsigned long )f == (unsigned long )((void *)0)) {
#line 355
    return ((enum cmd_retval )-1);
  }
#line 358
  cfg_references ++;
#line 360
  n = (u_int___0 )0;
#line 361
  line = (char *)((void *)0);
#line 362
  retval = (enum cmd_retval )0;
#line 363
  while (1) {
#line 363
    buf = fgets((char * __restrict  )buf, (int )len, (FILE * __restrict  )f);
#line 363
    if (! buf) {
#line 363
      break;
    }
#line 365
    if ((int )*(buf + (len - 1UL)) == 10) {
#line 366
      len --;
    }
#line 367
    printf((char const   * __restrict  )"%s: %s", path, buf);
#line 370
    if ((unsigned long )line != (unsigned long )((void *)0)) {
#line 371
      tmp = strlen(line);
#line 371
      oldlen = (size_t )tmp;
#line 372
      tmp___0 = xrealloc((void *)line, (size_t )1, (oldlen + len) + 1UL);
#line 372
      line = (char *)tmp___0;
    } else {
#line 374
      oldlen = (size_t )0;
#line 375
      tmp___1 = malloc(len + 1UL);
#line 375
      line = (char *)tmp___1;
    }
#line 379
    memcpy(line + oldlen, buf, len);
#line 380
    *(line + (oldlen + len)) = (char )'\000';
#line 381
    n ++;
#line 384
    tmp___2 = strlen(line);
#line 384
    len = (size_t )tmp___2;
#line 385
    if (len > 0UL) {
#line 385
      if ((int )*(line + (len - 1UL)) == 92) {
#line 386
        *(line + (len - 1UL)) = (char )'\000';
#line 389
        if (len > 1UL) {
#line 389
          if ((int )*(line + (len - 2UL)) != 92) {
#line 390
            continue;
          }
        }
      }
    }
#line 392
    copy = line;
#line 393
    line = (char *)((void *)0);
#line 396
    buf = copy;
#line 397
    while (1) {
#line 397
      tmp___3 = isspace((int )((u_char___0 )*buf));
#line 397
      if (! tmp___3) {
#line 397
        break;
      }
#line 398
      buf ++;
    }
#line 399
    if ((int )*buf == 0) {
#line 400
      continue;
    }
#line 403
    tmp___4 = cmd_string_parse((char const   *)buf, & cmdlist, & cause);
#line 403
    if (tmp___4 != 0) {
#line 404
      free((void *)copy);
#line 405
      if ((unsigned long )cause == (unsigned long )((void *)0)) {
#line 406
        continue;
      }
#line 407
      free((void *)cause);
#line 408
      continue;
    }
#line 410
    free((void *)copy);
#line 411
    if ((unsigned long )cmdlist == (unsigned long )((void *)0)) {
#line 412
      continue;
    }
#line 414
    if ((unsigned long )ctxin == (unsigned long )((void *)0)) {
#line 415
      ctx.msgdata = (struct msg_command_data *)((void *)0);
#line 416
      ctx.curclient = (struct client *)((void *)0);
#line 417
      ctx.cmdclient = (struct client *)((void *)0);
    } else {
#line 419
      ctx.msgdata = ctxin->msgdata;
#line 420
      ctx.curclient = ctxin->curclient;
#line 421
      ctx.cmdclient = ctxin->cmdclient;
    }
#line 425
    cfg_cause = (char *)((void *)0);
  }
#line 427
  if ((unsigned long )line != (unsigned long )((void *)0)) {
#line 428
    free((void *)line);
  }
#line 430
  fclose(f);
#line 432
  cfg_references --;
#line 434
  return (retval);
}
}
#line 437 "tmux_leak_10.c"
int main(void) 
{ 
  struct cmd_ctx ctxin ;
  struct causelist causes ;
  void *tmp ;

  {
#line 441
  tmp = malloc((size_t )1);
#line 441
  causes.list = (char **)tmp;
#line 442
  while (1) {
#line 442
    causes.num = (u_int___0 )0;
#line 442
    causes.list = (char **)((void *)0);
#line 442
    causes.space = (size_t )0;
#line 442
    break;
  }
#line 443
  load_cfg("path", & ctxin, & causes);
#line 444
  return (0);
}
}
