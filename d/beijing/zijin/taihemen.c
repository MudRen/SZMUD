//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "̫���� ");
	set("long",  @LONG
����һ���޴����¥����ɫ��ǽ�ڣ���ɫ���ң�����������ɫ���֣�
̫���š���ǰ�����ӽ����ʿ���ֳֳ�ì�����������������ϣ�������䣬
��������һ�㡣��ǰ���������������µ�̫�͵�Ӵ����������ʹ�����
����֮һ��̫�͵����ͨ���š�
LONG
	);

	set("exits",([
        "north" : __DIR__"guang1",
        "south" : __DIR__"guang2",
		]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
