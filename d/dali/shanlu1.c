// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ����ɽ·���Ѵ�����ï�ܵ�ɭ���У��򶫲�Զ�ɴ���������
��--����ǣ���ȥ�������ɽ�����ڽӽ��������ģ�����·��������
��ƽ��������ɽ����᫣���·�������ѡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu2.c",
		"east" : __DIR__"northgate.c",
	]));


	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
