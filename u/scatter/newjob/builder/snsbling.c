//room: /newjob/builder/snsbling.c �ɰ���
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "�ɰ���");
        set("long", @LONG
����ͦ�Σ����ɭɭ����ɽ��Ұ�������Ͱ�������һƬ������Ȼ�ľ�
�󡣰�ɽ��һ��������ƽ���ϳ����˸�������Ļ��ݣ�æµ���۷�������
�Ĳ��ۣ�������С�����ĳ��Ÿ衣
LONG
        );

        set("exits", ([   
        "south" : __DIR__"snssping",   
        "west" : __DIR__"snlslin",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
