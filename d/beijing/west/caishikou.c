//Cracked by Roath
// Room: /d/beijing/west/caishikou.c

inherit ROOM;

void create()
{
	set("short", "���п�");
	set("long", @LONG
����һ���൱���ֵ�ʮ��·�ڣ�·��������һ���߸ߵ�ʮ����
ľ�ˣ����滹�а߰�Ѫ�����󷲳�͢��ն���ˣ���ʬ���У�ն��ʾ
�ڣ�����������С�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"guangandajie",
  "north" : __DIR__"xuanwumen",
  "east" : __DIR__"tianqiao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
