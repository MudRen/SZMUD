// Code of ShenZhou
// room: /d/baituo/btroad
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
            "east" : "/d/xingxiu/huyang4",
            "west" : "/d/baituo/btgate",
        ]));
        set("outdoors","baituo");
        replace_program(ROOM);

	set("cost", 1);
        setup();
}

