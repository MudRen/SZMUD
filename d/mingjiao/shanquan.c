// Code of ShenZhou
// Room: /d/mingjiao/shanquan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽȪ");
	set("long", @LONG
һ���������������Ƶģ����������Ĵ��ǿ������ĵط��в���Ը�ؼ�
�˳�����ת����������ˮ�档��Χ�������������۲ݽ����·�����������
һ�㣬�̵ĸ��̣���ĸ��죬����Ȫ���ƺ���һ�������ø������䵽���㡣
żʱ��һ��������Ů��˵˵ЦЦ�Ĳ������������һЦ���������ͷ׵���
�硣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"bshantan",
		"northeast" : __DIR__"shanjiao1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
