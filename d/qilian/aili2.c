// Code of ShenZhou
// Summer 9/12/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()

{
        set("short", "������");
        set("long", @LONG
������һ����ɳ��̧����ȥ����ããһƬɳĮ�����޾�ͷ��ֱ����ߣ�
һ������̤�룬��ʯţ�뺣����ʧ����Ӱ�����ˣ��ɹ����Ϊ��������
LONG
        );
        set("exits", ([
                "north" : __DIR__"aili3",
                "west" : __DIR__"aili",
		"south" : __DIR__"aili3",
		"east" : __DIR__"aili3",
        ]));


        set("outdoors","qilian-shan");
	set("cost", 5);
        setup();
}
int valid_leave(object me, string dir)
{
	if( random((int)me->query_skill("dodge")) <= 5)
	{
		me->receive_wound("qi", 300, "����ɳ������");
		message_vision(HIY"$N�����ӱ���ɳ��ס�ˡ� \n"NOR, me);
	}
        else {
                me->receive_damage("qi", 200, "����ɳ������");
                me->receive_wound("qi",  100, "����ɳ������");
                message_vision(HIY"$N��˫�����������ݽ���ɳ�\n"NOR, me );
	}
	return ::valid_leave(me, dir);
} 
