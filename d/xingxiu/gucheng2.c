// Code of ShenZhou
// �ų�
// maco

inherit ROOM;

void create()
{
	set("short", "�ų�");
	set("long", @LONG
��ط����Ǹ����ľ������������Ʒ��Ȼ�����˲�֪����
���£�������Ȼ��á���·ֻ����ذ׹ǣ���ǹ��ꪣ�������
�������Ǿ�����һ����ս��ȫ�Ǿ��񶼸�����ɱ��һ�㡣
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng1",
		"west" : __DIR__"gucheng3",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

