// Code of ShenZhou
// room: /mingjiao/shulin2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï��
��Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�
Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );

        set("exits", ([
                "west"  : __DIR__"shulin2",
                "north" : __DIR__"shulin2",
                "south" : __DIR__"shulin2",
                "east"  : __DIR__"shulin1",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
