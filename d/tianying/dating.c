// Code of ShenZhou
//room: dating.c
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
		"south" : __DIR__"zoulang8",
		"west" : __DIR__"xiangfang3",
		"east" : __DIR__"shufang",
        ]));

        setup();
	replace_program(ROOM);
}
