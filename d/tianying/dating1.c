// Code of ShenZhou
//room: dating1.c
inherit ROOM;

void create()
{
        set("short","��������");
        set("long", @LONG
�߽����ͻ��һ������֮�⣬������ʮ�ֿտ�������������յ
��ƣ������Ǿ�׳�彣��ʿ����ɭ�ϱ��ˡ�������һ������ǰ��һ��
��̴ľ��������������������������������������¡�
LONG
           );

	set("exits",([
		"south" : __DIR__"zoulang",
		"west" : __DIR__"xiangfang",
		"north" : __DIR__"houting",
		"east" : __DIR__"shufang",
        ]));

        setup();
	replace_program(ROOM);
}
