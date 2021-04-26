// Code of ShenZhou
// Room: /d/xiangyang/guangchang.c

inherit ROOM;

void create()
{
	set("short", "���Ĺ㳡");
	set("long", @LONG
�����Ǳ������壬�������ˣ������人���������£�������Ϊ������������
������ɽ��ˮ��ˮ½��ͨ����봨�¡��½��ϡ�������������λ��۴����׳�
�����С��ϴ�����֮˵������ʡͨ�顱֮˵������������Ĺ㳡����������
���ÿ�������ͣ�㣬���ﲻ����Ȼ�������Ե�ȴ���Ǻܷ���������������ȥ��
��һƬɭ�����󣬲�ʱ�����Լ���Ѳ�ߵĹٱ��߹�����Ⱥ��·���С�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beijie1",
  "south" : __DIR__"nanjie1",
  "east" : __DIR__"dongjie1",
  "west" : __DIR__"xijie1",
]));
	set("no_sleep_room", 1);

	setup();
	replace_program(ROOM);
}
