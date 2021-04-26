// Code of ShenZhou
// Room: /d/newdali/shegu.c

inherit ROOM;

void create()
{
	set("short", "�߹���");
	set("long", @LONG
�߹���λ�ڴ�����ڣ����ڵ��ɽб���嶫�¡��ഫ����������
�������١�����β�����ڣ���ˮ���ģ�����ʿ�γ��ֻ�����������
��ͬ���ھ������˽�������ˮ�ƣ����߹ǻ�����ˮ����Ϣ������һ��
�ܴ�ʽ����ש����
LONG
	);

	set("objects", ([
		"/d/village/npc/kid" : 2,
		]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"east" : __DIR__"taihejie4.c",
		"west" : __DIR__"qingchi",
		]));
	set("no_clean_up", 0);

	setup();
}
