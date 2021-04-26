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
�����������ӹ�ȥ���Ա���һ��Ƭʢ���Ļ��䣬���ҡҷ��ɢ������
���㡣��Զ�����ǻ�ɽŮ���ӵ���Ϣ�ҡ�
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang1",
	"west" : __DIR__"zoulang5",
	"south" : __DIR__"liangong2",
    ]));

    create_door("south", "ľ��", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    replace_program(ROOM);
}