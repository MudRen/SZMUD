// Code of ShenZhou
//ywz yidao2.c
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�̫�����߹��ڶ���������С���
������Ǿ��ǵ����š������š��� 
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"southwest" : __DIR__"yidao1",
                "northwest" : __DIR__"yidao2",
		"northeast" : __DIR__"yidao3",
                "north" : __DIR__"gaoliangdi",
        ]));
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
