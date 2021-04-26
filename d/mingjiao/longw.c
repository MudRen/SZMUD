// Code of ShenZhou
// Room: /d/mingjiao/longw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˼�������������˵����˺��裬����ӥʨ�������Ϊ����������
���ξ��˺�ľ���ƣ����о�ϸ���ͼ�����������롣���Ϻ������ӳ��
��ڻԻ͡���ǽ�ϻ�����һ����������������������צ�����˾�η��
LONG
	);
	set("objects",([
		__DIR__"npc/daiqisi" : 1,
	]));

	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"daguangchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
