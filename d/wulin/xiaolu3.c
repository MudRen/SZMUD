// room /d/wulin/xiaolu3.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
��������ȥ����ת���򱱣�·������ľ�������У��ڷ��л������졣
���漴�����ƾӡ��ɴ�������������ͬ�˵ĵ������ڡ�
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiaolu2",
         "north" : __DIR__"xiaolu4",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
