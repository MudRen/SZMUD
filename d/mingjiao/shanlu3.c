// Code of ShenZhou
// room: /mingjiao/shanlu3.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ��ĵ�·��᫲�ƽ������ɷ�Ƿ�����������Ȼ�����̵ĵ��̡�ż��
���Կ���Ѳ�ӵ��������ڡ�������ȥ����һƬ��ư��̵����֡�
LONG );

        set("exits", ([
                "west"        : __DIR__"shulin1",
                "eastdown"    : __DIR__"shanlu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
