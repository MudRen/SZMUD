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
����ɽ����ȫ�ǰ�����ѩ��ɽ������ȴ�����Դ���ľ�����ϱ�һƬ
�������ɣ�ï�ܷ�ʢ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan3",
		"west" : __DIR__"caoyuan2",
		"south" : __DIR__"caoyuan4",
		"north" : __DIR__"caoyuan5",
		"southeast" : __DIR__"lake2",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

