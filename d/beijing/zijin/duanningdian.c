//Cracked by Roath
// Room: /d/beijing/zijincheng/duanningdian.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǵ�Żʵ۵Ĺڣ��ۣ������ĵĵط�������������˸��ִ�С
����ͬ��ɫ�Ĺ��ӡ�������д��һ������ǩ�������Ѿ�����һ����
�ĵĻҳ�����Ȼ�ܾ�û�������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"rijingmen",
  "north" : __DIR__"yuchafang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
