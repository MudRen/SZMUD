// Jiuer Aug 15, 2001
// /d/jueqing/shanlu2.c

inherit ROOM;

void create()
{
	set("short","��ɽ��");

	set("long",@LONG
�ߵ����ɽ·����ƽ����һЩ����������������Ϣ��̧ͷ������
�ߵ��±ڣ���ɽ�ڶ��ͣ���������·��Ѱ������ղ���ɽ�����Σ�����
�������亹��Զ������ɽ���������������񷿣��������ƣ����������
ũ������׼���緹����վ������������ǰ��ȥ��
LONG);
	
	set("exits",([
		"southeast" : __DIR__"shanlu3",
		"northup" : __DIR__"shanlu1",]));
	
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}