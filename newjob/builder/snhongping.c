//room: /newjob/builder/snhongping.c ��ƺ
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", HIR"��ƺ"+NOR);
        set("long", @LONG
��ƺλ����ũ����������´����һС��Ͽ����ء���ƺϿϿ�������
�ߣ������������ι��͡��������£�ɽ������������ʱ�ڣ����־�Ⱦ��
һ���ļ���ϪȪ���ʣ���Ϫ���Ե�������������ī����һ�㡣
LONG
        );

        set("exits", ([   
        "north" : __DIR__"snlslin",
        "south" : __DIR__"snmuyuping",     
        "east" : __DIR__"snssping",
        "west" : __DIR__"snrukou",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
