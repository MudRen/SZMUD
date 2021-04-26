// Code of ShenZhou
// room: /mingjiao/shanlu2.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ֻ���˴���·��᫣������վ���һ�����ذ�������բʯ�š���������
�����̵Ĺ������ˡ������ڴ����������������������ȴҲ����Ѹ��������
��֮������ͷ���죬��Ϯ�����Ĵ�ɵ���δ��óȻ���롣
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"shanlu1",
                "southeast" : __DIR__"badake",
                
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
