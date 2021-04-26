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
���������ӹ�ȥ���Ա���һ��Դ�ï�����ӣ�����ʮ�����ġ���Զ
�����ǻ�ɽ�е��ӵ���Ϣ�ҡ�
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang3",
	"west" : __DIR__"zoulang1",
	"south" : __DIR__"liangong1",
    ]));

    create_door("south", "ľ��", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    replace_program(ROOM);
}