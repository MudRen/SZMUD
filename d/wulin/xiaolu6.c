// room /d/wulin/xiaolu6.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
С·����������խ��ɽ·��������ʯ���������ս���˼��С����
��ؼ�����ǰ�ߡ�
LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu5",
         "east" : __DIR__"xiaolu7",
        ]));

        set("no_clean_up", 0);        
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
