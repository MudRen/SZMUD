// July 31,2000
// Code by April
// /gumu/midao2.c

inherit ROOM;

void create()
{
        set("short", "�ܵ�");

        set("long",@LONG
�㶫ת���䣬Խ��Խ�͡�ͬʱ���½�����ʪ����֪���ѳ��˹�Ĺ��ֻ
���ڰ�����Լ��ȥ���������ǲ�����ܵ������һƬ�����ֲ�����ָ����
��һ�������·�涸�����Ǳ�ֱ���£���������������ˮ֮����
LONG);
		
		set("exits",([ "westup" : __DIR__"midao1",
			"eastdown" : __DIR__"midao3",
			]));

		set("cost",5);
		setup();
}

