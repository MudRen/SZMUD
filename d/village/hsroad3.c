// Code of ShenZhou
// wdroad3.c
// by Xiang
// Modified by qfy August 24, 96

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "����·");
	set("long", @LONG
һ���ӿ����ݵ���·������������ͨ��ɽ������Ǹ߼�����Ĳ�ԭ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : "/d/emei/emroad6",
		"north" : __DIR__"sexit",
	]));

	set("cost", 1);
	setup();
//	replace_program(ROOM);
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
        if (j>0) me->set_temp("rob_victim", 1);

        if ( interactive(ob=this_player()) && ob->query_temp("biao/ma")
        && present("hong biao", ob) && random(5)==1
	|| me->query_temp("rob_victim") && random(3)==1) {
                message_vision(HIR"ֻ����һ�󲥲�����һ���ݿ��Բݶ������˳�����ס$N��\n"NOR, ob);
		robber = new(__DIR__"npc/caokou");
                robber->move(environment(ob));
        }
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("biao/li") && present("cao kou", environment(me)) 
	|| me->query_temp("rob_victim") && present("cao kou", environment(me)))
		return notify_fail("�ݿ�����һ����Ц��ˬ��Ľ���������������Ȼ������Ī����\n");
	else { me->delete_temp("rob_victim"); }

	return ::valid_leave(me, dir);
}
