//Cracked by Roath
//ywz yidao2.c
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�̫�����߹��ڶ���������С���
������Ǿ�ʦ�������ˡ�
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
			"southwest" : __DIR__"yidao1",
			"northeast" : __DIR__"dadao_yongan_s",
			"northwest": "/d/heimuya/road1",
			"north" : __DIR__"gaoliangdi",
        ]));
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
