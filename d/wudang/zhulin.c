// Code of ShenZhou
// zhulin.c �����
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "�����" );
	set("long", @LONG
�������ܶ������֣�һ������ʯ�̳ɵ�С·����������졣΢�����
������Ҷ����ɲɲ���������Ե�һƬ�����������峿�ı��մ�����͸������
���յ�������������ġ����߹��ݴԵ��Աߣ���ʱ������Ƭ��ݣ����ľ���
֮�У�С�������ٿȻ�����������ڳ��š�
LONG
	);
	set("exits", ([
		"south" : __DIR__"hs_xiaolu",
		"north" : __DIR__"xiaolu2",
	]));
	
	setup();
	replace_program(ROOM);
}
