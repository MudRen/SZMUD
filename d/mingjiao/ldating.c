// Code of ShenZhou
// Room: /d/mingjiao/ldating.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�һ������");
	set("long", @LONG
̤����������һ��ѣ�Ρ������ĽǸ���һ���¯������ɫ�Ļ����
������Ծ������վ�����ų��ⱳ�Ĵ󺺣�����û��һ˿ʹ�࣬�·��Ծ�
ϰ��������û��ů��Ļ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"shanlu76",
  "east" : __DIR__"shanlu33",
]));
	set("objects",([
		__DIR__"npc/xinran" : 1,
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
