//Cracked by Roath
// Room: /d/beijing/zijincheng/yushufang.c

inherit ROOM;

void create()
{
	set("short", "���鷿");
	set("long", @LONG
���ʵ۴��ǰ����֮��,���ڱ�ֵ��̫���Ĩ��һ����Ⱦ�����
���ˡ���ǰ�������һ��̴ľ��������������ض���һ���飬����һ
�������ݴ����������ˡ����Ӷ��ߣ�һ¯�������١����������³�ɬ
ɬ�����㡣ʹ��һ���ݱ�˼�ɵ����������棬������һ����ܣ����
�϶�������.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jingyanggong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
