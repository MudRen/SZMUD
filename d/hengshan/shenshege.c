//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���߸�");
        set("long", 
"������㣬�Բ�������Ϊ�����ɽ���ʯ���ѣ��Ǵ˸󣬲���
�ȣ���ջ�������촰�������ػأ������ɾ�����߲�����������
Ĳ�ᣬ���ӣ����ӵ��񡣴�˵ʫ����׳��������£���㵲��ѣ�
�ڸ��ڱ����顰׳�ۡ����֡�\n");
        
set("exits", ([
                "southdown"  : __DIR__"xuankongsi",
                "south"   : __DIR__"feiqiao",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

