// Room Of Mxj
// have a good day
// Room Of Mxj
// have a good day

#include <ansi.h>  
inherit ROOM; 

void create()
{
set("short",HIM"�һ�԰"NOR);
set ("long",  
"


   ��������ڤ���"HIM"�һ�԰"NOR"����ÿ��ÿҹ��������˼����"HIC"�һ���"NOR"�ĸ��º�
"HIC"�һ���"NOR"�ķ�չ�������������壬�ͷ�����ȫ���������硣�����м����ܵ�
ͨ����ͬ�ĵط���
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
    		"$NĬĬ����һ���������ͻȻ������һ���"HIY"�ƽ�"NOR"��\n", me);
	return 1;	
}	
