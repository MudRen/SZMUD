// Code of ShenZhou
// Room: /d/mingjiao/hdating.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��ˮ�����");
	set("long", @LONG
�˼䲻����󣬲���֮�н���һ������֮�⡣����վ���������̵��ӣ�
ÿ�����������϶�����һ��ɫ���档���г��貢����������ȴ��һ��˵��
�������ϡ����½�������ڷ���һ���˺ϱ���ϸ�ĺ����ף��׿���������
�ף���ϸһ�ƣ�ȴ��һ�㱡���ı�����һ�ɹ�������Ӵ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoulang",
  "out" : __DIR__"xiaochang",
]));
	set("objects",([
		__DIR__"npc/tangyang" : 1,
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
