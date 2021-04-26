// Code of ShenZhou
// Room: /d/newdali/dian3.c

inherit ROOM;

void create()
{
	set("short", "�سص̰�");
	set("long", @LONG
��ط羰���ˣ��ص̰�����������к��У����ϱ��Ա�ˮ������̲���
�ݺ�֮�࣬�����ڵ�أ����ֻ����£���������ɽ֮�������к��У�ң��
����ɽɫ����ӳ�ز��䣬������ˮ��������̣���Ȼ��ʤ��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dian4",
  "westdown" : __DIR__"dian2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
