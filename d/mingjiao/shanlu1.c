// Code of ShenZhou
// room: /mingjiao/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ֻ���˴���·��᫣������վ���һ�����ذ�������բʯ�š����򱱾�
�����̵Ĺ������ˡ����ܳ�����ӳ���������ԡ�һƬ�����������⡣
LONG );

        set("exits", ([
                "northup"   : __DIR__"shanlu",
                "southeast" : __DIR__"shanlu2",
                
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}
