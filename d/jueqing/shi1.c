// /d/jueqing/shi1.c  С��
// By jiuer

inherit ROOM;

void create()
{
	set("short","С��");
	set("long",@LONG 
ֻ�����г����ª�����ྻ�쳣������ֻһ��һ����������ޱ��
�������õķ�λ��ȴ��Ϥ֮���������Ĺʯ���е�����һģһ��������
��תȥ���Ǽ�С�ҡ�
LONG);
	
	set("exits",([ 
		"east" : __DIR__"shi2",
		"out" : __DIR__"maowu",
		]));
	
	set("objects", ([
		"/d/jueqing/obj/fish" : 1,
		]));
	set("resource/water", 1);	
	set("cost",1);
	setup();
	replace_program(ROOM);
}
