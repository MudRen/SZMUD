// /d/jueqing/shanlu3.c
// Jiuer Aug 15, 2001

inherit ROOM;
void create()
{
	set("short","ũ��");

	set("long",@LONG
����ɽ���µļ���ũ�ң��ݶ�Ʈ�����ƴ��̣�ũ����������æµ��
׼���緹��ʱ��ʱ���������ǵĴ������������Ϳ쵽ɽׯ�ˣ���������
ɽ��·��
LONG);
	
	set("exits",([
		"east" : __DIR__"shanlu4",
		"northwest" : __DIR__"shanlu2",
		]));
	
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}
