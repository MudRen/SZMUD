//Cracked by Roath
// Room: /d/beijing/zijincheng/yuehuamen.c

inherit ROOM;

void create()
{
	set("short", "�»���");
	set("long", @LONG
����һ�����ι��ţ�ÿ����Բ֮ʱ���¹����ڹ���֮�ϣ��Ե���
����������ɱ���������Ӻ��������������һ��ƫ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"neiyoumen",
  "south" : __DIR__"nzsfang",
  "north" : __DIR__"pibenchu",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
