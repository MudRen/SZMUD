// workroom.c ������ �G���c
// snowlf by 2001.09.17
// snowlf change of 2001.9.30 (add board)  
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"������"NOR);
        set("long","һ����Ө��͸��ˮ��������������������ڵ����Ｘ��ȫ������ˮ��
���ģ��ݶ���Ƕһ��˶���"+HIW+"ҹ����"+NOR+"(yemingzhu)�������ŵķ�����һ��"+HIW+"����
��"+NOR+"(desk)���Ա��п���(zuo)�����Ϸ���һ��"+HIR+"ɺ��"+NOR+"�辰������������˸о�
���ޱȵ��������ף�����������Ժ(kuayuan)�����ߵ�����(zoulang)ͨ��
��԰��������죬��ʱƮ�������㣡
");
        set("no_fight", 1);           
        set("valid_startroom",1);
        
        set("exits", ([
         	"west" : __DIR__"kuayuan",
		"out" : __DIR__"asgard-door",
		"east" : __DIR__"zoulang",
		"down" : "/d/xingxiu/lingshan",
        "newjob" : "/u/snowlf/room/meeting_room",
		"hmsz" : "/u/lisser/hmsz-dy",
		
        ]));

        set("item_desc", ([
                        "yemingzhu": "һ��˶���ҹ���飬ɢ����譲ӵĹ�� ���ǹ��е�����֮�\n",
                        "kuayuan": "���ߵĿ�Ժ�������������޹����Ů��ס�����б���ֹ����\n",
                        "desk": "��������ˮ�����ģ����Ϸ���һ��ɺ���辰��һ������(jian su).\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([ 
                __DIR__"gongnu1":1,                
                __DIR__"gongnu2":1,   
                "/d/taohua/obj/xiangcha" : 1,
                "/clone/wiz/guo": 2,              
       
]));
        setup();
        call_other("/clone/board/jiansu", "???");
}
