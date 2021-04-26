// Code of ShenZhou
// Room: /d/mingjiao/yongdao.c
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
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"shenwei",
  "west" : __DIR__"shanlu7",
  "south" : __DIR__"shijie1",
  "east" : __DIR__"yongdao2",
  "northeast" : __DIR__"moluo",
]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
