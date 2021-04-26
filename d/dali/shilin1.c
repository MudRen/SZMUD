// Code of ShenZhou
// Room: /d/newdali/shilin1.c

inherit ROOM;

void create()
{
	set("short", "·��ʯ��");
	set("long", @LONG
�����������洦�ɼ���ʯ���죬ʯ��Լ���ʯ��ͦ����������ʣ��������ˡ�
����ʯ���ܾۣ��罣��ſգ�çç�Բԣ�ٲȻһƬ�ֺ���εΪ׳�ۡ����Ӵ�ɽ֮
�л����ֱк���ɵ�ˮ���ƣ���ɽȪ��ۣ�������������
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cangshan",
  "northup" : __DIR__"shilin5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
