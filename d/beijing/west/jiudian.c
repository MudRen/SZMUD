//Cracked by Roath
// Room: /d/beijing/west/jiudian.c

inherit ROOM;

void create()
{
	set("short", "С�Ƶ�");
	set("long", @LONG
����һ����С�ľƵ꣬���⿴��ȥʮ���嵭�����Ҳֻ����ͨ��
�ɣ����㶹֮�ࡣ�����Ƕ����лش��ã�������͹����ˡ�������ɢ
�����ż����ˣ���С���к���Ҳ���Ǻ��𾢡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baozhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
