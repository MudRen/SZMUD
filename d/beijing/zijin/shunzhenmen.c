//Cracked by Roath
// Room: /d/beijing/zijincheng/shunzhenmen.c

inherit ROOM;

void create()
{
	set("short", "˳����");
	set("long", @LONG
��������԰��������ţ����峯��ƽʱ�ǹ��ŵģ��ʵۡ��ʺ�
���ɳ���ʱ����ʱ���ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shenwumen",
  "south" : __DIR__"yuhuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
