// Room: /d/changan/xfroad3.c
// by bravo 

inherit ROOM;

void create()
{
        set("short", "�Ҹ����");
        set("long", @LONG
��������ͨ�����ŵıؾ�֮·�����ϱȽ����壬�⼸���ΰ����ã���ѹ��
�յ��¼��Ѿ������ˣ�����ȥ���ź�ԩ��Ҳ���ˡ�������Щ��Ҷ��һ��紵����
���˲���������
LONG );
        set("outdoors", "changan");
        set("no_clean_up", 0);
        set("exits", ([
                
                "northeast"  : __DIR__"nroad1",
                "southwest" : __DIR__"xfroad2",
        ]));
set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
