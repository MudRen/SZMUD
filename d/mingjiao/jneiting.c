// Code of ShenZhou
// Room: /d/mingjiao/jneiting.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ıڹ���ʮ�����������������ѹ�ɫ�����⣬��������Щ�Źֵ�
�������������ź��⣬���ƹ�һ�գ�����������������һ������Χ������
���ʡ����Ϊ�����ұ��ǳ����������м������棬�඼����ͭ������֮�ࡣ
LONG
	);
			set("objects",([
		__DIR__"npc/zhuangzheng" : 1,
]));

	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shanlu28",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
