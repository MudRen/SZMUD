// Filename:   /d/jueqinggu/shiwu.c ��ʯ��
// Jiuer Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",WHT"��ʯ��"NOR);

        set("long",@LONG
�в���ʱ�����ѵ���ɽ�嶥��һ��ƽ��֮�أ�ֻ��һ������Ļ�
�����ܶ�ȼ�����߽���ʮ�ɣ�������ѿ������ף����֮������ʯ�ݡ�
LONG);

        set("exits",([ 
                "south" : __DIR__"stoneroad",
                ]));
        set("objects", ([
			"/d/jueqing/npc/tongzi" : 1, 
                ]));
        
		set("no_fight" ,1);

		set("outdoors", "jueqing");
	       set("valid_startroom", 1);
        set("cost",1);  
        replace_program(ROOM);
        setup(); 
        "/clone/board/jueqing_b"->foo();
}
