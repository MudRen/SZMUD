//room: /newjob/builder/snmuyuping.c ľ��ƺ
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "ľ��ƺ");
        set("long", @LONG
ľ��ƺ����ũ�ܲ�����������ȴ�Ǹ�������ľ�ĺ�ȥ�����������ľ
������ڰ������£�����С�������˶����������﷥ľ���и�����ĺ�
�����������￿�����������µ�ľͷ�������ɵ�Ư����ɽ�¡�����ƽʱ��
�ټ������ޣ�ֻ�м�ֻ�����Ľ�˿������ˣ��
LONG
        );

        set("exits", ([   
        "north" : __DIR__"snhongping",   
        "east" : __DIR__"sngsmiao",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
