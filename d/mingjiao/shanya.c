// Code of ShenZhou
// room: /mingjiao/shanya.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
һ�����͵�������ס�����ȥ·����ɽԼ����ʮ�ɿ��⡣��ͷ����һ
���������ȴ������ֻ��һƬ�ڳ����أ�����ף����˲���ͷ��Ŀѣ��
LONG );

        set("exits", ([
                "southwest"   : __DIR__"shanlu4",
        ]));

        set("outdoors", "mingjiao" );
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
