// Code of ShenZhou
// Room: zoulang.c ����
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "����");
    set("long", @LONG
���ȶ���ľ�ź����Ż�ɽ�е��ӵ���Ϣ�ң������ź���Ů���ӵ���Ϣ
�ҡ��ϱ��ǻ�ɽ���ŵ����ң����ӽԲ�׼��ȥ���������ǿ�����
LONG
    );

    set("exits", ([
	"east" : __DIR__"nanshi",
	"west" : __DIR__"nushi",
	"south" : __DIR__"buwei2",
	"north" : __DIR__"zoulang1",
    ]));

    set("objects", ([
        CLASS_D("huashan") + "/dayou" : 1,
    ]));

    create_door("east", "ľ��", "west", DOOR_CLOSED);
    create_door("west", "ľ��", "east", DOOR_CLOSED);	

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir != "south" ) {
	if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir != "north" )
	   return notify_fail("��ɽ������ͣ��㲻��ס�����\n");
    }

    if ( me->query("gender") == "����" && dir == "west" && !wizardp(me) )
	return notify_fail("������㣬�е�����Ϣ���ڶ��ߣ�\n");

    if ( me->query("gender") == "Ů��" && dir == "east" && !wizardp(me) )
	return notify_fail("������㣬Ů������Ϣ�������ߣ�\n");

    if ( me->query("gender") == "����" && (dir=="east" || dir=="west") )
	return notify_fail("�㲻��ס�����\n");

    if (dir == "south" && objectp(present("lu dayou", environment(me))))
	return notify_fail("½���кȵ���������ʦ�������ң���λ"+RANK_D->query_respect(me)+"��ֹ����\n");

    return ::valid_leave(me, dir);
}
