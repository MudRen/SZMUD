//Cracked by Roath
// Room: /d/beijing/zijincheng/qinandian.c

inherit ROOM;

void create()
{
	set("short", "�հ���");
	set("long", @LONG
���ڹ�������,�ǹ��о��е��̻����Ҫ����,ÿ���ش��
��,�ʵ��ڴ˵���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"yuhuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
