// Code of ShenZhou
// ɽ·1 /d/shenlong/shanlu1
// ALN 9 / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
        set("long", @LONG
����̤��ϸɳ���ŵ�����Ʈ���������㣬��������ɾ�������ɽ��С
·ǰ�У����ߴ���������У������徲�������������ڿ���֮�С������Ǻ�
̲��������ͨ��嶥��ɽ·����������ɽϪ��
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"west" : __DIR__"haitan",
		"north" : __DIR__"shanlu2",
		"southeast" : __DIR__"shanxi",
        ]));

	set("cost", 4);

        set("snaketype", ({"yinhuan", "zsnake"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";