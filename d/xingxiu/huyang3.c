// Code of ShenZhou
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "������");
	set("long", @LONG
��·���������Ŵ�Ƭï�ܵĺ���ľ(tree)��ΡΡȻ�������أ�
����һ������������ڴ˷ֲ������𽥽ӽ�ɳĮ���ϱ�����һƬ
�����֣���ȥ�����ɼ�������ɳ�ѻ��ɵ�ɽ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"huyang2",
		"south" : __DIR__"huyang5",
		"west" : __DIR__"huyang4",
	]));
	set("item_desc", ([
	"tree" : "�����ǻ�Į����ߴ����ľ���赲�˴�Į��ɳ��ҲʹɳĮ������������\n"
		"���ǿ��޺������������˵���������ǡ�����һǧ�ꡱ��\n"
		"���ڻ�Į������һǧ�겻�����������ڻ�Į��һǧ�겻���������ڻ�Į��һǧ�겻�á�\n",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

