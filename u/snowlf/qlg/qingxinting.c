// huayuan.c   ������/����ͤ
// snowlf by 2001.12.19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"����ͤ"NOR);
        set("long","
    �ڻ�԰��һ�ǣ���ˮ��һ�����ɱ��µ�ͤ�ӣ�ͤ���Ȼ��ȸ߳����ף�
ͤ�����㣬�в����Ѹ�����ְҵϵͳ��һ�����ʱ�����ң�������һ����
��������к�£�������ɳص�ˮԴ����ͤ���Լ�ͤ������Ż��Ⱥ�ˮ鿣�
�����ͺɵĺ�ȥ����ƾ���࿴��������ɫ�����۵ס�

    "+HIM+"���������棬�����е����������Ŀ�������
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
		"out" : __DIR__"huayuan",  
		"south" : __DIR__"jiuqu4",
		"east" : __DIR__"jiuqu3",
		"westup" : __DIR__"yaochi",
		"up" : __DIR__"meeting_room",		
        ]));

        set("item_desc", ([
                        "lotus flower": "������Ҷ����̣�ӳ�պɻ������죡\n",
			"������ɫ": "������Ҷ����̣�ӳ�պɻ������죡\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",0);
        setup();

}
