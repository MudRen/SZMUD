// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "ʥ����");
	set("long", @LONG
������Ǵ�����ҵļ���----ʥ�����ˣ�������սй��ˣ�������
���������£�����������ʵ���λ����������ҡ��˵ر�����ɽ����
�ٶ�ˮ����ռ��ʤ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"diancang.c",
	]));


	set("cost", 1);
	set("outdoors", "dali");
	setup();
}
