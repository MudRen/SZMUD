// Code of ShenZhou
// xiaoxi.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "���ԭ");
	set("long", @LONG
����һ��Ƭ���ƽԭ���ޱ��޼ʵ������ȥ��������ӣ��ݵ�
�ϼ���ֻ�����ڱ��ܳԲݡ���ԭ����һ����ɽ���������������
����ɽ����ȫ�ǰ�����ѩ��ɽ������ȴ�����Դ���ľ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan4",
		"west" : __DIR__"shanlu1",
		"north" : __DIR__"caoyuan3",
		"south" : __DIR__"caoyuan3",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
