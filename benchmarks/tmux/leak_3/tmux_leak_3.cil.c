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
#line 67 "../stdio.h"
typedef unsigned short u_short___0;
#line 68 "../stdio.h"
typedef unsigned int u_int___0;
#line 79 "../stdio.h"
typedef unsigned char u_char___0;
#line 85 "../stdio.h"
typedef int pid_t___0;
#line 39 "../tmux.h"
typedef char bitstr_t;
#line 41 "../tmux.h"
struct event {

};
#line 42 "../tmux.h"
struct termios {

};
#line 48
struct key_binding;
#line 48
struct key_binding;
#line 49
struct key_bindings;
#line 49
struct key_bindings;
#line 50
struct args;
#line 50
struct args;
#line 51
struct client;
#line 51
struct client;
#line 52
struct cmd_find_state;
#line 52
struct cmd_find_state;
#line 53
struct cmdq_item;
#line 53
struct cmdq_item;
#line 54
struct cmdq_list;
#line 54
struct cmdq_list;
#line 55
struct environ;
#line 55
struct environ;
#line 56
struct format_job_tree;
#line 56
struct format_job_tree;
#line 57
struct input_ctx;
#line 57
struct input_ctx;
#line 59
struct mouse_event;
#line 59
struct mouse_event;
#line 60
struct options;
#line 60
struct options;
#line 61
struct options_entry;
#line 61
struct options_entry;
#line 62
struct session;
#line 62
struct session;
#line 63
struct tmuxpeer;
#line 63
struct tmuxpeer;
#line 140 "../tmux.h"
typedef unsigned long long key_code;
#line 473 "../tmux.h"
struct options_tree {
   struct options_entry *rbh_root ;
};
#line 473 "../tmux.h"
struct options {
   struct options_tree tree ;
   struct options *parent ;
};
#line 479 "../tmux.h"
struct __anonstruct_name_entry_26 {
   struct paste_buffer *rbe_left ;
   struct paste_buffer *rbe_right ;
   struct paste_buffer *rbe_parent ;
   int rbe_color ;
};
#line 479 "../tmux.h"
struct __anonstruct_time_entry_27 {
   struct paste_buffer *rbe_left ;
   struct paste_buffer *rbe_right ;
   struct paste_buffer *rbe_parent ;
   int rbe_color ;
};
#line 479 "../tmux.h"
struct paste_buffer {
   char *data ;
   size_t size ;
   char *name ;
   int automatic ;
   u_int___0 order ;
   struct __anonstruct_name_entry_26 name_entry ;
   struct __anonstruct_time_entry_27 time_entry ;
};
#line 543 "../tmux.h"
struct utf8_data {
   u_char___0 data[9] ;
   u_char___0 have ;
   u_char___0 size ;
   u_char___0 width ;
};
#line 585 "../tmux.h"
struct grid_cell {
   u_char___0 flags ;
   u_short___0 attr ;
   int fg ;
   int bg ;
   struct utf8_data data ;
};
#line 592 "../tmux.h"
struct __anonstruct_data_29 {
   u_char___0 attr ;
   u_char___0 fg ;
   u_char___0 bg ;
   u_char___0 data ;
};
#line 592 "../tmux.h"
union __anonunion____missing_field_name_28 {
   u_int___0 offset ;
   struct __anonstruct_data_29 data ;
};
#line 592 "../tmux.h"
struct grid_cell_entry {
   u_char___0 flags ;
   union __anonunion____missing_field_name_28 __annonCompField1 ;
};
#line 606 "../tmux.h"
struct grid_line {
   u_int___0 cellused ;
   u_int___0 cellsize ;
   struct grid_cell_entry *celldata ;
   u_int___0 extdsize ;
   struct grid_cell *extddata ;
   int flags ;
};
#line 618 "../tmux.h"
struct grid {
   int flags ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 hscrolled ;
   u_int___0 hsize ;
   u_int___0 hlimit ;
   struct grid_line *linedata ;
};
#line 633
struct cmd_list;
#line 646
struct bufferevent;
#line 671
enum __anonenum_lineflag_33 {
    LINE_SEL_NONE = 0,
    LINE_SEL_LEFT_RIGHT = 1,
    LINE_SEL_RIGHT_LEFT = 2
} ;
#line 671 "../tmux.h"
struct screen_sel {
   int flag ;
   int hidden ;
   int rectflag ;
   enum __anonenum_lineflag_33 lineflag ;
   int modekeys ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 ex ;
   u_int___0 ey ;
   struct grid_cell cell ;
};
#line 693
struct screen_titles;
#line 693
struct screen_titles;
#line 694 "../tmux.h"
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
   u_int___0 hsize ;
   int mode ;
   bitstr_t *tabs ;
   struct screen_sel sel ;
};
#line 721
struct window_pane;
#line 746 "../tmux.h"
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
#line 766
struct winlink;
#line 766
struct format_tree;
#line 788
struct window;
#line 788
struct layout_cell;
#line 788 "../tmux.h"
struct __anonstruct_entry_34 {
   struct window_pane *tqe_next ;
   struct window_pane **tqe_prev ;
};
#line 788 "../tmux.h"
struct __anonstruct_tree_entry_35 {
   struct window_pane *rbe_left ;
   struct window_pane *rbe_right ;
   struct window_pane *rbe_parent ;
   int rbe_color ;
};
#line 788 "../tmux.h"
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
   struct __anonstruct_entry_34 entry ;
   struct __anonstruct_tree_entry_35 tree_entry ;
};
#line 865 "../tmux.h"
struct window_panes {
   struct window_pane *tqh_first ;
   struct window_pane **tqh_last ;
};
#line 870 "../tmux.h"
struct __anonstruct_alerts_entry_36 {
   struct window *tqe_next ;
   struct window **tqe_prev ;
};
#line 870 "../tmux.h"
struct __anonstruct_winlinks_37 {
   struct winlink *tqh_first ;
   struct winlink **tqh_last ;
};
#line 870 "../tmux.h"
struct __anonstruct_entry_38 {
   struct window *rbe_left ;
   struct window *rbe_right ;
   struct window *rbe_parent ;
   int rbe_color ;
};
#line 870 "../tmux.h"
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
   struct __anonstruct_alerts_entry_36 alerts_entry ;
   struct options *options ;
   struct grid_cell style ;
   struct grid_cell active_style ;
   u_int___0 references ;
   struct __anonstruct_winlinks_37 winlinks ;
   struct __anonstruct_entry_38 entry ;
};
#line 922 "../tmux.h"
struct __anonstruct_entry_39 {
   struct winlink *rbe_left ;
   struct winlink *rbe_right ;
   struct winlink *rbe_parent ;
   int rbe_color ;
};
#line 922 "../tmux.h"
struct __anonstruct_wentry_40 {
   struct winlink *tqe_next ;
   struct winlink **tqe_prev ;
};
#line 922 "../tmux.h"
struct __anonstruct_sentry_41 {
   struct winlink *tqe_next ;
   struct winlink **tqe_prev ;
};
#line 922 "../tmux.h"
struct winlink {
   int idx ;
   struct session *session ;
   struct window *window ;
   size_t status_width ;
   struct grid_cell status_cell ;
   char *status_text ;
   int flags ;
   struct __anonstruct_entry_39 entry ;
   struct __anonstruct_wentry_40 wentry ;
   struct __anonstruct_sentry_41 sentry ;
};
#line 941 "../tmux.h"
struct winlinks {
   struct winlink *rbh_root ;
};
#line 942 "../tmux.h"
struct winlink_stack {
   struct winlink *tqh_first ;
   struct winlink **tqh_last ;
};
#line 945
enum layout_type {
    LAYOUT_LEFTRIGHT = 0,
    LAYOUT_TOPBOTTOM = 1,
    LAYOUT_WINDOWPANE = 2
} ;
#line 952 "../tmux.h"
struct layout_cells {
   struct layout_cell *tqh_first ;
   struct layout_cell **tqh_last ;
};
#line 955 "../tmux.h"
struct __anonstruct_entry_42 {
   struct layout_cell *tqe_next ;
   struct layout_cell **tqe_prev ;
};
#line 955 "../tmux.h"
struct layout_cell {
   enum layout_type type ;
   struct layout_cell *parent ;
   u_int___0 sx ;
   u_int___0 sy ;
   u_int___0 xoff ;
   u_int___0 yoff ;
   struct window_pane *wp ;
   struct layout_cells cells ;
   struct __anonstruct_entry_42 entry ;
};
#line 992
struct hooks;
#line 992 "../tmux.h"
struct __anonstruct_gentry_46 {
   struct session *tqe_next ;
   struct session **tqe_prev ;
};
#line 992 "../tmux.h"
struct __anonstruct_entry_47 {
   struct session *rbe_left ;
   struct session *rbe_right ;
   struct session *rbe_parent ;
   int rbe_color ;
};
#line 992 "../tmux.h"
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
   struct __anonstruct_gentry_46 gentry ;
   struct __anonstruct_entry_47 entry ;
};
#line 1055 "../tmux.h"
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
#line 1078 "../tmux.h"
struct tty_key {
   char ch ;
   key_code key ;
   struct tty_key *left ;
   struct tty_key *right ;
   struct tty_key *next ;
};
#line 1088
struct tty_code;
#line 1088
struct tty_code;
#line 1090 "../tmux.h"
struct __anonstruct_entry_48 {

};
#line 1090 "../tmux.h"
struct tty_term {
   char *name ;
   u_int___0 references ;
   char acs[11][2] ;
   struct tty_code *codes ;
   int flags ;
   struct __anonstruct_entry_48 entry ;
};
#line 1106
struct evbuffer;
#line 1106
enum __anonenum_term_type_49 {
    TTY_VT100 = 0,
    TTY_VT101 = 1,
    TTY_VT102 = 2,
    TTY_VT220 = 3,
    TTY_VT320 = 4,
    TTY_VT420 = 5,
    TTY_UNKNOWN = 6
} ;
#line 1106 "../tmux.h"
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
   enum __anonenum_term_type_49 term_type ;
   struct mouse_event mouse ;
   int mouse_drag_flag ;
   void (*mouse_drag_update)(struct client * , struct mouse_event * ) ;
   void (*mouse_drag_release)(struct client * , struct mouse_event * ) ;
   struct event key_timer ;
   struct tty_key *key_tree ;
};
#line 1206 "../tmux.h"
struct __anonstruct_entry_50 {
   struct message_entry *tqe_next ;
   struct message_entry **tqe_prev ;
};
#line 1206 "../tmux.h"
struct message_entry {
   char *msg ;
   u_int___0 msg_num ;
   time_t msg_time ;
   struct __anonstruct_entry_50 entry ;
};
#line 1215 "../tmux.h"
struct __anonstruct_entry_51 {
   struct args_entry *rbe_left ;
   struct args_entry *rbe_right ;
   struct args_entry *rbe_parent ;
   int rbe_color ;
};
#line 1215 "../tmux.h"
struct args_entry {
   u_char___0 flag ;
   char *value ;
   struct __anonstruct_entry_51 entry ;
};
#line 1221 "../tmux.h"
struct args_tree {
   struct args_entry *rbh_root ;
};
#line 1222 "../tmux.h"
struct args {
   struct args_tree tree ;
   int argc ;
   char **argv ;
};
#line 1234 "../tmux.h"
struct cmd_find_state {
   int flags ;
   struct cmd_find_state *current ;
   struct session *s ;
   struct winlink *wl ;
   struct window *w ;
   struct window_pane *wp ;
   int idx ;
};
#line 1256
struct cmd_entry;
#line 1256 "../tmux.h"
struct __anonstruct_qentry_52 {
   struct cmd *tqe_next ;
   struct cmd **tqe_prev ;
};
#line 1256 "../tmux.h"
struct cmd {
   struct cmd_entry  const  *entry ;
   struct args *args ;
   char *file ;
   u_int___0 line ;
   int flags ;
   void *data ;
   struct __anonstruct_qentry_52 qentry ;
};
#line 1269 "../tmux.h"
struct __anonstruct_list_53 {
   struct cmd *tqh_first ;
   struct cmd **tqh_last ;
};
#line 1269 "../tmux.h"
struct cmd_list {
   int references ;
   struct __anonstruct_list_53 list ;
};
#line 1276
enum cmd_retval {
    CMD_RETURN_ERROR = -1,
    CMD_RETURN_NORMAL = 0,
    CMD_RETURN_WAIT = 1,
    CMD_RETURN_STOP = 2
} ;
#line 1284
enum cmdq_type {
    CMDQ_COMMAND = 0,
    CMDQ_CALLBACK = 1
} ;
#line 1290 "../tmux.h"
struct cmdq_shared {
   int references ;
   int flags ;
   struct format_tree *formats ;
   struct mouse_event mouse ;
   struct cmd_find_state current ;
};
#line 1305
struct cmdq_item;
#line 1306 "../tmux.h"
struct cmdq_list {
   struct cmdq_item *tqh_first ;
   struct cmdq_item **tqh_last ;
};
#line 1316
struct cmd_entry;
#line 1322
struct key_table;
#line 1322 "../tmux.h"
struct __anonstruct_message_log_54 {
   struct message_entry *tqh_first ;
   struct message_entry **tqh_last ;
};
#line 1322
enum __anonenum_prompt_mode_55 {
    PROMPT_ENTRY = 0,
    PROMPT_COMMAND = 1
} ;
#line 1322
struct cmd_q;
#line 1322 "../tmux.h"
struct __anonstruct_entry_56 {
   struct client *tqe_next ;
   struct client **tqe_prev ;
};
#line 1322 "../tmux.h"
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
   struct __anonstruct_message_log_54 message_log ;
   char *prompt_string ;
   struct utf8_data *prompt_buffer ;
   size_t prompt_index ;
   int (*prompt_inputcb)(struct client * , void * , char const   * , int  ) ;
   void (*prompt_freecb)(void * ) ;
   void *prompt_data ;
   u_int___0 prompt_hindex ;
   enum __anonenum_prompt_mode_55 prompt_mode ;
   int prompt_flags ;
   struct session *session ;
   struct session *last_session ;
   int wlmouse ;
   int references ;
   struct cmd_q *cmdq ;
   struct __anonstruct_entry_56 entry ;
};
#line 1434 "../tmux.h"
struct __anonstruct_entry_57 {
   struct key_binding *rbe_left ;
   struct key_binding *rbe_right ;
   struct key_binding *rbe_parent ;
   int rbe_color ;
};
#line 1434 "../tmux.h"
struct key_binding {
   key_code key ;
   struct cmd_list *cmdlist ;
   int flags ;
   struct __anonstruct_entry_57 entry ;
};
#line 1443 "../tmux.h"
struct key_bindings {
   struct key_binding *rbh_root ;
};
#line 1445 "../tmux.h"
struct __anonstruct_entry_58 {
   struct key_table *rbe_left ;
   struct key_table *rbe_right ;
   struct key_table *rbe_parent ;
   int rbe_color ;
};
#line 1445 "../tmux.h"
struct key_table {
   char const   *name ;
   struct key_bindings key_bindings ;
   u_int___0 references ;
   struct __anonstruct_entry_58 entry ;
};
#line 1507
struct paste_buffer;
#line 1515
struct format_tree;
#line 16 "tmux_leak_3.c"
struct __anonstruct_args_59 {
   char const   *template ;
   int lower ;
   int upper ;
};
#line 16 "tmux_leak_3.c"
struct cmd_entry {
   char const   *name ;
   char const   *alias ;
   struct __anonstruct_args_59 args ;
   char const   *usage ;
   int flags ;
   enum cmd_retval (*exec)(struct cmd * , struct cmdq_item * ) ;
};
#line 35 "tmux_leak_3.c"
struct cmd_state {
   struct client *c ;
   struct cmd_find_state tflag ;
   struct cmd_find_state sflag ;
};
#line 41 "tmux_leak_3.c"
struct __anonstruct_entry_60 {
   struct cmdq_item *tqe_next ;
   struct cmdq_item **tqe_prev ;
};
#line 41 "tmux_leak_3.c"
struct cmdq_item {
   char const   *name ;
   struct cmdq_list *queue ;
   struct cmdq_item *next ;
   struct client *client ;
   enum cmdq_type type ;
   u_int___0 group ;
   u_int___0 number ;
   time_t time ;
   int flags ;
   struct cmdq_shared *shared ;
   struct cmd_list *cmdlist ;
   struct cmd *cmd ;
   enum cmd_retval (*cb)(struct cmdq_item * , void * ) ;
   void *data ;
   struct cmd_state state ;
   struct __anonstruct_entry_60 entry ;
};
#line 88
struct cmd_load_buffer_data;
#line 237 "/usr/include/stdio.h"
extern int fclose(FILE *__stream ) ;
#line 272
extern FILE *fopen(char const   * __restrict  __filename , char const   * __restrict  __modes ) ;
#line 362
extern int printf(char const   * __restrict  __format  , ...) ;
#line 715
extern size_t fwrite(void const   * __restrict  __ptr , size_t __size , size_t __n ,
                     FILE * __restrict  __s ) ;
#line 830
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror)(FILE *__stream ) ;
#line 483 "/usr/include/stdlib.h"
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
#line 733
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) realpath)(char const   * __restrict  __name ,
                                                                                 char * __restrict  __resolved ) ;
#line 77 "tmux_leak_3.c"
extern int ( /* missing proto */  strdup)() ;
#line 71 "tmux_leak_3.c"
char *server_client_get_path(struct client *c , char const   *file ) 
{ 
  char *path ;
  char resolved[4096] ;
  int tmp ;
  char *tmp___0 ;
  int tmp___1 ;

  {
#line 76
  if ((int const   )*file == 47) {
#line 77
    tmp = strdup(file);
#line 77
    path = (char *)tmp;
  }
#line 78
  tmp___0 = realpath((char const   * __restrict  )path, (char * __restrict  )(resolved));
#line 78
  if ((unsigned long )tmp___0 == (unsigned long )((void *)0)) {
#line 79
    return (path);
  }
#line 80
  free((void *)path);
#line 81
  tmp___1 = strdup(resolved);
#line 81
  return ((char *)tmp___1);
}
}
#line 84 "tmux_leak_3.c"
static enum cmd_retval cmd_load_buffer_exec(struct cmd *self , struct cmdq_item *item ) 
{ 
  struct args *args ;
  struct client *c ;
  FILE *f ;
  char const   *path ;
  char const   *bufname ;
  char *pdata ;
  char *file ;
  size_t psize ;
  int tmp ;

  {
#line 87
  args = self->args;
#line 89
  c = item->client;
#line 96
  bufname = (char const   *)((void *)0);
#line 98
  path = (char const   *)*(args->argv + 0);
#line 100
  file = server_client_get_path(c, path);
#line 101
  f = fopen((char const   * __restrict  )file, (char const   * __restrict  )"rb");
#line 102
  if ((unsigned long )f == (unsigned long )((void *)0)) {
#line 103
    printf((char const   * __restrict  )"%s", file);
#line 104
    free((void *)file);
#line 105
    return ((enum cmd_retval )-1);
  }
#line 108
  pdata = (char *)((void *)0);
#line 109
  psize = (size_t )0;
#line 110
  tmp = ferror(f);
#line 110
  if (tmp) {
#line 111
    printf((char const   * __restrict  )"%s: read error", file);
#line 112
    goto error;
  }
#line 114
  if ((unsigned long )pdata != (unsigned long )((void *)0)) {
#line 115
    *(pdata + psize) = (char )'\000';
  }
#line 117
  fclose(f);
#line 118
  free((void *)file);
#line 120
  return ((enum cmd_retval )0);
  error: 
#line 123
  free((void *)pdata);
#line 124
  if ((unsigned long )f != (unsigned long )((void *)0)) {
#line 125
    fclose(f);
  }
#line 127
  return ((enum cmd_retval )-1);
}
}
#line 142
extern int ( /* missing proto */  strcmp)() ;
#line 130 "tmux_leak_3.c"
static enum cmd_retval cmd_save_buffer_exec(struct cmd *self , struct cmdq_item *item ) 
{ 
  struct args *args ;
  struct client *c ;
  char const   *path ;
  char const   *bufdata ;
  char const   *flags ;
  char *msg ;
  char *file ;
  size_t used ;
  size_t bufsize ;
  FILE *f ;
  int tmp ;
  size_t tmp___0 ;

  {
#line 133
  args = self->args;
#line 134
  c = item->client;
#line 142
  tmp = strcmp(path, "-");
#line 142
  if (tmp == 0) {
#line 143
    if ((unsigned long )c == (unsigned long )((void *)0)) {
#line 144
      return ((enum cmd_retval )-1);
    }
#line 146
    if ((unsigned long )c->session == (unsigned long )((void *)0)) {
#line 147
      goto do_stdout;
    } else
#line 146
    if (c->flags & 8192) {
#line 147
      goto do_stdout;
    }
#line 148
    goto do_print;
  }
#line 151
  flags = "wb";
#line 153
  file = server_client_get_path(c, path);
#line 154
  f = fopen((char const   * __restrict  )file, (char const   * __restrict  )flags);
#line 155
  if ((unsigned long )f == (unsigned long )((void *)0)) {
#line 156
    printf((char const   * __restrict  )"%s", file);
#line 157
    free((void *)file);
#line 158
    return ((enum cmd_retval )-1);
  }
#line 161
  tmp___0 = fwrite((void const   * __restrict  )bufdata, (size_t )1, bufsize, (FILE * __restrict  )f);
#line 161
  if (tmp___0 != bufsize) {
#line 162
    printf((char const   * __restrict  )"%s: write error", file);
#line 163
    fclose(f);
#line 165
    return ((enum cmd_retval )-1);
  }
#line 168
  fclose(f);
#line 169
  free((void *)file);
#line 171
  return ((enum cmd_retval )0);
  do_stdout: 
#line 174
  return ((enum cmd_retval )0);
  do_print: 
#line 177
  if (bufsize > 2499UL) {
#line 178
    return ((enum cmd_retval )-1);
  }
#line 180
  msg = (char *)((void *)0);
#line 182
  used = (size_t )0;
#line 184
  free((void *)msg);
#line 185
  return ((enum cmd_retval )0);
}
}
#line 188 "tmux_leak_3.c"
int main(void) 
{ 
  struct cmd self ;
  struct cmdq_item item ;

  {
#line 192
  cmd_load_buffer_exec(& self, & item);
#line 193
  cmd_save_buffer_exec(& self, & item);
#line 194
  return (0);
}
}