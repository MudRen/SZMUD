//Cracked by Roath
// Room: /d/beijing/west/huangqiongyu.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�ż�������λ�ĵط���������һ��Բ��ĥש�Է��Χǽ����������
�������ڡ������������ڴ���������ʯͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanqiu",
  "north" : __DIR__"danbiqiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
