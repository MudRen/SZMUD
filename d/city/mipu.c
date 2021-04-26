// Code of ShenZhou
// Room: /city/mipu.c
// YZC 1996/11/13 
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ò����׼��˽�������������������������ά�ִ��򡣵�����ϰ����
�ڣ�ֻ��һ���������Ļ��������ͷ��һЩ�˴��ס���ҵı�����񶼺����ߣ�
�������Ե��޿��κΣ�ֻ��һ�ߴ����ף�һ��������߶�š����Ϸ�����һ������
(paizi)���򱱾Ϳ��Գ����̵����Ͻ����ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiangnanjie",
        ]));

        set("item_desc", ([
                "paizi" : "�����ڸ��������Ǽۣ���ÿ����ԭ���������ǰ���һ����\n",
        ]));

        set("objects", ([
                "/d/forest/npc/cl_mi" : 1,
                "/d/forest/npc/cl_huoji" : 1,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ling;

        if( me->query_temp("bangs/shoptime") ) {
                me->delete_temp("bangs/shoptime");
                me->set_temp("apply/short", 
                ({ HIR + "���ְ�" + "����"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
                if( ling = present("bang ling", me) )
                        ling->delete("job");
               message_vision("$N���˲�ע�⣬������š�\n", me);
        }

        return ::valid_leave(me, dir);
}

