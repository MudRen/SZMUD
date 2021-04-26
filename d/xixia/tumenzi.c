// Code of ShenZhou
// Room: /d/xixia/tumenzi.c

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "������");
	set("long", @LONG
������Ҳ����ǰפ���ĵط�����Χȫ��ɳĮ���м�һ��СС�����ޣ�������
���е��ص������ס������ǰ��������һ������ռ��������������Ϊ��Ӫ�ĳ�
���ӣ��޶�����
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shixiazi",
  "south" : __DIR__"weiwu",
]));
	setup();
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

        if ( interactive(ob=this_player())
        && me->query_temp("rob_victim") && random(3)==1) {

                message_vision(HIR"ͻȻһ���������ߵ��������˳�������ס��$N��\n"NOR, me);
	 robber = new(__DIR__"npc/mazei");
                robber->move(environment(ob));
        }
}
int valid_leave(object me, string dir)
{
        if ( me->query_temp("rob_victim") && present("ma zei", environment(me) ))
                return notify_fail("�����װͰ͵ؽе����Ŵ����㣬�콫������������ \n");
        else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}
