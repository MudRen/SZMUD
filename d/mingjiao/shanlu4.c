// Code of ShenZhou
// room: /mingjiao/shanlu4.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ֻ���˴���·��᫣������վ���һ�����ذ�������բʯ�š���������
�����ƣ���֪��ʲôȥ����
LONG );

        set("exits", ([
                "northeast"   : __DIR__"shanya",
                "westdown"    : __DIR__"shanlu",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 2);


        setup();
        replace_program(ROOM);
}
