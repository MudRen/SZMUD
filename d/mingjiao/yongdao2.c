// Code of ShenZhou
// Room: /d/mingjiao/yongdao2.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ�������ֳ�������ÿ�����ɴ��������һ����ѣ�������
��������硣���ߵ�ǽ���Ͽ���Щ��֪����ͼ�����ƹ���ħ���������ޡ�
����������ת����ʱ�����ͽΪ�����������֪�����˶������¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yongdao",
  "south" : __DIR__"shijie2",
  "northup" : __DIR__"shanlu19",
  "northwest" : __DIR__"moluo",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
