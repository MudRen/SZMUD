//Cracked by Roath
// Room: /d/beijing/west/baihoutang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ׼Ҵ�լ�ĺ��ã�����ɢ����һЩδ�վ���ֽǮ������ɢ
����һЩ������һ�������ſڴ����������ɵ�ʹ�˺�ëֱ������
յ���ɢ������Ƶĵƹ⣬����ȥʮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lingtang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
