//Cracked by Roath
// Room: /d/beijing/west/lingtang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ����������һ��������������һ�����ơ����й�����
ᣣ������и��ײġ��Ա������ϵ��Ű˸����ֵ���ɫ�����Ա߹���
��������������һ���л���ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baihoutang",
  "south" : __DIR__"baiqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
