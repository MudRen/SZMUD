// Code of ShenZhou
// Room: /d/dali/tusi4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ǻ�������һ¥һ�׵���ʽ�������ݽǵ��ϸ�ܣ����ξ���������
ͼ�������޻�ľ�ĵ�̣�������������·��ӱ����������ʮ������˾���б�����
�õ�һ����
LONG);
	set("exits", ([
		"south" : __DIR__"tusi3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
