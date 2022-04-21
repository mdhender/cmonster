// Copyright (c) 2022 Michael D Henderson
//
// Copyright (c) 1988, 2001 Rich Skrenta
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef MONSTER_MONSTER_H
#define MONSTER_MONSTER_H

#include <stdarg.h>

typedef unsigned char boolean;

boolean alloc_block(int *n);
boolean alloc_detail(int *n, char *s);
boolean alloc_int(int *n);
boolean alloc_line(int *n);
boolean alloc_log(int *n);
boolean alloc_obj(int *n);
boolean alloc_room(int *n);
boolean can_alter(int dir, int room_);
boolean can_drop(void);
boolean can_hold(void);
boolean can_make(int dir, int room_);
boolean check_person(int n, char *id);
boolean checkhide(void);
boolean cycle_open(void);
boolean desc_allowed(void);
boolean drop_everything(int pslot);
boolean edit_desc(int *dsc);
boolean enter_universe(void);
boolean exact_obj(int *n, char *s);
boolean exact_pers(int *n, char *s);
boolean exact_room(int *n,  char *s);
boolean exact_user(int *n, char *s);
boolean fix_player(void);
boolean hold_obj(int n);
boolean is_owner(int n, boolean surpress);
boolean isnum(char *s);
boolean links_possible(void);
boolean loc_ping(void);
boolean look_detail(char *s);
boolean look_person(char *s);
boolean lookup_alias(int *n, char *s_);
boolean lookup_detail(int *n, char *s_);
boolean lookup_dir(int *dir, char *s_);
boolean lookup_obj(int *pnum, char *s_);
boolean lookup_pers(int *pnum, char *s_);
boolean lookup_room(int *n, char *s_);
boolean lookup_set(int *n, char *s_);
boolean lookup_show(int *n, char *s_);
boolean lookup_spell(int *n, char *s_);
boolean lookup_user(int *pnum, char *s_);
boolean nuke_person(int n, char *id);
boolean obj_here(int n);
boolean obj_hold(int n);
boolean obj_nameinuse(int objnum, char *newname);
boolean obj_owner(int n, boolean checkpub);
boolean parse_obj(int *n, char *s, boolean override);
boolean parse_pers(int *pnum, char * s_);
boolean ping_player(int n, boolean silent);
boolean place_obj(int n, boolean silent);
boolean protected_(int n);
boolean put_token(int room_, int *aslot, int hidelev);
boolean revive_player(int *mylog);
boolean room_nameinuse(int num, char *newname);
boolean take_obj(int objnum, int slot);
boolean which_dir(int *dir, char *s_);
char keyget(void);
double mrandom(void);
int find_hold(int objnum, int slot);
int find_numexits(void);
int find_numhold(int player);
int find_numobjs(void);
int find_numpeople(void);
int find_obj(int objnum);
int lookup_cmd(char *s_);
int n_can_see(void);
int number(char *s);
int punch_force(int sock);
void addblocks(int n);
void addints(int n);
void addlines(int n);
void addobjects(int n);
void addrooms(int n);
void anal_exit(int dir);
void analyze_exit(int dir);
void block_subs(int n, char *s);
void check_subst(void);
void checkevents(boolean silent);
void clear_command(void);
void clear_people(int loc);
void collision_wait(void);
void createroom(char *s);
void crystal_look(int chill_msg);
void custom_help(void);
void custom_room(void);
void deadcheck(int *err, char *s);
void default_fail(void);
void del_room(int n);
void delete_block(int *n);
void delete_int(int *n);
void delete_line(int *n);
void delete_log(int *n);
void delete_obj(int *n);
void delete_room(int *n);
void desc_health(int n, char *header);
void desc_obj(int n);
void desc_person(int i);
void disown_user(char *s);
void dist_list(void);
void do_accept(char *s);
void do_brief(void);
void do_claim(char *s);
void do_custom(char *dirnam);
void do_describe(char *s);
void do_destroy(char *s);
void do_die(void);
void do_disown(char *s);
void do_drop(char *s);
void do_duplicate(char *s);
void do_endplay(int lognum, boolean ping);
void do_examine(char *s, boolean *three, boolean silent);
void do_exit(int exit_slot);
void do_form(char *s_);
void do_get(char *s);
void do_go(char *s, boolean verb);
void do_health(char *s);
void do_hide(char *s);
void do_inv(char *s);
void do_link(char *s_);
void do_look(char *s);
void do_makeobj(char *s);
void do_meta_get(int n);
void do_objects(void);
void do_objrename(int objnum);
void do_ping(char *s);
void do_players(char *s);
void do_poof(char *s_);
void do_program(char *objnam);
void do_public(char *s);
void do_punch(char *s);
void do_refuse(char *s);
void do_relink(char *s_);
void do_rename(void);
void do_rooms(char *s_);
void do_s_details(void);
void do_s_exits(void);
void do_s_help(void);
void do_s_object(char *s_);
void do_say(char *s_);
void do_search(char *s);
void do_self(char *s);
void do_set(char *s_);
void do_setname(char *s);
void do_show(char *s_);
void do_system(char *s_);
void do_unhide(char *s);
void do_unlink(char *s);
void do_unmake(char *s);
void do_use(char *s);
void do_version(char *s);
void do_wear(char *s);
void do_whisper(char *s_);
void do_who(void);
void do_whois(char *s);
void do_wield(char *s);
void do_y_altmsg(void);
void do_y_help(void);
void do_zap(char *s);
void doawait(double t);
void drop_obj(int slot, int pslot);
void edit_append(void);
void edit_delete(int n);
void edit_doinsert(int n);
void edit_help(void);
void edit_insert(int n);
void edit_replace(int n);
void edit_show(void);
void exit_case(int dir);
void exit_default(int dir, int kind);
void exit_fail(int dir);
void finish_guts(void);
void fix_stuff(void);
void freeblock(void);
void freedate(void);
void freeevent(void);
void freeindex(void);
void freeint(void);
void freeline(void);
void freenam(void);
void freeobj(void);
void freeobjnam(void);
void freeobjown(void);
void freeown(void);
void freepers(void);
void freeroom(void);
void freespell(void);
void freetime(void);
void freeuser(void);
void get_key(int dir);
void get_punch(int sock, char *s);
void getblock(int n);
void getdate(void);
void getevent(int n);
void gethere(int n);
void getindex(int n);
void getint(int n);
void getline(int n);
void getnam(void);
void getobj(int n);
void getobjnam(void);
void getobjown(void);
void getown(void);
void getpers(void);
void getroom(int n);
void getspell(int n);
void gettime(void);
void getuser(void);
void handle_event(boolean *printed);
void init(void);
void init_exit(int dir);
void kill_user(char *s);
void leave_universe(void);
void link_room(int origdir, int targdir, int targroom);
void list_get(void);
void list_rooms(char *s);
void lock(int fdes);
void log_action(int theaction, int thetarget);
void log_begin(int room_);
void log_entry(int direction, int room_, int sender_slot);
void log_event(int send, int act, int targ, int p, char *s, int room_);
void log_exit(int direction, int room_, int sender_slot);
void log_quit(int room_, boolean dropped);
void make_line(int *n, char *prompt, int limit);
void maybe_drop(void);
void move_asleep(void);
void mprintf(const char *fmt, ...);
void nice_say(char *s);
void nicedate(char *timestr, char *newstr);
void niceprint(int *len, char *s);
void nicetime(char *timestr, char *newstr);
void noisehide(int percent);
void obj_view(int objnum);
void p_getsucc(int n);
void p_usefail(int n);
void p_usesucc(int n);
void parser(void);
void pchars(char *s);
void people_header(char *where);
void poor_health(int p);
void prestart(void);
void print_desc(int dsc, char *default_);
void print_line(int n);
void print_room(void);
void print_subs(int n, char *s);
void prog_kind(int objnum);
void prog_obj(int objnum);
void program_help(void);
void put_punch(int sock, char *s);
void putblock(void);
void putchars(char *s);
void putdate(void);
void putevent(void);
void putindex(void);
void putint(void);
void putline(void);
void putnam(void);
void putobj(void);
void putobjnam(void);
void putobjown(void);
void putown(void);
void putpers(void);
void putroom(void );
void putspell(void);
void puttime(void);
void putuser(void);
void rebuild_system(void);
void relink_room(int origdir, int targdir, int targroom);
void remove_exit(int dir);
void reveal_exits(boolean *one);
void reveal_objects(boolean *two);
void reveal_people(boolean *three);
void rnd_event(boolean silent);
void room_help(void);
void s_set(int n, char *s);
void s_show(int n, char *s);
void setevent(void);
void setup_guts(void);
void show_altnoise(int n);
void show_exits(void);
void show_group(void);
void show_help(void);
void show_kind(int p);
void show_midnight(int n, boolean *printed);
void show_noises(int n);
void show_objects(void);
void show_people(void);
void special(char *s_);
void system_help(void);
void system_view(void);
void take_hit(int p);
void take_token(int aslot, int roomno);
void tests(void);
void time_health(void);
void time_midnight(void);
void time_noises(void);
void time_trapdoor(boolean silent);
void unlock(int fdes);
void use_crystal(int objnum);
void view_punch(char *a, char *b, int p);
void view_room(void);
void welcome_back(int *mylog);
void xpoof(int loc);

extern char *trim(void);

/* Input routine.   Gets a line of text from user which checking
   for async events */
extern void grab_line(char *prompt, char *s, boolean echo);

/* p2c definitions */

#ifndef true
# define true    1
# define false   0
#endif

#ifndef TRUE
# define TRUE    1
# define FALSE   0
#endif

//extern char *ctime();


#endif //MONSTER_MONSTER_H
