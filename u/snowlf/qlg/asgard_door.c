// qlg/asgard_door  �P�s �G���c���f
// snowlf by 2001.12.16



#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIM"��ɽ"NOR);
        set("long",
    "���������ƶ˵�һ����ɽ�������ǰ��һ����Ө��͸��ˮ��������ǰ�̲���
�𣬶�����һСƬ"+HIR+"����"+NOR+"�����ִ����������ͷ���½翴ȥ��ȴ���������ɽ֮
�ϡ�
    ʰ�׶��ϣ����ù�ǰ��������ǰ��յ�����Ϸֱ�����"+HIG+"���ߡ�"+NOR+","+HIM+"������"+NOR+"���֡�
    
");
        set("no_fight", 1);           
        set("valid_startroom",1);
        
        set("exits", ([
           "snowyu" : "/u/snowyu/yangtai",
		"west" : __DIR__"caodi",
		"enter" : "/u/snowlf/workroom",
		"east" : __DIR__"fenglin",
         	"down" : "/d/xingxiu/lingshan",
       		"newjob" : "/u/snowlf/room/meeting_room",
                "hmsz" : "/u/karlopex/hmsz-dy",
		"xrz" : "/u/xrz/workroom",
		"wr" : "/d/wizard/wizard_room",
		
        ]));

        set("item_desc", ([
                        "�½�": "���ִ����������ͷ���½翴ȥ��ȴ���������ɽ��\n",
                        "����": "    ��ʱ��������ʱ�ڣ�������Ҷ�Ӷ������ˡ���һƬ��Ҷ������̾����������
��ע��������Щ��Ҷ�ƴ����޾���ϲ�ã�������������£���չ��֦Ѿ��������
���Ĺ⻪������̾������һ���˽�ǰ�˴ʾ䣢����˭Ⱦ˪�������⾳����    \n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);

        setup();

}
