// Code of ShenZhou
// Room: /d/xixia/wufosi.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������������Χȫ��ɳ������������Ѿ���������
���п������ɳ����ң��Ӱ���Ľ���������ϡ���Ա���������¡���
���֣�Ψһ���������Ľ����Ǵ����ݶ���ȫ�ǿ�����ǿ���������紵
�����������ġ���---��---������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shimen",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
