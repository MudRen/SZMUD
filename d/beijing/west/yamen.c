//Cracked by Roath
// Room: /d/beijing/west/yamen.c

inherit ROOM;

void create()
{
	set("short", "˳�츮����");
	set("long", @LONG
����˳�츮������֮�أ���Ϊ˳�츮����ά������һ���ΰ���
�����ش󣬼�֮����Ȩ���ڶ࣬�Ĳ��׹�Ͻ���ʶ�˳�츮��֮����
�ݸ�Ҫ����һ��������Ҳ������ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guloudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
