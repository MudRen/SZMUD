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
    ���ÿ�Ժ���ţ����Ǿ������ȣ����������ϻأ��������ģ��ڲ�һ�����ң�Ϊ��
���黭֮�ã����ٺɻ��ء�
    "+HIM+"������죬��ʱƮ���������㣡
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	"north" : __DIR__"jiuqu4",
         	"northeast" : __DIR__"huayuan",
         	"south" : __DIR__"neiyuan",
		"east" : __DIR__"study",
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
