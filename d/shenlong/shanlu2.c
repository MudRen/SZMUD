// Code of ShenZhou
// ɽ·2 /d/shenlong/shanlu2
// ALN 9 / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
        set("long", @LONG
���µ�ϸɳ���������ɽ�ϵ���ʯ��ɽ·�ľ������ŵ�����Ʈ��������
���㣬��������ɾ�������ɽ��С·ǰ�У����ߴ���������У������徲��
�����������ڿ���֮�С�������ɽ�£����������ѵ�ɽ·��
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"northup" : __DIR__"shanpo1",
                "northeast" : __DIR__"shanqiu",
		"south" : __DIR__"shanlu1",
        ]));
	set("cost", 4);

        set("snaketype", ({"snake", "zsnake"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";












