// qlg/fenglin.c ����
// snowlf by 2001.12.17

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIR"����"NOR);
        set("long","
    ��ʱ��������ʱ�ڣ�������Ҷ�Ӷ������ˡ���һƬ��Ҷ������̾����������
��ע��������Щ��Ҷ�ƴ����޾���ϲ�ã�������������£���չ��֦Ѿ��������
���Ĺ⻪������̾������һ���˽�ǰ�˴ʾ䣢����˭Ⱦ˪�������⾳��
    
"NOR);

        set("no_fight", 0);           
        set("valid_startroom",1);
        
        set("exits", ([
         	"west" : __DIR__"asgard_door",
		

		
        ]));


        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([ 
                
                 __DIR__"npc/yutu":2,   
   
       
]));
        setup();
 
}
