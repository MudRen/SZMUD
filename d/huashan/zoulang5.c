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
�������������ȵľ�ͷ���ϱߵķ����Ů���ӵ���Ϣ�ҡ�����Զ����
ȥ��һƬƬ�����ڰ�����ĳ���ͱڣ���Լ�ɼ������ٲ��Է嶥һк���£�
��ɫ������ǧ��
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang4",
	"south" : __DIR__"nushi",
    ]));

    create_door("south", "ľ��", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
//    replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "����" && dir == "south" && !wizardp(me) )
		return notify_fail("������㣬����Ů������Ϣ�ң�\n");

	return ::valid_leave(me, dir);
}
