// Code of ShenZhou
// Room: /d/dali/wuhua7.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������ȣ�ͨ��������˵����ҡ����˶�¥��ë
ձ�Ѿ����ɴ��ף�����ľ���ϻ���л�����棬�����Щ��ʱ��
���ֻ���ÿ���߰˲�������һ����̨���������̴�ͭ�������γ���
��֮����һ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wuhua6.c",
  "enter" : __DIR__"wuhua9.c",
]));
	set("no_clean_up", 0);
set("cost",1);
	setup();
	replace_program(ROOM);
}
