// Code of ShenZhou
// �ų�
// maco

inherit ROOM;

void create()
{
	set("short", "�ų�����");
	set("long", @LONG
���ǹų����ľͽ���һ�����ӡ�����͹��һ���״���죬
�̸���ڣ�ȴ�Ǹ������������
LONG
	);

	set("exits", ([
		"south" : __DIR__"gucheng3",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
