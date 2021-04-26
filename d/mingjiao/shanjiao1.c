// Code of ShenZhou
// Room: /d/mingjiao/shanjiao1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
��غ컨�̲ݣ���Զ����һ���֡�����ϸ�������л���ˮ�������ֲ�
���С���ֻɽȸ�ɹ��������ľ�֮��������һ��������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"shanquan",
  "northup" : __DIR__"qingshilu1",
  "southeast" : __DIR__"songlin1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
