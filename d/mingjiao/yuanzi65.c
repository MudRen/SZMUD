// Code of ShenZhou
// Room: /d/mingjiao/yuanzi65.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Ժ��");
	set("long", @LONG
Ժ������ʯС���������滨��ݣ��ָ�ϣ֦�����㸡������Ӱ���飬
ʱ�ų�ݷ��ɡ�����ɽˮ֮����Ȼ����ո��Ļس���������֮����εȻ
���㡣�������᷿�Ĵ�����͸���ƻ�֮�⡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xixiang",
  "south" : __DIR__"ceting64",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
