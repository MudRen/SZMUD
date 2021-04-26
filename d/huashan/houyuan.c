// Code of ShenZhou
// houyuan.c
// qfy June 14, 1997.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "��Ժ");
    set("long", @LONG
�����ǻ�ɽ�ɵĺ�Ժ�������ǻ�ɽ���ӵľ��Һ�����������ɽ������
��ɽ�����������վ��������������¡���������һ��С��Ժ���м�ɽС�أ�
��ɫ���ˣ����н�����԰����ɫ��
LONG
    );

    set("exits", ([
	"east" : __DIR__"xuanya",
	"west" : __DIR__"huayuan2",
	"south" : __DIR__"zoulang1",
	"north" : __DIR__"huayuan",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/dayou" : 1,
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

    if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir == "south" && !wizardp(me)
    && !me->query_temp("marks/bai_ning") && objectp(present("lu dayou", environment(me))) )
	return notify_fail("½���кȵ��������ǻ�ɽ�ɵ���Ժ����λ"+RANK_D->query_respect(me)+"��ֹ����\n");

    return ::valid_leave(me, dir);
}