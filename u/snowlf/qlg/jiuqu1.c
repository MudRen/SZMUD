// jiuqu.c   ������/��������
// snowlf by 2001.12.18

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIW"��������"NOR);
        set("long","
    �������������Ǿ������ȣ����������ϻأ��������ģ��ڲ�һ�����ң�Ϊ��
���黭֮�ã����ٺɻ��ء�
    "+HIM+"������죬��ʱƮ���������㣡
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	"north" : __DIR__"qingshi",
         	"west" : "/u/snowlf/workroom",
		"southwest" : __DIR__"asgard_door",
		"east" : __DIR__"shuixie",
		
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
