// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "�����ŵ�");
	set("long", @LONG
��������ɽ��߷塪����ľ���嶫�ࡣ���������ŵ������𰢿�
�տ��Ȳ�����ɽ�ڣ�����������������Ǻ�ͨ����������Ҫ��·��
Ҳ�������ϡ�������һ���ݾ���
LONG
	);
	set("exits", ([
		"northup" : __DIR__"gudao2",
		"westdown" : __DIR__"lake",
	]));
	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
