// Code of ShenZhou
// �ų�
// maco

inherit ROOM;

void create()
{
	set("short", "�ų�");
	set("long", @LONG
���е�·�������Թ��������ۻ����ҡ�·�����Ӷ����໵��
�������ؿɲ���͸��һ�ɼž������ա�
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng2",
		"west" : __DIR__"gucheng5",
		"north" : __DIR__"gucheng4",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

