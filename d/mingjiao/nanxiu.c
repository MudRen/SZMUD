// Code of ShenZhou
// Room: /d/mingjiao/nanxiu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ܲ���ʲô���裬ֻ���߰�����ľ�󴲣������������̵���������
Ϣ��ÿ����ľ���߶���һֻ��ľ�䣬����װ�е����Ǹ������¿㡣������
����һ��ľͷ��������һ��ͭ��̨��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang46",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
