// shuixie.c   ������/ˮ�
// snowlf by 2001.12.18

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIM"ˮ�"NOR);
        set("long","�س�������ǰ�У������������Ϊһˮ鿡�ˮ��ӯ��һС�ſɴ�԰�"+HIC+"����
����֮�ҡ�"+NOR+"����������أ������ģ����Ź�����£��¿����ۡ�ƾ���࿴������
��ɫ�����۵ס�����ɻ�������ת�������򣬼�����԰��

    "+HIM+"���������棬�����е����������Ŀ�������
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([

		"west" : __DIR__"jiuqu1",
		"northwest" : __DIR__"jiuqu2",
		"northeast" : "/u/xrz/workroom",
        ]));

        set("item_desc", ([
                        "lotus flower": "������Ҷ����̣�ӳ�պɻ������죡\n",
			"������ɫ": "������Ҷ����̣�ӳ�պɻ������죡\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",1);
        set("objects",([ 
                __DIR__"npc/gongnu3":1,                
       
]));
        setup();

}
