// Code of ShenZhou
// Room: /d/taishan/baihe.c
// Date: CSWORD 96/03/25
// Modified by qfy August 24, 96.

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "�׺�Ȫ");
	set("long", @LONG
�ഫ��ǰ������һ���׺�Ȫ������ˮ��������Ϊ̩ɽ֮���Ȫˮ����ӿ
�����ϣ������ˮ���ɺ������ų��ϴ��һ��������Ϊ������ϧ������һ����˽
������С�٣�������Ȫˮ�������������ŷ�ˮ֮˵����Ȫ�۶������׺�Ȫ�Ӵ˱�
�ɺ��ˡ�����ֻʣ��һ�����š��׺�Ȫ�����ֵ�ʯ����Ϊ���������������ϣ�
������ɽ֮·��
LONG
	);

	set("exits", ([
		"northup" : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));

	set("resource/water",1);
	set("outdoors", "taishan");
	set("cost", 4);
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
        && present("hong biao", ob) && random(3)==1
        || me->query_temp("rob_victim") && random(5)==1) {
                message_vision(HIR"ͻȻһ���󺺴�ʯ�������˳�����ס$N������һ��ɽ����\n"NOR, ob);
		robber = new(__DIR__"npc/shanzei");
                robber->move(environment(ob));
        }
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("biao/ma") && present("shan zei", environment(me) )
        || me->query_temp("rob_victim") && present("shan zei", environment(me)))
		return notify_fail("ɽ���������Ͽ콫��������������Ȼ��ͱ�ָ�������뿪��\n");
	else { me->delete_temp("rob_victim"); }

	return ::valid_leave(me, dir);
}
