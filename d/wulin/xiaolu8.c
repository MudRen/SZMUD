// room /d/wulin/xiaolu8.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
С·�ѵ���ͷ����������Ϊ����ʹ�ߵľ������������ʯͷ���ɣ���
���佨������Ȼ�е�һ�����ϡ�

LONG
        );

        set("exits", ([
        "south" : __DIR__"xiaolu7",
        "east" : __DIR__"fajue",
        "west" : __DIR__"fajuw",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
