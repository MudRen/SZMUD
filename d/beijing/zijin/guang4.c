//Cracked by Roath
// Room: /d/beijing/zijincheng/guang4.c

inherit ROOM;

void create()
{
	set("short", "�տ��㳡");
	set("long", @LONG
���ǿտ�һ���Ĺ㳡��������ϰ�����������
�����ʿ�����ڴ���ʾ���ʵ۱����ϱߵļ�
ͤ�ļ����ɴ�������һ��ƽ����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jingyunmen",
  "north" : __DIR__"fengxiandian",
  "south" : __DIR__"jianting",
  "east" : __DIR__"ningshoumen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
