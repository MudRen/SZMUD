// Code of ShenZhou
// /d/mingjiao/fuw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˼�������������������ǿտ����������б����ܣ��ϰ�ʮ������
�������Ե��ŵı�ǽ�ϻ���һ����ɫ������˫����ţ������ɲ����ڱ�
��׺�ż��κ�ɫѪɫ�㣬���˲���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"daguangchang",
]));
	set("objects",([
//                CLASS_D("mingjiao")+"/weiyixiao" : 1,
	]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
