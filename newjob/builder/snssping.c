//room: /newjob/builder/snssping.c ɼ��ƺ
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "ɼ��ƺ");
        set("long", @LONG
���ﳤ���˸��־޴������ɼ������������������꣬�����ϽԱ�
����̦��ʮ�����¾�����֦��Ҷ����ѩѹ������Ȼ�����Ĵ����洦�ɼ���
��Щ�����е���Ȼ���ţ�������֮ǿ����̾������������һ�������Ҷ
������Ҷ�γɵ�Ҷ�࣬����һ�ȣ������������Ų���
LONG
        );

        set("exits", ([   
        "north" : __DIR__"snsbling",  
        "south" : __DIR__"sngsmiao",   
        "west" : __DIR__"snhongping",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
