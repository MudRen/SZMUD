//Cracked by Roath
// Room: /d/beijing/east/guozidamen.c

inherit ROOM;

void create()
{
	set("short", "���Ӽ�");
	set("long", @LONG
���Ӽ���̫ѧ����ӡ�ѧϰ�ĵط���Ϊ�������������ѧ
�������Ӽ��н�ϰ����ʦ���Ǳ�ѧ����֮ʿ������Ժ�ĺ��֡�
ѧʿҲ�������˽�ѧ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guoziqianyuan",
  "south" : __DIR__"guozijianjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
