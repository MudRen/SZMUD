//room: /newjob/builder/tsqslu.c ̩ɽ��ʯ·
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
һ���������ʯ·���۵�˳ɽ�ƶ��ϡ�ϸ����Щ��·����ʯ����С��
��״����ȡ�ɫ�󶼷ǳ�һ�£������ߵ��˶࣬·���ѱ�Ħ��ʮ�ֹ⻬��
·����ͻ����ʯͷ����������·���Ϲ̶�֮����ˮ������Щ·���ϾͿ���
����һ�����µ�С�ӣ�����ν��ˮ��ʯ����Ҳ��
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tsxslu",
        "east" : __DIR__"tshgslu",
        "north" : __DIR__"tsqschangn",
        "south" : __DIR__"tsqschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
