// Code of ShenZhou
// Room: /d/mingjiao/wuqiku.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ�䲻С�ķ��䣬����һ��������İڷ��ż��ӣ����ϻ�ţ�
�򿿣���ڣ���Ҳ��ٱ�����ʮ�˰����������ȫ�����в��ٴ�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shanlu28",
]));
	set("objects",([
		__DIR__"npc/wujincao" : 1,
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
