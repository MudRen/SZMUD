// Code of ShenZhou
// emroad2.c С·
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "С·");
        set("long", @LONG
�����Ĵ�������Ľ��硣һ�������ĵ�С��·�����������������ũ���
���·�����˺��٣����ҴҸ�·��
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"emroad3",
                "west" : __DIR__"emroad1",
        ]));

/*        set("objects", ([
                __DIR__"npc/xiao_tufei": 1,
        ]) );
*/
        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
}
void init()
{
        object ob, robber, *inv, me=this_player();
        int i, j=0;

/*
        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("value") >= 10000
                && !inv[i]->query("money_id"))
		{
			j++;
	if ( wizardp( me ) ) write( inv[i]->query( "id" ) + "\n" );
		}
        }
        if (j>0) me->set_temp("rob_victim", 1);

        if ( interactive(ob=this_player()) 
	&& me->query_temp("rob_victim") && random(5)==1) {

                message_vision(HIR"ͻȻһ���������ߵ��������˳�������ס��$N��\n"NOR, me);
                robber = new(__DIR__"npc/rob_tufei");
                robber->move(environment(ob));
        }
*/
}
int valid_leave(object me, string dir)
{
        if ( me->query_temp("rob_victim") && present("tu fei", environment(me) ))
                return notify_fail("�����װͰ͵ؽе����Ŵ����㣬�콫������������\n");
        else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}
