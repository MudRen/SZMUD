// jiuqu2.c   ������/��������
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
    �����س������Ѷ��������������ϻأ��������ģ��ڲ��ǻ�԰�����ٺɻ�
�ء��ɴ˱���ת��������ͷ��һ�ۺ�Сͤ���������ġ�������ת��������ի��
ת���������ң�����ͷΪһˮ鿡�
   
    "+HIM+"���������棬�����е����������Ŀ�������  
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	
		"west" : __DIR__"huayuan",
		"south" : __DIR__"jiuqu2",
		"northwest" : __DIR__"qingxinting",  
        ]));

        set("item_desc", ([
                        "lotus flower": "������Ҷ����̣�ӳ�պɻ������죡\n",
			"������ɫ": "������Ҷ����̣�ӳ�պɻ������죡\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",1);

        setup();

}
