// Code of ShenZhou
// Room: donglang.c ����
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();
int valid_leave(object, string);

void create()
{
    set("short", "����");
    set("long", @LONG
�����ǻ�ɽ�ɵĲ����ң�ר����ɽ���Ӷ���д�֡�����һЩ���׺;�
�顣�������Ż�԰�������Ǹ�ƫ����
LONG
    );

    set("exits", ([
	"east" : __DIR__"shuyuan",
	"west" : __DIR__"huayuan",
	"north" : __DIR__"pianting",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/liangfa" : 1,
    ]));

    set("no_clean_up", 0);

    set("cost", 0);
    setup();
    //replace_program(ROOM);
}

void init()
{
	this_player()->delete_temp("possbooks");
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if (dir == "east" && objectp(present("liang fa", environment(me)))) {
	if ( !myfam || myfam["family_name"] != "��ɽ��" )
	   return notify_fail("������ס��˵���������Ǳ�����Ժ����λ"+RANK_D->query_respect(me)+"��������\n");

	if ( (int)me->query_temp("huashan/��") )
	   return notify_fail("������ס��˵�������������飬���Ȼ��Ҳ��������ã�\n");    
    }

    return ::valid_leave(me, dir);
}
