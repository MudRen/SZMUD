// Room: /d/changan/center.c
// by bravo 

inherit ROOM;

void create()
{
        set("short", "ʮ�ֽ�ͷ");
        set("long", @LONG
������ǳ���������ĵط��ˡ����������ͨ���ǵĸ����ط�������ǰ
�ߣ����Ǹ��ô��ţ���������������ԩ��˵��ĵط�����Ϊ�����ٸ���������
��ʱ����Ѳ�����߶�Ѳ�顣��������м�������������������һЩ���յ�����
ʾ���գ����ù������������кã�
LONG );
        set("outdoors", "changan");
        set("no_clean_up", 0);
        set("exits", ([
                "southeast"  : __DIR__"wwroad5",
                "southwest" : __DIR__"wwroad2",
                "northeast"  : __DIR__"xfroad5",
                "northwest" : __DIR__"xfroad2",
        ]));
        set("objects",([
                 "d/city/npc/xunbu":1,
                 "d/city/npc/liumang":1,
        ]));
        set("fanhua", 2);

        setup();
        replace_program(ROOM);
}
