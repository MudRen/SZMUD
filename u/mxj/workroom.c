// Room Of Mxj
// have a good day
// Room Of Mxj
// have a good day

#include <ansi.h>  
inherit ROOM; 

void create()
{
set("short",HIM"桃花园"NOR);
set ("long",  
"


   这里是马冥风的"HIM"桃花园"NOR"，他每天每夜都在这里思想著"HIC"桃花岛"NOR"的更新和
"HIC"桃花岛"NOR"的发展。这里清雅脱族，和凡间完全是两个世界。这里有几条密道
通往不同的地方。
"
);

set("exits", ([ 
"gyz" : "/d/taihu/shufang",
"kd" : "/d/city/kedian",  
"th" : "/d/taohua/hyjuchu",
"wiz" : "/d/wizard/wizard_room",
"thxx" : "/u/mxj/th_room",
])); 
call_other("/clone/board/mxj_b.c", "???"); 
set("valid_startroom",1); 
set("no_fight",1); 

set("objects", ([
// "/d/taohua/obj/tiexiao" : 1,
// "/d/taohua/obj/zhuxiao" : 1,
"/d/taohua/obj/bagua" : 1,
"/u/mxj/tongxiao" : 1,
"/clone/weapon/changbian" : 1,
"/u/mxj/shizi" : 5,
]));

setup();
}

void init()
{
	add_action("do_qu","qu");
   	
}

int do_qu()
{
	object ob;
	object me = this_player();
	ob = new("/clone/money/gold");
	ob->set_amount(200);
	ob->move("/u/mxj/workroom");
	message_vision(
    		"$N默默念了一段咒语，地上突然出现了一大堆"HIY"黄金"NOR"！\n", me);
	return 1;	
}	
