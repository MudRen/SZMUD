//ROOM: caifeng.c

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long",@LONG
���ǡ����չ����Ĳ÷��ҡ�����Ů��Χ����һ�飬�������ߣ�����Ů
�죬�ѵ�������Ϊ���Ժ���һ�����ż��� 
LONG      
  );
        set("exits", ([
		"south" : __DIR__"changl10",
        ]));
        set("objects",([
		"/kungfu/class/lingjiu/tbyang" : 1,
       	]));
        setup();
        replace_program(ROOM);
}