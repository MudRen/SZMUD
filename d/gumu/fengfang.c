// July 31,2000
// Code by April
// /gumu/fengfang.c
// update April 2001.11.09

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","玉蜂房");

	set("long",@LONG
这是一间巨大的石室，几十个玉蜂箱整齐地摆满了整个石室。几个古
墓派弟子在这里辛勤劳作。玉蜂喜阴，室顶有几个黑黝黝的出口供玉蜂进
出。
LONG);

	set("exits",([ 
		"north" : __DIR__"mudao15",
		]));

	set("objects", ([
		"/kungfu/class/gumu/npc/sun" : 1,
		]));

	set("cost",1);

	setup();
}

void init()
{
	add_action("do_gua","gua");
}

int do_gua(string arg)
{
	object me = this_player();
	object *inv;	// 身上带的东西
	int i;
	int has_ping,has_box,mi_full,has_jiang,ping_empty_num;
	int mi_left,jiang_left;
	object ping,box;

	if ( me->query("family/family_name") != "古墓派" ) return 0;

	if( !arg || arg == "" ) return 0;

	if( arg != "mi" && arg !="box" && arg !="beehive" && arg!= "box") 
		return notify_fail("你要刮什么？\n");

	has_ping=0;
	has_box=0;
	mi_full=0;
	mi_left=0;
	has_jiang=0;
	ping_empty_num=0;
	jiang_left=0;

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++){
		if( inv[i]->query("name") == CYN"青瓷瓶"NOR ){
			has_ping =1;
			if (inv[i]->query("liquid/remaining") <= 0)
				ping_empty_num += 1;
		}
		if( inv[i]->query("name") == HIW"玉蜂箱"NOR ){
			has_box =1;
			if (inv[i]->query("mi_lvl") >= 2){
				box = inv[i];
				mi_full = 1;
			}
		}
	}
	if (!has_box) return notify_fail("你的玉蜂箱呢。\n");
	if (!mi_full) return notify_fail("你玉蜂箱里的玉蜂蜜还没采够呢！\n");
	if (!has_ping) return notify_fail("你需要青瓷瓶来装玉蜂蜜。\n");
	if (!ping_empty_num) return notify_fail("你需要空瓶装玉蜂蜜。\n");

	mi_left = box->query("mi_lvl")/2;
	if ( mi_left/10*10 == mi_left ){
		if ( (mi_left/10) > ping_empty_num ) 
			return notify_fail("你仔细检查了一下青瓷瓶，发现空瓶数目不够。\n");
	}
	else if ( (mi_left/10 + 1) > ping_empty_num ) 
		return notify_fail("你仔细检查了一下青瓷瓶，发现空瓶数目不够。\n");

	if ( me->query_skill("bee-training",1) > 60 && mi_left >= 10 ) {
		jiang_left = (mi_left - 10)/2 + 25;
		if ( me->query_skill("bee-training",1) > 90 ) 
			jiang_left += me->query_skill("bee-training",1) - 90;
		if ( random(100) < jiang_left ){
			jiang_left = 10;
			has_jiang = 1;
		}
		else {
			jiang_left = 0;
			has_jiang = 0;
		}
	}

	if ( has_jiang ) mi_left -= 10;
	for(i=0; i<sizeof(inv); i++){
		if( inv[i]->query("name") == CYN"青瓷瓶"NOR ){
			if (!inv[i]->query("liquid/remaining")){
				if( mi_left ){
					if( mi_left >= 10 ){
						inv[i]->set("liquid/remaining",10);
						mi_left -= 10;
					}
					else {
						inv[i]->set("liquid/remaining",mi_left);
						mi_left = 0;
					}
					inv[i]->set("liquid/name","玉蜂蜜");
				}
				else if( jiang_left ){
					if( jiang_left >= 10){
						inv[i]->set("liquid/remaining",10);
						jiang_left -= 10;
					}
					else {
						inv[i]->set("liquid/remaining",mi_left);
						jiang_left = 0;
					}
					inv[i]->set("liquid/name","玉蜂王浆");
				}
			}
		}
	}

	message_vision("$N慢慢打开玉蜂箱的盖子。\n", me);
	message_vision("$N慢慢抽出一排装满玉蜂蜜的木板。\n", me);
	message_vision("$N慢慢刮下玉蜂蜜装入青瓷瓶。\n", me);
	if ( has_jiang ) {
		message_vision("$N小心翼翼地刮下玉蜂王浆装入青瓷瓶。\n", me);
		message_vision("$N拿了一只空玉蜂箱，小心翼翼将玉蜂分群。\n", me);
		if ( box->query_amount() < 5 ) {
//		if ( box->query_amount() < 4 
//			|| ( box->query_amount() == 4 && me->query("combat_exp") < 500000 ) ){
			box->set_amount(box->query_amount() + 1);
			me->add_temp("bee_count",1);
			me->add("bee_count",1);
		}
		else message_vision("$N把新玉蜂箱留在蜂房。\n", me);
	}
	message_vision("$N把玉蜂箱恢复原状。\n", me);
	
	box->set("mi_lvl",0);

	return 1;
}