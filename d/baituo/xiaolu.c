// Code of ShenZhou
// room: /d/baituo/xiaolu.c
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�����Ǻ����������һ��С·����������ԼԼ�Գ�һ����ɳ��������
��ɽ��ɽ���Ʈ�����ƵĲ��̣���������ס���˼ҡ�
LONG
        );
        set("exits", ([ 
            "east" : "/d/xingxiu/huyang4",
            "west" : __DIR__"btgate",
        ]));
        set("outdoors","baituo");
        replace_program(ROOM);
		set("cost", 1);
		setup();
}

