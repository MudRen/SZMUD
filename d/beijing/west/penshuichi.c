//Cracked by Roath
// Room: /d/beijing/west/penshuichi.c

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
����һ���㳡�������и�ˮ�أ�����ββ���������е����Ρ�
ˮ�����п�ߴ����ɵ�̫��ʯ������ˮ���Ӷ������������г�һ��
��СС���ٲ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"baihuayuan",
  "south" : __DIR__"shibanlu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
