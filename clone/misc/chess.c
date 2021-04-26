// Code of ShenZhou
//file from http://www.lhmz.yn.cninfo.net/jackyboy/storage.htm
//Modified by maco again
//

#include <ansi.h>
#define che TABLE[table[sROW]][sCOL][2]
#define cc TABLE[table[sROW]][sCOL][3]
#define cc1 TABLE[table[tROW]][tCOL][3]
inherit ITEM;
inherit F_SAVE;

string bche = "";
string rche = "";
string aaa = "";
int aa = 0;
int bb = 0;

mapping TABLE = ([ // table /*┌┐┖┚─┃├┤┬┴┼*/
0: ([
	0 :({ "┌",HIR"车"NOR, 1,1 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┬",HIR"马"NOR, 2,1 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┬",HIR"相"NOR, 3,1 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┬",HIR"仕"NOR, 4,1 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┬",HIR"帅"NOR, 5,1 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┬",HIR"仕"NOR, 4,1 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┬",HIR"相"NOR, 3,1 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┬",HIR"马"NOR, 2,1 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┐",HIR"车"NOR, 1,1 }),
	]),
1: ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "＼", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "／", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),

2: ([
	0 :({ "├", "  ", 0,0 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┼", "  ", 0,0 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┼", "  ", 0,0 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┼", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┼", "  ", 0,0 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┼", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┼", "  ", 0,0 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┼", "  ", 0,0 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┤", "  ", 0,0 }),
	]),
3: ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "／", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "＼", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
4 : ([
	0 :({ "├", "  ", 0,0 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┼",HIR"炮"NOR, 6,1 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┼", "  ", 0,0 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┼", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┼", "  ", 0,0 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┼", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┼", "  ", 0,0 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┼",HIR"炮"NOR, 6,1 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┤", "  ", 0,0 }),
	]),
5 : ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "  ", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "  ", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
6 : ([
	0 :({ "├",HIR"兵"NOR, 7,1 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┼", "  ", 0,0 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┼",HIR"兵"NOR, 7,1 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┼", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┼",HIR"兵"NOR, 7,1 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┼", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┼",HIR"兵"NOR, 7,1 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┼", "  ", 0,0 }),
15:({ "─", "  ", 0,0 }),
	16:({ "┤",HIR"兵"NOR, 7,1 }),
	]),
7 : ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "  ", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "  ", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
8 : ([
0 :({ "┖", "  ", 0,0 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┴", "  ", 0,0 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┴", "  ", 0,0 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┴", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┴", "  ", 0,0 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┴", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┴", "  ", 0,0 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┴", "  ", 0,0 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┚", "  ", 0,0 }),
	]),
9 : ([
	0 : ({ " ～～ 楚  河 ～～～～ 汉  界 ～～ ", "  ", 0,0 }),
	]),
10: ([
	0 :({ "┌", "  ", 0,0 }),
1 :({ "─", "  ", 0,0 }),
	2 :({ "┬", "  ", 0,0 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┬", "  ", 0,0 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┬", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┬", "  ", 0,0 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┬", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┬", "  ", 0,0 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┬", "  ", 0,0 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┐", "  ", 0,0 }),
	]),
11: ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "  ", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "  ", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
12 : ([
	0 :({ "├",HIC"卒"NOR, 7,2 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┼", "  ", 0,0 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┼",HIC"卒"NOR, 7,2 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┼", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┼",HIC"卒"NOR, 7,2 }),
9 :({ "─", "  ", 0,0 }),
	10:({ "┼", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┼",HIC"卒"NOR, 7,2 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┼", "  ", 0,0 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┤",HIC"卒"NOR, 7,2 }),
	]),
13: ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "  ", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "  ", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
14: ([
	0 :({ "├", "  ", 0,0 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┼",HIC"包"NOR, 6,2 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┼", "  ", 0,0 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┼", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┼", "  ", 0,0 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┼", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┼", "  ", 0,0 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┼",HIC"包"NOR, 6,2 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┤", "  ", 0,0 })
]),
15: ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
	6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "＼", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "／", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
16: ([
	0 :({ "├", "  ", 0,0 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┼", "  ", 0,0 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┼", "  ", 0,0 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┼", "  ", 0,0 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┼", "  ", 0,0 }),
	9 :({ "─", "  ", 0,0 }),
	10:({ "┼", "  ", 0,0 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┼", "  ", 0,0 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┼", "  ", 0,0 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┤", "  ", 0,0 })
	]),
18: ([
	0 : ({ "┃", "  ", 0,0 }),
	1 : ({ "  ", "  ", 0,0 }),
	2 : ({ "┃", "  ", 0,0 }),
	3 : ({ "  ", "  ", 0,0 }),
	4 : ({ "┃", "  ", 0,0 }),
	5 : ({ "  ", "  ", 0,0 }),
6 : ({ "┃", "  ", 0,0 }),
	7 : ({ "／", "  ", 0,0 }),
	8 : ({ "┃", "  ", 0,0 }),
	9 : ({ "＼", "  ", 0,0 }),
	10: ({ "┃", "  ", 0,0 }),
	11: ({ "  ", "  ", 0,0 }),
	12: ({ "┃", "  ", 0,0 }),
	13: ({ "  ", "  ", 0,0 }),
	14: ({ "┃", "  ", 0,0 }),
	15: ({ "  ", "  ", 0,0 }),
	16: ({ "┃", "  ", 0,0 })
	]),
19: ([
	0 :({ "┖",HIC"车"NOR, 1,2 }),
	1 :({ "─", "  ", 0,0 }),
	2 :({ "┴",HIC"马"NOR, 2,2 }),
	3 :({ "─", "  ", 0,0 }),
	4 :({ "┴",HIC"象"NOR, 3,2 }),
	5 :({ "─", "  ", 0,0 }),
	6 :({ "┴",HIC"士"NOR, 4,2 }),
	7 :({ "─", "  ", 0,0 }),
	8 :({ "┴",HIC"将"NOR, 5,2 }),
	9 :({ "─", "  ", 0,0 }),

10:({ "┴",HIC"士"NOR, 4,2 }),
	11:({ "─", "  ", 0,0 }),
	12:({ "┴",HIC"象"NOR, 3,2 }),
	13:({ "─", "  ", 0,0 }),
	14:({ "┴",HIC"马"NOR, 2,2 }),
	15:({ "─", "  ", 0,0 }),
	16:({ "┚",HIC"车"NOR, 1,2 }),
	]),

]);

string *table;

string *tossText = ({

	"│      │\n"
	"│  "HIR"●"NOR"  │\n"
	"│      │\n",

	"│  ●  │\n"
	"│      │\n"
	"│  ●  │\n",

"│●    │\n"
	"│  ●  │\n"
	"│    ●│\n",

	"│"HIR"●  ●"NOR"│\n"
	"│      │\n"
	"│"HIR"●  ●"NOR"│\n",

	"│●  ●│\n"
	"│  ●  │\n"
	"│●  ●│\n",

	"│●  ●│\n"
	"│●  ●│\n"
	"│●  ●│\n",

	"┏━━━┐\n",
	"┖━━━┛\n",
});


int init_tab();
int do_display(string arg);
int do_move(string arg);
int do_toss();
int do_draw();
string long();
string query_save_file();
void do_check();
int do_save();
int do_deploy();

void create()
{
	set_name("象棋棋盘", ({ "chinese chess board","board" }) );
	set_weight(3000000);
	set_max_encumbrance(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张象棋棋盘。\n");
		set("value", 0);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
	}
	set("no_refresh",1);
	setup();
}
void init() {
init_tab();
	add_action("do_move","move");   
	add_action("do_toss","toss");
	add_action("do_reset","reset");
	add_action("do_save","csave");
	add_action("do_deploy","deploy");
	add_action("do_lose","lose");
	add_action("do_draw","draw");
	add_action("do_review","review");
}

string query_save_file()
{ 
if( bb == 1 )
return DATA_DIR + "cchess/" 
+ this_player()->query("id")[0..0] 
+ "/" + this_player()->query("id"); 
else
return DATA_DIR + "cchess/cchess"; 
}

int init_tab() {
	table = keys(TABLE);
	table = sort_array(table,1);
	return 1;
}

int do_move(string arg) {
	int sROW,sCOL,tROW,tCOL,i,ii,x,y,tem,tem1,tem2,tem3,tem4;
	string msg,msg1;
object ob,me,target, winner, loser; 
ob = this_object();
me = this_player();
msg1 = "";

if( ob->query("over") ) return notify_fail("这盘棋已经结束了。 \n");

if( me->name() != ob->query("name1") && me->name() != ob->query("name2") )
return notify_fail("你还是先投骰子吧！\n");

if( !ob->query("name2") )
return notify_fail("还要有一个人才能下棋！\n");

if( ob->query("round") == 0 && ob->query("first") != me->name() )
return notify_fail("这个回合不该你走棋！\n");

if( ob->query("round") == 1 && ob->query("first") == me->name() )
return notify_fail("这个回合不该你走棋！\n");

if( !(present(ob->query("id1"),environment(ob))) || 
!(present(ob->query("id2"),environment(ob))) )
return notify_fail("要在双方都在场时才能走棋。\n");

if( me->query("id") == ob->query("id1")) target = find_player(ob->query("id2"));
 else target = find_player(ob->query("id1"));

	if( !arg ) return notify_fail("移动棋子：move 纵坐标 横坐标 to 纵坐标 横坐标 \n");

	if( sscanf(arg,"%d %d to %d %d",sCOL,sROW,tCOL,tROW) != 4 )
		return notify_fail("移动棋子：move 纵坐标 横坐标 to 纵坐标 横坐标 \n");

if( tCOL > 9 || tCOL < 1 || tROW > 9 || tROW < 0 ||
sCOL > 9 || sCOL < 1 || sROW > 9 || sROW < 0)
		return notify_fail("你输入的位置已经在象棋盘之外了。\n");

if( tCOL == sCOL && sROW == tROW )
return notify_fail("这还用移动吗？\n");

	sCOL -= 1;
	tCOL -= 1;

	sROW = sROW * 2;
	tROW = tROW * 2;
	sCOL = sCOL * 2;
	tCOL = tCOL * 2;

	if( TABLE[table[sROW]][sCOL][1] == "  " )
return notify_fail("这个地方没有棋子。\n");

if( TABLE[table[tROW]][tCOL][3] == TABLE[table[sROW]][sCOL][3] )
return notify_fail("你要吃掉自己的棋子？\n");

if( ob->query("round") == 0 && cc != 1 )
		return notify_fail("你拿错棋子了吧！\n");

if( ob->query("round") == 1 && cc != 2 )
		return notify_fail("你拿错棋子了吧！\n");


//车 
if( che == 1 ){
if( tCOL != sCOL && sROW != tROW )
return notify_fail("这个棋子只能走直线。\n");

if( tCOL > sCOL && tCOL - sCOL > 2 )
for (i=sCOL+2;i<tCOL;i++){
if( i%2!=0) continue;
if( TABLE[table[sROW]][i][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( sCOL > tCOL && sCOL - tCOL > 2 )
for (i=tCOL+2;i<sCOL;i++){
if( i%2!=0) continue;
if( TABLE[table[sROW]][i][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( tROW > sROW && tROW - sROW > 2  )
for (i=sROW+2;i<tROW;i++){
if( i%2!=0) continue;
if( TABLE[table[i]][sCOL][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( sROW > tROW && sROW - tROW > 2 )
for (i=tROW+2;i<sROW;i++){
if( i%2!=0) continue;
if( TABLE[table[i]][sCOL][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
}

//马
if( che == 2 ){
if( tCOL == sCOL || sROW == tROW )
return notify_fail("马不能走直线。\n");

if( tCOL < (sCOL - 4) || tCOL > (sCOL + 4) ||
tROW < (sROW - 4) || tROW > (sROW + 4 ) )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( (tCOL == sCOL - 2 || tCOL == sCOL + 2) && 
(tROW != sROW - 4 && tROW != sROW + 4) )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( (tCOL == sCOL - 4 || tCOL == sCOL + 4) && 
(tROW != sROW - 2 && tROW != sROW + 2) )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( sCOL-tCOL < -2 && TABLE[table[sROW]][sCOL+2][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( sCOL-tCOL > 2 && TABLE[table[sROW]][sCOL-2][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( sROW-tROW > 2 && TABLE[table[sROW-2]][sCOL][1] != "  "  )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( sROW-tROW < -2 && TABLE[table[sROW+2]][sCOL][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
//相
if( che == 3 ){
if( tCOL == sCOL || sROW == tROW )
return notify_fail("相不能走直线。\n");

if( (tROW != sROW-4 && tROW != sROW+4) || (tCOL != sCOL-4 
&& tCOL != sCOL+4) )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( tCOL > sCOL ){
if( tROW > sROW && TABLE[table[sROW+2]][sCOL+2][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( tROW < sROW && TABLE[table[sROW-2]][sCOL+2][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( tCOL < sCOL ){
if( tROW > sROW && TABLE[table[sROW+2]][sCOL-2][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( tROW < sROW && TABLE[table[sROW-2]][sCOL-2][1] != "  " )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( (cc == 1 && tROW > 9) || (cc == 2 && tROW < 9) )
return notify_fail("相不能过河。\n");
}
//仕
if( che == 4 ){

if( tCOL == sCOL || sROW == tROW )
return notify_fail("仕不能走直线。\n");

if( (tROW != sROW-2 && tROW != sROW+2) || (tCOL != sCOL-2 
&& tCOL != sCOL+2) )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( cc == 1 && (tCOL > 10 || tCOL < 6 || tROW > 4) )
return notify_fail("仕必需在九宫格内移动。\n");

if( cc == 2 && (tCOL > 10 || tCOL < 6 || tROW < 14) )
return notify_fail("仕必需在九宫格内移动。\n");
}
//帅
if( che == 5 ){
if( tCOL != sCOL && sROW != tROW )
return notify_fail("这个棋子只能走直线。\n");

if( tCOL - sCOL > 2 || tCOL - sCOL < -2 ||
tROW - sROW > 2 || tROW - sROW < -2 )
return notify_fail("帅一次只能走一格。\n");

if( cc == 1 )
if( tCOL > 10 || tCOL < 6 || tROW > 4 )
return notify_fail("帅必需在九宫格内移动。\n");

if( cc == 2 )
if( tCOL > 10 || tCOL < 6 || tROW < 14 )
return notify_fail("帅必需在九宫格内移动。\n");
}
//炮
if( che == 6 ){
ii = 0;

if( tCOL != sCOL && sROW != tROW )
return notify_fail("这个棋子只能走直线。\n");


if( cc1 != 0 )
if( tCOL - sCOL == 2 || tCOL - sCOL == -2 ||
tROW - sROW == 2 || tROW - sROW == -2 )
return notify_fail("这个棋子不能移动到那个地方。\n");

if( tCOL > sCOL ){
for (i=sCOL+2;i<tCOL;i++){
if( i%2!=0) continue;
if( TABLE[table[sROW]][i][1] != "  " )
ii += 1;
if( ii > 1 )
return notify_fail("这个棋子不能移动到那个地方。\n");
if( ii == 1 && cc1 == 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
if( ii == 0 && cc1 != 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( sCOL > tCOL ){
for (i=tCOL+2;i<sCOL;i++){
if( i%2!=0) continue;
if( TABLE[table[sROW]][i][1] != "  " )
ii += 1;
if( ii > 1 )
return notify_fail("这个棋子不能移动到那个地方。\n");
if( ii == 1 && cc1 == 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
if( ii == 0 && cc1 != 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( tROW > sROW && tROW - sROW > 2  ){
for (i=sROW+2;i<tROW;i++){
if( i%2!=0) continue;
if( TABLE[table[i]][sCOL][1] != "  " )
ii += 1;
if( ii > 1 )
return notify_fail("这个棋子不能移动到那个地方。\n");
if( ii == 1 && cc1 == 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
if( ii == 0 && cc1 != 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}

if( sROW > tROW && sROW - tROW > 2 ){
for (i=tROW+2;i<sROW;i++){
if( i%2!=0) continue;
if( TABLE[table[i]][sCOL][1] != "  " )
ii += 1;
if( ii > 1 )
return notify_fail("这个棋子不能移动到那个地方。\n");
if( ii == 1 && cc1 == 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
if( ii == 0 && cc1 != 0 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
}

//兵
if( che == 7 ){
if( tCOL - sCOL > 2 || tCOL - sCOL < -2 ||
tROW - sROW > 2 || tROW - sROW < -2 )
return notify_fail("兵一次只能走一格。\n");
if( tCOL != sCOL && sROW != tROW )
return notify_fail("这个棋子只能走直线。\n");
if( cc == 1 ){
if( sROW > tROW ) return notify_fail("兵不能往回走。\n");
if( tCOL != sCOL && sROW < 9 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
if( cc == 2 ){
if( sROW < tROW ) return notify_fail("兵不能往回走。\n");
if( tCOL != sCOL && sROW > 9 )
return notify_fail("这个棋子不能移动到那个地方。\n");
}
}

if ( TABLE[table[tROW]][tCOL][2] != 0 ){
msg1 += "$N吃掉了对手一个" + sprintf("%s。\n",TABLE[table[tROW]][tCOL][1]);
if( cc1 == 1 )
bche+=TABLE[table[tROW]][tCOL][1];
else
rche+=TABLE[table[tROW]][tCOL][1];
}

if ( TABLE[table[tROW]][tCOL][2] == 5 ){
msg1 += HIW"$n叹了口气，说道：“棋差一着，满盘皆输，这当真是天意吗？”\n"NOR;
msg1 += HIY"棋局结束，$N赢得了这场对弈的胜利！\n"NOR;
ob->set("over",this_player()->name());
ob->set("end_time", time());
this_player()->add("c_chess/win",1);
target->add("c_chess/lose",1);
}

	TABLE[table[tROW]][tCOL][1] = TABLE[table[sROW]][sCOL][1];
TABLE[table[tROW]][tCOL][2] = TABLE[table[sROW]][sCOL][2];
TABLE[table[tROW]][tCOL][3] = TABLE[table[sROW]][sCOL][3];
	TABLE[table[sROW]][sCOL][1] = "  ";
TABLE[table[sROW]][sCOL][2] = 0; 
TABLE[table[sROW]][sCOL][3] = 0; 

tem4 = 0;
	for( y=0;y<6;y++ ){
if( y%2 != 0 ) continue;
		for( x=6;x<12;x++ ) {
if( x%2 != 0 ) continue;
			if( TABLE[table[y]][x][2] == 5 ){
tem = x;
tem3 = y;
break;
		}
}
}

	for( y=14;y<19;y++ ){
if( y%2 != 0 ) continue;
		for( x=6;x<12;x++ ) {
if( x%2 != 0 ) continue;
			if( TABLE[table[y]][x][2] == 5 ){
tem1 = x;
tem2 = y;
break;
}
		}
}

if( tem == tem1 ){
for (i=tem3+2;i<tem2;i++){
if( i%2!=0) continue;
if( TABLE[table[i]][tem][1] != "  " )
tem4 = 1; 
}
if( tem4 == 0 ){
	msg1 += HIR"王见王，死棋！\n"NOR;
	msg1 += HIY"棋局结束，$n赢得了这场对弈的胜利！\n"NOR; 

ob->set("over", ob->query("name1") == me->name()?ob->query("name2"):
ob->query("name1") );
ob->set("end_time", time());
target->add("c_chess/win",1);
this_player()->add("c_chess/lose",1);
}


}

	if( sROW == tROW )
if( cc1 == 2 )
		msg = sprintf("『%s』%s平%s",
					TABLE[table[tROW]][tCOL][1],
					chinese_number(10-(sCOL/2+1)),
					chinese_number(10-(tCOL/2+1)) );
else
		msg = sprintf("『%s』%s平%s",
					TABLE[table[tROW]][tCOL][1],
					chinese_number(sCOL/2+1),
					chinese_number(tCOL/2+1) );

	else 
if( cc1 == 2 ) //t先 s後 row横
		if( sROW>tROW )
			msg = sprintf("『%s』%s进%s",
TABLE[table[tROW]][tCOL][1],
			chinese_number(10-(sCOL/2+1)),
			sCOL==tCOL?chinese_number( 10-((sROW-tROW)/2) ):chinese_number(10-(tCOL/2+1)) );
		else
			msg = sprintf("『%s』%s退%s",
			TABLE[table[tROW]][tCOL][1],
			chinese_number(10-(sCOL/2+1)),
			sCOL==tCOL?chinese_number( 10-((tROW-sROW)/2) ):chinese_number(10-(tCOL/2+1)) );

else 
		if( tROW>sROW )
			msg = sprintf("『%s』%s进%s",
TABLE[table[tROW]][tCOL][1],
			chinese_number(sCOL/2+1),
			sCOL==tCOL?chinese_number( (tROW-sROW)/2 ):chinese_number(tCOL/2+1) );
		else
			msg = sprintf("『%s』%s退%s",
			TABLE[table[tROW]][tCOL][1],
			chinese_number(sCOL/2+1),
			sCOL==tCOL?chinese_number( (sROW-tROW)/2 ):chinese_number(tCOL/2+1) );

	message_vision( "$N下了一着"+msg+"\n",this_player());

	if(target->query_temp("pending/draw_chess") == me) {
       		message("vision", "看来"+ me->name() + "无意以和局结束对弈。\n", environment(me), me);
		target->delete_temp("pending/draw_chess");
	}
	message_vision( msg1,me, target);

do_check();

aa += 1;

if( !ob->query("start_time") ) ob->set("start_time", time());

if( aa >= 5 && aa/5*5 == aa ){
aaa += msg+"\n"; 
} else {
aaa += msg+" ";
}

ob->query("round") == 1?ob->set("round",0):ob->set("round",1);
return 1;
}

int do_toss() {
	int num;
	string text;
object me, ob;
me = this_player();
ob = this_object();

if( ob->query("name2") )
return notify_fail("已经有两个人在下棋了。\n");

if( me->name() == ob->query("name1") )
return notify_fail("你已经投过一次骰子了。\n");

	num = random(6);

if( ob->query("num") == num )
	num = random(6);

	text = "拿起骰子在手中摇了两摇, 掷出了一个：\n";
	text += tossText[6]+tossText[num]+tossText[7];
	message_vision( "$N"+text,me );

if( ob->query("name1") ){
ob->query("num")>num?ob->set("first",ob->query("name1"))
:ob->set("first",me->name());
	message_vision( ob->query("first")+"使用红色棋子先行。\n",me );
}

ob->set("num",num);
ob->query("name1")?ob->set("name2",me->name()): ob->set("name1",me->name());
ob->query("id1")?ob->set("id2",me->query("id")):ob->set("id1",me->query("id"));

	return 1;
}

int do_draw() {

object me, target, ob;
me = this_player();
ob = this_object();

if( me->query("id") == ob->query("id1")) target = find_player(ob->query("id2"));
 else target = find_player(ob->query("id1"));

if( ob->query("over") ) return notify_fail("这盘棋已经结束了。 \n");

if( me->name() != ob->query("name1") && me->name() != ob->query("name2") )
return notify_fail("你是局外人，还是专心看棋吧！\n");

if(aa < 30)
return notify_fail("才下这麽几步棋，就要提议和局了？\n"); 

if( ob->query("round") == 0 && ob->query("first") == me->name() && (object)target->query_temp("pending/draw_chess") != me)
return notify_fail("你必需在走完一步棋後才能提议和局。\n");

if( ob->query("round") == 1 && ob->query("first") != me->name() && (object)target->query_temp("pending/draw_chess") != me)
return notify_fail("你必需在走完一步棋後才能提议和局。\n");

if( !(present(ob->query("id1"),environment(ob))) || 
!(present(ob->query("id2"),environment(ob))) )
return notify_fail("要在双方都在场时才能走棋。\n");

	if( (object)target->query_temp("pending/draw_chess") != me ) {
	message_vision("$N对$n说道："+ RANK_D->query_respect(target) + "弈道超群，"+RANK_D->query_self(me)+"佩服之至。你我棋逢对手，这局祗怕难分胜负，不如便算和局如何？\n",me,target);
	me->set_temp("pending/draw_chess", target);
	tell_object(target, YEL"如果你赞成和局结束，请你也下一次draw指令。\n"NOR );
	write(YEL "由于对方是由玩家控制的人物，必须等对方同意，此局对弈才会和局结束。\n" NOR);
	}
	else {
	message_vision("$N一推棋盘，说道：好，便依"+ RANK_D->query_respect(target) + "所言，这局不分胜败。\n",me,target);
	message_vision(HIY"\n$N和$n的对弈结束了，双方议定和局。\n"NOR,me, target);
	me->delete_temp("pending/draw_chess");
	target->delete_temp("pending/draw_chess");
	ob->set("over", "drawn_game" );
	ob->set("end_time", time());
	target->add("c_chess/draw",1);
	me->add("c_chess/draw",1);
	}

	return 1;
}

string long(){
	int row,col,i;
	string text,round,msg;
object me ,ob;
ob = this_object();
me = this_player();
	text = "\n1   2   3   4   5   6   7   8   9\n";
msg = ob->query("name1")==ob->query("first")?ob->query("name2"):ob->query("name1");

if( ob->query("name2") ){
if( ob->query("over") == "drawn_game")
round = " 这盘棋是和局收场。";
else if( ob->query("over") )
round = " 这盘棋"+ob->query("over")+"赢了。";
else if( ob->query("round") == 1 )
round = " 现在轮到"+HIC"蓝子"NOR+"走子";
else
round = " 现在轮到"+HIR"红子"NOR+"走子";
TABLE[table[9]][0][1] = sprintf("%s%s",TABLE[table[9]][0][0],round );
}

if( me->name() != ob->query("first") ){
TABLE[table[17]][0][1] = "┃";
TABLE[table[3]][0][1] = "┃";
TABLE[table[5]][0][1] = "┃";
TABLE[table[13]][0][1] = "┃";
TABLE[table[15]][0][1] = "┃";
TABLE[table[0]][0][0] = "┌";
TABLE[table[10]][0][0] = "┌";
TABLE[table[0]][16][0] = "┐";
TABLE[table[10]][16][0] = "┐";
TABLE[table[18]][16][0] = "┘";
TABLE[table[8]][16][0] = "┘";
TABLE[table[8]][0][0] = "└";
TABLE[table[18]][0][0] = "└";
TABLE[table[2]][16][0] = TABLE[table[4]][16][0]
= TABLE[table[6]][16][0] = TABLE[table[12]][16][0]
= TABLE[table[14]][16][0] = TABLE[table[16]][16][0]
= "┤";
TABLE[table[2]][0][0] = TABLE[table[4]][0][0]
= TABLE[table[6]][0][0] = TABLE[table[12]][0][0]
= TABLE[table[14]][0][0] = TABLE[table[16]][0][0]
= "├";

TABLE[table[1]][16][1] = "┃ 如有问题，请参看“help c_chess”";
TABLE[table[15]][16][1] = sprintf("%s%s%s",TABLE[table[15]][16][0]," ",bche );
TABLE[table[5]][16][1] = sprintf("%s%s%s",TABLE[table[5]][16][0]," ",rche );

if( ob->query("name2") ){
TABLE[table[3]][16][1] = sprintf("%s%s%s","┃"," ("+ob->query("first")+") ",HIR"红方"NOR+"所吃棋子：" );
TABLE[table[13]][16][1] = sprintf("%s%s%s","┃"," ("+msg+") ",HIC"蓝方"NOR+"所吃棋子：" );
}

for( i=2;i<16;i++){
if( i%2!=0) continue;
TABLE[table[8]][i][0] = "┴";
TABLE[table[10]][i][0] = "┬";
TABLE[table[18]][i][0] = "┴";
TABLE[table[0]][i][0] = "┬";
}

	for( row=0; row<sizeof(table); row++ ) {
		for( col=0; col<sizeof(TABLE[table[row]]); col++ ) {
			if( TABLE[table[row]][col][1] == "  " )
				text += sprintf("%s", TABLE[table[row]][col][0] );
			else
				text += sprintf("%s", TABLE[table[row]][col][1] );
		}
		if( row%2 == 0)
			text += sprintf(" %d", row/2 );
		text += "\n";
	}
} else {
	text = "\n9   8   7   6   5   4   3   2   1\n";
TABLE[table[1]][16][1] = "┃";
TABLE[table[3]][16][1] = "┃";
TABLE[table[5]][16][1] = "┃";
TABLE[table[13]][16][1] = "┃";
TABLE[table[15]][16][1] = "┃";
TABLE[table[0]][0][0] = "┘";
TABLE[table[18]][16][0]= "┌";
TABLE[table[0]][16][0] = "└";
TABLE[table[18]][0][0] = "┐";
TABLE[table[8]][16][0] = "┌";
TABLE[table[10]][16][0] = "└";
TABLE[table[2]][16][0] = TABLE[table[4]][16][0]
= TABLE[table[6]][16][0] = TABLE[table[12]][16][0]
= TABLE[table[14]][16][0] = TABLE[table[16]][16][0]
= "├";
TABLE[table[10]][0][0] = "┚";
TABLE[table[8]][0][0] = "┐";
TABLE[table[2]][0][0] = TABLE[table[4]][0][0]
= TABLE[table[6]][0][0] = TABLE[table[12]][0][0]
= TABLE[table[14]][0][0] = TABLE[table[16]][0][0]
= "┤";

TABLE[table[17]][0][1] = "┃ 如有问题，请参看“help c_chess”";
TABLE[table[13]][0][1] = sprintf("%s%s%s",TABLE[table[15]][16][0]," ",bche );
TABLE[table[3]][0][1] = sprintf("%s%s%s",TABLE[table[5]][16][0]," ",rche );

if( ob->query("name2") ){
TABLE[table[5]][0][1] = sprintf("%s%s%s","┃"," ("+ob->query("first")+") ",HIR"红方"NOR+"所吃棋子：" );
TABLE[table[15]][0][1] = sprintf("%s%s%s","┃"," ("+msg+") ",HIC"蓝方"NOR+"所吃棋子：" );
}

for( i=2;i<16;i++){
if( i%2!=0) continue;
TABLE[table[8]][i][0] = "┬";
TABLE[table[10]][i][0] = "┴";
TABLE[table[18]][i][0] = "┬";
TABLE[table[0]][i][0] = "┴";
}

	for( row=(sizeof(table)-1); row>-1; row-- ) {
		for( col=(sizeof(TABLE[table[row]])-1); col>-1; col-- ) {
			if( TABLE[table[row]][col][1] == "  " )
				text += sprintf("%s", TABLE[table[row]][col][0] );
			else
				text += sprintf("%s", TABLE[table[row]][col][1] );
		}
		if( row%2 == 0)
			text += sprintf(" %d", row/2 );
		text += "\n";
	}
}
	return text;
}
void do_check(){
int x,y,tem,tem1,i,tem3,check;
object ob = this_object();
check = 0;

if( ob->query("over") ) return;

if( ob->query("round") == 1 )
	for( y=0;y<5;y++ ){
if( y%2 != 0 ) continue;
		for( x=6;x<11;x++ ) {
if( x%2 != 0 ) continue;
			if( TABLE[table[y]][x][2] == 5 ){
tem = x;
tem1 = y;
break;
		}
}
}
else
	for( y=14;y<19;y++ ){
if( y%2 != 0 ) continue;
		for( x=6;x<11;x++ ) {
if( x%2 != 0 ) continue;
			if( TABLE[table[y]][x][2] == 5 ){
tem = x;
tem1 = y;
break;
}
		}
}

if( tem1 < 9 )
if( TABLE[table[tem1+2]][tem][2] == 7 &&
TABLE[table[tem1+2]][tem][3] != TABLE[table[tem1]][tem][3] )
check = 1;

if( tem1 > 9 )
if( TABLE[table[tem1-2]][tem][2] == 7 && 
TABLE[table[tem1-2]][tem][3] != TABLE[table[tem1]][tem][3] )
check = 1;

if( TABLE[table[tem1]][tem+2][2] == 7 )
check = 1;

if( TABLE[table[tem1]][tem-2][2] == 7 )
check = 1;


tem3 = 0;
for (i=tem+2;i<17;i++){
if( i%2!=0) continue;
if( tem3 == 1 && TABLE[table[tem1]][i][2] == 6 )
if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if( TABLE[table[tem1]][i][2] == 1 && tem3 == 0 )
if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if(  TABLE[table[tem1]][i][2] != 0 )
tem3 += 1;
}

tem3 = 0;
for (i=tem-2;i>-1;i--){
if( i%2!=0) continue;
if( tem3 == 1 && TABLE[table[tem1]][i][2] == 6 )
if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if( TABLE[table[tem1]][i][2] == 1 && tem3 == 0 )
if( TABLE[table[tem1]][i][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if(  TABLE[table[tem1]][i][2] != 0 )
tem3 += 1;
}

tem3 = 0;
for (i=tem1-2;i>-1;i--){
if( i%2!=0) continue;
if( tem3 == 1 && TABLE[table[i]][tem][2] == 6 )
if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if( TABLE[table[i]][tem][2] == 1 && tem3 == 0 )
if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if(  TABLE[table[i]][tem][2] != 0 )
tem3 += 1;
}

tem3 = 0;
for (i=tem1+2;i<19;i++){
if( i%2!=0) continue;
if( tem3 == 1 && TABLE[table[i]][tem][2] == 6 )
if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if( TABLE[table[i]][tem][2] == 1 && tem3 == 0 )
if( TABLE[table[i]][tem][3] != TABLE[table[tem1]][tem][3] ){
check = 1;
break;
}
if(  TABLE[table[i]][tem][2] != 0 )
tem3 += 1;
}

if( tem1 > 1 ){
if( TABLE[table[tem1-2]][tem-2][2] == 0 ){
if( tem1 > 2 )
if( TABLE[table[tem1-4]][tem-2][2] == 2 && 
TABLE[table[tem1-4]][tem-2][3] != TABLE[table[tem1]][tem][3] )
check = 1;

if( TABLE[table[tem1-2]][tem-4][2] == 2 && TABLE[table[tem1-2]][tem-4][3] != 
TABLE[table[tem1]][tem][3] )
check = 1;
}

if( TABLE[table[tem1-2]][tem+2][2] == 0 ){
if( tem1 > 2 )
if( TABLE[table[tem1-4]][tem+2][2] == 2 && 
TABLE[table[tem1-4]][tem+2][3] != TABLE[table[tem1]][tem][3] )
check = 1;

if( TABLE[table[tem1-2]][tem+4][2] == 2 && TABLE[table[tem1-2]][tem+4][3] != 
TABLE[table[tem1]][tem][3] )
check = 1;
}
}

if( tem1 < 17 ){
if( TABLE[table[tem1+2]][tem-2][2] == 0 ){
if( tem1 < 16 )
if( TABLE[table[tem1+4]][tem-2][2] == 2 && 
TABLE[table[tem1+4]][tem-2][3] != TABLE[table[tem1]][tem][3] )
check = 1;

if( TABLE[table[tem1+2]][tem-4][2] == 2 && TABLE[table[tem1+2]][tem-4][3] != 
TABLE[table[tem1]][tem][3] )
check = 1;
}

if( TABLE[table[tem1+2]][tem+2][2] == 0 ){
if( tem1 < 16 )
if( TABLE[table[tem1+4]][tem+2][2] == 2 && 
TABLE[table[tem1+4]][tem+2][3] != TABLE[table[tem1]][tem][3] )
check = 1;

if( TABLE[table[tem1+2]][tem+4][2] == 2 && TABLE[table[tem1+2]][tem+4][3] != 
TABLE[table[tem1]][tem][3] )
check = 1;
}
}

if( check ) message_vision("$N说道："+HIG"“将军！！”\n"NOR,this_player() ); 

}

int do_save()
{
bb = 1;
save();
write("棋局记录完毕。\n");
return 1;
}

int do_deploy()
{
object me,ob;
me = this_player();
ob = this_object();
bb = 1; 

if( ob->query("id1") )
if( (present(ob->query("id1"),environment(ob))) || 
(present(ob->query("id2"),environment(ob))) )
if( me->name() != ob->query("name1") && me->name() != ob->query("name2") && !ob->query("over") )
return notify_fail("比赛还在进行中，你不能乱动棋盘！\n"); 

if( !restore() ) return notify_fail("你目前没有纪录的残局。\n");

setup();
message_vision("$N凝思一阵，摆出了一个残局。\n",this_player());
ob->delete("start_time");  //重新计时
write("这局棋会在走棋後重新计时。\n");
write("OK！\n");
return 1;
}

int do_lose()
{
object ob,me,target;
ob = this_object();
me = this_player();

if( me->name() != ob->query("name1") && me->name() != ob->query("name2") )
return notify_fail("你并没有在下棋。\n"); 

if( ob->query("over") )
return notify_fail("这盘棋已经结束了。\n"); 

if( bche == "" && rche == "" )
return notify_fail("这样就认输了?\n"); 

if( me->query("id") == ob->query("id1")) target = find_player(ob->query("id2"));
 else target = find_player(ob->query("id1"));

message_vision(HIW"$N长叹一声：“...我输了！...”\n"NOR,this_player());
message_vision(HIY"因为$N认输，$n赢得了这场对弈的胜利。\n"NOR,me, target);
ob->set("over", ob->query("name1") == me->name()?ob->query("name2"):
ob->query("name1") );
ob->set("end_time", time());
target->add("c_chess/win",1);
this_player()->add("c_chess/lose",1);
return 1;
}

int do_review()
{
int t, mm, d, h, m, s;
string time, msg;

if(aa <= 0)
return notify_fail("这盘棋还没有人动过棋。\n"); 

if(this_object()->query("start_time")) {

	t = time() - this_object()->query("start_time");
	s = t % 60;	     t /= 60;
	m = t % 60;	     t /= 60;
	h = t % 24;	     t /= 24;
	d = t % 30;	     t /= 30;
	mm = t;

	if(mm) time = chinese_number(mm) + "月";
	else time = "";

	if(d) time += chinese_number(d) + "天";
	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	write("棋局进行时间："+time+"。\n");
}

write("这局棋下了"+chinese_number(aa)+"着棋路：\n");
write(aaa+"\n");
return 1;
}


int do_reset(){
object ob, me, obj;
me = this_player();
ob = this_object();
bb = 0;

if ( ( ob->query("id2") ) 
&& ((present(ob->query("id1"),environment(ob))) || (present(ob->query("id2"),environment(ob))))
&& ( me->name() != ob->query("name1") && me->name() != ob->query("name2") && !ob->query("over") ) )

return notify_fail("比赛还在进行中，你不能乱动棋盘！\n"); 
else {

message_vision("$N重新摆了一个棋局。\n",this_player());

obj = new(base_name(ob));
obj->move(environment(ob));
obj->set("startroom", base_name(environment(ob)));
destruct(this_object());

}
return 1;
}
