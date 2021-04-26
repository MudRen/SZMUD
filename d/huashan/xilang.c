// Code of ShenZhou
// Room: xilang.c ����
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "����");
    set("long", @LONG
�������ߴ������󷹲����������ʿ�֪�Ƕ����ǻ�ɽ�ɵĳ���������
��ɽ�������˸߲��ҵ�̸�����Լ��ķ��ʷ�������еļ������¡����м�
��Ů������æ�������ղˡ�
LONG
    );

    set("exits", ([
	"east" : __DIR__"huayuan",
	"west" : __DIR__"chufang",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/lingshan" : 1,
    ]));

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");


    if (dir == "west" && objectp(present("yue lingshan", environment(me)))) {
	if ( !myfam || myfam["family_name"] != "��ɽ��")
	   return notify_fail("���������˵���������Ǳ��ɳ�����"+RANK_D->query_respect(me)+"����ǰ����衣\n");
    }

    return ::valid_leave(me, dir);
}
