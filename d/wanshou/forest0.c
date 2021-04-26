// Code of ShenZhou
// /d/wanshou/forest0.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��һƬ������ľï�ܣ�������գ������������ޱ��޼ʡ��ڰ�
�оͻ���ʲô����ͻ�������������ȥ�Ƶġ����������һƬ����
�ޱߡ������ڰ������ֲ���һ�󵨺����������ǸϿ��˳�ȥ�ĺá�
LONG
        );
        set("exits", ([
				"north" : __DIR__"forest"+(random(3)+1),
				"northeast" : __DIR__"shijie",
				"southdown" : __DIR__"shanjiao",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="northeast" ) {

            if (!myfam || myfam["family_name"] != "����ɽׯ"){
                return notify_fail("���������̫���ˣ��߲���ȥ��\n");
			}
        }
        return ::valid_leave(me, dir);
}

