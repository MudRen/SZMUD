// room /d/wulin/xiaolu2.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
С·�����������죬��ɫԽ�����ģ�·���Բ�ľ�𽥶�����������ʱ
��Ұ���������дܹ���
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiaolu1",
         "west" : __DIR__"xiaolu3",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}













