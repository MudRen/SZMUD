// Code of ShenZhou
// Room: /d/xixia/dayuan.c

inherit ROOM;

void create()
{
	set("short", "һƷ�ô�Ժ");
	set("long", @LONG
����һƷ�õĴ�Ժ����ʱ�����Ű��µ���һ��������ȴû��һ����
Ϣ�����ĳ��档Ժ�е������ò�������������ϳ�������Ӱ�ӡ�ż����
����У�����������ļž���΢�紵������Ҷ�趯��������ɳɳ������
������ʯ�ĵ��濴��ȥ�ɸɾ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"ypgate",
  "north" : __DIR__"dating",
  "east" : __DIR__"jytang",
  "west" : __DIR__"zhangfang" ,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
