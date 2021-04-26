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
���������ȵľ�ͷ���ϱ����ŵķ�������е��ӵ���Ϣ�ҡ�����ȴ��
һƬ�վ������¡�������ȥ�����������ƺ�֮�䣬�����ػ��󳩡�
LONG
    );

    set("exits", ([
	"west" : __DIR__"zoulang2",
	"south" : __DIR__"nanshi",
    ]));

    create_door("south", "ľ��", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
//    replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "Ů��" && dir == "south" && !wizardp(me) )
		return notify_fail("������㣬�����е�����Ϣ�ң�\n");

	return ::valid_leave(me, dir);
}