// Code of ShenZhou
// Room: /d/mingjiao/tiehanshan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
���ǹ����������һ��Сɽ�壬�˴�ɽ�Ƶ�ƽ������ش���λ������
�㲼����ľϡ�裬�˼�����������һ����С·ͨ��ɽ�£�������Լ�ɼ�
��ʯ��ᾡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"shanlu20",
  "southeast" : __DIR__"shanlu23",
]));
//	set("objects",([
//		__DIR__"npc/zhuyuanzhang" : 1,
//	]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
