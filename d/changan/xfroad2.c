// Room: /d/changan/xfroad2.c
// by bravo 

inherit ROOM;

void create()
{
        set("short", "�Ҹ����");
        set("long", @LONG
�ߵ����������������ǹٸ��ˡ�Զ���ٸ����ţ������������޾�
��ɵ�վ���������ģ�������Щ��Ҷ��һ��紵�������˲���������
LONG );
        set("outdoors", "changan");
        set("no_clean_up", 0);
        set("exits", ([
                "southeast"  : __DIR__"center",
                "northwest" : __DIR__"gfdoor",
                "northeast"  : __DIR__"xfroad3",
                "southwest" : __DIR__"xfroad1",
        ]));
set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
