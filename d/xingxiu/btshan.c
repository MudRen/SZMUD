// Code of ShenZhou
// room: /d/xingxiu/btroad
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�����Ǻ����������һ��С·������ͨ������ɽ��
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"huyang4",
            "west" : __DIR__"btgate",
        ]));
        set("outdoors","xingxiuhai");
        replace_program(ROOM);

	set("cost", 1);
        setup();
}

