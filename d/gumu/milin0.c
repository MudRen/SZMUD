// July 31,2000 
// Code by April
// /gumu/milin0.c

inherit ROOM;

void create()
{
	set("short","������");

    set("long",@LONG
���������֣�ֻ��Ȫˮ���ˣ�С����ݺ��һ�ɵ���������ż���Ļ��㣬
���������������ֻ���ɫ���۷���������˷�������������ת��һȦ
�ַɻ�ȥ�ˡ����Ͻ������֣�������һ��յء�
LONG);
	
	set("exits",([ "south" : __DIR__"milin1",
		"north" : __DIR__"kongdi",
		]));

	set("objects", ([
                "/kungfu/class/gumu/npc/huangyi" : 1,
                ]));

	set("cost",2);
	set("outdoors", "gumu");

	setup();
	replace_program(ROOM);
}
