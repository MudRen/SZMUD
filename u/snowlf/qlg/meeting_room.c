 // meeting_room.c ������ ��ĳ��
// snowlf by 2001.10.23
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"��ְҵϵͳ��һ�����ʱ������"NOR);
        set("long","�ۺ�ͤ�Ķ�¥Ŀǰ�Ѹ�����ְҵϵͳ��һ�����ʱ�����ң��ݶ���Ƕ
��һ��"+HIW+"ҹ����"+NOR+"(yemingzhu)����Ϊҹ������֮�ã��м��С�����(desk)
�����д����˵Ĳ����һ�����µ�С���±�(cahier)�����(enter)�Ƿ�ڤ
����Ƶ����ܹ����ҡ�  
    
    "+HIM+"������죬��ʱ��ͤ��ĺɳ�Ʈ���������㣡

"NOR);
        
        set("exits", ([
        

                
                "snowlf" : __DIR__"asgard_door", 
                "scatter" : "/u/scatter/workroom",
                "hopeful" : "/u/hopeful/workroom",
                "cheap" : "/u/cheap/workroom",
                "charm" : "/u/charm/workroom",
                "sys" : "/d/wizard/sys_r",
                "enter" : "/newjob/tiejiang/meeting",  
                "tj" : "/newjob/tiejiang/tjtmp_room",
                "down" : __DIR__"qingxinting", 
                "up"  : __DIR__"yangtai", 
                        
        ]));

        set("item_desc", ([
                        "yemingzhu": "һ��˶���ҹ���飬ɢ����譲ӵĹ�� ����������������֮�\n",

                        "desk": "һ�Ŵ�ĥ�úܾ��µĴ���ʯ�����������д����˵Ĳ����һ�����µ�С���±���.\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",1);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([
                __DIR__"npc/gongnu1":1,
                __DIR__"npc/gongnu2":1,
                "/d/taohua/obj/xiangcha" : 1,
                "/d/xingxiu/obj/hamigua": 1,
                "/d/wudang/obj/mitao": 1,

]));

        setup();
        call_other("/clone/board/cahier", "???");
}

