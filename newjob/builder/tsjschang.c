//room: /newjob/builder/tszschang.c ̩ɽ��ʯ��
//Lara 2001/12/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�������ص�С���֣���ǰ��Ȼ���ʡ���ǰ����һƬ׳�۵ľ���һ��
��ɫ��ɽ��εض���ɽ�ϴ�ݲ���������ɽ����һ��޴����ʯ��ɽ��
��һ����̫���۵�С�ӣ�С��һֱ����ɽ���У���ˮ�Ļ��������������
����һ���ܴ�ĵ��°�����
LONG
        );

        set("exits", ([        
        "out" : __DIR__"tsshiwu",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
