// Code of ShenZhou
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "������");
	set("long", @LONG
����ľ�Ӱ���ɳĮ��Ե�ش��������Ŵ�Ƭï�ܵĺ���ľ(tree)
��ΡΡȻ�������أ�����һ��������һ���������̵ĵ�·��ֱͨ��
�������ࡣ
LONG
	);

	set("exits", ([
		"east" : __DIR__"shamo4",
		"west" : __DIR__"huyang2",
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

