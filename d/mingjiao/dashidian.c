// Code of ShenZhou
// Room: /d/mingjiao/dashidian.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��ʳ��");
	set("long", @LONG
ʥ����̳�������ڶ࣬��ʳ��֮����󣬿���ǧ�˹��ͣ�����Ϊ��ʳ
����������ഫ�������ƣ�����Ϊ�������ӣ��ϳ��������̹档���
����г������źȾƲ�ȭ֮����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qiankun",

]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
