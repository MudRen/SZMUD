//Cracked by Roath
// Room: /d/beijing/zijincheng/yuyaofang.c

inherit ROOM;

void create()
{
	set("short", "��ҩ��");
	set("long", @LONG
���ǽ����е���ҩ��������˴������ҩ�ģ�����ҩ���˱Ƕ���������
ҩ������ð�ݣ��Ա߼���С̫�����������Ž���¯����λ̫ҽ����������
ʲô����֪���Ƿ��ǻ�������Ƿ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sikongchu",
  "north" : __DIR__"rijingmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
