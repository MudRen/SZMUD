// study.c   ������/��ի
// snowlf by 2001.12.19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIW"��ի"NOR);
        set("long","
    ��ի���������һ��������   
    
	     		�ƻ�ҹ������ζ  
	     		ī����տ������
    
    ���Ŷ��룬���������ŵķ�����һ��"+HIW+"����"+NOR+"(desk)���Ա߿�ǽ��������
���Ϸ������飬���Ϸ���һ��"+HIR+"ɺ��"+NOR+"�辰���ݶ���Ƕһ��˶���"+HIW+"ҹ����"+NOR+"(yemingzhu)��

"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
		
		"west" : __DIR__"jiuqu5",
		"out" : __DIR__"huayuan",		
        ]));

        set("item_desc", ([
			"yemingzhu": "һ��˶���ҹ���飬ɢ����譲ӵĹ�� ���ǹ��е�����֮�\n",
                        "desk": "����һ�ź���������������Ϸ���һ��ɺ���辰��һ������(jian su).\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",0);
        setup();
        
        call_other("/clone/board/jiansu2", "???");
}
