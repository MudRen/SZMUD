// Code of ShenZhou
// Room: /d/mingjiao/milin40.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ɽ���̹ǣ������֦��ż�м��߹���������������
�������̬����Զ����ʱʱ����������ľ������ǰ���ĺ����ʹ���
�ϵ�����ƽ���˼��ֲ�����������ϡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mguangchang",
]));
	set("objects", ([
		__DIR__"obj/pine" : 2,
	]));
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
