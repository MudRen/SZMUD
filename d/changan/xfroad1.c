// Room: /d/changan/xfroad1.c
// by bravo 

inherit ROOM;

void create()
{
        set("short", "�Ҹ����");
        set("long", @LONG
��������ͨ�����ŵıؾ�֮·�����ϱȽ����壬�⼸���ΰ����ã���ѹ��
�յ��¼��Ѿ������ˣ�����ȥ���ź�ԩ��Ҳ���ˣ�������Щ��Ҷ��һ��紵��
���˲���������
LONG );
        set("outdoors", "changan");
        set("no_clean_up", 0);
        set("exits", ([
                
                "northeast"  : __DIR__"xfroad2",
                "southwest" : __DIR__"wroad1",
        ]));
set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
