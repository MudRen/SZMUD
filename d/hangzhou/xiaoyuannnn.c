// Code of ShenZhou
// /d/hangzhou/xiaoyuane.c
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{       set("short", "СԺ");
        set("long", @LONG
�������ھֵĺ�Ժ�������ķſͻ����ڻ���ƽʱ���ű�������ͷ����������  
�е�ȥ����Ҳ�������ĳ������������ͷ��������ٷ���˼�����ɮ��ָ���ھ���  
���ºü����˵��书��������Ե�������֣�ʱ��ͨ���ﵩ��
LONG);
        set("exits", ([ /* sizeof() == 3 */ 
                "south" : __DIR__"xiaoyuannn",
        ]));

        set("objects", ([
                __DIR__"npc/zhu" : 1,
        ]));

	set("cost", 1);

        set("outdoors", "hangzhou");
        setup();
}

/*
void init()
{
        object me = this_player();
        int cost;

        if( me->query_condition("lmjob") && interactive(me) ) {
                cost = 20000 / ( (int)me->query_con() + 2 * (int)me->query("int") );
                me->receive_damage("jing", cost + random(cost));
                me->receive_damage("jingli", cost + random(cost));

                message_vision("\n��λ��ͷ��ǰ��$N�������ȿֺ����$N����书��\n", this_player());
                me->start_busy(1 + random(cost/10));
        }
        add_action("do_dazuo", "dazuo");
}

int do_dazuo(string arg)
{
        object me = this_player();
        mixed busy;

        if( busy = me->query_busy() ) {
                if (intp(busy)) me->start_busy(busy+1);
                return notify_fail("��������æ�ţ�\n");
        }

        return 0;
}

int valid_leave(object me, string dir)
{
        if( me->query_condition("lmjob") ) {
                me->apply_condition("lmjob", 0);
                me->delete_temp("lmjob");
                message_vision("\n$N�����Ե���ͷ��˵�������е㼱�£��´��ٽ����ǰɡ�\n", me);
        }

        return ::valid_leave(me, dir);
}
*/
