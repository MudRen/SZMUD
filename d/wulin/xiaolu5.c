// room /d/wulin/xiaolu5.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
������һ��ɽ��С·�����������ߣ�·���ѷǳ�ƽ����һ·�Ϲ�ʯ��
ᾣ����߱߿���Ҳ����һ����Ȥ��
LONG
        );

        set("exits", ([
         "west" : __DIR__"dianmen",
         "east" : __DIR__"xiaolu6",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
