// Jiuer Aug 15, 2001
inherit ROOM;
void create()
{
	set("short","ɽ����");

	set("long",@LONG
ɽ·�������ƽ̹����������������Ҳ����ƣ���������Ѿ���ϡ��
��ɽׯ�Ĵ�ʯ���ˣ��㲻�ɵļӿ��˽Ų���
LONG);
	
	set("exits",([
		"east" : __DIR__"stoneroad",
		"west" : __DIR__"shanlu3",
		]));
	set("cost",1);
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}