// Code of ShenZhou
// tianshan: /d/xingxiu/shanjiao.c
// Jay 3/17/96
// Modified by qfy August 24, 1996.
// Ryu 5/10/1997

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
������Ǳ������������ˡ������ǹ�֮�⣬Ρ�����ɽ��ֱ�����죬
������ΰ��ãã��Ұ����İ������һƬ�д䣬���ڵ�����ӣ�����һ��
��ɫ�Ķд��������ӻء����ϣ��ǽ���ˮޡ�ݺᣬ�ִ�������һ����ɽ
�������Ϊ���롣�������������ľ۾������Ͻ����ޱߵ����������
��ɳĮ��
LONG
	);
	set("exits", ([
	    "west" : __DIR__"tianroad1",
	    "north" : __DIR__"nanmen",
	    "southwest" : __DIR__"nanjiang",
	    "southeast" : __DIR__"silk4",
]));
	set("no_clean_up", 0);
	set("outdoors", "xingxiuhai" );
	set("objects", ([
	__DIR__"npc/hasake" : 1,
	    __DIR__"npc/trader" : 1]));

	set("cost", 2);
	setup();
//      replace_program(ROOM);
}

void init()
{
	object ob, robber, *inv, me=this_player();
	int i, j=0;

	inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("value") >= 10000 
		&& !inv[i]->query("money_id")) j++;
	}
	
	if (me->query("family/family_name")!="������" && j>0)
	me->set_temp("rob_victim", 1);

	if ( interactive(ob=this_player()) && ob->query_temp("biao/bayi")
	&& present("hong biao", ob) && random(3)==1 
	|| me->query_temp("rob_victim") && random(5)==1) {
		message_vision(HIR"�����ţ�����һ�������ɵ������˳�������ס��$N��\n"NOR, ob);
		robber = new(__DIR__"npc/xxdizi");
		robber->move(environment(ob));
	}
}

int valid_leave(object me, string dir)
{
    int current_water;

    if ( me->query_temp("biao/bayi") && present("xingxiu dizi", environment(me)) 
	|| me->query_temp("rob_victim") && present("xingxiu dizi", environment(me)))
	return notify_fail("�����ɵ��Ӷ�ݺݵ���в�����콫����������������ȡ�㹷����\n");
	
    if (dir == "southwest") {

	if (!userp(me)) return 0;
	current_water = me->query("water");
	if (current_water==0) {
	}

	if (current_water>0 && current_water<20) {
	    me->set("water",0);
	}

	if (current_water>20) {
	    me->set("water",current_water-20);
	}
	return ::valid_leave(me, dir);
    }
	else { me->delete_temp("rob_victim"); }
	return ::valid_leave(me, dir);

}
