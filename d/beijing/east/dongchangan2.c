//Cracked by Roath
// Room: /d/beijing/east/dongchangan2.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ƿ������ֵĶ������֣���ֽ����������ˮ��������
����Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�С
�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chongwenmen",
  "west" : "/d/beijing/zijin/dongchangan",
  "east" : __DIR__"guanxiangtai",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
