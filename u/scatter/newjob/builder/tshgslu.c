//room: /newjob/builder/tsqslu.c ̩ɽ����ʯ·
//Lara 2001/12/09
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����ʯ·");
        set("long", @LONG
����·ȫ���ɻ���ʯ�̳ɣ���Ӳ����ʯ��·������൱̤ʵ�����ڻ�
��ʯ�Ƚ�ϡ�٣��������·�ɲ�ͬ��С�Ļ���ʯ�ּ����̳ɡ�·�ľ�ͷ��
һ��С�ݣ�����ƽʱ����û�˾�ס��
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tsqslu",
        "east" : __DIR__"tsshiwu",
        "north" : __DIR__"tszschangn",
        "south" : __DIR__"tszschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
