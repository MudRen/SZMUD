// Code of ShenZhou
// Room: /d/xixia/kongdi.c

inherit ROOM;

void create()
{
	set("short", "���пյ�");
	set("long", @LONG
����ɽ���е�һ���յأ��������µķֲ�����ʮ��ľ�ݣ�����������Ʈ��
���Ͽգ�����С������׷�����֣�������û����ɵ�ſ��������ɹ̫������Χ
ɽ����ͬ���Ǿ�ľ���죬����ȥ�������һ��������͵�С�塣�����Ŀյ�����
����ľ�ݿ���ȥ�е�����עĿ�������Ͷ�������һ��ɽ·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"dawu",
  "northwest" : __DIR__"spring",
  "southwest" : __DIR__"tulu",
]));
	set("objects", ([
		"/d/city/npc/wolfdog" : 2,
		"/d/city/npc/boy" : 1,
	]));
	set("cost", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
